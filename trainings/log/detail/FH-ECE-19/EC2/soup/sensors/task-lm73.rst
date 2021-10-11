.. ot-task:: ec2.sensors.task_lm73
   :dependencies: ec2.devenv.sphinx_intro, 
		  ec2.devenv.virtualbox,
		  ec2.sensors.task_sensor_iface,
		  ec2.devenv.hwdoc

Temperature Sensor: LM73
========================

.. contents::
   :local:

Description
-----------

Write a Python class that implements the ``Thermometer``
:doc:`interface <task-sensor-iface>`, and sits on top of the `LM73
<https://www.ti.com/product/LM73>`__ temperature sensor.

Further Information
-------------------

* :doc:`/trainings/material/soup/linux/hardware/i2c/topic`
* :download:`Datasheet <lm73.pdf>`
* `TI product page <https://www.ti.com/product/LM73>`__

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_lm73
