.. ot-task:: ec2.sensors.task_simu
   :dependencies: ec2.sensors.task_sensor_iface
   :percent-done: 0

Simulated/Dummy Thermometers
============================

.. contents::
   :local:

Description
-----------

Write a Number of Simulated Thermometers
........................................
  
**Why?**
  
* Cool to have when I'm on a train and don't have hardware around.
* Cool to have when I want to unit-test my code.
  
**Which?**

* One that reads the temperature from a file (that `exists already
  <https://github.com/jfasch/FH-ECE-19/blob/master/src/ece19/sensors/file_thermometer.py>`__)
* One that generates a sine (its samples can be given to a Fourier
  analysis). ``Thermometer_Sine``
* One that spits out random numbers in a range
  (``random.randrange()``). ``Thermometer_Random``.
* One that gives a constant temperature. ``Thermometer_Constant``.

Unit Testing Tools: Simulating the Timeline
...........................................

The :doc:`thermometer interface <task-sensor-iface>` 's main method
``get_temperature()`` returns a tuple ``(timestamp, celsius)``.

During unit testing (we don't yet know what that is), we don't want to
run a test that reads temperatures every second in a loop, for
example, only to check that what is returned is a sine wave. *This
would take too long*, and nobody would have enough patience to run the
unit tests.

**We want to simulate time**. ``Thermometer_Sine``,
``Thermometer_Random``, ``Thermometer_Constant`` should be given that
optional functionality to return timestamps from a given input
sequence, rather than the real time.

Based upon a `simple sketch in our project
<https://github.com/jfasch/FH-ECE-19/blob/master/tests/timeline-example.py>`__,
and an :doc:`attempt to explain all this
</trainings/material/soup/python/python_1010_generators_yield/topic>`,
all simulated thermometer implementation should have an optional
constructor parameter (call it, say, ``timeline``, uniformly) that can
be used by unit tests.
  
Write a Simple Program
......................

Write a simple program to verify that those thermometers work ok. We
cannot use :doc:`task-prog-stdout` for this because that task is
running in parallel and might not have started altogether.

Integration
-----------

Communicate to your users how your thermometers are used, and how to
instantiate them. Especially, :doc:`task-prog-stdout` is in charge of
implementing two alternative config file syntaxes where they need to
know how all thermometers are instantiated.

From the :doc:`plan <../group-ec2>`, we can pinpoint that
:doc:`../mqtt/task-prog-mqtt` depends on :doc:`task-prog-stdout`. The
reason is that they will have to pick up the config file from the
latter task. Before the config files are fully implemented, they too
will want to use your thermometers.

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_simu
