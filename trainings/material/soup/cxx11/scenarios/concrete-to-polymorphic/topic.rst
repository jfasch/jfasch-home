From Concrete To Polymorphic (``class Sensor``)
===============================================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/index`

Most Concrete, And Old School
-----------------------------

.. sidebar:: Documentation

   * `man -s2 time
     <https://man7.org/linux/man-pages/man2/time.2.html>`__
   * `man -s3 sleep
     <https://man7.org/linux/man-pages/man3/sleep.3.html>`__

* Mock sensor straightforward, with a method ``set_value()`` for test
  usage. (Note that ``Logger`` only uses ``get_value()``.)

.. literalinclude:: code/concrete-no-chrono/sensor-mock.h
   :language: c++
   :caption: :download:`code/concrete-no-chrono/sensor-mock.h`

* ``Logger::log_one()`` takes the current time, and outputs the sensor
  value along with it (`man -s2 time
  <https://man7.org/linux/man-pages/man2/time.2.html>`__).

.. literalinclude:: code/concrete-no-chrono/logger.h
   :language: c++
   :caption: :download:`code/concrete-no-chrono/logger.h`

* Main program calls ``logger.log_one()`` at a one-second interval
  (`man -s3 sleep
  <https://man7.org/linux/man-pages/man3/sleep.3.html>`__)

.. literalinclude:: code/concrete-no-chrono/main.cpp
   :language: c++
   :caption: :download:`code/concrete-no-chrono/main.cpp`

Use ``std::chrono`` For Time
----------------------------

* logger

  * time -> chrono :doc:`/trainings/material/soup/cxx11/chrono/topic`

    * copy from :ref:`cxx11-chrono-clock-domains` -> system_clock
    * use auto :doc:`/trainings/material/soup/cxx11/auto/topic`

  * talk about system_clock vs steady_clock

* main

  * use chrono/thread -> literals
