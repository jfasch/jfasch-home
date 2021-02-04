.. include:: <mmlalias.txt>

Interrupts (Screenplay)
=======================

.. contents::
   :local:

New ``ioctl``: ``MY_ACTIVATE_GPIO``
-----------------------------------

* Aha, third ``ioctl()`` parameter: ``unsigned long``
* Add new ``my_device`` method, ``my_device_activate_gpio()``, and
  call right into it
