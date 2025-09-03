.. include:: <mmlalias.txt>


Display Interface/Infrastructure
================================

.. contents::
   :local:

Standup Records
---------------

Requirements
------------

.. sidebar::

   **See also**

   * :doc:`pwm-display`
   * `display-led-stripe.h
     <https://github.com/jfasch/FH-ECE21/blob/main/toolcase/base/display-led-stripe.h>`__

New Interface ``PercentageDisplay``
...................................

There is a new interface, ``PercentageDisplay``, defined in
`percentage-display.h
<https://github.com/jfasch/FH-ECE21/blob/main/toolcase/base/percentage-display.h>`__

.. code-block:: c++

   class PercentageDisplay
   {
   public:
       virtual ~PercentageDisplay() = default;
       virtual void show_percentage(double) = 0;
   };


Existing Implementations
........................

We have two implementations that show temperatures; put those under
this interface.

* :doc:`pwm-display`
* `display-led-stripe.h
  <https://github.com/jfasch/FH-ECE21/blob/main/toolcase/base/display-led-stripe.h>`__

*Composite* Display
...................

Implement a
:doc:`/trainings/material/soup/cxx/cxx-design-patterns/composite/composite`
display.

Testing: Breadboard Acrobatics, Demo Program
--------------------------------------------

Wire onto the breadboard

* PWM as in :doc:`pwm-display`
* Eight (say) LEDs, each connected to a GPIO

Write one test program ``demo/display-demo``) that 

* instantiates both classes
* Store pointers to both objects in a ``std::vector<PercentageDisplay*>``
* Enter a loop that changes the percentage shown on each periodically

  That program is already there, in ``src_demos/main.cpp``, together
  with much of the ``Display`` stuff. Clean it up.
