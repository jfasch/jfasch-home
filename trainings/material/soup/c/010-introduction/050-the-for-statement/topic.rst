.. include:: <mmlalias.txt>

.. jf-topic:: c.introduction.for_loop
   :dependencies: c.introduction.exercise_fahrenheit_float



``for`` Loops
=============

``for``: Loop Simplification (1)
--------------------------------

``while`` **loop approach:**

* Fixed number of runs
* Counter is initialized
* Termination condition is evaluated
* Counter is incremented

**This can be done simpler!**

``for``: Loop Simplification (2)
--------------------------------

.. code-block:: c

   for (initialization; condition; step)
       ...

* *initialization* is evaluated exactly once - before entering the loop
* *condition* is evaluated everytime before the loop body is
  entered. *false* |longrightarrow| loop termination
* *step* is evaluated after the loop body, and before the condition
  
*initialization*, *condition* and *step* are regular *statements*

Second Program, revisited
-------------------------

.. literalinclude:: fahrenheit-for.c
   :language: c
   :caption: :download:`fahrenheit-for.c`

* Wherever there can be a variable, there can be an *expression*
* A *block* (``{`` and ``}``) is only necessary when the loop body
  consists of multiple *statements*
* ``5.0/9 * (fahr - 32)`` is ``float`` because ``5.0`` is
