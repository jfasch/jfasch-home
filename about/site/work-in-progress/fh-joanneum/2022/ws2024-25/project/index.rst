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

On The Basis
------------

Create Linux prototype implementations for the following hardware
pieces that are found on the next-generation Crazy Car.

* :doc:`proximity-vl53l1x`
* :doc:`gyroscope-bno055`
* :doc:`motor-control-btn9960lv`
* :doc:`servo-motor`

On Top Of The Basis
-------------------

In addition to that, solve problems like

* devices needing calibration
* configure acceleration ramps on top of motor control
* servos likewise

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

