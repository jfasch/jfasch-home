.. ot-task:: ec2.switches.task_simu
   :dependencies: ec2.switches.task_switch_iface
   :percent-done: 0

Simulated/Dummy Switch
======================

.. contents::
   :local:

Description
-----------

.. list-table::
   :align: left

   * * Write a switch that is implemented in software
  
       Why?
  
       * Cool to have when I'm on a train and don't have hardware
         around.
       * Cool to have when I want to unit-test my code.
  
       How?

       * Switch object of this type, rather than operating hardware IO
         pins, simply have a ``bool`` member that is set
         (``set_state()``) and returned (``get_state()``) accordingly.


Dependencies
------------

.. ot-graph::
   :entries: ec2.switches.task_simu
