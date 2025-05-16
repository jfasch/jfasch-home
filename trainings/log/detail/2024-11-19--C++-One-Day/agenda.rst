.. include:: <mmlalias.txt>


Agenda: C++: A One-Day Overview (2024-11-19 - 2024-11-21)
=========================================================

.. contents::
   :local:

The "New C++": Fundamental Changes Since 2011
---------------------------------------------

.. sidebar:: Livehacking screenplay

   * :doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking`

A live-coded overview of what will follow, showing the cornerstones of
the "new C++". Starting with a C++98 code base, we morph that into
something that has a more modern appeal.

* Memory management/pointer types (``std::shared_ptr<>``,
  ``std::unique_ptr<>``)
* Pythonicity: ``auto``, *Structured Binding*, and more
* Lambdas
* Threading: threads, and locking
* Container classes and iteration: range based ``for``
* *Real* container initialization
* Generalized typesafe unions: ``std::variant<>``
* Generalized function pointer: ``std::function<>``
* New OO features: ``final``, ``overide``

Low Hanging Fruit
-----------------

Much of it has been said in the intro section, but let's quickly
repeat ...

* :doc:`/trainings/material/soup/cxx11/auto/topic`
* :doc:`/trainings/material/soup/cxx11/structured-binding/topic`
* :doc:`/trainings/material/soup/cxx11/range-for/range-based-for`
* :doc:`/trainings/material/soup/cxx11/brace-initialization/index`
* :doc:`/trainings/material/soup/cxx11/miscellaneous/any-variant-optional/variant`
* :doc:`/trainings/material/soup/cxx11/bind-function/020-function/topic`

Memory Management
-----------------

* :doc:`/trainings/material/soup/cxx11/smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/uniqueptr`
  (and a little :doc:`moving
  </trainings/material/soup/cxx11/move/index>`)
* :doc:`/trainings/material/soup/cxx11/smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/weakptr` (optional)

Lambdas
-------

* :doc:`/trainings/material/soup/cxx11/lambda/lambda`
* :doc:`/trainings/material/soup/cxx11/lambda/lambda-capture`

Multithreading
--------------

From :doc:`/trainings/material/soup/cxx11/multithreading/index`:

* :doc:`/trainings/material/soup/cxx11/multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/scoped-locking`
* :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/atomics`

Optional (But Cool) Topics
--------------------------

From
:doc:`/trainings/material/soup/cxx11/move/index`:

* :doc:`/trainings/material/soup/cxx11/move/overview`
* :doc:`/trainings/material/soup/cxx11/move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/move/afterword`

From :doc:`/trainings/material/soup/cxx11/multithreading/index`:
communication primitives

* :doc:`/trainings/material/soup/cxx11/multithreading/promise-future`
* :doc:`/trainings/material/soup/cxx11/multithreading/condition-variable`
