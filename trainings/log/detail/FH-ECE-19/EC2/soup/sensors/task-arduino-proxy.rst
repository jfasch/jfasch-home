.. ot-task:: ec2.sensors.task_arduino_proxy
   :dependencies: ec2.sensors.task_sensor_iface,
		  ec2.devenv.virtualbox

Arduino/Raspberry Communication (Proxy Sensor)
==============================================

.. contents::
   :local:

Description
-----------

An application of the `proxy pattern
<https://en.wikipedia.org/wiki/Proxy_pattern>`__:

* The physical sensor sits on an Arduino (the Arduino starter kit
  contains a number such of sensors).
* The Arduino program communicates the sensor values to the Raspberry,
  using a serial cable.
* On the Raspberry, a dedicated class reads those values from the
  other end of the cable. That class is at the same level of the above
  classes, and implements the same :doc:`interface
  <task-sensor-iface>`: it **is-a** thermometer.
* *Protocol considerations*

  The interface above is *synchronous*: on request (the user calls the
  method ``get_temperature()``), the current temperature is read and
  returned.

  To fit that paradigm, the protocol must also be *synchronous*:

  * Raspberry to Arduino: "Hey, give me the temperature!"
  * (Arduino: reads temperature from device)
  * Arduino to Raspberry: sends temperature

  A number of ubiquitous problems on the horizon. Sooner or later, one
  or all of the following will become apparent:

  * Arduino hangs. Temperature response will not come back from it
    within a timeout period.
  * Arduino sees overlapping requests because the Raspberry
    misbehaves. How to deal with this?

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_arduino_proxy
