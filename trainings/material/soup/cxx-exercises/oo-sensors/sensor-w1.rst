.. ot-exercise:: cxx.exercises.oo_sensors.sensor_w1
   :dependencies: cxx.exercises.oo_sensors.sensor_interface,
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

To your project, as a subdirectory of the toplevel directory, add a
directory ``bin-trainee/``, and register it with your top-level
``CMakeLists.txt``.

Add :download:`onewire-temperature-monolithic.cpp
</trainings/material/soup/cxx-code/oo-sensor-w1/bin/onewire-temperature-monolithic.cpp>`
to that directory (and its ``CMakeLists.txt``, of course)

Test Monolithic Implementation
------------------------------

* Setup toolchain (if not yet done):
  :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
* Build as described in
  :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`

  In short (please supply the paths from your situation),

  .. code-block:: console

     $ mkdir /tmp/FH-ECE20-patterns-pi/        # <--- create build directory
     $ cd /tmp/FH-ECE20-patterns-pi/           # <--- cd into it
     $ cmake -DCMAKE_TOOLCHAIN_FILE=/home/jfasch/armv8-rpi4-linux-gnueabihf.cmake ~/work/FH-ECE20-patterns/
     ... roedel ...
     $ make

* Transfer to Raspberry (my build directory is
  ``/tmp/FH-ECE20-patterns-pi``, your is likely different)

  .. code-block:: console

     $ scp -P 2020 /tmp/FH-ECE20-patterns-pi/bin-trainee/onewire-temperature firstname.lastname@jfasch.bounceme.net:

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

* Add the following test to the test suite in ``tests-trainee/``
* To make it run, create a pair of files
  ``libtrainee/sensor-w1.{h,cpp}``

.. note::

   The sensor implementation is in no way tied to the Raspberry. All
   it does is read a file, and that can be done on the development
   machine (a PC likely) just as well.

.. literalinclude:: /trainings/material/soup/cxx-code/oo-sensor-w1/tests/sensor-w1-suite.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-sensor-w1/tests/sensor-w1-suite.cpp`
   :language: c++

Refactoring
-----------

* Using ``class W1Sensor`` from ``<sensor-w1.h>``, modify
  ``onewire-temperature.cpp`` to use that class.
* **Goal**: ``onewire-temperature.cpp`` must not use any of file
  operations ``open()``, ``read()`` and ``close()`` to read the sensor
  file. All that is done by ``W1Sensor``.

**Testing**

* When done, test it on the Pi like above
