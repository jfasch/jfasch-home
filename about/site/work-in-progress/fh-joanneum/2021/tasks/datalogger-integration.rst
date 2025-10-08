.. include:: <mmlalias.txt>


Data Logger: Integration
========================

.. contents::
   :local:

Requirements
------------

Integrate :doc:`datalogger` with the real world

* Sensors

  * Re-use sensor from :doc:`boiling-pot-basic-integration`
  * Possibly add a number of built-in CPU sensors, just for fun

* Sinks. A composite (see
  :doc:`/trainings/material/soup/cxx/cxx-design-patterns/composite/index`)
  of

  * :doc:`datalogger-csv-sink`
  * :doc:`datalogger-mqtt-sink`
