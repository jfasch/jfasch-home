.. include:: <mmlalias.txt>


Agenda: Python Advanced (2023-11-22 - 2023-11-24)
=================================================

.. contents::
   :local:

.. sidebar::

   **Available Material**

   * :doc:`/trainings/material/soup/python/group`

Day 1: Basic Python
-------------------

Exercise Prerequisites: The Commandline
.......................................

* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/drafts/argparse/topic`

Datatypes, Datatypes
....................

Audience consists of experienced programmers in other languages, so I
expect to go over these topics rather quickly. We should not miss the
central points though, like Python's referencing scheme,
im/mutability, memory management, typing. And iteration of course
|:sunglasses:|. Everything's an object, alas.

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
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

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
* :doc:`/trainings/material/soup/python/advanced/modules`

Day 2: Group Project Kickoff, Advanced Topics
---------------------------------------------

Group Project Kickoff
.....................

Create a semi-realistic application, put together in a typical Python
project. Solve problems as we go (for example: at some point in the
project is will be necessary to formalize error handling; that will
lead us to :doc:`exceptions
</trainings/material/soup/python/advanced/exceptions/topic>`)

**An idea: Data Logger**

* Data acquisition: gathering sensor data
* Varying kinds of sensors: physical hardware, internet proxy, MQTT,
  ...
* Varying kinds of information sinks: CSV, database, MQTT, ...
* Acquisition machinery: timestamping, frequency, buffering, ...

Project Management, Test Driven Development
...........................................

**Project Management**

* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/drafts/setuptools/topic`

**Test Driven Development**

* Establish mindset
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`
* ``pytest`` fixtures

  * :doc:`pytest:how-to/tmp_path`
  * :doc:`pytest:how-to/monkeypatch`

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

Postpone most of that, start with classes and bring in the rest later.

Error Handling And Recovery
...........................

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

Day 3: More Advanced Topics (All The Rest, And More)
----------------------------------------------------

Note that this is much more than we will actually have time for - most
of it is optional.

MQTT
....

Bring that into the project somehow (find a use case |:innocent:|)

* :doc:`/trainings/material/soup/python/misc/mqtt/topic`
* :doc:`python:library/json`

CSV And Databases
.................

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/misc/db/group`

Closures, Decorators And More
.............................

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Dynamic Features
................

* :doc:`/trainings/material/soup/python/advanced/exec/topic`
* :doc:`The eval() function <python:library/functions>`

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
* :doc:`python:library/queue`

Data Science Topics
...................

* :doc:`/trainings/material/soup/python/misc/pandas/group`
* From :doc:`/trainings/material/soup/python/misc/ai/group`

  * :doc:`/trainings/material/soup/python/misc/ai/machine-learning-intro`
  * :doc:`/trainings/material/soup/python/misc/ai/linear-regression/topic`
  * :doc:`/trainings/material/soup/python/misc/ai/k-means`

* NumPy: Cite :doc:`/trainings/log/detail/2019-11-12/index`
