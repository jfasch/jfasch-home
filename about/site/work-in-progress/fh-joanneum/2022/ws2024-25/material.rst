.. include:: <mmlalias.txt>


Embedded Computing 2 (STECE-2022): Material
===========================================

.. contents::
   :local:

.. sidebar:: Github Project

   * Github project: https://github.com/jfasch/FH-STECE2022

Crazy Car On Linux Project Plan
-------------------------------

.. note::

   This is currently a draft only!

Sensors
.......

* VL53L0X Time-of-Flight (ToF) ranging sensor

  * Data sheet: https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html
  * Linux kernel driver exists:
    https://github.com/torvalds/linux/blob/master/drivers/iio/proximity/vl53l0x-i2c.c

    * User space access yet unclear, research needed
    * Maybe (if only for educational purposes) hack that across
      ``/dev/i2c-1``
