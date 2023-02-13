.. ot-exercise:: cxx.exercises.oo_sensors.sensor_w1_factory
   :dependencies: cxx.exercises.oo_sensors.sensor_w1

.. include:: <mmlalias.txt>


Exercise: OneWire Sensor Factory
================================

.. contents::
   :local:

Problem
-------

* On Linux, Onewire device addresses are mapped to aptly named
  directories - e.g. ``/sys/bus/w1/devices/28-02131d959eaa``
* ``W1Sensor`` reads from a ``sysfs`` file,
  e.g. ``/sys/bus/w1/devices/28-02131d959eaa/temperature``, just like

  .. code-block:: console
  
     $ cat /sys/bus/w1/devices/28-02131d959eaa/temperature 
     23062

  or, in C++,

  .. code-block:: c++

     W1Sensor sensor("/sys/bus/w1/devices/28-02131d959eaa/temperature");
     std::cout << sensor.get_temperature() << std::endl;

* A hypothetical system (a heating control, for example) configuration
  does not want to mention *file system paths* like that

  * Highly OS dependent
  * Humans who configure systems might not be Linux experts

* *Device addresses* are well understood

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/900-standard-library-miscellanea/string/topic`
   * :doc:`/trainings/material/soup/cxx11/filesystem/topic`

* |longrightarrow| need something that ...

  * Searches the Onewire tree (``/sys/bus/w1``) for a device directory
    that looks something like ``devices/*-<address in hex>``. (The
    ``*`` matches ``28`` in our example - the *vendor ID* is not
    relevant because the address part is globally unique in the
    Onewire universe).
  * Having found that directory, we know that it must contain a file
    named ``temperature``
  * Creates a ``W1Sensor``, passing the temperature file
    ``/sys/bus/w1/devices/28-02131d959eaa/temperature`` to its
    constructor.

* That something (call it ``W1SensorFactory``) is then used to create
  sensors from configuration data, like so ...

  .. code-block:: c++

     uint64_t address = ...;                  // <--- address, taken from a config of any kind
     W1SensorFactory factory("/sys/bus/w1");  // <--- onewire tree, rooted at /sys/bus/w1
     W1Sensor* sensor = factory.find_by_address(address);
     std::cout << sensor->get_temperature() << std::endl;

Implementation
--------------

Lets create a class ``W1SensorFactory`` (a *factory* is something that
creates something) that fulfills the requirements listed further
below.

Fixture
.......

As a test-implementation detail, the fixture class
``sensor_w1_factory_suite`` ...

* Creates a temporary directory ``dirname`` for the duration of the
  test run. That directory is taken as a simulated ``/sys/bus/w1``
  Onewire sysfs directory.
* That directory ``dirname`` is arranged to contain a device,
  ``<dirname>/devices/28-02131d959eaa``.
* ``<dirname>/devices/28-02131d959eaa/temperature`` is the device's
  temperature file.
* The method ``void change_temperature(double temperature)`` is used
  to modify the temperature from within test code.

.. literalinclude:: /trainings/material/soup/cxx-code/oo-sensor-w1-factory/tests/sensor-w1-factory-fixture.h
   :caption: :download:`/trainings/material/soup/cxx-code/oo-sensor-w1-factory/tests/sensor-w1-factory-fixture.h`
   :language: c++

.. note::

   Download that file, place it into your project's ``tests/``
   directory, and update that directory's ``CMakeLists.txt`` file
   accordingly.

Unit Tests
..........

One by one, download the following files into ``tests/`` (and to the
obvious ``CMakeLists.txt`` dance). when one test passes, procees to
the next.

``basic``
`````````

The sunny case: given an existing Onewire address, the factory returns
a ``W1Sensor`` object.

.. literalinclude:: /trainings/material/soup/cxx-code/oo-sensor-w1-factory/tests/sensor-w1-factory-suite--basic.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-sensor-w1-factory/tests/sensor-w1-factory-suite--basic.cpp`
   :language: c++

``notfound``
````````````

One possible error: *address not found*. Lacking any knowledge of
:doc:`C++ smart pointers
</trainings/material/soup/cxx11/030-smart-pointers/group>`, a raw
pointer with the value ``nullptr`` is returned.

.. literalinclude:: /trainings/material/soup/cxx-code/oo-sensor-w1-factory/tests/sensor-w1-factory-suite--notfound.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-sensor-w1-factory/tests/sensor-w1-factory-suite--notfound.cpp`
   :language: c++

``find_is_const``
`````````````````

Exercising our C++ expertise, we know that something that *creates*
something rarely modifies itself - hence the
``W1SensorFactory::find_by_address()`` could just as well be
``const``.

.. literalinclude:: /trainings/material/soup/cxx-code/oo-sensor-w1-factory/tests/sensor-w1-factory-suite--find_is_const.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-sensor-w1-factory/tests/sensor-w1-factory-suite--find_is_const.cpp`
   :language: c++

Testing In Isolation
....................

.. code-block:: console

   $ pwd
   /home/jfasch/tmp/FH-ECE20-final-x86_64    # <--- my PC build directory (yours might be different)

ALl green ...

.. code-block:: console

   $ ./tests/FH-ECE20-final--suite 
   Running main() from /home/jfasch/work/FH-ECE20-final/googletest/googletest/src/gtest_main.cc
   [==========] Running 5 tests from 3 test suites.
   [----------] Global test environment set-up.
   [----------] 2 tests from sensor_const_suite
   [ RUN      ] sensor_const_suite.basic
   [       OK ] sensor_const_suite.basic (0 ms)
   [ RUN      ] sensor_const_suite.is_a_sensor
   [       OK ] sensor_const_suite.is_a_sensor (0 ms)
   [----------] 2 tests from sensor_const_suite (0 ms total)
   
   [----------] 2 tests from sensor_random_suite
   [ RUN      ] sensor_random_suite.basic
   [       OK ] sensor_random_suite.basic (0 ms)
   [ RUN      ] sensor_random_suite.is_a_sensor
   [       OK ] sensor_random_suite.is_a_sensor (0 ms)
   [----------] 2 tests from sensor_random_suite (0 ms total)
   
   [----------] 1 test from w1_sensor_suite
   [ RUN      ] w1_sensor_suite.test_read_sensor
   [       OK ] w1_sensor_suite.test_read_sensor (0 ms)
   [----------] 1 test from w1_sensor_suite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 5 tests from 3 test suites ran. (0 ms total)
   [  PASSED  ] 5 tests.

Testing In Reality
------------------

On The PC
.........

Once the project compiles on *and for* the development machine, you
are able to test it; no need for target hardware.

* Create a simulated ``sysfs`` tree at ``/tmp/w1-root`` (for example),
  together with a fully functional sensor device

  .. code-block:: console

     $ mkdir -p /tmp/w1-root/devices/32-deadbeef
     $ echo 36700 >> /tmp/w1-root/devices/32-deadbeef

* Run our sophisticated application on it (taking the role of a the
  system configurator mentioned above)

  .. code-block:: console

     $ pwd
     /home/jfasch/tmp/FH-ECE20-final-x86_64    # <--- my PC build directory (yours might be different)

  .. code-block:: console

     $ ./bin/onewire-temperature-factory 
     ./bin/onewire-temperature-factory <basedir> <address-in-hex> [interval]
         basedir                 ... e.g. /sys/bus/w1
         address-in-hex          ... 0xdeadbeef
	 interval                ... in seconds
         n-iterations (optional) ... number of measurements
                                     before termination

  .. code-block:: console

     $ ./bin/onewire-temperature-factory /tmp/w1-root 0xdeadbeef 2 4
     36.7
     36.7
     36.7
     36.7

On The Target
.............

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`
   * FH toolchain setup (you should have that already in place for a
     long time though):
     :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`

Having *cross compiled* the project (:doc:`see here
</trainings/material/soup/linux/toolchain/cmake/cross>`), we test it
against a real sensor device.

.. code-block:: console

   $ pwd
   /home/jfasch/tmp/FH-ECE20-final-pi    # <--- my Pi build directory (yours might be different)

.. code-block:: console

   $ scp -P 2020 ./bin/onewire-temperature-factory joerg.faschingbauer@jfasch.bounceme.net:
   $ ssh -p 2020 joerg.faschingbauer@jfasch.bounceme.net ./onewire-temperature-factory /sys/bus/w1 0x2131d959eaa 2 4
   ... real temperatures ...

