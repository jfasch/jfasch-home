.. include:: <mmlalias.txt>

Python Basics (23.11.2020 - 25.11.2020)
=======================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Start**

   Monday 23.11.2020, 9:00

   **Official Description**

   :doc:`/trainings/material/soup/python/basics/group`

   **Github Repo**

   Outcome visible `here <https://github.com/jfasch/2020-11-23>`__

   **Material**

   :doc:`/trainings/material/soup/python/group`

Preparation
-----------

Workspace Setup
...............

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/misc/vscode`

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

Log
---

Day 1
.....

Slides through to #77 "References, (Im)Mutability

Day 2
.....

* Early morning wakeup

  * ``for``, ``range``, and iteration in general
  * *Context*: variables live in global or local context. Contexts are
    dictionaries, and variable names are the keys in those
    dictionaries. Short demo of ``exec()``.

* Functions
* Exercises: Lists, Loops, Functions. TODO: give links to source on
  github.
* More on Lists, Dictionaries, Sets
* File IO (reading)

Day 3
.....

Starting with a text file like below, apply "transformations" of some
sort.

.. code-block:: console
   :caption: Initial File Content

   Patrick:13.06.1996:Wagna
   Gernot:21.01.1982:Graz
   Joerg:19.06.1966:Graz

Exercise: JSON
``````````````

From the above file, write a program that creates a JSON file that
contains the same data as a list of dictionaries:

.. code-block::

   [
      {
         "name": "Patrick",
	 "birthday": "13.06.1996",
	 "birthplace": "Wagna"
      },
      ...
   ]

The program will be invoked as follows:

.. code-block:: console

   $ py txt2json.py <input-file> <output-file>

Links
-----

* File IO: https://www.youtube.com/watch?v=Uh2ebFW8OYM
* :doc:`Data science </trainings/material/soup/python/misc/ai/group>`
* jjj exceptions corey schaefer
* jjj slice corey schaefer
* jjj KI
