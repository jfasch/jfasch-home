.. include:: <mmlalias.txt>

.. ot-topic:: c.types_operators_expressions.constants
   :dependencies: c.types_operators_expressions.datatypes_size


Constants
=========

Constants and Types
-------------------

**Question: which type has e.g. ``42``?**

|longrightarrow| some more rules follow ...

.. list-table::
   :align: left

   * * ``42``, ``052``, ``0x2A``, ``0b010010``
     * ``int``
   * * ``42l``, ``42L``
     * ``long``
   * * ``123.456f``, ``123.456F``
     * ``float``
   * * ``123.456``
     * ``double``
   * * ``123.456l``, ``123.456L``
     * ``long double``
   * * ``'a'``, ``'\141'``, ``'\x61'``
     * ``char``
   * * '\n'
     * ``char``

Character Constants: *Escape Sequences*
---------------------------------------

.. list-table::
   :align: left

   * * ``\a``
     * "Alert" \\
   * * ``\b``
     * Backspace
   * * ``\f``
     * Formfeed
   * * ``\n``
     * Newline
   * * ``\r``
     * Carriage Return
   * * ``\t``
     * Horizontal TAB
   * * ``\v``
     * Vertical TAB
   * * ``\\``
     * Backslash
   * * ``\?``
     * Question mark
   * * ``\'``
     * Single Quote
   * * ``\"``
     * Double Quote
   * * ``\ooo``
     * Octal char value
   * * ``\xhh``
     * Hexadecimal ``char`` value

String Constants
----------------

**String**: array of characters, terminated by null-byte

.. code-block:: c

   char hello[] = "hello,world\n";
   char hello[] = "hello," "world\n";
   char hello[] = "hello," 
      "world\n";

* Concatenated by compiler
* |longrightarrow| String literals may span multiple lines

.. image:: 01-01-string.dia

Character vs. String Constants
------------------------------

**Easily confused:**

.. code-block:: c

   if ('x' == "x") { /* compiler error */
       ...
   }

* ``'x'`` is a character
* ``"x"`` is a character array (a *string*)

Symbolic Constants (1)
----------------------

**Preprocessor constants:** the *good old* way to express symbolic
constants

.. code-block:: c
 
   #define JAN 0
   #define FEB 1
   #define MAR 2
   ...

* Preprocessor replaces all occurences in text
* Often not desired

  * too brutal/stupid
  * alternative: manual maintenance of values |longrightarrow| error
    prone

Symbolic Constants (2)
----------------------

**Enumeration** is often more appropriate

.. code-block:: c
  
   enum month {
       JAN,
       FEB,
       MAR,
       ...
   };

* Value has integer type
* *Value* is irrelevant, only comparison is
* |longrightarrow| ``switch`` statement
