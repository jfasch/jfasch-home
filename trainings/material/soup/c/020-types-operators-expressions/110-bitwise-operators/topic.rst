.. include:: <mmlalias.txt>

.. ot-topic:: c.types_operators_expressions.bit_operators
   :dependencies: c.types_operators_expressions.exercise_string_reduce


Bit-Operators
=============

Bit Manipulation
----------------

* **C is a hardware language**  
* |longrightarrow| many operators to manipulate individual bits

.. list-table::
   :align: left
   :header-rows: 1

   * * ``&``
     * bitwise AND
   * * ``|``
     * bitwise OR
   * * ``^``
     * bitwise XOR
   * * ``<<``
     * shift left
   * * ``>>``
     * shift right
   * * ``~``
     * bitwise invert

*Why?**
  
* Manipulating hardware registers
* Saving space (e.g. persistence, protocols)
* ...

Bitwise AND and OR
------------------

**Extract/mask bits**

.. list-table::
   :align: left

   * * 
     * ``0x4b``
     * ``01001011``
   * * ``&``
     * ``0x0c``
     * ``00001100``
   * * Gives
     * ``0x08``
     * ``00001000``

**Add bits**

.. list-table::
   :align: left

   * *
     * ``0x4b``
     * ``01001011``
   * * ``|``
     * ``0x0c``
     * ``00001100``
   * * Gives
     * ``0x4f``
     * ``01001111``

Bitwise XOR
-----------

**Exclusive OR**

.. list-table::
   :align: left

   * *
     * ``0x4b``
     * ``01001011``
   * * ``^``
     * ``0x0c``
     * ``00001100``
   * * Gives
     * ``0x47``
     * ``01000111``

Shift Left
----------

.. list-table::
   :align: left

   * * ``0x03``
     * ``<< 2``
     * ``00000011``
   * * ``0x0c``
     * 
     * ``00001100``
   * * ``0x03``
     * ``<< 7``
     * ``00000011``
   * * ``0x80``
     * 
     * ``10000000``

* Filled with zeroes from right
* Bits fall off to the left

Shift Right
-----------

.. list-table::
   :align: left

   * * ``0x30``
     * ``>> 2``
     * ``00110000``
   * * ``0x0c``
     * 
     * ``00001100``
   * * ``0x30``
     * ``>> 5``
     * ``00110000``
   * * 
     * 
     * ``?????001``

* Bits fall off to the right
* ``unsigned``: filled with zeroes from left
* ``signed``: *machine dependent*

|longrightarrow| Shift operations on signed entities is nonsense
anyway

Inverting ("One's-Complement")
------------------------------

.. list-table::
   :align: left

   * * ``~``
     * ``0x4c``
     * ``01001100``
   * * 
     * ``0xb3``
     * ``10110011``

