.. include:: <mmlalias.txt>

.. ot-topic:: c.program_flow.statements_and_blocks
   :dependencies: c.types_operators_expressions.precedence_and_order_of_evaluation


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
