SOLID: Hysteresis With Display
==============================

Consider the following class definitions ...

.. literalinclude:: q-solid--hysteresis-with-display/hysteresis-with-display.h
   :language: c++

The problem with the definition of ``Hysteresis`` is obvious: for
devices without any kind of temperature display, the ``Display*``
parameter to its constructor will not be passed (respectively, it will
be passed as NULL pointer).

Which of the five SOLID principles are violated? Which are not? Comment!

.. list-table::
   :align: left
   :widths: 10 50 50
   :header-rows: 1

   * * Principle
     * Why violated?
     * Why not?
   * * Single Responsibility
     *
     *
   * * Open/Closed
     * 
     *
   * * Liskov Substitution
     *
     *
   * * Interface Segregation
     *
     *
   * * Dependency Inversion
     *
     *
