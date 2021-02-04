.. include:: <mmlalias.txt>

Multiple Devices (Screenplay)
=============================

.. contents::
   :local:

Multiple Devices: Module Parameter
----------------------------------

* *Careful*, don't reserve only one minor, but rather the maximum:
  ``MINORMASK``
* Fill device list with as many devices

``ioctl``: Add Device
---------------------

* Figure out which is the next minor number to use
* Note how we jump through hoops to get fops in: forward-declaring all
  cdev fops methods
