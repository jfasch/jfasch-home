.. include:: <mmlalias.txt>

.. jf-topic:: c.types_operators_expressions.type_conversions
   :dependencies: c.types_operators_expressions.relational_logical_operators


Type Conversions
================

Implicit Type Conversions
-------------------------

**Bad news:** C does not care much about widths and signs

* Assignment to narrower types simply cuts off
* Sign propagation is undefined
* Sign may change across signed/unsigned assignments
* |longrightarrow| History is full of integer overflow bugs, sign bugs
  etc.
* GCC (and other compilers) has options that warn on possible
  type-bugs (can be very loud though)

Rules are not easy to comprehend - especially the *Why* behind
|longrightarrow| Examples ...

Sign Bugs
---------

**Unsigned to signed, same width**

.. list-table::
   :align: left

   * * .. code-block:: c

          unsigned int ui = 4294967295U;
          int i = ui;

     * * ``0xffffffff`` in `2's
         <http://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html>`__
         `complement
         <http://en.wikipedia.org/wiki/Two%27s_complement>`__
       * |longrightarrow| ``i == -1``

**The other way around: signed to unsigned**

.. list-table::
   :align: left

   * * .. code-block:: c

          int i = -1;
          unsigned int ui = i;

     * * ``-1`` is ``0xffffffff`` in `2's
         <http://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html>`__
         `complement
         <http://en.wikipedia.org/wiki/Two%27s_complement>`__
       * |longrightarrow| ``ui == 4294967295U``
  
.. attention::

   This is **desired behavior from the very beginning**
   |longrightarrow| no compiler error, no compiler warning!

   Though at least GCC can be convinced to warn:

   * ``-Wsign-conversion``
   * more global: ``-Wconversion``

Truncation
----------

.. list-table::
   :align: left

   * * .. code-block:: c

          unsigned long ul = 4294967296U;
          unsigned int ui = ul;

     * * Unscrupulous conversion (by brutal truncation) of a 64 bit
         number (``0x100000000``) to a 32 bit number
       * |longrightarrow| ``ui == 0``

.. note::

   ``-Wconversion``

Sign Propagation
----------------

.. list-table::
   :align: left

   * * .. code-block:: c

          char c = '\310';
          int ic = c;

     * * ``char`` is signed on ``x86_64``
       * ``c == -56``

.. note::

   ``-Wconversion``

Conversion Using Operators
--------------------------

**Hard rule**

  If an operator gets passed different types, then the "weaker" is
  converted to the "stronger" - the result is of the "stronger" type.

**What does that mean?** (disregarding ``unsigned``)

* If one operand is ``long double``, then the other is converted
* else, if one is ``double``, ...
* else, if one is ``float``, ...
* else, ``char`` and ``short`` are converted to ``int``
* |longrightarrow| ``int`` *is the default type for arithmetic
  operations*

Conversion and ``unsigned`` (1)
-------------------------------

**Hard rule**. There is no hard rule. Well almost:

  When mixing ``unsigned`` and ``signed`` integers of the same width,
  then ``signed`` is converted to ``unsigned``

.. warning::

   Gosh!

**Additionally**: widths are hardware defined!

.. list-table::
   :align: left

   * * .. code-block:: c

          -1L < 1U

     * * *True*: ``1U`` becomes ``1L``
       * ``-1U`` (``unsigned`` 32) is less than the "stronger" ``-1L`` (``signed`` 64)
       * fits in ``signed`` 64 *losslessly*
       * |longrightarrow| **Correct!**

   * * .. code-block:: c

          -1L < 1UL

     * * **False**: ``-1L`` (``signed`` 64) becomes ``unsigned`` 64, as dictated by the right hand
         side.
       * |longrightarrow| **Incorrect!**

.. warning::

   This is **desired behavior from the very beginning**
   |longrightarrow| no compiler error, no compiler warning!

   Though at least GCC can be convinced to warn:

   * ``-Wsign-conversion``
   * more global: ``-Wconversion``

Conversion and ``unsigned`` (2)
-------------------------------

**Beware of mixing!**

* Not a problem if the ``signed`` part can never become negative
* **Big problem otherwise!**

.. code-block:: c

   int x;
   unsigned int y;
   
   if (x < y) ...

.. code-block:: console

   $ gcc -Wsign-compare ...
   warning: comparison between signed and unsigned integer expressions

Compiler Warnings
-----------------

**All that is desired behavior!**

* Read: *historical baggage*
* |longrightarrow| compiler warnings have to be explicitly enabled

.. list-table:: 
   :align: left
   :header-rows: 1

   * * Option
     * Meaning
   * * ``-Wsign-conversion``
     * Sign could change
   * * ``-Wconversion``
     * Value and sign ...
   * * ``-Wsign-compare``
     * Comparison with mixed signed value
   * * ``-Wtype-limits``
     * E.g. ``if (ui >= 0) ...``
   * * ``-Wall``
     * Selection of "good" warnings
   * * ``-Wextra``
     * ... more good warnings
   * * ``-pedantic``
     * Does not hurt
   * * ``-Werror``
     * Anti-Sloppiness: *warnings become errors*

.. tip::

   **General advice**: the more the better!

Last Warning
------------

**C's datatypes are immensely hazardous**. More hazardous is, though:

* Overengineering
* Messy design
* Loosing control over one's data structures
* Not knowing ranges of variables
* Not being open to program modification

Forced Conversion - Cast
------------------------

Should an automatic conversion be identified as being wrong
(e.g. because the compiler warns), it can be *overridden* ...

.. code-block:: c

   int x;
   unsigned int y;
   
   if (x < (signed)y) ...
