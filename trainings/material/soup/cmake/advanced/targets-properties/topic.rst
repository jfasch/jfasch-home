.. include:: <mmlalias.txt>


Targets, Properties, And More
=============================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`screenplay`

.. sidebar:: Trainer's note

   * Finally, don't forget to discuss :doc:`global-incdir`

Target Types
------------

.. sidebar::

   **Documentation**

   * `add_library()
     <https://cmake.org/cmake/help/latest/command/add_library.html>`__
   * `add_executable()
     <https://cmake.org/cmake/help/latest/command/add_executable.html>`__

* Two basic types: ``add_executable()`` and ``add_library()``
* ``add_executable()`` is not relevant ...

  * Only entry point into dependency graph
  * |longrightarrow| does not propagate anything to dependers
  * There *are no* dependers

* ``add_library()`` ...

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

(For a complete list see `add_library()
<https://cmake.org/cmake/help/latest/command/add_library.html>`__)

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Target function 
     * Property name
     * Description
     * Documentation
   * * ``target_compile_definitions()``
     * ``COMPILE_DEFINITIONS``
     * Macros set on the compiler command line (``-Dname=value``)
     * `target_compile_definitions()
       <https://cmake.org/cmake/help/latest/command/target_compile_definitions.html>`__
   * * ``target_compile_options()``
     * ``COMPILE_OPTIONS``
     * Non-macro compiler flags/options
     * `TARGET_COMPILE_OPTIONS()
       <https://cmake.org/cmake/help/latest/command/target_compile_options.html>`__
   * * ``target_include_directories()``
     * ``INCLUDE_DIRECTORIES``
     * Include directories
     * `target_include_directories()
       <https://cmake.org/cmake/help/latest/command/target_include_directories.html>`__
   * * ``target_link_libraries()``
     * (Much more complicated, see documentation)
     * Dependencies, in the widest sense
     * `target_link_libraries()
       <https://cmake.org/cmake/help/latest/command/target_link_libraries.html>`__
   * * ``set_target_properties()``
     * Any property, including custom properties
     * See documentation
     * `set_target_properties()
       <https://cmake.org/cmake/help/latest/command/set_target_properties.html>`__

Properties: ``PRIVATE``, ``PUBLIC``, ``INTERFACE``?
---------------------------------------------------

.. sidebar::

   **Documentation**

   * `Transitive Usage Requirements
     <https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#target-usage-requirements>`__

* ``PUBLIC`` *propagated* to *dependers*

  * Dependency through ``#include <other.h>`` in a header file
    |longrightarrow| all *includers* need to know
  * ``blacklist`` availability in :doc:`approach 2
    <../conditional-code-approach-2/topic>` (but only if ``blacklist``
    has compiled code)
  * ``PUBLIC`` only possible when target has *compiled code*

* ``PRIVATE`` does not propagate

  * For example, one might structure a target's source code into
    ``src/``, ``private-inc/``, and ``public-inc/`` |longrightarrow|
    ``private-inc/`` would be ``target_include_directories(... PRIVATE
    ...)``
  * For example, ``target_compile_definitions()`` for target-local
    compilation only

* ``INTERFACE`` *propagated* to *dependers*

  * Just like ``PUBLIC`` - except that ``PUBLIC`` is not possible on
    ``INTERFACE`` targets (e.g. header-only libraries)
  * Asymmetric; smells like it does in many corners of CMake
  * Documentation has no clear explanation. Exceptions, and
    paragraph-long explanations.

Demo Time
---------

Move on to :doc:`screenplay`


Final Note: ``include_directories()``
-------------------------------------

:doc:`global-incdir`
