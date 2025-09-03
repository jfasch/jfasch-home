.. include:: <mmlalias.txt>


``std::condition_variable`` (Live Hacking Multithreaded Queue)
==============================================================

.. contents::
   :local:

Overview
--------

.. code-block:: c++

   #include <condition_variable>

**Generic communication device**

* Communicate changes in shared state |longrightarrow|
  notification/wakeup
* Used together with a :doc:`mutex
  </trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/mutex>`

**Operations**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Operation
     * Description
   * * *wait*
     * * Atomically unlocks mutex, and puts calling thread to sleep
         until condition is *signalled*
       * When condition is signalled, atomically takes the mutex and
         wakes one (or all) waiters
   * * *signal* (*notify*)
     * Signal the condition variable (i.e., notify waiter)

**Sample communication scenarios**

* Semaphores
* Events
* Message queues
* :doc:`Promises and futures <promise-future>`

Overview: Operations
--------------------

.. sidebar:: 

   **Documentation**

   * `std::condition_variable <https://en.cppreference.com/w/cpp/thread/condition_variable>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Operation
     * Description
   * * Constructor
     * Default only (cannot move when someone's waiting)
   * * ``wait(lock, stop_waiting)``
     * * ``lock``: unique lock guard
       * ``stop_waiting``: callable (predicate) that returns ``bool``;
         see :ref:`below <predicate>`
   * * ``wait_for()``, ``wait_until()``
     * Timeouts of various sorts
   * * ``notify_one()``
     * Notify (and wakeup) one waiting thread
   * * ``notify_all()``
     * Notify (and wakeup) all waiting threads

.. note::

   Broadcasting (``notify_all()``) a condition variable wakes up all
   waiting threads. If only one can handle the event, then waking all
   is a waste of resources - in this case ``notify_one()`` should
   rather be used.

   See `Thundering herd problem
   <https://en.wikipedia.org/wiki/Thundering_herd_problem>`__

Communication, Polling: Thread-Safe Queue
-----------------------------------------

* Double-ended queue (``std::deque``)
* Producer adds to tail
* Consumer removes from head
* Protected by a mutex
* Corner cases |longrightarrow| **conditions**

  * Queue is full
  * Queue is empty
  * |longrightarrow| spin on either side if condition holds

.. literalinclude:: code/c++11-thread-condvar-queue-polling.cpp
   :caption: :download:`code/c++11-thread-condvar-queue-polling.cpp`
   :language: c++

Anti-Polling: Thread-Safe Queue, And POSIX Condition Variables
--------------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/sysprog/posix-threads/060-condition-variable/topic`

.. literalinclude:: code/c++11-thread-condvar-queue-pthread.cpp
   :caption: :download:`code/c++11-thread-condvar-queue-pthread.cpp`
   :language: c++

Discussion: Signalling And Waiting, Predicates: *Separation Of Concerns*
------------------------------------------------------------------------

* Waiting - and *atomically releasing a mutex* - is one thing

  * Necessary to implement *any* kind of parallel handshake
  * |longrightarrow| OS building block

.. _predicate:

* The *condition* itself is part of the concrete problem

  Here:

  * Full: ``_queue.size() == _maxelem`` |longrightarrow| wait until
    *not empty*
  * Empty: ``_queue.size() == 0`` |longrightarrow| wait until *not
    full*

  |longrightarrow| **predicate**

* Signalling wakes a waiter (possibly immediately, depending on
  realtime attributes, and whatnot)

  * Signalling while holding the mutex |longrightarrow| waiter has to
    go to sleep waiting for the mutex *again*
  * |longrightarrow| best done when *not* holding the mutex

* Mutex: scoped locking would be great also

That being said ...

Thread-Safe Queue, And C++ Condition Variables
----------------------------------------------

**Wish list**

* Scoped locking: ``std::unique_lock`` (see :doc:`here
  </trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/mutex>`)
* Predicate: parameter (usually a lambda) to ``condvar.wait()``

.. literalinclude:: code/c++11-thread-condvar-queue-condvar.cpp
   :caption: :download:`code/c++11-thread-condvar-queue-condvar.cpp`
   :language: c++
