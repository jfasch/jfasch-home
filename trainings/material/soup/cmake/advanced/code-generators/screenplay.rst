.. ot-topic:: cmake.advanced.code_generators
   :dependencies: cmake.advanced.external_dependencies_mosquitto
.. include:: <mmlalias.txt>


Screenplay: Generated Code (``add_custom_command()``)
=====================================================

.. contents::
   :local:

.. sidebar:: Documentation

   * `add_custom_command
     <https://cmake.org/cmake/help/latest/command/add_custom_command.html>`__

.. sidebar:: Trainer's note

   * Source code starts here

     .. command-output:: ls -l ../../project/generated-code/CMakeLists.txt
        :cwd: .
        :shell:

   * Download into ``firmware/``

     * :download:`2024-06-20.conf </trainings/material/soup/cmake/project/generated-code/firmware/2024-06-20.conf>`
     * :download:`conf-sensors.h </trainings/material/soup/cmake/project/generated-code/firmware/conf-sensors.h>`
     * :download:`2024-06-20-manual.cpp </trainings/material/soup/cmake/project/generated-code/firmware/2024-06-20-manual.cpp>`
     * :download:`data-logger-deeply-embedded.cpp </trainings/material/soup/cmake/project/generated-code/firmware/data-logger-deeply-embedded.cpp>`
     * :download:`config-generator.py </trainings/material/soup/cmake/project/generated-code/firmware/config-generator.py>`

What We Want
------------

Imagine ...

* In the Linux variant, sensor configurations are read from ``.ini``
  style config file
* Deeply embedded cannot do this because there is no filesystem

Solution ...

* Can we generate code from these config files?
* |longrightarrow| link-time polymorphism

Handwritten Prototype: What A Code Generator Could Do For Us
------------------------------------------------------------

* Lets say, sensor config files have the format

  .. code-block:: text
     :caption: :download:`2024-06-20.conf (Download)
               </trainings/material/soup/cmake/project/generated-code/firmware/2024-06-20.conf>`

     [bottom-right]
     Type = Const
     Value = -273.15

     # ... more ...

* In a dedicated ``.cpp`` file, we mirror that same information (this
  is what we will generate)

  .. code-block:: c++
     :caption: :download:`2024-06-20-manual.cpp (Download)
               </trainings/material/soup/cmake/project/generated-code/firmware/2024-06-20-manual.cpp>`

     #include "conf-sensors.h"       // <--- THE config's extern declaration
     
     #include <sensor-const.h>
     
     SensorConfig conf_sensors;      // <--- THE config's definition
     
     namespace {
         struct conf_sensors_init
         {
             conf_sensors_init()
             {
                 conf_sensors.add_sensor("bottom-right", std::make_unique<ConstantSensor>(-273.15));
         	// ... more ...
             };
         };
         conf_sensors_init init;
     };

* Main program uses ``conf_sensors`` from the ``extern`` declaration

  .. code-block:: c++
     :caption: :download:`data-logger-deeply-embedded.cpp (Download)
               </trainings/material/soup/cmake/project/generated-code/firmware/data-logger-deeply-embedded.cpp>`

     #include "conf-sensors.h"         // <--- conf_sensors'  extern declaration

     DataLogger logger(conf_sensors,   // <--- conf_sensors' usage
                       ...);

One Deeply Embedded Application (``2024-06-20-manual.cpp``)
-----------------------------------------------------------

* ``data-logger-deeply-embedded.cpp`` uses ``conf_sensors``
* |longrightarrow| defined in ``2024-06-20-manual.cpp``
* ... or any other file ...
* |longrightarrow| link-time decision
* Build instructions for the ``2024-06-20-manual.cpp`` constellation

  .. code-block:: cmake

     add_executable(
       app-data-logger-deeply-embedded-2024-06-20-manual

       data-logger-deeply-embedded.cpp 
       2024-06-20-manual.cpp                      # <--- polymorphic
     )
     target_link_libraries(app-data-logger-deeply-embedded-2024-06-20-manual base data-logger)
     install(TARGETS app-data-logger-deeply-embedded-2024-06-20-manual DESTINATION bin)
 
Another Deeply Embedded Application (Generated From ``2024-06-20.conf``)
------------------------------------------------------------------------

.. sidebar:: Documentation

   * `add_custom_command
     <https://cmake.org/cmake/help/latest/command/add_custom_command.html>`__

* Generator demo

  .. code-block:: console

     $ pwd
     .../firmware
     $ ./config-generator.py 2024-06-20.conf /tmp/demo.cpp
     $ cat /tmp/demo.cpp

* Build instructions: link with a not-yet-existig file,
  ``2024-06-20.cpp`` (from the build tree)

  .. code-block:: cmake

     add_executable(
       app-data-logger-deeply-embedded-2024-06-20 
     
       data-logger-deeply-embedded.cpp
       ${CMAKE_CURRENT_BINARY_DIR}/2024-06-20.cpp    # <--- to be generated
     
     )
     target_link_libraries(app-data-logger-deeply-embedded-2024-06-20 base data-logger)
     install(TARGETS app-data-logger-deeply-embedded-2024-06-20 DESTINATION bin)

* Code generation: ``add_custom_command()``

  .. code-block:: cmake

     add_custom_command(
       OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/2024-06-20.cpp    # <--- same as in add_executable()

       COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/config-generator.py ${CMAKE_CURRENT_SOURCE_DIR}/2024-06-20.conf ${CMAKE_CURRENT_BINARY_DIR}/2024-06-20.cpp
       DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/config-generator.py ${CMAKE_CURRENT_SOURCE_DIR}/2024-06-20.conf
     ) 

  Discuss ``DEPENDS`` ...

* Generated config includes ``conf-sensors.h`` from source directory
  |longrightarrow| ``PRIVATE`` "include" property

  .. code-block:: cmake

     target_include_directories(app-data-logger-deeply-embedded-2024-06-20 PRIVATE .)

Et Voila!
---------
