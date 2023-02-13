.. ot-group:: linux.toolchain


Toolchain, And Cross Development
================================

.. contents::
   :local:

Topics
------

.. sidebar:: 

   **Source Code**

   The example code in this section is maintained on `Github
   <https://github.com/jfasch/jfasch-home-linux-toolchain>`__

   **See also**

   * :doc:`/trainings/material/soup/linux/ssh/group`

An overview of the *toolchain* is given - a collection of tools
(compiler, linker, ...) to transform C/C++ source code into running
executables.

This is followed by an introduction to `CMake <cmake.org>`_, a higher
level build tool that solves many problems that both hand-written
``Makefile`` hacks and IDE-clickabout builds have.

Last, a bit more involved, we see how cross development is
done. Together with :doc:`/trainings/material/soup/linux/ssh/group`,
this enables us to build software for devices that show a different
architecture that the development machine.

.. toctree::
   :maxdepth: 1

   basics/topic
   separate-compilation/topic
   static-library/topic
   shared-libraries/topic
   cross/group
   cmake/stub-cmake-course
   cmake/local
   cmake/cross
   raspberry-pi/group

Exercises
---------

.. toctree::
   :maxdepth: 1

   exercises/group

Dependencies
------------

.. ot-graph::
   :entries: linux.toolchain
