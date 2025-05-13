.. include:: <mmlalias.txt>


Standard Template Library: Basics
=================================

.. contents::
   :local:

.. toctree::
   :hidden:

   pointer-arith-basics
   pointer-arith-out-of-range
   pointer-arith-difference
   pointer-arith-algo
   algo-copy

Containers, Iterators, Algorithms
---------------------------------

**Genius Combination of ...**

* Operator overloading (``->``, ``*``, ``+``, ``+=``, ``++``)
* Abstract *containers*
* Abstract *algorithms*
* ... based upon *pointer arithmetic*!

|longrightarrow| *Pointer arithmetic*, revisited ...

Blahblah
--------

.. list-table::
   :align: left

   * * **Pointer and array index**

       * *Pointer + Integer = Pointer*
       * Exactly the same as subscript ("index") operator
       * *No range check*
       * |longrightarrow| Error prone
       * But: performance!

     * * 

         .. image:: 40-10-00-pointer-plus-int.dia
	    :scale: 40%

       * 

         .. image:: 40-10-00-pointer-plus-int-error.dia
	    :scale: 40%

Pointer Increment and Decrement
-------------------------------

.. sidebar::

   **Live Hacking**

   * :doc:`pointer-arith-basics`

.. list-table::
   :align: left

   * * **Pointer Increment**

       .. code-block:: c++

	  int *pa = a;
	  ++pa;

     * 
     
       .. image:: 40-10-00-pointer-increment.dia
	  :scale: 40%

   * * **Pointer Decrement**

       .. code-block:: c++

	  int *pa = &a[1];
	  --pa;

     * 

       .. image:: 40-10-00-pointer-decrement.dia
	  :scale: 40%

Out Of Range Errors (The Spirit Of C)
-------------------------------------

.. sidebar::

   **Live Hacking**

   * :doc:`pointer-arith-out-of-range`

**Pointers don't necessarily point to valid memory locations ...**

.. list-table::
   :align: left

   * * .. code-block:: c++

          *pa = a + 4;
	  pa -= 2;
	  i = *pa; /* ok */

     * 

       .. image:: 40-10-00-pointer-out-of-range.dia
	  :scale: 40%

   * * .. code-block:: c++

          *pa = a - 1;
	  pa += 2;
	  i = *pa; /* ok */

     *

       .. image:: 40-10-00-pointer-out-of-range-negative.dia
	  :scale: 40%

Pointer Difference
------------------

.. sidebar::

   **Live Hacking**

   * :doc:`pointer-arith-difference`

**How many array elements are there between two pointers?**

.. list-table::
   :align: left

   * * .. code-block:: c++

          p = &a[0];
	  q = &a[2];
	  num = q - p;      /* 2 */

     *

       .. image:: 40-10-00-pointer-diff.dia
	  :scale: 40%

**General practice ("The Spirit of C"):** [#no-spirit]_

* *Beginning* of an array (a *set* of elements) is a *pointer to the
  first element*
* *End* is *pointer past the last element*

Step Width? (1)
---------------

**So far:** pointer to ``int`` - how about different datatypes?

|longrightarrow| same!

* *pointer + n*: points to the *n*-th array element from *pointer*
* Type system knows about sizes
* Pointer knows the type of the data it points to
* Careful with ``void`` and ``void*``

Step Width? (2)
---------------

.. code-block:: c++

   struct point
   {
       int x, y;
   };
   
   struct point points[3], *begin, *end;
   
   begin = points;
   end = points + sizeof(points)/sizeof(struct point);
   
   while (begin < end) {
       ...
       ++begin;
   }

And Arbitrary Data Types?
-------------------------

.. list-table::
   :align: left

   * * *sizeof*: size (in bytes) of a type or variable

       .. code-block:: c++

          sizeof(int)
          sizeof(struct point)
          sizeof(i)
          sizeof(pi)
	  sizeof(pp)

     * 

       .. image:: 40-10-00-pointer-plus-int-generalized.dia
	  :scale: 40%

Enter Algorithms (On Good Old C Arrays)
---------------------------------------

.. sidebar::

   **Live Hacking**

   * :doc:`pointer-arith-algo`

* Iteration over all elements of an array
* ``begin``: pointer to first element, *inclusive*
* ``end``: pointer past last element, *exclusive*
* |longrightarrow| *range* ``[begin, end)``

.. code-block:: c++

   int sum(const int *begin, const int *end)
   {
       int sum = 0;
   
       while (begin < end)
           sum += *begin++; /* precedence? what? */
       return sum;
   }

.. code-block:: c++

   void copy(const int *src_begin, const int *src_end, int *dst_begin)
   {
       while (src_begin != src_end)
           *dst_begin++ = *src_begin++;
   }
   
.. list-table::
   :align: left

   * * 

       .. image:: 40-10-00-pointer-begin-end.dia
	  :scale: 40%

     * **Pretty, isn't it?**

STL Algorithms
--------------

.. sidebar::

   **Documentation**

   * `C++ algorithms <https://en.cppreference.com/w/cpp/algorithm>`__

   **Live Hacking**

   * :doc:`algo-copy`

* ``#include <algorithm>``
* Many general purpose algorithms
* One of the simplest: ``std::copy<>()``

STL Containers
--------------

**Container**

* Extremely practical collection of template classes
* Sequential container |longrightarrow| array, list
* Associative containers


.. rubric:: Footnotes

.. [#no-spirit] `Dennis Ritchie
		<https://en.wikipedia.org/wiki/Dennis_Ritchie>`_ once
		said, though, that *C has no spirit*.
