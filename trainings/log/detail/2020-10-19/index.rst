.. include:: <mmlalias.txt>

Python Basic and Advanced (19.10.2020 - 22.10.2020)
===================================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Start**

   Monday 19.10.2020, 9:00

   **Official Description**

   :doc:`/trainings/repertoire/python/basics`

   **Material**

   .. csv-table::

      PDF Slides, :download:`Python </trainings/material/pdf/300-python.pdf>`
      :doc:`OpenTraining </about/site/opentraining/index>` Topics, :doc:`/trainings/material/soup/python/group`

Preparation
-----------

Workspace Setup
...............

* :doc:`/trainings/material/soup/python/basics/installation`
* :doc:`/trainings/material/soup/python/draft/vscode`

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

* :doc:`/trainings/material/soup/python/basics/python_0110_blahblah/topic`
* :doc:`/trainings/material/soup/python/basics/python_0120_helloworld/topic`
* :doc:`/trainings/material/soup/python/basics/python_0130_syntax_etc/topic`
* :doc:`/trainings/material/soup/python/basics/python_0140_variables/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview/topic`
* :doc:`/trainings/material/soup/python/basics/python_0150_datatypes_overview_compound/topic`
* :doc:`/trainings/material/soup/python/basics/python_0160_boolean/topic`
* :doc:`/trainings/material/soup/python/basics/python_0170_if/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_interactive`
* :doc:`/trainings/material/soup/python/exercises/legacy/mixed_list_executable`
* :doc:`/trainings/material/soup/python/exercises/legacy/dict_keyerror`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`
* :doc:`/trainings/material/soup/python/exercises/legacy/cmdline_digit`
* :doc:`/trainings/material/soup/python/basics/python_0193_while/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/while_primeness`
* :doc:`/trainings/material/soup/python/basics/python_0200_sequential_types/topic`
* :doc:`/trainings/material/soup/python/basics/python_0210_indexing_slicing/topic`
* :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
* :doc:`/trainings/material/soup/python/basics/python_0270_functions/topic`
* :doc:`/trainings/material/soup/python/exercises/legacy/primeness_function`

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

* :doc:`/trainings/material/soup/python/exercises/legacy/uniq_function`

  #. Complicated iteration over outputsequence, only to determine
     membership. First with a flag, then with an ``else`` clause.
  #. ``in`` operator on outputsequence
  #. Performance: using a ``set`` for have-ness

  *End result:*
  `uniq.py <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/uniq.py>`__

  *Generator version (can't resist):* `uniq-generator.py
  <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/uniq-generator.py>`__

* :doc:`/trainings/material/soup/python/exercises/legacy/join_function`

  Sketch multiple ways to solve the problem.

  #. `join-manual-index.py
     <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/join-manual-index.py>`__. Iterate
     over the input list, manually tracking indexes to determine if
     we are at the last element.
  #. `join-manual-index-range.py
     <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/join-manual-index-range.py>`__. Iterate
     over a ``range`` object for index keeping, and use *index based
     iteration* on the input list.
  #. `join-slicing.py
     <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/join-slicing.py>`__. Another
     cumbersome but working approach: cut out ``[1:]`` from the
     input list.
  #. `join-correct-sep.py
     <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/join-correct-sep.py>`__. Add
     separator unconditionally after each element, and take
     correcting action finally.
  #. `join-enumerate.py
     <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/join-enumerate.py>`__:
     use `enumerate()
     <https://docs.python.org/3/library/functions.html#enumerate>`__
     to iterate over the input sequence *and* keep the indexes.

* ``for`` loops

  * :doc:`/trainings/material/soup/python/basics/python_0220_for/topic`
  * :doc:`/trainings/material/soup/python/basics/python_0225_range/topic`,
    and the *iterator protocol*

* Generators:
  :doc:`/trainings/material/soup/python/python_1010_generators_yield/topic`

  #. `fibo-inline.py
     <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/fibo-inline.py>`__. Generate
     Fibonacci numbers in an infinite loop, and print them as we
     go. This is not modular (we're not using a function), but it
     allows for *infinity*.
  #. `fibo-function.py
     <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/fibo-function.py>`__. Externalize
     Fibonacci generation into a function. This is modular, but we
     have to limit the amount of numbers generated (or we will run out
     of memory).
  #. `fibo-generator.py
     <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/fibo-generator.py>`__. Using
     a function (err, a *generator*), *and* have infinity.

Day 3
.....

* Comprehension expressions

  * List comprehension, from
    :doc:`/trainings/material/soup/python/basics/python_0400_lists/topic`. Code:
    `list-comprehension.py
    <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/list-comprehension.py>`__.
  * Generator expression. Code: `generator-expression.py
    <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/generator-expression.py>`__.
  * Dictionary comprehension. Code: `dictionary-comprehension.py
    <https://github.com/jfasch/2020-10-19/blob/main/live-hacking/dictionary-comprehension.py>`__.

* File IO

  * :doc:`/trainings/material/soup/python/basics/python_0500_files/topic`
  * The ``with`` statement: *context managers*

* Group exercise: discussion

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

* Class ``Message`` to hold rows (include ``datetime.datetime``
  conversion). Code: `csvlog/unified/message.py
  <https://github.com/jfasch/2020-10-19/blob/main/csvlog/unified/message.py>`__.
* Function to read CSV into a list of ``Message`` objects. Code:
  `csvlog/unified/csv_Reader.py
  <https://github.com/jfasch/2020-10-19/blob/main/csvlog/unified/csv_Reader.py>`__
* One main program that prints CAN messages. Code:
  `csvlog/unified/print-log.py
  <https://github.com/jfasch/2020-10-19/blob/main/csvlog/unified/print-log.py>`__
* Cut out a time interval from a larger list
* Show how CAN bus programming is done in Linux and Python, using the
  ``socket`` module. 

  * Excerpt from my Grazer Linuxtage 2014 talk: "CAN-Bus mit Linux und
    Python" (:download:`PDF <910-glt-2014.pdf>`, `Youtube Video
    <https://www.youtube.com/watch?v=5XuSr4M9uNI>`__).
  * Code: `csvlog/joerg/can-recv.py
    <https://github.com/jfasch/2020-10-19/blob/main/csvlog/joerg/can-recv.py>`__

Links
-----

Tutorials
.........

* `Transforming Code into Beautiful, Idiomatic Python
  <https://www.youtube.com/watch?v=OSGv2VnC0go>`__. **Raymond
  Hettinger**, emphasizing on his favorite phrase "There must be a
  better way". (Hettinger is a "Python Core Developer".)
* `Modern dictionaries
  <https://www.youtube.com/watch?v=p33CVV29OG8>`__: **Raymond
  Hettinger** again, this time emphasizing on dictionaries, even more
  than I did. (Hehe, I just discovered that he's bringing my quick
  hash table explanation to a conclusive end. Hard stuff for the
  unaware though.)
* `Unit Testing <https://www.youtube.com/watch?v=6tNS--WetLI>`__:
  **Corey Schafer** (he has a number of really good *and* short
  tutorial videos; look out for him as you search).
* `Generators Tutorial
  <https://www.youtube.com/watch?v=bD05uGo_sVI>`__: **Corey Schafer**
  again, this time 11 minutes on generators. (I couldn't resist.)

CAN Bus
.......

* `CAN Utils on Github <https://github.com/linux-can/can-utils>`__
* Grazer Linuxtage 2014: "CAN-Bus mit Linux und Python"

  * :download:`PDF <910-glt-2014.pdf>`
  * `Youtube Video <https://www.youtube.com/watch?v=5XuSr4M9uNI>`__

