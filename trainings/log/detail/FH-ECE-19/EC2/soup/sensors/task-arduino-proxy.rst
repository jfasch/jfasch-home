.. ot-task:: ec2.sensors.task_arduino_proxy
   :dependencies: ec2.sensors.task_sensor_iface


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

Integration
-----------

Due to the complexity of this task, the integrator's role is not a
simple one.

* **Testing** 

  * Communicate with the development department what's
    available. 
  * Setup the sensor (Arduino plus serial cable), according to their
    instructions.
  * Write a small test program. Better yet: use that of your
    development department, or complain to your development department
    why they leave you with untested code.

  Do all this in front of your documentation department, because they
  will have to explain what you are doing to :doc:`others
  <task-prog-stdout>`.

* **Communicate to users**

  The primary outcome of :doc:`task-prog-stdout` is two different
  configuration file formats that *instantiate* all thermometers,
  *including yours*.

  Notify them when your group's outcome is in a shape to be integrated
  by them, *and help them do this*. 

  *Note* that you might need to push your documentation department to
  do their job. Ideally, :doc:`task-prog-stdout` should be able to
  accomplish integration on their own. To reach that goal, you need to
  enter a "Read docs, try, fail, feedback" loop.

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_arduino_proxy
