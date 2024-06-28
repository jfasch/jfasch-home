.. ot-topic:: cmake.advanced.external_dependencies_mosquitto
   :dependencies: cmake.advanced.external_dependencies_sqlite3_optional_configured_file
.. include:: <mmlalias.txt>


Screenplay: Integrating ``libmosquitto`` (MQTT - Handwritten Find-Module)
=========================================================================

.. contents::
   :local:

.. sidebar:: Complete source code

   * https://github.com/jfasch/cmake-external-dependency-mosquitto

First: Clean Up Toplevel ``CMakeLists.txt``
-------------------------------------------

* Cram SQLite3 stuff into into ``cmake/sqlite3.cmake``

  .. literalinclude:: /foreign/cmake-external-dependency-mosquitto/cmake/sqlite3.cmake
     :caption: :download:`sqlite3.cmake (download)
               </foreign/cmake-external-dependency-mosquitto/cmake/sqlite3.cmake>`
     :language: cmake
  
* Include from tolevel
* Leave ``configure_file()`` in place, toplevel (because of its
  prominence)

Add MQTT Capability To Datalogger
---------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx-design-patterns/composite/composite`

.. sidebar:: Documentation

   * `mosquitto.h <https://mosquitto.org/api/files/mosquitto-h.html>`__

* Add to ``toolcase/data-logger`` ...


  * :download:`sink-mqtt.h
    </foreign/cmake-external-dependency-mosquitto/toolcase/data-logger/include/public/sink-mqtt.h>`
  * :download:`sink-mqtt.cpp
    </foreign/cmake-external-dependency-mosquitto/toolcase/data-logger/src/sink-mqtt.cpp>`
  * :download:`sink-composite.h
    </foreign/cmake-external-dependency-mosquitto/toolcase/data-logger/include/public/sink-composite.h>`
  * :download:`sink-composite.cpp
    </foreign/cmake-external-dependency-mosquitto/toolcase/data-logger/src/sink-composite.cpp>`

* Use in ``firmware/data-logger.cpp``

  * conditionally ``#include``, instantiate, and add to
    ``SinkComposite`` instance

    * ``SinkTerminal``
    * ``SinkSQLite3``
    * ``SinkMQTT``

External ``libmosquitto`` Dependency
------------------------------------

.. sidebar:: Documentation

   * `add_library
     <https://cmake.org/cmake/help/latest/command/add_library.html>`__
   * `find_package_handle_standard_args
     <https://cmake.org/cmake/help/latest/module/FindPackageHandleStandardArgs.html>`__

* No find module that comes with CMake
* |longrightarrow| write one myself

  .. literalinclude:: /foreign/cmake-external-dependency-mosquitto/cmake/FindMosquitto.cmake
     :caption: :download:`FindMosquitto.cmake (download)
	       </foreign/cmake-external-dependency-mosquitto/cmake/FindMosquitto.cmake>`
     :language: cmake

* ``add_library(... INTERFACE IMPORTED)`` (see `add_library
  <https://cmake.org/cmake/help/latest/command/add_library.html>`__)
* Glue all together in ``cmake/mosquitto.cmake``, and include from
  toplevel ``CMakeLists.txt``

  .. literalinclude:: /foreign/cmake-external-dependency-mosquitto/cmake/mosquitto.cmake
     :caption: :download:`mosquitto.cmake (download)
               </foreign/cmake-external-dependency-mosquitto/cmake/mosquitto.cmake>`
     :language: cmake
* Add ``HAVE_MOSQUITTO`` to ``project-config.h.in``
* Et voila!
