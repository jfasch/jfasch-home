.. include:: <mmlalias.txt>


2024-05-27(6): Cross Development, Toolchain Installation
========================================================

.. contents::
   :local:

Cross Development
-----------------

* :doc:`/trainings/material/soup/linux/toolchain/cross/basics`
* :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`
* :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`

Exercise: Install Cross Toolchain 
---------------------------------

* Setup cross toolchain as in
  :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
* Download CMake toolchain file as in
  :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
* Build the project from the last exercise,
  :doc:`../2024-05-06/exercise`

C++ Intro: Livecoding Session
-----------------------------

See
https://github.com/jfasch/FH-STECE2022/tree/main/livecoding/sensor-oo-c
for code.

* Morphing :doc:`../2024-05-06/exercise` into something
  object-oriented, but still C
* Introduce exception handling; this is done to overcome the weird
  function signature of ``sensor_get_temperature()``.

  * Causing exceptions (``throw``):
    https://github.com/jfasch/FH-STECE2022/blob/main/livecoding/sensor-oo-c/lib/sensor.cpp
  * Reacting upon exceptions (``try``, and ``catch``)

    * Production code:
      https://github.com/jfasch/FH-STECE2022/blob/main/livecoding/sensor-oo-c/bin/read-sensor.cpp
    * Test code (attention, the logic seems somehow inverted):
      https://github.com/jfasch/FH-STECE2022/blob/main/livecoding/sensor-oo-c/tests/suite-sensor.cpp

User's View
...........

* :doc:`/trainings/material/soup/cxx03/900-standard-library-miscellanea/string/topic`

Exercise: Parse Lines From ``/etc/passwd``
------------------------------------------

* Moodle submission: 
* Exercise definition:
  :doc:`/trainings/material/soup/cxx03/exercises-misc/passwd-parser/exercise`
