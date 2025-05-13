.. include:: <mmlalias.txt>


Optimizations: Memory Optimizations
===================================

.. contents::
   :local:

Memory: Caches
--------------

* Access to main memory is slow
* CPU memory cache to speed access up by magnitudes
* Organized in *cache lines* ~512 bytes each
* Cache hierarchies

.. image:: 92-03-00-performance-memory-cache.dia

Locality Of Reference
---------------------

**Rules to keep caches hot**

* Group data together, so that nearby data is in the same cache line
* Use contiguous memory where possible; for example

  * Aggregation of structures
  * Sequential access in large (multidimensional?) arrays
  * Sorted arrays rather than fragmented tree structures

* Take care that data does not bounce back and forth between cache and
  main memory ("cache thrashing")
* |longrightarrow| **Locality of reference**

Multidimensional Arrays
-----------------------

.. code-block:: c
   :caption: C Array Definition

   int array[4/*rows*/][3/*columns*/];

.. list-table::
   :align: left

   * * **4x3 Matrix**

       .. image:: 92-03-00-performance-memory-array-matrix.dia

       Conceptually, a rectangular matrix

     * **Memory layout**

       .. image:: 92-03-00-performance-memory-array-layout.dia

       Physically, a linear array

Multidimensional Arrays: Cache Thrashing
----------------------------------------

* Traversing the matrix columns-first is correct
* ... **but not efficient**

.. code-block:: c

   for (j=0; j<rows; j++)
       for (i=0; i<columns; i++)
           access(array[i][j]);

.. image:: 92-03-00-performance-memory-array-layout-thrash.dia

Multidimensional Arrays: Forward Indexing
-----------------------------------------

* Always traverse array *row-first*
* "Forward indexing"
* Best **Locality of reference**

.. code-block:: c

   for (i=0; i<rows; i++)
       for (j=0; j<columns; j++)
           access(array[i][j]);

.. image:: 92-03-00-performance-memory-array-layout-ok.dia
