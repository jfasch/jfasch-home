.. include:: <mmlalias.txt>


More About Sets
===============

Sets
----

* Unordered collection of distinct objects
* |longrightarrow| *set* in a mathematical sense
* Membership tests
* Addition and removal of elements
* Mathematical operations, like ...

  * Intersection
  * Union
  * Difference

Operations on Sets (1)
----------------------

**Test operations**

.. list-table::
   :align: left

   * - ``x in s``
     - Is ``x`` member of ``s``
   * - ``x not in s``
     - ``in``, negated
   * - ``s1 == s2``
     - ``True`` if both contain the same elements
   * - ``s1 != s2``
     - ...
   * - ``s.isdisjoint(other)``
     - Does ``s`` have no elements in common with ``other``?
   * - ``s1 <= s2``
     - Is ``s1`` a subset of ``s2``?
   * - ``s1 < s2``
     - Is ``s1`` a *strict* subset of ``s2``?
   * - ``s1 >= s2``
     - Is ``s1`` a superset of ``s2``?
   * - ``s1 > s2``
     - Is ``s1`` a *strict* superset of ``s2``?

Operations on Sets (2)
----------------------

**Building sets from other sets**

.. list-table::
   :align: left

   * - ``s1 | s2``
     - Union
   * - ``s1 & s2``
     - Intersection
   * - ``s1 - s2``
     - Difference
   * - ``s1 ^ s2``
     - Symmetric difference

All operations available as ``|=`` (for example)

.. code-block:: python
   :caption: Constructing sets

   >>> s = {1, 2, 3}
   >>> s = set([1, 2, 3]) # ... or any iterable
