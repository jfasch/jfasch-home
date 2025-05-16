.. include:: <mmlalias.txt>


Python Advanced (2023-04-24 - 2023-04-26)
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

   * https://github.com/jfasch/2023-04-24

   **Notebook**

   * Structure: :doc:`notebook-wrapper`
   * Entire notebook: :download:`notebook.ipynb`

   **Material**

   * :doc:`/trainings/material/soup/python/index`

Day 1: Python Inside Out
------------------------

Basics Recap
............

* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`

Generators
..........

From
:doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic`)

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/iterator-protocol`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/fibonacci-generator`

Dynamic Features
................

* :doc:`/trainings/material/soup/python/advanced/exec/topic`
* :doc:`The eval() function <python:library/functions>`

Object Oriented Programming
...........................

From :doc:`/trainings/material/soup/python/advanced/oo/index` ...

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`

Day 2: Object Oriented Programming, And Miscellaneous Discussion
----------------------------------------------------------------

Morning Opening
...............

Company code review. Cool, clean. Performance hint: use generators a
lot.

* *Generate* dataframes that appear in a directory from time to
  time: `watch-dataframes.py
  <https://github.com/jfasch/2023-04-24/blob/main/livehacking/watch-dataframes.py>`__
* *Generate* mass data which would otherwise have to be loaded into
  memory: `iter-measurement.py
  <https://github.com/jfasch/2023-04-24/blob/main/livehacking/iter-measurement.py>`__

Object Oriented Programming (Continued)
.......................................

From :doc:`/trainings/material/soup/python/advanced/oo/index` ...

* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Clean Code?
...........

From :doc:`/trainings/material/soup/clean-code/index` ...

* :doc:`/trainings/material/soup/clean-code/craft-sw`
* :doc:`/about/site/work-in-progress/2022-04-13/seminar/clean-code-craftsmanship`

Group Project Kickoff
.....................

* Big picture

  .. image:: project.png
     :scale: 50%
  
  * Data acquisition: gathering sensor data
  * Varying kinds of sensors: physical hardware, internet proxy, MQTT, ...
  * Varying kinds of information sinks: CSV, database, MQTT, ...
  * Acquisition machinery: timestamping, frequency, buffering, ...

* Start hacking: "data logger device", first sketch. To be implemented
  by three groups.

  * `datalogger-joerg.py
    <https://github.com/jfasch/2023-04-24/blob/main/programs/datalogger-joerg.py>`__

Day 3: Group Project
--------------------

Project Setup (IDE Usage?)
..........................

Apart from any kind of IDE (IDE's tend to hide those details from
you - this is not to help you, but to make you depend on them), these
are the steps to make our project work:

* :doc:`/trainings/material/soup/python/exercises/sensors/project-setup`

Related topics:

* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`

How to make VS Code work (terminal is simpler, I'd say
|:face_with_raised_eyebrow:|):

* `Using Python environments in VS Code
  <https://code.visualstudio.com/docs/python/environments>`__

Continue Hacking
................

Until 10am; explain:

* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

  Someone said, "Lets check for file existence first, and create the
  file if it does not exist." |longrightarrow| *Exclusive creation!*
  (``open(filename, 'x')``)

* :doc:`/trainings/material/soup/python/swdev/unittest`

  Someone was using ``unittest``. Not exactly deprecated, but
  ``pytest`` (see
  :doc:`/trainings/material/soup/python/swdev/pytest/intro`) *rocks*
  (not only compared to ``unittest``, but *absolutely*)

* Random notes

  * Reopen file in every loop iteration (``open(..., 'a')``)? Better
    leave it open until done? |longrightarrow| RAII jjj link
  * Polymorphize loop iterations? Infinite vs. finite?
  * ``KeyboardInterrupt``? Termination of an infinite loop? Graceful
    termination? |longrightarrow| ``threading`` in unit test (setting
    stop flag in main thread). Ugly!

Test Driven Development, ``pytest``
...................................

* (Try to) establish mindset
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`
* ``pytest`` fixtures

  * :doc:`pytest:how-to/tmp_path`
  * :doc:`pytest:how-to/monkeypatch`

Untold
------

Closures, Decorators And More
.............................

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Error Handling And Recovery
...........................

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

Miscellaneous Threading
.......................

.. sidebar::

   **The GIL**

   * `GIL, over at the Python Wiki
     <https://wiki.python.org/moin/GlobalInterpreterLock>`__
   * `David Beazley: Understanding the Python GIL (Youtube)
     <https://youtu.be/Obt-vMVdM8s>`__

* Show how the load/modify/store conflict appears to not be an issue
  in Python (?) (:download:`code/race-load-modify-store.py`)

  * Could that be the `GIL <https://wiki.python.org/moin/GlobalInterpreterLock>`__
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

  * `Events <https://docs.python.org/3/library/threading.html#event-objects>`__. Maybe
    some live-hacked dice-rolling in a subthread.
  * :doc:`python:library/queue`

* Multiprocessing

  Simply walk through the introductory example in
  :doc:`python:library/multiprocessing`

Design Patterns Overview
........................

* :doc:`/trainings/material/soup/cxx-design-patterns/uml/uml`
* :doc:`/trainings/material/soup/cxx-design-patterns/oo-principles`
* :doc:`Design patterns
  </trainings/material/soup/cxx-design-patterns/index>`: problems,
  possible solutions

