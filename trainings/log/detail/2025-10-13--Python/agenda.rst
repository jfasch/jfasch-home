.. include:: <mmlalias.txt>


Agenda: Python (2025-10-13 - 2025-10-15)
========================================

Idea is to quickly go over Python basics (variables, datatypes,
functions, ...) on day 1. Then, on day 2, launch a group exercise to
make something bigger (see :ref:`2025-10-13-exercise`). The remaining
material (OO etc., read below) is then covered in support of making
something bigger.

.. contents::
   :local:

Setup
-----

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/misc/vscode`

Basics
------

Datatypes
.........

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0125_running/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`

Exercises
`````````

* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`
* :doc:`/trainings/material/soup/python/exercises/legacy/dict_keyerror`

More On Datatypes
.................

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`

Control Flow, Sequences, *Iteration*
....................................

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`

Exercises
`````````

* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness`

Functions
.........

From
:doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`:

* :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

Exercises
`````````

* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers_function`
* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`

Lets keep the following topics in mind, but defer them until later.

* Towards decorators

  * :doc:`/trainings/material/soup/python/advanced/starargs/topic`
  * :doc:`/trainings/material/soup/python/advanced/closures/topic`
  * :doc:`/trainings/material/soup/python/advanced/decorators/topic`

* Not functions, but generators. (From
  :doc:`/trainings/material/soup/python/advanced/iteration-generation/topic`)

  * :doc:`/trainings/material/soup/python/advanced/iteration-generation/iteration-generation/topic`
  * :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic`

File IO
.......

* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

.. _2025-10-13-exercise:

Exercise Kick Off
-----------------

.. note::

   This exercise (a data logger) is not set in stone. What makes it
   ideal is that it gives us much opportunity to cover the remaining
   topics.

Based upon what we have learned, we are ready to enter a larger
exercise. Starting with one exercise where each participant is on
their own, straightforwardly hack a "data logger" that reads from a
number of named input sensors and writes a CSV file.

**Future**

* Turn inputs (sensors) and outputs (CSV and ...) into something more
  flexible (|longrightarrow| OO)
* Unit testing
* Project management and packaging

Modules
-------

* :doc:`/trainings/material/soup/python/advanced/modules`

(Exercise: split monolithic data logger into something more
approachable)

Object Oriented Programming, And Exceptions
-------------------------------------------

From :doc:`/trainings/material/soup/python/advanced/oo/index` ...

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Exceptions too,

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`

Exercise: OO
------------

.. sidebar:: Trainer's note

   * Come up with ``pytest`` unit tests
   * Give a short venv and pip overview
   * Give a short ``pytest`` overview

* Add more outputs; for example ...

  * :doc:`MQTT </trainings/material/soup/python/misc/mqtt/topic>`
  * :doc:`Database </trainings/material/soup/python/misc/db/index>`
  * ...

* Polymorphic sensor 

  * One that receives UDP datagrams asynchronously (|longrightarrow|
    :doc:`Multithreading
    </trainings/material/soup/python/advanced/multithreading/index>`)
  * One over userspace I2C? (:doc:`here
    </trainings/material/soup/linux/hardware/i2c/topic>`)

* "Main Loop" object

  * configurable interval
  * graceful termination
  * time (and interval) abstracted away with a generator?

Project Work: Virtual Environments, Unit Testing, Packaging, PyPI
-----------------------------------------------------------------

From :doc:`/trainings/material/soup/python/swdev/index`,

* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pypi`
* :doc:`/trainings/material/soup/python/swdev/pytest/index`

Optional Topics
---------------

* Using ``matplotlib`` to draw graphs from gathered data
* Data analysis using :doc:`pandas
  </trainings/material/soup/python/misc/pandas/index>`
* Automation using `subprocess
  <https://docs.python.org/3/library/subprocess.html#module-subprocess>`__
  and `shutil
  <https://docs.python.org/3/library/shutil.html#module-shutil>`__
