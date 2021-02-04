.. include:: <mmlalias.txt>

Multiple Devices (Slideshow)
============================

.. contents::
   :local:

Module Parameter: ``ndevices``
------------------------------

.. code-block::

   module_param(ndevices, int, 0);

* Fill list with as many devices as the parameter says.
* Range checking on ``ndevices``

New ``ioctl``: *Add Event*
---------------------------

* On demand add new devices.
* Somewhat like the ``probe()`` method of the PCI and USB subsystems.
* Not so beautiful: a new device can be added via *any* existing device

  * Bad if somebody give ``ndevices=0``
  * Should have a master/control device which is always there
  * Anyway, I just don't care

