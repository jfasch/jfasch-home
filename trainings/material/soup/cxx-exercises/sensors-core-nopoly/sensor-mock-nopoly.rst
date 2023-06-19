.. ot-exercise:: cxx.exercises.oo_sensors.sensor_mock_nopoly
   :dependencies: cxx03.data_encapsulation.classes_objects,
		  linux.toolchain.cmake_local

.. include:: <mmlalias.txt>


Exercise: ``MockSensor_nopoly`` (Non-Polymorphic)
=================================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Requirement
-----------

Implement a sensor class ``MockSensor_nopoly`` which does not access any real
hardware, but rather has a method ``set_temperature()``. Unit tests
use that method to change the value of future temperature
measurements.

.. literalinclude:: /trainings/material/soup/cxx-exercises/sensors-core-nopoly/code/tests/sensor-mock-nopoly-basic.cpp
   :language: c++
   :caption: :download:`Download sensor-mock-nopoly-basic.cpp
             </trainings/material/soup/cxx-exercises/sensors-core-nopoly/code/tests/sensor-mock-nopoly-basic.cpp>`

Topics Covered
--------------

.. ot-graph::
   :entries: cxx.exercises.oo_sensors.sensor_mock_nopoly
