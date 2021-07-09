.. include:: <mmlalias.txt>

.. jf-topic:: c.types_operators_expressions.arithmetic_operators
   :dependencies: c.types_operators_expressions.declarations


Arithmetic Operators
====================

Arithmetic Operators (1)
------------------------

**Arithmetic operators and their operands**

.. list-table::
   :align: left
   :header-rows: 1

   * * Operator
     * Meaning
     * Operand type
   * * ``*``
     * multiplication
     * integer, floatingpoint
   * * ``/``
     * division
     * integer, floatingpoint
   * * ``\%``
     * modulo
     * integer
   * * ``+``
     * addition
     * integer, floatingpoint
   * * ``-``
     * subtraction
     * integer, floatingpoint

.. attention::

   Integer division truncates!

Arithmetic Operators (2)
------------------------

**Precedence rules**

* Multiplication, division, modulo precede addition, subtraction
* Operators with same precedence are associated *from left to right*

.. list-table::
   :align: left

   * * ``30 / 2 + 1``
     * ``(30 / 2) + 1``
     * precedence
   * * ``1 + 30 / 2``
     * ``1 + (30 / 2)``
     * precedence
   * * ``1 - 2 + 3``
     * ``(1 - 2) + 3``
     * left-associative
   * * ``30 / 3 % 2``
     * ``(30 / 3) % 2``
     * left-associative
