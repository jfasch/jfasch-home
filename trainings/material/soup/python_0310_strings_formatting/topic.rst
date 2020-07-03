.. include:: <mmlalias.txt>

String Formatting
=================

.. contents::
   :local:

.. jf-topic:: python.python_0310_strings_formatting
   :dependencies: python.python_0300_strings

C-Style Formatting (1)
----------------------

**Good old C:** ``%[flags][width][.precision]type}``

.. list-table::
   :align: left

   * - **Good ol' C**
     - **Python**
   * - .. code-block:: c
          :caption: Program

	  int i = 42;
	  float f = 3.14159265359;
	  printf("%07d, %8.4f\n", i, f);

       .. code-block:: console
	  :caption: Output

	  0000042,   3.1416

     - .. code-block:: python
          :caption: Same in Python, using the ``%`` operator

          >>> '%07d' % 42
          '0000042'
          >>> '%07d, %8.4f' % (42, 3.14159265359)
          '0000042,   3.1416'

C-Style Formatting: Conversions
-------------------------------

**Frequently used conversions** ...

.. csv-table::
   :align: left

   ``s``, String
   ``c``, Single character
   ``d``, Integer (decimal)
   ``o``, Integer (octal)
   ``x``, Integer (hexadecimal lowercase)
   ``X``, Integer (hexadecimal uppercase)
   ``f``, Floating point, exponential format (lowercase)
   ``F``, Floating point, exponential format (uppercase)
   ``\%``, The ``%`` sign itself

C-Style Formatting: Flags
-------------------------

**Frequently used flags** ...

.. csv-table::
   :align: left

   ``#``, Octal or hex integer conversions: ``0x...`` prefixes
   ``0``, Pad with '0' characters
   ``-``, Left alignment
   ``+``, Print sign even if positive
   `` `` (space), Print space in place of sign if positive

C-Style Formatting: Examples
----------------------------

.. list-table::
   :align: left

   * - .. code-block:: python

          >>> '%#5X' % 47
          ' 0X2F'
          >>> '%5X' % 47
          '   2F'
          >>> '%#5.4X' % 47
          '0X002F'
          >>> '%#5o' % 25
          ' 0o31'
          >>> '%+d' % 42
          '+42'

     - .. code-block:: python

          >>> '% d' % 42
          ' 42'
          >>> '%+2d' % 42
          '+42'
          >>> '% 4d' % 42
          '  42'
          >>> '% 4d' % -42
          ' -42'
          >>> '%04d' % 42
          '0042'

The ``format`` Method
---------------------

**Problems** with C-style formatting

* Not flexible enough (as always)
* Positional parameters only
* Parameter position must match occurence in format string

.. code-block:: python
   :caption: A better (?) way of formatting

   >>> '0 {0:05d}, 1 {1:8.2f}, 0 again {0}'.format(42, 1.5)
   '0 00042, 1     1.50, 0 again 42'
   >>> 'a {a:05d}, b {b:8.2f}, a again {a}'.format(a=42, b=1.5)
   'a 00042, b     1.50, a again 42'

More |longrightarrow| `RTFM
<https://docs.python.org/3.8/library/string.html#format-string-syntax>`__
