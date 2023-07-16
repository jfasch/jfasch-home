.. ot-topic:: cmake.structure
   :dependencies: cmake.installation
.. include:: <mmlalias.txt>

Structure - Subdirectories, Dependencies, and Include Paths
===========================================================

.. contents::
   :local:

.. sidebar::

   **Source**

   .. code-block:: console

      08-structure/
      ├── CMakeLists.txt
      ├── bin
      │   ├── CMakeLists.txt
      │   ├── hello-first.c
      │   └── hello-second.c
      └── libhello
          ├── CMakeLists.txt
          ├── hello.c
          ├── hello.h
          ├── hello-name.c
          └── hello-name.h

   * :download:`08-structure/CMakeLists.txt`
   * :download:`08-structure/bin/CMakeLists.txt`
   * :download:`08-structure/bin/hello-first.c`
   * :download:`08-structure/bin/hello-second.c`
   * :download:`08-structure/libhello/CMakeLists.txt`
   * :download:`08-structure/libhello/hello.h`
   * :download:`08-structure/libhello/hello.c`
   * :download:`08-structure/libhello/hello-name.c`
   * :download:`08-structure/libhello/hello-name.h`

Reorganization
--------------

.. sidebar::

   **Documentation**

   * `ADD_SUBDIRECTORY()
     <https://cmake.org/cmake/help/latest/command/add_subdirectory.html>`__

* Descend into ``libhello/`` and ``bin/``

  * Move files around
  * Move CMake code around
  * *Miss to care about include paths*

  .. code-block:: console
     :caption: Toplevel ``CMakeLists.txt``

     ADD_SUBDIRECTORY(libhello)
     ADD_SUBDIRECTORY(bin)

.. code-block:: console

   $ make
   [ 14%] Building C object libhello/CMakeFiles/hello.dir/hello.c.o
   [ 28%] Building C object libhello/CMakeFiles/hello.dir/hello-name.c.o
   [ 42%] Linking C shared library libhello.so
   [ 42%] Built target hello
   [ 57%] Building C object bin/CMakeFiles/hello-first.dir/hello-first.c.o
   /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/code/bin/hello-first.c:1:10: fatal error: hello.h: No such file or directory
       1 | #include "hello.h"
         |          ^~~~~~~~~
   compilation terminated.
   make[2]: *** [bin/CMakeFiles/hello-first.dir/build.make:76: bin/CMakeFiles/hello-first.dir/hello-first.c.o] Error 1
   make[1]: *** [CMakeFiles/Makefile2:144: bin/CMakeFiles/hello-first.dir/all] Error 2
   make: *** [Makefile:136: all] Error 2

Dependencies, And *Target Properties*
-------------------------------------

.. sidebar::

   **Documentation**

   * `TARGET_INCLUDE_DIRECTORIES()
     <https://cmake.org/cmake/help/latest/command/target_include_directories.html>`__

* Dependencies are in place

  .. image:: 08-structure/Demo.png
     :scale: 60%

* Only code has been moved around
* |longrightarrow| ``hello`` header files are now too far away from
  ``bin/`` targets
* Let ``hello`` carry that information

  .. code-block:: console

     TARGET_INCLUDE_DIRECTORIES(hello PUBLIC .)

* |longrightarrow| *propagated* to dependers
* ``PUBLIC`` vs. ``PRIVATE``

  * ``PUBLIC`` *propagated* to *dependers* (see/show ``.dependers``
    dot file) so they can find the headers of targets they depend on
  * ``PRIVATE`` does not propagate. Purpose: e.g., one might structure
    (internally only) a target's source code into ``src/`` and
    ``inc/`` for example.
