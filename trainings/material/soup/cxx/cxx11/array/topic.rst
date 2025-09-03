.. include:: <mmlalias.txt>


std::array
==========

.. sidebar:: Documentation

   * `std::array
     <https://en.cppreference.com/w/cpp/container/array.html>`__

Problem: C Arrays
-----------------

* *Decay* to pointers to first element
* Cannot be copied *using only the language*
* Clumsy code to determine length

  * Sentinel value, like ``'\0'`` on C strings 
  * Pass length together with pointer

* Compiler cannot help on out-of-bounds

``std::array`` To The Rescue
----------------------------

.. code-block:: c++

   #include <array>
   std::array<int, 3> a;

* Implemented as ``struct``
* Copy done by the language
* *Does not decay* to anything
* Size is part of the type
* Simple and efficient

Basic Usage
-----------

* No constructor defined
* Implemented as `struct`` |longrightarrow| initializer list for free
* *Attention*: default constructor leaves elements *undefined*

.. literalinclude:: code/basic.cpp
   :caption: :download:`code/basic.cpp`
   :language: c++

Initialization
--------------

* Like C aggregate (struct/array) initialization
* |longrightarrow| uninitialized elements initialized 0 (or default,
  respectively)

.. literalinclude:: code/initialization.cpp
   :caption: :download:`code/initialization.cpp`
   :language: c++

* Type and size deduced from initializer (since C++17?)

.. literalinclude:: code/deducing_type.cpp
   :caption: :download:`code/deducing_type.cpp`
   :language: c++

Copy And Equality
-----------------

* This easiest: ``std::array`` is a ``struct``
* |longrightarrow| Compiler generated

.. literalinclude:: code/copy.cpp
   :caption: :download:`code/copy.cpp`
   :language: c++

.. literalinclude:: code/equality.cpp
   :caption: :download:`code/equality.cpp`
   :language: c++

* ``constexpr``, because it is so easy
* Like most methods

.. literalinclude:: code/constexpr_equality.cpp
   :caption: :download:`code/constexpr_equality.cpp`
   :language: c++

Works With Range-For, Structured Binding, And Algorithms
--------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/range-for/index`
   * :doc:`/trainings/material/soup/cxx/cxx11/structured-binding/topic`

.. literalinclude:: code/range_for.cpp
   :caption: :download:`code/range_for.cpp`
   :language: c++

.. literalinclude:: code/structured_binding.cpp
   :caption: :download:`code/structured_binding.cpp`
   :language: c++

.. literalinclude:: code/sort.cpp
   :caption: :download:`code/sort.cpp`
   :language: c++

