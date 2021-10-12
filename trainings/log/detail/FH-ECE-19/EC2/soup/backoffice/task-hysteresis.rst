.. ot-task:: ec2.backoffice.task_hysteresis
   :dependencies: ec2.mqtt.task_prog_publish,
		  ec2.sensors.task_simu,
		  ec2.switches.task_simu

MQTT Hysteresis
===============

.. contents::
   :local:

Description
-----------

Implement a hysteresis class. The temperature measurements are
received from a subscription of an MQTT topic.

Instantiation parameters are:

* Lower bound
* Callback if temperature falls below lower bound 
* Upper bound
* Callback if temperature rises above upper bound

Further Information
-------------------

* `Wikipedia <https://en.wikipedia.org/wiki/Hysteresis>`__

Dependencies
------------

.. ot-graph::
   :entries: ec2.backoffice.task_hysteresis
