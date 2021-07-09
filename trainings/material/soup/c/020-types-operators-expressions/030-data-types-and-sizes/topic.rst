.. include:: <mmlalias.txt>

.. jf-topic:: c.types_operators_expressions.datatypes_size
   :dependencies: c.types_operators_expressions.variable_names


Data Types, Sizes
=================

Standard Data Types And Their Sizes
-----------------------------------

**C knows about the following base types**

* ``char``: one byte in the machine's character set (mostly ASCII, nowadays)
* ``int``: integer, as the processor architecture sees fit (nowadays 32 bits, mostly)
* ``float``: *single-precision* floating point
* ``double``: *double-precision* floating point

.. attention::

   C does not specify the width of any of these types!  ("machine
   dependent")

Integer Variants ("Qualifiers")
-------------------------------

**Width modification**

* ``short int`` (abbreviated: ``short``)
* ``long int`` (abbreviated: ``long``)
* ``long double``

**Signs (for all integer types)**

* ``signed``
* ``unsigned``

**Helpers**

* ``CHAR_BITS``: a macro, bits per character (generally 8, nowadays)
* ``sizeof``: operator, width in characters

Widths
------

**Integer widths on different architectures**

.. list-table::
   :align: left
   :header-rows: 1

   * * Type
     * ``x86``
     * ``amd64``
     * ``arm``
   * * ``char``
     * 8
     * 8
     * 8
   * * ``int``
     * 32
     * 32
     * 32
   * * ``short``
     * 16
     * 16
     * 16
   * * ``long``
     * 32
     * 64
     * 32

**Standard Type Aliases** (from ``<stdint.h>``)

.. list-table::
   :align: left
   :header-rows: 1

   * * Signed
     * Unsigned
   * * ``int8_t``
     * ``uint8_t``
   * * ``int16_t``
     * ``uint16_t``
   * * ``int32_t``
     * ``uint32_t``
   * * ``int64_t``
     * ``uint64_t``

**When to use which ...**

* It depends (as always)
* Program flow (loop counters etc.) are natural integers (preferably
  ``int`` or ``unsigned int``)
* In memory data structure where memory is tight: ``short``
* Protocols, persistence: ``<stdint.h>``
