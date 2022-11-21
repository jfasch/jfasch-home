Exercise: OneWire Sensor Class
==============================

.. contents:
   :local:

Download Monolithic Sensor Implementation
-----------------------------------------

To your project, as a subdirectory of the toplevel
directory, add a directory ``bin-trainee/``, and register
it with your top-level ``CMakeLists.txt``.

Add `onewire-temperature.cpp
<https://github.com/jfasch/FH-ECE20-patterns/blob/main/bin-trainer/onewire-temperature.cpp>`__
to that directory (and its ``CMakeLists.txt``, of course)

Test Monolithic Implementation
------------------------------

* Setup toolchain (if not yet done): :doc:`toolchain-setup`
* Build as described in
  :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`
* Transfer to Raspberry (my build directory is
  ``/tmp/FH-ECE20-patterns-pi``)

  .. code-block:: console

     $ scp -P 2020 /tmp/FH-ECE20-patterns-pi/bin-trainee/onewire-temperature firstname.lastname.faschingbauer@jfasch.bounceme.net:

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

.. literalinclude:: w1-sensor-suite.cpp
   :caption: :download:`w1-sensor-suite.cpp`
   :language:c++

Refactoring
-----------

* Using ``class W1Sensor`` from ``<sensor-w1.h>``, modify
  ``onewire-temperature.cpp`` to use that class.
* **Goal**: ``onewire-temperature.cpp`` must not use any of file
  operations ``open()``, ``read()`` and ``close()`` to read the sensor
  file. All that is done by ``W1Sensor``.

**Testing**

* When done, test it one the Pi like above
