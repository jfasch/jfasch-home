.. include:: <mmlalias.txt>


Exercise: ``LEDStripeDisplay_nopoly`` (Non-Polymorphic)
=======================================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx-exercises/nopoly-sensors-core/sensor-mock-nopoly`
   * :doc:`/trainings/material/soup/cxx/cxx-exercises/nopoly-switch-mock/switch-mock-nopoly`
   * :doc:`/trainings/material/soup/cxx/cxx-exercises/nopoly-hysteresis/hysteresis-nopoly`

Requirement
-----------

Implement a temperature display (``class LEDStripeDisplay_nopoly``) as
follows.

* It uses a sensor (a ``MockSensor_nopoly`` for now) to measure the
  temperature
* It controls an "LED bar" consisting of multiple switches
  (``MockSwitch_nopoly``), one per LED.
* It is configured to show temperatures within a certain range

  * Temperatures below that range turn all LEDs off
  * Temperatures above that range turn all LEDs on
  * Temperatures within range are associated with one specific LED,
    which is turned on together with all LEDs left of it

The following tests formally specify the requirement if anything is
left unclear. Use these to complete the exercise, one by one.

.. literalinclude:: code/tests/display_led_stripe_nopoly_suite__somewhere_in_the_middle.cpp
   :language: c++
   :caption: :download:`Download
             display_led_stripe_nopoly_suite__somewhere_in_the_middle.cpp
             <code/tests/display_led_stripe_nopoly_suite__somewhere_in_the_middle.cpp>`

.. literalinclude:: code/tests/display_led_stripe_nopoly_suite__below_range.cpp
   :language: c++
   :caption: :download:`Download
             display_led_stripe_nopoly_suite__below_range.cpp
             <code/tests/display_led_stripe_nopoly_suite__below_range.cpp>`

.. literalinclude:: code/tests/display_led_stripe_nopoly_suite__above_range.cpp
   :language: c++
   :caption: :download:`Download
             display_led_stripe_nopoly_suite__above_range.cpp
             <code/tests/display_led_stripe_nopoly_suite__above_range.cpp>`

.. literalinclude:: code/tests/display_led_stripe_nopoly_suite__movement.cpp
   :language: c++
   :caption: :download:`Download
             display_led_stripe_nopoly_suite__movement.cpp
             <code/tests/display_led_stripe_nopoly_suite__movement.cpp>`

.. literalinclude:: code/tests/display_led_stripe_nopoly_suite__variations.cpp
   :language: c++
   :caption: :download:`Download
             display_led_stripe_nopoly_suite__variations.cpp
             <code/tests/display_led_stripe_nopoly_suite__variations.cpp>`
