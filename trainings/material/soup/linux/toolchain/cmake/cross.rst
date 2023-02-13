.. ot-topic:: linux.toolchain.cmake_cross
   :dependencies: linux.toolchain.cmake_local

.. include:: <mmlalias.txt>


CMake: Cross Build
==================

.. sidebar:: 

   **Source Code**

   The example code in this section is maintained on `Github
   <https://github.com/jfasch/jfasch-home-linux-toolchain>`__

.. contents::
   :local:

Cross Build: Parameters
-----------------------

* Cross build parameters "toolchain" and "sysroot"
* See :doc:`/trainings/material/soup/linux/toolchain/cross/basics` and
  :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
* *Toolchain*: usually a ``$PATH`` setting and a compiler name
  (``arm-linux-gnueabihf-gcc``)
* *Sysroot*: a directory with target artifacts

In its raw form:

.. code-block:: console

   $ PATH=/home/jfasch/cross/toolchains/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf/bin:$PATH
   $ export PATH
   $ arm-linux-gnueabihf-gcc --sysroot ~/cross/sysroots/raspberry -o hello-single hello-single.c 

Core Build Instructions: *Target Agnostic*
------------------------------------------

A typical (simple) ``CMakeLists.txt`` ...

.. code-block:: cmake

   ADD_LIBRARY(greet hello.h hello.c hello-flexible.c)

   ADD_EXECUTABLE(hello-first hello-first.c)
   TARGET_LINK_LIBRARIES(hello-first greet)

   ADD_EXECUTABLE(hello-second hello-second.c)
   TARGET_LINK_LIBRARIES(hello-second greet)

* Build instructions are target-agnostic
* What goes in a library?
* What goes into an executable?
* What does an executable depend on?

Toolchain Files
---------------

.. sidebar:: Documentation

   * `Cross Compiling With CMake
     <https://cmake.org/cmake/help/book/mastering-cmake/chapter/Cross%20Compiling%20With%20CMake.html>`__
   * `CMAKE_SYSROOT
     <https://cmake.org/cmake/help/latest/variable/CMAKE_SYSROOT.html>`__

* ``CMakeLists.txt`` is target-agnostic
* By default: native compilation
* Parameters *Sysroot* and *Toolchain* are set in per-target
  "toolchain files"

.. literalinclude:: ../jfasch-home-linux-toolchain/cmake/Toolchain-RaspberryPi.cmake
   :language: cmake
   :caption: :download:`../jfasch-home-linux-toolchain/cmake/Toolchain-RaspberryPi.cmake`

Step 1: Generate ``Makefile`` in Build Directory
------------------------------------------------

Sadly, cross build is a little more involved than native build - even
with CMake ...

.. code-block:: console
   
   $ cd /home/jfasch/build-pi
   $ cmake -DCMAKE_TOOLCHAIN_FILE=/home/jfasch/source/Toolchain-RaspberryPi.cmake /home/jfasch/source
   -- The CXX compiler identification is GNU 11.2.1
   -- Detecting CXX compiler ABI info
   -- Detecting CXX compiler ABI info - done
   -- Check for working CXX compiler: /usr/bin/c++ - skipped
   -- Detecting CXX compile features
   -- Detecting CXX compile features - done
   -- Configuring done
   -- Generating done
   -- Build files have been written to: /home/jfasch/build-pi


This creates a ``Makefile`` in the *build directory*

* Used as usual
* Only generated |longrightarrow| basically unreadable

Step 2: Build Using ``make``
----------------------------

.. code-block:: console

   $ pwd
   /home/jfasch/build-pi
   $ make
   [ 14%] Building C object CMakeFiles/greet.dir/hello.c.o
   [ 28%] Building C object CMakeFiles/greet.dir/hello-flexible.c.o
   [ 42%] Linking C static library libgreet.a
   [ 42%] Built target greet
   [ 57%] Building C object CMakeFiles/hello-second.dir/hello-second.c.o
   [ 71%] Linking C executable hello-second
   [ 71%] Built target hello-second
   [ 85%] Building C object CMakeFiles/hello-first.dir/hello-first.c.o
   [100%] Linking C executable hello-first
   [100%] Built target hello-first

Et voila:

.. code-block:: console

   $ ls -l 
   total 96
   -rw-rw-r--. 1 jfasch jfasch 13921 Apr 22 10:58 CMakeCache.txt
   drwxrwxr-x. 7 jfasch jfasch   280 Apr 22 11:02 CMakeFiles
   -rw-rw-r--. 1 jfasch jfasch  1688 Apr 22 10:58 cmake_install.cmake
   -rwxrwxr-x. 1 jfasch jfasch 26192 Apr 22 11:02 hello-first
   -rwxrwxr-x. 1 jfasch jfasch 27920 Apr 22 11:02 hello-second
   -rw-rw-r--. 1 jfasch jfasch  8102 Apr 22 11:02 libgreet.a
   -rw-rw-r--. 1 jfasch jfasch  8503 Apr 22 10:58 Makefile

.. code-block:: console

   $ file hello-first 
   hello-first: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux-armhf.so.3, BuildID[sha1]=5db807d9b005b19e1e0c957755fa7ca7b771edcb, for GNU/Linux 3.2.0, with debug_info, not stripped
