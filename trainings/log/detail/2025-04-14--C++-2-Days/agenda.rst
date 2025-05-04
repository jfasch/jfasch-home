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

New Language Features
.....................

* Spaceship ``operator<=>``
* Local variables in ``if`` and ``for`` statements
* Lambda in C++20
* ``constexpr`` in C++20
* ``constinit`` and ``consteval``
* Concepts: better template error messages
* Attributes, especially ``[[likely]]`` und ``[[unlikely]]``
* Modules

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
