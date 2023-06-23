Python Basics (2023-06-20 - 2023-06-22)
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

   * Structure: :doc:`notebook-wrapper`
   * Entire notebook: :download:`notebook.ipynb`

   **Github Repository**

   * `https://github.com/jfasch/2023-06-20
     <https://github.com/jfasch/2023-06-20>`__

   **Material**

   * :doc:`/trainings/material/soup/python/group`

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
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic` (livehacked: `argv.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/argv.py>`__)
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit` (solution: `digit.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/digit.py>`__

Control Flow, Sequences, *Iteration*
````````````````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers` (solution, in one line, using a generator expression |:wink:|: `maximum.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/maximum.py>`__)

Miscellaneous
`````````````

* *Generating* Fibonacci numbers: `fibonacci.py
  <https://github.com/jfasch/2023-06-20/blob/main/livehacking/fibonacci.py>`__

Day2
----

Morning Wakeup
..............

* Index-based vs. element-based iteration
* ``yield``, again: sequence of yielded element (three in a row), with
  debug statement in between
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/iteration-generation/topic`

Basics
......

Control Flow, Sequences, *Iteration*
````````````````````````````````````

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness` (solution: `prime.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/prime.py>`__)

More Datatypes
```````````````

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* From :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic` ...

  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
  * :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function` (solution: `prime-function.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/prime-function.py>`__)
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function` (solution: `uniq-function.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/uniq-function.py>`__)
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_generator` (solution: `uniq-generator.py <https://github.com/jfasch/2023-06-20/blob/main/livehacking/uniq-generator.py>`__)
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`

Day 3
-----

File I/O, And Encoding
......................

* :doc:`/trainings/material/soup/python/misc/encoding/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/distill`

Exercise Series: CSV Files
..........................

* :doc:`/trainings/material/soup/python/misc/csv/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`

Untold
------

Object Oriented Programming
...........................

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/exercises/userdb/user-class-person`

Advanced Language Features
..........................

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/topic`
* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
