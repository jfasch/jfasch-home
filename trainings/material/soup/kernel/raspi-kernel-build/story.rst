.. meta::
   :description: How to build raspberry kernel (plus explanations)
   :keywords: cross compile, kernel, raspberry, pi, embedded,
              architecture, target


Rasperry Pi: Kernel Build
=========================

.. contents:: 
   :local:

Introduction
------------

This document is a transcript of a shell script I use to do repeated
Linux kernel builds for the Raspberry Pi. I use the Raspi a lot, both
for educational purposes (I give courses on various topics around
Linux), and for hardware prototyping.

Note that the entire process of building the Rasperry Pi kernel is
described `over at raspberrypi.org
<https://www.raspberrypi.org/documentation/linux/kernel/building.md>`__. The
foundation's description is targetted to the end user who wants to get
the problem solved. Enable one more drivers in the build, and be done.

This description borrows heavily from the foundation's, but deviates
in a few places. It is for people who want to do more, for example,

* Maintain their own kernels using Git
* Build kernels for different architectures, and not only for the Rasperry
* Use different toolchains (I use Gentoo's ``crossdev`` to create
  toolchains)
* Understand better what's involved

Cross Toolchain on Host
-----------------------

It's no fun to do large compilations on the Pi. The Pi2 has become a
lot more powerful - 4 processors can do more than just one. RAM has
also doubled but there is still "only" 1GB which soon becomes the
limiting factor for a parallel kernel compilation.

This is why we do *cross compiling*. One could compile on the Pi if
one wants, things become simpler when done without cross compiling -
but not much as we will see. Anyway, there are other platforms which
are not as capable as the Pi - where there is no native compilation no
matter what -, and the same principles apply there.

Architecture Name - What's That?
................................

I am not exactly sure where those *architecture names* come from, and
what their canonical definition is. I understand that one needs a
*cross toolchain* to build code *on the workstation*, and that code
will run *on the target machine* (Pi in our case).

*So how to select the toolchain?* Every toolchain has a *name*, and I
cannot come up with a good explanation of how these names are made up.
Here two examples,

* *The Raspberry Foundation's toolchain*. See `here
  <https://www.raspberrypi.org/documentation/linux/kernel/building.md>`__
  for how to get it (it boils down to cloning a Github
  repository). Obviously they use the target name
  ``arm-linux-gnueabihf``. Makes sense, the ``...hf`` stands for
  *hardware floatingpoint*.
* *Gentoo's crossdev*. Here the Pi toolchain is referred to as
  ``armv6j-hardfloat-linux-gnueabi`` (see `here
  <https://wiki.gentoo.org/wiki/Raspberry_Pi>`__) which also makes
  sense. ``hardfloat`` as above, plus there we are more specific about
  the processor type: ``armv6j``.

The point is that there is no magic behind the toolchain name (except
that you should choose the right toolchain for your target
architecture of course). All you need to know is that the target name
is part of the name of the binaries,

.. code-block:: console

   $ ls -1 /usr/bin/armv6j-hardfloat-linux-gnueabi-*
   /usr/bin/armv6j-hardfloat-linux-gnueabi-ar
   /usr/bin/armv6j-hardfloat-linux-gnueabi-as
   /usr/bin/armv6j-hardfloat-linux-gnueabi-g++
   /usr/bin/armv6j-hardfloat-linux-gnueabi-gcc
   /usr/bin/armv6j-hardfloat-linux-gnueabi-ld
   /usr/bin/armv6j-hardfloat-linux-gnueabi-nm
   /usr/bin/armv6j-hardfloat-linux-gnueabi-objcopy
   ...

I, being a Gentoo user, will use ``armv6j-hardfloat-linux-gnueabi``
for the remainder.

Building a Toolchain with Gentoo's ``crossdev``
...............................................

Links: 

* https://wiki.gentoo.org/wiki/Raspberry_Pi
* https://wiki.gentoo.org/wiki/Overlay/Local_overlay

Crossdev will pull in a lot of Ebuilds which are used to build the
members (``binutils``, ``gcc``, ...) of the toolchain. These will not
be stored in the main portage tree, but rather in a `local portage
overlay <https://wiki.gentoo.org/wiki/Overlay/Local_overlay>`__ that
you will have to create.

To create a local overlay for the crossdev artifacts,

.. code-block:: console

   # mkdir -p /usr/local/portage-crossdev/profiles
   # echo local-crossdev > /usr/local/portage-crossdev/profiles/repo_name

In ``/etc/portage/repos.conf/crossdev.conf`` (create if it does not
exist), add

.. code-block:: console

   [local-crossdev]
   location = /usr/local/portage-crossdev
   priority = 9999
   masters = gentoo
   auto-sync = no

Build the toolchain (this can take a while),

.. code-block:: console

   # crossdev --stable --target armv6j-hardfloat-linux-gnueabi

Other Toolchains
................

The `Raspberry Foundation's documentation
<https://www.raspberrypi.org/documentation/linux/kernel/building.md>`__
has a precompiled toolchain available from a Git repository. (What
mindset leads you to using Git for this?)

If you are developing for industry embedded platforms, as I do from
time to time, chances are that you will be using a vendor supplied
toolchain. No difference, basically, other than probably very outdated
versions. If the pain becomes too hard because the version are way too
outdated, Gentoo's ``crossdev`` can always come to the rescue.


Kernel Source
-------------

I use to track Linus's repository, and pull stuff from others as
needed. Occasional kernel work is also done there. Together with
out-of-source kernel builds, this is what is in this description:

* Get the mainline kernel
* Augment it with the Raspi tree on Github

Kernel source from Linus's repository (I use to have it in
``~/work/linux``),

.. code-block:: console

   $ git clone https://github.com/torvalds/linux.git ~/work/linux

The Raspberry kernel source is in
https://github.com/raspberrypi/linux.git - add this as a *git remote*,

.. code-block:: console

   $ cd ~/work/linux
   $ git remote add raspberrypi https://github.com/raspberrypi/linux.git
   $ git remote -v
   origin	https://github.com/torvalds/linux.git (fetch)
   origin	https://github.com/torvalds/linux.git (push)
   raspberrypi	https://github.com/raspberrypi/linux.git (fetch)
   raspberrypi	https://github.com/raspberrypi/linux.git (push)

Initial fetch,

.. code-block:: console

   $ git fetch raspberrypi

Add a local tracking branch (and check it out) for the one remote
branch that we want to work on. ``rpi-4.1.y`` is the current version
as of this writing.

.. code-block:: console

   $ git checkout -b rpi-4.1.y remotes/raspberrypi/rpi-4.1.y

Kernel Compilation
------------------

Parameters for the Build
........................

In order to make the million command lines that follow more concise
and maintainable, I set a few variables that are referred to in the
remainder as needed. In real life all this would be done in a shell
script (it is), but it is easier to make things clear in a
step-by-step manner.

``SOURCEDIR`` is where the kernel source is. The build will leave that
tree untouched.

.. code-block:: console

   $ SOURCEDIR=$HOME/work/linux

``BUILDDIR`` is where the kernel build goes. Initially empty.

.. code-block:: console

   $ BUILDDIR=/var/jfasch/raspi/kernel/rpi-4.1.y-jfasch/build
   $ mkdir -p $BUILDDIR

``BUILDPARAM`` is supplied to the kernel build as a whole, as a
commandline parameter to the ``make`` program. This one's for cross
compilation - select the ARM architecture, and specify your cross
toolchain.

**Important**: when supplying the toolchain name
(``armv6j-hardfloat-linux-gnueabi``) to the kernel build, we have to
add an extra '-' at the end, making it into
``armv6j-hardfloat-linux-gnueabi-``. The kernel build system prepends
the supplied value to ``gcc`` literally.

Otherwise the build will fail with a rather unobvious message,

.. code-block:: console

   scripts/kconfig/zconf.tab.c:199:24: fatal error: zconf.hash.c: No such file or directory

So,

.. code-block:: console

   $ BUILDPARAM="ARCH=arm CROSS_COMPILE=armv6j-hardfloat-linux-gnueabi-"

Next, I like the build to take place out-of-source, and this is how it
is done.

.. code-block:: console

   $ BUILDPARAM="$BUILDPARAM -C $SOURCEDIR"
   $ BUILDPARAM="$BUILDPARAM O=$BUILDDIR"

When the build is done, the build artifacts have to be collected and
transferred to the Raspi. There are two places on the Raspi that are
relevant for the boot,

* Bootloader stuff. This is on a ``fat32`` partition; the kernel,
  device tree, and device tree overlays go there.
* Kernel modules. The module tree is part of the regular root
  filesystem which is ``ext4`` formatted partition (not necessarily,
  but Raspbian images come in that shape).

When the build is done, we will prepare two tar files, out of two
directory trees that we fill. This is what the following variables are
there for,

.. code-block:: console

   $ BOOTDIR=/var/jfasch/raspi/kernel/rpi-4.1.y-jfasch/bootfs
   $ ROOTDIR=/var/jfasch/raspi/kernel/rpi-4.1.y-jfasch/rootfs
   $ mkdir -p $BOOTDIR $ROOTDIR

Finally, the kernels for Raspi versions 1 and 2 are
different. (Further down we'll create different kernel configurations
for the two.) The bootloader decides which one to load, based on its
filename,

For the Pi 1, choose

.. code-block:: console

   $ SOURCEDIR=$HOME/work/linux

``BUILDDIR`` is where the kernel build goes. Initially empty.

.. code-block:: console

   $ BUILDDIR=/var/jfasch/raspi/kernel/rpi-4.1.y-jfasch/build
   $ mkdir -p $BUILDDIR

``BUILDPARAM`` is supplied to the kernel build as a whole, as a
commandline parameter to the ``make`` program. This one's for cross
compilation - select the ARM architecture, and specify your cross
toolchain.

**Important**: when supplying the toolchain name
(``armv6j-hardfloat-linux-gnueabi``) to the kernel build, we have to
add an extra '-' at the end, making it into
``armv6j-hardfloat-linux-gnueabi-``. The kernel build system prepends
the supplied value to ``gcc`` literally.

Otherwise the build will fail with a rather unobvious message,

.. code-block:: console

   scripts/kconfig/zconf.tab.c:199:24: fatal error: zconf.hash.c: No such file or directory

So,

.. code-block:: console

   $ BUILDPARAM="ARCH=arm CROSS_COMPILE=armv6j-hardfloat-linux-gnueabi-"

Next, I like the build to take place out-of-source, and this is how it
is done.

.. code-block:: console

   $ BUILDPARAM="$BUILDPARAM -C $SOURCEDIR"
   $ BUILDPARAM="$BUILDPARAM O=$BUILDDIR"

When the build is done, the build artifacts have to be collected and
transferred to the Raspi. There are two places on the Raspi that are
relevant for the boot,

* Bootloader stuff. This is on a ``fat32`` partition; the kernel,
  device tree, and device tree overlays go there.
* Kernel modules. The module tree is part of the regular root
  filesystem which is ``ext4`` formatted partition (not necessarily,
  but Raspbian images come in that shape).

When the build is done, we will prepare two tar files, out of two
directory trees that we fill. This is what the following variables are
there for,

.. code-block:: console

   $ KERNEL=kernel

For the Pi 2, choose

.. code-block:: console

   $ KERNEL=kernel7

Preparing the Kernel ``.config`` File
.....................................

If you have a running Raspi, you can retrieve the kernel configuration
from the running kernel (logged in as root on the Raspi),

.. code-block:: console

   # modprobe configs    # suddenly /proc/config.gz appears
   # gzip -cd /proc/config.gz > /tmp/raspi-config

Then, on the host, copy that file into the build directory (which is
still empty at this point), and let the build assimilate it,

.. code-block:: console

   $ cp raspi-config $BUILDDIR/.config
   $ make $BUILDPARAM oldconfig

Alternatively, for the Raspi tree, there is a way to create the same
configuration without having a running Raspi.

For the Pi 1, call

.. code-block:: console

   $ make $BUILDPARAM bcmrpi_defconfig

For the Pi 2, call

.. code-block:: console

   $ make $BUILDPARAM bcm2709_defconfig

This creates the same ``$BUILDDIR/.config`` kernel configuration file
that we extracted from the live Raspi above. Assimilate,

.. code-block:: console

   $ make $BUILDPARAM oldconfig

Now is the time to make adjustments - this is why we are compiling a
custom kernel in the first place. Enter the configuration menu,

.. code-block:: console

   $ make $BUILDPARAM menuconfig

Your modification demands may vary - here are demands that I can
imagine.

 * ``CONFIG_LOCALVERSION``: it make sense to differentiate (with
   ``uname -r`` for example) your custom kernel from the original. I
   append ``-jfasch``, at a minimum or something more precise.
 * ``CONFIG_IKCONFIG``: link ``/proc/config.gz`` statically. Otherwise
   one has to ``modprobe configs`` to see it. I use the file often
   during development, and don't want to load a module eveytime I need
   it.
 * ``CONFIG_CAN_MCP251X``: a CAN controller that I needed to talk to
   in one of my recent projects. Already there, as a module - but
   better check.
 * ``CONFIG_SENSORS_LM73``: an I2C temperature sensor. Configure as
   module.

Building the Kernel Artifacts
.............................

Now, having created and edited the configuration, the tree is fit for
building. Note how we didn't yet make any modifications to the source
(``$SOURCEDIR``) itself - all we did takes place in ``$BUILDDIR``. Let
the system build all the necessary artifacts,

* The main kernel image
* Modules
* Device tree blobs

.. code-block:: console

   $ make $BUILDPARAM zImage modules dtbs

If your host machine happens to have multiple cores (likely), gain a
speed up by doing parallel compilation (mine has four cores, and I
specify one less because I usually want to do other work during the
build),

.. code-block:: console

   $ make -j3 $BUILDPARAM zImage modules dtbs

Packaging
---------

Now's the time to collect all the artifacts together, and transfer
them onto the Raspi. We create two "packages" so to say, in the form
of tar files. One package contains the artifacts that are read by the
bootloader, the other package contains the module tree of the kernel
we just built.

Bootloader Artifacts
....................

The kernel image, ``arch/arm/boot/zImage``, has to be wrapped into an
envelope that is understood by the bootloader. As root,

.. code-block:: console

   $ $SOURCEDIR/scripts/mkknlimg $BUILDDIR/arch/arm/boot/zImage $BOOTDIR/$KERNEL.img

In addition to the kernel, the bootloader loads the *device
tree*. Before starting te kernel, it composes a complete tree out of a
*main device tree* and overlays. Copy these artifacts,

.. code-block:: console

   $ cp $BUILDDIR/arch/arm/boot/dts/*.dtb $BOOTDIR/
   $ mkdir $BOOTDIR/overlays
   $ cp $BUILDDIR/arch/arm/boot/dts/overlays/*.dtb $BOOTDIR/overlays/

Having all this in ``$BOOTDIR``, create a tar file from it,

.. code-block:: console

   $ tar -C $BOOTDIR -jcf /tmp/raspi-boot.tar.bz2 .

Module Tree
...........

Install the kernel modules into ``$ROOTDIR``. This will create a
module tree starting at ``$ROOTDIR/lib/modules/<kernel-version>`` - so
``$ROOTDIR`` can be thought of as an *overlay* over the target root
filesystem.

.. code-block:: console

   $ make $BUILDPARAM INSTALL_MOD_PATH=$ROOTDIR modules_install

Then, create another tar package containing ``$ROOTDIR``. The root
filesystem (``ext4``) has an idea what owners and groups are, so it
makes sense to create a tar file reflecting the ideal situation -
modules are owned by root -,

.. code-block:: console

   $ tar -C $ROOTDIR --owner root --group root -jcf /tmp/raspi-root.tar.bz2 .

Summary
.......

The outcome of our kernel build is two "packages" in the form of tar
files. Each of these files functions as an "overlay" over one of the
two filesystems that are usually employed by a Raspberry distribution.

It is worth noting that ...

* We did not have to become superuser during the build. (We did for
  the cross toolchain installation, clearly. But this is a one-time
  operation.)
* The packages contain only relative paths.

The "boot" overlay file contains those artifacts that are relevant for
the bootloader, and they are read before the kernel is started. This
package looks as follows,

.. code-block:: console

   $ tar jtf /tmp/raspi-boot.tar.bz2
   ./
   ./bcm2709-rpi-2-b.dtb
   ./kernel7.img
   ./overlays/
   ./overlays/smi-overlay.dtb
   ./overlays/rpi-ft5406-overlay.dtb
   ./overlays/mcp2515-can1-overlay.dtb
   ./overlays/pwm-overlay.dtb
   ...

The "root" overlay contains the kernel module tree. It contains kernel
modules, and these are loaded *by the running kernel*. This package
looks as follows,

.. code-block:: console

   $ tar jtf /tmp/raspi-root.tar.bz2 
   ./
   ./lib/
   ./lib/modules/
   ./lib/modules/4.1.10-v7-jfasch+/
   ./lib/modules/4.1.10-v7-jfasch+/source
   ./lib/modules/4.1.10-v7-jfasch+/modules.order
   ./lib/modules/4.1.10-v7-jfasch+/modules.symbols.bin
   ./lib/modules/4.1.10-v7-jfasch+/kernel/
   ./lib/modules/4.1.10-v7-jfasch+/kernel/net/
   ./lib/modules/4.1.10-v7-jfasch+/kernel/net/ipv4/
   ./lib/modules/4.1.10-v7-jfasch+/kernel/net/ipv4/xfrm4_mode_beet.ko
   ./lib/modules/4.1.10-v7-jfasch+/kernel/net/ipv4/inet_lro.ko
   ./lib/modules/4.1.10-v7-jfasch+/kernel/net/ipv4/esp4.ko
   ./lib/modules/4.1.10-v7-jfasch+/kernel/net/ipv4/xfrm4_mode_transport.ko
   ./lib/modules/4.1.10-v7-jfasch+/kernel/net/ipv4/udp_tunnel.ko
   ... (many more) ...

Next (and last), we have to bring these packages onto the target in
order to boot our new versions.

Deployment
----------

Given our two packages, deployment is simple. Insert an SD card that
is prepared with your favorite Raspberry distribution (I only tested
with Raspbian, but there's no real reason why it shouldn't work with
any other), and you'll get presented with two partitions (mine are
``/dev/sdb*``),

.. code-block:: console

   $ cat /proc/partitions 
   ...
      8       17      57344 sdb1
      8       18    4162560 sdb2
   ...

I use Gnome 3 and systemd which is a bit decadent, but I sure enjoy
external storage being mounted automatically,

.. code-block:: console

   $ mount
   /dev/sdb1 on /run/media/jfasch/boot type vfat (...)
   /dev/sdb2 on /run/media/jfasch/ec2aa3d2-eee7-454e-8260-d145df5ddcba type ext4 (...)

(You might have to take manual care to establish a similar situation.)

First, the "boot" stuff. We don't have to become root since ``fat32``
is permission-agnostic, so we just unpack the "boot" package onto the
SD card's boot partition,

.. code-block:: console

   $ tar -C /run/media/jfasch/boot -jxf /tmp/raspi-boot.tar.bz2

Next, the "root" stuff. We cannot unpack our "root" package into the
mounted ``ext4`` filesystem - its ``/lib/modules/`` directory is owned
by root, and that's where the module tree is supposed to go to. So, as
root,

.. code-block:: console

   # tar -C /run/media/jfasch/ec2aa3d2-eee7-454e-8260-d145df5ddcba -jxf /tmp/raspi-root.tar.bz2

Finally,

.. code-block:: console

   $ sync

Done. Pull out card, insert into Raspi, boot.

Variation
.........

If you have a running Raspi and you don't want to shut it down for too
long (pull out card, do the deployment as described above, insert card
back in, boot), then you can do the deployment onto the filesystems
while the Raspi is running from them. There no danger of overwriting
files while they are in use - all that's being use is loaded into
memory and runs from there. The bootloader is done, the kernel is
loaded into memory, has interpreted the device tree, and the modules
are in place. Transfer the packages onto the Raspi, and do the same
with the running filesystems.

The ``fat32`` "boot" filesystem is mounted at ``/boot``. Files are
only accessible as root because that is the user who mounted the
filesystem - so we have to become root.

.. code-block:: console

   # tar -C /boot -jxf /tmp/raspi-boot.tar.bz2

Same for the ``ext4`` "root" filesystem, which in fact *is* the root
filesystem for the running kernel,

.. code-block:: console

   # tar -C / -jxf /tmp/raspi-root.tar.bz2

Done. Reboot.

Summary
-------

Now what have we done?

* We built a cross toolchain, using Gentoo's extremely cool
  ``crossdev``. We could use just about any other toolchain, as long
  as it can build code that can run on the target processor. With
  embedded "industry boards" you usually receive a vendor provided
  toolchain, so this is likely the way to go in such cases. Remember
  that the toolchain name is just a prefix of the toolchain's
  executables (compiler, linker, etc.)
* We used Git heavily (no, not heavily) to get to our kernel
  source. This is not necessary if you receive the kernel source from
  elsewhere - all that's needed is the kernel tree, no matter where it
  comes from. Nevertheless, if you plan for proper forward
  development, I recommend you to urge vendors to communicate properly
  via Git.
* We did some kernel configuration, enabling modules, features, and
  whatnot. Play around.
* We built the kernel *out-of-source*. This is a very cool way of
  keeping the source tree read-only - which is definitely recommended
  when you use one Git repository for work on multiple kernel
  versions.
* We prepared "packages". This is not necessary, but it is a good way
  to structure your deployments - and, most of all, to get an
  understanding of which goes where. There are distributions
  (Debian/Raspbian being only one of them) and even meta-distributions
  (Yocto, and to some extent, Gentoo) that are based on a great deal
  of that knowledge.
