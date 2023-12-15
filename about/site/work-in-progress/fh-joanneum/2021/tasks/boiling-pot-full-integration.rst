.. include:: <mmlalias.txt>

.. ot-task:: fh2021.boiling_pot_full_integration
   :dependencies: fh2021.boiling_pot_basic_integration,
		  fh2021.boiling_pot_display,
		  fh2021.display_infrastructure,
		  fh2021.datalogger_mqtt_sink


Boiling Pot: Full Integration (Display And IoT)
===============================================

.. contents::
   :local:

Standup Records
---------------

Requirements
------------

* Breadboard acrobatics from :doc:`boiling-pot-basic-integration`
* More breadboard acrobatics taken from :doc:`display-infrastructure`
* "Firmware"

  * Create a copy of `firmware/boiling-pot.cpp
    <https://github.com/jfasch/FH-ECE21/blob/main/firmware/boiling-pot.cpp>`__
  * Use a composite display (as described in
    :doc:`display-infrastructure`), composed of one PWM and one LEd
    stripe
  * Use a MQTT reporter

Dependencies
------------

.. ot-graph::
   :entries: fh2021.boiling_pot, fh2021.sysfs_gpio_switch
