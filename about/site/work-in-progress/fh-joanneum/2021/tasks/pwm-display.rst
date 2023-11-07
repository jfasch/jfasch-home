.. include:: <mmlalias.txt>

.. ot-task:: fh2021.pwm_display


Temperature Display: LED Via A PWM Controller
=============================================

.. sidebar::
   
   **See also**

   * :doc:`/trainings/material/soup/linux/hardware/pwm/topic`


Requirements
------------

Implement a class that implements PWM control according to
:doc:`/trainings/material/soup/linux/hardware/pwm/topic`.

When done, try hard to unify (by defining an *interface* that both
*implement*) that class with the ``LEDStripeDisplay`` that we have in
our project. *Hint:* both are used to show *percentages*.

Implementation
--------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/hardware/pwm/topic`

* Write a ``class PWMDisplay`` that has methods

  * (Constructor). Configures the PWM channel; parameters ``channel``
    (``int``) and ``period`` (``unsigned long``?).

    * Export the PWM channel. Write ``5`` (or whatever the channel is)
      into ``/sys/class/pwm/export``. **Note that one has to wait a
      bit** until the ``pwm5`` directory becomes visible.
    * Configure the *period*. Write ``10000000`` (or whatever
      ``period`` was configured) into the ``period`` file.

  * ``void set(unsigned long percentage);``

    Compute the appropriate *duty cycle* and write that into the
    ``duty_cycle`` file.

Testing
-------

It is hard to come up with automatic tests for real
hardware. (Although the file operations could somehow be verified.)

Write a test program in ``bin/`` that you use interactively/manually.

Future (*Not* Part Of This Development Cycle)
---------------------------------------------

(None)

Dependencies
------------

.. ot-graph::
   :entries: fh2021.pwm_display
