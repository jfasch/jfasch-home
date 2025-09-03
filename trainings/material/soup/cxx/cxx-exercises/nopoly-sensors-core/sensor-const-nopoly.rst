.. include:: <mmlalias.txt>


Exercise: ``ConstantSensor_nopoly`` (Non-Polymorphic)
=====================================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Requirement
-----------

Implement a sensor class ``ConstantSensor_nopoly`` which does not
access any real hardware, but rather always measures the same
temperature - the one it is initialized with.

.. literalinclude:: /trainings/material/soup/cxx/cxx-exercises/nopoly-sensors-core/code/tests/sensor-const-nopoly-basic.cpp
   :language: c++
   :caption: :download:`Download sensor-const-nopoly-basic.cpp
             </trainings/material/soup/cxx/cxx-exercises/nopoly-sensors-core/code/tests/sensor-const-nopoly-basic.cpp>`
