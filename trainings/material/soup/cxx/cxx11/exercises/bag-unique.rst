Exercise: Bag Of Items, By Unique Reference
===========================================

Continuing from :doc:`bag-copy`, create a similar class ``BagUnique``
that contains pointers of type ``std::unique_ptr<Item>`` such that the
tests below pass.

Special features:

* Find out: what would the return type of ``find_by_int() const`` be?

  * Can it be the vector's member type, a ``std::unique_ptr<Item>``?
    Why not?
  * A ``const std::unique_ptr<Item>&`` maybe? Why not?

* Try to create a ``std::unique_ptr<Item>`` and assign it to variable
  which you then insert, like (naively)

  .. code-block:: c++

     auto v = std::make_unique<BagUnique::Item>("something", 42);
     bag.insert(v);

  Does it work? What do you notice?

.. literalinclude:: code/bag-unique-suite.cpp
   :caption: :download:`code/bag-unique-suite.cpp`
   :language: c++

