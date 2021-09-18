.. include:: <mmlalias.txt>

.. ot-topic:: c.types_operators_expressions.conditional_expressions
   :dependencies: c.types_operators_expressions.assignment_operators_and_expressions


``?:`` - Conditional Expression
===============================

``?:`` - Conditional Expression (1)
-----------------------------------

**The long way**

.. code-block:: c

   int max(int a, int b)
   {
       int z;
   
       if (a > b)
           z = a;
       else
           z = b;
       return z;
   }

``?:`` - Conditional Expression (2)
-----------------------------------

**The short way**

.. code-block:: c

   int max(int a, int b)
   {
       return (a > b)? a: b;
   }

* Saving space
* Usable as expression
