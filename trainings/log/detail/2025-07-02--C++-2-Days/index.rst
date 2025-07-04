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

Multithreading, Memory Model
............................

This section is a bit involved as all of this is somehow related.

* From :doc:`/trainings/material/soup/cxx11/multithreading/index`

  * :doc:`/trainings/material/soup/cxx11/multithreading/memory-model/topic`. This
    briefly shows what a race condition is, and gives mutex examples.

* :doc:`/trainings/material/soup/cxx11/multithreading/atomic-shared-ptr/topic`. 

``std::span``, Ranges, Views, Concepts
......................................

* :doc:`/trainings/material/soup/cxx11/span/topic`
* :doc:`/trainings/material/soup/cxx11/ranges/index`
* From :doc:`/trainings/material/soup/cxx11/concepts/index`

  * :doc:`/trainings/material/soup/cxx11/concepts/intro/topic`
  * :doc:`/trainings/material/soup/cxx11/concepts/writing-concepts/topic`

Rest
....

.. * Custom Class That Supports Brace Initialization
..   (:doc:`/trainings/material/soup/cxx11/brace-initialization/index`)

* std::unordered_set<> and std::unordered_map<>
* Execution policies of parallel algorithms - frontal
  (:doc:`/trainings/material/soup/cxx11/drafts/parallel-algo/topic`)
* Formatting Library (std::format(), std::print())
  (:doc:`/trainings/material/soup/cxx11/format/topic`)
* The Spaceship Operator <=> (And Comparison In General) - frontal
  (:doc:`/trainings/material/soup/cxx11/spaceship/topic`)
* Explicit Object Member Functions (A.k.a Deducing this)
  (:doc:`/trainings/material/soup/cxx11/deducing-this/topic`)
* std::any, std::variant
  (:doc:`/trainings/material/soup/cxx11/any-variant-optional/index`)
* Coroutines? Generators?
  (:doc:`/trainings/material/soup/cxx11/coroutines/index`)
