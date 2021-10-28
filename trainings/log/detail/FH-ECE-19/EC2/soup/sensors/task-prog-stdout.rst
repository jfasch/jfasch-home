.. ot-task:: ec2.sensors.task_prog_stdout
   :dependencies: ec2.sensors.task_simu


Program: Read Sensors, Write to ``stdout``
==========================================

.. contents::
   :local:

Description
-----------

Write a program that periodically reads temperatures from a given set
of thermometers. The set of thermometers is read from a configuration
file.

Currently (as of 2021-10-28), the program looks like follows:

..  code-block:: python

    #!/usr/bin/env python
    
    from ece19.sensors.file_thermometer import FileThermometer
    import time
    
    
    thermometers = [
        FileThermometer('/tmp/thermometer1', name='FileThermometer1'),
        FileThermometer('/tmp/thermometer2', name='FileThermometer2'),
        # thermometer = LM73Thermometer(1, 0x49, name='LM73')
    ]    
    interval = 0.5
    
    while True:
        for th in thermometers:
            timestamp, temperature = th.get_temperature()
            print(timestamp, temperature)
        time.sleep(interval)

The functionality of the program is clear: given a list of
thermometers and an interval, it does that one simple thing: output
all sensor values infinitely at that interval, to *standard output*
[#pipe]_. Like so:

.. code-block:: console

   $ ./bin/read-thermometers
   FileThermometer1 1635446701.3454807 42.7
   FileThermometer2 1635446701.3455074 -273.5
   FileThermometer1 1635446701.8460739 42.7
   FileThermometer2 1635446701.84612 -273.5

The complexity of the task is that nobody likes those hardcoded
variables ``thermometers`` and ``interval``. We want to feed these
parameters into the program via a configuration file.

Lets implement two different configuration file formats in a way that
makes them available to other people as well (for example, the task
:doc:`../mqtt/task-prog-mqtt` will happily use it):

* One that uses the ``configparser`` module from the Python standard
  library (`documentation
  <https://docs.python.org/3/library/configparser.html>`__) to define
  a Windows ``.ini`` style format. Put it in, say,
  ``ece19/configs/sensors_ini.py``.
* One that is not a special configuration file syntax in itself, but
  rather uses the Python ``exec()`` function. See
  :doc:`/trainings/material/soup/python/swdev/exec/topic` for an
  explanation. Put it in, say, ``ece19/configs/sensors_exec.py``.

Call the program, feeding configuration from a ``.ini`` file:

.. code-block:: console

   $ ./bin/read-thermometers --conf-ini some-config.ini
   ...

Call the program, feeding configuration from a Python config file:

.. code-block:: console

   $ ./bin/read-thermometers --conf-exec some-config.py
   ...

.. note::

   To parse this ``--conf-ini`` and ``--conf-exec`` commandline, you
   use the ``argparse`` module from the Python standard
   library. Documentation `here
   <https://docs.python.org/3/library/argparse.html>`__.

.. rubric:: Footnotes

.. [#pipe] The program is designed to be part of a larger pipeline.

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_prog_stdout
