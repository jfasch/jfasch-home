.. ot-topic:: linux.toolchain.raspi.toolchain_setup
   :dependencies: linux.toolchain.cross.basics

.. include:: <mmlalias.txt>


Cross Toolchain Setup
=====================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`toolchain-build-docker-fedora`

Download And Install Toolchain Archive
--------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/archiving-compression/group`

   **Download**

   * `armv8-rpi4-linux-gnueabihf.tar.xz
     <https://drive.google.com/file/d/1YAlNEQT9UY-z-nVWX-U55i0Zl1TNUfjB/view?usp=share_link>`__

* Create a directory, say, ``~/toolchains`` (you might well choose a
  different name). We will use that directory as a well-known place to
  put our toolchains in. (Toolchains tend to be updated a lot, and
  keeping different versions together in one directory helps
  organizing our work.)
* `Download
  <https://drive.google.com/file/d/1YAlNEQT9UY-z-nVWX-U55i0Zl1TNUfjB/view?usp=share_link>`__
  the toolchain archive (a whopping 70MB)
* Unpack the archive into ``~/toolchains``, as follows

  * Change into toolchain install directory

  .. code-block:: console
  
     $ cd ~/toolchains

  * Get an overview of the download, and see what's in it

  .. code-block:: console

     $ ls -l ~/Downloads/armv8-rpi4-linux-gnueabihf-gcc-10.2-glibc-2.31.tar.xz 
     -rw-r--r--. 1 jfasch jfasch 73018472 May 12 08:16 Downloads/armv8-rpi4-linux-gnueabihf-gcc-10.2-glibc-2.31.tar.xz

  .. code-block:: console

     $ tar -t -f ~/Downloads/armv8-rpi4-linux-gnueabihf-gcc-10.2-glibc-2.31.tar.xz | head
     armv8-rpi4-linux-gnueabihf/
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/usr/
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/usr/include/
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/usr/include/asm-generic/
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/usr/include/asm-generic/auxvec.h
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/usr/include/asm-generic/bitsperlong.h
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/usr/include/asm-generic/bpf_perf_event.h
     armv8-rpi4-linux-gnueabihf/armv8-rpi4-linux-gnueabihf/sysroot/usr/include/asm-generic/errno-base.h

  * If you are fine, unpack it. This will create a directory
    ``~/toolchains/armv8-rpi4-linux-gnueabihf`` - our toolchain base
    directory.

  .. code-block:: console

     $ tar -x -f ~/Downloads/armv8-rpi4-linux-gnueabihf-gcc-10.2-glibc-2.31.tar.xz

  .. code-block:: console

     $ ls -l ~/toolchains/
     total 0
     dr-xr-xr-x. 1 jfasch jfasch 128 Apr 17 12:01 armv8-rpi4-linux-gnueabihf

Establish CMake Toolchain File
------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`

   **Download**

   * CMake toolchain file: :download:`armv8-rpi4-linux-gnueabihf.cmake`

* :download:`Download the toolchain file
  <armv8-rpi4-linux-gnueabihf.cmake>` into ``~/toolchains``
* The *toolchain file* describes toolchain parameters for cross builds
  that you will perform using CMake, eventually. Modify the downloaded
  file to reflect your situation, by changing the following line:

  .. code-block:: text

     set(TOOLCHAIN_BASE_DIR /home/jfasch/toolchains/armv8-rpi4-linux-gnueabihf)

Test Run
--------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`

* You already have a CMake project that you maintain. Lets assume this
  is ``~/project-source`` (a Git clone maybe).
* Create another build directory - this time for a Raspi cross build:

  .. code-block:: console

     $ mkdir ~/project-build-raspi

  ... and change into it:

  .. code-block:: console

     $ cd ~/project-build-raspi

* Create the cross build instructions

  .. code-block:: console

     $ pwd
     /home/jfasch/project-build-raspi
     $ cmake -DCMAKE_TOOLCHAIN_FILE=$HOME/toolchains/armv8-rpi4-linux-gnueabihf.cmake ~/project-source
     ... roedel ...

* Build it

  .. code-block:: console

     $ pwd
     /home/jfasch/project-build-raspi
     $ make
     ... roedel roedel...
