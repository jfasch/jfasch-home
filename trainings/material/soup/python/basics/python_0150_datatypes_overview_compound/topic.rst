.. include:: <mmlalias.txt>

Compound Datatypes
==================

.. contents::
   :local:

.. jf-topic:: python.basics.python_0150_datatypes_overview_compound
   :dependencies: python.basics.python_0150_datatypes_overview

Compound Datatypes By Example: List, Tuple
------------------------------------------

**Typical "sequence" types** ...

.. list-table::
   :align: left

   * - ::

	  l = [1,2,3]
	  l.append(4)
	  l.extend([5,6,7])
	  l += [8,9]
	  new_l = l + [10,11]

     - - *Mutable*: can be modified *in-place*
       - Type: ``list``

   * - ::

	  t = (1,2,3)
	  t = (1,)
	  new_t = t + (4,5)

     - - *Immutable*: cannot be modified, only copied
       - Type: ``tuple``

Compound Datatypes By Example: Dictionary
-----------------------------------------

.. list-table::
   :align: left

   * - ::

	  >>> d = {1:'one', 2:'two'}
	  >>> d[2]
	  'two'
	  >>> d[3] = 'three'
	  >>> 3 in d
	  True
	  >>> del d[3]
	  >>> 3 in d
	  False

     - - *Associative array*
       - Key/value mapping
       - Common operations: insert, remove, query

Compound Datatypes By Example: Set
----------------------------------

.. list-table::
   :align: left

   * - ::

	  >>> s = {1,2,3}
	  >>> 1 in s
	  True
	  >>> s.add(4)
	  >>> s
	  {1, 2, 3, 4}
	  >>> s.remove(1)
	  >>> 1 in s
	  False

     - - Bag of elements
       - No value like dictionary
       - *Membership test* is the most important operation
