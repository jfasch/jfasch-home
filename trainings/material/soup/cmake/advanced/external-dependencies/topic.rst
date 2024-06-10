.. ot-topic:: cmake.advanced.external_dependencies
   :dependencies: cmake.advanced.targets_properties
.. include:: <mmlalias.txt>


External Dependencies
=====================

.. contents::
   :local:

.. sidebar::

   **Source**

   .. code-block:: console

      13-external-dependencies/
      ├── bin
      │   ├── CMakeLists.txt
      │   ├── hello-first.cpp
      │   ├── hello-second.cpp
      │   └── hello-third.cpp
      ├── blacklist
      │   ├── blacklist.cpp
      │   ├── blacklist.h
      │   └── CMakeLists.txt
      ├── CMakeLists.txt
      ├── DemoConfig.h.in
      └── libhello
          ├── CMakeLists.txt
          ├── greeter-alias-db.cpp
          ├── greeter-alias-db.h
          ├── greeter.h
          ├── greeter-name.cpp
          ├── greeter-name.h
          ├── greeter-simple.cpp
          └── greeter-simple.h

   * :download:`code/CMakeLists.txt`
   * :download:`code/DemoConfig.h.in`
   * :download:`code/bin/CMakeLists.txt`
   * :download:`code/bin/hello-first.cpp`
   * :download:`code/bin/hello-second.cpp`
   * :download:`code/bin/hello-third.cpp`
   * :download:`code/libhello/CMakeLists.txt`
   * :download:`code/libhello/greeter.h`
   * :download:`code/libhello/greeter-simple.h`
   * :download:`code/libhello/greeter-simple.cpp`
   * :download:`code/libhello/greeter-name.h`
   * :download:`code/libhello/greeter-name.cpp`
   * :download:`code/libhello/greeter-alias-db.h`
   * :download:`code/libhello/greeter-alias-db.cpp`
   * :download:`code/blacklist/CMakeLists.txt`
   * :download:`code/blacklist/blacklist.h`
   * :download:`code/blacklist/blacklist.cpp`

``FIND_PACKAGE()``
------------------

.. sidebar::

   **Teacher's note**

   .. code-block:: console

      $ sudo dnf remove sqlite-devel

   **Documentation**

   * `FIND_PACKAGE()
     <https://cmake.org/cmake/help/latest/command/find_package.html>`__
   * `List of available "find" modules: cmake-modules(7)
     <https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html>`__
   * `FindSQLite3
     <https://cmake.org/cmake/help/latest/module/FindSQLite3.html>`__

* Pulling in parameters for ``SQLite3``

.. code-block:: console
   :caption: Toplevel ``CMakeLists.txt``

   FIND_PACKAGE(SQLite3)      # <--- continues if not found

.. code-block:: console

   $ cmake /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/13-external-dependencies/
   ...
   -- Could NOT find SQLite3 (missing: SQLite3_INCLUDE_DIR SQLite3_LIBRARY) 
   ...

* |longrightarrow| Handle through *optional code* (like in
  :doc:`../conditional-code-approach-1/topic` and :doc:`../conditional-code-approach-2/topic`)

``FIND_PACKAGE(... REQUIRED)``
------------------------------

.. note::

   A requirement appears to only fail if at least one target *depends*
   on the *imported target*

   .. code-block:: console
      :caption: ``libhello/CMakeLists.txt``

      TARGET_LINK_LIBRARIES(hello SQLite::SQLite3)

* *Requiring* ``SQLite3`` |longrightarrow| failing if not found

  .. code-block:: console
  
     FIND_PACKAGE(SQLite3 REQUIRED)

  .. code-block:: console
  
     $ cmake /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/13-external-dependencies/
     ...
     CMake Error at libhello/CMakeLists.txt:8 (TARGET_LINK_LIBRARIES):
       Target "hello" links to:
     
         SQLite::SQLite3
     
       but the target was not found.  Possible reasons include:
     
         * There is a typo in the target name.
         * A find_package call is missing for an IMPORTED target.
         * An ALIAS target is missing.

* Success after installing ``sqlite-devel``

  .. code-block:: console

     $ sudo dnf install sqlite-devel
     $ cmake /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/13-external-dependencies/
     ...
     -- Found SQLite3: /usr/include (found version "3.36.0") 
     ...

``SQLite3`` Parameters
----------------------

* Find-modules usually set variables
* `FindSQLite3
  <https://cmake.org/cmake/help/latest/module/FindSQLite3.html>`__ is
  documented to set those (put in toplevel ``CMakeLists.txt``)

  .. code-block:: console

     MESSAGE(DEBUG "SQLite3_INCLUDE_DIRS ${SQLite3_INCLUDE_DIRS}")
     MESSAGE(DEBUG "SQLite3_LIBRARIES ${SQLite3_LIBRARIES}")
     MESSAGE(DEBUG "SQLite3_VERSION ${SQLite3_VERSION}")
     MESSAGE(DEBUG "SQLite3_FOUND ${SQLite3_FOUND}")

  .. code-block:: console

     $ cmake --log-level=debug /home/jfasch/work/jfasch-home/trainings/material/soup/cmake/13-external-dependencies/
     ...
     -- SQLite3_INCLUDE_DIRS /usr/include
     -- SQLite3_LIBRARIES /usr/lib64/libsqlite3.so
     -- SQLite3_VERSION 3.36.0
     -- SQLite3_FOUND TRUE
     ...

Using ``SQLite3`` Parameters
----------------------------

* With "Modern CMake" (that with targets, and propagated properties)
  not necessary anymore
* Used to be necessary in olden days
* Only say ``TARGET_LINK_LIBRARIES(hello SQLite::SQLite3)``
* |longrightarrow| All is fine

Demo Time
---------

* Download into ``libhello/``

  * :download:`code/libhello/greeter-alias-db.h`
  * :download:`code/libhello/greeter-alias-db.cpp`

* In ``libhello/greeter-alias-db.h``, notice

  .. code-block:: c

     #include <sqlite3.h>

  * |longrightarrow| found as ``/usr/include/sqlite3.h``
  * Compiler looks there anyway

* Linked against SQLite library

  .. code-block:: console

     $ ldd bin/hello-third 
            ...
            libsqlite3.so.0 => /lib64/libsqlite3.so.0 (0x00007f76ae011000)
	    libz.so.1 => /lib64/libz.so.1 (0x00007f76adef7000)
	    ...
     
  * Somebody must have told linker to look for ``sqlite3``
  * That library in turn pulls in ``z``
