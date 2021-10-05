.. ot-task:: ec2.sensors.task_sensors
   :dependencies: ec2.devenv.sphinx_intro, 
		  ec2.devenv.virtualbox,
		  ec2.sensors.task_sensor_iface,
		  ec2.devenv.hwdoc

Hardware Temperature Sensors (Core Classes)
===========================================

.. contents::
   :local:

Description
-----------

A set of Python classes for temperature sensors, implementing the
``Thermometer`` :doc:`interface <task-sensor-iface>`.

* DS18S20 (Onewire) 

  * :doc:`/trainings/material/soup/linux/hardware/w1/topic`
  * :download:`Datasheet <DS18S20.pdf>`
  * `Onewire filesystem
    <https://www.kernel.org/doc/html/latest/w1/index.html>`__

* LM73 (I2C) 

  * :doc:`/trainings/material/soup/linux/hardware/i2c/topic`
  * :download:`Datasheet <lm73.pdf>`
  * `TI product page <https://www.ti.com/product/LM73>`__

* Possibly other sensors? Some from the Arduino starter kit?

.. note:: 

   DS18S20 and LM73 sensors are well-supported by Linux; their drivers
   support the ``hwmon`` driver interface (`here
   <https://www.kernel.org/doc/Documentation/hwmon/sysfs-interface>`__)

* Documentation

  * Docstrings in Python code (see `here
    <https://docs.python.org/3/library/pydoc.html>`__).
  * Hardware setup. For example, LM73 is an i2c device and wants to be
    announced.
  * Kernel configuration: ``/etc/modules-load.d/``

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_sensors
