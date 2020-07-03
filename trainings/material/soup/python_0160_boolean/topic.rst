.. include:: <mmlalias.txt>

Boolean
=======

.. contents::
   :local:

.. jf-topic:: python.python_0160_boolean
   :dependencies: python.python_0150_datatypes_overview

Boolean Values
--------------

**Boolean**: the last of the simple ones

.. list-table::
   :align: left

   * - ::

          >>> 1 < 2
	  True
	  >>> 'X' == 'U'
	  False

     - - Values ``True`` and ``False``
       - Result of comparison operators
       - Used with control flow statements (``if``, ``while``)
       - |longrightarrow| later

Boolean Operators
-----------------

**Usual operators** ...

* ``L and R``: ``True`` if both ``L`` and ``R`` evaluate to ``True``
* ``L or R``: ``True`` if ``L`` or ``R`` evaluate to ``True``
* ``not X``: ``True`` if ``X`` evaluates to ``False``

**Short circuit evaluation:** operands are only evaluated until the
expression's value is clear

* ``L and R``: if ``L`` is ``False``, then the expression cannot
  become ``True`` anymore |longrightarrow| ``R`` not evaluated
* ``L or R``: if ``L`` is ``True``, ...
* |longrightarrow| important when ``L``, ``R`` are functions with
  *side effects*
