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

Unit Testing Tools
..................

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

Check out
:doc:`/trainings/material/soup/python/iteration-generation/topic`;
generators provide a way to generate infinte sequences of timestamps.
  
Write a Simple Program
......................

Write a simple program to verify that those thermometers work ok. We
cannot use :doc:`task-prog-stdout` for this because that task is
running in parallel and might not have started altogether.

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_simu
