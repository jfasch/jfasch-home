.. include:: <mmlalias.txt>


Agenda: C++: News Until C++20 (2025-05-14 - 2025-05-15)
=======================================================

.. contents::
   :local:

Training Goal/Style
-------------------

The audience consists of professional programmers who are not new to
C++. As such, rather than reinforcing each topic through exercises, it
is more important to *discuss* matters and to develop a common
knowledge and a common sense.

Throughout the training, the presentation style will be
live-coding-by-trainer, only falling back to a traditional frontal
presentation style where applicable. The audience will be left with a
screenplay-like writeup, much like :doc:`this one
</trainings/material/soup/cxx11/introduction/overview-livehacking>`.

``constexpr``, and the C++20 ``consteval`` and ``constinit``
------------------------------------------------------------

From
:doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/index`

* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/const`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/constexpr`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/consteval`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/constinit`
* :doc:`/trainings/material/soup/cxx11/constexpr-constinit-consteval/if`

Concepts (a.k.a. "Template error messages are a PITA")
------------------------------------------------------

From
:doc:`/trainings/material/soup/cxx11/concepts/index`

* :doc:`/trainings/material/soup/cxx11/concepts/intro/topic`
* :doc:`/trainings/material/soup/cxx11/concepts/writing-concepts/topic`
* :doc:`/trainings/material/soup/cxx11/concepts/links`

Local variables in ``if`` and ``for`` statements
------------------------------------------------

* :doc:`/trainings/material/soup/cxx11/control-flow-locals/topic`

Lambdas
-------

From
:doc:`/trainings/material/soup/cxx11/lambda/index`

* :doc:`/trainings/material/soup/cxx11/lambda/lambda`
* :doc:`/trainings/material/soup/cxx11/lambda/lambda-is-functor`
* :doc:`/trainings/material/soup/cxx11/lambda/lambda-is-functor-pitfall`
* :doc:`/trainings/material/soup/cxx11/lambda/lambda-capture`

Attributes
----------

* :doc:`/trainings/material/soup/cxx11/attributes/topic`

Spaceship Operator
------------------

* :doc:`/trainings/material/soup/cxx11/spaceship/topic`

Multithreading (And Related Topics)
-----------------------------------

* :doc:`/trainings/material/soup/cxx11/multithreading/atomic-shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx11/multithreading/memory-model/topic`
* From :doc:`/trainings/material/soup/cxx11/multithreading/index`

  * :doc:`/trainings/material/soup/cxx11/multithreading/010-introduction/topic`
  * :doc:`/trainings/material/soup/cxx11/multithreading/020-thread/topic`
  * :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/mutex`
  * :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/scoped-locking`
  * :doc:`/trainings/material/soup/cxx11/multithreading/040-locking-atomics/atomics`
  * :doc:`/trainings/material/soup/cxx11/multithreading/promise-future`
  * :doc:`/trainings/material/soup/cxx11/multithreading/condition-variable`

* Atomic references (``atomic_ref``)
* And realtime? C++ does not define realtime concepts, so this is an
  OS topic.
* From :doc:`/trainings/material/soup/cxx11/coroutines/index`

  * :doc:`/trainings/material/soup/cxx11/coroutines/intro`

Modules
-------

Leider nein

.. .. * std::same_as<>, no_narrowing_conversion<>
.. .. 
.. ..   * `Keynote: The Real Problem of C++ - Klaus Iglberger
.. ..     <https://youtu.be/vN0U4P4qmRY?si=nD4fRmurcBjX2UiD>`__
.. .. 
.. ..     .. raw:: html
.. .. 
.. ..        <iframe width="560" height="315" 
.. ..                src="https://www.youtube.com/embed/vN0U4P4qmRY?si=Emhn2EtAQO9w_3I0" 
.. .. 	       title="YouTube video player" 
.. .. 	       frameborder="0" 
.. .. 	       allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
.. .. 	       referrerpolicy="strict-origin-when-cross-origin" 
.. .. 	       allowfullscreen>
.. ..        </iframe>
.. .. 
.. ..     Somewhere in the middle

News From The Standard Library
------------------------------

* From :doc:`/trainings/material/soup/cxx11/ranges/index`

  * :doc:`/trainings/material/soup/cxx11/ranges/intro`
  * :doc:`/trainings/material/soup/cxx11/ranges/good-bad`
  * :doc:`/trainings/material/soup/cxx11/ranges/links`

* ``std::format``: *Pythonicity never stops*
* :doc:`/trainings/material/soup/cxx11/chrono/topic`
* ``std::span``: the problems it solves, and usage

Optional Content From Past C++ Versions
---------------------------------------

If the situation wants it, we can look over
material that predates C++20, such as:

* :doc:`/trainings/material/soup/cxx11/move/index`
* :doc:`/trainings/material/soup/cxx11/smart-pointers/index`
* :doc:`/trainings/material/soup/cxx11/any-variant-optional/variant`

You can always browse :doc:`all material
</trainings/material/soup/index>` - but be warned, it is rather
unstructured.
