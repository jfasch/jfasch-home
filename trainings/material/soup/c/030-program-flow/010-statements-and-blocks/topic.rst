.. include:: <mmlalias.txt>


Statements and Blocks
=====================

Statement vs. Block
-------------------

**Single statements terminated with** "``;``"

.. code-block:: c

   a = 1;
   f(a);

**Block ("compound statement") is a group of statements**
|longrightarrow| syntactically equivalent to a single statement
  
.. code-block:: c

   {
       a = 1;
       f(a);
   }

*Attention*: no "``;``"
