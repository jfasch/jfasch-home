.. include:: <mmlalias.txt>


C++ For Embedded Developers (2023-04-18 - 2023-04-20)
=====================================================

.. contents::
   :local:

.. sidebar::

   * Start: Monday 9:00
   * 3 days
   * Project on Github: https://github.com/jfasch/2023-04-18

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

Work Environment
----------------

Preferred: Ubuntu under Windows (WSL)
.....................................

I suggest you use the :doc:`Windows Subsystem For Linux (WSL2)
</trainings/material/soup/linux/basics/intro/wsl>` (Microsoft
documentation `here
<https://docs.microsoft.com/en-us/windows/wsl/>`__). This sets up a
virtualized Ubuntu inside Windows, together with all interoperability
wazoo.

When installed, open a Ubuntu terminal, and install the software that
is required for this training.

.. code-block::

   $ sudo apt update
   $ sudo apt install git build-essential cmake libgtest-dev libgmock-dev

Skeleton Project Setup
......................

Follow the instructions in the `course project README
<https://github.com/jfasch/2023-04-18>`__ to setup the initial version
of the course project.

Day 1
-----

Introduction
............

* :doc:`/trainings/material/soup/cxx/cxx11/introduction/index`

  * :doc:`/trainings/material/soup/cxx/cxx11/introduction/overview-livehacking`
  * Outcome, including a quit-flag for the threads: `intro.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/livehacking/intro.cpp>`__

Some Details
............

* A little ``constexpr``: `constexpr.cpp
  <https://github.com/jfasch/2023-04-18/blob/main/livehacking/constexpr.cpp>`__
* From :doc:`/trainings/material/soup/cxx/cxx11/lambda/index`

  * :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda`
  * :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda-capture`
  * ChatGPT bashing ("How would you compute the squares of a list of
    numbers with a lambda, like you would in Python?"):
    `lambda-transform.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/livehacking/lambda-transform.cpp>`__
  * More about lambda: `lambda.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/livehacking/lambda.cpp>`__

* A little threading (more:
  :doc:`/trainings/material/soup/cxx/cxx11/multithreading/index`)

  * And Python's ``asyncio``? (maybe watch the video in
    :doc:`/about/site/work-in-progress/blink/index` |:metal:|)

Standard Template Library
.........................

From :doc:`/trainings/material/soup/cxx/cxx03/060-stl/index`

* :doc:`/trainings/material/soup/cxx/cxx03/060-stl/010-basics/topic`
* :doc:`/trainings/material/soup/cxx/cxx03/060-stl/015-vector-copy-etc/topic`
* :doc:`/trainings/material/soup/cxx/cxx03/060-stl/020-algorithm/index`
* :doc:`/trainings/material/soup/cxx/cxx03/060-stl/040-sequential-containers/index`
* :doc:`/trainings/material/soup/cxx/cxx03/060-stl/050-associative-containers/index`

OO
..

From
:doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/index`

* :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/c`
* :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/cpp-introduction`
* :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/ctor-custom`
* :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/ctor-default`

Day 2
-----

Warm-Up
.......

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/020-thread/topic`
   * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/mutex`
   * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/atomics`

* ``std::atomic<>``. Revisit Ludwig's ChatGPT findings, and introduce
  a signal handler in `intro.cpp
  <https://github.com/jfasch/2023-04-18/blob/main/livehacking/intro.cpp>`__.

  * Memory visibility across multiple CPUs?
  * Cache invalidation?
  * *Memory model?*

* A little threading (from
  :doc:`/trainings/material/soup/cxx/cxx11/multithreading/index`)

  * Load-modify-store conflict: `race-condition.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/livehacking/race-condition.cpp>`__
  * Fixed with mutex (and a nice little class encapsulating all that):
    `race-condition-fixed-mutex.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/livehacking/race-condition-fixed-mutex.cpp>`__
  * Fixed with ``std::atomic<>``: `race-condition-fixed-atomic.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/livehacking/race-condition-fixed-atomic.cpp>`__

Sensor Exercise, Resolved
.........................

* Implement (live-hacked) `test-sensor.cpp
  <https://github.com/jfasch/2023-04-18/blob/main/group-joerg/tests/test-sensor.cpp>`__

  * https://github.com/jfasch/2023-04-18/blob/main/group-joerg/lib/sensor.h
  * `sensor-registry.h
    <https://github.com/jfasch/2023-04-18/blob/main/group-joerg/lib/sensor-registry.h>`__
  * `sensor-registry.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/group-joerg/lib/sensor-registry.cpp>`__

* Discussing OO issues:
  :doc:`/trainings/material/soup/cxx/cxx-design-patterns/oo-principles`

OO, Cont'd
..........

From
:doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/index`

* :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/010-overloading/topic`
* :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/020-methods/topic`
* :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/040-this/topic`
* :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/050-references/topic`
* :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/060-static/topic`
* :doc:`/trainings/material/soup/cxx/cxx03/030-functions-and-methods/070-operators/topic`
* Exercise: Fix Issues In Project

Smart Pointers
..............

* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/shared-ptr/topic`
* With this, fix memleak

Day 3
-----

Smart Pointers (Continued)
..........................

* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/unique-ptr/topic`
* Morphed our "registry" universe to use those ...

  * `sensors-main.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/group-joerg/bin/sensors-main.cpp>`__
  * `sensor-registry.h
    <https://github.com/jfasch/2023-04-18/blob/main/group-joerg/lib/sensor-registry.h>`__
  * `sensor-registry.cpp
    <https://github.com/jfasch/2023-04-18/blob/main/group-joerg/lib/sensor-registry.cpp>`__

Heavy Weight OO |:muscle:|
..........................

Complete the pointless ``point`` class, by quickly moving across the
following topics from
:doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/index`

* :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/copy-basics`
* :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/ctor-dtor`
* :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/object-copy`

From
:doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/index`

* :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/basics`
* :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/virtual-method`
* :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/pure-virtual`
* :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/destructor`
* :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/interface`

See live-hacked code in `interfaces.cpp
<https://github.com/jfasch/2023-04-18/blob/main/livehacking/interfaces.cpp>`__.

Exception Handling
..................

From :doc:`/trainings/material/soup/cxx/cxx03/040-exceptions/index`:

* :doc:`/trainings/material/soup/cxx/cxx03/040-exceptions/020-try-catch/topic`

Exercises: Containers And Algorithms 
....................................

From :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/index`:

* :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/vector`
* :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/map`
* :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/algo`
* :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/uniq`
* :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/filter-odd`
* :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/filter-greater-10`
* :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/filter-generic`
* :doc:`/trainings/material/soup/cxx/cxx-exercises/stl/sensor-repository/index`

Exercises: OO And Interfaces
............................

* :doc:`/trainings/material/soup/cxx/cxx-exercises/sensor-interface/sensor-interface`
  (polymorphic use of different sensors)
* :doc:`Averaging sensor ("Composite" pattern)
  </trainings/material/soup/cxx/cxx-design-patterns/composite/composite>`
* :doc:`/trainings/material/soup/cxx/cxx-exercises/sensor-w1/sensor-w1`
  (OneWire sensor - in the Linux OneWire style)
* :doc:`/trainings/material/soup/cxx/cxx-exercises/sensor-w1-factory/sensor-w1-factory`
  (*factory* pattern - a class that creates OneWire sensors *by address*)
