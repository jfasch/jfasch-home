.. include:: <mmlalias.txt>


Cross Toolchain Setup
=====================

.. sidebar::

   **See also**

   * :doc:`toolchain-build-docker-fedora`

.. contents::
   :local:

Download And Install Toolchain Archive
--------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/archiving-compression/index`

   **Download**

   * `armv8-rpi4-linux-gnueabihf-gcc-10.2-glibc-2.31.tar.xz
     <https://drive.google.com/file/d/1FskznIXk4v_1JFyFbHtNLjC_WPDOLehH/view?usp=sharing>`__

* Create a directory, say, ``~/x-tools`` (the :doc:`Crosstool-NG
  </blog/2022/09/cross-raspi>` default name, you might well choose a
  different name). We will use that directory as a well-known place to
  put our toolchains in. (Toolchains tend to be updated a lot, and
  keeping different versions together in one directory helps organize
  our work.)
* `Download
  <https://drive.google.com/file/d/1FskznIXk4v_1JFyFbHtNLjC_WPDOLehH/view?usp=sharing>`__
  the toolchain archive (a whopping 70MB)
* Unpack the archive into ``~/x-tools``, as follows

  * Change into toolchain install directory

  .. code-block:: console

     $ mkdir ~/x-tools
     $ cd ~/x-tools

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
     ...

  * If you are fine, unpack it. This will create a directory
    ``~/x-tools/armv8-rpi4-linux-gnueabihf`` - our toolchain base
    directory.

  .. code-block:: console

     $ tar -x -f ~/Downloads/armv8-rpi4-linux-gnueabihf-gcc-10.2-glibc-2.31.tar.xz

  .. code-block:: console

     $ ls -l ~/x-tools/
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
  <armv8-rpi4-linux-gnueabihf.cmake>` into ``~/x-tools``
* The *toolchain file* describes toolchain parameters for cross builds
  that you will perform using CMake, eventually. Modify the downloaded
  file to reflect your situation, by changing the following line:

  .. code-block:: text

     set(TOOLCHAIN_BASE_DIR /home/jfasch/x-tools/armv8-rpi4-linux-gnueabihf)

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
     $ cmake -DCMAKE_TOOLCHAIN_FILE=$HOME/x-tools/armv8-rpi4-linux-gnueabihf.cmake ~/project-source
     ... roedel ...

* Build it

  .. code-block:: console

     $ pwd
     /home/jfasch/project-build-raspi
     $ make
     ... roedel roedel...
