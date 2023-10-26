.. include:: <mmlalias.txt>


Python Advanced (2023-10-24 - 2023-10-26)
=========================================

.. toctree::
   :hidden:

   agenda
   notebook-wrapper

.. contents::
   :local:

.. sidebar::

   **Original Agenda** 

   * :doc:`agenda`

   **Github Repository**

   * https://github.com/jfasch/2023-10-24

   **Notebook**

   * Structure: :doc:`notebook-wrapper`
   * Entire notebook: :download:`notebook.ipynb`

   **Material**

   * :doc:`/trainings/material/soup/python/group`

Day 1
-----

Python Basics Recap
...................

All optional. But we should not miss the central points like Python's
referencing scheme, im/mutability, memory management, typing. And
iteration of course |:sunglasses:|. Everything's an object, alas.

The Very Basics
```````````````

* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0310_strings_formatting/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`

Exercise time ...

* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`

``range()``, And Iteration In General
`````````````````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/iterator-protocol`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/fibonacci-generator`


Modules
```````

* :doc:`/trainings/material/soup/python/advanced/modules`

Group Project Kickoff
.....................

* Draw "Data Logger" sketch
* Sensor classes intro
* Main loop |longrightarrow| application, simply printing to stdout

Object Oriented Programming
...........................

From :doc:`/trainings/material/soup/python/advanced/oo/group` ...

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`

Day 2
-----

Leftover From Yesterday
.......................

* ``float.__int__()`` (via ``Person.__str__()``)
* Where does the ``exit()`` function come from? It is not documented
  in the builtin functions documentation, nonetheless it is present as
  a global function.

  * :doc:`python:library/constants`: at the bottom, there is a note
    about the :doc:`python:library/site` module doing that
  * :doc:`python:library/site` does not mention that

  |longrightarrow| a-ha

* ``frozendict``? There is no such thing, but there's a :doc:`python:library/stdtypes`
* ``async``/``await``? |longrightarrow| :doc:`/about/site/work-in-progress/blink/index`

Group Project: Flip Chart Sketches
..................................

jjj take pictures

jjj * :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

Miscellaneous
.............

* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`

Object Oriented Programming, Continued
......................................

From :doc:`/trainings/material/soup/python/advanced/oo/group` ...

* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`

Group Project, OO-ified
.......................

* ``FileSensor``
* ``CSVSink``
* ``AcquisitionLoop``

Bring them live ...

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/basics/permissions/basics`
   * :doc:`/trainings/material/soup/python/swdev/pytest/intro`
   * Coding guidelines? |longrightarrow| `PEP-8
     <https://peps.python.org/pep-0008/>`__

* Integration into ``datalogger.py``
* Make ``datalogger.py`` a real program (|longrightarrow|
  :doc:`/trainings/material/soup/linux/basics/permissions/basics`)
* Problems

  * Test data (the test temperature file for ``FileSensor``)
    |longrightarrow|
    :doc:`/trainings/material/soup/python/swdev/pytest/intro`
  * Testing ``AcquisitionLoop``

    * Number of iterations
    * Timestamps?

Test Driven Development
.......................

* :doc:`/trainings/material/soup/python/swdev/pytest/intro`
* Look into tests
* ``AcquisitionLoop``? 

  * Externalize timestamps |longrightarrow| iterables and generators
  * :doc:`python:library/itertools`

Object Oriented Programming, Continued
......................................

* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`

  Apply inheritance

  * Create ``Sensor`` base class (*test first*)
  * ``assert`` being-a ``Sensor`` before entering main loop

* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

  * Require ``Sensor`` to be-a ``abc.ABC`` (*test first*)

* Put all sensor implementations under an abstract base class,
  ``sensor.Sensor``.

Decorator Toolcase: ``*args``, ``**kwargs``
...........................................

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`

Day 3
-----

Morning Greeting
................

* How does ``pytest`` know which fixtures are requested?
  |longrightarrow| :doc:`python:library/inspect`
* Sergey's OPC-UA sensor
* Revisit ``test_acquisition_loop.test_mock_csv_sink``. Replace
  ``class MyMockedThing`` with a function that uses ``nonlocal``
* |longrightarrow|
  :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`
  (enter :doc:`/trainings/material/soup/python/advanced/closures/topic`)
* Further plan (see below)

Decorator Toolcase, Continued
.............................

* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Multithreading
..............

* :doc:`/trainings/material/soup/python/advanced/multithreading/basics`
* Hack small *Load-Modify-Store* race
  (:doc:`/trainings/material/soup/linux/sysprog/posix-threads/030-exercise-pthcreate-race-condition/topic`
  and
  :doc:`/trainings/material/soup/linux/sysprog/posix-threads/040-mutex/topic`
  in C++
* Same in Python |longrightarrow| nothing
* |longrightarrow| The GIL (Global Interpreter Lock), and `its way out
  of the Python interpreter
  <https://discuss.python.org/t/pep-703-making-the-global-interpreter-lock-optional-in-cpython-acceptance/37075>`__
* :doc:`/trainings/material/soup/python/advanced/multithreading/mutex`

Exercises
.........

Sensor Implementation That Receives UDP Datagrams
`````````````````````````````````````````````````

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/multithreading/basics`
   * :doc:`/trainings/material/soup/python/advanced/multithreading/mutex`
   * :doc:`python:library/queue`

* Datagrams contain temperature in millcelsius (just like ``FileSensor``)
* Look into ``acquisition_loop_utils.py`` for how to receive datagrams
  on a port
* Acquisition rate does ont necessarily match datagram rate. It might
  well be that

  * Datagrams are received much faster (10ms, for example) than the
    acquisition loop acquires measurements (1s interval, for
    example). Samples gather up inside the sensor (roughly 100 samples
    per measurement with the above rates).

    In this case (multiple samples available at the time
    ``sensor.get_temperature()`` is called) a call to
    ``sensor.get_temperature()`` must

    * compute the average across available samples
    * remove the gathered samples to make room for new incoming data

  * Datagrams are received at a slower rate than the loop acquires. In
    this case there is *nothing* available to return from
    ``sensor.get_temperature()``. To overcome that,

    * If a measurement from a previous measurement is available,
      return that
    * If no measurement has yet been made, raise an exception

* To not drop any packets while the main acquisition loop is busy
  doing other things (block on file IO, for example, or wait for
  another sensor to complete its measurement), the sensor
  implementation must spawn a thread, internally, that does the
  network communication.

  In fact, the whole point of the exercise is to *correctly*
  communicate the data to the main (acquisition) thread.

* Is it possible to TDD that? Try hard.

``CompositeSink``
`````````````````

* ``AcquisitionLoop`` knows about *only one* ``Sink``. That is the
  plan!
* Create one ``Sink`` implementation, ``CompositeSink``, that
  dispatches ``write_measurement()`` onto multiple sinks that it
  *owns*
* Write a test for that, together.

MQTT Sink Implementation
````````````````````````

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/misc/mqtt/topic`
   * :doc:`python:library/json` (``dumps()`` and ``loads()``)
   * `monkeypatch fixture
     <https://docs.pytest.org/en/4.6.x/reference.html#monkeypatch>`__

* Publish measurement dictionary to an MQTT broker
* Define format of transmitted data
* TDD?!

Timestamps?
```````````

Bring timestamps (``datatime.datatime``) into the game ...

* Formally define measurement dictionary (test)
* Wrap ``sensors`` dictionary that is used in ``datalogger.py`` into a
  class, say, ``Sensors``. 
* Write a method ``Sensors.read_measurements() -> Measurements``
* ``class Measurements`` is an encapsulation of the raw dictionary
  that is composed in ``AcquisitionLoop``, and consumed across all
  ``Sink`` implementations.

Error Handling And Recovery
...........................

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

Still Untold
------------

Data Science
............

Pandas
``````

* :doc:`/trainings/material/soup/python/misc/pandas/basics`
* :doc:`/trainings/material/soup/python/misc/pandas/iloc`
* :doc:`/trainings/material/soup/python/misc/pandas/loc`
* :doc:`/trainings/material/soup/python/misc/pandas/indexes`
* :doc:`/trainings/material/soup/python/misc/pandas/filters`
* :doc:`/trainings/material/soup/python/misc/pandas/mod_col`
* :doc:`/trainings/material/soup/python/misc/pandas/add_row`

NumPy
`````

* :doc:`/trainings/log/detail/2019-11-12/index`
* :doc:`numpy:reference/routines.fft`

  `NumPy Tutorials : 011 : Fast Fourier Transforms - FFT and IFFT
  <https://youtu.be/su9YSmwZmPg?si=IEBwM4nWM5XxGNOL>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/su9YSmwZmPg?si=Yqn-pPccCs9kEK7h" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

Looping Constructs (With An Emphasis On The ``else`` Clause)
............................................................

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`

Functions
.........

* :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

Project Management
..................

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
