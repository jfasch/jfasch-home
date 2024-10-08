.. include:: <mmlalias.txt>


Proximity Sensor: VL53L1X
=========================

.. contents::
   :local:

Facts
-----

Time-of-Flight (ToF) ranging sensor.

* Breakout board: https://shop.pimoroni.com/products/vl53l1x-breakout
* Data sheet:
  https://www.st.com/en/imaging-and-photonics-solutions/vl53l1x.html

Notes
-----

* The device emits interrupts |longrightarrow| how could we make use
  of them?
* Linux kernel driver exists for VL53L0X
  https://github.com/torvalds/linux/blob/master/drivers/iio/proximity/vl53l0x-i2c.c

  * User space access for that driver yet unclear, research needed
  * Maybe (if only for educational purposes) hack that across
    ``/dev/i2c-1``

