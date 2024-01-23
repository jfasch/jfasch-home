SOLID: Sensor Has ID
====================

Consider the following ``Sensor`` hierarchy (and imagine that there
are many more implementations like ``W1Sensor`` out there that
implement the ``Sensor`` interface).

.. literalinclude:: q-solid--sensor-with-id/sensor.h
   :language: c++

.. literalinclude:: q-solid--sensor-with-id/sensor-w1.h
   :language: c++

Here is a sampe usage of the ``W1Sensor`` class.

.. literalinclude:: q-solid--sensor-with-id/sensor-with-id-main.cpp
   :language: c++

Which of the five SOLID principles are violated? (Wrong answers are
subtracted from correct answers)

.. list-table::
   :align: left
   :widths: auto

   * * `X` if violated
     * Principle
   * * 
     * Single Responsibility
   * * 
     * Open/Closed
   * * 
     * Liskov Substitution
   * * 
     * Interface Segregation
   * * 
     * Dependency Inversion
