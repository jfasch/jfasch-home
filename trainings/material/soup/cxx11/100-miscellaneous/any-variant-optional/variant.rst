.. include:: <mmlalias.txt>


New-Style Union: ``std::variant``
=================================

.. sidebar::

   **Documentation**

   * `std::variant
     <https://en.cppreference.com/w/cpp/utility/variant>`__

Problems With C Unions, And C++ Types
-------------------------------------

* ``union`` with C++ can be gotten right
* Need to call destructors explicitly
* Other weirdnesses
* |longrightarrow| *no!*
* |longrightarrow| ``std::variant``

Instantiation, Default Initialization, Member Access
----------------------------------------------------

.. literalinclude:: code/variant-default_ctor.cpp
   :caption: :download:`code/variant-default_ctor.cpp`
   :language: c++

Non-Default Initialization
--------------------------

.. literalinclude:: code/variant-converting_ctor.cpp
   :caption: :download:`code/variant-converting_ctor.cpp`
   :language: c++

Accessing Non-Current Member: ``std::bad_variant_access``
---------------------------------------------------------

.. literalinclude:: code/variant-bad-access.cpp
   :caption: :download:`code/variant-bad-access.cpp`
   :language: c++

.. literalinclude:: code/variant-visit.cpp
   :caption: :download:`code/variant-visit.cpp`
   :language: c++

Non-Throwing Accessor: ``std::get_if<>``
----------------------------------------

* Exceptions are bad (at least in Embedded) 
* |longrightarrow| back to pointers |:metal:|

.. literalinclude:: code/variant-get-if.cpp
   :caption: :download:`code/variant-get-if.cpp`
   :language: c++

And Non-Fundamental Types?
--------------------------

.. literalinclude:: code/variant-string-and-charp.cpp
   :caption: :download:`code/variant-string-and-charp.cpp`
   :language: c++

.. literalinclude:: code/variant-no-default-ctor.cpp
   :caption: :download:`code/variant-no-default-ctor.cpp`
   :language: c++

