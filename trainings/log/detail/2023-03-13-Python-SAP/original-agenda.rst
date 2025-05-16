Original Agenda: Python For SAP Developers (2023-03-13 - 2023-03-15)
====================================================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Start**

   Lets start at 9AM on Monday, and see how we proceed on Tuesday and
   Wednesday.

   **Material**

   * :doc:`/trainings/material/soup/python/index`

Agenda (i.e., a basis for further discussion) for a three day Python
training. Exercises will be woven in on demand (see :doc:`here
</trainings/material/soup/python/exercises/index>`).

Day 1: Basics
-------------

Goal: gain a basic understanding of Python: variables, datatypes, some
language internals (good to know if one wants to do more).

Setup
.....

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/misc/vscode`
* `Jupyter Notebook <https://jupyter.org/>`__ Intro

Datatypes
.........

An overview of the language, how variables are used, and which primary
datatypes there are.

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0125_running/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0139_commandline_argv/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`

Control Flow, Sequences, *Iteration*
....................................

Basic branching and looping. Iteration (via the ``for`` loop) is an
important topic in Python, which is why we dedicate some time to it.

* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`

More Datatypes
..............

There is more to say about datatypes than what has already been said
(there is always more to everything in Python). What's *mutable*,
va. *immutable*, and what are the consequences? How can we save
another three lines of code? What's *Pythonic*?

* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0250_refs_flat_deep_copy/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`
* :doc:`/trainings/material/soup/python/basics/python_0300_strings/topic`
* :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`
* :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`
* :doc:`/trainings/material/soup/python/basics/python_0450_dictionaries/topic`
* :doc:`/trainings/material/soup/python/basics/python_0460_sets/topic`
* :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`

Day 2: Outlook Into Advanced Python
-----------------------------------

Goal: there's always more. OO isn't necessary, for example,
nonetheless Python is strongly object oriented *internally*
[#oo-aint-overengineering]_. Exception handling isn't necessary either
(one can always let exceptions pass by and terminate the
program). Knowing what *decorators* are isn't necessary either, much
like the *iterator protocol*, or *context managers*.

If you want to do more (probably with less code), you'll want to know
more; on day 2 we take a look into some topics that are optional, but
good to at least know the basics of.

OO Introduction
...............

Python is strongly object oriented internally - even an ``int`` is an
*object of class int*, for example. It does not impose OO knowledge on
its users though; nevertheless knowing a bit of it cannot hurt.
  
* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`

Exception Handling
..................

Error handling is commonly done using *exceptions* - a construct that
lets you focus your code on the sunny case, and do clumsy error
handling in a separate section of the code.

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`

Context Managers (Automatic Cleanup)
....................................

Much like error handling, resource cleanup tends to become
clumsy. Context managers are a way to bring more structure to that
part of a program.

* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

Iteration, Generators, Comprehensions
.....................................

Iterating over large sets of data - while at the same time saving
resources - is one of the absolute strengths of Python. Lets dive a
bit deeper into what a ``for`` loop actually is.

* :doc:`/trainings/material/soup/python/advanced/iteration-generation/topic`
* :doc:`/trainings/material/soup/python/advanced/comprehensions/topic`

Decorators, and Related Topics
..............................

It might not be immediately obvious what a decorator is, and what
benefits it can bring. Lets have a look into that part of the
language. On the way, we'll have a look into how :doc:`parameter
passing </trainings/material/soup/python/advanced/starargs/topic>`
works, and what a :doc:`closure
</trainings/material/soup/python/advanced/closures/topic>` is.

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
* :doc:`/trainings/material/soup/python/advanced/closures/topic`
* :doc:`/trainings/material/soup/python/advanced/decorators/topic`

Day 3: Domain Specifics
-----------------------

That day is dedicated to solving domain specific problems:
implementing a SAP data pipeline in Python.

Pandas
......

From :doc:`/trainings/material/soup/python/misc/pandas/index` ...

* :doc:`/trainings/material/soup/python/misc/pandas/basics`
* :doc:`/trainings/material/soup/python/misc/pandas/iloc`
* :doc:`/trainings/material/soup/python/misc/pandas/loc`
* :doc:`/trainings/material/soup/python/misc/pandas/indexes`
* :doc:`/trainings/material/soup/python/misc/pandas/filters`
* :doc:`/trainings/material/soup/python/misc/pandas/mod_col`
* :doc:`/trainings/material/soup/python/misc/pandas/add_row`

NumPy
.....

* `NumPy <https://numpy.org/>`__ overview

Unit Testing
............
  
* :doc:`Unit testing
  </trainings/material/soup/python/swdev/pytest/intro>`


.. rubric:: Footnotes

.. [#oo-aint-overengineering] OO is often associated with
                              overengineering. Let's not go in that
                              direction.
