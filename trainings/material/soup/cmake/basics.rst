.. ot-topic:: cmake.basics
.. include:: <mmlalias.txt>


Basics: Boilerplate, And Executables
====================================

.. contents::
   :local:

Single Monolithic Executable
----------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/toolchain/basics/topic`

   **Source**

   .. code-block:: console

      01-single/
      ├── CMakeLists.txt
      └── hello-single.c

   * :download:`01-single/CMakeLists.txt`
   * :download:`01-single/hello-single.c`

* First: toolchain
* :doc:`/trainings/material/soup/linux/toolchain/basics/topic`
* Default output name: ``a.out``

  .. code-block:: console

     $ gcc hello-single.c
     $ ./a.out 
     Hello World

* Explicit output name

  .. code-block:: console

     $ gcc -o hello-single hello-single.c 
     $ ./hello-single 
     Hello World

* Wish list item: out-of-source build (Git requires me to
  ``.gitignore`` output files, for example)
* |longrightarrow| CMake

Building With CMake
-------------------

.. sidebar::

   **Documentation**

   * `CMAKE_MINIMUM_REQUIRED()
     <https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html>`__
   * `PROJECT()
     <https://cmake.org/cmake/help/latest/command/project.html>`__
   * `ADD_EXECUTABLE()
     <https://cmake.org/cmake/help/latest/command/add_executable.html>`__

* ``CMakeLists.txt`` (top-level, others will follow once we have
  subdirectories)

  .. code-block:: console
     :caption: :download:`01-single/CMakeLists.txt`

     CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
     PROJECT(Demo)
     ADD_EXECUTABLE(hello-single hello-single.c)

* ``CMAKE_MINIMUM_REQUIRED()``: required by CMake; used to declare
  which features we will need (or fail)
* ``PROJECT()``: used in many corners, e.g. package names

  * ``VERSION`` parameter (optional); used later when building shared
    libraries
* ``ADD_EXECUTABLE()``

Building With CMake: Separate Source And Build Directories
----------------------------------------------------------

* *Source directory*,
  e.g. ``/home/jfasch/work/jfasch-home/trainings/material/soup/cmake/01-single``
* Build directory, e.g. ``/tmp/build``

  * Not version controlled |longrightarrow| does not interfere with
    version control
  * Completely resurrectable
  * Not subject to backups
  * Cheap storage medium

* Simplest way of building

  * Change to build directory
  * Call ``cmake`` to build ``Makefile`` skeleton (or ``ninja``) *from
    the source directory*
  * Call ``make`` (or ``ninja``, for that matter) *in the build
    directory*

.. code-block:: console
   :caption: Create ``Makefile`` structure

   $ cd /tmp/build
   $ cmake /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/01-single
   -- The C compiler identification is GNU 12.2.1
   -- The CXX compiler identification is GNU 12.2.1
   -- Detecting C compiler ABI info
   -- Detecting C compiler ABI info - done
   -- Check for working C compiler: /usr/bin/cc - skipped
   -- Detecting C compile features
   -- Detecting C compile features - done
   -- Detecting CXX compiler ABI info
   -- Detecting CXX compiler ABI info - done
   -- Check for working CXX compiler: /usr/bin/c++ - skipped
   -- Detecting CXX compile features
   -- Detecting CXX compile features - done
   -- Configuring done (0.7s)
   -- Generating done (0.0s)
   -- Build files have been written to: /tmp/build
   
.. code-block:: console
   :caption: Build using ``make``

   $ make
   [ 50%] Building C object CMakeFiles/hello-single.dir/hello-single.c.o
   [100%] Linking C executable hello-single
   [100%] Built target hello-single

Executables Consisting Of Multiple Sources
------------------------------------------

.. sidebar::

   **Source**

   .. code-block:: console

      02-modular/
      ├── CMakeLists.txt
      ├── hello.c
      ├── hello.h
      └── hello-main.c

   * :download:`02-modular/CMakeLists.txt`
   * :download:`02-modular/hello-main.c`
   * :download:`02-modular/hello.h`
   * :download:`02-modular/hello.c`

* Programs are rarely so simple
* Separate compilation units
* |longrightarrow| potential code re-use
* ``ADD_EXECUTABLE()`` can take more than one source file parameters

.. code-block:: console

   ADD_EXECUTABLE(hello-modular hello-main.c hello.c)

Problem: Duplicate Compilation
------------------------------

.. sidebar::

   **Source**

   .. code-block:: console

      03-two-users-duplicate-compilation/
      ├── CMakeLists.txt
      ├── hello.c
      ├── hello-first.c
      ├── hello.h
      └── hello-second.c
      
   * :download:`03-two-users-duplicate-compilation/CMakeLists.txt`
   * :download:`03-two-users-duplicate-compilation/hello-first.c`
   * :download:`03-two-users-duplicate-compilation/hello-second.c`
   * :download:`03-two-users-duplicate-compilation/hello.h`
   * :download:`03-two-users-duplicate-compilation/hello.c`

* Maybe show raw toolchain in action:
  :doc:`/trainings/material/soup/linux/toolchain/separate-compilation/topic`
* Duplication of build rules (``hello.c`` is built twice)

  .. code-block:: console

     ADD_EXECUTABLE(hello-first hello-first.c hello.c)
     ADD_EXECUTABLE(hello-second hello-second.c hello.c)

Problem: More Functionality
---------------------------

.. sidebar::

   **Source**

   .. code-block:: console

      04-more-functionality/
      ├── CMakeLists.txt
      ├── hello.c
      ├── hello-first.c
      ├── hello.h
      ├── hello-name.c
      ├── hello-name.h
      └── hello-second.c
            
   * :download:`04-more-functionality/CMakeLists.txt`
   * :download:`04-more-functionality/hello-first.c`
   * :download:`04-more-functionality/hello-second.c`
   * :download:`04-more-functionality/hello.h`
   * :download:`04-more-functionality/hello.c`
   * :download:`04-more-functionality/hello-name.c`
   * :download:`04-more-functionality/hello-name.h`

* Download ``hello-name.{h,c}`` (add new function ``hello_name()``)
* Call in both executables. Live-hack commandline args.

  * ``hello-first`` takes only ``argv[1]``
  * ``hello-second`` is more elaborate: all the rest

.. literalinclude:: 04-more-functionality/hello-name.h
   :caption: :download:`04-more-functionality/hello-name.h`
   :language: c

.. literalinclude:: 04-more-functionality/hello-name.c
   :caption: :download:`04-more-functionality/hello-name.c`
   :language: c

Solution: Libraries
-------------------

* Bag of object file
* Come in *shared* flavors
