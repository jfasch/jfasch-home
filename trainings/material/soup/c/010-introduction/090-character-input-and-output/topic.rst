.. include:: <mmlalias.txt>

.. jf-topic:: c.introduction.character_io
   :dependencies: c.introduction.exercise_fahrenheit_cpp


Character I/O
=============

The Outside World
-----------------

``stdio.h``: **functions and constants for I/O**

* Standard input and output
* File I/O
* Formatted
* Buffered

**Most simple ones first:**

.. code-block:: c

   int c;
   c = getchar();
   putchar(c);

``cat`` for the Poor (1)
------------------------

.. literalinclude:: cat-poor.c
   :language: c
   :caption: :download:`cat-poor.c`

``cat`` for the Poor (2)
------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          while (c != EOF)

     * * ``EOF`` - *End-of-File*
       * ``!=`` - *not equal*

**But** ugly code duplication: ``getchar()`` called twice

.. list-table:: 
   :align: left

   * * .. code-block:: c

          while ((c = getchar()) != EOF)
              putchar(c);

     * * An *assignment* is an *expression*
       * |longrightarrow| has a value
       * |longrightarrow| use that as condition
       * Caution: operator precedence, braces!

More Examples ...
-----------------

.. list-table::
   :align: left

   * * .. code-block:: c

          long nc = 0;
          
          while (getchar() != EOF)
              ++nc;

     * **Counting input characters**

       * ``++``: increment operator
       * ``long``: long integer (64 bit, mostly)

.. list-table::
   :align: left

   * * .. code-block:: c

          long nc;
          for (nc = 0; getchar() != EOF; ++nc);

     * **Same with** ``for`` **loop and empty body**

       Just more obscure

More Examples - ``if``
----------------------

**Counting lines:** ``\n`` terminates a line
  
.. code-block:: c

   int c, nl = 0;
   
   while ((c = getchar()) != EOF)
       if (c == '\n')
           ++nl;

* ``if``: alright
* ``==``: equality; **but inappropriate for floating point numbers**
* ``\n``: character constant for newline (linefeed), ASCII 10 (0A)

``if``, Formally
----------------
  
.. code-block:: c

   if (expression)
       true-statement
   else   // optional
       false-statement

**Statement can be:**

* Single statement (terminated with ';')
* Multiple statements, grouped inside ``{ ... }``

Operators, Formally
-------------------

.. list-table::
   :align: left
  
   * * ``==``
     * Equality
   * * ``!=``
     * Inequality
   * * ``&&``
     * Boolean AND
   * * ``||``
     * Boolean OR
   * * ``!``
     * Boolean NOT
