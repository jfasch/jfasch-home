.. include:: <mmlalias.txt>


C++: A One-Day Overview (2024-11-19 - 2024-11-21)
=================================================

.. toctree::
   :hidden:

   agenda

.. sidebar::

   **Github Repository**

   * https://github.com/jfasch/2024-11-19

   **Original Agenda** 

   * :doc:`agenda`

   **Material**

   * :doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking-oo`

This was unusual: a one-day course based on
:doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking-oo`,
given three times in a row [#groundhog-day]_, to three different
groups at the same company.

The day was woven around :doc:`the screenplay
</trainings/material/soup/cxx11/introduction/overview-livehacking-oo>`,
which I used to live-hack `2024-11-19/intro.cpp
<https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/intro.cpp>`__ -
which is the final outcome.

See :doc:`the screenplay
</trainings/material/soup/cxx11/introduction/overview-livehacking-oo>`
to see how we got there. Any deviations (asked questions, discussions)
are documented below.

.. contents::
   :local:

Course Flow: Questions And Discussions
--------------------------------------

The following chapters correspond to sections in
:doc:`/trainings/material/soup/cxx11/introduction/overview-livehacking-oo`,
which are referred to in their respective sidebars.

``std::map``, And Pitfalls (:ref:`cxx11-overview-class-item-encap`)
...................................................................

.. sidebar:: Section(s) in script

   * :ref:`cxx11-overview-class-item-encap`
   * :ref:`cxx11-overview-class-item-encap-pitfall`

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
`2024-11-19/map-pitfall-no1.cpp
<https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/map-pitfall-no1.cpp>`__

Brace Initialization
....................

.. sidebar:: Section(s) in script

   * :ref:`cxx11-overview-brace-init`

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/brace-initialization/index`

Discussed the differences between ``{}`` and ``()``. See
`2024-11-19/brace-init.cpp
<https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/brace-init.cpp>`__

Smart Pointers, And Move Semantics
..................................

.. sidebar:: Section(s) in script

   * :ref:`cxx11-overview-smart-pointers`
   * :ref:`cxx11-overview-unique-ptr`
   * :ref:`cxx11-overview-move`
   * :ref:`cxx11-overview-shared-ptr`

.. sidebar:: See also

   **Pointer Classes**

   * :doc:`/trainings/material/soup/cxx11/smart-pointers/introduction/topic`
   * :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`
   * :doc:`/trainings/material/soup/cxx11/smart-pointers/shared-ptr/topic`
   * (Not covered) :doc:`/trainings/material/soup/cxx11/smart-pointers/weak-ptr/topic`
   * :doc:`/trainings/material/soup/cxx11/smart-pointers/closing-words/topic`

   **Move semantics, and Rvalue references**

   * :doc:`/trainings/material/soup/cxx11/move/overview`
   * :doc:`/trainings/material/soup/cxx11/move/livehack-string-move`
   * :doc:`/trainings/material/soup/cxx11/move/livehack-using-string-move`
   * :doc:`/trainings/material/soup/cxx11/move/afterword`

While using ``std::shared_ptr<>`` in `2024-11-19/intro.cpp
<https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/intro.cpp>`__,
we approached the topic in

* `2024-11-19/shared-ptr-memory-mgmt.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/shared-ptr-memory-mgmt.cpp>`__
* `2024-11-19/unique-ptr-memory-mgmt.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/unique-ptr-memory-mgmt.cpp>`__

While we were at it, we discussed related topics like

* Return value optimization (RVO) and `Copy Elision
  <https://en.wikipedia.org/wiki/Copy_elision>`__. Demo code in
  `2024-11-19/rvo-or-not.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/rvo-or-not.cpp>`__
* Moving and rvalue references in general
  (:doc:`/trainings/material/soup/cxx11/move/index`)
* Dual implementation (move and copy) of, say,
  ``std::vector::push_back()``. Demo code in `2024-11-19/push-back-move.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/push-back-move.cpp>`__

Lambda
......

.. sidebar:: Section(s) in script

   * :ref:`cxx11-overview-lambda`
   * :ref:`cxx11-overview-lambda-todolist`

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/lambda/lambda`
   * :doc:`/trainings/material/soup/cxx11/lambda/lambda-is-functor`
   * :doc:`/trainings/material/soup/cxx11/lambda/lambda-is-functor-pitfall`
   * :doc:`/trainings/material/soup/cxx11/lambda/lambda-capture`
   * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/sort`

Transformed `2024-11-19/intro.cpp
<https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/intro.cpp>`__
into something that is more to the point. Talk about interfaces, the
cost of ``virtual`` (RTTI is not free), and readability in general.

For what a lambda really is, see the old school functor demo
(`2024-11-19/functor.cpp
<https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/functor.cpp>`__).

Use cases for lambda:

* The optional third parameter, ``Compare``, to ``std::sort``
  (see `2024-11-19/sort-lambda.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/sort-lambda.cpp>`__)
* Creating threads, and more specifically, using `std::async
  <https://en.cppreference.com/w/cpp/thread/async>`__ (see
  `2024-11-19/async.cpp
  <https://github.com/jfasch/2024-11-19/blob/main/2024-11-19/async.cpp>`__)

.. rubric:: Footnotes

.. [#groundhog-day] It went somewhat like the movie `Groundhog Day
                    <https://de.wikipedia.org/wiki/Und_t%C3%A4glich_gr%C3%BC%C3%9Ft_das_Murmeltier>`__
