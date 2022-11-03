Python (2022-11-07 - 2022-11-10)
================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Material**

   * :doc:`/trainings/material/soup/python/group`

   **Source Code**

   * `Github <https://github.com/jfasch/2022-10-17>`__

   **Notebook**

   * :doc:`Structure <notebook-wrapper>`
   * :doc:`Whole notebook <notebook>`
   * :download:`Download <notebook.ipynb>`

Agenda
------

Up Front
........

* :doc:`/trainings/material/soup/python/swdev/pip/topic`
* :doc:`/trainings/material/soup/python/swdev/venv/topic`
* :doc:`/trainings/material/soup/python/swdev/pytest-intro`

Advanced Python
...............

* Iteration (Recap)
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`
* :doc:`/trainings/material/soup/python/advanced/oo-new/group`

  * :doc:`/trainings/material/soup/python/advanced/oo-new/constructor/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo-new/classes-and-dicts/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo-new/methods/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo-new/str-repr/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo-new/properties/topic`
  * :doc:`/trainings/material/soup/python/advanced/oo-new/namedtuple/topic`
  * (Implementation) Inheritance, super(), isinstance(), issubclass()
  * Interface Inheritance (Abstract Base Classes) - The ``abc`` Module
  * Operator overloading, ``__str__()``, ``__repr__()``
  * MRO

* Metaprogramming

  * What is a class?

    * Class methods (built-in)

  * Using ``type()`` to create a class/type
  * Runtime Class Manipulation
  * Class Decorators

* Function Arguments, Closures, Decorators

  * :doc:`/trainings/material/soup/python/advanced/starargs/topic`
  * :doc:`/trainings/material/soup/python/advanced/closures/topic`
  * :doc:`/trainings/material/soup/python/advanced/decorators/topic`

* Generators, The ``yield`` Keyword

  * :doc:`/trainings/material/soup/python/advanced/iteration-generation/iteration-generation/topic`
  * Generator Expressions

* ``eval()`` and ``exec()``

  * :doc:`/trainings/material/soup/python/advanced/exec/topic`

* The ``with`` Statement (Context Managers)

File System Interaction
.......................

https://docs.python.org/3/library/filesys.html

* :doc:`/trainings/material/soup/linux/basics/intro/wsl`
* :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/group` (Linux Filesystem)
* The ``shutil`` Module
* Exercise: Like
  :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/group`,
  only in Python
* ``os.path``: https://docs.python.org/3/library/os.path.html
* ``pathlib``: https://docs.python.org/3/library/pathlib.html
* ``os.walk()``

Agenda (Old Version)
--------------------

The Language Fundamentals
.........................

(From :doc:`/trainings/material/soup/python/basics/group`)

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0125_running/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* Exercises

  * :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
  * :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
  * :doc:`/trainings/material/soup/python/exercises/legacy/max_numbers`
  * :doc:`/trainings/material/soup/python/exercises/legacy/dict_keyerror`

* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`

* Exercises

  * :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`

* Exercises

  * :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness`
  * :doc:`/trainings/material/soup/python/exercises/legacy/uniq_plain`


* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`

* Exercises

  * :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`

* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0310_strings_formatting/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0330_strings_encoding/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

* Exercises

  * :doc:`/trainings/material/soup/python/exercises/legacy/wc`
  * :doc:`/trainings/material/soup/python/exercises/legacy/passwd`

* :doc:`/trainings/material/soup/python/basics/python_1000_function_objects/topic`

Exercise Series: CSV, JSON
..........................

* :doc:`/trainings/material/soup/python/misc/csv/topic`

* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`
* :doc:`/trainings/material/soup/python/exercises/userdb/userdb_csv`
* :doc:`/trainings/material/soup/python/exercises/userdb/user_json`

More Language Features
......................

Decorators
``````````

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

(More About) Exception Handling, Modules, OO
````````````````````````````````````````````

* :doc:`/trainings/material/soup/python/advanced/exceptions`
* :doc:`/trainings/material/soup/python/advanced/modules`
* :doc:`/trainings/material/soup/python/advanced/oo/group`

And Most Important: ``exec`` And ``yield``
``````````````````````````````````````````

* :doc:`/trainings/material/soup/python/advanced/exec/topic`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/topic`

Databases
.........
  
* :doc:`/trainings/material/soup/python/misc/db/dbapi2`
* :doc:`/trainings/material/soup/python/exercises/csv/csv-db`
