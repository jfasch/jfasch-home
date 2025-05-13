.. include:: <mmlalias.txt>


Pointers and Arrays
===================

.. contents::
   :local:

It's Only Memory
----------------

**Pointers and arrays** are closely related to each other

* Automatic conversion array |longrightarrow| pointer
* Array-type function parameters are in fact pointers to the first (0-th) array element
* Index operator (``a[i]``) is *pointer arithmetic*
* *True strength of C*

.. code-block:: c

   int a[] = { 42, 1, 23 };
   char str[] = { 'h', 'a', 'l', 'l', 'o', '\0' };
   
   int *pa1 = &a[0];
   int *pa2 = a;

Conversion Array |longrightarrow| Pointer
-----------------------------------------

.. list-table::
   :align: left

   * * .. code-block:: c

          int a[3];
          int *pa1 = &a[0];
          int *pa2 = a;

     * 

       .. image:: 05-03-00-conv-pointer-array.dia

Pointer Arithmetic (1)
----------------------

.. list-table::
   :align: left

   * * **Pointer and array index**

       * *Pointer + Integer = Pointer*
       * Equivalent to subscript ("index") operator
       * Just like subscript *there is no range check being made*
       * |longrightarrow| Errors happen
       * *But*: performance!

     * 

       .. image:: 05-03-00-pointer-plus-int.dia

       .. image:: 05-03-00-pointer-plus-int-error.dia

Pointer Arithmetic (2)
----------------------

.. list-table::
   :align: left

   * * **Pointer increment**

       .. code-block:: c

	  int *pa = a;
	  ++pa;

     * 

       .. image:: 05-03-00-pointer-increment.dia

   * * **Pointer decrement**

       .. code-block:: c

	  int *pa = &a[1];
	  --pa;

     *
     
       .. image:: 05-03-00-pointer-decrement.dia

Pointer Arithmetic (3)
----------------------

**Pointers don't necessarily point to something that is valid** ...

.. list-table::
   :align: left

   * * .. code-block:: c
     
          pa = a + 4;  // or "pa += 4"
	  pa -= 2;
	  i = *pa; /* ok */

     * 

       .. image:: 05-03-00-pointer-out-of-range.dia

   * * .. code-block:: c

          pa = a - 1;
          pa += 2;
          i = *pa; /* ok */

     * 

       .. image:: 05-03-00-pointer-out-of-range-negative.dia

Pointer Arithmetic: Difference
------------------------------

**How many elements are there between two pointers?**

.. list-table::
   :align: left

   * * .. code-block:: c

          p = &a[0];
          q = &a[3];   // *one past* last valid element
          num = q - p; /* 2 */

     * 

       .. image:: 05-03-00-pointer-diff.dia

**Often (C++ STL) it is done like so:**

* *Beginning* of an array ("a set of elements") is the *pointer to the
  first element*
* *End* is *pointer to one past the last valid element*

Pointer Arithmetic: Array Algorithms
------------------------------------

**Iterating over all elements of the array**

.. code-block:: c

   int sum(const int *begin, const int *end)
   {
       int sum = 0;
   
       while (begin < end)
           sum += *begin++; /* precedence? what? */
       return sum;
   }

.. list-table::
   :align: left

   * * 

       .. image:: 05-03-00-pointer-begin-end.dia

     * **Beautiful, isn't it?**

Pointer Arithmetic: Jump Width? (1)
-----------------------------------

**So far:** pointer to ``int`` - how are arrays of other (even
compound) types handled?

|longrightarrow| just the same!

* *Pointer + n*: points *n* elements further
* Type system is not stupid (only sometimes)
* Pointer know *which type* is being pointed to
* Be careful with ``void`` and ``void*``: ``sizeof(void)`` is *undefined*!

Pointer Arithmetic: Jump Width? (2)
-----------------------------------

.. code-block:: c

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

Pointer Arithmetic: Arbitrary Datatypes
---------------------------------------

.. list-table::
   :align: left

   * * * ``sizeof``: size (in bytes) of a type/variable
     
       .. code-block:: c

          sizeof(int)
          sizeof(struct point)
          sizeof(i)
          sizeof(pi)
          sizeof(pp)

     * 
     
       .. image:: 05-03-00-pointer-plus-int-generalized.dia

