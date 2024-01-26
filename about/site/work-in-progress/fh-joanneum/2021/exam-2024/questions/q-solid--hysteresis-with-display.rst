SOLID: Hysteresis With Display
==============================

Consider the following class definitions ...

.. literalinclude:: q-solid--hysteresis-with-display/hysteresis-with-display.h
   :language: c++

The problem with the definition of ``Hysteresis`` is obvious: for
devices without any kind of temperature display, the ``Display*``
parameter to its constructor will not be passed (respectively, it will
be passed as NULL pointer).

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
