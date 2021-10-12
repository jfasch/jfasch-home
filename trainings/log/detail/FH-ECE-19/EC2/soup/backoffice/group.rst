.. ot-group:: ec2.backoffice

MQTT "Backoffice" Applications (MQTT *Subscribers*)
===================================================

A number of sample applications in the "backoffice" that receive
information from the IoT crap, via :doc:`MQTT <../mqtt/group>`.

.. contents::
   :local:

Tasks
-----

.. toctree::
   :maxdepth: 1

   task-pid-controller
   task-hysteresis

Dependencies
------------

.. ot-graph::
   :entries: ec2.sensors
