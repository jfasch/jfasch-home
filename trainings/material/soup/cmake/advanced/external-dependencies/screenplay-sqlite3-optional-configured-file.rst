.. ot-topic:: cmake.advanced.external_dependencies_sqlite3_optional_configured_file
   :dependencies: cmake.advanced.external_dependencies_sqlite3
.. include:: <mmlalias.txt>


Screenplay: Making ``SQLite3`` Optional (``configure_file()``)
==============================================================

.. contents::
   :local:

Alternative: ``configure_file()`` Instead Of ``target_compile_definitions()``
-----------------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`screenplay-sqlite3-optional-graph`

.. sidebar:: Documentation

   * `configure_file()
     <https://cmake.org/cmake/help/latest/command/configure_file.html>`__

* In :doc:`screenplay-sqlite3-optional-graph`, we used
  ``target_compile_definitions()`` to *propagate*
  ``HAVE_SINK_SQLITE3`` from ``toolcase/base/`` right into
  ``firmware/data-logger.cpp``
* If done much, this can clutter compiler commandlines with macro
  definitions
* What if every user like ``firmware/data-logger.cpp`` pulls in that
  information via a dedicated - *generated* - header file?
* |longrightarrow| `configure_file()
  <https://cmake.org/cmake/help/latest/command/configure_file.html>`__
* Beware: this is not less a massacre!

Make It So
----------

* Remove propagated commandline macro from ``toolcase/data-logger/``

  .. code-block:: cmake
  
     # if (SQLite3_FOUND)
     #   target_compile_definitions(data-logger INTERFACE HAVE_SQLITE3=1)
     # endif()

* ``firmware/data-logger.cpp`` still builds - it just does not see
  ``HAVE_SQLITE3`` defined
* ``firmware/data-logger.cpp`` to act differently
* |longrightarrow| pull in a header file that contains
  ``HAVE_SQLITE3`` (and possibly related) definitions

.. code-block:: c++

   #include <project-config.h>     // <--- defines HAVE_SQLITE3
   #if HAVE_SQLITE3==1
   #  include <sink-sqlite3.h>
   #else
   #  include <sink-terminal.h>
   #endif

.. code-block:: console

   .../firmware/data-logger.cpp:4:10: fatal error: project-config.h: No such file or directory
       4 | #include <project-config.h>     // <--- defines HAVE_SQLITE3
         |          ^~~~~~~~~~~~~~

"Configured Files": ``configure_file()``
----------------------------------------

.. sidebar:: Documentation

   * `configure_file()
     <https://cmake.org/cmake/help/latest/command/configure_file.html>`

* Toplevel (any other directory is fine, but lets keep such things
  together prominently), add ``project-config.h.in``

  .. code-block:: c

     #pragma once
     #define HAVE_SQLITE3 @CONFIG_HAVE_SQLITE3@

* In toplevel ``CMakeLists..txt``, add

  .. code-block:: cmake

     find_package(SQLite3)      # <--- already in place
     
     if (SQLite3_FOUND)
       set(CONFIG_HAVE_SQLITE3 1)
     else()
       set(CONFIG_HAVE_SQLITE3 0)
     endif()
     configure_file(project-config.h.in project-config.h)
     include_directories(${CMAKE_CURRENT_BINARY_DIR})

* |longrightarrow| ``@CONFIG_HAVE_SQLITE3@`` will be substituted with
  variable value
* |longrightarrow| ``project-config.h`` in corresponding directory
  (toplevel in our case) in the build tree
* ``include_directories(${CMAKE_CURRENT_BINARY_DIR})`` adds that to
  the include paths of the entire build

What Else To Put In ``project-config.h.in``
-------------------------------------------

* Version numbers maybe?
* In toplevel ``CMakeLists.txt`` ...

  .. code-block:: cmake

     project(Gluehweinkochen VERSION 42.666)

     message("Major: ${Demo_VERSION_MAJOR}")   # <--- 42
     message("Major: ${Demo_VERSION_MINOR}")   # <--- 666

* In ``project-config.h.in``, add ...

  .. code-block:: c

     #define DEMO_MAJOR @Demo_VERSION_MAJOR@
     #define DEMO_MINOR @Demo_VERSION_MINOR@

* In ``firmware/data-logger.cpp`` and ``firmware/boiling-pot.cpp``,
  make use of those.
