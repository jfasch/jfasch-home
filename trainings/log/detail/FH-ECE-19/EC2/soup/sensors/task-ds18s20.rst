.. ot-task:: ec2.sensors.task_ds18s20
   :dependencies: ec2.devenv.sphinx_intro, 
		  ec2.devenv.virtualbox,
		  ec2.sensors.task_sensor_iface,
		  ec2.devenv.hwdoc

Temperature Sensor: DS18S20
===========================

.. contents::
   :local:

Description
-----------

Write a Python class that implements the ``Thermometer``
:doc:`interface <task-sensor-iface>`, and sits on top of the `DS18S20
<https://www.maximintegrated.com/en/products/sensors/DS18S20.html>`__
Onewire temperature sensor.

Further Information
-------------------

* :doc:`/trainings/material/soup/linux/hardware/w1/topic`
* :download:`Datasheet <DS18S20.pdf>`
* `Onewire filesystem
  <https://www.kernel.org/doc/html/latest/w1/index.html>`__
* `Analog Devices product page
  <https://www.maximintegrated.com/en/products/sensors/DS18S20.html>`__

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_ds18s20
