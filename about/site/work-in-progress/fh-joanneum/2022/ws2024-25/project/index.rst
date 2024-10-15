Project Plan (Yay)
==================

.. contents::
   :local:

.. toctree::
   :hidden:

   proximity-vl53l1x
   gyroscope-bno055
   motor-control-btn9960lv
   adc
   servo-motor
   display-ssd1305
   display-waveshare

Goal
----

Create Linux prototype implementations for the following hardware
pieces that are found on the next-generation Crazy Car.

* :doc:`proximity-vl53l1x`
* :doc:`gyroscope-bno055`
* :doc:`motor-control-btn9960lv`
* :doc:`servo-motor`

In addition to that, solve problems like

* devices needing calibration
* configure acceleration ramps on top of motor control
* servos likewise

Hardware-Interfaces
-------------------

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
----------

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

