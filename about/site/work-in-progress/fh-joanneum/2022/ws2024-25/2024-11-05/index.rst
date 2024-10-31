.. include:: <mmlalias.txt>


2024-11-05(6): Project, Sysprog Recap
=====================================

.. contents::
   :local:

Org
---

* Clarify licensing status

  * used training material (faschingbauer.me) is GPL3
  * also on faschingbauer.me: project management, design docs, thereby
    *that* material is also under GPL3
  * No specific license: https://github.com/jfasch/FH-STECE2022 (this
    year's EC2 project) and https://github.com/jfasch/FH-ENDLESS (my
    contributions to it)

    Which license to pick? -> https://choosealicense.com/

* Define hardware (task group) owner

Material
--------

* Recap ``class point``. Emphasize on ``const``, and initialization

Project
-------

* :ref:`fh-2022--2024-10-29-homework`
* Software implications: aggregating objects into instances of higher
  level types

    * Show :doc:`../project/sysfs-pwm`
    * :doc:`../project/servo-motor`, which aggregates a :doc:`../project/sysfs-pwm`
    * :doc:`../project/motor-control-btn9960lv`, which aggregates one
      or two :doc:`../project/sysfs-pwm`

* :doc:`../project/motor-control-btn9960lv`

  * How's it with hardware? Do we need 2 PWMs, or just one?

    * Ask for permission of car layout docs -> put it in repo

  * How's it with software? Write test together.

* :doc:`../project/servo-motor`

  * How's it with software? Write test together.

* :doc:`../project/proximity-vl53l1x`: talk about usage sketch of
  ``class VL53L1X``
* :doc:`../project/gyroscope-bno055`: talk about usage sketch of
  ``class BNO055``
