.. ot-exercise:: cxx11.exercises.bag_shared
   :dependencies: cxx11.exercises.bag_unique,
		  cxx11.smart_pointers.shared_ptr,
		  cxx11.smart_pointers.weak_ptr,
		  cxx11.new_language_features.auto,
		  cxx11.new_language_features.range_based_for

Exercise: Bag Of Items, By Shared Reference
===========================================

.. contents::
   :local:

Step 1: Transform into ``std::shared_ptr``
------------------------------------------

Continuing from :doc:`bag-unique`, create a similar class
``BagShared`` that contains pointers of type ``std::shared_ptr<Item>``
such that the tests below pass.

.. literalinclude:: code/bag-shared-basic-suite.cpp
   :caption: :download:`code/bag-shared-basic-suite.cpp`
   :language: c++

Did the ``remove_by_int()`` method have to be modified?

Step 2: Accidental Move-Insert?
-------------------------------

To make sure you did not accidentally leave the move-version of
``insert()`` from :doc:`bag-unique` in place, make sure that the
following test passes:

.. literalinclude:: code/bag-shared-insert-const-ref.cpp
   :caption: :download:`code/bag-shared-insert-const-ref.cpp`
   :language: c++

Step 3: Move-Insert, And ``std::weak_ptr``
------------------------------------------

Implement a move version of ``insert()`` that returns a
``std::weak_ptr`` to the inserted object, such that the following test
passes,

.. literalinclude:: code/bag-shared-insert-move.cpp
   :caption: :download:`code/bag-shared-insert-move.cpp`
   :language: c++

