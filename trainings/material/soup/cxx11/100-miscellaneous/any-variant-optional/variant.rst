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

And Memory Usage?
-----------------

* Not defined by standard
* Results presented are from GCC

  .. code-block:: console

     $ gcc --version
     gcc (GCC) 13.3.1 20240913 (Red Hat 13.3.1-3)
     Copyright (C) 2023 Free Software Foundation, Inc.
     This is free software; see the source for copying conditions.  There is NO
     warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

* What does make sense?
* |longrightarrow| A typesafe union has to carry a type discriminator:
  at least as wide as a ``uint8_t`` for < 256 different types

.. sidebar:: See also

   * :doc:`/trainings/material/soup/c/080-advanced-language-features/030-alignment/topic`

.. literalinclude:: code/variant-mem-usage-2-uint8.cpp
   :caption: :download:`variant-mem-usage-2-uint8.cpp
             <code/variant-mem-usage-2-uint8.cpp>`
   :language: c++

.. code-block:: console

   $ ./c++11-variant-mem-usage-2-uint8 
   2
