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

.. contents::
   :local:

Introduction: What C++ >= 11 Brings
...................................

* :doc:`/trainings/material/soup/cxx/cxx11/introduction/overview-livehacking` (the outcome of it being `new-cpp.cpp <https://github.com/jfasch/2024-06-03/blob/main/livecoding/new-cpp.cpp>`__
* :doc:`/trainings/material/soup/cxx/cxx11/auto/topic`, including 

  * a discussion of how arrays continue to *decay* to pointers in C++,
    using ``auto``
  * a demo of good old C decayed arrays, `ptr-decay.cpp
    <https://github.com/jfasch/2024-06-03/blob/main/livecoding/ptr-decay.cpp>`__

* :doc:`/trainings/material/soup/cxx/cxx11/range-for/range-based-for`
* :doc:`/trainings/material/soup/cxx/cxx11/structured-binding/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda`, 
  and its relationship with ``std::function``, 
  :doc:`/trainings/material/soup/cxx/cxx11/bind-function/020-function/topic`

  * A little upside down show of it, `lambda.cpp
    <https://github.com/jfasch/2024-06-03/blob/main/livecoding/lambda.cpp>`__
  * Walking through the inevitable capturing syntax,
    :doc:`/trainings/material/soup/cxx/cxx11/lambda/lambda-capture`

Smart Pointers: ``std::shared_ptr<>``, ``std::unique_ptr<>`` (And A Little ``std::move``)
.........................................................................................

From :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/index`:

* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/introduction/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/weak-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/closing-words/topic`

Livecoding experiences:

* `unique-ptr.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/smart-pointers/unique-ptr.cpp>`__
* `weak-ptr.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/smart-pointers/weak-ptr.cpp>`__

Day 2
-----

.. contents::
   :local:

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

* From :doc:`/trainings/material/soup/misc/unittest/index`

  * :doc:`/trainings/material/soup/misc/unittest/unittest_gtest_basics/topic`
  * :doc:`/trainings/material/soup/misc/unittest/unittest_gtest_cmake/topic`
  * :doc:`/trainings/material/soup/misc/unittest/unittest_gtest_fixture/topic`

A Little CMake
..............

From :doc:`/trainings/material/soup/misc/cmake/index` (only what we use
from it)

* :doc:`/trainings/material/soup/misc/cmake/intro/basics`
* :doc:`/trainings/material/soup/misc/cmake/intro/libraries`
* :doc:`/trainings/material/soup/misc/cmake/intro/structure`

.. _exercise-day-2:

Exercise: ``class Sensor``, And A ``SensorConfig`` Thereof
..........................................................

* Implementation detail:
  :doc:`/trainings/material/soup/cxx/cxx03/060-stl/050-associative-containers/map`
* See ``tests`` directory in our Github project: https://github.com/jfasch/2024-06-03/tree/main/tests

  * Working: ``tests/sensor-const-suite.cpp``
  * Working: ``tests/sensor-random-suite.cpp``
  * Not working: ``tests/sensor-config-suite.cpp``. Does not even
    compile |longrightarrow| commented-out in ``tests/CMakeLists.txt``

* Comment-in ``tests/sensor-config-suite.cpp``
* Add implementation files ``toolcase/sensor-config.h`` and
  ``toolcase/sensor-config.cpp``, and fix until tests run.

Multithreading: Threads, Race Conditions, Locking Primitives
............................................................

From :doc:`/trainings/material/soup/cxx/cxx11/multithreading/index`:

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/010-introduction/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/020-thread/topic`

  Dissecting *joinable* vs. *detached* threads: `join-vs-detach.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/join-vs-detach.cpp>`__

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/atomics`

  ``i++`` made thread safe with ``std::atomic<>``:
  `mother-of-race-conditions--atomic.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/mother-of-race-conditions--atomic.cpp>`__

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/mutex`

  ``i++`` made thread safe with ``std::mutex`` (rather slow though):
  `mother-of-race-conditions--mutex.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/mother-of-race-conditions--mutex.cpp>`__

Day 3
-----

.. contents::
   :local:

Exercise: Make ``SensorConfig`` Thread Safe
...........................................

Based upon the :ref:`exercise from Day 2 <exercise-day-2>`,

* Implement new requirements from `tests/sensor-config-suite.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/tests/sensor-config-suite.cpp>`__
* Make ``SensorConfig`` thread safe. Empirically check its thread
  safety by running `tests/sensor-config-maybe-mt-safe.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/tests/sensor-config-maybe-mt-safe.cpp>`__

  (See `sensor-config.h
  <https://github.com/jfasch/2024-06-03/blob/main/toolcase/sensor-config.h>`__
  and `sensor-config.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/toolcase/sensor-config.cpp>`__)

Multithreading: Communication
.............................

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/promise-future`

  See a contrived ping-pong game, livecoded in `promise-future.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/promise-future.cpp>`__

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/condition-variable`

  See an implementation of a thread safe queue, livecoded in
  `thread-safe-queue.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/threads/thread-safe-queue.cpp>`__

  (A templated version of it available as `queue.h
  <https://github.com/jfasch/2024-06-03/blob/main/toolcase/queue.h>`__)

Day 4
-----

.. contents::
   :local:

Exercise Time
.............

Group 1: Data Logger (Sketch)
`````````````````````````````

Given N ``Sensor`` instances in a ``SensorConfig``, sketch a
producer-consumer scenario over a ``Queue`` (the thread safe queue
from `queue.h
<https://github.com/jfasch/2024-06-03/blob/main/toolcase/queue.h>`__),

* N threads producing ``(timestamp, sensor_name, sensor_value)``
  measurements into the queue.
* One thread consuming those samples from the queue, and writing them
  to ``stdout`` as they arrive.

Group 2: Use ``std::latch``
```````````````````````````

.. sidebar:: Documentation

   * `std::latch <https://en.cppreference.com/w/cpp/thread/latch>`__

* Read the `std::latch
  <https://en.cppreference.com/w/cpp/thread/latch>`__ documentation
* Given that communication device, and an understanding of it, write a
  program that pulls up a scenario that is just right for
  it. ("Construct a problem that fits the solution.")

.. _my-latch:

Group 3: Program a ``MyLatch`` Class
````````````````````````````````````

.. sidebar:: Documentation

   * `std::latch <https://en.cppreference.com/w/cpp/thread/latch>`__
   * `std::condition_variable
     <https://en.cppreference.com/w/cpp/thread/condition_variable>`__

* Read the `std::latch
  <https://en.cppreference.com/w/cpp/thread/latch>`__ documentation,
  and make sense of it.
* Write your own ``MyLatch`` implementation (presumably using a
  `std::condition_variable
  <https://en.cppreference.com/w/cpp/thread/condition_variable>`__ and
  a `std::mutex <https://en.cppreference.com/w/cpp/thread/mutex>`__)

Outcome:

* Implementation: `my-latch.h
  <https://github.com/jfasch/2024-06-03/blob/main/toolcase/my-latch.h>`__
* Test suite: `latch-suite.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/tests/latch-suite.cpp>`__
  (note how :doc:`futures
  </trainings/material/soup/cxx/cxx11/multithreading/promise-future>`
  can be used to achieve tests determinism)
* Demo program: `latch-demo.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/programs/latch-demo.cpp>`__

.. code-block:: console

   $ ./programs/latch-demo 1.2 3.6 0.1 7.5
   producer #3 arriving
   producer #1 arriving
   producer #2 arriving
   producer #4 arriving
   consumer says "yessss, everybody arrived"

RValue References, Move Semantics
.................................

* :doc:`/trainings/material/soup/cxx/cxx11/move/overview`
* Lengthy livecoding: *Rule Of 5?*

  * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/object-copy`
  * :doc:`/trainings/material/soup/cxx/cxx11/move/livehack-string-move`
  * :doc:`/trainings/material/soup/cxx/cxx11/move/livehack-using-string-move`

  Outcome `string-move.cpp
  <https://github.com/jfasch/2024-06-03/blob/main/livecoding/string-move.cpp>`__

* :doc:`/trainings/material/soup/cxx/cxx11/perfect-forwarding/topic`
