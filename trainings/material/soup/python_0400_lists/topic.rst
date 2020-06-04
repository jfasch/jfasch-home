.. include:: <mmlalias.txt>

Python: More on Lists
=====================

.. contents::
   :local:

.. jf-topic:: python_0400_lists
   :dependencies: python_0150_datatypes_overview_compound

List Access
-----------

**In addition to sequence access** ...

* ``L.append(elem)``: append ``elem`` to the list
* ``L.extend(l)``: extend ``L`` with another sequence ``l``
* ``L.insert(i, elem)``: insert ``elem`` at position ``i`` (same as
  ``L[i:i] = elem``)
* ``L.pop(i)``: remove element at ``i`` from the list (and return its
  value)
* ``L.sort()``: sort the list *in place*. Elements must be comparable
  |longrightarrow| careful with mixed lists!
* ``L.reverse()``: reverses the list *in place*
* ``sorted(L)``: return a sorted copy of the list
* ``reversed(L)``: returns a reversed copy of the list

List Methods: Examples
----------------------

.. code-block:: python

   >>> l = [3, 2, 5]
   >>> l.append(3)
   >>> l
   [3, 2, 5, 3]
   >>> l.extend([3, 2])
   >>> l.sort()
   >>> l
   [2, 2, 3, 3, 3, 5]
   >>> l.reverse()
   >>> l
   [5, 3, 3, 3, 2, 2]
   >>> sorted(l)
   [2, 2, 3, 3, 3, 5]

List Comprehension
------------------

**The best way to write good code** is to write as little code as
possible ...

.. code-block:: python
   :caption: Best explained by example

   >>> [i**2 for i in [1, 2, 3]]
   [1, 4, 9]

.. code-block:: python
   :caption: Traditional alternative

   def square_numbers(numbers):
       ret = []
       for i in numbers:
           ret.append(i**2)
       return ret
   sqn = square_numbers([1,2,3])
