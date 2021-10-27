.. ot-task:: ec2.sensors.task_lm73_dev
   :dependencies: ec2.devenv.sphinx_intro, 
		  ec2.devenv.virtualbox,
		  ec2.sensors.task_sensor_iface,
		  ec2.devenv.hwdoc

Temperature Sensor: LM73 (via ``i2c-dev``)
==========================================

.. contents::
   :local:

Description
-----------

* Write a Python class that implements the ``Thermometer``
  :doc:`interface <task-sensor-iface>`, and sits on top of the `LM73
  <https://www.ti.com/product/LM73>`__ temperature sensor.
* Integration: the thermometer class (call it ``ThermometerLM73_Dev``)
  implements the I2C protocol *manually*, as described in
  :doc:`/trainings/material/soup/linux/hardware/i2c/topic`: it opens
  the character device ``/dev/i2c-1``, connects to the device, and
  writes and reads bytes as shown in the sample code.

  This way, it does *not* use the kernel driver that comes with the
  Linux kernel. (The companion task, :doc:`task-lm73-hwmon`, *does*
  use the driver.)
* Document all that

Further Information
-------------------

* Topic: :doc:`/trainings/material/soup/linux/hardware/i2c/topic`
* :download:`Datasheet <lm73.pdf>`
* `TI product page <https://www.ti.com/product/LM73>`__

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_lm73_dev
