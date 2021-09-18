.. include:: <mmlalias.txt>

.. ot-topic:: c.types_operators_expressions.relational_logical_operators
   :dependencies: c.types_operators_expressions.arithmetic_operators


Relational and Logical Operators
================================

Relational Operators (1)
------------------------

.. list-table::
   :align: left
   :header-rows: 1
  
   * * Operator
     * Meaning
     * Operand type
   * * ``>``
     * greater
     * integer, floatingpoint
   * * ``>=``
     * greater equal
     * integer, floatingpoint
   * * ``<``
     * less
     * integer, floatingpoint
   * * ``<=``
     * less equal
     * integer, floatingpoint
   * * ``==``
     * equal
     * integer, floatingpoint
   * * ``!=``
     * not equal
     * integer, floatingpoint

.. attention::

   ``==`` and ``!=`` is *legal* for floatingpoint numbers, but not
   what you want!

Relational Operators (2)
------------------------

**Precedence rules**

* All relational operators are preceded by arithmetic operators
* ``>``, ``>=``, ``<``, ``<=``
* ``==``, ``!=``

.. note::

   Operators with equal precedence are associated from *left to right*

**So what does that mean?**

.. list-table::
   :align: left

   * * ``3 - 1 == 2``
     * Arithmetic has precedence
   * * ``'X' != 'U' == 1``
     * It is true that 'X' is not 'U'
   * * ``1 == ('X' != 'U')``
     * Same, explicitly precedented
   * * ``3 < 1 == 0 == 1``
     * It is true that 3 is not less than 1
   * * ``0 == 1 < 2``
     * *What?!*

Logical (*Boolean*) Operators
-----------------------------

**Logical expressions**

.. list-table::
   :align: left

   * * ``&&``
     * AND
   * * ``||``
     * OR

**Precedence rules**

* Boolean operators bind less strong than relational and arithmetic operators
* ``&&`` precedes ``||``
* Operators with equal precedence are associated from *left to right*

Boolean Operators: Short-Circuit
--------------------------------

**Short-circuit calculation**
  
* Boolean expressions are only evaluated to the point where their
  truth value is known
* |longrightarrow| Elegant and (for beginners at least) unreadable
  constructs

.. code-block:: c
   :caption: Counting leading blank lines

   int c, num_lf = 0;
   
   while ((c = getchar()) != EOF && c == '\n' && ++num_lf);
