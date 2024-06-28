.. ot-topic:: cmake.advanced.library_function_screenplay
   :dependencies: cmake.advanced.targets_properties_pub_priv_inc_screenplay
.. include:: <mmlalias.txt>


Screenplay: Function Wrapping ``add_library()``
===============================================

.. contents::
   :local:

.. sidebar:: Complete source code

   * https://github.com/jfasch/cmake-function-add-library

Streamline Build-Spaghetti: How Want It?
----------------------------------------

* :doc:`../targets-properties/screenplay` was a massacre
* ``toolcase/base/CMakeLists.txt`` has become rather cluttered
  (``base`` ist the worst, the others are ugly too)
* *Wanted*: simple call to ``my_add_library()``, beautifully
  reflecting the situation
* Implicitly dictating the directory structure

  .. code-block:: text

     .
     ├── include
     │   ├── private
     │   └── public
     └── src

.. code-block:: cmake

   my_add_library(
     NAME base 
   
     DEBUG
   
     PUBLIC_HEADERS
   
       sensor.h
       sensor-const.h
       sensor-random.h
       sensor-avg.h
       sensor-w1.h
       switch.h
       sysfs-switch.h
       hysteresis.h
   
     PRIVATE_HEADERS
   
       file-util.h
   
     SOURCES
   
       sensor-const.cpp
       sensor-random.cpp
       sensor-avg.cpp
       sensor-w1.cpp
       sysfs-switch.cpp
       hysteresis.cpp
       file-util.cpp
    )
   
Function ``my_add_library()``: ``cmake_parse_arguments()``
----------------------------------------------------------

.. sidebar:: See also

   * :doc:`../language/functions-and-macros/topic`

.. sidebar:: Documentation

   * `cmake_parse_arguments()
     <https://cmake.org/cmake/help/latest/command/cmake_parse_arguments.html>`__

* In same ``CMakeLists.txt``, define function
* |longrightarrow| ``cmake_parse_arguments()``

  .. code-block:: cmake

     function(my_add_library)
       cmake_parse_arguments(MY_ADD_LIBRARY "SHARED;STATIC" "NAME" "PRIVATE_HEADERS;PUBLIC_HEADERS;SOURCES" ${ARGN})
     
       message("MY_ADD_LIBRARY_SHARED: >${MY_ADD_LIBRARY_SHARED}<")
       message("MY_ADD_LIBRARY_STATIC: >${MY_ADD_LIBRARY_STATIC}<")
       message("MY_ADD_LIBRARY_NAME: >${MY_ADD_LIBRARY_NAME}<")
       message("MY_ADD_LIBRARY_PRIVATE_HEADERS: >${MY_ADD_LIBRARY_PRIVATE_HEADERS}<")
       message("MY_ADD_LIBRARY_PUBLIC_HEADERS: >${MY_ADD_LIBRARY_PUBLIC_HEADERS}<")
       message("MY_ADD_LIBRARY_SOURCES: >${MY_ADD_LIBRARY_SOURCES}<")
     endfunction()
  
* Hmm ... how about error checking? ``SHARED`` *and* ``STATIC``
  passed?
* Externalize into ``my_add_library.cmake``, and develop there (in
  script mode, mostly)
* |longrightarrow| we will use it in other modules too

Function ``my_add_library()``: Final Version
--------------------------------------------

.. literalinclude:: /foreign/cmake-function-add-library/cmake/my_add_library.cmake
   :caption: :download:`my_add_library.cmake (download)
             </foreign/cmake-function-add-library/cmake/my_add_library.cmake>`
   :language: cmake

Make ``my_add_library()`` A Matter For The Architect
----------------------------------------------------

* Put in toplevel ``cmake/`` directory (for all files of similar
  purpose)
* |longrightarrow| add to ``${CMAKE_MODULE_PATH}``
* ``include()`` in toplevel ``CMakeLists.txt``

  * Remove existing ``include()`` from ``base/CMakeLists.txt``
  * **RANT**: when including via ``${CMAKE_MODULE_PATH}``, omit the
    ``.cmake`` extension or the file will not be found

* |longrightarrow| *directory scope* (see
  :doc:`../language/variables/topic`)
* Restructure ``data-logger`` and ``boiling-pot``
* While we are at it, move compiler settings into
  ``/cmake/compiler.cmake``
