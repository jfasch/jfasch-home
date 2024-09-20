.. include:: <mmlalias.txt>


Agenda: C++: A One-Day Overview (Date Yet Unknown)
==================================================

.. contents::
   :local:

The "New C++": Fundamental Changes Since 2011
---------------------------------------------

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

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`
* :doc:`/trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/variant`
* :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`

Memory Management
-----------------

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
  (and a little :doc:`moving
  </trainings/material/soup/cxx11/020-new-language-features/060-move/group>`)
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr` (optional)

Lambdas
-------

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`

Multithreading
--------------

From :doc:`/trainings/material/soup/cxx11/050-multithreading/group`:

* :doc:`/trainings/material/soup/cxx11/050-multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/scoped-locking`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`

Optional (But Cool) Topics
--------------------------

From
:doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/group`:

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/afterword`

From :doc:`/trainings/material/soup/cxx11/050-multithreading/group`:
communication primitives

* :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`
