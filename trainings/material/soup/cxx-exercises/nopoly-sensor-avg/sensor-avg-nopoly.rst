.. include:: <mmlalias.txt>


Exercise: ``AveragingSensor_nopoly`` (Non-Polymorphic)
======================================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/initializer-list`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Requirement
-----------

Implement a sensor class ``AveragingSensor_nopoly`` which is not a
real sensor. Rather, it calculates its temperature as the average from
a configurable set of sensors that it knows.

.. literalinclude:: /trainings/material/soup/cxx-exercises/nopoly-sensor-avg/code/tests/sensor-avg-nopoly-basic.cpp
   :language: c++
   :caption: :download:`Download sensor-avg-nopoly-basic.cpp
	     </trainings/material/soup/cxx-exercises/nopoly-sensor-avg/code/tests/sensor-avg-nopoly-basic.cpp>`

.. literalinclude:: /trainings/material/soup/cxx-exercises/nopoly-sensor-avg/code/tests/sensor-avg-nopoly-change-temperatures.cpp
   :language: c++
   :caption: :download:`Download
	     sensor-avg-nopoly-change-temperatures.cpp
	     </trainings/material/soup/cxx-exercises/nopoly-sensor-avg/code/tests/sensor-avg-nopoly-change-temperatures.cpp>`
