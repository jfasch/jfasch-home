.. include:: <mmlalias.txt>


C++: A One-Day Overview (2024-11-19 - 2024-11-21)
=================================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda

.. sidebar::

   **Github Repository**

   * https://github.com/jfasch/2024-11-19

   **Original Agenda** 

   * :doc:`agenda`

2024-11-19 (Day 1)
------------------

Livecoding `day-1/intro.cpp
<https://github.com/jfasch/2024-11-19/blob/main/day-1/intro.cpp>`__,
according to `notes
<https://github.com/jfasch/2024-11-19/blob/main/day-1/notes.rst>`__

Notoriously did not reach the goal (there has no goal been set), but
touched the following topics as the pointless todo-list was morphed to
something even more pointless.

``std::map``, And Pitfalls
..........................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map`
   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-insert`
   * :ref:`cxx_map_inserting`

``std::map``, when filled using ``tdl["something"] = Item("... blah
...")``, requires ``class Item`` to have a default constructor. This
is not entirely obvious, to say the least.

**Problem**: ``std::map::operator[]()`` creates a node with a
default-constructed value, which is then overwritten with
``Item("... blah ...")``.

**Solution**: use ``std::map::insert()``, or even better in our case at
least, use an initializer list and a ``const todo_list`` object.

Demo of the pitfall (``std::map::operator[]()``) in
`day-1/map-pitfall-no1.cpp
<https://github.com/jfasch/2024-11-19/blob/main/day-1/map-pitfall-no1.cpp>`__

Brace Initialization
....................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`

Discussed the differences between ``{}`` and ``()``. See
`day-1/brace-init.cpp
<https://github.com/jfasch/2024-11-19/blob/main/day-1/brace-init.cpp>`__

Smart Pointers, And Move Semantics
..................................

.. sidebar:: See also

   **Pointer Classes**

   * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
   * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
   * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
   * (Not covered) :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
   * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

   **Move semantics, and Rvalue references**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-string-move`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-using-string-move`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/afterword`


While using ``std::shared_ptr<>`` in `day-1/intro.cpp
<https://github.com/jfasch/2024-11-19/blob/main/day-1/intro.cpp>`__,
we approached the topic in

* `day-1/shared-ptr-memory-mgmt.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/day-1/shared-ptr-memory-mgmt.cpp>`__
* `day-1/unique-ptr-memory-mgmt.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/day-1/unique-ptr-memory-mgmt.cpp>`__

While we were at it, we discussed related topics like

* Return value optimization (RVO) and `Copy Elision
  <https://en.wikipedia.org/wiki/Copy_elision>`__. Demo code in
  `day-1/rvo-or-not.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/day-1/rvo-or-not.cpp>`__
* Moving and rvalue references in general
  (:doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/group`)
* Dual implementation (move and copy) of, say,
  ``std::vector::push_back()``. Demo code in `day-1/push-back-move.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/day-1/push-back-move.cpp>`__

Pythonicity
...........

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for-map`

Nothing more to say; morphed `day-1/intro.cpp
<https://github.com/jfasch/2024-11-19/blob/main/day-1/intro.cpp>`__
into something more readable.

Lambda
......

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor-pitfall`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`
   * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/sort`

Transformed `day-1/intro.cpp
<https://github.com/jfasch/2024-11-19/blob/main/day-1/intro.cpp>`__
into something that is more to the point. Talk about interfaces, the
cost of ``virtual`` (RTTI is not free), and readability in general.

For what a lambda really is, see the old school functor demo
(`day-1/functor.cpp
<https://github.com/jfasch/2024-11-19/blob/main/day-1/functor.cpp>`__).

Use cases for lambda:

* The optional third parameter, ``Compare``, to ``std::sort``
  (see `day-1/sort-lambda.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/day-1/sort-lambda.cpp>`__)
* Creating threads, and more specifically, using `std::async
  <https://en.cppreference.com/w/cpp/thread/async>`__ (see
  `day-1/async.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/day-1/async.cpp>`__)

