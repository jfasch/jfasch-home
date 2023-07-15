.. ot-topic:: cmake.targets_properties
.. include:: <mmlalias.txt>


Targets, Properties, And More
=============================

.. contents::
   :local:

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

