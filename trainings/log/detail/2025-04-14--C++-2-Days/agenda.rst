.. include:: <mmlalias.txt>


Agenda: C++: News Until C++20 (2025-05-14 - 2050-05-15)
=======================================================

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
</trainings/material/soup/cxx11/010-introduction/overview-livehacking>`.

Topics
------

* ``constexpr``, and the C++20 ``consteval`` and ``constinit``

  From
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/constexpr-constinit-consteval/group`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/constexpr-constinit-consteval/const`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/constexpr-constinit-consteval/constexpr`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/constexpr-constinit-consteval/consteval`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/constexpr-constinit-consteval/constinit`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/constexpr-constinit-consteval/if`

* Concepts (a.k.a. "Template error messages are a PITA")

  From
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/group`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/intro`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/writing-concepts`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/concepts/links`

* Local variables in ``if`` and ``for`` statements

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/control-flow-locals`

* Lambdas (and C++20 news)

  From
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor-pitfall`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`

* Attributes

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/attributes/topic`

* Spaceship operator

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/spaceship/topic`

New Language Features
.....................

* Modules

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

Multithreading
..............

Attendees are experienced in multithreading. Nonetheless the topic is
important enough for a solid recap.

* C++ memory model overview
* Atomic smart pointers, and what's unsafe with smart pointers
* Atomic references (``atomic_ref``)
* Synchronization and communication primitives
* And realtime? C++ does not define realtime concepts, so this is an
  OS topic.
* Coroutines, and what makes them different from threads

News From The Standard Library
..............................

* ``std::format``: *Pythonicity never stops*
* ``std::chrono``: calendar and timezone
* ``std::ranges``: overview
* ``std::span``: the problems it solves, and usage
