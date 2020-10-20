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

Log
---

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
