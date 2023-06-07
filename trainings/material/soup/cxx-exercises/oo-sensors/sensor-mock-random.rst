.. ot-exercise:: cxx.exercises.oo_sensors.sensor_mock_random
   :dependencies: cxx.exercises.oo_sensors.sensor_mock_const,
		  cxx03.data_encapsulation.initializer_list,
		  cxx03.data_encapsulation.classes_objects,
		  linux.toolchain.cmake_local

.. include:: <mmlalias.txt>


Exercise: ``RandomSensor`` (Mocking Sensor)
===========================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/initializer-list`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Requirement
-----------

Implement a sensor class ``RandomSensor`` which does not access any
real hardware, but rather returns a random temperature within a given
range.

.. literalinclude:: /trainings/material/soup/cxx-code/sensors-duck/tests/sensor-random-suite-basic.cpp
   :language: c++
   :caption: :download:`Download sensor-random-suite-basic.cpp
             </trainings/material/soup/cxx-code/sensors-duck/tests/sensor-random-suite-basic.cpp>`

Implementation Hint: Randomicity In C++
.......................................

* The following program demonstrates how to generate uniformly
  distributed random ``double`` values in a specified range.

.. literalinclude:: random-demo.cpp
   :language: c++
   :caption: :download:`Download random-demo.cpp <random-demo.cpp>`

Implementation Hint: Initializer Lists
......................................

See
:doc:`/trainings/material/soup/cxx03/020-data-encapsulation/initializer-list`
for how to initialize members in an initializer list.

Topics Covered
--------------

.. ot-graph::
   :entries: cxx.exercises.oo_sensors.sensor_mock_random
