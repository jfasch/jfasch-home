.. include:: <mmlalias.txt>


Temperature Display: LED Via A PWM Controller
=============================================

.. contents::
   :local:

.. sidebar::
   
   **See also**

   * :doc:`/trainings/material/soup/linux/hardware/pwm/topic`

Standup Records
---------------

2023-11-20
..........

* Use raw file IO (see :doc:
  :doc:`/trainings/material/soup/linux/sysprog/file-io/basics`)
* Do not do the ``export`` (making ``/sys/class/pwm/pwmchip0/pwm0``
  available to userspace) dance; rather place that responsibility on a
  "system-setup phase" (that we don't have).

  "System setup" will have to be done manually before an application
  run. At the time that this becomes too cumbersome, define how we
  want it.
* Look out for something like

  .. code-block:: c++

     class PercentageDisplay
     {
     public:
         // ...
         virtual void show_percentage(unsigned int) = 0;
         // ...
     };

* Refactoring round (just like :doc:`switch-interface`): put
  everything display-like under its hood

2023-12-14
..........

* ``src_demos/``? Move things to ``toolcase/base/``!
* What's the relationship between, e.g.

  * ``src_demos/LEDStripeDisplay.h`` and
    ``toolcase/base/display-led-stripe.h``
  * ``src_demos/PWMDisplay.h`` and ``toolcase/base/pwm_controller.h``

  |longrightarrow| unify!

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

  * ``void set_percentage(unsigned long percentage);``

    Compute the appropriate *duty cycle* and write that into the
    ``duty_cycle`` file.

  * Use unbuffered IO, like in
    :doc:`/trainings/material/soup/linux/sysprog/file-io/basics`, and in
    the exercise
    :doc:`/trainings/material/soup/linux/sysprog/file-io/basics-exercise-copy/exercise`


Testing
-------

It is hard to come up with automatic tests for real
hardware. (Although the file operations could somehow be verified.)

Write a test program in ``bin/`` that you use interactively/manually.

Future (*Not* Part Of This Development Cycle)
---------------------------------------------

(None)
