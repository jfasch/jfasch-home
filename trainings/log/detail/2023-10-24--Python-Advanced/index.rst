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

Up Front: Project Management
----------------------------

.. sidebar::

   * Github: https://github.com/jfasch/2023-10-24

Setup Github project (crossing fingers)

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`

Python Basics Recap
-------------------

All optional. But we should not miss the central points like Python's
referencing scheme, im/mutability, memory management,
typing. Everything's an object, alas.

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

Exercise Series: CSV Files
..........................

If appropriate, go through these exercises:

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`

Group Project Kickoff
---------------------

* Draw "Data Logger" sketch
* Sensor classes intro
* Main loop |longrightarrow| application, simply printing to stdout

Object Oriented Programming
---------------------------

From :doc:`/trainings/material/soup/python/advanced/oo/group` ...

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`

  Apply inheritance

  * Create ``Sensor`` base class (*test first*)
  * ``assert`` being-a ``Sensor`` before entering main loop

* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

  * Require ``Sensor`` to be-a ``abc.ABC`` (*test first*)
