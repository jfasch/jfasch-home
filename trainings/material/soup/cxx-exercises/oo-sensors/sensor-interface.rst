.. ot-exercise:: cxx.exercises.oo_sensors.sensor_interface
   :dependencies: cxx03.inheritance_oo.interface,
		  linux.toolchain.cmake_local

.. include:: <mmlalias.txt>


Exercise: Sensor Interface
==========================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Project Setup
-------------

Directory ``sensors``
.....................

Download the following files into directory ``sensors/``:

* :download:`CMakeLists.txt
  </trainings/material/soup/cxx-code/sensors-duck/sensors/CMakeLists.txt>`
* :download:`sensor-const.h
  </trainings/material/soup/cxx-code/sensors-duck/sensors/sensor-const.h>`
* :download:`sensor-const.cpp
  </trainings/material/soup/cxx-code/sensors-duck/sensors/sensor-const.cpp>`
* :download:`sensor-random.h
  </trainings/material/soup/cxx-code/sensors-duck/sensors/sensor-random.h>`
* :download:`sensor-random.cpp
  </trainings/material/soup/cxx-code/sensors-duck/sensors/sensor-random.cpp>`

Directory ``bin``
.................

Download the following files into directory ``bin/``:

* :download:`CMakeLists.txt
  </trainings/material/soup/cxx-code/sensors-duck/bin/CMakeLists.txt>`
* :download:`sensor-const-main.cpp
  </trainings/material/soup/cxx-code/sensors-duck/bin/sensor-const-main.cpp>`
* :download:`sensor-random-main.cpp
  </trainings/material/soup/cxx-code/sensors-duck/bin/sensor-random-main.cpp>`

Directory ``tests``
...................

Download the following files into directory ``tests/``:

* :download:`CMakeLists.txt
  </trainings/material/soup/cxx-code/sensors-duck/tests/CMakeLists.txt>`
* :download:`sensor-const-suite-basic.cpp
  </trainings/material/soup/cxx-code/sensors-duck/tests/sensor-const-suite-basic.cpp>`
* :download:`sensor-random-suite-basic.cpp
  </trainings/material/soup/cxx-code/sensors-duck/tests/sensor-random-suite-basic.cpp>`

Build and Test
..............

* Build the project
* In the build directory for ``bin/``,

  .. code-block:: console

     $ ./sensor-const-main 
     42.7

  .. code-block:: console

     $ ./sensor-random-main 
     17.7177

* In the build directory for ``tests/``,

  .. code-block:: console

     $ ./cxx-exercises-sensors-duck--suite 
     Running main() from /home/jfasch/work/jfasch-home/googletest/googletest/src/gtest_main.cc
     [==========] Running 2 tests from 2 test suites.
     [----------] Global test environment set-up.
     [----------] 1 test from sensor_const_suite
     [ RUN      ] sensor_const_suite.basic
     [       OK ] sensor_const_suite.basic (0 ms)
     [----------] 1 test from sensor_const_suite (0 ms total)
     
     [----------] 1 test from sensor_random_suite
     [ RUN      ] sensor_random_suite.basic
     [       OK ] sensor_random_suite.basic (0 ms)
     [----------] 1 test from sensor_random_suite (0 ms total)
     
     [----------] Global test environment tear-down
     [==========] 2 tests from 2 test suites ran. (0 ms total)
     [  PASSED  ] 2 tests.

Problem: Polymorphic Thermometer Usage
--------------------------------------

``ConstantSensor`` and ``RandomSensor`` are completely unrelated -
*they don't share a common base class*. They just look similar. This
programming technique, *Duck Typing*, is heavily used in dynamic
languages such as Python (see
:doc:`/trainings/material/soup/python/advanced/oo/abc/topic`). It is
not appropriate in a strongly tyoed language like C++ though, as we
will see.

The following program uses an instance of each *in an array of a
hypothetical interface/base class* to measure two temperature
points. It calculates the average of both points, and outputs that.

.. literalinclude:: /trainings/material/soup/cxx-code/sensors-core/bin/sensors-avg.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/sensors-core/bin/sensors-avg.cpp`
   :language: c++

The Exercise
------------

* Download the program into the ``bin/`` directory, and register it
  with that directory's ``CMakeLists.txt`` file:

  * :download:`sensors-avg.cpp
    </trainings/material/soup/cxx-code/sensors-core/bin/sensors-avg.cpp>`

* In addition ot the program, download two tests into the ``tests/``
  directory, and register them with that directory's
  ``CMakeLists.txt`` file:

  .. literalinclude:: /trainings/material/soup/cxx-code/sensors-core/tests/sensor-const-suite-is-a-sensor.cpp
     :caption: :download:`sensor-const-suite-is-a-sensor.cpp
               </trainings/material/soup/cxx-code/sensors-core/tests/sensor-const-suite-is-a-sensor.cpp>`
     :language: c++

  .. literalinclude:: /trainings/material/soup/cxx-code/sensors-core/tests/sensor-random-suite-is-a-sensor.cpp
     :caption: :download:`sensor-random-suite-is-a-sensor.cpp
               </trainings/material/soup/cxx-code/sensors-core/tests/sensor-random-suite-is-a-sensor.cpp>`
     :language: c++

* *It won't build*
* Add the missing ``Sensor`` interface (create a file
  ``sensors/sensor.h`` to contain it), and make the program compile
  and run. In UML, the new sensor hierarchy would look like follows:

  .. image:: sensor-hierarchy.png
     :scale: 30%

* Run the program

  .. code-block:: console

     $ ./bin/cxx-exercises-sensors-avg 
     27.5731

* Run the tests

  .. code-block:: console

     $ ./tests/cxx-exercises-sensors-core--suite 
     Running main() from /home/jfasch/work/jfasch-home/googletest/googletest/src/gtest_main.cc
     [==========] Running 4 tests from 2 test suites.
     [----------] Global test environment set-up.
     [----------] 2 tests from sensor_const_suite
     [ RUN      ] sensor_const_suite.basic
     [       OK ] sensor_const_suite.basic (0 ms)
     [ RUN      ] sensor_const_suite.is_a_sensor
     [       OK ] sensor_const_suite.is_a_sensor (0 ms)
     [----------] 2 tests from sensor_const_suite (0 ms total)
     
     [----------] 2 tests from sensor_random_suite
     [ RUN      ] sensor_random_suite.basic
     [       OK ] sensor_random_suite.basic (0 ms)
     [ RUN      ] sensor_random_suite.is_a_sensor
     [       OK ] sensor_random_suite.is_a_sensor (0 ms)
     [----------] 2 tests from sensor_random_suite (0 ms total)
     
     [----------] Global test environment tear-down
     [==========] 4 tests from 2 test suites ran. (0 ms total)
     [  PASSED  ] 4 tests.

Topics Covered
--------------

.. ot-graph::
   :entries: cxx.exercises.oo_sensors.sensor_interface
