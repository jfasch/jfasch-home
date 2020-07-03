.. include:: <mmlalias.txt>

Indexing and Slicing
====================

.. contents::
   :local:

.. jf-topic:: python.python_0210_indexing_slicing
   :dependencies: python.python_0200_sequential_types

Indexing (1)
------------

**Accessing the n-th element** is straightforward ...

.. code-block:: python

   >>> text = "Hello World"
   >>> text[0]
   'H'
   >>> text[6]
   'W'
   >>> text[-1]
   'd'
   >>> text[-4]
   'o'
   >>> text[len(text)-1] == text[-1]  # AAH!!
   True

Indexing (2)
------------

**Same with other sequences** ...

.. code-block:: python

   >>> a_list = ['Peter', 'Paul', 'Mary']
   >>> a_list[0]
   'Peter'
   >>> a_list[-1]
   'Mary'

.. code-block:: python

   >>> a_tuple = (1, 'one', 1.0)
   >>> a_tuple[0]
   1
   >>> a_tuple[-1]
   1.0

Slicing: Cutting Out
--------------------

**Extracting part of a sequence** ...

.. code-block:: python

   >>> text = "Hello World"
   >>> text[0:5]
   'Hello'
   >>> text[:5]
   'Hello'
   >>> text[6:11]
   'World'
   >>> text[6:]
   'World'
   >>> text[6:-1]
   'Worl'
   >>> text[-5:-1]
   'Worl'

Slicing: Step Width
-------------------

**Killer feature: slices with step width**

.. code-block:: python

   >>> text = "Hello World"
   >>> text[0:7:2]
   'HloW'
   >>> text[::2]
   'HloWrd'
   >>> text[:-6:2]
   'Hlo'
   >>> text[::-1]
   'dlroW olleH'

Slice Assignment
----------------

**Sub-slice assignment**

.. code-block:: python

   >>> l = [2, 3, 'a', 'b', 7]
   >>> l[2:4] = [4, 5, 6]
   >>> l
   [2, 3, 4, 5, 6, 7]

**Prepending**

.. code-block:: python

   >>> l[:0] = [0, 1]
   >>> l
   [0, 1, 2, 3, 4, 5, 6, 7]

**Appending (but see** ``list`` **methods** ``append()`` **and** ``extend()``

.. code-block:: python

   >>> l[len(l):] = [8, 9]
   >>> l
   [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
