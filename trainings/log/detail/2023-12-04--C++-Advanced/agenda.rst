.. include:: <mmlalias.txt>


Agenda: C++: Advanced Topics
============================

.. contents::
   :local:

Introduction: A New Language To Me
----------------------------------

* :doc:`/trainings/material/soup/cxx11/010-introduction/overview-livehacking`

Range Based for Loops
.....................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-for/range-based-for`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-for/range-based-for-map`

Tuple Unpacking (err, Structured Binding)
.........................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`

Duck Typing (err, ``auto``) Without A Duck
..........................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`

Brace Initialization
....................

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/index`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/intro`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/implementor-view`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/mess`

New OO keywords: override, final, default, delete
.................................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`

``constexpr``, ``constinit``, ``consteval``
...........................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/constexpr-constinit-consteval/constexpr`
* ``constinit``
* ``consteval``

Functions: ``std::function<>``, Lambdas
.......................................

* From :doc:`/trainings/material/soup/cxx11/040-bind-function/index`:

  * :doc:`/trainings/material/soup/cxx11/040-bind-function/010-bind/topic`
  * :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`

* From :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/index`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor-pitfall`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`

Strongly Typed enum
...................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/010-strongly-typed-enums/topic`

Delegating Constructor
......................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/050-delegating-ctor/topic`

``nullptr``
...........

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/070-miscellaneous/topic`

Moving, RValue References: Do We Want To Copy Sensors?
------------------------------------------------------

Moving: Usage
.............

From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/index`:

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction-livehack`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

Moving: Implementation
......................

Building upon the example from
:doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index` which is 

* Pointless
* It implements a pointless ``String`` class that does resource
  management

Do some initial live hacking

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/afterword`

Live-code a sensor class for
:doc:`/trainings/material/soup/linux/hardware/w1/topic`

* Show problems |longrightarrow| *copy!*
* |longrightarrow| rule of five
* Inhibit copy
* Implement move

Round it up: ``&&`` is not always what you think |:thumbsdown:|
|:middle_finger:|

* :doc:`/trainings/material/soup/cxx11/035-perfect-forwarding/topic`
  (a feature which shares the syntax with moving in that it uses
  ``&&``, but is something completely different)

Type Erasure
------------

* *Type erasure*: what is that, and why?
* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/index`

Allocators
----------

Ugh. Try to come up with something. Urgh.

C++ Pythonic Toolcase
---------------------

* ``std::any``
* ``std::optional``
* ``std::variant``

Concepts
--------

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/index`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/intro/topic`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/writing-concepts/topic`

Multithreading
--------------

From :doc:`/trainings/material/soup/cxx11/050-multithreading/index`:

* :doc:`/trainings/material/soup/cxx11/050-multithreading/010-introduction/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/scoped-locking`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`

Outlook In ``>=20``
-------------------

* From :doc:`/trainings/material/soup/cxx11/020-new-language-features/ranges/index`

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
