.. include:: <mmlalias.txt>

.. ot-task:: fh2021.datalogger_integration
   :dependencies: fh2021.datalogger,
		  fh2021.datalogger_mqtt_sink,
		  fh2021.datalogger_csv_sink


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
  :doc:`/trainings/material/soup/cxx-design-patterns/composite/composite`)
  of

  * :doc:`datalogger-csv-sink`
  * :doc:`datalogger-mqtt-sink`

Dependencies
------------

.. ot-graph::
   :entries: fh2021.datalogger
