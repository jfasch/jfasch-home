.. include:: <mmlalias.txt>


Tuple Unpacking (Err, Structured Binding)
=========================================

.. contents::
   :local:

Basics: Python Tuple Unpacking
------------------------------

.. sidebar:: See also

   * :doc:`../auto/topic`

.. sidebar:: Documentation

   * `Structured binding declaration (since C++17)
     <https://en.cppreference.com/w/cpp/language/structured_binding>`__

* Wanted: Python tuple unpacking (that feature is based on iteration,
  a very strong concept in Python)

.. code-block:: python

   a, b, c = [1, 2, 3]   # from list
   a, b, c = (1, 2, 3)   # from tuple
   ...

* |longrightarrow| *structured binding*
* C++-ification of Python
* Comes in many flavors since C++ cares more about types, obviously
* Creates variables in surrounding scope
* *Not* based on iteration (which is also a very strong concept in
  C++)

For example ...

.. code-block:: c++

    struct point
    {
        int x, y;
    };
    point p{1,2};
    auto [x, y] = p;

Variations, Compatible Data Types
---------------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Variant
     * Meaning
   * * ``auto [...]``
     * By copy
   * * ``auto& [...]``
     * By reference
   * * ``const auto& [...]``
     * By ``const`` reference

**Works on structured data**

* ``struct``
* ``std::tuple``
* ``std::pair``
* ...

**Works on arrays too**

.. code-block:: c++

   int array[] {1, 2, 3};
   auto [x, y, z] = array;

*Not* on pointer to array;

.. code-block:: c++

   int array[] {1, 2, 3};
   int *parray = array;
   auto [x, y, z] = parray;

.. code-block:: console

   error: cannot decompose non-array non-class type ‘int*’
     25 |     const auto& [x, y, z] = array;
        |                 ^~~~~~~~~

``struct``: By Copy
-------------------

.. literalinclude:: code/c++11-structured_binding_suite--struct_copy.cpp
   :caption: :download:`code/c++11-structured_binding_suite--struct_copy.cpp`
   :language: c++

``struct``: Reference
---------------------

.. literalinclude:: code/c++11-structured_binding_suite--struct_reference.cpp
   :caption: :download:`code/c++11-structured_binding_suite--struct_reference.cpp`
   :language: c++

``struct``: By ``const`` Reference
----------------------------------

.. literalinclude:: code/c++11-structured_binding_suite--struct_const_reference.cpp
   :caption: :download:`code/c++11-structured_binding_suite--struct_const_reference.cpp`
   :language: c++

``std::tuple``: By Copy
-----------------------

.. literalinclude:: code/c++11-structured_binding_suite--tuple_copy.cpp
   :caption: :download:`code/c++11-structured_binding_suite--tuple_copy.cpp`
   :language: c++

``std::tuple``: By Reference
----------------------------

.. literalinclude:: code/c++11-structured_binding_suite--tuple_reference.cpp
   :caption: :download:`code/c++11-structured_binding_suite--tuple_reference.cpp`
   :language: c++

``std::tuple``: By ``const`` Reference
--------------------------------------

.. literalinclude:: code/c++11-structured_binding_suite--tuple_const_reference.cpp
   :caption: :download:`code/c++11-structured_binding_suite--tuple_const_reference.cpp`
   :language: c++

Arrays: By Copy
---------------

.. literalinclude:: code/c++11-structured_binding_suite--array_copy.cpp
   :caption: :download:`code/c++11-structured_binding_suite--array_copy.cpp`
   :language: c++

Arrays: By Reference
--------------------

.. literalinclude:: code/c++11-structured_binding_suite--array_reference.cpp
   :caption: :download:`code/c++11-structured_binding_suite--array_reference.cpp`
   :language: c++

Arrays: By ``const`` Reference
------------------------------

.. literalinclude:: code/c++11-structured_binding_suite--array_const_reference.cpp
   :caption: :download:`code/c++11-structured_binding_suite--array_const_reference.cpp`
   :language: c++


