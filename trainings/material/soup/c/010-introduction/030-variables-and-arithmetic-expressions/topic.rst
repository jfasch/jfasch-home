.. include:: <mmlalias.txt>

.. jf-topic:: c.introduction.variables_and_arithmetic_expressions
   :dependencies: c.introduction.hello_world


Variables and Arithmetic
========================

My Second Program (1)
---------------------

.. literalinclude:: fahrenheit-while.c
   :caption: :download:`fahrenheit-while.c`

My Second Program (2)
---------------------

.. list-table::

   * * .. code-block:: c

          /* ... */

     * Comment (can span multiple lines)

   * * .. code-block:: c

          int fahr, celsius;

     * * Variable *definition*
       * Must come at the beginning of a *block*

   * * .. code-block:: c

          int lower = 0, upper = 300, step = 20;

     * Variable *definition* and *initialization*

My Second Program (3)
---------------------

.. list-table::

   * * .. code-block:: c

          while (fahr <= upper) {
              ...
          }

     * * **Loop**: "*While condition holds, execute body*"
       * **Condition**: ``fahr`` *is less or equal* ``upper``

   * * .. code-block:: c

          celsius = 5 * (fahr - 32) / 9;

     * Usual arithmetic (*expression*) |longrightarrow| usual operator
       precedence rules

* Careful: *integer division brutally truncates decimal places!*
* More natural but always 0: ``5/9 * (fahr-32)``

My Second Program (4)
---------------------

.. code-block:: c

   printf("%d\t%d\n", fahr, celsius);

* *Formatted output*
* |longrightarrow| number of arguments can vary (?)
* "``%d``" obviously means "integer"
* **Important:** ``printf()`` is not part of the core language, but
  rather an ordinary *library function*
* |longrightarrow| *standard library*

More Datatypes
--------------

.. list-table::

   * * ``int``
     * Integer, nowadays mostly 32 bits wide
   * * ``float``
     * Floating point number, mostly 32 bit
   * * ``char``
     * Single character (one byte, generally)
   * * ``short``
     * Smaller integer
   * * ``double``
     * *double precision* variant of ``float``

* Width and precision of all datatypes is *machine dependent*!
* Compound datatypes: arrays, structures, ... (|longrightarrow| later)


