.. include:: <mmlalias.txt>


C++: A New Language Starting In 2011
====================================

.. toctree::
   :hidden:

   2022-05-11

.. contents::
   :local:

Metadata
--------

* Live-Hacking, and exercise material on Github: `2022-06-14
  <https://github.com/jfasch/2022-06-14>`__
* Also on Github: `entire homepage
  <https://github.com/jfasch/jfasch-home>`__

Introduction
------------

* :doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking`

Pythonicity (Thank You: Readablility and Writability)
-----------------------------------------------------

Range Based for Loops
.....................

From
:doc:`/trainings/material/soup/cxx11/range-for/index`

* :doc:`/trainings/material/soup/cxx11/range-for/range-based-for`
* :doc:`/trainings/material/soup/cxx11/range-for/range-based-for-map`

Tuple Unpacking (err, Structured Binding)
.........................................

* :doc:`/trainings/material/soup/cxx11/structured-binding/topic`

Duck Typing (err, ``auto``) Without A Duck
..........................................

* :doc:`/trainings/material/soup/cxx11/auto/topic`

Exercise
........

* :doc:`/trainings/material/soup/cxx11/exercises/bag-copy`

Things That Simply Deserved Fixing Since Ages
---------------------------------------------

Brace Initialization
....................

From :doc:`/trainings/material/soup/cxx11/brace-initialization/index`

* :doc:`/trainings/material/soup/cxx11/brace-initialization/intro`
* :doc:`/trainings/material/soup/cxx11/brace-initialization/implementor-view`

New OO keywords: override, final, default, delete
.................................................

* :doc:`/trainings/material/soup/cxx11/oo/override`
* :doc:`/trainings/material/soup/cxx11/oo/final`
* :doc:`/trainings/material/soup/cxx11/oo/delete`
* :doc:`/trainings/material/soup/cxx11/oo/default`

Strongly Typed enum
...................

* :doc:`/trainings/material/soup/cxx11/strongly-typed-enums/topic`

Delegating Constructor
......................

* :doc:`/trainings/material/soup/cxx11/delegating-ctor/topic`

``nullptr``
...........

* :doc:`/trainings/material/soup/cxx11/miscellaneous2/topic`

Smart Pointers
--------------

From :doc:`/trainings/material/soup/cxx11/smart-pointers/index`:

* :doc:`/trainings/material/soup/cxx11/smart-pointers/introduction/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/introduction-livehack`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/040-closing-words/topic`

Exercise
........

* :doc:`/trainings/material/soup/cxx11/exercises/bag-unique`
* :doc:`/trainings/material/soup/cxx11/exercises/bag-shared`

Moving, “RValue References”
---------------------------

* :doc:`/trainings/material/soup/cxx11/move/index`

Functions (``std::bind<>``, ``std::function<>``, Lambdas)
---------------------------------------------------------

From :doc:`/trainings/material/soup/cxx11/bind-function/index`:

* :doc:`/trainings/material/soup/cxx11/bind-function/010-bind/topic`
* :doc:`/trainings/material/soup/cxx11/bind-function/020-function/topic`

From :doc:`/trainings/material/soup/cxx11/lambda/index`

* :doc:`/trainings/material/soup/cxx11/lambda/lambda`
* :doc:`/trainings/material/soup/cxx11/lambda/lambda-is-functor`
* :doc:`/trainings/material/soup/cxx11/lambda/lambda-is-functor-pitfall`
* :doc:`/trainings/material/soup/cxx11/lambda/lambda-capture`

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

Miscellaneous
-------------

**TODO: Important**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * ``std::any<>``, ``std::optional<>``, ``std::variant<>``
     * 
   * * ``vector<>::emplace_back()``
     * 
   * * ``forward``
     * 
   * * ``array``
     * 
   * * ``ref``, ``cref``
     * 

**TODO: Optional**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * new containers and algorithms (next to beginning somewhere)
     * 
   * * `File system library
       <https://en.cppreference.com/w/cpp/filesystem>`__
     * 
   * * ``chrono`` += how to sleep
     * Done in various live hacking session on the way; add to
       :doc:`slide material
       </trainings/material/soup/cxx11/chrono/topic>`
   * * `Regular expression library
       <https://en.cppreference.com/w/cpp/regex>`__
     * `(Raw) string literal
       <https://en.cppreference.com/w/cpp/language/string_literal>`__
   * * ``constexpr``, ``constexpr if`` (since C++17)
     *
