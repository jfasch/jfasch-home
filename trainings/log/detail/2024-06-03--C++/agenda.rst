.. include:: <mmlalias.txt>


Agenda: C++: A Thorough Overview (2024-06-03)
=============================================

.. contents::
   :local:

Introduction: A New Language To Me
----------------------------------

* :doc:`/trainings/material/soup/cxx/cxx11/introduction/overview-livehacking`

Range Based for Loops
.....................

* :doc:`/trainings/material/soup/cxx/cxx11/range-for/range-based-for`
* :doc:`/trainings/material/soup/cxx/cxx11/range-for/range-based-for-map`

Tuple Unpacking (err, Structured Binding)
.........................................

* :doc:`/trainings/material/soup/cxx/cxx11/structured-binding/topic`

C++ Pythonic Toolcase
.....................

* :doc:`/trainings/material/soup/cxx/cxx11/auto/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/any-variant-optional/variant`
* :doc:`/trainings/material/soup/cxx/cxx11/any-variant-optional/any`
* ``std::optional``

Brace Initialization (``std::initializer_list<>``)
..................................................

From :doc:`/trainings/material/soup/cxx/cxx11/brace-initialization/index`

* :doc:`/trainings/material/soup/cxx/cxx11/brace-initialization/intro`
* :doc:`/trainings/material/soup/cxx/cxx11/brace-initialization/implementor-view`
* :doc:`/trainings/material/soup/cxx/cxx11/brace-initialization/mess`

New OO keywords: override, final, default, delete
.................................................

* :doc:`/trainings/material/soup/cxx/cxx11/oo/override`
* :doc:`/trainings/material/soup/cxx/cxx11/oo/final`
* :doc:`/trainings/material/soup/cxx/cxx11/oo/delete`
* :doc:`/trainings/material/soup/cxx/cxx11/oo/default`

Functions: ``std::function<>``, Lambdas
.......................................

* From :doc:`/trainings/material/soup/cxx/cxx11/bind-function/index`:

  * :doc:`/trainings/material/soup/cxx/cxx11/bind-function/010-bind/topic`
  * :doc:`/trainings/material/soup/cxx/cxx11/bind-function/020-function/topic`

* From :doc:`/trainings/material/soup/cxx/cxx11/lambda/index`

  * :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda`
  * :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda-is-functor`
  * :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda-is-functor-pitfall`
  * :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda-capture`

Strongly Typed enum
...................

* :doc:`/trainings/material/soup/cxx/cxx11/strongly-typed-enums/topic`

Delegating Constructor
......................

* :doc:`/trainings/material/soup/cxx/cxx11/delegating-ctor/topic`

``nullptr``
...........

* :doc:`/trainings/material/soup/cxx/cxx11/miscellaneous2/topic`

Smart Pointers: ``std::shared_ptr<>``, ``std::unique_ptr<>`` (And A Little ``std::move``)
-----------------------------------------------------------------------------------------

From :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/index`:

* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/introduction/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/weak-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/closing-words/topic`

Moving, And RValue References (And Perfect Forwarding |:clap:|)
---------------------------------------------------------------

Moving
......

`Best explained in a live hacking session (from
:doc:`/trainings/material/soup/cxx/cxx11/new-language-features/move/index`)

* :doc:`/trainings/material/soup/cxx/cxx11/move/overview`, including *Rule Of Five*
* :doc:`/trainings/material/soup/cxx/cxx11/move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx/cxx11/move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx/cxx11/move/afterword`

Something Similar But Completely Different: Perfect Forwarding
..............................................................

``&&`` is not always what you think |:thumbsdown:|

* :doc:`/trainings/material/soup/cxx/cxx11/perfect-forwarding/topic`
  (a feature which shares the syntax with moving in that it uses
  ``&&``, but is something completely different)

Unit Testing With ``googletest``
--------------------------------

From :doc:`/trainings/material/soup/misc/unittest/index`:

* :doc:`/trainings/material/soup/misc/unittest/unittest_gtest_basics/topic`
* :doc:`/trainings/material/soup/misc/unittest/unittest_gtest_cmake/topic`
* :doc:`/trainings/material/soup/misc/unittest/unittest_gtest_fixture/topic`

Multithreading
--------------

From :doc:`/trainings/material/soup/cxx/cxx11/multithreading/index`:

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/010-introduction/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/scoped-locking`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/atomics`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/promise-future`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/condition-variable`

Miscellaneous
-------------

Strings
.......

* :doc:`/trainings/material/soup/cxx/cxx03/900-standard-library-miscellanea/string/topic`
* ``std::string_view``: purpose, and usage

``constexpr``, ``constinit``, ``consteval``
...........................................

* :doc:`/trainings/material/soup/cxx/cxx11/constexpr-constinit-consteval/constexpr`
* ``constinit``
* ``consteval``

Code (And Project) Sanity
.........................

* Best practices |longrightarrow| `C++ Core Guidelines |:laughing:|
  <https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines>`__
* ``const``, opinionated (was: why shoud I initialize members in an
  initializer list and not in the constructor body?)
* Memory leaks and uninitialized memory |longrightarrow| `valgrind
  <https://valgrind.org/>`__
* Metrics and static code analysis

Clean Code, Design Patterns
...........................

* :doc:`/trainings/material/soup/misc/clean-code/index`
  (overview/discussion only)
* From :doc:`/trainings/material/soup/cxx/cxx-design-patterns/index`

  * :doc:`/trainings/material/soup/cxx/cxx-design-patterns/singleton/singleton` (but see "Code Sanity" above)
  * :doc:`/trainings/material/soup/cxx/cxx-design-patterns/adapter/adapter`
  * :doc:`/trainings/material/soup/cxx/cxx-design-patterns/observer/observer`
  * :doc:`/trainings/material/soup/cxx/cxx-design-patterns/abstract-factory/abstract-factory`
  * Strategy, and Dependency Inversion/Injection
  * Builder
