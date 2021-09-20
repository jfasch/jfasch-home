.. ot-task:: ec2.sensors.task_sensor_iface

Thermometer Interface Definition
================================

.. contents::
   :local:

Description
-----------

* Define a temperature sensor (thermometer) interface to be used
  throughout the project, roughly as follows.

  .. code-block:: python
  
     class Thermometer:
         def get_temperature(self):
             celsius = ... # read temperature
	     timestamp = time.time()
	     return (timestamp, celsius)

* Write a number of simulated thermometers 

  Why?

  * Cool to have when I'm on a train and don't have hardware around.
  * Cool to have when I want to unit-test my code.

  Which?

  * One that generates a sine (its samples can be given to a 
    Fourier analysis)
  * One that spits out random numbers in a range
  * One that gives a constant temperature

* Write a simple program that instantiates all of those, and outputs
  measurement values to *standard output*.

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_sensor_iface
