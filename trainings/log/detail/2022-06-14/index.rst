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

Things That Simply Deserved Fixing Since Ages
---------------------------------------------

Brace Initialization
....................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/topic`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/initializer-list`

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

Smart Pointers
--------------

From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`:

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction-livehack`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

Exercise
........

* :doc:`/trainings/material/soup/cxx11/exercises/bag-unique`
* :doc:`/trainings/material/soup/cxx11/exercises/bag-shared`

Moving, “RValue References”
---------------------------

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/group`

Functions (``std::bind<>``, ``std::function<>``, Lambdas)
---------------------------------------------------------

From :doc:`/trainings/material/soup/cxx11/040-bind-function/group`:

* :doc:`/trainings/material/soup/cxx11/040-bind-function/010-bind/topic`
* :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor-pitfall`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`

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

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * Discussion: Thread Objects
     * * Ctor starts code in thread -> plain function, std::function,
         lambda
       * No copy, only move (obviously)
       * ``join()``, ``detach()``: terminating before join? live hack
         that!
   * * Extend :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/scoped-locking`
     * * ``scoped_lock`` (see-also condvar)
       * ``unique_lock``
   * * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`:
       add ``struct`` specialization
     * 
   * * Add literals to
       :doc:`/trainings/material/soup/cxx11/100-miscellaneous/010-chrono/topic`
     * ... and a "See also" to a literals live hackery
   * * Memory Model
     * See for example the unlocked ``answer``, ``answer_valid`` story
   * * Semaphores (since 20)
     * * Distill from `semaphore <https://en.cppreference.com/w/cpp/thread/counting_semaphore>`__
       * Add "see-also"
	 :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
       * Add "see-also"
	 :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`

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
       </trainings/material/soup/cxx11/100-miscellaneous/010-chrono/topic>`
   * * `Regular expression library
       <https://en.cppreference.com/w/cpp/regex>`__
     * `(Raw) string literal
       <https://en.cppreference.com/w/cpp/language/string_literal>`__
   * * ``constexpr``, ``constexpr if`` (since C++17)
     *
