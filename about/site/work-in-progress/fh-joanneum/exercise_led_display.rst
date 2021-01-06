.. jf-topic:: fh.exercise_led_display
   :dependencies: fh.exercise_avg_sensor,
		  fh.gpio,
		  fh.cxx_unittest

Exercise: LED Temperature Display
=================================

Goals
-----

* Learn how to use GPIO pins on Linux
* Learn how to abstract details away. Talk about *boolean* values, and
  not LEDs that emit light or not.

Hardware
--------

* A number of LEDs, arranged linearly from left (cold) to right (hot)
* The usual sensors

Outcome
-------

A program that

* ... periodically queries the configured thermometers and builds the
  average. This is done by using one single *averaging* thermometer
  that does the query, internally.
* ... feeds the computed average temperature into said LED display
  device. 

  * That display device is abstracted into something that *just
    displays* temperatures (its users don't want to have to know that
    it is implemented with seven LEDs).

* A number of unit tests
