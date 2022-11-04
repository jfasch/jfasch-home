.. ot-topic:: python.advanced.oo_new.operator_overloading
   :dependencies: python.advanced.oo_new.classes_and_dicts

.. meta::
   :description: A thorough walk through Python's operator
                 overloading: reverse operations, "NotImplemented"
                 return value
   :keywords: python, operators object oriented programming, class

.. include:: <mmlalias.txt>


Operator Overloading
====================

.. contents::
   :local:

.. attention::

   **Respect!**

   * Colleagues want to understand your code
   * Only overload operators when it makes sense
   * **It is hard to get right!**
   * Lots of magic behind the scene (reverse operations, proper use of
     ``NotImplemented``)

Operators Are "Dunder" Methods
------------------------------

Pythonicity: even the innocent ``int`` type is a class

.. jupyter-execute::

   int

... with all consequences: class dictionary, methods (err, operators)

.. jupyter-execute::

   int.__dict__['__add__']

Operators ...

.. jupyter-execute::

   1 + 2

... are methods:

.. jupyter-execute::

   int.__add__(1, 2)

Hypothetical And Pointless ``class Number``
-------------------------------------------

.. jupyter-execute::

   class Number:
       def __init__(self, n):
           self.n = n

Simplest: Equality Comparison (``==``)
--------------------------------------

* By default, Python defines object *equality* as object *identity*
* |longrightarrow| two different objects with the same value compare
  un-equal

.. jupyter-execute::

   l = Number(2)
   r = Number(2)
   
   l==r      # <--- same as "l is r"

* Not whats expected
* |longrightarrow| overload ``==`` by defining the ``__eq__`` method

.. jupyter-execute::

   class Number:
       def __init__(self, n):
           self.n = n
       def __eq__(self, other):
           return self.n == other.n

.. jupyter-execute::

   l = Number(2)
   r = Number(2)

   l == r

* ``Number`` does not define ``__ne__``
* Special Python behaivor
* Python calls ``__eq__`` and negates the result

.. jupyter-execute::

   l != r    # <--- not (l==r)

Comparing Against Incompatible Types? (Lotsa Magic!)
----------------------------------------------------

* ``Number`` With ``int``?
* |longrightarrow| ``NotImplemented`` triggers more special Python
  behavior

.. jupyter-execute::

   import numbers
   
   class Number:
       def __init__(self, n):
           self.n = n
       def __eq__(self, other):
           if isinstance(other, Number):           # <--- easy
               return self.n == other.n
           elif isinstance(other, numbers.Number): # <--- any Python number
               return self.n == other
           else:
	       return NotImplemented               # <--- magic

**Straightforward**: compare ``Number`` with ``int``

* ``Number.__eq__`` knows about ``int``
* Compares directly

.. jupyter-execute::
  
   Number(2) == 2

**Less straightforward**: compare ``int`` with ``Number``

* ``int.__eq__`` knows nothing
* Returns ``NotImplemented``

.. jupyter-execute::
  
   i = 2
   i == Number(2)

But, at a lower level ...

.. jupyter-execute::
  
   i.__eq__(Number(2))

* As a fallback of that, Python reverses operands, thereby asking the
  right hand operand

.. jupyter-execute::

   two = Number(2)
   two.__eq__(2)

* Et voila ...

.. jupyter-execute::

   i = 2
   i == Number(2)

**Special behavior**: this is the same as ...

.. jupyter-execute::

   number2 = Number(2)
   int2 = 2
   result = int2.__eq__(number2)
   if result is NotImplemented:    # <--- retry, in reverse order
       result = number2.__eq__(int2)

   result

**Not so special**: comparing with e.g. ``str``

* Both direct and reversed operation return ``NotImplemented``

.. jupyter-execute::
   :raises:

   Number(2) == '2'

Ordering: Less-Than (`<`) Operator
----------------------------------

As opposed to equality comparison (``==``, ``!=``), Python itself does
not order objects:

.. jupyter-execute::
   :raises:

   Number(2) < Number(3)

Straightforward implementation; no different from ``__eq__``:

.. jupyter-execute::

   import numbers
   
   class Number:
       def __init__(self, n):
           self.n = n
       def __lt__(self, other):
           if isinstance(other, Number):
               return self.n < other.n
           elif isinstance(other, numbers.Number):
               return self.n < other
           else:
               return NotImplemented

Solves problem:

.. jupyter-execute::

   Number(2) < Number(3)

Ordering Magic, Again: ``__gt__`` in terms of ``__lt__``
--------------------------------------------------------

Magically, we see ``>`` implemented:

.. jupyter-execute::

   l = Number(3)
   r = Number(2)

   l > r

No surprise though; Python knows that this is the same as ``r < l``:

.. jupyter-execute::

   if hasattr(l.__class__, '__gt__'):
       result = l.__gt__(r)
   else:
       result = r.__lt__(l)

   result

Table: Comparison Operators
---------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Operator
     * Method
   * * ``<``
     * ``__lt__``
   * * ``<=``
     * ``__le__``
   * * ``==``
     * ``__eq__``
   * * ``!=``
     * ``__ne__``
   * * ``>``
     * ``__gt__``
   * * ``>=``
     * ``__ge__``

``@functools.total_ordering`` To The Rescue
-------------------------------------------

* Even without the *reflection* magic, implementing all of these is
  much writing
* |longrightarrow| ``@functools.total_ordering`` decorator

.. jupyter-execute::

   import numbers
   import functools
   
   @functools.total_ordering
   class Number:
       def __init__(self, n):
           self.n = n
       def __eq__(self, other):
           if isinstance(other, Number):
               return self.n == other.n
           elif isinstance(other, numbers.Number):
               return self.n == other
           else:
               return NotImplemented
       def __lt__(self, other):
           if isinstance(other, Number):
               return self.n < other.n
           elif isinstance(other, numbers.Number):
               return self.n < other
           else:
               return NotImplemented
   
   Number(1) <= Number(2)
   # ... and all the other operators ...

Arithmetic Operators
--------------------

Reverting back to start ...

.. jupyter-execute::
   :raises:

   class Number:
       def __init__(self, n):
           self.n = n
   
   Number(1) - Number(2)

* No surprise: implement ``__sub__``
* Ideally, with full-bloated ``NotImplemented`` bells and whistles

.. jupyter-execute::

   import numbers
   
   class Number:
       def __init__(self, n):
           self.n = n
       def __sub__(self, other):
           if isinstance(other, Number):
               return Number(self.n - other.n)
           elif isinstance(other, numbers.Number):
               return Number(self.n - other)
           else:
               return NotImplemented
   
   sum = Number(1) - 2
   sum.n

Arithmetic Operators, Reverse Operations
----------------------------------------

* Comparison operators are easy: operations are symmetric (``l < r``
  |DoubleLeftRightArrow| ``r > l``)
* Arithmetic operators are not generally symmetric/commutative: ``l -
  r`` vs. ``r - l``
* |longrightarrow| ``NotImplemented`` fallbacks handled differently

.. jupyter-execute::
   :raises:

   l = 1
   r = Number(2)
   
   l - r
      
Hm. ``int`` knows nothing:

.. jupyter-execute::

   l.__sub__(r)

* Python knows that arithmetic operator are not generally symmetric
* Does not call ``r.__sub__(l)`` as a fallback
* |longrightarrow| ``__rsub__`` - *reverse subtraction*

.. jupyter-execute::

   import numbers
   
   class Number:
       def __init__(self, n):
           self.n = n
       def __sub__(self, other):
           if isinstance(other, Number):
               return Number(self.n - other.n)
           elif isinstance(other, numbers.Number):
               return Number(self.n - other)
           else:
               return NotImplemented
       def __rsub__(self, other):
           if isinstance(other, Number):
               return Number(other.n - self.n)
           elif isinstance(other, numbers.Number):
               return Number(other - self.n)
           else:
               return NotImplemented
   
   l = 1
   r = Number(2)
   
   diff = l - r
   diff.n
   
Table: Operators And The Methods To Implement Them
--------------------------------------------------

Here's a table summarizing the rest of the operators that can be
overloaded in Python. Reverse operations are not listed; they are
usually prefixed with an ``r``, as in ``__rsub__``, ``__radd__``,
``__rrshift__``.

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Meaning
     * Operator
     * Method
   * * Addition
     * ``+``
     * ``__add__``
   * * Subtraction
     * ``-``
     * ``__sub__``
   * * Multiplication
     * ``*``
     * ``__mul__``
   * * Power
     * ``**``
     * ``__pow__``
   * * Division
     * ``/``
     * ``__truediv__``
   * * Floor Division
     * ``//``
     * ``__floordiv__``
   * * Modulo
     * ``%``
     * ``__mod__``
   * * Bitwise Left Shift
     * ``<<``
     * ``__lshift__``
   * * Bitwise Right Shift
     * ``>>``
     * ``__rshift__``
   * * Bitwise AND
     * ``&``
     * ``__and__``
   * * Bitwise OR
     * ``|``
     * ``__or__``
   * * Bitwise XOR
     * ``^``
     * ``__xor__``
