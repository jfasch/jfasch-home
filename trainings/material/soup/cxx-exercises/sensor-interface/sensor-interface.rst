.. include:: <mmlalias.txt>


Exercise: Sensor Interface
==========================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/interface`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Project Setup
-------------

**TODO: this needs more thinking**

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

* In addition to the program, download two tests into the ``tests/``
  directory, and register them with that directory's
  ``CMakeLists.txt`` file:

  .. literalinclude:: /trainings/material/soup/cxx-code/sensors-core/tests/sensor-const-is-a-sensor.cpp
     :caption: :download:`sensor-const-is-a-sensor.cpp
               </trainings/material/soup/cxx-code/sensors-core/tests/sensor-const-is-a-sensor.cpp>`
     :language: c++

  .. literalinclude:: /trainings/material/soup/cxx-code/sensors-core/tests/sensor-random-is-a-sensor.cpp
     :caption: :download:`sensor-random-is-a-sensor.cpp
               </trainings/material/soup/cxx-code/sensors-core/tests/sensor-random-is-a-sensor.cpp>`
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
