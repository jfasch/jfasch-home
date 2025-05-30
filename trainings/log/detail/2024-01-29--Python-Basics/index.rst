Python Basics (2024-01-29 - 2024-01-31)
=======================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda
   notebook-wrapper

.. sidebar::

   **Original Agenda** 

   * :doc:`agenda`

   **Notebook**

   * :doc:`Chapters <notebook-wrapper>`
   * :doc:`Right in the middle of it <notebook>`
   * Download: :download:`notebook.ipynb`

   **Github Repository**

   * `https://github.com/jfasch/2024-01-29
     <https://github.com/jfasch/2024-01-29>`__

   **Material**

   * :doc:`/trainings/material/soup/python/index`

Day 1
-----

Setup
.....

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/misc/vscode`

Basics
......

Datatypes
`````````

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0125_running/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`

Control Flow, Sequences, *Iteration*
````````````````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`
* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`

Day 2
-----

* :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness`

Functions
.........

* :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`
* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function`

More Datatypes, File IO
.......................

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/distill`
  (Solution: `distill.py
  <https://github.com/jfasch/2024-01-29/blob/main/livehacking/distill.py>`__)

``os.listdir()``, ``os.path.join()``
....................................

See :doc:`notebook <notebook>`

Day 3
-----

Morning Awakening
.................

* ``os.walk()``
* ``pathlib``: a better ``os.join()``
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/topic`

More About Datatypes
....................

* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`

Unit Testing (``pytest``), Project Management
.............................................

* :doc:`/trainings/material/soup/python/swdev/pytest/intro`
* From :doc:`/trainings/material/soup/python/swdev/pip/topic`:

  * :doc:`/trainings/material/soup/python/swdev/pip/slides`
  * :doc:`/trainings/material/soup/python/swdev/pip/screenplay`

* From :doc:`/trainings/material/soup/python/swdev/venv/topic`

  * :doc:`/trainings/material/soup/python/swdev/venv/slides`
  * :doc:`/trainings/material/soup/python/swdev/venv/screenplay`

Object Oriented Programming
...........................

From :doc:`/trainings/material/soup/python/advanced/oo/index`:

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`

(Optional) Exercise Series: CSV Files
.....................................

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`

``pandas``, ``numpy``, ``scikit-learn``
.......................................

From :doc:`/trainings/material/soup/python/misc/pandas/index`

* :doc:`/trainings/material/soup/python/misc/pandas/basics`
* :doc:`/trainings/material/soup/python/misc/pandas/iloc`
* :doc:`/trainings/material/soup/python/misc/pandas/loc`
* :doc:`/trainings/material/soup/python/misc/pandas/indexes`
* :doc:`/trainings/material/soup/python/misc/pandas/filters`
* :doc:`/trainings/material/soup/python/misc/pandas/mod_col`
* :doc:`/trainings/material/soup/python/misc/pandas/add_row`

``numpy`` and ``scikit-learn``: see :doc:`notebook <notebook>`

