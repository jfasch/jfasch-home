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

Wild hacking expected ...

* :doc:`/trainings/material/soup/python/advanced/oo`
* :doc:`/trainings/material/soup/python/advanced/exceptions`
* :doc:`/trainings/material/soup/python/advanced/modules`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`

Advanced Language Topics
........................

**Encoding**

* :doc:`/trainings/material/soup/python/misc/encoding/topic`

**Iterator Protocol**

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/topic`

**Metaprogramming**

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Miscellaneous
.............

* :doc:`/trainings/material/soup/python/misc/db/group`
* :doc:`/trainings/material/soup/python/advanced/threading/group`
