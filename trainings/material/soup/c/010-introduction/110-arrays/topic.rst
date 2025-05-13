.. include:: <mmlalias.txt>


Arrays
======

Array Definition, Explicit Initialization
-----------------------------------------

**Nonsensical but illustrative exercise:** count digits, whitespace,
and others.

.. literalinclude:: countchars-explicit-init.c
   :language: c
   :caption: :download:`countchars-explicit-init.c`

Array Access
------------

You access the ``n``-th element of the array using the *index*
(``[n]``) operator.

.. code-block:: c

   int n = 7;   // for example
   int number;
   ndigit[n] = 666;  // write value 666 in n-th array position
   number = ndigit[n];   // read value from n-th array position (and store into 'number')

Discussion: Initialization
--------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          int nwhite = 0, nother = 0;

     * Counter for whitespace and rest

   * * .. code-block:: c

          int ndigit[10];
          
          for (i = 0; i < 10; ++i)
	      ndigit[i] = 0;

     * * 10 counters for digits 0..9
       * *Attention*: Indexes start at 0

Discussion: ``if``, ``else``
----------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          while ((c = getchar()) != EOF)
              if (c >= '0' && c <= '9')
                  ++ndigit[c-'0'];
              else if (c == ' ' || c == '\t' || c == '\n')
                  ++nwhite;
              else
                  ++nother;

     * * There is only ``if`` and ``else``
       * No ``elif`` (as in Python, for example)
       * |longrightarrow| second ``if`` is *nested*

Array Initializer
-----------------

.. literalinclude:: countchars-array-initializer.c
   :language: c
   :caption: :download:`countchars-array-initializer.c`

Discussion: Initializer
-----------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          int ndigit[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

     * Array initialized as 10 zeroes

   * * .. code-block:: c

          int ndigit[10] = { 1, 2, 3, 4 };

     * Array initialized as ``{ 1, 2, 3, 4, 0, 0, 0, 0, 0, 0 }``

   * * .. code-block:: c

          int ndigit[10] = { 0 };

     * Array initialized as 10 zeroes

Initialization using ``memset()``
---------------------------------

.. literalinclude:: countchars-memset-init.c
   :language: c
   :caption: :download:`countchars-memset-init.c`

Discussion: ``memset()``
------------------------

See ``memset()`` `manual page
<https://man7.org/linux/man-pages/man3/memset.3.html>`__.

.. list-table::
   :align: left

   * * .. code-block:: c

          memset(ndigit, 0, sizeof(ndigit));

     * * For the purpose of parameter passing, ``ndigit`` is a
         *pointer* to the 0-th element |longrightarrow| the
         *beginning* of the array.
       * ``sizeof()`` operator: size in bytes |longrightarrow|
	 ``10*sizeof(int)`` (40)

