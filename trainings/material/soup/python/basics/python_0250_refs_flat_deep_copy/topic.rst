.. include:: <mmlalias.txt>

References, (Im)mutability
==========================

.. contents::
   :local:

.. ot-topic:: python.basics.python_0250_refs_flat_deep_copy
   :dependencies: python.basics.python_0140_variables,
		  python.basics.python_0150_datatypes_overview,
		  python.basics.python_0150_datatypes_overview_compound

Immutability: Numbers
---------------------

**Numbers are immutable** ...

* Object of type ``int`` with value 42
* Variable ``a`` points to it ("gives it a name")
* The object cannot change its value - there is no method to modify an
  integer object
* |longrightarrow| The latter situation is equivalent to the former
  (which is the implementation)

.. list-table::
   :align: left
   :widths: auto
  
   * - .. jupyter-execute::

          a = 42
	  b = a

       Both ``a`` and ``b`` refer to the same object:

       .. jupyter-execute::

	  print(id(a))
	  print(id(b))

     - .. image:: 0250-refs-flat-deep-copy-immutability-numbers-shared.dia
          :scale: 50%

Modifying An Integer In-Place? (Immutability)
---------------------------------------------

.. jupyter-execute::

   id(a)

* Operator ``+=`` modifies an integer in-place?
* ``a = a+7`` modifies an integer in-place?
* |longrightarrow| No, both create new objects!

.. jupyter-execute::

   a += 1
   id(a)         # <--- different object now

.. jupyter-execute::

   a = a + 7
   id(a)         # <--- again, different object now

Immutability: Tuples
--------------------

.. list-table::
   :align: left
   :widths: auto

   * - .. jupyter-execute::

          a = (42, "xy", 13)
	  b = a

	  print(id(a))
	  print(id(b))

       - Like lists, but *immutable*
       - No way to modify a tuple

	 * No appending
	 * No slice assignment
	 * No nothing
	   
     - .. image:: 0250-refs-flat-deep-copy-immutability-tuples-shared.dia
	  :scale: 50%

* And operator ``+=``?

.. jupyter-execute::

   a += ('foo', 'bar')
   print(a)
   print(id(a))
   print(id(b))

* |longrightarrow| leaves ``b`` alone

.. jupyter-execute::

   b

Mutability: Lists (1)
---------------------

**Lists are mutable** ...

* Objects can be modified
* E.g. by using ``append()``

.. list-table::
   :align: left
   :widths: auto

   * - .. jupyter-execute::

          a = [1, 2, 3]
	  b = a
	  b

       * Both now refer to the same object
       * Modify ``b`` ...

       .. jupyter-execute::

	  b.append(4)
	  b

       * ... and see ``a`` modified!

       .. jupyter-execute::

	  a

     - .. image:: 0250-refs-flat-deep-copy-mutability-list.dia
	  :scale: 50%

Mutability: Lists (2)
---------------------

**Danger ...**

* Take care when passing complex data structures
* Not passed *by copy* (as in C++)
* Passed *by reference* (as in Java and C#, for example)

**Solution?**

* Is copy a solution?
* |longrightarrow| I'd say no!
* *Being careful is a solution!*

.. jupyter-execute::

   a = [1, 2, 3]
   b = a[:]             # <--- copy
   a.append(4)
   b

**Shallow** Copy
----------------

* A list within a list
* Create "copy"
     
.. jupyter-execute::

   a = [1, [1, 2, 3], 2]
   b = a[:]      # <--- copy
   b

* This is only a *shallow* copy

.. image:: 0250-refs-flat-deep-copy-shallow-copy.dia
   :scale: 60%

* Modify ``a``

.. jupyter-execute::

   a[1].append(4)
   a

* And ``b``?

.. jupyter-execute::

   b

* Reason: *nested list has not been copied!*

.. jupyter-execute::

   a[1] is b[1]

* Only first level copied
* *Shallow copy*
* ``a[1]`` is a *reference*
* ``is``: *object identity*

Deep Copy
---------

**Solution:** not easy

* Recursive structure traversal
* Handling every possible type
* Dedicated module in the standard library: ``copy``
* Solution?

.. jupyter-execute::

   import copy
   a = [1, [1, 2, 3], 2]
   b = copy.deepcopy(a)
   a[1] is b[1]
