.. ot-task:: ec2.sensors.task_prog_stdout
   :dependencies: ec2.sensors.task_simu,
		  ec2.sensors.task_arduino_proxy,
		  ec2.sensors.task_lm73_dev,
		  ec2.sensors.task_ds18s20,
		  ec2.sensors.task_lm73_hwmon


Program: Read Sensors, Write to ``stdout``
==========================================

.. contents::
   :local:

Description
-----------

Write a program that periodically reads temperatures from a given set
of thermometers. The set of thermometers is read from a configuration
file.

Currently (as of 2021-10-28), the program looks like follows (`here on
Github
<https://github.com/jfasch/FH-ECE-19/blob/master/bin/read-thermometers>`__):

..  code-block:: python
    :caption: ``read-thermometers``

    #!/usr/bin/env python
    
    from ece19.sensors.file_thermometer import FileThermometer
    import time
    
    
    thermometers = [
        FileThermometer('/tmp/thermometer1', name='FileThermometer1'),
        FileThermometer('/tmp/thermometer2', name='FileThermometer2'),
        # LM73Thermometer(1, 0x49, name='LM73')
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
  :doc:`/trainings/material/soup/python/advanced/exec/topic` for an
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

Integration
-----------

Downwards: Thermometer Constructors
...................................

This task's prinmary outcome are two alternative configuration file
parsers whose main difficulty is to *instantiate* all available
thermometers. See the dependent tasks below (those which this task
*depends on*) for which thermometers are available.

The *integrator's job*, in this regard, is to

* communicate with those task's teams to check what's available
* communicate to your own task's development department what need to
  be implemented
* communicate to your own task's documentation department what the
  users of your task's outcome (config and stdout-program) need to
  know
* continuously check if all is right: test it

Upwards: MQTT Publisher
.......................

:doc:`../mqtt/task-prog-mqtt` heavily depends on your config file
implementation. It's not like this is a "I can only start when they
are finished!" relationship - their main outcome is publishing sensor
values to MQTT, and they have :doc:`simulation sensors <task-simu>`
that they can hardcode to start with.

They will have to use your configs once they start to claim "We're
done!".

The *integrator's job*, in this regard, is to

* communicate to them what is available, and how (you need to push
  your documentation department for this)
* periodically sit together with them once they start integrating with
  you

.. rubric:: Footnotes

.. [#pipe] The program is designed to be part of a larger pipeline.

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_prog_stdout
