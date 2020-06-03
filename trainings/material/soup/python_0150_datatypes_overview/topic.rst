.. include:: <mmlalias.txt>

Python: Datatypes
=================

.. contents::
   :local:

.. jf-topic:: python_0150_datatypes_overview
   :dependencies: python_0140_variables

Numbers
-------

**Numbers are simplest** ...


* Integer (``int``) - *sign* is irrelevant
* Floating point (``float``)
* Complex (``complex``)
* Boolean (``bool``)

**More powerful types** ...

* *Sequences* with very powerful operations

  * Immutable sequences: Strings, Bytes, Tuples
  * Lists

* *Sets*

  * *Mappings*: *key* to *value*

Integer Numbers
---------------

**Range** ...

* Represent numbers in an *unlimited* range - limited only by
  available memory

**Integer literals** ...

* Decimal: ``1234``, ``-1234``
* Octal: ``0o01234 == 1*8**3+2*8**2+3*8**1+4*8**0 == 668``
* Hexadecimal: ``0x1234} == 1*16**3+2*16**2+3*16**1+4*16**0 == 4660``
* Binary: ``0b100110``

Integer Numbers: Comparison
---------------------------

**Comparison operators**

.. csv-table::
   :align: left

   ``<``, less than
   ``<=``, less or equal
   ``>``, greater than
   ``>=``, greater or equal
   ``==``, equal
   ``!=``, not equal

Integer Numbers: Arithmetic
---------------------------

**Arithmetic operators**

.. csv-table::
   :align: left

   ``+``, addition
   ``-``, subtraction
   ``*``, multiplication
   ``/``, *division*
   ``//``, *floor division*
   ``%``, modulo
   ``**``, exponentiation
   ``-``, negation (unary)

Shortcut: self modification (not only for the ``+`` operator)

::

   i = i + 7
   i += 7

Operator Precedence
-------------------

**Boring but important:** precedence rules

* Exponentiation comes first (*binds strongest*)
* Negation
* ``*``, ``/``, ``%`` (left associative)
* ``+``, ``-`` (binary operators)
* Comparison operators

**Not boring --- necessary in programming**

* If in doubt, use explicit braces: ``2 * 7 % 3 != 2 * (7 % 3)``
* If not in doubt, think about colleagues

  * If in doubt, use explicit braces

Floating Point Numbers
----------------------

**Floating point vs. Integer**

* Operators listed above also valid for floating point numbers
* Not unbounded

  * ... otherwise :math:`\pi` would consume all memory

**Literals**

* Decimal point: ``3.14159265359``
* Exponent: ``2.3e12``, ``1.5e-34``

Numbers: Python2 vs. Python 3 (1)
---------------------------------

**Incompatibility alert!**

* There is no *pure integer division in 3*
* ``int`` only if possible
* ``float`` otherwise
* ... *as opposed to 2*

**Reason:**

* Python is also a beginners language
* There are many other incompatibilities as well
* ... the entire object model has changed

.. list-table::
   :align: left

   * - **Python 2**
     - **Python 3**
   * - ::

          >>> 3/2
	  1
	  >>> type(3/2)
	  <type 'int'>

     - ::

          >>> 3/2
	  1.5
	  >>> type(3/2)
	  <class 'float'>

Numbers: Python2 vs. Python 3 (2)
---------------------------------

**General advice** regarding numbers

* Do not rely on the division operator ``/`` to do *floor division*

  * Portably, ``3/2 != 1``
  * Not easy when coming from Java or C
  * ... or just about any other language

* Don't differentiate between ``int`` and ``float``
* Use *explicit floor division*, ``//``

  * Portably, ``3//2 == 1``

Strings: Python 2
-----------------

**Python 2 strings** ...

* A string could have just about any encoding
* Strings were raw bytes, basically
* Everybody had to know *where* the string came from
* Could be ASCII, could be Unicode, could be bytes, could be ...
* Type ``unicode`` --- added as an afterthought
* File I/O done *without* an idea of encoding

**Problems** ...

* Implicit conversions back and forth
* Clearly defined but not at all obvious
* |longrightarrow| Mixing text and binary

Strings: Python 2 --- Confusion
-------------------------------

.. list-table::
   :align: left

   * - ::

          >>> type('abc')
	  <type 'str'>
	  >>> 'abc'
	  'abc'
	  >>> len('abc')
	  3

     - - That was easy
       - ASCII
   * - ::

          >>> type('äöü')
	  <type 'str'>
	  >>> 'äöü'
	  '\xc3\xa4\xc3\xb6\xc3\xbc'
	  >>> len('äöü')
	  6
	  >>> 'äöü'[0]
	  '\xc3'

     - - Content comes from terminal
       - |longrightarrow| UTF-8 (in my case)
       - Umlauts are 2 bytes in UTF-8
       - |longrightarrow| Gosh!

Strings: Python 2 - ``unicode`` (1)
-----------------------------------

**Good news**

.. list-table::
   :align: left

   * - ::

          >>> type(u'äöü')
	  <type 'unicode'>
	  >>> u'äöü'
	  u'\xe4\xf6\xfc'
	  >>> len(u'äöü')
	  3
	  >>> u'äöü'[0]
	  u'\xe4'

     - - * Explicit type ``unicode``
         * Content is typed
	   * (I still don't get it)

Strings: Python 2 --- ``unicode`` (2)
-------------------------------------

**Bad news**

.. list-table::
   :align: left

   * - ::

          >>> type(u'abc' + 'def')
	  <type 'unicode'>
	  >>> type(u'abc' + b'def')
	  <type 'unicode'>

     - - * Can be mixed with ``str``
         * Can be mixed with ``bytes`` (which is another afterthought)

           * |longrightarrow| Semantics not entirely clear

	 * |longrightarrow| *Chaos*
	 * |longrightarrow| *Bugs, bugs, bugs ...*

Strings: Python 3
-----------------

**Strings are always Unicode - Basta!**

* Major reason for the 2 to 3 move

  * Python 2 Unicode is a mess

* No ``unicode`` type anymore
* *No mixing* of ``str`` and ``bytes``
* *Sources* which create strings know about encodings - and create Unicode strings accordingly

  * File I/O

Python 3, Generally
-------------------

**Which version should I choose**

* Answer 1: Python 3
* Answer 2: unless you have a compelling reason not to

  * Large Python 2 codebase
  * Ancient distro version (though there are Python 3 packages
    available for most)


**So much for Python 2 vs. 3** ...

Datatype Conversions
--------------------

**Conversion between types** ...

.. list-table::
   :align: left

   * - ::

          >>> str(42)
	  '42'
	  >>> int('42')
	  42
	  >>> int('10', 16)
	  16
	  >>> float('12.3')
	  12.3
	  >>> int(12.3)
	  12

     - - Conversions
       - Better viewed as *constructors* of the corresponding types
       - Common theme across the language
