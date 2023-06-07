.. ot-exercise:: cxx.exercises.oo_sensors.sensor_mock_const
   :dependencies: cxx03.data_encapsulation.classes_objects,
		  linux.toolchain.cmake_local

.. include:: <mmlalias.txt>


Exercise: ``ConstantSensor`` (Mocking Sensor)
=============================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Requirement
-----------

Implement a sensor class ``ConstantSensor`` which does not access any
real hardware, but rather always measures the same temperature - the
one it is initialized with.

.. literalinclude:: /trainings/material/soup/cxx-code/sensors-duck/tests/sensor-const-suite-basic.cpp
   :language: c++
   :caption: :download:`Download sensor-const-suite-basic.cpp
             </trainings/material/soup/cxx-code/sensors-core-nopoly/tests/sensor-const-suite-basic.cpp>`

Topics Covered
--------------

.. ot-graph::
   :entries: cxx.exercises.oo_sensors.sensor_mock_const
