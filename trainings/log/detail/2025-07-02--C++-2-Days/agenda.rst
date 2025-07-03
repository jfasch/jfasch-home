.. include:: <mmlalias.txt>


Agenda: C++ - Overview Of New Language Features (Around C++20)
==============================================================

The audience consists of professional programmers who are not new to
C++. As such, rather than reinforcing each topic through exercises, it
is more important to *discuss* matters and to develop a common
knowledge and a common sense.

Throughout the training, the presentation style will be
live-coding-by-trainer, falling back to a traditional frontal
presentation style where applicable.

.. contents::
   :local:

Didactic High Speed
-------------------

Smart Pointers
..............

:doc:`/trainings/material/soup/cxx11/move/index` is a complex topic to
explain. A smart pointer overview is a good thing to have anyway. Lets
start with that, and - through ``std::unique_ptr`` - get insight in what
*moving* is from a user's point of view.

From :doc:`/trainings/material/soup/cxx11/smart-pointers/index`

* :doc:`/trainings/material/soup/cxx11/smart-pointers/introduction/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/weak-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/closing-words/topic`

Rule Of Five (Three, Zero), And Move Semantics
..............................................

Another good thing to have is a rule to fight against C++'s
shortcomings. This expains how to write *copyable* and *movable*
types, likewise.

* :doc:`/trainings/material/soup/cxx11/rule-of-5/topic`
* :doc:`/trainings/material/soup/cxx11/move/index`
* :doc:`/trainings/material/soup/cxx11/perfect-forwarding/topic`, only
  to show that this is a different concept but looks syntactically
  much like *moving*.

Multithreading, Memory Model
----------------------------

This section is a bit involved as all of this is somehow related.

* From :doc:`/trainings/material/soup/cxx11/multithreading/index`

  * :doc:`/trainings/material/soup/cxx11/multithreading/memory-model/topic`. This
    briefly shows what a race condition is, and gives mutex examples.

* :doc:`/trainings/material/soup/cxx11/multithreading/atomic-shared-ptr/topic`. 

News From The Language
----------------------

* From :doc:`/trainings/material/soup/cxx11/brace-initialization/index`

  * :doc:`/trainings/material/soup/cxx11/brace-initialization/intro`
  * :doc:`/trainings/material/soup/cxx11/brace-initialization/implementor-view`
  * :doc:`/trainings/material/soup/cxx11/brace-initialization/mess`

* :doc:`/trainings/material/soup/cxx11/control-flow-locals/topic`
* :doc:`/trainings/material/soup/cxx11/auto/topic`
* :doc:`/trainings/material/soup/cxx11/structured-binding/topic`
* :doc:`/trainings/material/soup/cxx11/deducing-this/topic`
* :doc:`/trainings/material/soup/cxx11/spaceship/topic`
* From :doc:`/trainings/material/soup/cxx11/concepts/index`

  * :doc:`/trainings/material/soup/cxx11/concepts/intro/topic`
  * :doc:`/trainings/material/soup/cxx11/concepts/writing-concepts/topic`

News From The Library
---------------------

* :doc:`/trainings/material/soup/cxx11/ranges/index`
* :doc:`/trainings/material/soup/cxx11/format/topic`
* :doc:`/trainings/material/soup/cxx11/filesystem/topic`. In addition
  to basic functionality, show how to handle UTF-8 encoded paths
  (``std::filesystem::u8path``) [#make_material]_
* From :doc:`/trainings/material/soup/cxx11/any-variant-optional/index`

  * :doc:`/trainings/material/soup/cxx11/any-variant-optional/any`
  * :doc:`/trainings/material/soup/cxx11/any-variant-optional/variant`

* Container and algorithms overview (:doc:`here
  </trainings/material/soup/cxx03/060-stl/index>`). Show hash-table
  based data structures ``std::unordered_set<>`` and
  ``std::unordered_map<>`` [#make_material]_.
* :doc:`/trainings/material/soup/cxx11/array/topic`
* Execution policies of parallel algorithms [#make_material]_
* :doc:`/trainings/material/soup/cxx11/span/topic`
* ``std::tuple<>`` [#make_material]_

C++ Executed At Compile Time (The ``constexpr`` Engine)
-------------------------------------------------------

From :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/index`

* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/const`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/constexpr`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/consteval`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/constinit`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/if`


.. rubric:: Footnotes
.. [#make_material] Material to be created.

