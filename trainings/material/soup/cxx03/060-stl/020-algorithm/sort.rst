.. ot-topic:: cxx03.stl.algorithm.sort
   :dependencies: cxx03.stl.basics

.. include:: <mmlalias.txt>


``std::sort``
=============

.. contents::
   :local:

Algorithm: ``std::sort``
------------------------

Now for something simple ...

.. code-block:: c++
   :caption: Sorting a C array

   int int_array[] = { 34, 45, 1, 3, 2, 666 };
   std::sort(int_array, int_array + 6);

.. code-block:: c++
   :caption: Sorting a C++ ``vector``

   std::vector<int> int_array;
   int_array.push_back(42);
   int_array.push_back(7);
   int_array.push_back(666);
   
   std::sort(int_array.begin(), int_array.end());

Algorithm: ``std::sort``, custom comparison
-------------------------------------------

.. code-block:: c++

   bool less_reverse(int l, int r)
   {
       return l > r;
   }
   
   int int_array[] = { 34, 45, 1, 3, 2, 666 };
   std::sort(int_array, int_array + 6, less_reverse);
