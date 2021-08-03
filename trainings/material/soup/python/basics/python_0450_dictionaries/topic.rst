.. include:: <mmlalias.txt>

More on Dictionaries
====================

.. contents::
   :local:

.. jf-topic:: python.basics.python_0450_dictionaries
   :dependencies: python.basics.python_0150_datatypes_overview_compound,
                  python.basics.python_0220_for

Dictionaries
------------

**Associative arrays** ...

* Stores pairs of *key* and *value*
* Keys are unique

  * |longrightarrow| no two keys with the same value can exist in the
    same dictionary object

* Fast lookup
* Internally realized as a *hash table*

  * Keys are not sorted
  * No deterministic iteration possible

Dictionary Access
-----------------

.. list-table::
   :align: left

   * - ``d[key] = value``
     - Insert (or overwrite) ``value`` under ``key``
   * - ``d[key]``
     - returns value of ``key`` (or raises exception)
   * - ``d.get(key)``
     - returns value of ``key`` (or ``None`` if not there)
   * - ``d.get(key,defval)``
     - returns value of ``key`` (or ``defval`` if not there)
   * - ``del d[key]``
     - remove entry for ``key`` (exception if not there)
   * - ``d.keys()``
     - iterable over keys
   * - ``d.values()``
     - iterable over values
   * - ``d.items()``
     - iterable over data as ``(key,value)`` tuples
   * - ``len(d)``
     - number of entries (as with all non-scalar types)
   * - ``d.setdefault(key,defval)``
     - return value if there, else insert ``defval`` and return that
   * - ``d.update(other)``
     - merge dictionary ``other`` into this
   * - ``key in d``
     - does ``key`` exist in ``d``?
   * - ``key not in d``
     - does ``key`` not exist in ``d``?

Examples: Simple Access
-----------------------

.. code-block:: python
   :caption: Literal, insertion, access

   >>> d = {} # empty
   >>> d = {'one': 1, 'two': 2}
   >>> d['one']
   1

.. code-block:: python
   :caption: Nothing there

   >>> d.get('one')
   1
   >>> d.get('three')
   None
   >>> d['three']
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   KeyError: 'three'

Examples: Shortcuts
-------------------

**Shortcuts** for what would otherwise be too much code ...

.. list-table::
   :align: left

   * - .. code-block:: python
          :caption: Default without modification

          >>> d.get('three', 3)
          3
          >>> d.get('three')
          None

     - .. code-block:: python
          :caption: Default with modification

          >>> d.setdefault('three', 3)
          3
          >>> d['three']
          3

Dictionary Iteration (1)
------------------------

* Iteration is a fundamental concept in Python
* ... even more so in Python 3
* |longrightarrow| *compatibility alert!*

.. code-block:: python
   :caption: Python 3

   >>> d.keys()
   dict_keys(['three', 'one', 'two'])
   >>> list(d.keys())
   ['three', 'one', 'two']

.. code-block:: python
   :caption: Python 2

   >>> d.keys()
   ['three', 'two', 'one']
   >>> d.iterkeys()
   <dictionary-keyiterator object at 0x7ff2e8753418>

Dictionary Iteration (2)
------------------------

.. code-block:: python
   :caption: Iteration over values

   >>> list(d.values())
   [3, 1, 2]
   >>> list(d.items())
   [('three', 3), ('one', 1), ('two', 2)]

* Wait: ``d.item()`` lets me iterate over tuples ...
* Why shouldn't I use *tuple unpacking* then?

.. code-block:: python
   :caption: The entire power of Python

   for key, value in d.items():
       ...

Building Dictionaries
---------------------

.. code-block:: python

   >>> d = {}
   >>> d = {1: 'one', 2: 'two'}
   >>> d = dict()
   >>> d = dict({1: 'one', 2: 'two'})
   >>> d = dict([('one', 1), ('two', 2), ('three', 3)])
