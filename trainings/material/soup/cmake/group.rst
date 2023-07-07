.. ot-group:: cmake

.. include:: <mmlalias.txt>


CMake: An Introduction
======================

.. image:: logo.jpg
   :alt: CMake logo
   :align: right
   :scale: 50%

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
	* * One day
      * * **Course Language**
	* * Course material language is English
	  * Trainer language is English or German
      * * **Booking**
	* training@faschingbauer.co.at

Basics: Boilerplate, And Executables
------------------------------------

Single Monolithic Executable
............................

* 1-single
* :doc:`/trainings/material/soup/linux/toolchain/basics/topic`
* ``PROJECT()``
  (https://cmake.org/cmake/help/latest/command/project.html)

  |longrightarrow| ``VERSION`` parameter (optional); used later
  when building shared libraries

Executables Consisting Of Multiple Sources
.......................................... 

* 2-modular
* factor ``hello()`` out into separate compilation unit
* add as second file to ``ADD_EXECUTABLE()``

Problem: Duplicate Compilation
..............................

* 3-two-users-duplicate-compilation
* :doc:`/trainings/material/soup/linux/toolchain/separate-compilation/topic`

Problem: More Functionality
...........................

* 4-more-functionality
* Add new function ``hello_name()``
* Call in both executables. Live-hack commandline args.

  * ``hello-first`` takes only ``argv[1]``
  * ``hello-second`` is more elaborate: all the rest

Libraries
---------

* 5-static-libraries
* :doc:`/trainings/material/soup/linux/toolchain/static-library/topic`
* dependencies
* project sanity
* dot files

More About Libraries: *Shared Libraries*
----------------------------------------

* 6-shared-libraries-preview
* Normal libraries

  * ``STATIC``
  * ``SHARED``
  * ``MODULE``: no ``SONAME``, and version symlinks
  * ``-DBUILD_SHARED_LIBS=ON``

* ``OBJECT``: bags of object files, not contained in a library of
  whatever form
* ``INTERFACE``: does not contain any compiled sources; for
  propagation of properties such as include paths (|longrightarrow|
  later jjj)

* Build with ``-DBUILD_SHARED_LIBS=ON``
* More about *loading*

  * Program interpreter |longrightarrow| hash bang in scripts
  * ``/etc/ld.so.conf``
  * Library ``SONAME`` and ``NEEDED`` tags |longrightarrow| look in
    ``/usr/lib64/``

    .. code-block:: console

	 $ rpm -qf /usr/lib64/libboost_regex.so.1.76.0
	 $ sudo dnf install boost-devel

    * A-ha: development versions
  
      .. code-block:: console
  
         $ ls -l /usr/lib64/libboost_regex*
         lrwxrwxrwx. 1 root root     24 Jul 14  2022 /usr/lib64/libboost_regex.so -> libboost_regex.so.1.76.0
         -rwxr-xr-x. 1 root root 289264 Jul 14  2022 /usr/lib64/libboost_regex.so.1.76.0

  * Temporarily add 

    .. code-block:: console

	 SET_PROPERTY(TARGET hello PROPERTY VERSION "1")``

    and modify to 

    .. code-block:: console

	 PROJECT(Demo VERSION "1.0.0")
	 SET_PROPERTY(TARGET hello PROPERTY VERSION ${PROJECT_VERSION})

    Discuss ABI versions (|longrightarrow| rarely project versions
    can be used as ABI versions)

* |longrightarrow| can of worms: **installation/deployment**

Installation
------------

* 7-install-basic
* *Prefix* (e.g. ``/usr``): ``-DCMAKE_INSTALL_PREFIX``
* https://cmake.org/cmake/help/latest/command/install.html
* Only library and executable installation for now; more:

  * Header files: ``TARGET/{PUBLIC,PRIVATE}_HEADER``
  * Regular ``FILES``

.. code-block:: console

   $ tree ~/tmp/cmake-demo-install/
   /home/jfasch/tmp/cmake-demo-install/
   ├── bin
   │   ├── hello-first
   │   └── hello-second
   └── lib
       └── libhello.so

* And ``SONAME``?

  ``SET_PROPERTY(TARGET hello PROPERTY VERSION "1")`` (already in
  place)

.. code-block:: console

   $ tree ~/tmp/cmake-demo-install/
   /home/jfasch/tmp/cmake-demo-install/
   ├── bin
   │   ├── hello-first
   │   └── hello-second
   └── lib
       ├── libhello.so -> libhello.so.1.0.0
       └── libhello.so.1.0.0

* Running installed programs in the face of shared libraries

  .. code-block:: console

     $ ~/tmp/cmake-demo-install/bin/hello-first 
     /home/jfasch/tmp/cmake-demo-install/bin/hello-first: error while loading shared libraries: libhello.so.1.0.0: cannot open shared object file: No such file or directory

* Running uninstalled programs (from the build tree)

  .. code-block:: console

     $ ./hello-first 
     Hello World

* Why? |longrightarrow| ``RUNPATH`` ELF attribute

  .. code-block:: console

     $ readelf --dynamic ./hello-first 
     ...
     0x0000000000000001 (NEEDED)             Shared library: [libhello.so.1.0.0]
     0x000000000000001d (RUNPATH)            Library runpath: [/home/jfasch/tmp/cmake-demo:]
     ...

  ``RUNPATH`` is missing from the installed version; removed during
  installation

  .. code-block:: console

     $ make install
     ...
     -- Set runtime path of "/home/jfasch/tmp/cmake-demo-install/bin/hello-first" to ""
     -- Set runtime path of "/home/jfasch/tmp/cmake-demo-install/bin/hello-second" to ""
     ...

Structure - Subdirectories, Dependencies, and Include Paths
-----------------------------------------------------------

* 8-structure
* https://cmake.org/cmake/help/latest/command/add_subdirectory.html
* Descend into ``libhello/`` and ``bin/``

  * Move files around
  * Move Cmake code around
  * *Miss to care about include paths*

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

* Hmm: dependencies! Build and show graph again
* Add to target property ``INCLUDE_DIRECTORIES``
  (https://cmake.org/cmake/help/latest/prop_tgt/INCLUDE_DIRECTORIES.html#prop_tgt:INCLUDE_DIRECTORIES)

  .. code-block:: console

     TARGET_INCLUDE_DIRECTORIES(hello PUBLIC .)

* ``TARGET_INCLUDE_DIRECTORIES()``
  (https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories)
* ``PUBLIC`` vs. ``PRIVATE``

  * ``PUBLIC`` *propagated* to *dependers* (see/show ``.dependers``
    dot file) so they can find the headers of targets they depend on
  * ``PRIVATE`` does not propagate. One might structure (internally
    only) a target's source code into ``src/`` and ``inc/`` for
    example.

Switch To C++
-------------

* 9-c++
* C++ standard

  .. code-block:: console

     set(CMAKE_CXX_STANDARD 23)

* jjj class diagram (doxygen?)

Debugging (``MESSAGE()``, etc)
------------------------------

``MESSAGE()``: Usage, Pitfalls
..............................

.. sidebar::

   **Documentation**

   * `message
     <https://cmake.org/cmake/help/latest/command/message.html>`__

* Basic usage

  .. code-block:: console
  
     MESSAGE("Howdy")
  
  is the same as
  
  .. code-block:: console
  
     MESSAGE(NOTICE "Howdy")

  is the same as

  .. code-block:: console
  
     MESSAGE(Howdy)          # <--- root of all evil (one of roots)

|longrightarrow| all sorts of ... crap:

* Tags? Enums? *No!*

  .. code-block:: console

     MESSAGE(WARNING "Howdy")

  Prints, as expected ...

  .. code-block:: console

     CMake Warning at CMakeLists.txt:5 (MESSAGE):
       Howdy
		  
  .. code-block:: console

     MESSAGE(BULLSHIT "Howdy")

  Prints ...

  .. code-block:: console

     cd ~/tmp/cmake-demo&&cmake ~/work/jfasch-home/trainings/material/soup/cmake/code/
     BULLSHITHowdy

``MESSAGE()``: Popular "Modes"
..............................

More: `Documentation (message)
<https://cmake.org/cmake/help/latest/command/message.html>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Mode
     * Description
   * * ``FATAL_ERROR``
     * CMake Error, stop processing and generation.
   * * ``SEND_ERROR``
     * CMake Error, continue processing, but skip generation.
   * * ``WARNING``
     * CMake Warning, continue processing.
   * * (none) or ``NOTICE``
     * Important message printed to stderr to attract user's attention.
   * * ``STATUS``
     * The main interesting messages that project users might be
       interested in. Ideally these should be concise, no more than a
       single line, but still informative.
   * * ``VERBOSE``
     * Detailed informational messages intended for project
       users. These messages should provide additional details that
       won't be of interest in most cases, but which may be useful to
       those building the project when they want deeper insight into
       what's happening.
   * * ``DEBUG``
     * Detailed informational messages intended for developers working
       on the project itself as opposed to users who just want to
       build it. These messages will not typically be of interest to
       other users building the project and will often be closely
       related to internal implementation details.
   * * ``TRACE``
     * Fine-grained messages with very low-level implementation
       details. Messages using this log level would normally only be
       temporary and would expect to be removed before releasing the
       project, packaging up the files, etc.

.. code-block:: console

   $ cmake --help
   ...
   --log-level=<ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE>
   ...

.. attention::

   All of this lacks a clear definition. Apparently ...

   * Ordering appear to be ``ERROR > WARNING > NOTICE > STATUS >
     VERBOSE > DEBUG > TRACE``
   * ``STATUS`` is the default "level"

Configured Header File (``CONFIGURE_FILE()``)
---------------------------------------------

* 10-configure-file

Problem
.......

* Want to output project version in executables
* |longrightarrow| Set version using ``PROJECT()``

  .. code-block:: console
  
     PROJECT(Demo VERSION 42.666)
     MESSAGE(DEBUG "Major: ${Demo_VERSION_MAJOR}")
     MESSAGE(DEBUG "Major: ${Demo_VERSION_MINOR}")

* Compiled code does not have access to CMake variables

Solution: Configure Files
.........................

* Convert CMake variables to *macros* using ``CONFIGURE_FILE()``

  .. code-block:: console
  
     CONFIGURE_FILE(DemoConfig.h.in DemoConfig.h)

* ``DemoConfig.h.in`` contents

  .. code-block:: c++

     // This file is generated, do not modify
     
     #define DEMO_MAJOR @Demo_VERSION_MAJOR@
     #define DEMO_MINOR @Demo_VERSION_MINOR@

* Converted to ``${CMAKE_CURRENT_BINARY_DIR}/DemoConfig.h``

Use In Executables
..................

* Pick up CMake variables from configure file

.. code-block:: c++

   #include <DemoConfig.h>
   // ...
   std::cout << "Version " << DEMO_MAJOR << '.' << DEMO_MINOR << std::endl;

* Does not compile |longrightarrow| include path missing

.. code-block:: console

   bin/hello-first.cpp:4:10: fatal error: DemoConfig.h: No such file or directory
       4 | #include <DemoConfig.h>
         |          ^~~~~~~~~~~~~~
   
* Solution: set include path *for all* (to add a dependency would be
  overkill but could be done)

.. code-block:: console

   INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

Optional Code
-------------

Problem
.......

* ``hello-second`` licensing requirements
* Must pay extra ``$$`` to be able to greet "Joerg" (and a number of
  other blacklisted names)
* |longrightarrow| separate builds

  * One that ignores a blacklist (pay extra ``$$``)
  * One in the public domain, with restrictions

Solution: Add An Option
.......................

.. sidebar:: 

   **Documentation**

   * `option
     <https://cmake.org/cmake/help/latest/command/option.html>`__
   * `if (and conditionals)
     <https://cmake.org/cmake/help/latest/command/if.html>`__

* Goal: add option ``USE_BLACKLIST`` to be used like

  .. code-block:: console

     $ cmake -DUSE_BLACKLIST=ON ...
     $ cmake -DUSE_BLACKLIST=OFF ...

* Implementation

  * Conditionally build a ``blacklist`` library
  * Provide macro ``DEMO_USE_BLACKLIST`` so ``NameGreeter`` can decide
    whether to use it

Define Option And Macro
.......................

* Define option

  .. code-block:: console
     :caption: Toplevel ``CMakeLists.txt``
  
     OPTION(USE_BLACKLIST "Refuse to greet blacklisted names" ON)

* Normalize option values for better macros usage

.. code-block:: console
   :caption: Toplevel ``CMakeLists.txt``, below ``OPTION()``

   # normalize option strings into numbers (for better macros usage)
   IF (${USE_BLACKLIST} STREQUAL ON)
     SET(USE_BLACKLIST 1)
   ELSEIF (${USE_BLACKLIST} STREQUAL OFF)
     SET(USE_BLACKLIST 0)
   ELSE()
     MESSAGE(DEBUG "USE_BLACKLIST must be ON or OFF (not ${USE_BLACKLIST}); assuming OFF")
     SET(USE_BLACKLIST 0)
   ENDIF()

* Provide macro ``DEMO_USE_BLACKLIST`` which expands to int/bool value

  .. code-block:: c++
     :caption: DemoConfig.h.in

     #define DEMO_USE_BLACKLIST @USE_BLACKLIST@

More Topics
-----------

* Compiler warnings (diverge into it when something fails)
* Multithreading
* C++

  * ``set(CMAKE_CXX_STANDARD 23)``


* Properties, ``INTERFACE`` libraries

  https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Usage%20Requirements%20for%20a%20Library.html#exercise-1-adding-usage-requirements-for-a-library

  * target_compile_definitions()
  * target_compile_options()
  * target_include_directories()
  * target_link_directories()
  * target_link_options()
  * target_precompile_headers()
  * target_sources()

* Using installed project |longrightarrow| install headers

  https://stackoverflow.com/questions/10487256/cmake-how-to-properly-copy-static-librarys-header-file-into-usr-include

* (Much) more about ``SONAME``, ``NEEDED``, ABI versioning, and
  loading |longrightarrow| ``ldconfig``

* Variables

  * ``CMAKE_SOURCE_DIR``
  * ``CMAKE_CURRENT_SOURCE_DIR``
  * ``CMAKE_BINARY_DIR``
  * ``CMAKE_CURRENT_BINARY_DIR``

* Properties
