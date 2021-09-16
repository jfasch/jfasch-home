.. jf-task:: ec.ec2.task_sensors
   :dependencies: ec.ec2.sphinx_intro, 
		  ec.ec2.virtualbox,
		  ec.ec2.task_sensor_iface

Hardware Temperature Sensors (Core Classes)
===========================================

.. contents::
   :local:

Deliverables
------------

A set of Python classes for temperature sensors, implementing the
``Thermometer`` :doc:`interface <task-sensor-iface>`.

* DS18S20 (Onewire) 

  * :download:`Datasheet <DS18S20.pdf>`
  * `Onewire filesystem
    <https://www.kernel.org/doc/html/latest/w1/index.html>`__

* LM73 (I2C) 

  * `TI product page <https://www.ti.com/product/LM73>`__
  * :download:`Datasheet <lm73.pdf>`
  * LM73 via userspace I2C (`here
    <https://www.kernel.org/doc/Documentation/i2c/dev-interface>`__)

.. note:: 

   Both sensors are well-supported by Linux; their drivers support the
   ``hwmon`` driver interface (`here
   <https://www.kernel.org/doc/Documentation/hwmon/sysfs-interface>`__)

* Documentation

  * Docstrings in Python code (see `here
    <https://docs.python.org/3/library/pydoc.html>`__).
  * Hardware setup. For example, LM73 is an i2c device and wants to be
    announced.
  * Kernel configuration: ``/etc/modules-load.d/``

Dependencies
------------

.. jf-topicgraph::
   :entries: ec.ec2.task_sensors
