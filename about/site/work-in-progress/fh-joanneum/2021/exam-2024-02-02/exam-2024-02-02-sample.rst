WS2023/2024: Exam 2024-02-02 (Sample)
=====================================

.. list-table::
   :align: left

   * * **Name**
     * 

SOLID
-----

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx-design-patterns/oo-principles`
   * `SOLID on Wikipedia <https://en.wikipedia.org/wiki/SOLID>`__

Question 1
..........

Consider the following ``Sensor`` hierarchy (and imagine that there
are many more implementations like ``W1Sensor`` out there that
implement the ``Sensor`` interface).

.. literalinclude:: sensor-with-id/sensor.h
   :language: c++

.. literalinclude:: sensor-with-id/sensor-w1.h
   :language: c++

Here is a sampe usage of the ``W1Sensor`` class.

.. literalinclude:: sensor-with-id/sensor-with-id-main.cpp
   :language: c++

Which of the five SOLID principles are violated? (Wrong answrs are
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
