.. ot-task:: ec2.mqtt.task_prog_publish
   :dependencies: ec2.sensors.task_prog_stdout

Program: Read Sensors, Publish to MQTT Topic
============================================

.. contents:: 
   :local:

Description
-----------

Relation to :doc:`../sensors/task-prog-stdout`
..............................................

This is not going to be much different from
:doc:`../sensors/task-prog-stdout`. Please read that task description
first to see what they are up to.

In short, what :doc:`../sensors/task-prog-stdout` does is:

* Read values from a **list of thermometers**, at a given *interval**
* Write those values to *standard output* as they are available

The difference between this MQTT task and
:doc:`../sensors/task-prog-stdout` is that, rather than writing the
values to *standard output*, the values are *published* to their
respective MQTT topics.

JSON
....

JSON (`documentation <https://docs.python.org/3/library/json.html>`__)
is a popular data format on The Internet, especially when using
brokers like MQTT.

Please define a suitable JSON structure for the ``(timestamp,
temperature)`` tuples that are being transferred. Straightforward
would be a dictionary (err, this is a *map* in Javascript; Javascript
data structures are very similar to Python's) like so,

.. code-block:: javascript

   {
      "timestamp": 1635502701.9270382,
      "temperature": -273.15
   }

Collaboration With Colleagues
.............................

**Configuration file formats**

:doc:`../sensors/task-prog-stdout` defines two configuration file
formats. You are going to use those when they are ready, and
incorporate it in to your program.

You sure don't want to wait until these formats are fully implemented
and tested, so what you need is a temporary solution - your primary
task is MQTT after all.

Solution to this problem:

* Hardcode the thermometer list in the meantime
* Wait for a notification from the :doc:`../sensors/task-prog-stdout`
  team that they are done with config
* Implement commandline parsing (``argparse``, see there) and config
  file usage.

Final State
...........

(Taken from :doc:`../sensors/task-prog-stdout`, replaced
``read-thermometers`` with ``publish-thermometers``.)

.. code-block:: console

   $ ./bin/publish-thermometers --conf-ini some-config.ini
   ...

Call the program, feeding configuration from a Python config file:

.. code-block:: console

   $ ./bin/publish-thermometers --conf-exec some-config.py
   ...

Further Information
-------------------

* See :doc:`here </trainings/material/soup/python/misc/mqtt/topic>`
  for more informtion about MQTT, and how to use it in Python.

Dependencies
------------

.. ot-graph::
   :entries: ec2.mqtt.task_prog_publish

.. rubric:: Footnotes

