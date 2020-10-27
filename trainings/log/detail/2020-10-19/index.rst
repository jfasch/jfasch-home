.. include:: <mmlalias.txt>

Python Basic and Advanced (19.10.2020 - 22.10.2020)
===================================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Start**

   Monday 19.10.2020, 9:00

   **Official Description**

   :doc:`/trainings/repertoire/python-basics`

   **Material**

   .. csv-table::

      PDF Slides, :download:`Python </trainings/material/pdf/300-python.pdf>`
      :doc:`OpenTraining </about/site/opentraining/index>` Topics, :doc:`/trainings/material/soup/python/python`

Preparation
-----------

Workspace Setup
...............

* :doc:`/trainings/material/soup/draft/installation`
* :doc:`/trainings/material/soup/draft/vscode`

Agenda
------

This is a preliminary list of *very basic* topics. The *advanced* part
of the training is under discussion. Please send feedback/suggestions to
training@faschingbauer.co.at.

* Variables and Types

  * Numerical types such as integer, floating point, boolean
  * Sequential types such as list, tuple, string
  * Indexing, slicing and other operations on sequential types
  * Associative types such as dictionaries and sets
  * Mutable versus immutable

* Control Flow

  * ``if``
  * ``while``
  * ``for``: more about *iteration*

* Functions

  * Why and how
  * Parameters passing: positional versus keyword parameters, default
    parameters
  * Return values

* Exception Handling

  * The exception hierarchy in the standard library
  * How to define custom exception classes
  * Raising exceptions, and reacting on them

* Strings — Advanced Features

  * String methods
  * Formatting
  * Encoding: what it is, and how Python solves encoding problems

* File I/O

  * Opening and/or creating files
  * Reading and writing

* Advanced Topics

  * Database Programming
  * Web Programming with Flask

Additional Topics, brought in by Thomas
.......................................

* Programmverweise mit import XY und Aufruf von XY.ZAB
* JSON Handling
* Exception Handling
* with open(eventCodeFile, 'r') as f:
    definedLISAEvents = json.load(f)['event_ids']
* print (f'bla{variable}blubb'} : was macht das f hier? (habe gesehen, eine verbesserte Stringformatierung in Python3?)
* CTYPES
* Klassen und deren Aufruf im .py Code
* Headerfiles (.h) verwenden
* from lib import *
* .lst Files (Listen?)
* Socket module
* Shell script inclusion
* Code Snippet: "@cs.CALLBACKFUNC" was macht das?

Outcome
-------

Notebook
........

.. toctree::

   Notebook

Links

* :doc:`Link to entire notebook <Notebook>`
* Download notebook: :download:`Notebook.ipynb`

Day 1
.....

* :doc:`/trainings/material/soup/python/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/python_0190_exercises/topic`
* :doc:`/trainings/material/soup/python/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/python_0195_exercises/topic`
* :doc:`/trainings/material/soup/python/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/python_0270_functions/topic`
* :doc:`/trainings/material/soup/python/python_0275_exercises/topic`:
  exercise 1 "Prime"

Day 2
.....

* Observation by Thomas: "as opposed to C# I need to define a function
  before I can use it"

  Longish answer ...

  * Variables are *names* that refer to objects
  * ``def`` is only a *statement*: creates a *function* object, and
    points a *name* (the function name to it)
  * Cannot use a *name* that is not there
  * Show how to delete (and resurrect) the ``int`` type

* :doc:`/trainings/material/soup/python/python_0275_exercises/topic`

  * Exercise 2: ``uniq()``. 

    * TODO: Screenplay

      * Complicated iteration over outputsequence, only to determine
        membership. First with a flag, then with an ``else`` clause.
      * ``in`` operator on outputsequence
      * Performance: using a ``set`` for have-ness

  * Exercise 3: ``join()``. Sketch multiple ways to solve the problem.

    * ``join-manual-index.py``
    * ``join-manual-index-range.py``
    * ``join-slicing.py``
    * ``join-enumerate.py``

* ``for`` loops

  * :doc:`/trainings/material/soup/python/python_0220_for/topic`
  * :doc:`/trainings/material/soup/python/python_0225_range/topic`,
    and the *iterator protocol*

* Generators:
  :doc:`/trainings/material/soup/python/python_1010_generators_yield/topic`

  * TODO: reference ``fibo-*.py`` files

Day 3
.....

* Comprehension expressions

  * List comprehension, from
    :doc:`/trainings/material/soup/python/python_0400_lists/topic` (live hacking `here <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/list-comprehension.py>`__)
  * Generator expression (live hacking `here <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/generator-expression.py>`__
  * Dictionary comprehension (live hacking `here <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/dictionary-comprehension.py>`__)

* File IO

  * :doc:`/trainings/material/soup/python/python_0500_files/topic`
  * The ``with`` statement: *context managers*

* Group exercise

  A CAN bus log is gathered by software running on a device. That log
  contains CAN frames, basically. It has CSV format, suitable for
  analysis with Excel. One wants to automate the process of log
  analysis, at least to a certain extent.

  * Start with the ``csv`` module: read the log file, print the
    content of each row. *Iteration*, basically, and some *tuple
    unpacking*.
  * Sideway: *encoding*. The logfile is in ``cp1252`` format.

Day 4
.....

* *Plan*

  * unify
  * Format a message list to JSON
  * Cut out a time interval from a larger list
  * Show how CAN bus programming is done in Linux and Python, using
    the ``socket`` module.
  * Explain ``**kwargs``, see :doc:`here
    </trainings/material/soup/draft/starargs/topic>` for more. TODO:
    link to ``DictReader`` example in exercises.

* Class ``Message`` to hold rows
* Function to read CSV into a list of ``Message`` objects
* Modularization: message, reader, and one main program that prints
  out messages




Links
-----

https://www.youtube.com/watch?reload=9&v=EiOglTERPEo
https://www.youtube.com/watch?v=OSGv2VnC0go


CAN slides
