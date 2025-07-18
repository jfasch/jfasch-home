.. include:: <mmlalias.txt>


Agenda: C++: Advanced Topics
============================

.. contents::
   :local:

Introduction: A New Language To Me
----------------------------------

* :doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking`

Range Based for Loops
.....................

* :doc:`/trainings/material/soup/cxx11/range-for/range-based-for`
* :doc:`/trainings/material/soup/cxx11/range-for/range-based-for-map`

Tuple Unpacking (err, Structured Binding)
.........................................

* :doc:`/trainings/material/soup/cxx11/structured-binding/topic`

Duck Typing (err, ``auto``) Without A Duck
..........................................

* :doc:`/trainings/material/soup/cxx11/auto/topic`

Brace Initialization
....................

From :doc:`/trainings/material/soup/cxx11/brace-initialization/index`

* :doc:`/trainings/material/soup/cxx11/brace-initialization/intro`
* :doc:`/trainings/material/soup/cxx11/brace-initialization/implementor-view`
* :doc:`/trainings/material/soup/cxx11/brace-initialization/mess`

New OO keywords: override, final, default, delete
.................................................

* :doc:`/trainings/material/soup/cxx11/oo/override`
* :doc:`/trainings/material/soup/cxx11/oo/final`
* :doc:`/trainings/material/soup/cxx11/oo/delete`
* :doc:`/trainings/material/soup/cxx11/oo/default`

``constexpr``, ``constinit``, ``consteval``
...........................................

* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/constexpr`
* ``constinit``
* ``consteval``

Functions: ``std::function<>``, Lambdas
.......................................

* From :doc:`/trainings/material/soup/cxx11/bind-function/index`:

  * :doc:`/trainings/material/soup/cxx11/bind-function/010-bind/topic`
  * :doc:`/trainings/material/soup/cxx11/bind-function/020-function/topic`

* From :doc:`/trainings/material/soup/cxx11/lambda/index`

  * :doc:`/trainings/material/soup/cxx11/lambda/lambda`
  * :doc:`/trainings/material/soup/cxx11/lambda/lambda-is-functor`
  * :doc:`/trainings/material/soup/cxx11/lambda/lambda-is-functor-pitfall`
  * :doc:`/trainings/material/soup/cxx11/lambda/lambda-capture`

Strongly Typed enum
...................

* :doc:`/trainings/material/soup/cxx11/strongly-typed-enums/topic`

Delegating Constructor
......................

* :doc:`/trainings/material/soup/cxx11/delegating-ctor/topic`

``nullptr``
...........

* :doc:`/trainings/material/soup/cxx11/miscellaneous2/topic`

Moving, RValue References: Do We Want To Copy Sensors?
------------------------------------------------------

Moving: Usage
.............

From :doc:`/trainings/material/soup/cxx11/smart-pointers/index`:

* :doc:`/trainings/material/soup/cxx11/smart-pointers/introduction/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/weak-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/closing-words/topic`

Moving: Implementation
......................

Building upon the example from
:doc:`/trainings/material/soup/cxx11/move/index` which is 

* Pointless
* It implements a pointless ``String`` class that does resource
  management

Do some initial live hacking

* :doc:`/trainings/material/soup/cxx11/move/overview`
* :doc:`/trainings/material/soup/cxx11/move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/move/afterword`

Live-code a sensor class for
:doc:`/trainings/material/soup/linux/hardware/w1/topic`

* Show problems |longrightarrow| *copy!*
* |longrightarrow| rule of five
* Inhibit copy
* Implement move

Round it up: ``&&`` is not always what you think |:thumbsdown:|
|:middle_finger:|

* :doc:`/trainings/material/soup/cxx11/perfect-forwarding/topic`
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

From :doc:`/trainings/material/soup/cxx11/concepts/index`

* :doc:`/trainings/material/soup/cxx11/concepts/intro/topic`
* :doc:`/trainings/material/soup/cxx11/concepts/writing-concepts/topic`

Multithreading
--------------

From :doc:`/trainings/material/soup/cxx11/multithreading/index`:

* :doc:`/trainings/material/soup/cxx11/multithreading/010-introduction/topic`
* :doc:`/trainings/material/soup/cxx11/multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/scoped-locking`
* :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/atomics`
* :doc:`/trainings/material/soup/cxx11/multithreading/promise-future`
* :doc:`/trainings/material/soup/cxx11/multithreading/condition-variable`

Outlook In ``>=20``
-------------------

* From :doc:`/trainings/material/soup/cxx11/ranges/index`

  * :doc:`/trainings/material/soup/cxx11/ranges/intro`
  * :doc:`/trainings/material/soup/cxx11/ranges/good-bad`

* :doc:`/trainings/material/soup/cxx11/coroutines/intro`

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
