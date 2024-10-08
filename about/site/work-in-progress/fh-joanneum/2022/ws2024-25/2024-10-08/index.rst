.. include:: <mmlalias.txt>


2024-10-08(6): Project/Peripherals/Cross
========================================

.. contents::
   :local:

Devices Overview
----------------

* :doc:`../project/proximity-vl53l1x`
* :doc:`../project/gyroscope-bno055`
* :doc:`../project/motor-control-btn9960lv`
* :doc:`../project/display-waveshare`
* :doc:`../project/servo-motor`

Cross Development Recap
-----------------------

* :doc:`/trainings/material/soup/linux/toolchain/cross/basics`
* :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
* :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`

Hardware Interfaces
-------------------

I2C
...

* Enable I2C on Raspi

  * :ref:`w1-i2c-raspi-bootloader`
  * :ref:`w1-i2c-raspi-i2cdetect`

* Userspace I2C, ``/dev/i2c-1``, ``ic2-dev`` and SMBus:

  * Kernel documentation:
    https://docs.kernel.org/i2c/dev-interface.html
  * Example using LM73 temperature sensor: :ref:`lm73-userspace-i2c`

PWM
...

* :doc:`/trainings/material/soup/linux/hardware/pwm/topic`

SPI
...

* `ws2812-spi on Github
  <https://github.com/jfasch/ws2812-spi>`__. Look into `ws2812/spi.cpp
  <https://github.com/jfasch/ws2812-spi/blob/main/ws2812/spi.cpp>`__:

  .. code-block:: c++

     struct spi_ioc_transfer tr = {
         .tx_buf = (unsigned long)xfer_bytes,
         .len = (uint32_t)xfer_size,
         .speed_hz = s.profile().frequency_hz,
     };

     int ret = ioctl(_fd, SPI_IOC_MESSAGE(1), &tr);

* https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf

  Things to take into accout when you use SPI to clock out multi-byte
  waveforms. Take care of "2.3.1. SPI implementation details", where
  they say that there is a garanteed gap between two bytes. During
  that time the MOSI signal is also low (alas it's SPI).
