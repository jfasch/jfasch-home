Python Basic and Advanced (22.3.2021 - 25.3.2021)
=================================================

.. contents::
   :local:

.. sidebar:: Material

   * PDF Slides (:download:`Download
     </trainings/material/pdf/300-python.pdf>`)

Agenda
------

* Day 1: Programming Basics

  * Variables
  * Control Flow: ``if``, ``while``, ``for``
  * Functions
  * Exercises

* Day 2: Python, Advanced

  * Data Structures: ``list``, ``set``, ``dict``
  * Iteration
  * File I/O (CSV Files?)
  * Exercises

* Day 3: even more advanced

  * Object Oriented Programming
  * Unit Testing
  * Decorators
  * Exercises

* Day 4: Consulting


Jupyter Notebook
----------------

.. sidebar:: Download

   :download:`Notebook.ipynb`

.. toctree::

   Notebook

Log
---

We're lagging behind what's in the agenda, don't want to lose anybody.

Day 1
.....

* Basics from the slides, up until ``if`` (see :doc:`here
  </trainings/material/soup/python/python_0170_if/topic>`)
* :doc:`/trainings/material/soup/python/python_0190_exercises/exercise_max_numbers`

  Solution, doing everything by hand ...

  .. literalinclude:: code/maximum-potschert.py
     :caption: :download:`code/maximum-potschert.py`
     :language: python

  Solution, knowing about the ``map()`` `function
  <https://docs.python.org/3/library/functions.html#map>`__ and the
  ``max()`` `function
  <https://docs.python.org/3/library/functions.html#max>`__
  
  .. literalinclude:: code/maximum-gscheit.py
     :caption: :download:`code/maximum-gscheit.py`
     :language: python

Day 2
.....

* :doc:`Exercise: digit translation
  </trainings/material/soup/python/python_0165_exercises/exercise_cmdline_digit>`

  .. literalinclude:: code/digit.py
     :caption: :download:`code/digit.py`
     :language: python

* ``while``
* :doc:`Exercise: primeness (using while)
  </trainings/material/soup/python/python_0195_exercises/exercise_while_primeness>`

  .. literalinclude:: code/prime-while.py
     :caption: :download:`code/prime-while.py`
     :language: python

* ``for``, ``range()``
* :doc:`Exercise: primeness (using for)
  </trainings/material/soup/python/python_0230_exercises/exercise_for_primeness>`

  .. literalinclude:: code/prime-for.py
     :caption: :download:`code/prime-for.py`
     :language: python

* Functions
* :doc:`Exercise: primeness (function)
  </trainings/material/soup/python/python_0275_exercises/exercise_primeness_function>`

  .. literalinclude:: code/prime-function.py
     :caption: :download:`code/prime-function.py`
     :language: python

* :doc:`Exercise: uniq function
  </trainings/material/soup/python/python_0275_exercises/exercise_misc>`

  .. literalinclude:: code/uniq.py
     :caption: :download:`code/uniq.py`
     :language: python

Day 3
.....

Cold start in the morning:

* ``uniq()`` transformed into *generator*
* ``with``
* ``is``

Links
-----

* :doc:`Python/NumPy Course by myself, including links
  <../2019-11-12/index>`
