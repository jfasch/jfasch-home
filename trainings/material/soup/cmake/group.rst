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

.. toctree::
   :maxdepth: 1

   basics
   libraries
   shared-libraries
   installation
   structure
   cxx
   configure_file
   optional-code-problem
   optional-code-approach-1
   targets-properties

.. contents::
   :local:

Approach 2: Remove Too Much CMake Optionality
---------------------------------------------

* Remove optional descending from toplevel ``CMakeLists.txt``
* Remove optional dependency from ``libhello``
* Remove ``DEMO_USE_BLACKLIST`` from ``DemoConfig.h.in``
* Test (|longrightarrow| macro not defined)

  .. code-block:: console

     $ cmake -DUSE_BLACKLIST=ON  ~/work/jfasch-home/trainings/material/soup/cmake/code/
     $ make
     greeter-name.h:8:3: error: #error DEMO_USE_BLACKLIST not defined
     8 | # error DEMO_USE_BLACKLIST not defined
       |   ^~~~~

* How to solve? Where to define macro?

Approach 2: ``TARGET_COMPILE_DEFINITIONS()`` (``backlist`` Availablility)
-------------------------------------------------------------------------

.. sidebar:: 
   
   **Documentation**

   * `TARGET_COMPILE_DEFINITIONS()
     <https://cmake.org/cmake/help/latest/command/target_compile_definitions.html>`__
   * `TARGET_COMPILE_OPTIONS()
     <https://cmake.org/cmake/help/latest/command/target_compile_options.html>`__

* Let ``blacklist`` announce its availability to its dependers
* |longrightarrow| ``TARGET_COMPILE_DEFINITIONS()``

  .. code-block:: console
     :caption: ``blacklist/CMakeLists.txt``

     TARGET_COMPILE_DEFINITIONS(blacklist PUBLIC DEMO_USE_BLACKLIST=1)

* Test

  * ``cmake -DUSE_BLACKLIST=ON ...`` |longrightarrow| works
  * ``cmake -DUSE_BLACKLIST=OFF ...`` |longrightarrow| blacklist still
    used

* |longrightarrow| put optionality in ``blacklist``

Approach 2: Push Optionality Down In ``blacklist`` (|longrightarrow| ``INTERFACE`` Targets)
-------------------------------------------------------------------------------------------

* Naive approach

  .. code-block:: console

     IF (${USE_BLACKLIST})
       ADD_LIBRARY(blacklist blacklist.cpp)
     
       TARGET_INCLUDE_DIRECTORIES(blacklist PUBLIC .)
       TARGET_COMPILE_DEFINITIONS(blacklist PUBLIC DEMO_USE_BLACKLIST=1)
     ELSE()
       TARGET_COMPILE_DEFINITIONS(blacklist PUBLIC DEMO_USE_BLACKLIST=0)
     ENDIF()

  .. code-block:: console

     $ cmake -DUSE_BLACKLIST=OFF  ~/work/jfasch-home/trainings/material/soup/cmake/code/
     CMake Error at blacklist/CMakeLists.txt:7 (TARGET_COMPILE_DEFINITIONS):
       Cannot specify compile definitions for target "blacklist" which is not
       built by this project.
     
     -- Configuring incomplete, errors occurred!

* ``INTERFACE`` targets: dependency nodes, but without anything that's
  built
* Can have dependencies itself (``TARGET_LINK_LIBRARIES()``)
* Ours has ``TARGET_COMPILE_DEFINITIONS()``

  .. code-block:: console

     IF (${USE_BLACKLIST})
       ADD_LIBRARY(blacklist blacklist.cpp)
     
       TARGET_INCLUDE_DIRECTORIES(blacklist PUBLIC .)
       TARGET_COMPILE_DEFINITIONS(blacklist INTERFACE DEMO_USE_BLACKLIST=1) # <--- INTERFACE
     ELSE()
       ADD_LIBRARY(blacklist INTERFACE)
       TARGET_COMPILE_DEFINITIONS(blacklist INTERFACE DEMO_USE_BLACKLIST=0) # <--- INTERFACE
     ENDIF()

Target Types
------------

.. sidebar::

   **Documentation**

   * `ADD_LIBRARY()
     <https://cmake.org/cmake/help/latest/command/add_library.html>`__
   * `ADD_EXECUTABLE()
     <https://cmake.org/cmake/help/latest/command/add_executable.html>`__

* Two basic types: ``ADD_EXECUTABLE()`` and ``ADD_LIBRARY()``
* ``ADD_EXECUTABLE()`` is not relevant ...

  * Only entry point into dependency graph
  * |longrightarrow| does not propagate anything to dependers
  * There *are no* dependers

* ``ADD_LIBRARY()`` ...

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Type
       * Description
     * * Normal library
       * ``STATIC`` (default), ``SHARED``, ``MODULE``. *Has sources to
         be built.*
     * * Object libraries
       * Technically much like normal libraries, but *not* an archive
         or shared object (only virtual, implemented by CMake)
     * * Interface libraries
       * No sources; only there to propagate properties to dependers,
         and to have further dependencies on their own.

Properties
----------

(For a complete list see `ADD_LIBRARY()
<https://cmake.org/cmake/help/latest/command/add_library.html>`__)

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Target function 
     * Property name
     * Description
     * Documentation
   * * ``TARGET_COMPILE_DEFINITIONS()``
     * ``COMPILE_DEFINITIONS``
     * Macros set on the compiler command line (``-Dname=value``)
     * `TARGET_COMPILE_DEFINITIONS()
       <https://cmake.org/cmake/help/latest/command/target_compile_definitions.html>`__
   * * ``TARGET_COMPILE_OPTIONS()``
     * ``COMPILE_OPTIONS``
     * Non-macro compiler flags/options
     * `TARGET_COMPILE_OPTIONS()
       <https://cmake.org/cmake/help/latest/command/target_compile_options.html>`__
   * * ``TARGET_INCLUDE_DIRECTORIES()``
     * ``INCLUDE_DIRECTORIES``
     * Include directories
     * `TARGET_INCLUDE_DIRECTORIES()
       <https://cmake.org/cmake/help/latest/command/target_include_directories.html>`__
   * * ``TARGET_LINK_LIBRARIES()``
     * (Much more complicated, see documentation)
     * Dependencies, in the widest sense
     * `TARGET_LINK_LIBRARIES()
       <https://cmake.org/cmake/help/latest/command/target_link_libraries.html>`__

Properties: ``PRIVATE``, ``PUBLIC``, ``INTERFACE``?
---------------------------------------------------

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

Dependencies
------------

.. ot-graph::
   :entries: cmake
