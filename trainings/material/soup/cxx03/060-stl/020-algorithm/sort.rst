.. include:: <mmlalias.txt>


.. sidebar:: Documentation

   * `std::sort <https://en.cppreference.com/w/cpp/algorithm/sort>`__
     @ `cppreference.com <https://cppreference.com>`__
   * `std::sort
     <http://www.cplusplus.com/reference/algorithm/sort/>`__ @
     `cplusplus.com <https://cplusplus.com>`__

``sort<>``
==========

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

Live Hacking
------------

.. literalinclude:: code/sort.cpp
   :caption: :download:`code/sort.cpp`
   :language: c++
