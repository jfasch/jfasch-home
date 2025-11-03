.. include:: <mmlalias.txt>


Everything Is A File (Live Demo)
================================

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/blocking-io/blocking-io`

Simple is beautiful
-------------------

.. important::

      One sometimes has to think more to reach simplicity.

      This pays off a thousand times.

Ok: a File is a File
--------------------

* A file is a file. That's simple.
* There are tools explicitly made to read and write files, everybody
  can use these.

.. code-block:: console
   :caption: Write to a File

   $ echo Hello > /tmp/a-file

.. code-block:: console
   :caption: Read from a File

   $ cat /tmp/a-file
   Hello

Is a Serial Interface (UART) a File?
------------------------------------

Why not? Data go out and come in!

.. code-block:: console
   :caption: Write into the Cable

   $ echo Hello > /dev/ttyUSB0

.. code-block:: console
   :caption: Read off the Cable

   $ cat /dev/ttyUSB1
   Hello

Pseudo Terminals
----------------

**Terminals**

* History: login via a hardware terminal, connected through a serial line
* Terminal (TTY) layer (in the kernel) implements session management
* *Pseudo Terminal*: software instead of cable

Consequentially, output to a pseudo terminal is like writing to a
cable, err, file.

.. code-block:: console
   :caption: Write to a Pseudo Terminal

   $ echo Hello > /dev/pts/0

Disks and Partitions
--------------------

.. code-block:: console
   :caption: USB Stick Backup

   # cat /proc/partitions
   major minor  #blocks  name
   
      8       32    2006854 sdc
      8       33    2006823 sdc1
   # cp /dev/sdc1 /Backups/USB-Stick
   # mount -o loop /Backups/USB-Stick /mnt

``/proc`` and ``/sys``
----------------------

* Kernel has variables in memory that configure certain aspects of its
  operation
* Most of these variables are exposed as files
* |longrightarrow| *Virtual* file systems: ``sys`` and ``proc``

.. code-block:: console
   :caption: Processes as directories

   $ cd /proc/$$       # ... deserves a bit of explanation though :-)

.. code-block:: console
   :caption: Suspend to Disk

   # echo disk > /sys/power/state

Pseudo Devices
--------------

.. topic:: Documentation

   * `man dd <https://man7.org/linux/man-pages/man1/dd.1.html>`__
   * `/dev/zero <https://en.wikipedia.org/wiki//dev/zero>`__
   * `/dev/null <https://en.wikipedia.org/wiki/Null_device>`__
   * `Difference between /dev/null and /dev/zero
     <https://unix.stackexchange.com/questions/254384/difference-between-dev-null-and-dev-zero>`__

* ``/dev/null``: trash can, swallowing everything you write to it)x

  $ echo hallo
  hallo
  $ echo hallo > /dev/null

* ``/dev/zero``: insane amount of NULL-bytes

  .. code-block:: console
     :caption: Burn CPU copying NULL-bytes back and forth

     $ ls -l /dev/zero
     crw-rw-rw-. 1 root root 1, 5 Mar  7 12:10 /dev/zero
     $ cat /dev/zero > /dev/null

  .. code-block:: console
     :caption: Create a 1MiB sized file containing NULL-bytes, and
               format it as FAT

     $ dd if=/dev/zero of=/tmp/1MibFS.fat count=1024 bs=1024
     $ ls -lh /tmp/1MibFS.fat
     -rw-rw-r--. 1 jfasch jfasch 1.0M Mar  7 17:32 /tmp/1MibFS.fat
     $ mkfs.vfat /tmp/1MibFS.fat 

* ``/dev/random``: kernel, respectively drivers, collect entropy from
  certain kinds of interrupts.

  .. code-block:: console

     $ ls -l /dev/random
     crw-rw-rw-. 1 root root 1, 8 Mar  7 12:10 /dev/random
     $ cat /dev/random
