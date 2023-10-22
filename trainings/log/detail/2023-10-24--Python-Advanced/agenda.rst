.. include:: <mmlalias.txt>


Agenda: Python Advanced (2023-10-24 - 2023-10-26)
=================================================

.. contents::
   :local:

.. sidebar::

   **Available Material**

   * :doc:`/trainings/material/soup/python/group`

Day 1: Basic Python
-------------------

Up Front: Project Management
............................

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`

Exercise Prerequisites
......................

* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/drafts/argparse/topic`

Datatypes, Datatypes
....................

* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0310_strings_formatting/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`

Functions
.........

* :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

Looping Constructs (With An Emphasis On The ``else`` Clause)
............................................................

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`

Generators
..........

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/iterator-protocol`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/fibonacci-generator`

Miscellaneous
.............

* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`

Day 2: Advanced Python Features
-------------------------------

Closures, Decorators And More
.............................

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Dynamic Features
................

* :doc:`/trainings/material/soup/python/advanced/exec/topic`
* :doc:`The eval() function <python:library/functions>`

Object Oriented Programming
...........................

From :doc:`/trainings/material/soup/python/advanced/oo/group` ...

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Error Handling And Recovery
...........................

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

Modules And Packages
.................... 

* :doc:`/trainings/material/soup/python/advanced/modules`

Multithreading
..............

.. sidebar::

   **The GIL**

   * `GIL, over at the Python Wiki
     <https://wiki.python.org/moin/GlobalInterpreterLock>`__
   * `David Beazley: Understanding the Python GIL (Youtube)
     <https://youtu.be/Obt-vMVdM8s>`__

* :doc:`/trainings/material/soup/python/advanced/multithreading/basics`
* :doc:`/trainings/material/soup/python/advanced/multithreading/mutex`
* Discussion: The *Global Interpreter Lock (GIL)*

  * Show how the load/modify/store conflict appears to not be an issue
    in Python (?) (:download:`code/race-load-modify-store.py`)
  * Could that be the `GIL
    <https://wiki.python.org/moin/GlobalInterpreterLock>`__ ?
  * What's the GIL altogether?
  * Why could it be a bad idea to trust the GIL too much?
    (|longrightarrow| `PEP 703 <https://peps.python.org/pep-0703/>`__)
  * Jason Brownlee `mentions
    <https://superfastpython.com/thread-race-condition-shared-variable/>`__
    the same "issue" -- there is no race condition. There used to, he
    says, before Python 3.10, but nowadays there's not. He shows an
    contrived way to show a race (involving a ``time.sleep(0)``
    |:rolling_eyes:|)
  * Fix that with a mutex (show ``with`` usage!)

* :doc:`python:library/queue`

Multiprocessing
...............

Simply walk through the introductory example in
:doc:`python:library/multiprocessing`

Day 3: Into The Wild
--------------------

Data Science Topics
...................

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/misc/db/group`
* :doc:`/trainings/material/soup/python/misc/pandas/group`
* From :doc:`/trainings/material/soup/python/misc/ai/group`

  * :doc:`/trainings/material/soup/python/misc/ai/machine-learning-intro`
  * :doc:`/trainings/material/soup/python/misc/ai/linear-regression/topic`
  * :doc:`/trainings/material/soup/python/misc/ai/k-means`

Test Driven Development
.......................

* Establish mindset
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`
* ``pytest`` fixtures

  * :doc:`pytest:how-to/tmp_path`
  * :doc:`pytest:how-to/monkeypatch`

Group Project: An Idea
......................

* Data acquisition: gathering sensor data
* Varying kinds of sensors: physical hardware, internet proxy, MQTT,
  ...
* Varying kinds of information sinks: CSV, database, MQTT, ...
* Acquisition machinery: timestamping, frequency, buffering, ...
