.. ot-task:: ec2.sensors.task_lm73_hwmon
   :dependencies: ec2.devenv.sphinx_intro, 
		  ec2.sensors.task_sensor_iface,
		  ec2.devenv.hwdoc

Temperature Sensor: LM73 (via ``hwmon``)
========================================

.. contents::
   :local:

Description
-----------

* Write a Python class that implements the ``Thermometer``
  :doc:`interface <task-sensor-iface>`, and sits on top of the `LM73
  <https://www.ti.com/product/LM73>`__ temperature sensor.
* Integration: the thermometer class (call it
  ``ThermometerLM73_hwmon``) uses the decadent Linux driver
  infrastructure: the LM73 driver that comes with Linux implements the
  ``hwmon`` (for *Hardware Monitoring*) interface. Reading
  temperatures from sensors is as easy as reading the content of a
  file, for example ``/sys/class/hwmon/hwmon1/temp1_input``. See
  :doc:`/trainings/material/soup/linux/hardware/i2c/topic` for
  details.
* Document all that

Complication: Build a Custom Kernel
...................................

Unfortunately, Raspberry Pi OS does not package the LM73 driver, which
complicates the task: we have to build our own kernel. See
:doc:`/trainings/material/soup/linux/hardware/i2c/topic` for more.

Integration
-----------

* Once your thermometer is in a shape to be used, notify your users
  (:doc:`task-prog-stdout` depends on you) how this is done.
* Help them integrate your thermometer
* Before, push your documentation department to do their job, or else
  you will have to explain all that repeatedly

Further Information
-------------------

* Topic: :doc:`/trainings/material/soup/linux/hardware/i2c/topic`
* :download:`Datasheet <lm73.pdf>`
* `TI product page <https://www.ti.com/product/LM73>`__

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_lm73_hwmon
