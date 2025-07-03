.. include:: <mmlalias.txt>


C++ - Overview Of New Language Features (Around C++20) (2025-07-02 - 2025-07-03)
================================================================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda

.. sidebar::

   * :doc:`agenda`

Day 1
-----

Smart Pointers
..............

:doc:`/trainings/material/soup/cxx11/move/index` is a complex topic to
explain. A smart pointer overview is a good thing to have anyway. Lets
start with that, and - through ``std::unique_ptr`` - get insight in what
*moving* is from a user's point of view.

From :doc:`/trainings/material/soup/cxx11/smart-pointers/index`

* :doc:`/trainings/material/soup/cxx11/smart-pointers/introduction/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/weak-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/closing-words/topic`

Rule Of Five (Three, Zero), And Move Semantics
..............................................

Another good thing to have is a rule to fight against C++'s
shortcomings. This expains how to write *copyable* and *movable*
types, likewise.

* :doc:`/trainings/material/soup/cxx11/rule-of-5/topic`
* :doc:`/trainings/material/soup/cxx11/move/index`
* :doc:`/trainings/material/soup/cxx11/perfect-forwarding/topic`, only
  to show that this is a different concept but looks syntactically
  much like *moving*.

C++ Executed At Compile Time (The ``constexpr`` Engine)
.......................................................

From :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/index`

* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/const`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/constexpr`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/consteval`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/constinit`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/if`

``std::filesystem``
...................

* :doc:`/trainings/material/soup/cxx11/filesystem/topic`

Day 2
-----

* Multithreading - eher kurz
* C++ Memory Model - s.o.
* Custom Class That Supports Brace Initialization
* Concepts
* std::span<> , Ranges And Views
* std::unordered_set<> and std::unordered_map<>
* Execution policies of parallel algorithms - frontal
* Formatting Library (std::format(), std::print())
* The Spaceship Operator <=> (And Comparison In General) - frontal
* Explicit Object Member Functions (A.k.a Deducing this)
* std::any, std::variant
