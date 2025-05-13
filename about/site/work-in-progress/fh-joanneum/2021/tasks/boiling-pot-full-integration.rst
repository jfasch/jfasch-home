.. include:: <mmlalias.txt>


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
