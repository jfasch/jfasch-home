.. ot-exercise:: cxx.exercises.sensor_w1
   :dependencies: cxx.exercises.sensor_interface,
		  linux.sysprog.fileio.exercise_w1_sensor

Exercise: OneWire Sensor Class
==============================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/sysprog/file-io/exercise-sensor-read`

Download Monolithic Sensor Implementation
-----------------------------------------

* Download :download:`onewire-temperature-monolithic.cpp
  </trainings/material/soup/cxx-exercises/sensor-w1/code/bin/onewire-temperature-monolithic.cpp>`
  to your *programs* directory
* Add it to ``CMakeLists.txt``

Test Monolithic Implementation
------------------------------

* Setup toolchain (if not yet done):
  :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
* Build as described in
  :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`

  In short (please supply the paths from your situation -
  ``/tmp/build`` and ``~/source`` are only placeholders),

  .. code-block:: console

     $ mkdir /tmp/build/                       # <--- create build directory
     $ cd /tmp/build/                          # <--- cd into it
     $ cmake -DCMAKE_TOOLCHAIN_FILE=/home/jfasch/armv8-rpi4-linux-gnueabihf.cmake ~/source/
     ... roedel ...
     $ make

* Transfer to Raspberry,

  .. code-block:: console

     $ scp -P 2020 /tmp/build/path/to/your/programs/onewire-temperature firstname.lastname@jfasch.bounceme.net:

* Test it

  .. code-block:: console

     $ ssh -p 2020 firstname.lastname@jfasch.bounceme.net ./onewire-temperature
     ./onewire-temperature <filename> <interval>

     $ ssh -p 2020 firstname.lastname@jfasch.bounceme.net ./onewire-temperature /sys/bus/w1/devices/28-02131d959eaa/temperature 1
     20687
     20687
     ...

``class W1Sensor``
------------------

* Add the following test to your test suite (i.e., register it a
  another source file in ``CMakeLists.txt``)
* To make it run, create a pair of files (``sensor-w1.{h,cpp}``) in
  your library directory (again, ``CMakeLists.txt``)
* Fix test failures until green

.. note::

   The sensor implementation is in no way tied to the Raspberry. All
   it does is read a file, and that can be done on the development
   machine (a PC likely) just as well.

.. literalinclude:: /trainings/material/soup/cxx-exercises/sensor-w1/code/tests/sensor-w1-suite.cpp
   :caption: :download:`sensor-w1-suite.cpp
             </trainings/material/soup/cxx-exercises/sensor-w1/code/tests/sensor-w1-suite.cpp>`
   :language: c++

Refactoring
-----------

Modify ``onewire-temperature.cpp`` to not use any file
operations. Rather, ``#include <sensor-w1.h>`` and use that instead.

**Testing**

* When done, test it on the Pi like above
