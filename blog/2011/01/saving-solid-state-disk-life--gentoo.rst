.. post:: 2011-01-11
   :category: linux
   :author: Jörg Faschingbauer
   :location: Hart bei Graz, Austria
   :language: en

Saving Solid State Disk Life (Gentoo)
=====================================

.. sidebar:: Contents

   .. contents::
      :local:
      :depth: 1

Rant
----

Today's mechanical disks are optimized for writing one Excel sheet a
day it seems. Holding the browser cache significantly decreases
lifetime of a disk. Developing source code and compiling entire trees
multiple times a day, plus updating a Gentoo install once a week is a
recipe to kill a disk.

So I killed three (*three*) mechanical disks last year.

I pretty much depend on these disks as I don't like moving back and
forth between the number one and the spare laptop three times in a
row. (I'm self employed, and the volume of such undertakings is
*indirectly* proportional to the flow of money into my pocket.)

Which is why I decided to purchase a solid state disk. My choice was a
Corsair Force Series 120. It has pretty good reviews on the Internet,
especially for having received a firmware overhaul that reserves less
space for the wear leveling management, thus leaving more of the space
to the user.

I should have known better. Fresh firmware is not cool; it has never
been. During the Gentoo install (no, I compile to RAM now, and *not*
to disk) there is a point where I reboot to switch away from the
Ubuntu LiveCD boot, into the fresh Gentoo system. That was the time
where the SSD has vanished - it was gone! No mention of it, nowhere.

Support request on the Corsair website, sent disk to their returns
department in the Netherlands. After a few days received an email
saying it would last unusually long as they had to cope with an
unusual volume of returns. Looks like I am not alone. I bet they
themselves write those SSD reviews you find on the Internet.

Anyway - after two more weeks of aggressive spare laptop harddisk
treatment I am now the proud owner of a 120G SSD with even fresher
firmware, and have set it up to a point where I can work with it. I
describe below what I did to extend its life, and what's still to be
done. If you have recipes that target the same, please let me know.

No Swap
-------

I have plenty of RAM (4G), and I run Linux, so there shouldn't be any
need to swap. Unfortunately hibernating does not work without swap
(the kernel uses swap to write the state into). I configured one
partition for the purpose of hibernating, which I don't configure in
``/etc/fstab``.

I usually suspend to RAM when at home, and when I move to the living
room or board a train to Germany then I hibernate like so,

.. code-block:: shell

   # sync && swapon /dev/sda1 && echo disk > /sys/power/state && swapoff /dev/sda1

``tmpfs`` instances here and there
----------------------------------

The overall rule is, "You can read from a SSD as often as you want,
but don't write to it.". With this in mind, I immediately identify two
places where I write continuously, and which can be mitigated easily.

* ``/tmp`` is used by programs to hold small amounts of temporary data
  which is perfect for a ``tmpfs`` instance.
* ``/var/tmp/portage`` is used by portage (Gentoo's package installer)
  to compile the packages before installation. I have plenty of RAM
  (4G), so why not use that for compilation. See below for an
  openoffice rant.

All that needs to be done is add two entries to ``/etc/fstab``:

.. code-block:: shell

   portage-tmpfs /var/tmp/portage tmpfs rw 0 0
   tmp-tmpfs     /tmp             tmpfs rw 0 0

You might want to set ``TMPDIR=/tmp`` explicitly, to have GCC write
its temporary files there instead of in its current working
directory. Create a dedicated file in ``/etc/env.d``, and call
``env-update``.

I could limit the space on these by writing ``rw,size=500m`` for
example. Anyway, ``tmpfs`` limits its size to be half the memory as a
default, so in my case this is 2G in each instance.

I hit the limit on the ``/var/tmp/portage`` instance really soon, when
I tried to install openoffice. That piece of crap requires 6G of disk
space for compilation! Ok, I take it I have to make an exception which
reads like so,

.. code-block:: shell

   # # (plug my USB throwaway 1TB disk)
   # mount /dev/sdc1 /mnt/disk
   # mkdir /mnt/disk/tmp-portage
   # mount --bind /mnt/disk/tmp-portage /var/tmp/portage
   # emerge openoffice
   # # (wait a day or two)
   # rm -rf /mnt/disk/tmp-portage
   # umount /var/tmp/portage
   # umount /mnt/disk

Syslog, ``/var/log/messages``
-----------------------------

I like to watch ``/var/log/messages``, and in fact I have ``tail -f
/var/log/messages`` runnung in a dedicated terminal. I usually have no
interest in keeping the logfile; the last time the kernel crashed was
when I had put an offending debug message into ``i2c-dev.c`` to trap a
userspace error I had made. And that was on the Beagleboard.

So, ``/var/log/messages`` is another candidate for ``tmpfs``. Complications:

* Restrict the file in size, which is best done by ``logrotate``.
* Cannot use ``/var/log`` as mountpoint for the ``tmpfs``, as there's
  more in that directory.

Mountpoint for messages
.......................

I create a dedicated directory as a mountpoint, moving the
``messages`` one level deeper,

.. code-block:: shell

   # rm /var/log/messages
   # mkdir /var/log/messages

Mount a ``tmpfs`` there, using ``/etc/fstab``,

.. code-block:: shell

   messages-tmp  /var/log/messages tmpfs rw 0 0

At this point you use ``mount -a`` to immediately create the
mount. Next, tell ``syslog-ng`` about it. In
``/etc/syslog-ng/syslog-ng.conf`` write,

.. code-block:: shell

    # ...
    destination messages { file("/var/log/messages/messages"); };
    # ...

Logrotate
.........

.. code-block:: shell

   # emerge app-admin/logrotate

Make sure ``cron`` is running (``rc-status|grep cron``, he runs ``logrotate``). ``syslog-ng`` already comes with a ``logrotate`` configuration file, ``/etc/logrotate.d/syslog-ng``. Tune this to our needs (rotate the file when its size exceeds 20M, keeping one compressed copy).

.. code-block:: shell

   /var/log/messages/messages {
        compress
        compresscmd /bin/bzip2
        compressoptions -9
        compressext .bz2
        size 20M
        rotate 1
        missingok
        sharedscripts
        postrotate
            /etc/init.d/syslog-ng reload > /dev/null 2>&1 || true
        endscript
   }

Kernel I/O Scheduler
--------------------

The kernel uses an algorithm called an I/O scheduler to optimize disk access. It does this by collecting read and write requests at adjacent disk locations. This is not necessary with SSDs as there are no disks and no heads. I switch off the scheduler for ``sda`` (which is the SSD), and keep the default scheduler (``cfq``) for USB disks I use to plug on occasion (for example if there's an openoffice update).</p><p>In ``/etc/conf.d/local.start`` I write,

.. code-block:: shell

   echo noop > /sys/block/sda/queue/scheduler

Use RAM for the Kernel Build
----------------------------

I am a big believer in out-of-source builds. The kernel build system
is also capable of it, and I use to build the kernel in ``/tmp`` like
so.

.. code-block:: shell

   # mkdir /tmp/kernel-build
   # cp /boot/linux-2.6.36-gentoo-r5/.config /tmp/kernel-build
   # make -C /usr/src/linux O=/tmp/kernel-build oldconfig
   # make -C /usr/src/linux O=/tmp/kernel-build menuconfig
   # make -C /usr/src/linux O=/tmp/kernel-build all
   # ...

Don't forget to save away the ``.config`` file, as it will be gone
after a reboot. I use to store it along with the kernel image in
``/boot/linux-2.6.36-gentoo-r5``.

Things that are left
--------------------

There are a couple of things that still need work.

* Xorg appears to have a hardcoded log location; I didn't find a
  config option to have it write its ``Xorg.0.log`` in a directory
  other than ``/var/log``.
* There appears to be bug in portage; it does not respect the
  ``EMERGE_LOG_DIR`` variable. Otherwise, I could redirect the files
  ``emerge.log`` and ``emerge-fetch.log`` out of ``/var/log``, just
  like I do with ``/var/log/messages``.
* The fact remains that I build my own projects on disk. I have to
  solve that somehow; I am thinking of using ``aufs`` or
  ``unionfs-fuse`` to partly persist those. Some scripting around it
  maybe, to persist those parts of the build which are currently in
  ram. But this is another story, maybe I'll write about it when I
  know what I want.
