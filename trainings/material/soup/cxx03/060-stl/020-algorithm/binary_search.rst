.. ot-topic:: cxx03.stl.algorithm.binary_search
   :dependencies: cxx03.stl.basics, cxx03.stl.algorithm.sort

.. include:: <mmlalias.txt>


.. sidebar:: Documentation

   * `std::binary_search <https://en.cppreference.com/w/cpp/algorithm/binary_search>`__
     @ `cppreference.com <https://cppreference.com>`__
   * `std::binary_search
     <http://www.cplusplus.com/reference/algorithm/binary_search/>`__
     @ `cplusplus.com <https://cplusplus.com>`__

``binary_search<>``: On Sorted Sequence
=======================================

.. contents::
   :local:

More Intelligent Search
-----------------------

**When things are sorted, they give a better search**

* Sorted ``std::vector``
* |longrightarrow| more efficient search
* |longrightarrow| *binary* search

.. code-block:: c++

   int int_array[] = { 34, 45, 1, 3, 2, 666 };
   std::sort(int_array, int_array+6);
   bool found = std::binary_search(int_array, int_array+6, 3);

**Problem**

* One can only decide whether the element is contained
* Searching for data? |longrightarrow| See :doc:`lower_bound`

Live Hacking
------------

.. literalinclude:: code/binary_search.cpp
   :caption: :download:`code/binary_search.cpp`
   :language: c++
