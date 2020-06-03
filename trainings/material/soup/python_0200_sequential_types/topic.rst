.. include:: <mmlalias.txt>

Python: Sequential Datatypes
============================

.. contents::
   :local:

.. jf-topic:: python_0200_sequential_types
   :dependencies: python_0150_datatypes_overview

Sequential Datatypes
--------------------

**Sequential Datatypes** are a *sequence* of elements

* Strings: sequence of Unicode *code points*
* Lists: *mutable* sequence of elements of *any* type
  (|longrightarrow| recursive)
* Tuples: like lists, but *immutable*
* Binary data ...

  * Bytes: like strings, only binary - there is no
      *encoding*. *Immutable*
  * Byte arrays: *mutable* arrays of raw bytes

* Common set of operations

  * Indexing
  * Concatenation
  * Several specialities: slicing ...

* Very powerful (albeit a bit hard to read)

Sequence Elements
-----------------

**Elements are numbered**

* Starting at *zero*

.. image:: 0200-sequential-types-index.dia

Sequence Membership
-------------------

The ``in`` operator ...

.. code-block:: python

   >>> 2 in ['one', 2, 'three']
   True
   >>> 3 in ['one', 2, 'three']
   False
   >>> 'three' in ['one', 2, 'three']
   True
   >>> 'three' not in ['one', 2, 'three']
   False

* Cool for short sequences
* *Sequential search*
* |longrightarrow| probably not the right datastructure for searches

Sequence Multiplication
-----------------------

**String multiplication**

.. code-block:: python

   >>> 'blah' * 5
   'blahblahblahblahblah'

**Arbitrary sequence multiplication**

.. code-block:: python

   >>> [1, 2, 3] * 5
   [1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3]
   >>> ['one', 2, 'three'] * 3
   ['one', 2, 'three', 'one', 2, 'three', 'one', 2, 'three']
