.. include:: <mmlalias.txt>

.. ot-task:: fh2021.libgpiod_switch
   :dependencies: fh2021.switch_interface


``libgpiod`` Switch
===================

Requirements
------------

.. sidebar::

   **See also**

   * ``libgpiod`` Link jjj
   * :doc:`boiling-pot`
   * ``class Hysteresis`` in our project
   * ``class LEDStripeDisplay`` in our project
   * ``class MockSwitch`` in our project

Write a class ``LibGPIODSwitch`` that uses jjj link internally.

This class is going to be used to implement switches that software
might want to use in real life.

Implementation
--------------

.. sidebar::

   **See also**

   * ``libgpiod`` Link jjj

.. attention::

   This task has a dependency on :doc:`switch-interface`.

* Write a ``class LibGPIODSwitch`` that has methods

  * (Constructor). Configures the GPIO.

    * jjj initialization
    * Configure for output

  * ``void set_state(bool);``

Testing
-------

Write a test program in ``bin/`` that you use
interactively/manually. Much like :doc:`sysfs-gpio-switch`.

Future (*Not* Part Of This Development Cycle)
---------------------------------------------

Dependencies
------------

.. ot-graph::
   :entries: fh2021.libgpiod_switch
