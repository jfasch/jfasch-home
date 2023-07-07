.. include:: <mmlalias.txt>


Agenda: C++: Advanced Topics
============================

.. contents::
   :local:

Introduction
------------

* :doc:`/trainings/material/soup/cxx11/010-introduction/history`
* :doc:`/trainings/material/soup/cxx11/010-introduction/overview-livehacking`

Pythonicity (Thank You: Readablility and Writability)
-----------------------------------------------------

Range Based for Loops
.....................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for-map`

Tuple Unpacking (err, Structured Binding)
.........................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`

Duck Typing (err, ``auto``) Without A Duck
..........................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`

Exercise
........

* :doc:`/trainings/material/soup/cxx11/exercises/bag-copy`

  `Solution on Github: bag-copy.h
  <https://github.com/jfasch/2022-07-26/blob/main/exercises/bag-copy.h>`__

Things That Simply Deserved Fixing Since Ages
---------------------------------------------

Brace Initialization
....................

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/intro`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/implementor-view`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/mess`

New OO keywords: override, final, default, delete
.................................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`

Strongly Typed enum
...................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/010-strongly-typed-enums/topic`

Delegating Constructor
......................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/050-delegating-ctor/topic`

``nullptr``
...........

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/070-miscellaneous/topic`

``constexpr``, ``constinit``, ``consteval``
-------------------------------------------

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/055-constexpr/topic`
* ``constinit``
* ``consteval``

Smart Pointers, And Move Semantics
----------------------------------

* From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`:

  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction-livehack`
  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
  * :doc:`/trainings/material/soup/cxx11/exercises/bag-unique`
  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
  * :doc:`/trainings/material/soup/cxx11/exercises/bag-shared`
  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

* Moving, “RValue References”

  Put emphasis on *Rule Of Five*!

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/group`
  * :doc:`/trainings/material/soup/cxx11/035-perfect-forwarding/topic`
    (a feature which shares the syntax with moving in that it uses
    ``&&``, but is something completely different)

Types, Functions, Type Erasure, Toolcase
----------------------------------------

A broader view of interfaces, and what can be done about it.

Functions (``std::function<>``, Lambdas)
........................................

* From :doc:`/trainings/material/soup/cxx11/040-bind-function/group`:

  * :doc:`/trainings/material/soup/cxx11/040-bind-function/010-bind/topic`
  * :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`

* From :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor-pitfall`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`

Type Erasure
............

* *Type erasure*: what is that, and why?
* Solutions

C++ Toolcase
............

* ``std::any``
* ``std::optional``
* ``std::variant``

Dynamic Versus Static Typing: Templates
.......................................

* From :doc:`/trainings/material/soup/cxx03/050-templates/group`

  * :doc:`/trainings/material/soup/cxx03/050-templates/010-function-templates/topic`
  * :doc:`/trainings/material/soup/cxx03/050-templates/020-class-templates/topic`

* Type traits

Concepts
........

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/group`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/intro`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/writing-concepts`

Multithreading
--------------

From :doc:`/trainings/material/soup/cxx11/050-multithreading/group`:

* :doc:`/trainings/material/soup/cxx11/050-multithreading/010-introduction/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/030-race-conditions/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/scoped-locking`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`

Outlook In ``>=20``
-------------------

* From :doc:`/trainings/material/soup/cxx11/020-new-language-features/ranges/group`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/ranges/intro`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/ranges/good-bad`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/coroutines/intro`

Miscellaneous
-------------

Attributes And The Like
.......................

* [[nodiscard]]: Was bedeutet das?
* [[fallthrough]]: Was bedeutet das?
* noexcept

``<algorithm>`` Overview
........................

* ``std::transform``
* ``std::find``
* ``std::find_if``
* ``std::lower_bound``
* ...

Miscellaneous Miscellaneous
...........................

* const overloading
* user-defined literals
* ``std::string_view``
