.. include:: <mmlalias.txt>


C++: A New Language Starting In 2011
====================================

.. contents::
   :local:

Metadata
--------

* Live-Hacking, and exercise material on Github: `2022-07-26
  <https://github.com/jfasch/2022-07-26>`__
* Also on Github: `entire homepage
  <https://github.com/jfasch/jfasch-home>`__

Course Preparation
------------------

We will be doing a number of exercises and trainer livehacking
sessions. All this is done starting from a `skeleton Github project
<https://github.com/jfasch/2022-07-26>`__.

Please try and get the skeleton project, create an environment that
works for you, and test-build that project.

Work Environment
................

I suggest you use the :doc:`Windows Subsystem For Linux (WSL2)
</trainings/material/soup/linux/basics/intro/wsl>` (Microsoft
documentation `here
<https://docs.microsoft.com/en-us/windows/wsl/>`__). This sets up a
virtualized Ubuntu inside Windows, together with all interoperability
wazoo.

It is also possible to setup a Linux-like environment on native
Windows, using the following emulation layers

* `Cygwin <https://www.cygwin.com/>`__
* `MinGW <https://www.mingw-w64.org/>`__ (known to have problems when
  it comes to threading)

Skeleton Project
................

The project uses `CMake <https://cmake.org/>`__ and `googletest
<https://github.com/google/googletest>`__. Ideal work anvironment is
Linux(-like). If you have such an environment, then the steps to build
the project are,

* Clone and massage the project source

  .. code-block:: console

     $ pwd
     $ /home/jfasch/src       # <--- your mileage will vary
     $ git clone https://github.com/jfasch/2022-07-26.git
     $ cd 2022-07-26/
     $ git submodule init
     $ git submodule update

* Create build directory, and chdir there

  .. code-block:: console

     $ mkdir /tmp/2022-07-26-build
     $ cd /tmp/2022-07-26-build

* Use CMake to create makefiles

  .. code-block:: console

     $ pwd
     /tmp/2022-07-26-build
     $ cmake /home/jfasch/src/2022-07-26

* Build

  .. code-block:: console

     $ pwd
     /tmp/2022-07-26-build
     $ make

* Test

  .. code-block:: console

     $ pwd
     /tmp/2022-07-26-build
     $ ./exercises/exercises-suite 
     Running main() from /home/jfasch/tmp/2022-07-26/googletest/googletest/src/gtest_main.cc
     [==========] Running 1 test from 1 test suite.
     [----------] Global test environment set-up.
     [----------] 1 test from dummy_suite
     [ RUN      ] dummy_suite.fail
     /home/jfasch/tmp/2022-07-26/exercises/fail.cpp:5: Failure
     Failed
     [  FAILED  ] dummy_suite.fail (0 ms)
     [----------] 1 test from dummy_suite (0 ms total)
     
     [----------] Global test environment tear-down
     [==========] 1 test from 1 test suite ran. (0 ms total)
     [  PASSED  ] 0 tests.
     [  FAILED  ] 1 test, listed below:
     [  FAILED  ] dummy_suite.fail
     
      1 FAILED TEST

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

Smart Pointers
--------------

From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`:

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction-livehack`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
* :doc:`/trainings/material/soup/cxx11/exercises/bag-unique` (
  `Solution on Github: bag-unique.h
  <https://github.com/jfasch/2022-07-26/blob/main/exercises/bag-unique.h>`__)
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/exercises/bag-shared`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

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
