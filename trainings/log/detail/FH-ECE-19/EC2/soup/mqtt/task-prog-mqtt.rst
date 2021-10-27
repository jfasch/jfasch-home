.. ot-task:: ec2.mqtt.task_prog_publish
   :dependencies: ec2.sensors.task_prog_stdout

Program: Read Sensors, Publish to MQTT Topic
============================================

Conceptually, this is like :doc:`../sensors/task-prog-stdout`: a
program that reads sensor values in a given interval. Rather than
writing the values to ``stdout``, we *publish* those to respective
MQTT *topics*.

See :doc:`here </trainings/material/soup/python/draft/mqtt/topic>` for
more informtion about MQTT, and how to use it in Python.

.. contents::
   :local:

Description
-----------

A program that periodically reads temperatures from a given set of
thermometers. That program has the following characteristics.

* Uses the configuration file from :doc:`../sensors/task-prog-stdout`
  to define the set of sensors to use.
* As configured, publishes sensors values (as JSON formatted
  structures/dictionaries) to their respective MQTT topics.

  .. code-block:: console

     $ ./publish-thermometers --config-file /etc/thermometers.conf

Further Information
-------------------

* :doc:`/trainings/material/soup/python/draft/mqtt/topic`

Dependencies
------------

.. ot-graph::
   :entries: ec2.mqtt.task_prog_publish

.. rubric:: Footnotes

