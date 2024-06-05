.. include:: <mmlalias.txt>


C++: A Thorough Overview (2024-06-03)
=====================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda

.. sidebar::

   **Github Repository**

   * https://github.com/jfasch/2024-06-03

   **Original Agenda** 

   * :doc:`agenda`

Day 1
-----

Introduction: What C++ >= 11 Brings
...................................

* :doc:`/trainings/material/soup/cxx11/010-introduction/overview-livehacking` (the outcome of it being `new-cpp.cpp <https://github.com/jfasch/2024-06-03/blob/main/livecoding/new-cpp.cpp>`__
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`, including 

  * a discussion of how arrays continue to *decay* to pointers in C++,
    using ``auto``
  * a demo of good old C decayed arrays, `ptr-decay.cpp
    <https://github.com/jfasch/2024-06-03/blob/main/livecoding/ptr-decay.cpp>`__

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`, 
  and its relationship with ``std::function``, 
  :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`

  * A little upside down show of it, `lambda.cpp
    <https://github.com/jfasch/2024-06-03/blob/main/livecoding/lambda.cpp>`__
  * Walking through the inevitable capturing syntax,
    :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`

Smart Pointers: ``std::shared_ptr<>``, ``std::unique_ptr<>`` (And A Little ``std::move``)
.........................................................................................

From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`:

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

Livecoding experiences:

* `unique-ptr.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/smart-pointers/unique-ptr.cpp>`__
* `weak-ptr.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/smart-pointers/weak-ptr.cpp>`__

Day 2
-----

Morning Awakening
.................

* ``mutable`` on lambda, to capture value by non-const copy:
  `weak-ptr.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/smart-pointers/weak-ptr.cpp>`__

Unit Testing, Test Driven Development, And ``googletest``
.........................................................

* Relevant parts from :download:`Design Patterns and Test Driven
  Development (PDF)
  </trainings/material/pdf/060-design-patterns-unittests.pdf>`

* From :doc:`/trainings/material/soup/unittest/group`

  * :doc:`/trainings/material/soup/unittest/unittest_gtest_basics/topic`
  * :doc:`/trainings/material/soup/unittest/unittest_gtest_cmake/topic`
  * :doc:`/trainings/material/soup/unittest/unittest_gtest_fixture/topic`

A Little CMake
..............

From :doc:`/trainings/material/soup/cmake/group` (only what we use
from it)

* :doc:`/trainings/material/soup/cmake/intro/basics`
* :doc:`/trainings/material/soup/cmake/intro/libraries`
* :doc:`/trainings/material/soup/cmake/intro/structure`

.. _exercise-day-2:

Exercise: ``class Sensor``, And A ``SensorConfig`` Thereof
..........................................................

* Implementation detail:
  :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map`
* See ``tests`` directory in our Github project: https://github.com/jfasch/2024-06-03/tree/main/tests

  * Working: ``tests/sensor-const-suite.cpp``
  * Working: ``tests/sensor-random-suite.cpp``
  * Not working: ``tests/sensor-config-suite.cpp``. Does not even
    compile |longrightarrow| commented-out in ``tests/CMakeLists.txt``

* Comment-in ``tests/sensor-config-suite.cpp``
* Add implementation files ``toolcase/sensor-config.h`` and
  ``toolcase/sensor-config.cpp``, and fix until tests run.

Multithreading
..............

From :doc:`/trainings/material/soup/cxx11/050-multithreading/group`:

* :doc:`/trainings/material/soup/cxx11/050-multithreading/010-introduction/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/020-thread/topic`

  Dissecting *joinable* vs. *detached* threads: `join-vs-detach.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/join-vs-detach.cpp>`__

* :doc:`/trainings/material/soup/cxx11/050-multithreading/030-race-conditions/topic`
  
  ``i++`` ain't thread safe - the *load/modify/store conflict*:
  `mother-of-race-conditions.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/mother-of-race-conditions.cpp>`__

* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`

  ``i++`` made thread safe with ``std::atomic<>``:
  `mother-of-race-conditions--atomic.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/mother-of-race-conditions--atomic.cpp>`__

* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`

  ``i++`` made thread safe with ``std::mutex`` (rather slow though):
  `mother-of-race-conditions--mutex.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/mother-of-race-conditions--mutex.cpp>`__

Day 3
-----

Multithreading, Continued
.........................

* Exercise time: based upon the :ref:`exercise from Day 2
  <exercise-day-2>`,

  * Implement new requirements from `tests/sensor-config-suite.cpp
    <https://github.com/jfasch/2024-06-03/blob/main/tests/sensor-config-suite.cpp>`__
  * Make ``SensorConfig`` thread safe. Empirically check its thread
    safety by running `tests/sensor-config-maybe-mt-safe.cpp
    <https://github.com/jfasch/2024-06-03/blob/main/tests/sensor-config-maybe-mt-safe.cpp>`__

    (See `sensor-config.h
    <https://github.com/jfasch/2024-06-03/blob/main/toolcase/sensor-config.h>`__
    and `sensor-config.cpp
    <https://github.com/jfasch/2024-06-03/blob/main/toolcase/sensor-config.cpp>`__)

* :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`

  See a contrived ping-pong game, livecoded in `promise-future.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/promise-future.cpp>`__

* :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`

  See an implementation of a thread safe queue, livecoded in
  `thread-safe-queue.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/thread-safe-queue.cpp>`__

  (A templated version of it available as `queue.h
  <https://github.com/jfasch/2024-06-03/blob/main/toolcase/queue.h>`__)
