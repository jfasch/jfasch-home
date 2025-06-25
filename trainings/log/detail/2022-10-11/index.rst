.. include:: <mmlalias.txt>


C++: A New Language Starting In 2011 (2022-10-11 - 2022-10-13)
==============================================================

.. contents::
   :local:

Metadata
--------

* Live-Hacking, and exercise material on Github: `2022-10-11
  <https://github.com/jfasch/2022-10-11>`__
* Also on Github: `entire homepage
  <https://github.com/jfasch/jfasch-home>`__

Course Preparation
------------------

We will be doing a number of exercises and trainer livehacking
sessions. All this is done starting from a `skeleton Github project
<https://github.com/jfasch/2022-10-11>`__.

Please try and get the skeleton project, create an environment that
works for you, and test-build that project.

Work Environment
................

I suggest you use the :doc:`Windows Subsystem For Linux (WSL2)
</trainings/material/soup/linux/basics/intro/wsl>` (Microsoft
documentation `here
<https://docs.microsoft.com/en-us/windows/wsl/>`__). This sets up a
virtualized Ubuntu insode Windows, together with all interoperability
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
     $ git clone https://github.com/jfasch/2022-10-11.git
     $ cd 2022-10-11/
     $ git submodule init
     $ git submodule update

* Create build directory, and chdir there

  .. code-block:: console

     $ mkdir /tmp/2022-10-11-build
     $ cd /tmp/2022-10-11-build

* Use CMake to create makefiles

  .. code-block:: console

     $ pwd
     /tmp/2022-10-11-build
     $ cmake /home/jfasch/src/2022-10-11

* Build

  .. code-block:: console

     $ pwd
     /tmp/2022-10-11-build
     $ make

Introduction
------------

* :doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking`

Pythonicity (Thank You: Readablility and Writability)
-----------------------------------------------------

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
* :doc:`/trainings/material/soup/cxx11/brace-initialization/mess`

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
* :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/exercises/bag-unique`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/weak-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/exercises/bag-shared`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/closing-words/topic`

Moving, “RValue References”, And Perfect Forwarding
---------------------------------------------------

From :doc:`/trainings/material/soup/cxx11/move/index`

* :doc:`/trainings/material/soup/cxx11/move/overview`
* :doc:`/trainings/material/soup/cxx11/move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/move/afterword`

Perfect forwarding *ain't moving*:

* :doc:`/trainings/material/soup/cxx11/perfect-forwarding/topic`

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

News in C++20 (2023-06-13)
--------------------------

Coroutines and C++23 Generators
...............................

From
:doc:`/trainings/material/soup/cxx11/coroutines/index`

* :doc:`/trainings/material/soup/cxx11/coroutines/intro`

Ranges And Views
................

From
:doc:`/trainings/material/soup/cxx11/ranges/index`

* :doc:`/trainings/material/soup/cxx11/ranges/intro`
* :doc:`/trainings/material/soup/cxx11/ranges/good-bad`
* :doc:`/trainings/material/soup/cxx11/ranges/links`

Concepts
........

From
:doc:`/trainings/material/soup/cxx11/concepts/index`

* :doc:`/trainings/material/soup/cxx11/concepts/intro/topic`
* :doc:`/trainings/material/soup/cxx11/concepts/writing-concepts/topic`
* :doc:`/trainings/material/soup/cxx11/concepts/links`
