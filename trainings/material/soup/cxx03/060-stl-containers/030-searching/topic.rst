.. include:: <mmlalias.txt>

.. jf-topic:: cxx03.stl.searching
   :dependencies: cxx03.stl.sorting


Searching
=========

Algorithms: ``std::find``
-------------------------

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

Algorithms: ``std::find`` - ``end()``
-------------------------------------

**Important concept**: "not found" |DoubleLeftRightArrow| pointer past
the last element

.. code-block:: c++

   std::vector<int> int_array;
   // ...
   
   std::vector<int>::const_iterator found = 
       std::find(int_array.begin(), int_array.end(), 7);
   if (found == int_array.end())
       std::cout << "not found" << std::endl;
   else 
       std::cout << *found << std::endl;

More Intelligent Search: ``std::binary_search``
-----------------------------------------------

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
* Searching for data?

More Intelligent Search: ``std::lower_bound``
---------------------------------------------

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
