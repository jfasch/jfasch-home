.. ot-topic:: cxx11.miscellaneous.variant

.. include:: <mmlalias.txt>


New-Style Union: ``std::variant``
=================================

.. sidebar:: Documentation

   * `std::variant
     <https://en.cppreference.com/w/cpp/utility/variant>`__

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/group`

.. contents::
   :local:

Problems With C Unions, And C++ Types
-------------------------------------

* ``union`` with C++ *can* be gotten right

  * It's just unlikely

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

The Visitor
-----------

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

``std::string`` And ``const char*`` Are Different
-------------------------------------------------

.. literalinclude:: code/variant-string-and-charp.cpp
   :caption: :download:`code/variant-string-and-charp.cpp`
   :language: c++

And User Defined Types?
-----------------------

.. literalinclude:: code/variant-no-default-ctor.cpp
   :caption: :download:`code/variant-no-default-ctor.cpp`
   :language: c++
