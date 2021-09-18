.. ot-topic:: ecproposal.ec1.linux.exercise_sensors
   :dependencies: ecproposal.ec1.linux.dev_mgmt, 
		  ecproposal.ec1.cxx.iface,
		  ecproposal.ec1.cxx.build,
		  ecproposal.ec1.git

EX: Temperature Sensors
=======================

.. contents::
   :local:

Goals
-----

Combine programming skills with OS/hardware knowledge.

* Learn how to interact with hardware on Linux
* Learn how to design and use software interfaces

Hardware
--------

A number of different temperature sensors.

* DS18S20 (Onewire) (:download:`Datasheet <DS18S20.pdf>`)
* `LM73 (I2C) <https://www.ti.com/product/LM73>` (:download:`Datasheet
  <lm73.pdf>`)

Outcome
-------

* A set of C++ classes implementing an ad-hoc ``Thermometer``
  interface

  * DS18S20 via Onewire filesystem (`here
    <https://www.kernel.org/doc/html/latest/w1/index.html>`__)
  * LM73 via userspace I2C (`here
    <https://www.kernel.org/doc/Documentation/i2c/dev-interface>`__)
  * Both DS18S20 and LM73 via the ``hwmon`` driver interface (`here
    <https://www.kernel.org/doc/Documentation/hwmon/sysfs-interface>`__)

* Code to read a JSON sensor configuration file

  * Using an external library, possibly `this one
    <https://github.com/nlohmann/json>`__
  * See how hard that is with C/C++

* A program or two to

  * Read out sensors, and output reports of different sorts
  * Calculate averages
  * Possibly see how `SQLite3
    <https://www.sqlite.org/capi3ref.html>`__ goes. I'd rather not do
    this but save the time for an easier Python experience.
