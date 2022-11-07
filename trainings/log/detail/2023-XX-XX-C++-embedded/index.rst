.. include:: <mmlalias.txt>


C++ For Embedded Developers (Beginning of 2023)
===============================================

.. contents::
   :local:

.. sidebar::

   * 3 days

Goal
----

Give an idea how an experienced C programmer can benefit from the C++
toolcase. The following aspects are covered, accompanied with many
exercises.

* C++ is an *object oriented* language. That term alone has many
  facets, and a solid understanding of each is given. Constructors,
  destructors, automatic pointer/base-class conversion, late binding
  ("abstract"?), and all that.
* C++ also brings a rich toolset in form of its *standard
  library*. After a short conceptual introduction, *containers* and
  *algorithms* are something that is immediately useful for non-OO
  programmers.
* C++ does not stop there; :doc:`starting from its 2011 definition
  </trainings/repertoire/c-like/cxx11>`, the language has undergone a
  major revolution. An overview is given.

Object Oriented Programming
---------------------------

* From :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`

  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/private-protected`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`
  * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

Standard Template Library
-------------------------

* Pointer Arithmetic Recap:
  :doc:`/trainings/material/soup/c/050-pointers-and-arrays/040-pointers-and-arrays/topic`
* :doc:`/trainings/material/soup/cxx03/060-stl/010-basics/topic`
* Basic Algorithms

  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/for_each`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/copy`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/reverse`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/reverse_copy`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/find`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/find_if`

* Sorted Array Algirithms

  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/sort`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/binary_search`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/lower_bound`

* Sequential Containers

  * :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/basics`
  * :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/vector`
  * :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/list`

* Associative Containers

  * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/basics`
  * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map`
  * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/multimap`

Exercise Series
---------------

Exercise series ideas ...

* Sensors

  * A sensor *abstract base class* - an *interface*
  * A number of concrete sensor implementations
  * A configured set of those, measuring live data
  * Live data is *posted* via another interface

* Display(s)

  * Another *interface* in the system
  * Display measurement values
  * Concrete implementation: a software PWM using a timer and a GPIO

C++11 Outlook
-------------

* Language features (from
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/group`)

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/055-constexpr/topic`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for-map`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/010-strongly-typed-enums/topic`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
