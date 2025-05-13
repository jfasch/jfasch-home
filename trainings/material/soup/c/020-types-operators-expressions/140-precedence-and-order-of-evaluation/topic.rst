.. include:: <mmlalias.txt>


Precedence, Associativity
=========================

Summary: Operators
------------------

**Operators seen thus far**
  
* Arithmetic (unary and binary)
* Comparison
* Boolean
* Bitwise
* Assignment (combined)
* Conditional expression

Operators: Precedence und Associativity (1)
-------------------------------------------

**Operator Table**

* Ordered by precedence (strongest binding first)
* Left- or right associativity at equal precedence

**Attention**

* Precedence und associativity often not intuitive

  * E.g.: ``x | y < z`` is evaluated as ``x | (y < z)``

* |longrightarrow| difficult to comprehend and remember
* *Use braces to make precedence explicit*
* |longrightarrow| for yourself and for your successor

Operators: Precedence und Associativity (2)
-------------------------------------------

.. list-table::
   :align: left
   :header-rows: 1
   :stub-columns: 1

   * *
     * Operator
     * Associativity
   * * highest
     * ``()``, ``[]``, ``->``, ``.``
     * left
   * *
     * ``!``, ``~``, ``++``, ``--``, ``+``, ``-``, ``*``, ``&``, ``(type)`` (cast), ``sizeof``
     * right (unary operators)
   * *
     * ``*``, ``/``, ``%``
     * left
   * *
     * ``+``, ``-``
     * left
   * * 
     * ``<<``, ``>>``
     * left
   * * 
     * ``<``, ``<=``, ``>``, ``>=``
     * left
   * * 
     * ``==``, ``!=``
     * left
   * * 
     * ``&``
     * left
   * * 
     * ``^``
     * left
   * *
     * ``|``
     * left
   * *
     * ``&&``
     * left
   * *
     * ``||``
     * left
   * *
     * ``?:``
     * right
   * *
     * ``=``, ``+=``, ``-=``, ``*=``, ``/=``, ``%=``, ``&=``, ``^=``, ``|=``, ``<<=``, ``>>=``
     * right
   * * lowest
     * ``,``
     * left

More Warnings
-------------

**The order in which operands are evaluated is unspecified (compiler
dependent)**

.. code-block:: c

   x = f() + g(); /* DANGER! */

**The order in which function parameters are evaluated is unspecified
(compiler dependent)**

.. code-block:: c

   f(++i, i); /* DANGER! */
   a[i] = i++; /* MORE DANGER */
