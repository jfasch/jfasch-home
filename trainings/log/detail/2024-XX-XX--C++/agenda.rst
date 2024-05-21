.. include:: <mmlalias.txt>


Agenda: C++: A Thorough Overview
================================

.. contents::
   :local:

Basics
------

Introduction
............

* :doc:`/trainings/material/soup/cxx03/001-introduction/topic`

Data Encapsulation
..................

From :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/group`

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/c`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/initializer-list`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/copy-basics`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete` (C++ 11)
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/default` (C++ 11)

Functions and Methods
.....................

From :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/group`

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/010-overloading/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/030-const/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/040-this/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/060-static/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/065-static-member-variables/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`

C++ Template Basics
...................

From :doc:`/trainings/material/soup/cxx03/050-templates/group`

* :doc:`/trainings/material/soup/cxx03/050-templates/010-function-templates/topic`
* :doc:`/trainings/material/soup/cxx03/050-templates/020-class-templates/topic`

Inheritance And Object Oriented Design
......................................

From :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`

* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/private-protected`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/override` (C++ 11)
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/final` (C++ 11)
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

More From C++ 11
----------------

* :doc:`/trainings/material/soup/cxx11/010-introduction/overview-livehacking`

Present these in an overview style, going into detail when
appropriate/desired.

Optional But Useful Language Features
.....................................

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/group`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/050-delegating-ctor/topic`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/intro`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/implementor-view`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/mess`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor-pitfall`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`

Optional: Pointer Classes
.........................

From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction-livehack`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

Move Semantics, Rvalue References (You Will Die If You Don't Know What That Is)
...............................................................................

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/group`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/afterword`

Optional: Perfect Forwarding (Looks Like Moving But Isn't)
..........................................................

* :doc:`/trainings/material/soup/cxx11/035-perfect-forwarding/topic`

Optional: Algorithms And Containers (*Very* Useful Though)
----------------------------------------------------------

From :doc:`/trainings/material/soup/cxx03/060-stl/group`

* :doc:`/trainings/material/soup/cxx03/060-stl/010-basics/topic`
* :doc:`/trainings/material/soup/cxx03/060-stl/015-vector-copy-etc/topic`
* :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/group`
* :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/group`
* :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/group`
* :doc:`/trainings/material/soup/cxx03/060-stl/allocators/group`

Useful Embedded Topics
----------------------

``constexpr``, ``constinit``, ``consteval``
...........................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/055-constexpr/topic`
* ``constinit``
* ``consteval``

Omitting ``virtual``
....................

From
:doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/group`

* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/why-replace-virtual`
* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/classic-virtual`
* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/related-no-virtual`
* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/unrelated`
* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/variant-manual-if`
* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/variant-manual-visit`
* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/variant-automatic-visit`
* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/type-erasure`

Allocators (Using Container Templates In The Absence Of A Heap)
...............................................................

* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/allocator`

Project Sanity/Management
-------------------------

CMake Intro: Project Structure
..............................

From :doc:`/trainings/material/soup/cmake/group`

* :doc:`/trainings/material/soup/cmake/basics`
* :doc:`/trainings/material/soup/cmake/libraries`
* :doc:`/trainings/material/soup/cmake/shared-libraries`
* :doc:`/trainings/material/soup/cmake/installation`
* :doc:`/trainings/material/soup/cmake/structure`

Unit Testing With googletest
............................

From :doc:`/trainings/material/soup/unittest/group`

* :doc:`/trainings/material/soup/unittest/unittest_gtest_basics/topic`
* :doc:`/trainings/material/soup/unittest/unittest_gtest_cmake/topic`
* :doc:`/trainings/material/soup/unittest/unittest_gtest_fixture/topic`
* Mocking? Interfaces? Simulating hardware?

Performance
...........

From :doc:`/trainings/material/soup/c/100-performance/group`

* :doc:`/trainings/material/soup/c/100-performance/010-introduction/topic`
* :doc:`/trainings/material/soup/c/100-performance/020-computebound/topic`
* :doc:`/trainings/material/soup/c/100-performance/030-memory/topic`

Software Design
...............

* Dependency Injection and *Dependency Management*
* From :doc:`/trainings/material/soup/cxx-design-patterns/group`

  * :doc:`/trainings/material/soup/cxx-design-patterns/adapter/adapter`
  * :doc:`/trainings/material/soup/cxx-design-patterns/proxy/proxy`
  * :doc:`/trainings/material/soup/cxx-design-patterns/observer/observer`
  * :doc:`/trainings/material/soup/cxx-design-patterns/abstract-factory/abstract-factory`
  * Strategy
