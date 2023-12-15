.. include:: <mmlalias.txt>

.. ot-task:: fh2021.switch_interface


(DONE) Switch Interface
=======================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx-exercises/nopoly-switch-mock/switch-mock-nopoly`

We have ``MockSwitch`` that serves no real purpose but
testing. Prepare the ground for future "real" switches (see below).

* Define a ``Switch`` interface (``switch.h``, much like ``sensor.h``)
* Change ``MockSwitch`` to be *an implementation of* ``Switch``
* Modify ``LEDStripeDisplay`` to use ``Sensor`` and ``Switch`` (and
  not ``MockSensor`` and ``MockSwitch``)
* Modify ``Hysteresis`` to use ``Sensor`` and ``Switch`` (and not
  ``MockSensor`` and ``MockSwitch``)
