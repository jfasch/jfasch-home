.. include:: <mmlalias.txt>


Loops: ``while`` and ``for``
============================

``while``: general purpose loop
-------------------------------

.. code-block:: c

   while (condition is true)
       do something

* Most general looping construct
* Serves all uses
* With a couple of extra variables everything is doable
* ... in many cases complicated though

|longrightarrow| ``for``, ``do - while``
  
From ``while`` to ``for`` (1)
-----------------------------

**Iteration** over sets of elements using ``while``

.. list-table::
   :align: left

   * * **Iteration using** ``while``

       .. code-block:: c

          i = 0;
          sum = 0;
          while (i < 100) {
              sum += i;
              ++i;
          }

     * **Generally**

       .. code-block:: c

	  init-expression
          while (cond-expression) {
              body-statement
              next-expression
          }

From ``while`` to ``for`` (2)
-----------------------------

**The following constructs are equivalent:**

.. code-block:: c

   init-expression
   while (cond-expression) {
       body-statement
       next-expression
   }

.. code-block:: c

   for (init-expression; cond-expression; next-expression)
       body-statement

**Plus:**

* *init-expression*, *cond-expression* and
  *next-expression* are **optional**

``for``, a Little Closer
------------------------

.. code-block:: c

   for (i = 0, sum = 0; i < 100; ++i)
       sum += i;

.. list-table::
   :align: left

   * * *init-expression*
     * ``i = 0, sum = 0``
   * * *cond-expression*
     * ``i < 100``
   * * *next-expression*
     * ``++i``

Comma Operator
--------------

**Comma operator:**

* The *expression* ``expr-1, expr-2`` has the value ``expr-2``
* The *operator* "``,``" is left-associative
* Precedence: lowest precedenceof all operators (see operator table)

.. code-block:: c
  
   value = expr-1, expr-2; /* expr-2 */
   value = expr-1, expr-2, expr-3; /* expr-3 */
   value = 1, 2, 3; /* 3 */

``for``: Infamous Idioms
------------------------

**C is infamous for excessive compactness ...**

**As above, only more compact**

.. code-block:: c

   for (i = 0, sum = 0; i < 100; sum += i++);

**Infinite loop**

.. code-block:: c

   for (;;) {
       do_something();
       sleep(5);
   }

**A crash, in microcontroller terminology**

.. code-block:: c

   for (;;);

