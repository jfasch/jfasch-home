.. include:: <mmlalias.txt>

.. ot-task:: fh2021.sysfs_gpio_switch
   :dependencies: fh2021.switch_interface


SysFS GPIO Switch
=================

.. contents::
   :local:

Standup Records
---------------

2023-11-20
..........

* Pull request won't accept changes other than necessary to complete
  task

  * Revert all changes that were made to fix upstream errors
  * Update fork (see :doc:`../git/git`)

Requirements
------------

.. sidebar::

   **See also**

   * :doc:`boiling-pot`
   * ``class Hysteresis`` in our project
   * ``class LEDStripeDisplay`` in our project
   * ``class MockSwitch`` in our project

Write a class ``SysFSGPIOSwitch`` that uses
:doc:`/trainings/material/soup/linux/sysprog/intro-hw/sysfs-gpio`
internally.

This class is going to be used to implement switches that software
might want to use in real life.

Implementation
--------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/sysprog/intro-hw/sysfs-gpio`
   * :doc:`/trainings/material/soup/linux/sysprog/file-io/basics`
   * :doc:`/trainings/material/soup/linux/sysprog/file-io/basics-exercise-copy/exercise`

.. attention::

   This task has a dependency on :doc:``switch-interface``! A real
   switch is used under *real* conditions, whereas a *mocking* switch
   is used for testing - code should not depend on implementations,
   but rather on interfaces.

   Before you implement a switch interface (and derive your switch
   class from it), **talk to the guys** from :doc:`boiling-pot`. Or
   else it may happen that both groups do duplicate work which results
   in Git conflicts!

* Write a ``class SysFSGPIOSwitch`` that has methods

  * (Constructor). Configures the GPIO.

    * Export the GPIO. Write ``20`` (or whatever the pin's number is)
      into ``/sys/class/gpio/export``. **Note that one has to wait a
      bit** until the ``gpio20`` directory becomes visible.  for output
      (exports the pin, write ``out`` into the IO's ``direction``
      file).
    * Configure for output. Write ``out`` into the GPIO's
      ``direction`` file.

  * ``void set_state(bool);``

    Write ``0`` or ``1`` to the IO's ``value`` file, to control the
    pin's output voltage.

Testing
-------

It is hard to come up with automatic tests for real
hardware. (Although the file operations could somehow be verified.)

Write a test program in ``bin/`` that you use interactively/manually.

Future (*Not* Part Of This Development Cycle)
---------------------------------------------

* Should we do the configuration in the constructure? Or is it better
  to proide a ``configure()`` method that is called later in a
  program's lifecycle?
* An alternative GPIO interface, ``libgpiod`` (see
  :doc:`/about/site/work-in-progress/blink/glt2023/installation`). SysFS
  GPIO is deprecated!

Dependencies
------------

.. ot-graph::
   :entries: fh2021.sysfs_gpio_switch, fh2021.boiling_pot
