.. include:: <mmlalias.txt>


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
