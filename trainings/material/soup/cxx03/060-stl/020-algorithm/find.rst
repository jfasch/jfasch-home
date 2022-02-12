.. ot-topic:: cxx03.stl.algorithm.find
   :dependencies: cxx03.stl.basics

.. include:: <mmlalias.txt>


.. sidebar:: Documentation

   * `std::find_if
     <https://en.cppreference.com/w/cpp/algorithm/find>`__ @
     `cppreference.com <https://cppreference.com>`__
   * `std::find_if
     <http://www.cplusplus.com/reference/algorithm/find_if/>`__ @
     `cplusplus.com <https://cplusplus.com>`__

``find<>``: Sequential Search, by Equality
==========================================

.. contents::
   :local:

Basic Usage
-----------

**Search** at its simplest: linearly for *equality*

.. code-block:: c++

   int int_array_c[] = { 34, 45, 1, 3, 2, 666 };
   
   const int *found = std::find(int_array_c, int_array_c+6, 3);
   if (found == int_array_c+6)
       std::cout << "not found" << std::endl;
   else 
       std::cout << *found << std::endl;

**Attention**: "not found" |DoubleLeftRightArrow| pointer one past the
last element

Not Found?
----------

**Important concept**: "not found" |DoubleLeftRightArrow| pointer past
the last element

.. image:: begin-end.dia

.. code-block:: c++

   std::vector<int> int_array;
   // ...
   
   std::vector<int>::const_iterator found = 
       std::find(int_array.begin(), int_array.end(), 7);
   if (found == int_array.end())
       std::cout << "not found" << std::endl;
   else 
       std::cout << *found << std::endl;

