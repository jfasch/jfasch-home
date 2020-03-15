.. post:: 2010-07-30
   :category: linux, embedded
   :author: Jörg Faschingbauer
   :location: Hart bei Graz, Austria
   :language: en

Beagleboard: How to Repair NAND (also known as 40W)
===================================================

.. sidebar:: Contents

   .. contents::
      :local:

It happened again. Friends of mine have an alias,

.. code-block:: shell

   alias faschingbauer="rm -rf ~"

in their ``.bashrc`` for a couple of years now, and now I created a
creative variation thereof.

I used to have my beagleboard running happily off an SD card, using a
root filesystem which I had updated natively from a `Gentoo ARM stage3
<http://mirrors.kernel.org/gentoo/releases/arm/autobuilds/current-stage3/armv4tl-softfloat-linux-gnueabi/>`__. This
is decadent, so I prepared a Busybox-only initramfs linked into the
kernel image (cross-built of course, as opposed to the stage3), with
the plans to use this as an alternative boot image residing in NAND
flash.

It happened to me that, during finding out the correct arguments of
U-Boot's ``nand erase`` command, I hit the
return key early - expecting that a sole

.. code-block:: shell

   nand erase

would give me further instructions. U-Boot took it literally though
and erased NAND, just like I told it to. A reboot showed the fatal
consequences. "40W" was the only thing I saw over the serial terminal
(115200/8N1 by the way).

Here in the remainder I write down how to recover from such a
fauxpas. The internet has a lot of explanations, but none of them is a
walk-through from the beginning to the end. You'll have to do a couple
of things, and most of the instructions you'll find don't explain
much. This is not what I like, so I researched a bit and write the
annotated collected instructions down right here. You might find it
useful - I surely will once I'll brick my beagle again.

Basics
------

The OMAP has a small boot ROM inside. This is the first of the chain
of boot loaders, and it's where the CPU core jumps to when it's done
with whatever CPU cores do when they are powered on). The boot ROM is
programmed to load a second stage boot loader (the "X-Loader" as it is
called) into the processor's SRAM. X-Loader is then responsible for
loading another stage - U-Boot in the Linux case - into the external
DRAM. It's the latter two stages - X-Loader and U-Boot - that I
faschingbauered away from NAND, and that I'll recover now.

They key to all that is the ability of the boot ROM to boot from a
MMC/SD card when the user button is pressed during its operation. We
will prepare one such card, put the boot files on it, and write these
to NAND.

Getting X-Loader and U-Boot
---------------------------

The beagleboard guys wrote up a page with `board validation
instructions
<http://code.google.com/p/beagleboard/wiki/BeagleboardRevC3Validation>`__. This
is where I have most of the information from. There they give links to
the images that I want. Take care that you select the ones that match
your board revision; the files they use on that page are slightly
seasoned. I have a recent C4, and I found it valuable to have a recent
U-Boot version that enables power on the USB host controller. This was
a change they made from C3 to C4, for example - take care.

Anyway, `Angstrom
<http://www.angstrom-distribution.org/demo/beagleboard/>`__ have the
most recent stuff. Download X-Loader and U-Boot from there, and
additionally another bootloader stage, ``MLO``, which is used during
the MMC boot. The filenames change, just browse the directory a choose
something that sounds like ``x-load.bin.ift``, ``u-boot*``,
``MLO*``. Save them away for later use. I saved them as
``x-load.bin.ift`` and ``u-boot.bin``, and it's these names that I
refer to later on.

Creating a Bootable MMC/SD card
-------------------------------

For basic card configuration I refer you to `a TI maintained page
<http://processors.wiki.ti.com/index.php/MMC_Boot_Format>`__ which is
very concise and to the point, and where there is nothing much left to
say. I followed the instruction using fdisk, and obvoiusly the card
can be read by the boot ROM. There are reports that FAT32 does not
work on some cards, and that selecting FAT16 instead helped. You might
want to try that out in case.

Once the card is ready and a FAT partition has been created, you mount
that partition and put the files on it as follows.

* First comes ``MLO``, as file ``MLO``, no matter what name you stored
  it under on your disk. It is read by the boot ROM, and that one is
  very particular that the file is found in the first sectors.
* You store the U-Boot image as file ``u-boot.bin``. ``MLO`` expects
  it under that name during MMC boot. (If you intend to use a
  different U-Boot image for NAND then you store that one under a
  different name which you use further down when we write NAND.)
* The X-Loader is not used during MMC boot, so you can choose any name
  you like.

Insert the card into the MMC/SD slot of the beagle, and boot. In case
you erased your NAND only partly and there is still something
meaningful in it, be sure to hold down the user button to force the
boot ROM to boot from the card.

Repairing the NAND
------------------

The following is taken from the `reset.scr
<http://beagleboard.googlecode.com/files/reset_revc_v3.scr>`__ U-Boot
script referred to by the `beagleboard validation instructions
<http://code.google.com/p/beagleboard/wiki/BeagleboardRevC3Validation>`__. I
took care to annotate as much as possible in order to understand the
steps.

First off, we initialize MMC/SD.

.. code-block:: shell

   OMAP3 beagleboard.org # mmc init
   mmc1 is available

To understand where the numbers in the remainder instructions come
from, open the kernel source file
``arch/arm/mach-omap2/board-omap3beagle.c``. I'll refer to that file
in the remainder explanations. Near the top of the file you'll notice
the partition table; you'll find it insightful.

Writing X-Loader to NAND
------------------------

First, erase the X-Loader partition. According to the partition table,
it starts at offset 0 (where the OMAP's boot ROM expects it) and is
4*128K=0x80000 bytes long.

The boot ROM relies on hardware to manage error correction code (ECC),
as described in the `tech note
<http://download.micron.com/pdf/technotes/nand/tn2916.pdf>`__, so we
select it.

..  code-block:: shell

    OMAP3 beagleboard.org # nandecc hw
    HW ECC selected

    OMAP3 beagleboard.org # nand erase 0 80000
    NAND erase: device 0 offset 0x0, size 0x80000
    Erasing at 0x60000 -- 100% complete.
    OK

According to the `tech note
<http://download.micron.com/pdf/technotes/nand/tn2916.pdf>`__ again,
the OMAP's boot ROM takes care of bad blocks (unlikely because an
intermediate bootloader isn't written to flash that often, but
nevertheless it sounds like a good idea). It checks the first four
blocks of the X-Loader partition for a valid image, so we write the
image into these four blocks. Again, the erase block size is
determined by looking in ``board-omap3beagle.c`` - 128K = 0x20000.

Read the image into memory, and write it out 4 times, in the first
four erase blocks of the partition.

.. code-block:: shell

   OMAP3 beagleboard.org # fatload mmc 0 80200000 x-load.bin.ift
   reading x-load.bin.ift
   20392 bytes read

   OMAP3 beagleboard.org # nand write 80200000 0 20000
   NAND write: device 0 offset 0x0, size 0x20000
   131072 bytes written: OK
   
   OMAP3 beagleboard.org # nand write 80200000 20000 20000
   NAND write: device 0 offset 0x20000, size 0x20000
   131072 bytes written: OK

   OMAP3 beagleboard.org # nand write 80200000 40000 20000
   NAND write: device 0 offset 0x40000, size 0x20000
   131072 bytes written: OK

   OMAP3 beagleboard.org # nand write 80200000 60000 20000
   NAND write: device 0 offset 0x60000, size 0x20000
   131072 bytes written: OK

Writing U-Boot to NAND
----------------------

Can't find which ECC incarnation the X-Loader uses, software seems to
be the choice (sounds like the do-nothing-and-cross-fingers approach).

.. code-block:: shell

   OMAP3 beagleboard.org # nandecc sw
   SW ECC selected

According to the kernel sources, U-Boot's partition starts at offset
0x80000 and is 15*128K=0x1e0000 bytes long.

Erase NAND, load U-Boot from card, write it to the partition.

.. code-block:: shell

   OMAP3 beagleboard.org # nand erase 80000 1e0000
   NAND erase: device 0 offset 0x80000, size 0x1e0000
   Erasing at 0x240000 -- 100% complete.
   OK

   OMAP3 beagleboard.org # fatload mmc 0 80200000 u-boot.bin
   reading u-boot.bin
   275928 bytes read

   OMAP3 beagleboard.org # nand write 80200000 80000 1e0000
   NAND write: device 0 offset 0x80000, size 0x1e0000
   1966080 bytes written: OK

That's it. You are now able to boot without the card, up to the U-Boot
prompt.

Take care when you flash the kernel. In case you don't know the
correct ``nand erase`` parameters, write

.. code-block:: shell

   OMAP3 beagleboard.org # help nand

instead of ``nand erase``. I suggest you type

.. code-block:: shell

   OMAP3 beagleboard.org # nand erase 280000 400000

just like the kernel source says for the kernel partition.
