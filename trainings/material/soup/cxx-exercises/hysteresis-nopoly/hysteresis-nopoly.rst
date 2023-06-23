.. ot-exercise:: cxx.exercises.oo_sensors.hysteresis_nopoly
   :dependencies: cxx.exercises.oo_sensors.sensor_mock_nopoly,
		  cxx.exercises.oo_switches.switch_mock_nopoly,
		  cxx03.data_encapsulation.classes_objects,
		  linux.toolchain.cmake_local

.. include:: <mmlalias.txt>


Exercise: ``Hysteresis_nopoly`` (Non-Polymorphic)
=================================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Requirement
-----------

Implement a class ``Hysteresis_nopoly`` (a Thermostat) that works as follows.

* It uses a sensor (a ``MockSensor_nopoly`` for now) to measure the
  temperature
* It controls a switch (a ``MockSwitch_nopoly`` for now)
* If the temperature falls below a certain configurable *low*
  threshold, the switch is set to *on* (heating is turned *on*)
* If the temperature rises above a certain configurable *high*
  threshold, the switch is set to *off* (heating is turned *on*)

Use the following tests to drive you through the exercise:

.. literalinclude:: /trainings/material/soup/cxx-exercises/hysteresis-nopoly/code/tests/hysteresis-nopoly-nop_when_within_range.cpp
   :language: c++
   :caption: :download:`Download
             hysteresis-nopoly-nop_when_within_range.cpp
             </trainings/material/soup/cxx-exercises/hysteresis-nopoly/code/tests/hysteresis-nopoly-nop_when_within_range.cpp>`

.. literalinclude:: /trainings/material/soup/cxx-exercises/hysteresis-nopoly/code/tests/hysteresis-nopoly-falls_below_range.cpp
   :language: c++
   :caption: :download:`Download
             hysteresis-nopoly-falls_below_range.cpp
             </trainings/material/soup/cxx-exercises/hysteresis-nopoly/code/tests/hysteresis-nopoly-falls_below_range.cpp>`

.. literalinclude:: /trainings/material/soup/cxx-exercises/hysteresis-nopoly/code/tests/hysteresis-nopoly-rises_above_range.cpp
   :language: c++
   :caption: :download:`Download
             hysteresis-nopoly-rises_above_range.cpp
             </trainings/material/soup/cxx-exercises/hysteresis-nopoly/code/tests/hysteresis-nopoly-rises_above_range.cpp>`

.. literalinclude:: /trainings/material/soup/cxx-exercises/hysteresis-nopoly/code/tests/hysteresis-nopoly-rises_above_range_when_on.cpp
   :language: c++
   :caption: :download:`Download
             hysteresis-nopoly-rises_above_range_when_on.cpp
             </trainings/material/soup/cxx-exercises/hysteresis-nopoly/code/tests/hysteresis-nopoly-rises_above_range_when_on.cpp>`

Topics Covered
--------------

.. ot-graph::
   :entries: cxx.exercises.oo_sensors.hysteresis_nopoly
