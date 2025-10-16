.. include:: <mmlalias.txt>


``while`` Loops
===============

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

.. note:: 

   **Pythonicity**

   This example is rather contrived. One would rather use the built-in
   ``sum()`` function (`documentation here
   <https://docs.python.org/3/library/functions.html#sum>`__),
   combined with the ``range()`` function (`documentation here
   <https://docs.python.org/3/library/stdtypes.html#typesseq-range>`__)
   to do the same.

   .. code-block:: python
		   
      sum(range(1,101))

``break`` and ``continue``
--------------------------

**Fine grained loop control** ...

* ``break`` ends the loop
* ``continue`` ends the current loop and continues with the next -
  evaluating the condition

*For example*: roll dice, until it shows six eyes ...

.. literalinclude:: dice-infinite.py
   :language: python
   :caption: :download:`dice-infinite.py`

Esoteric Feature: ``while/else``
--------------------------------

**Loops can have an "else" clause**

* Entered when loop terminates *naturally*
* ... *not* terminated by a ``break``
* Natural ``while`` loop termination: loop condition evaluates to
  ``False``

*For example*: roll dice six times. Win when it shows six eyes at
least once, lose when not.

.. list-table::
   :align: left
   :header-rows: 1

   * * Non-pythonic (using a flag)
     * Pythonic (``else`` on ``while``)
   * * .. literalinclude:: dice-sixtimes-flag.py
          :language: python
	  :caption: :download:`dice-sixtimes-flag.py`
     * .. literalinclude:: dice-sixtimes-else.py
          :language: python
	  :caption: :download:`dice-sixtimes-else.py`
