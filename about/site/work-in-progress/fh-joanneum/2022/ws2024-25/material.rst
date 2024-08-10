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

Hardware
........

* Proximity

  * VL53L0X Time-of-Flight (ToF) ranging sensor
  
    * Data sheet: https://www.st.com/en/imaging-and-photonics-solutions/vl53l0x.html
    * Linux kernel driver exists:
      https://github.com/torvalds/linux/blob/master/drivers/iio/proximity/vl53l0x-i2c.c
  
      * User space access yet unclear, research needed
      * Maybe (if only for educational purposes) hack that across
        ``/dev/i2c-1``

* Gyroskop

  * Interrupts? -> libgpiod

* ADC
* Motor

  * Stellmotor -> PWM?
  * Motorsteuerungen ueber I2C/SPI
  * Servo vs. Motor

* Display

  * OLED, direkt ueber SPI oder I2C:
    https://luma-oled.readthedocs.io/en/latest/hardware.html

    * `SSD1305 OLED 2,23" Anzeige Raspberry Pi Plattform-Evaluierung
      Erweiterungsboard
      <https://www.digikey.at/de/products/detail/adafruit-industries-llc/4567/12339162?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_High%20ROAS&utm_term=&productid=12339162&utm_content=&utm_id=go_cmp-20261091338_adg-_ad-__dev-c_ext-_prd-12339162_sig-CjwKCAjwqf20BhBwEiwAt7dtda7tVbbeSd6kjMnPBxrkZLY_TYz3RvuQZYBQAubuGW5NeJ6oBvJmsBoCvssQAvD_BwE&gad_source=1&gclid=CjwKCAjwqf20BhBwEiwAt7dtda7tVbbeSd6kjMnPBxrkZLY_TYz3RvuQZYBQAubuGW5NeJ6oBvJmsBoCvssQAvD_BwE>`__

  * TFT, Pi Hat?

    * `WAVESHARE Raspberry Pi Shield - Display LCD-Touch, 5", 800x480
      Pixel
      <https://www.reichelt.at/at/de/shop/produkt/raspberry_pi_shield_-_display_lcd-touch_5_800x480_pixel-227755?PROVID=2807&gad_source=1&gclid=CjwKCAjwqf20BhBwEiwAt7dtdQC510ClsIcayYg4_iPbRrg22QSyKgm6a-glYejbUuk5lJxGITZ4-RoCQK0QAvD_BwE&q=%2Fat%2Fde%2Fshop%2Fraspberry-pi-shield-display-lcd-touch-5-800x480-pixel-rasp-pi-5td-wav-p227755.html>`__

  

Hardware-Interfaces
...................

* Calibration

  * Stellmotor
  * Sensoren allgemein
  * Template, je nach Art/Calibration (e.g. table with 1024 entries,
    one for each possible value in range(2**10))

* ADC get_value() -> double
* Gyro
* PWM(duty,period).set_percentage(double)
* Stellmotor?
* Motor?
* Proximity
* Timer? Mocking time for tests?

Algorithms
..........

* Per SSH/commandline. Commands, die man spaeter auch braucht fuer
  Regelkreise

  * forward speed(accel curve?), time: cancel current setting if any
    (void_movement to not have any extra cases for None), establish
    new one
  * turn right/left degrees
  * sense gyro
  * sense proximity
  * sense rpm?
  * read errors
  * wait (timer)
