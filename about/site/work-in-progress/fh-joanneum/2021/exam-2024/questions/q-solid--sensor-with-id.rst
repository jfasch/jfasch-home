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

Obviously the ``id`` attribute of a sensor remains unused in most
situations.

Which of the five SOLID principles are violated? Write an ``X`` if a
principle is violated. Wrong answers are subtracted from correct
answers (the number of correct answers cannot become negative though).

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

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
