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

:doc:`/trainings/material/soup/cxx/cxx11/move/index` is a complex topic to
explain. A smart pointer overview is a good thing to have anyway. Lets
start with that, and - through ``std::unique_ptr`` - get insight in what
*moving* is from a user's point of view.

From :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/index`

* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/introduction/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/weak-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/closing-words/topic`

Rule Of Five (Three, Zero), And Move Semantics
..............................................

Another good thing to have is a rule to fight against C++'s
shortcomings. This expains how to write *copyable* and *movable*
types, likewise.

* :doc:`/trainings/material/soup/cxx/cxx11/rule-of-5/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/move/index`
* :doc:`/trainings/material/soup/cxx/cxx11/perfect-forwarding/topic`, only
  to show that this is a different concept but looks syntactically
  much like *moving*.

C++ Executed At Compile Time (The ``constexpr`` Engine)
.......................................................

That was a bit Involved - `Compiler Explorer
<https://godbolt.org/>`__, looking into objects with ``nm``, and all
that. Finally the conclusion was that template metaprogramming has
become obsolete |:kissing_heart:|.

From :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/index`

* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/const`
* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/constexpr`
* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/consteval`
* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/constinit`
* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/if`

``std::filesystem``
...................

There was some time left on that day, and ``std::filesystem`` is just
small enough to fill the gap.

* :doc:`/trainings/material/soup/cxx/cxx11/filesystem/topic`

Day 2
-----

Multithreading, Memory Model
............................

C++20 brings :doc:`Atomic Shared Pointer
</trainings/material/soup/cxx/cxx11/multithreading/atomic-shared-ptr/topic>` -
a review of threading, *race conditions*, atomics, and the C++ memory
model is in order.

* From :doc:`/trainings/material/soup/cxx/cxx11/multithreading/index`

  * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/memory-model/topic`. This
    briefly shows what a race condition is, and gives mutex examples.

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/atomic-shared-ptr/topic`. 

``std::span``, Ranges, Views, Concepts
......................................

An outlook how C++20 redefines (again) the way C++ programs are
written. The guys liked it, and started to use ranges in their code as
soon as we took the next break.

* :doc:`/trainings/material/soup/cxx/cxx11/span/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/ranges/index`
* From :doc:`/trainings/material/soup/cxx/cxx11/concepts/index`

  * :doc:`/trainings/material/soup/cxx/cxx11/concepts/intro/topic`
  * :doc:`/trainings/material/soup/cxx/cxx11/concepts/writing-concepts/topic`

All The Rest
............

* Looked over `cppreference.com <https://en.cppreference.com/>`__'s
  docs on `std::unordered_set
  <https://en.cppreference.com/w/cpp/container/unordered_set.html>`__
  and `std::unordered_map
  <https://en.cppreference.com/w/cpp/container/unordered_map.html>`__. Discussed
  difference between hash tables and red-black trees.
* :doc:`/trainings/material/soup/cxx/cxx11/drafts/parallel-algo/topic`. I
  hadn't gotten that to work, so only a frontal presentation of how it
  *should* work was given.
* :doc:`/trainings/material/soup/cxx/cxx11/format/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/spaceship/topic`. Presented
  frontally.
* :doc:`/trainings/material/soup/cxx/cxx11/deducing-this/topic`. Presented
  frontally, trying to understand what this particular feature brings
  (again, redefine the way C++ is written |:sleeping:|)
* :doc:`/trainings/material/soup/cxx/cxx11/any-variant-optional/index`. Frontally showing the API, discussing usage scenarios.
* Coroutines? Generators?
  (:doc:`/trainings/material/soup/cxx/cxx11/coroutines/index`). Material
  is a little outdated and not up to date with C++20. I had gotten a
  Python style generator to work with what was there (general
  coroutines). Discussed what that was, and the difference between it
  and multithreading.
