SOLID: Hysteresis With Display
==============================

Consider the following class definitions ...

.. literalinclude:: q-solid--hysteresis-with-display/hysteresis-with-display.h
   :language: c++

The problem with the definition of ``Hysteresis`` is obvious: for
devices without any kind of temperature display, the ``Display*``
parameter to its constructor will not be passed (ok, technically it
will be passed as NULL pointer).

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
