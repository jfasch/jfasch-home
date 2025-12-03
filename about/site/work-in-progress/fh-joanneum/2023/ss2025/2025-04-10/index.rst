.. include:: <mmlalias.txt>


2025-04-10 (3 UE): Linux Host System Setup
==========================================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/basics/index`

Overview: User? Home?
---------------------

.. code-block:: console
   :caption: User credentials

   $ id
   uid=1000(jfasch) gid=1000(jfasch) groups=1000(jfasch),10(wheel),104(input) context=unconfined_u:unconfined_r:unconfined_t:s0-s0:c0.c1023

.. code-block:: console
   :caption: Home directory = current working directory

   $ pwd
   /home/jfasch

Tour Through File System
------------------------

* ``/``

  .. code-block:: console

     $ ls -l /
     ...
     drwxr-xr-x.  21 root root 4300 Apr  7 20:53 dev
     drwxr-xr-x.   1 root root 4908 Apr  3 17:17 etc
     drwxr-xr-x.   1 root root   26 Jan 15 14:08 home
     dr-xr-xr-x. 398 root root    0 Mar 21 16:03 proc
     dr-xr-x---.   1 root root  278 Jan 15 14:57 root
     dr-xr-xr-x.  13 root root    0 Mar 21 16:03 sys
     drwxr-xr-x.   1 root root  168 Jan 15 14:36 usr
     ...

* ``/etc``: system configuration

  .. code-block:: console

     $ ls -l /etc
     ... # user and group database
     -rw-r--r--. 1 root root 2931 Jan 15 14:08 /etc/passwd
     -rw-r--r--. 1 root root 1110 Jan 15 14:08 /etc/group
     ... # service configuration (sshd ...)
     drwxr-xr-x. 1 root root      336 Nov 16 01:00 systemd
     ...

* ``/sys``: hardware device tree (and access)a

  .. code-block:: console

     $ ls -l /sys/bus/
     ...
     drwxr-xr-x. 4 root root 0 Apr  9 15:02 i2c
     drwxr-xr-x. 5 root root 0 Apr  9 15:02 pci
     drwxr-xr-x. 4 root root 0 Apr  9 15:02 spi
     ...

* ``/dev``: hardware device access

  .. code-block:: console

     $ ls -l /dev
     ... # block devices; eg. solid state disk
     brw-rw----.  1 root   disk    259,     0 Mar 21 16:03 nvme0n1
     brw-rw----.  1 root   disk    259,     1 Mar 21 16:03 nvme0n1p1
     brw-rw----.  1 root   disk    259,     2 Mar 21 16:03 nvme0n1p2
     brw-rw----.  1 root   disk    259,     3 Mar 21 16:03 nvme0n1p3
     ... # hardware; e.g. UARTs
     crw-rw----.  1 root   dialout   4,    64 Mar 21 16:03 ttyS0
     crw-rw----.  1 root   dialout   4,    65 Mar 21 16:03 ttyS1
     ... # pseudo devices
     crw-rw-rw-.  1 root   root      1,     8 Mar 21 16:03 random
     crw-rw-rw-.  1 root   root      1,     5 Mar 21 16:03 zero
     
* ``/home``: user home directories
* ``/root``: ``root`` (administrator) home directory
* ``/usr``: executable code (programs and shared libraries - the
  *system runtime*)
* ``/boot``: bootloader specific, kernel image

.. _fh-2025-04-10-workenv:

Work Environment
----------------

.. sidebar:: Git repo

   https://github.com/FH-STECE2023-Org/FH-STECE2023

* Work directories in ``~/My-Projects/`` 
* Build directories in ``~/My-Builds/``

In home directory (``/home/jfasch``)

.. code-block:: console

   $ cd
   $ pwd
   /home/jfasch

.. code-block:: console

   $ mkdir My-{Projects,Builds}

Get Code, Build
...............

.. sidebar:: Git repo

   https://github.com/FH-STECE2023-Org/FH-STECE2023

* Read `build instructions
  <https://github.com/FH-STECE2023-Org/FH-STECE2023/blob/main/README.rst>`__

  .. code-block:: console
  
     $ less ~/My-Projects/FH-STECE2023/README.rst

* Build
