.. ot-topic:: cmake.advanced.external_dependencies_sqlite3
   :dependencies: cmake.advanced.targets_properties,
		  cmake.advanced.targets_properties_pub_priv_inc_screenplay,
		  cmake.advanced.library_function_screenplay
.. include:: <mmlalias.txt>


Screenplay: Adding ``SQLite3`` External Dependency
==================================================

.. contents::
   :local:

Add SQLite3 Capability To Datalogger
------------------------------------

.. sidebar:: Complete source code

   * https://github.com/jfasch/cmake-external-dependency-sqlite3

.. sidebar:: Documentation

   * `An Introduction To The SQLite C/C++ Interface
     <https://www.sqlite.org/cintro.html>`__

.. sidebar:: Trainer's note

   * Make sure SQLite3 is not available ...

     .. code-block:: console
  
        $ sudo dnf remove sqlite-devel

* Add to ``toolcase/data-logger`` ...

  * :download:`sink-sqlite3.h
    </foreign/cmake-external-dependency-sqlite3/toolcase/data-logger/include/public/sink-sqlite3.h>`
  * :download:`sink-sqlite3.cpp
    </foreign/cmake-external-dependency-sqlite3/toolcase/data-logger/src/sink-sqlite3.cpp>`

* Use in ``firmware/data-logger.cpp``

  .. code-block:: c++

     if (argc != 2) {
         std::cerr << "Usage: " << argv[0] << " <SQLITE3-DB>" << std::endl;
         std::cerr << "  (Create: \"" << SinkSQLite3::create_table_statement << "\")" << std::endl;
         return 1;
     }
 
     ...
 
     auto sink = std::make_unique<SinkSQLite3>(argv[1]);

* Build

.. code-block:: console

   In file included from .../toolcase/data-logger/src/sink-sqlite3.cpp:1:
   .../toolcase/data-logger/./include/public/sink-sqlite3.h:5:10: fatal error: sqlite3.h: No such file or directory
       5 | #include <sqlite3.h>
         |          ^~~~~~~~~~~

``FIND_PACKAGE()``
------------------

.. sidebar:: Documentation

   * `find_package()
     <https://cmake.org/cmake/help/latest/command/find_package.html>`__
   * `List of available "find" modules: cmake-modules(7)
     <https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html>`__
   * `FindSQLite3
     <https://cmake.org/cmake/help/latest/module/FindSQLite3.html>`__

.. sidebar:: See also

   * :doc:`screenplay-sqlite3-optional-graph`
   * :doc:`screenplay-sqlite3-optional-configured-file`

* Pulling in parameters for ``SQLite3``

  .. code-block:: cmake
     :caption: Toplevel ``CMakeLists.txt``
  
     find_package(SQLite3)      # <--- continues if not found

* Not found unless ``sqlite3`` is available

  .. code-block:: console

     $ cmake ...
     ...
     -- Could NOT find SQLite3 (missing: SQLite3_INCLUDE_DIR SQLite3_LIBRARY) 
     ...

* Not an error though
* |longrightarrow| error remains: ``sqlite3.h: No such file or
  directory``
* Could continue if we could handle *optional* dependencies
* |longrightarrow| Later (:doc:`screenplay-sqlite3-optional-graph`,
  :doc:`screenplay-sqlite3-optional-configured-file`)

``FIND_PACKAGE(... REQUIRED)``
------------------------------

* C code cannot handle SQLite3 non-availablility
* |longrightarrow| better to fail early/clearly

  .. code-block:: cmake
  
     find_package(SQLite3 REQUIRED)
  
  .. code-block:: console
  
     $ cmake ...
     CMake Error at /usr/share/cmake/Modules/FindPackageHandleStandardArgs.cmake:230 (message):
       Could NOT find SQLite3 (missing: SQLite3_INCLUDE_DIR SQLite3_LIBRARY)
     Call Stack (most recent call first):
       /usr/share/cmake/Modules/FindPackageHandleStandardArgs.cmake:600 (_FPHSA_FAILURE_MESSAGE)
       /usr/share/cmake/Modules/FindSQLite3.cmake:54 (find_package_handle_standard_args)
       CMakeLists.txt:9 (find_package)

* Install SQLite3

  .. code-block:: console

     $ sudo dnf install sqlite-devel

* Try again

  .. code-block:: console

     $ cmake ...
     ...
     -- Found SQLite3: /usr/include (found version "3.42.0") 
     ...

Bringing A New Node Into The Graph: Theory
------------------------------------------

.. sidebar:: See also

   * :doc:`../targets-properties/topic`
   * :doc:`../targets-properties/screenplay`

.. sidebar:: Documentation

   * `FindSQLite3
     <https://cmake.org/cmake/help/latest/module/FindSQLite3.html>`__
   * `target_include_directories()
     <https://cmake.org/cmake/help/latest/command/target_include_directories.html>`__
   * `target_link_libraries
     <https://cmake.org/cmake/help/latest/command/target_link_libraries.html>`__

* Find-modules (if successful) usually define a node in the dependency
  graph
* Propagate properties across graphs's edges
* From `FindSQLite3
  <https://cmake.org/cmake/help/latest/module/FindSQLite3.html>`__

  * ``SQLite::SQLite3``: *imported* target |longrightarrow| **most
    important**
  * ``SQLite3_INCLUDE_DIRS``: include path (via
     `target_include_directories()
     <https://cmake.org/cmake/help/latest/command/target_include_directories.html>`__)
  * ``SQLite3_LIBRARIES``: nodes to depend on (via
     `target_link_libraries
     <https://cmake.org/cmake/help/latest/command/target_link_libraries.html>`__)
  * ``SQLite3_VERSION``: additional information
  * ``SQLite3_FOUND``: to check for availablity in CMake code

* Temporarily add, to see that information

  .. code-block:: cmake

     message("SQLite3_INCLUDE_DIRS ${SQLite3_INCLUDE_DIRS}")
     message("SQLite3_LIBRARIES ${SQLite3_LIBRARIES}")
     message("SQLite3_VERSION ${SQLite3_VERSION}")
     message("SQLite3_FOUND ${SQLite3_FOUND}")

* **But that is mostly not relevant!** (Read on)

Bringing A New Node Into The Graph: Practice
--------------------------------------------

* ``toolcase/data-logger`` has 

  * ``sink-sqlite3.h``
  * ``sink-sqlite3.cpp``

* |longrightarrow| *depends on* node ``SQLite::SQLite3``
* Add dependency there ...

  .. code-block:: cmake

     target_link_libraries(data-logger SQLite::SQLite3)

* **And that's all!**
