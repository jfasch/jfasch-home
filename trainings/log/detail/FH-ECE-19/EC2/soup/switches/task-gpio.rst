.. ot-task:: ec2.switches.task_gpio
   :dependencies: ec2.devenv.sphinx_intro, 
		  ec2.switches.task_switch_iface

GPIO Switch
===========

.. contents::
   :local:

Description
-----------

At the end of last semester, we wrote :doc:`a program that let an LED
blink <../../../EC1/Exercises/blinklicht>`. It is that code that
should make its way into a dedicated class that implements the
:doc:`switch interface <task-switch-iface>` - a class that uses the
``sysfs`` GPIO interface to implement switch functionality.


Further Information
-------------------

* See :doc:`../../../EC1/Exercises/blinklicht` for details.

Dependencies
------------

.. ot-graph::
   :entries: ec2.switches.task_gpio
