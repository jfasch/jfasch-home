Python (2022-11-16 - 2022-11-18)
================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Material**

   * :doc:`/trainings/material/soup/python/group`

   **Source Code**

   * `Github <https://github.com/jfasch/2022-11-16>`__

   **Notebook**

   * :doc:`Structure <notebook-wrapper>`
   * :doc:`Whole notebook <notebook>`
   * :download:`Download <notebook.ipynb>`

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

**Exercises**

* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`

Control Flow, Sequences, *Iteration*
....................................

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`
* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness`

More Datatypes
..............

* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_plain`
* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/distill`

Advanced Topics
---------------

* :doc:`/trainings/material/soup/python/basics/python_0310_strings_formatting/topic`
* :doc:`/trainings/material/soup/python/basics/python_0330_strings_encoding/topic`

Clean and Structured Coding
...........................

* :doc:`/trainings/material/soup/python/advanced/modules`
* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* From :doc:`/trainings/material/soup/python/advanced/oo/group`

  * :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/operator-overloading/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Extended Language Features
..........................

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/topic`
* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Project Management
..................

* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest-intro`

Group Exercise: Toy Project
---------------------------

Lets implement a small toy project that touches many topics of the
course, and which leaves us room to explore Python's huge standard
library by playing around.

* Acquire values from *any* sensor and send them *somewhere*
* Sensors are arranged in a class hierarchy starting at ``class
  Sensor``. Possible sensors are

  * Physical ones (not easily had on a PC though)
  * Simulated ones (e.g. spitting out random values)
  * Ones that read their values sequences from e.g. CSV files

* Value sinks likewise. Possible sinks are

  * CSV files
  * MQTT broker clients
  * CAN bus (can be had on a PC if it runs Linux)

