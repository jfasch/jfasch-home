.. ot-task:: ec2.backoffice.task_pid_controller
   :dependencies: ec2.mqtt.task_prog_publish,
		  ec2.sensors.task_simu,
		  ec2.switches.task_simu

MQTT PID Controller
===================

.. contents::
   :local:

Description
-----------

Implement a PID controller class. The temperature measurements are
received from a subscription of an MQTT topic.

Dependencies
------------

.. ot-graph::
   :entries: ec2.backoffice.task_pid_controller
