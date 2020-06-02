.. jf-topic:: python_0250_refs_flat_deep_copy
   :dependencies: python_0140_variables, python_0150_datatypes_overview, python_0150_datatypes_overview_compound

.. include:: <mmlalias.txt>

Python: References, (Im)mutability
==================================

.. contents::
   :local:

Immutability: Numbers
---------------------

**Numbers are immutable** ...

* Object of type ``int`` with value 42
* Variable ``a`` points to it ("gives it a name")
* The object cannot change its value - there is no method to
  modify an integer object
* |longrightarrow| The latter situation is equivalent to the former
  (which is the implementation)

.. list-table::
  
   * - .. code-block:: python

          a = 42
	  b = a

     - .. image:: 0250-refs-flat-deep-copy-immutability-numbers-shared.dia

.. list-table::
  
   * - .. code-block:: python

          a = 42
          b = 42
          
     - .. image:: 0250-refs-flat-deep-copy-immutability-numbers-distinct.dia

Immutability: Tuples
--------------------

**Same with tuples**

.. list-table::

   * - - Like lists, but *immutable*
       - No way to modify a tuple

	 * No appending
	 * No slice assignment
	 * No nothing

       - So both of these are equivalent

	 * To the user, ``b`` *is a copy of* ``a``

     - .. code-block:: python

          >>> a = (42, "xy", 13)
	  >>> b = a

       .. image:: 0250-refs-flat-deep-copy-immutability-tuples-shared.dia

       .. image:: 0250-refs-flat-deep-copy-immutability-tuples-distinct.dia

Mutability: Lists (1)
---------------------

**Lists are mutable** ...

.. list-table::

   * - .. code-block:: python

          >>> a = [1, 2, 3]
	  >>> b = a
	  >>> b
	  [1, 2, 3]
	  >>> b.append(4)
	  >>> b
	  [1, 2, 3, 4]
	  >>> a
	  [1, 2, 3, 4]

     - - Objects can be modified
       - E.g. by using ``append()``

       .. image:: 0250-refs-flat-deep-copy-mutability-list.dia

Mutability: Lists (2)
---------------------

**Danger ...**

* Take care when passing complex data structures
* Not passed *by copy* (as in C++)
* Passed *by reference* (as in Java)
* Make a copy if needed

.. code-block:: python
   :caption: Copying a list

   >>> a = [1, 2, 3]
   >>> b = a[:]
   >>> a.append(4)
   >>> b
   [1, 2, 3]

Shallow Copy
------------

.. list-table::

   * - .. code-block:: python

          >>> a = [1, [1, 2, 3], 2]
          >>> b = a[:]
          >>> b
          [1, [1, 2, 3], 2]
          >>> a[1].append(4)
          >>> a
          [1, [1, 2, 3, 4], 2]
          >>> b
          [1, [1, 2, 3, 4], 2]

       .. code-block:: python	  

	  >>> a[1] is b[1]
	  True

     - .. image:: 0250-refs-flat-deep-copy-shallow-copy.dia

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

.. code-block:: python

   >>> import copy
   >>> a = [1, [1, 2, 3], 2]
   >>> b = copy.deepcopy(a)
   >>> a[1] is b[1]
   False
