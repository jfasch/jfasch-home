.. include:: <mmlalias.txt>


Python Advanced (2021-12-01 - 2021-12-03)
=========================================

.. sidebar::

   **Contents**

   .. contents::
      :local:

   **Material**

   * :doc:`..//2021-11-17/index`
   * :doc:`/trainings/material/soup/python/group`

   **Notebook**

   * :doc:`2021-12-01`
   * :doc:`Notebook TOC <notebook-wrapper>`

   **Git**

   https://github.com/jfasch/2021-12-01

.. toctree::
   :hidden:

   2021-12-01
   notebook-wrapper

Day 1
-----

Basics Recap
............

* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* Discussion about Java's TreeSet, vs. Python's searchable things.

  * TreeSet sounds like a balanced binary tree, like some form of a
    `red black tree
    <https://en.wikipedia.org/wiki/Red%E2%80%93black_tree>`__

    .. image:: images/red-black-tree.png
       :scale: 40%

  * Hash table basics. Python's are most likely much more elaborate
    (randomized and whatnot).

    .. image:: images/hashtable.png
       :scale: 40%

* Comprehensions (``list``, ``set``, ``dict``). (No generator
  expressions though.) See :doc:`2021-12-01`.
* :doc:`/trainings/material/soup/python/basics/python_1000_function_objects/topic`

Group Project Preparation
.........................

* At the basis: :doc:`/trainings/material/soup/python/swdev/pytest-intro`
* Talking about IoT sensors posting crap into cloud

  .. image:: images/big-picture.png
     :scale: 40%

* Which kind of crap will sensors post into cloud?

  .. image:: images/sensors.png
     :scale: 40%

* Sensor hardware (irrelevant to us). We write software to deal with
  it

  .. image:: images/sensor-hardware-vs-software.png
     :scale: 40%

* We do not want to have

  * ... a real sensor where we need a Diesel engine to make it send
    out vibrations. We just want a sensor that send out vibrations
    when we tell it to.
  * ... a big fat OPC/UA broker in the middle. Not even a lighter MQTT
    broker. Nor do we want to depend on an internet cloud provider for
    testing.

  .. image:: images/mock.png
     :scale: 40%

* We sure can do something with multithreading. Let the sensor threads
  hammer their data into a `thread-safe queue
  <https://docs.python.org/3/library/queue.html>`__ (as an in-process
  replacement for a fat broker).

  .. image:: images/mt.png
     :scale: 40%
  
Day 2
-----

**Plan**: write a number of sensor classes

* ``SensorRandom``
* ``SensorSine``
* ``SensorConstant``

All these sensors should be decoupled from *wall clock time* - testing
time series data is hard when you *must* deal with time. We don't.

.. image:: images/timeaxis.png
   :scale: 40%

Wild hacking expected.

* :doc:`/trainings/material/soup/python/advanced/oo`
* :doc:`/trainings/material/soup/python/advanced/modules`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/topic`
* Git workflow question, "What commit local? What push pull?"

  .. image:: images/git-workflow.png
     :scale: 40%

* Last topic for today:
  :doc:`/trainings/material/soup/python/advanced/threading/group`

**TODO**

* jjj refer to test cases
* jjj refer to thread series
* jjj refer to tests for tomorrow

Day 3
-----

* :doc:`/trainings/material/soup/python/advanced/threading/group`

  Reiterate, was a bit fast yesteray.

* Interfaces, abstract base classes |longrightarrow|
  :doc:`python:library/abc`

  .. image:: images/sensors.png
     :scale: 40%

* *Exercise*: MQTT transport format - *serialize/deserialize* - for
  sensor tuples ``(ts, x, y, z)`` |longrightarrow|
  :doc:`python:library/json`

  .. image:: images/serialize-deserialize.png
     :scale: 40%

  .. image:: images/serialize.png
     :scale: 40%

  .. image:: images/deserialize.png
     :scale: 40%

  .. note::

     Don't forget to include error tests. JSON exceptions must not get
     swallowed, at least. :doc:`python:library/json`

* MQTT livehacking maybe? Complete MQTT walkthrough? 1h.

  * :doc:`/trainings/material/soup/python/misc/mqtt/topic`.
  * Publish sensor data

    * Use our json ``blah.exchangeformat`` module. See
      ``tests/test_mqtt_format.py`` for how it works.
    * Publish sensor data row by row, at an interval (Should I?
      :doc:`python:library/argparse`?)
    * Subscribe at the other end, using
      `https://mosquitto.org/man/mosquitto_sub-1.html`__
    * Discuss what to do

      * Average? Over a number of values? Hacked in a minute.
      * CSV?

	* Live hacking? Figure out
	  writer. :doc:`/trainings/material/soup/python/misc/csv/topic`
	* :doc:`python:library/csv` |longrightarrow| link
  
* :doc:`/trainings/material/soup/python/advanced/exceptions`

  * Requirement: JSON deserialize must raise a ``DeserializeError``.
  * Notebook: exception handling

    * base class last
    * ``finally``?
    * ``else``?

  * Create exception hierarchy for our little project.

* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`

  * Quick livehack demo what can be done.
  * MATLAB replacement

    * :doc:`numpy:index`

* :doc:`/trainings/material/soup/python/misc/encoding/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

Hmmm?
.....

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`
* :doc:`/trainings/material/soup/python/misc/db/group`

