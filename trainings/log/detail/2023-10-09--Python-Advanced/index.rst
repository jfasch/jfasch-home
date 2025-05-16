.. include:: <mmlalias.txt>


Python Advanced (2023-10-09 - 2023-10-11)
=========================================

.. contents::
   :local:

.. toctree::
   :hidden:

   notebook-wrapper

.. sidebar::

   **Predecessor Courses**

   This course is a followup to two "Python Basics" courses held
   before summer 2023,

   * :doc:`../2023-05-15--Python-Basics/index`
   * :doc:`../2023-06-20--Python-Basics/index`

   **Jupyter Notebook**

   * Structure: :doc:`notebook-wrapper`
   * Entire notebook: :doc:`notebook`
   * Download notebook: :download:`notebook.ipynb`

   **Github Repository (private to course participants)**

   * `https://github.com/jfasch/2023-10-09
     <https://github.com/jfasch/2023-10-09>`__

   **Material**

   * :doc:`/trainings/material/soup/python/index`

Recap Of Python Basics Course (Before Summer)
---------------------------------------------

Look through code in
`https://github.com/jfasch/2023-05-15/tree/main/livehacking/userdb
<https://github.com/jfasch/2023-05-15/tree/main/livehacking/userdb>`__

Project Management: Requirements, Sandboxing, Testing
-----------------------------------------------------

* :doc:`/trainings/material/soup/python/swdev/pip/slides`
* :doc:`/trainings/material/soup/python/swdev/pip/screenplay`
* :doc:`/trainings/material/soup/python/swdev/venv/slides`
* :doc:`/trainings/material/soup/python/swdev/venv/screenplay`
* :doc:`/trainings/material/soup/python/swdev/pytest/intro`

Exercises
.........

* Clone project: `https://github.com/jfasch/2023-10-09
  <https://github.com/jfasch/2023-10-09>`__
* Create virtual environment based upon ``requirements.txt``
* Become acquainted with Test Driven Development:
  :doc:`/trainings/material/soup/python/exercises/userdb/user_json`

Object Oriented Programming
---------------------------

Classes: Basics
...............

From :doc:`/trainings/material/soup/python/advanced/oo/index`

* :doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/constructor/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/namedtuple/topic`

Exercise
........

* Create a simple class:
  :doc:`/trainings/material/soup/python/exercises/userdb/user-class-person`

Classes: More
.............

* :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/properties/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/methods/topic`

Into The Wild: Group Project Kickoff
------------------------------------

With a basic understanding of code structuring (classes and modules -
and TDD), let's hack something. Idea: a "data logger" application.

* Configurable set of sensors
* Polymorphic data sinks
* Acquisition engine in the middle
* CSV log format initially; if there's time, we could add more (XML?
  :doc:`MQTT? </trainings/material/soup/python/misc/mqtt/topic>`)

Spoiler: Group Project Outcome
..............................

This is what became of it, at the end of day 3:

* A set of sensors, arranged in a class hierarchy
* A set of data loggers, arranged in a class hierarchy
* A set of error handlers, arranged in a class hierarchy
* An acquisition loop class which uses sensors, loggers, and error
  handlers

.. list-table::
   :align: left
   :widths: auto

   * * .. image:: acquisition-loop.png
          :scale: 30%
     * .. image:: hierarchies.png
          :scale: 30%

OO Design: Duck Typing, Inheritance, And Abstract Base Classes
--------------------------------------------------------------

* :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`
* :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

Exceptions, ``with``
--------------------

* :doc:`/trainings/material/soup/python/advanced/exceptions/topic`
* :doc:`/trainings/material/soup/python/advanced/context-mgr/topic`

More About Functions
--------------------

* :doc:`/trainings/material/soup/python/advanced/starargs/topic`
