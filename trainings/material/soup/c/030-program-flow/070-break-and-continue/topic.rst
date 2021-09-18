.. include:: <mmlalias.txt>

.. ot-topic:: c.program_flow.break_and_continue
   :dependencies: c.program_flow.loops_do_while


``break`` and ``continue``
==========================

``break`` and ``continue``
--------------------------

**Loop control** apart from the condition

* ``break``: terminates innermost enclosing loop or ``switch``

  * Nesting: outer loop/``switch`` not concerned

* ``continue``: next loop iteration

  * Loop condition is checked
  * ``for``: *next-expression* evaluated

.. code-block:: c

   for (i = 0; i < strlen(input); ++i) {
       if (!isprint(input[i]))
           /* do nothing for nonprintable chars */
           continue;
       error = do_something(input[i]);
       if (error)
           break;
   }
