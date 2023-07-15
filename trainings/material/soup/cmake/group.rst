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
   optional-code-approach-2
   targets-properties

.. contents::
   :local:

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
