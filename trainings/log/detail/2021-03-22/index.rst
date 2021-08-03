Python Basic and Advanced (22.3.2021 - 25.3.2021)
=================================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Material**

   * PDF Slides (:download:`Download
     </trainings/material/pdf/300-python.pdf>`)
   * :doc:`OpenTraining </about/site/opentraining/index>` Topics, :doc:`/trainings/material/soup/python/index`

   **Source Code**

   `See Github <https://github.com/jfasch/2021-03-22.1>`__

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
* :doc:`/trainings/material/soup/python/exercises/python_0190_exercises/exercise_max_numbers`

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
  </trainings/material/soup/python/exercises/python_0165_exercises/exercise_cmdline_digit>`

  .. literalinclude:: code/digit.py
     :caption: :download:`code/digit.py`
     :language: python

* ``while``
* :doc:`Exercise: primeness (using while)
  </trainings/material/soup/python/exercises/python_0195_exercises/exercise_while_primeness>`

  .. literalinclude:: code/prime-while.py
     :caption: :download:`code/prime-while.py`
     :language: python

* ``for``, ``range()``
* :doc:`Exercise: primeness (using for)
  </trainings/material/soup/python/exercises/python_0230_exercises/exercise_for_primeness>`

  .. literalinclude:: code/prime-for.py
     :caption: :download:`code/prime-for.py`
     :language: python

* Functions
* :doc:`Exercise: primeness (function)
  </trainings/material/soup/python/exercises/python_0275_exercises/exercise_primeness_function>`

  .. literalinclude:: code/prime-function.py
     :caption: :download:`code/prime-function.py`
     :language: python

* :doc:`Exercise: uniq function
  </trainings/material/soup/python/exercises/python_0275_exercises/exercise_misc>`

  .. literalinclude:: code/uniq.py
     :caption: :download:`code/uniq.py`
     :language: python

* Large group exercise (extending until course finish). Something with
  CSV files. File IO for a purpose.

Day 3
.....

Cold start in the morning:

* ``uniq()`` transformed into *generator*
* ``with``
* ``is``

Continue with the group exercise. Moved the code over to Github last
evening, starting with a short `Git intro
<https://www.youtube.com/watch?v=HVsySz-h9r4>`__.

* Using ``csv.DictReader``; see `here
  <https://docs.python.org/3/library/csv.html#csv.DictReader>`__
* Group exercise on `Github
  <https://github.com/jfasch/2021-03-22.1>`__

Day 4
.....



* Use ``collections.namedtuple`` for our ``dict`` objects that we use
  as *records*.
* Test driven development
* OO
* :doc:`/trainings/material/soup/python/draft/mqtt/topic`

Links
-----

* :doc:`Python/NumPy course by myself, including links
  <../2019-11-12/index>`
* `SciPy: Interpolation
  <https://docs.scipy.org/doc/scipy/reference/interpolate.html>`__
* `Pandas: read_excel()
  <https://pandas.pydata.org/docs/reference/api/pandas.read_excel.html>`__. Makes
  sense to look into: the ``converters`` parameter, for example, looks
  like it would offer a cool opportunity to hook in our dumb
  ``str("123,456")`` (note the *comma*) -> ``float(123.456)``
  conversions.
* :doc:`Virtual Environments
  </trainings/material/soup/python/draft/venv/topic>`, and
  :doc:`Python Package Index (PyPI)
  </trainings/material/soup/python/draft/pip/topic>`

(Tutorial) Videos
-----------------

* .. raw:: html

     <iframe width="560" 
             height="315" 
   	     src="https://www.youtube.com/embed/HVsySz-h9r4" 
   	     title="YouTube video player" 
   	     frameborder="0" 
   	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
   	     allowfullscreen>
     </iframe>

* .. raw:: html

     <iframe width="560" 
             height="315" 
   	     src="https://www.youtube.com/embed/OSGv2VnC0go" 
   	     title="YouTube video player" 
   	     frameborder="0" 
   	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
   	     allowfullscreen>
     </iframe>
   
* .. raw:: html

     <iframe width="560" 
             height="315" 
   	     src="https://www.youtube.com/embed/C-gEQdGVXbk" 
   	     title="YouTube video player" 
   	     frameborder="0" 
   	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
   	     allowfullscreen>
     </iframe>

* .. raw:: html

     <iframe width="560" 
             height="315" 
   	     src="https://www.youtube.com/embed/zdJEYhA2AZQ" 
   	     title="YouTube video player" 
   	     frameborder="0" 
   	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
   	     allowfullscreen>
     </iframe>

* .. raw:: html

     <iframe width="560" 
             height="315" 
   	     src="https://www.youtube.com/embed/jTYiNjvnHZY" 
   	     title="YouTube video player" 
   	     frameborder="0" 
   	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
   	     allowfullscreen>
     </iframe>

* .. raw:: html

     <iframe width="560" 
             height="315" 
   	     src="https://www.youtube.com/embed/6tNS--WetLI" 
   	     title="YouTube video player" 
   	     frameborder="0" 
   	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
   	     allowfullscreen>
     </iframe>

* .. raw:: html

     <iframe width="560" 
             height="315" 
   	     src="https://www.youtube.com/embed/K8L6KVGG-7o" 
   	     title="YouTube video player" 
   	     frameborder="0" 
   	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
   	     allowfullscreen>
     </iframe>
