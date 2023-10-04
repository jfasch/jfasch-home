.. ot-exercise:: cxx.exercises.sensor_mock_nopoly
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

Implement a sensor class ``MockSensor_nopoly`` which does not access
any real hardware to measure temperature. Rather, it has a method
``set_temperature()`` which can be used (by unit tests, ideally) to
control the value that is returned by subsequent calls to
``get_temperature()``.

Use the following test to guide you through the implementation:

.. literalinclude:: /trainings/material/soup/cxx-exercises/nopoly-sensors-core/code/tests/sensor-mock-nopoly-basic.cpp
   :language: c++
   :caption: :download:`Download sensor-mock-nopoly-basic.cpp
             </trainings/material/soup/cxx-exercises/nopoly-sensors-core/code/tests/sensor-mock-nopoly-basic.cpp>`

Topics Covered
--------------

.. ot-graph::
   :entries: cxx.exercises.sensor_mock_nopoly
