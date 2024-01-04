.. include:: <mmlalias.txt>

.. ot-task:: fh2021.boiling_pot_basic_integration
   :dependencies: fh2021.sysfs_gpio_switch,
		  fh2021.sensor_w1,
		  fh2021.boiling_pot		  



Boiling Pot: Basic Integration
==============================

.. contents::
   :local:

Standup Records
---------------

2023-12-14
..........

* Sensor as described in
  :doc:`/trainings/material/soup/linux/hardware/w1/topic`
* Someone from :doc:`sysfs-gpio-switch` to help out.

Requirements
------------

* Breadboard acrobatics

  * LED, as from :doc:`sysfs-gpio-switch`
  * :doc:`/trainings/material/soup/linux/hardware/w1/topic`

* "Firmware". `boiling-pot.cpp
  <https://github.com/jfasch/FH-ECE21/blob/main/firmware/boiling-pot.cpp>`__
  should be sufficient. Make changes as appropriate.

Dependencies
------------

.. ot-graph::
   :entries: fh2021.boiling_pot, fh2021.sysfs_gpio_switch
