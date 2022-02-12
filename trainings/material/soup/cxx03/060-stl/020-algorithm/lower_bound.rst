.. ot-topic:: cxx03.stl.algorithm.lower_bound
   :dependencies: cxx03.stl.algorithm.binary_search,
		  cxx03.stl.basics, 
		  cxx03.stl.algorithm.sort

.. include:: <mmlalias.txt>


.. sidebar:: Documentation

   * `std::lower_bound
     <https://en.cppreference.com/w/cpp/algorithm/lower_bound>`__ @
     `cppreference.com <https://cppreference.com>`__
   * `std::lower_bound
     <http://www.cplusplus.com/reference/algorithm/lower_bound/>`__
     @ `cplusplus.com <https://cplusplus.com>`__

``lower_bound<>``: On Sorted Sequence
=====================================

.. contents::
   :local:

More Intelligent Search
-----------------------

* **Result**: Pointer/iterator to element found *or past*
* |longrightarrow| very flexible

.. code-block:: c++

   std::vector<int> int_array;
   int_array.push_back(7);
   int_array.push_back(42);
   int_array.push_back(42);
   int_array.push_back(666);
   
   std::vector<int>::const_iterator lower = 
       std::lower_bound(int_array.begin(), int_array.end(), 42);
   while (lower != int_array.end() && *lower == 42) {
       std::cout << *lower << std::endl;
       ++lower;
   }
