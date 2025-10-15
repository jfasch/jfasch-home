.. include:: <mmlalias.txt>


Python (2025-10-13 - 2025-10-15)
================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda

.. sidebar::

   **Github**

   * https://github.com/jfasch/2025-10-13

   **Material**

   * :doc:`/trainings/material/soup/python/index`

   **Original Agenda**

   * :doc:`agenda`

Setup
-----

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/misc/vscode`

Day 1
-----

Datatypes
.........

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0125_running/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`

Exercises
`````````

* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`
* :doc:`/trainings/material/soup/python/exercises/legacy/dict_keyerror`

More About Datatypes
....................

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`

Control Flow, Sequences, *Iteration*
....................................

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`

Exercises
`````````

* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/exercises/legacy/for_primeness`

Day 2
-----

Cleanup Mess From Yesterday
...........................

* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`
* :doc:`/trainings/material/soup/python/advanced/iteration-generation/python_1010_generators_yield/fibonacci-generator`

Functions
.........

* :doc:`/trainings/material/soup/python/basics/python_0270_functions/slideshow`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/screenplay-scoping`

Exercises
`````````

* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function`

File IO, Encoding
.................

* :doc:`/trainings/material/soup/python/misc/encoding/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

Exercises
`````````

* :doc:`/trainings/material/soup/python/exercises/legacy/distill`

Modules
.......

* :doc:`/trainings/material/soup/python/advanced/modules`

Afternoon Hacking
.................

From :doc:`/trainings/material/soup/python/exercises/userdb-2/index`:

* :doc:`/trainings/material/soup/python/exercises/userdb-2/read-csv-dicts`
* :doc:`/trainings/material/soup/python/exercises/userdb-2/write-json-dicts`
* :doc:`/trainings/material/soup/python/exercises/userdb-2/csv2json`

What A ``class`` Can Do
.......................

From :doc:`/trainings/material/soup/python/advanced/oo/index`

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`

Day 3
-----

Morning Wakeup (At 7am |:face_with_raised_eyebrow:|)
....................................................

A Case For Duck Typing
``````````````````````

* Classes everywhere

  * Functions are *callable*: ``f.__call__()``
  * Generators

    .. code-block:: console

       >>> x = g()
       >>> type(x)
       <class 'generator'>

    * *Iterable*: ``__iter__()`` (and ``__next__()``, on the iterator)

  * Classes/types are *callable*: ``Person.__call__()``
    |longrightarrow| instantiation of a type
  * Modules

    .. code-block:: python

       >>> import sys
       >>> type(sys)
       <class 'module'>

* And inheritance?

  * File-like?
  * Callable?
  * Iterable?

Context Managers (``with``)
```````````````````````````

We've been using the ``with`` statement lately for file I/O. Lets have
a quick look at what that is ...

* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

OO, Continued (And Excpetions)
..............................

* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Exception are classes too, and there is an entire hierarchy starting
at ``BaseException``.

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`

Exercises
`````````

Lets use classes in our exercise project.

* :doc:`/trainings/material/soup/python/exercises/userdb-2/read-csv-objs`
* :doc:`/trainings/material/soup/python/exercises/userdb-2/write-json-objs`
* :doc:`/trainings/material/soup/python/exercises/userdb-2/csv2json-modern`

Random Cool Things
..................

Closures, Decorators, ...
`````````````````````````

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Standard Library Tour
.....................

* :doc:`/trainings/material/soup/python/drafts/argparse/topic`
* `collections
  <https://docs.python.org/3/library/collections.html>`__
* `csv <https://docs.python.org/3/library/csv.html>`__
* `datetime
  <https://docs.python.org/3/library/datetime.html>`__
* `html <https://docs.python.org/3/library/html.html>`__
* `itertools <https://docs.python.org/3/library/itertools.html>`__
* `json <https://docs.python.org/3/library/json.html>`__
* `logging <https://docs.python.org/3/library/logging.html>`__
* `multiprocessing
  <https://docs.python.org/3/library/multiprocessing.html>`__
* `shutil <https://docs.python.org/3/library/shutil.html>`__
* `subprocess <https://docs.python.org/3/library/subprocess.html>`__
* `tarfile <https://docs.python.org/3/library/tarfile.html>`__
* `threading
  <https://docs.python.org/3/library/threading.html#module-threading>`__
* `zipfile <https://docs.python.org/3/library/zipfile.html>`__
