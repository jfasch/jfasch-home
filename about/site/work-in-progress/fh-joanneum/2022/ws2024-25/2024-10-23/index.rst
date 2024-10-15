.. include:: <mmlalias.txt>


2024-10-23(6): Project: Linux I2C/PWM/SPI
=========================================

.. contents::
   :local:

I2C
---

Our project has two I2C devices that need to be programmed from
userspace (we want to create prototypes that can be used in other
contexts, and therefore cannot use Linux kernel drivers).

These devices are:

* :doc:`../project/proximity-vl53l1x`
* :doc:`../project/gyroscope-bno055`

Go over Linux userspace I2C:

* :doc:`/trainings/material/soup/linux/hardware/i2c/topic`

Explain difference between userspace I2C, and a kernel driver - coincidentally using a driver for a PWM device:

* :doc:`/trainings/material/soup/linux/hardware/pwm/topic`

PWM
---

* :doc:`../project/motor-control-btn9960lv`

  That device is controlled via two PWM channels. The Raspberry has
  only one (pin 18 has an alternative setting), so we use a PCA9685
  which is connected over I2C.

  |longrightarrow|
  :doc:`/trainings/material/soup/linux/hardware/pwm/topic`

* :doc:`../project/servo-motor`

  Could work over PWM. I suspect not. Read on for SPI.

SPI?
----

In case PWM does not work for the servos, then chances are that it is
PPM (`Wikipedia
<https://en.wikipedia.org/wiki/Pulse-position_modulation>`__)

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
