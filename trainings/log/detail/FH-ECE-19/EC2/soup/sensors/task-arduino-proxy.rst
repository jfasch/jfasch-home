.. ot-task:: ec2.sensors.task_arduino_proxy
   :dependencies: ec2.sensors.task_sensor_iface,
		  ec2.devenv.virtualbox

Arduino/Raspberry Communication (Proxy Sensor)
==============================================

.. contents::
   :local:

Description
-----------

This work is an application of the `proxy pattern
<https://en.wikipedia.org/wiki/Proxy_pattern>`__.

* The sensor-reading application (for example :doc:`task-prog-stdout`
  or :doc:`../mqtt/task-prog-mqtt`) runs on the Raspberry.
* The physical sensor sits on an Arduino (the Arduino starter kit
  contains a number of such sensors).
* Raspberry and Arduino are connected with a serial cable.

Subtasks
--------

* **Protocol**. Over the serial cable, a protocol must be
  implemented. This is the most critical task.
* **Raspberry**: a ``Thermometer`` subclass (say,
  ``SerialThermometer``) implements the ``get_temperature()`` method
  by

  * writing the request "Hey, give me the temperature!" onto the
    serial cable, to the Arduino.
  * reading the Arduino's response (the temperature) from the cable.

  Implemention language is Python; the `pyserial package
  <https://pypi.org/project/pyserial/>`__ provides a comfortable
  interface for UART communication.

* **Arduino**: the firmware main loop ...

  * listens on the cable for requests ("Hey, give me the temperature!"
    from the Raspberry).
  * reads the physical temperature from the sensor.
  * writes the temperature back onto the cable.

Expected Problems
-----------------

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
