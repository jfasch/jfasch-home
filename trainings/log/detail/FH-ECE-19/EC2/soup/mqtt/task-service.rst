.. ot-task:: ec2.mqtt.task_service
   :dependencies: ec2.mqtt.task_prog_publish,
		  ec2.devenv.systemd

Automatic Start: ``systemd`` Service
====================================

.. contents::
   :local:

Description
-----------

* Turn the :doc:`standalone publisher program <task-prog-mqtt>` into a
  ``systemd`` service program. Better yet, add a commandline argument
  that makes the program behave like a ``systemd`` service.

  The service will be of type ``notify`` (its unit file contains
  ``Type=notify``) - this means that the program must explicitly
  notify ``systemd`` that they have successfully finished startup an
  are ready for use.

* Write a unit file.

Dependencies
------------

.. ot-graph::
   :entries: ec2.mqtt.task_service
