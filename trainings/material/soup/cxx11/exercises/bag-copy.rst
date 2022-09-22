.. ot-exercise:: cxx11.exercises.bag_copy
   :dependencies: cxx11.new_language_features.auto,
		  cxx11.new_language_features.range_based_for

Exercise: Bag Of Items, By Copy
===============================

.. contents::
   :local:

Step 1: *Insert*, *Find* 
------------------------

Write a class ``BagCopy`` that 

* contains objects of a nested ``Item`` class *by copy*
* uses a ``std::vector`` internally

The class supports the methods

* ``insert()``
* ``find_by_int() const`` (try to use :doc:`range based for
  <..//020-new-language-features/range-based-for>` in the
  implementation)

Make the following tests pass:

.. literalinclude:: code/bag-copy-insert-find-suite.cpp
   :caption: :download:`code/bag-copy-insert-find-suite.cpp`
   :language: c++

Step 2: *Remove*
----------------

.. sidebar::

   **Documentation**

   * `std::vector::erase
     <https://en.cppreference.com/w/cpp/container/vector/erase>`__

Implement a ``remove_by_int()`` method such that the following test
passes. Read careful how the return value of the `erase() method
<https://en.cppreference.com/w/cpp/container/vector/erase>`__ of
``std::vector`` is used to modify a container while iterating over it.

Make the following test pass:

.. literalinclude:: code/bag-copy-remove-suite.cpp
   :caption: :download:`code/bag-copy-remove-suite.cpp`
   :language: c++
