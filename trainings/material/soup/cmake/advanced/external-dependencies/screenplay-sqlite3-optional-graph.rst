.. ot-topic:: cmake.advanced.external_dependencies_sqlite3_optional_graph
   :dependencies: cmake.advanced.external_dependencies_sqlite3
.. include:: <mmlalias.txt>


Screenplay: Making ``SQLite3`` Optional
=======================================

.. contents::
   :local:

What If We Know How to Live Without SQLite3?
--------------------------------------------

.. sidebar:: See also

   * :doc:`screenplay-sqlite3`

.. sidebar:: Documentation

   * `find_package()
     <https://cmake.org/cmake/help/latest/command/find_package.html>`__
   * `FindSQLite3
     <https://cmake.org/cmake/help/latest/module/FindSQLite3.html>`__

.. sidebar:: Trainer's note

   * Source code starts here

     .. command-output:: ls -l ../../project/external-dependency-sqlite3-optional/CMakeLists.txt
        :cwd: .
        :shell:

   * Uninstall SQLite3 again ...

     .. code-block:: console
  
        $ sudo dnf remove sqlite-devel

* ``toolcase/data-logger`` has ``sink-sqlite3.h`` and
  ``sink-sqlite3.cpp`` only *conditionally*
* |longrightarrow| ``SQLite3_FOUND`` (see `FindSQLite3
  <https://cmake.org/cmake/help/latest/module/FindSQLite3.html>`__)

Optionally *Not* Depending On SQLite3
-------------------------------------

.. sidebar:: Documentation

   * `target_compile_definitions()
     <https://cmake.org/cmake/help/latest/command/target_compile_definitions.html>`__

* Toplevel: make SQLite3 *not* required

  .. code-block:: cmake

     find_package(SQLite3)

* ``toolcase/data-logger/`` depends on SQLite3 (``SQLite::SQLite3``)
* Library **contains** ``sink-sqlite3.h`` and ``sink-sqlite3.cpp``,
  depending on ``SQLite3_FOUND``

  .. code-block:: cmake

     if (SQLite3_FOUND)
       set(inc_sink_sqlite3 sink-sqlite3.h)
       set(src_sink_sqlite3 sink-sqlite3.cpp)
     endif()  

  ... and substitute accordingly

* Library **depends** on ``SQLite::SQLite3``

  .. code-block:: cmake

     if (SQLite3_FOUND)
       target_link_libraries(data-logger SQLite::SQLite3)
     endif()

* Library **propagates** *dependency information* to its users (see
  below); ``INTERFACE`` because it does not need that information
  itself

  .. code-block:: cmake

     if (SQLite3_FOUND)
       target_compile_definitions(data-logger INTERFACE HAVE_SINK_SQLITE3=1)
     endif()

Optionally *Not* Depending On Someone Who Depends On SQLite3
------------------------------------------------------------

* ``firmware/data-logger.cpp`` (node ``app-data-logger``)
  uses/includes ``<sink-sqlite3.h>``
* In *that* node - ``app-data-logger`` - it would be nice to have a
  macro ``HAVE_SINK_SQLITE3`` available
* Litter ``#ifdef`` all across your code

  .. code-block:: cmake

     #ifdef HAVE_SINK_SQLITE3
     #  include <sink-sqlite3.h>
     #else
     #  include <sink-terminal.h>
     #endif

* It is a massacre, inevitably!
