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
  :doc:`/trainings/material/soup/linux/toolchain/cross/raspberry`
* *Toolchain*: usually a ``$PATH`` setting and a compiler name
  (``arm-linux-gnueabihf-gcc``)
* *Sysroot*: a directory with target artifacts

In its raw form:

.. code-block:: console

   $ PATH=/home/jfasch/cross/toolchains/gcc-linaro-12.0.1-2022.02-x86_64_arm-linux-gnueabihf/bin:$PATH
   $ export PATH
   $ arm-linux-gnueabihf-gcc --sysroot ~/cross/sysroots/raspberry -o hello-single hello-single.c 

CMake: "Toolchain Files"
------------------------

A typical (simple) ``CMakeLists.txt`` ...

.. code-block:: cmake

   ADD_LIBRARY(greet hello.h hello.c hello-flexible.c)
   
   ADD_EXECUTABLE(hello-first hello-first.c)
   TARGET_LINK_LIBRARIES(hello-first greet)
   
   ADD_EXECUTABLE(hello-second hello-second.c)
   TARGET_LINK_LIBRARIES(hello-second greet)

* Build instructions are target agnostic
* What goes in a library?
* What goes into an executable?
* What does an executable depend on?
