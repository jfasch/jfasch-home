.. include:: <mmlalias.txt>

String Formatting
=================

.. contents::
   :local:

.. ot-topic:: python.basics.python_0310_strings_formatting
   :dependencies: python.basics.python_0300_strings

.. sidebar::

   **Documentation**

   * `<https://docs.python.org/3.8/library/string.html#format-string-syntax>`__

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

     - * Same in Python, using the ``%`` operator (humorously)
       * Format single item into string, by position

       .. jupyter-execute::

            '%07d' % 42

       * Format multiple items (|longrightarrow| tuple) into string
         (again, by position)

       .. jupyter-execute::

	  '%07d, %8.4f' % (42, 3.14159265359)

C-Style Formatting: Conversions
-------------------------------

**Frequently used conversions** ...

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Format char
     * Type
     * Comment
   * * ``s``
     * String
     *
   * * ``c``
     * Single character
     *
   * * ``d``
     * Integer
     * decimal
   * * ``o``
     * Integer
     * octal
   * * ``x``
     * Integer
     * hexadecimal lowercase
   * * ``X``
     * Integer
     * hexadecimal uppercase
   * * ``f``
     * Floating point
     * exponential format (lowercase)
   * * ``F``
     * Floating point
     * exponential format (uppercase)
   * * ``\%``
     *
     * The ``%`` sign itself

C-Style Formatting: Flags
-------------------------

**Frequently used flags** ...

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Flag
     * Meaning
   * * ``#``
     * Octal or hex integer conversions: ``0x...`` prefixes
   * * ``0``
     * Pad with '0' characters
   * * ``-``
     * Left alignment
   * * ``+``
     * Print sign even if positive
   * * `` `` (space)
     * Print space in place of sign if positive

C-Style Formatting: Examples
----------------------------

.. list-table::
   :align: left
   :widths: auto

   * * .. jupyter-execute::

          '%#5X' % 47

     * .. jupyter-execute::

	  '%5X' % 47

     * .. jupyter-execute::

	  '%#5.4X' % 47

     * .. jupyter-execute::

	  '%#5o' % 25

     * .. jupyter-execute::

	  '%+d' % 42

   * * .. jupyter-execute::

          '% d' % 42

     * .. jupyter-execute::

	  '%+2d' % 42

     * .. jupyter-execute::

	  '% 4d' % 42

     * .. jupyter-execute::

	  '% 4d' % -42

     * .. jupyter-execute::

	  '%04d' % 42

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

Cool Since 3.6: *f-Strings*
---------------------------

* Definitely cool
* In-string syntax like above, but reaching out ...

.. jupyter-execute::

   something = 42
   f'Hey, something has a value, namely {something}'

* All of the fancy C-style format syntax is valid, e.g.

.. jupyter-execute::

   something = 42.666
   f'Well, this is also possible: {something:8.2f}'
