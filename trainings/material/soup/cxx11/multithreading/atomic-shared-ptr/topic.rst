.. include:: <mmlalias.txt>


Atomic Shared Pointer (``std::atomic<std::shared_ptr<>``)
=========================================================

.. contents::
   :local:

.. sidebar:: Documentation

   * https://en.cppreference.com/w/cpp/memory/shared_ptr/atomic2

Safe: Control Block Modification
--------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/smart-pointers/sharedptr`

.. literalinclude:: code/safe.cpp
   :caption: :download:`code/safe.cpp`
   :language: c++

.. _cxx11-thread-atomic-shared-ptr-sync-thread-start:

Sideways: Synchronizing With Thread Startup (1)
-----------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/multithreading/promise-future`

* A note on ``use_count()``: threads may not even running yet
* |longrightarrow| ``use_count()`` is nothing to build upon
* Synchronization/communication needed
* |longrightarrow|
  :doc:`/trainings/material/soup/cxx11/multithreading/promise-future`

.. literalinclude:: code/safe-future-spoiler.cpp
   :caption: :download:`code/safe-future-spoiler.cpp`
   :language: c++

Sideways: Synchronizing With Thread Startup (2)
-----------------------------------------------

.. sidebar:: Trainer's note

   For simplicity, start only one thread

.. literalinclude:: code/safe-future.cpp
   :caption: :download:`code/safe-future.cpp`
   :language: c++

Unsafe: Assignment To Shared Pointer
------------------------------------

.. literalinclude:: code/problem.cpp
   :caption: :download:`code/problem.cpp`
   :language: c++

Solution: ``std::atomic_store<>`` Specialization
------------------------------------------------

.. sidebar:: Documentation

   * `https://en.cppreference.com/w/cpp/memory/shared_ptr/atomic`

* Deprecated in C++20

.. literalinclude:: code/solution-atomic-function-specialization.cpp
   :caption: :download:`code/solution-atomic-function-specialization.cpp`
   :language: c++

Solution: ``std::atomic<std::shared_ptr>``
------------------------------------------

* Don't want manually enable thread safety by using global function
* Better: want the *object itself* to be thread safe
* Drawback: no ``std::make_atomic_shared()``

.. literalinclude:: code/solution-atomic-specialization.cpp
   :caption: :download:`code/solution-atomic-specialization.cpp`
   :language: c++
