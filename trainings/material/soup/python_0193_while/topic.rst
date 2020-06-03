.. include:: <mmlalias.txt>

Python: ``while`` Loops
=======================

.. contents::
   :local:

.. jf-topic:: python_0193_while
   :dependencies: python_0160_boolean

Looping Constructs
------------------

**Program flow is rarely linear** ...

* Branches |longrightarrow| ``if/elif/else``
* Repeated execution |longrightarrow| *loops*
* Python has only two looping constructs
* ``while``

  * Handcrafted *loop condition*
  * |longrightarrow| very verbose coding
  * Most general looping construct

* ``for``

  * *iteration* over something sequencish
  * Iteration ... generators ... ``yield`` ... outright genius!
  * |longrightarrow| later

``while`` Loops
---------------

**General form of a ``while`` loop** ...

.. code-block:: python

   while condition:
       statements

* *condition* is a boolean expression
* *statements* is an indented block of ... well
    ... statements
* Block is executed while *condition* holds

**Example: sum of numbers 1..100**

.. code-block:: python

   sum = 0
   i = 1
   while i <= 100:
       sum += i
       i += 1

``break`` and ``continue``
--------------------------

**Fine grained loop control** ...

* ``break`` ends the loop
* ``continue`` ends the current loop and continues with the next -
  evaluating the condition

.. code-block:: python

   while True:
       line = sys.stdin.readline()
       for c in line: print(c, ord(c))
       if len(line) == 0:
           # eof seen
           break
       if line.strip() == '':
           # ignore empty lines
           continue
   
       # ... do something ...

Esoteric Feature: ``while/else``
--------------------------------

**Loops can have an "else" clause**

* Entered when loop terminates *naturally*
* ... *not* terminated by a ``break``
* Natural ``while`` loop termination: loop condition evaluates to
  ``False``

.. code-block:: python

   i = 0
   while i < 100:
       i += 1
       number = random.randrange(0,1001)
       if number == 42:
           break
   else:
       print('no answer found')
