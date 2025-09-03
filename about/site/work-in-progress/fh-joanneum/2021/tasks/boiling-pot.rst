.. include:: <mmlalias.txt>


(DONE) Boiling Pot (The Beginning)
==================================

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx-exercises/nopoly-hysteresis/hysteresis-nopoly`

.. contents::
   :local:

Standup Records
---------------

2023-11-20
..........

* Complete tests (define a few more?)
* Pull request
* Team to continue on :doc:`switch-interface`

2023-12-14
..........

* Should be complete, no?

Requirements
------------

Write a program ``bin/boiling-pot.cpp`` that implements a boiling
pot. Usage should be somewhat like so:

.. code-block:: console
   :caption: Onewire Sensor at address ``02131d959eaa``, using GPIO
             number 20 to switch heating on/off

   $ bin/boiling-pot /sys/bus/w1/devices/28-02131d959eaa/temperature 20

.. code-block:: console
   :caption: HWMON Onewire Sensor no. 2, using GPIO number 20 to
             switch heating on/off

   $ bin/boiling-pot /sys/class/hwmon/hwmon2/temp1_input 20

.. code-block:: console
   :caption: A manually written file (for testing), using GPIO number
             20 to switch heating on/off

   $ bin/boiling-pot ~/manually-written-file 20

Implementation
--------------

.. attention::

   This task has a dependency on :doc:``switch-interface``! (A boiling
   pot wants to use a real switch, not only a mocking one.)

   Before you implement a switch interface (and derive mocking and
   real switches from it), **talk to the guys** from
   :doc:`sysfs-gpio-switch`. Or else it may happen that both groups do
   duplicate work which results in Git conflicts!

* Write a ``class BoilingPot`` that is used in the program. That class
  will likely use a ``Hysteresis`` internally to implement the control
  logic. (That class - ``Hysteresis`` - takes a ``Sensor`` and a
  ``Switch`` object.)
* ``class BoilingPot`` has a "temperature wheel" (a control knob) that
  steers that desired temperature of the pot.
* Lets hardcode the hysteresis ``low``/``high`` range for the time
  being. This control can be added later once we need it.

Testing
-------

**Write unit tests to cover the all functionality**

Future (*Not* Part Of This Development Cycle)
---------------------------------------------

* Temperature display |longrightarrow| later (we have
  ``LEDStripeDisplay``, but that *is-not-a* ``Display``)
* Modifiable low/high hysteresis settings
* Error reporting ("unreasonable sensor value"?)
* Status reporting ("switch on", "switch off", for example)
