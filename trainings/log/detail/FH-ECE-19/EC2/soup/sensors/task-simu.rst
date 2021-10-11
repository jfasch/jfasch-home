.. ot-task:: ec2.sensors.task_simu
   :dependencies: ec2.sensors.task_sensor_iface
   :percent-done: 0

Simulated/Dummy Thermometers
============================

.. contents::
   :local:

Description
-----------

.. list-table::
   :align: left

   * * Write a number of simulated thermometers 
  
       Why?
  
       * Cool to have when I'm on a train and don't have hardware
         around.
       * Cool to have when I want to unit-test my code.
  
       Which?

       * One that reads the temperature from a file
       * One that generates a sine (its samples can be given to a
         Fourier analysis)
       * One that spits out random numbers in a range
       * One that gives a constant temperature

     *
  
   * * Write a simple program that 

       * Instantiates all of those
       * Outputs measurement values to *standard output* in a loop, at
         a fixed interval

     * 

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors.task_simu
