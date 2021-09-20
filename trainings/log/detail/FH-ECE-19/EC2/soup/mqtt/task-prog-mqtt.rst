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

* Takes from a configuration file [#winini]_

  * The set of thermometers. Each thermometer has

    * Name
    * Type (be it a LM73, DS18S20, or one of the simulated
      thermometers)
    * MQTT parameters
      
      * Hostname and port number of broker
      * Topic to publish values to

  * The temperature read interval

* As configured, publishes sensors values (as JSON formatted
  structures/dictionaries) to their respective MQTT topics.

  .. code-block:: console

     $ ./publish-thermometers --config-file /etc/thermometers.conf

.. rubric:: Footnotes

.. [#winini] The ``configparser`` module from the Python standard
             library is a straightforward choice; see `here
             <https://docs.python.org/3/library/configparser.html>`__.

Dependencies
------------

.. ot-graph::
   :entries: ec2.mqtt.task_prog_publish
