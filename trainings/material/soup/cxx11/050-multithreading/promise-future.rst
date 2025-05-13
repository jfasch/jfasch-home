.. include:: <mmlalias.txt>


``std::promise`` and ``std::future`` (And Some ``std::chrono``) (Some Live Hacking)
===================================================================================

.. contents::
   :local:

Overview
--------

.. code-block:: c++

   #include <future>

**One-shot communication device**

* One thread *promises* to *produce* a value
* Another thread *waits* for it to become valid in the *future*

.. code-block:: c++

   std::promise<int> promise;
   auto future = promise.get_future();

   // producer ...
   promise.set_value(42);

   // consumer ...
   int value = future.get();

(See :ref:`below <exceptions>` for how to transport exceptions across
thread boundaries)

Overview: ``std::promise``
--------------------------

.. sidebar:: 

   **Documentation**

   * `std::promise <https://en.cppreference.com/w/cpp/thread/promise>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Operation
     * Description
   * * Constructor
     * * Default
       * Move
   * * ``operator=()``
     * Move only
   * * ``get_future()``
     * Get ``std::future`` object connected to this promise
   * * ``set_value()``
     * Make promise come true (i.e. consumer will return from
       ``future.get()``)
   * * ``set_exception(std::exception_ptr p)``
     * Consumer's ``future.get()`` will throw exception pointed to by
       ``p``

.. note::

   Communication is only *one-shot*: cannot set value (or exception)
   multiple times

Overview: ``std::future``
-------------------------

.. sidebar:: 

   **Documentation**

   * `std::future <https://en.cppreference.com/w/cpp/thread/future>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Operation
     * Description
   * * Constructor
     * * Default. *Object is not valid*; use ``promise.get_future()``
         instead
       * Move
   * * ``operator=()``
     * Move only
   * * ``share()``
     * Create a `std::shared_future
       <https://en.cppreference.com/w/cpp/thread/shared_future>`__
       object. The original future object is invalid afterwards.
   * * ``get()``
     * If value is available, return it. Else, wait and then return.
   * * ``wait()``
     * Wait for value to become available, without getting it.
   * * ``wait_for()``, ``wait_until()``
     * Timeouts of various sorts

Utterly Wrong: Waiting For Something To Become Ready
----------------------------------------------------

.. sidebar:: 

   **Documentation**

   * `nanosleep
     <https://man7.org/linux/man-pages/man2/nanosleep.2.html>`__


* Separate, uncoordinated, flag and answer
* Use ``nanosleep()`` to poll/wait

.. literalinclude:: code/c++11-thread-future-polling-unlocked.cpp
   :caption: :download:`code/c++11-thread-future-polling-unlocked.cpp`
   :language: c++

* Bugs

  * Unlocked
  * CPU may reorder |longrightarrow| flag may be in place before
    answer is

* Polling interval

  * Less latency |longrightarrow| more CPU time needed
  * Tight loop for maximum reaction

Sideways: ``std::chrono``, And Literals
---------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/100-miscellaneous/010-chrono/topic`

* Replace ``<time.h>`` with ``<chrono>``
* Use cool literals with built-in units, and ``constexpr``

  .. code-block:: c++

     #include <chrono>
     
     using namespace std::literals::chrono_literals;
     
     static constexpr auto ANSWER_COMPUTATION_TIME = 2s;
     static constexpr auto ANSWER_POLL_INTERVAL = 2ms;

.. literalinclude:: code/c++11-thread-future-polling-unlocked-chrono.cpp
   :caption: :download:`code/c++11-thread-future-polling-unlocked-chrono.cpp`
   :language: c++

Minimal Fix: Use ``std::mutex``
-------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`

   **Documentation**

   * `std::mutex <https://en.cppreference.com/w/cpp/thread/mutex>`__

* Add ``std::mutex`` to flag and answer
* Don't (yet) use scoped locking; rather use clumsy
  (non-exception-safe) ``lock()`` and ``unlock()``, together with a
  ``done`` flag

.. literalinclude:: code/c++11-thread-future-polling-mutex.cpp
   :caption: :download:`code/c++11-thread-future-polling-mutex.cpp`
   :language: c++

Anti-Clumsiness: Scoped Locking
-------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`

   **Documentation**

   * `std::scoped_lock
     <https://en.cppreference.com/w/cpp/thread/scoped_lock>`__

* Use ``std::scoped_lock`` |longrightarrow| remove ``done`` flag, and
  simply break out of loop

.. literalinclude:: code/c++11-thread-future-polling-lockguard.cpp
   :caption: :download:`code/c++11-thread-future-polling-lockguard.cpp`
   :language: c++

Pro-Readability: Encapsulate
----------------------------

* Create ``class Answer``
* Methods: ``set()``, ``wait(duration)``

.. literalinclude:: code/c++11-thread-future-polling-encapsulated.cpp
   :caption: :download:`code/c++11-thread-future-polling-encapsulated.cpp`
   :language: c++

Atomics On Structures?
----------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`

* Nested ``struct data``: flag and answer
* Use ``std::atomic<data>`` inside ``class Answer``

.. literalinclude:: code/c++11-thread-future-polling-atomic-struct.cpp
   :caption: :download:`code/c++11-thread-future-polling-atomic-struct.cpp`
   :language: c++

Anti-Polling: Semaphore
-----------------------

* No ``std::mutex`` |longrightarrow| ``std::binary_semaphore``
  (initialized with 0)
* Discuss barrier instruction (signal/wait semaphore)
* Discuss: ``_answer_valid`` not needed when properly waited
* Discuss: OS wait conditions, blocking system calls, realtime

.. literalinclude:: code/c++11-thread-future-semaphore.cpp
   :caption: :download:`code/c++11-thread-future-semaphore.cpp`
   :language: c++

Getting To The Point: ``std::promise`` And ``std::future``
----------------------------------------------------------

.. literalinclude:: code/c++11-thread-future-promise-future.cpp
   :caption: :download:`code/c++11-thread-future-promise-future.cpp`
   :language: c++


.. _exceptions:

And Exceptions?
---------------

.. literalinclude:: code/c++11-thread-future-promise-future-exception.cpp
   :caption: :download:`code/c++11-thread-future-promise-future-exception.cpp`
   :language: c++

