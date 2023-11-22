.. include:: <mmlalias.txt>

.. ot-task:: fh2021.datalogger


Data Logger
===========

.. sidebar::

   **Documentation**

   * `std::vector
     <https://en.cppreference.com/w/cpp/container/vector>`__
   * `std::pair <https://en.cppreference.com/w/cpp/utility/pair>`__
   * :doc:`/trainings/material/soup/cxx03/900-standard-library-miscellanea/string/topic`

Acquisition loop, left (sensors), right (a CSV file?
Terminal/``std::cout``?). Sketch that in spaghetti style
|longrightarrow| reusable components!

* Sensor config (by name). `Vector
  <https://en.cppreference.com/w/cpp/container/vector>`__ of `pairs
  <see https://en.cppreference.com/w/cpp/utility/pair>`__ ``(name:
  string, Sensor*)`` internally, but with a dedicated class around it
  to constrain the interface to what's needed.
* Acquisition loop class. *Interval*, left (sensor config), right
  (CSV/Terminal?).
* Problem: decoupling |longrightarrow| *interface* (eg. ``Sink``)

Standup Records
---------------

2023-11-20
..........

* Structure: ``datalogger/CMakeLists.txt``

  *Explain:* ``TARGET_INCLUDE_DIRECTORIES()`` announces ``.``
  ``PUBLIC`` to anyone who needs that node

* ``void DataLogger::startLogging(uint16_t count = 0);``, with ``0``
  having the special meaning *infinity* |longrightarrow| unification
  into *one single* method
* Remove leftover ``DataLogger::getTime()``. Defer implementation
  until we need timestamps
* ``tests/logger-suite.cpp``: don't use ``SinkFile`` - test *in terms
  of* ``SinkMock``

  |longrightarrow| make ``SinkMock`` usable for that purpose

* ``tests/sink-suite.cpp`` 

  * use ``SinkMock`` instead of ``SinkFile`` (like above)
  * don't use ``SensorConfig`` to create a ``SensorValues`` object -
    create it directly, inside the test (we're not testing
    ``SensorConfig``, only the sink)

    Best to create ``tests/sensor-values-suite.cpp`` to define the
    behavior of ``SensorValues``

* ``tests/sensor-config-suite.cpp``

  * Adding the same name three times should be an error (lets use
    ``throw runtime_error("...message here...")`` as an error handling
    replacement)
  * Three sensors should lead to a measurement size (.size()) of 3
  * ...

Requirements
------------

Modify the program ``bin/data-logger.cpp`` to compose itself out of
prebuilt components.

* Sensor config (by name).
* Acquisition loop class. *Interval*, left (sensor config), right
  (CSV/Terminal?).
* Problem: decoupling |longrightarrow| *interface* (eg. ``Sink``)

Implementation
--------------

Look like a number of classes is in order ...

* ``SensorConfig``. Holds the sensors, together with their names. 

  * ``void add(const std::string& name, Sensor*);``
  * Iteration over ``(name,sensor)`` pairs. Maybe a method ``const
    std::map<std::string, Sensor*> all();`` that gives easy access to
    that iteration? See the current state of ``bin/data-logger.cpp``
    for iteration.

* ``SensorValues``. Much like the ``SensorConfig``, but with live
  values instead of sensors.

* ``AcquisitionLoop``.

  * (Constructor). Parameters ``interval``, ``n_iterations``?
  * ``void doit();`` Nothing more.

* A ``Sink`` hierarchy, starting at the interface ``Sink``. (See the
  ``Sensor`` hierarchy for how interfaces are made.)

  * The interface will have to have something like ``void
    write_measurements(const SensorValues&);``
  * The first implementation could be for testing only -
    ``MockingSink``. That class simply stores the ``SensorValues``
    that it receives in a ``std::vector`` that is used by the tests.

Testing
-------

* Try hard to test all aspects
* Write tests before you start to program

Future (*Not* Part Of This Development Cycle)
---------------------------------------------

* Configuration files format(s). JSON? XML? YAML? ``.ini``?
* CSV sink
* MQTT sink

Dependencies
------------

.. ot-graph::
   :entries: fh2021.datalogger
