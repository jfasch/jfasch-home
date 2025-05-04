.. include:: <mmlalias.txt>


Agenda: C++: News Until C++20 (2 Days, Yet Unspecified)
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

The following list of topics is the outcome of a "pre-sales" talk with
the customer, for a two-days on-site C++ training. The list is largely
unordered (yet), and adaptations to it are likely to be made.

* Brace initialization (:doc:`here
  </trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group>`)
* RValue References, and Move Semantics (:doc:`here
  </trainings/material/soup/cxx11/020-new-language-features/060-move/group>`). Primarily,
  show the *usage* of moving.

  * What the compiler knows/does
  * Relation with RVO
  * Using ``std::move()``
  * Rule of 5 (as opposed to "3" before rvalue references were
    invented)
  * ``= delete``, ``= default``
  * Non-relation to *perfect forwarding* ( :doc:`here
    </trainings/material/soup/cxx11/035-perfect-forwarding/topic>`)

* Container and algorithms overview (:doc:`here
  </trainings/material/soup/cxx03/060-stl/group>`). Show hash-table
  based data structures ``std::unordered_set<>`` and
  ``std::unordered_map<>`` [#make_material]_.
* Structured Binding (:doc:`here
  </trainings/material/soup/cxx11/020-new-language-features/structured-binding>`). Discuss
  usage of ``std::tuple<>``.
* ``constexpr`` (:doc:`here
  </trainings/material/soup/cxx11/020-new-language-features/055-constexpr/topic>`)
  [#adapt_standard]_
* Multithreading (:doc:`here
  </trainings/material/soup/cxx11/050-multithreading/group>`). `OpenMP
  <https://www.openmp.org/>`__ is used by the custumer, so the problem
  appears to be solved. It might not hurt, though, to know what a race
  condition is, and how to protect against it.
* Smart pointers: ``std::shared_ptr<>`` vs. ``std::unique_ptr<>``
  (:doc:`here
  </trainings/material/soup/cxx11/030-smart-pointers/group>`). Probably
  show the *RValue References/Move Semantics* topic in the light of
  understanding compiler error messages when using
  ``std::unique_ptr<>`` incorrectly.
* ``std::array<>`` [#make_material]_
* ``std::span<>`` [#make_material]_
* Ranges and views (:doc:`here
  </trainings/material/soup/cxx11/020-new-language-features/ranges/group>`)
* ``std::any`` (:doc:`here
  </trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/any>`),
  ``std::variant<>`` (:doc:`here
  </trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/variant>`). Show
  usage, and discuss.
* The "spaceship" operator [#make_material]_
* ``std::fmt`` (vs ``printf()``) [#make_material]_
* ``std::filesystem`` (:doc:`here
  </trainings/material/soup/cxx11/filesystem/topic>`). In addition to
  basic functionality, show how to handle UTF-8 encoded paths
  (``std::filesystem::u8path``) [#make_material]_
* Deducing ``this`` (C++23) [#make_material]_
* Execution policies of parallel algorithms [#make_material]_

.. rubric:: Footnotes
.. [#adapt_standard] Material to be adapted to the latest standards.
.. [#make_material] Material to be created.

