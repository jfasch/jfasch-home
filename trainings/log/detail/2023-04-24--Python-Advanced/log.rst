.. include:: <mmlalias.txt>


Course Log: Python Advanced (2023-04-24 - 2023-04-26)
=====================================================

.. contents::
   :local:

.. sidebar::

   **Course Overview**

   * :doc:`index`

   **Notebook**

   * :doc:`Structure <notebook-wrapper>`
   * :doc:`Whole notebook <notebook>`
   * :download:`Download <notebook.ipynb>`

Up Front: Project Management
----------------------------

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`

Day 1: Python Inside Out
------------------------

Exercise Prerequisites
......................

* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/drafts/argparse/topic`

References And Other Pitfalls
.............................

* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

Looping Constructs (With An Emphasis On The ``else`` Clause)
............................................................

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`

Generators
..........

From
:doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic`)

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/iterator-protocol`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/fibonacci-generator`

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

Miscellaneous Threading
.......................

* Show how the load/modify/store conflict appears to not be an issue
  in Python (?) (:download:`code/race-load-modify-store.py`)

  * Could that be the `GIL
    <https://wiki.python.org/moin/GlobalInterpreterLock>`__?
  * What's the GIL altogether?
  * Why could it be a bad idea to trust the GIL too much?
    (|longrightarrow| `PEP 703
    <https://peps.python.org/pep-0703/>`__)
  *
    `https://superfastpython.com/thread-race-condition-shared-variable/`__
    mentions the same "issue" -- there is no race condition. There
    used to, before Python 3.10, but nowadays there's not. He shows an
    contrived way to show a race (involving a ``time.sleep(0)``
    |:rolling_eyes:|)
  * Fix that with a mutex (show ``with`` usage!)

  * `Events
    <https://docs.python.org/3/library/threading.html#event-objects>`__. Maybe
    some live-hacked dice-rolling in a subthread.
  * :doc:`python:library/queue`

* Multiprocessing

  Simply walk through the introductory example in
  :doc:`python:library/multiprocessing`

Day 2: Clean Code (In A Broader Sense), Group Project Kickoff
-------------------------------------------------------------

Group Project: Discussion
.........................

* Data acquisition: gathering sensor data
* Varying kinds of sensors: physical hardware, internet proxy, MQTT, ...
* Varying kinds of information sinks: CSV, database, MQTT, ...
* Acquisition machinery: timestamping, frequency, buffering, ...

Clean Code?
...........

From :doc:`/trainings/material/soup/clean-code/group` ...

* :doc:`/trainings/material/soup/clean-code/craft-sw`
* :doc:`/about/site/work-in-progress/2022-04-13/seminar/clean-code-craftsmanship`

Design Patterns Overview
........................

* :doc:`/trainings/material/soup/cxx-design-patterns/uml/uml`
* :doc:`/trainings/material/soup/cxx-design-patterns/oo-principles`
* :doc:`Design patterns
  </trainings/material/soup/cxx-design-patterns/group>`: problems,
  possible solutions

Test Driven Development
.......................

* (Try to) establish mindset
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`
* ``pytest`` fixtures

  * :doc:`pytest:how-to/tmp_path`
  * :doc:`pytest:how-to/monkeypatch`

Day 3: Group Project
--------------------

* Create two or three teams
* Use Test Driven Develpment (TDD) to formulate requirements
* *Loop: hack, fix, refactor*
