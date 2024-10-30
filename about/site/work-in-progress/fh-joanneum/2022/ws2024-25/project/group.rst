.. ot-group:: fh.crazycar

Project: Linux On Crazy Car?
============================

.. contents::
   :local:

Project Structure And Goal
--------------------------

Basic Components
................

Create Linux prototype implementations for the hardware devices that
are found on a car. These implementations should be usable from many
possible architectures, including the reference architectures below,
but also from more static architectures.

* :doc:`proximity-vl53l1x`
* :doc:`gyroscope-bno055`
* :doc:`motor-control-btn9960lv`
* :doc:`servo-motor`
* :doc:`sysfs-pwm`

**What's to come?**

* devices needing calibration
* configure acceleration ramps on top of motor control

Reference Architecture
......................

On top of the basics components, create a reference architecture

.. libreoffice:: architecture.odg

Task List
.........

The tasks that are currently on the horizon:

.. toctree::
   :maxdepth: 1

   proximity-vl53l1x
   gyroscope-bno055
   motor-control-btn9960lv
   servo-motor
   sysfs-pwm

Ideas
-----

.. toctree::
   :maxdepth: 1

   display-ssd1305
   display-waveshare

* Algorithms
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

Tasks And Dependencies
----------------------

.. ot-graph::
   :entries: fh.crazycar
