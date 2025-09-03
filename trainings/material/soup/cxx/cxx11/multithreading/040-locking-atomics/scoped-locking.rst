.. include:: <mmlalias.txt>


Scoped Locking
==============

.. contents::
   :local:

Explicit Unlocking Considered Dangerous
---------------------------------------

**What if a critical section throws?**

.. code-block:: c++

   lock.lock();
   do_something_errorprone(); // possibly throws
   do_more_of_it(); // possibly throws
   lock.unlock();

* Lock remains locked
* |longrightarrow| Deadlock

RAII - Resource Acquisition Is Initialization
---------------------------------------------

**Deterministic destructors**

* Objects are destroyed *at end of block*
* Unlike Java, Python, ... (garbage collection)
* |longrightarrow| **Exception safety!**

Simplest: ``std::lock_guard``
-----------------------------

.. sidebar::

   **Documentation**

   * `std::lock_guard
     <https://en.cppreference.com/w/cpp/thread/lock_guard>`__

* Obtains (single) lock in constructor
* Releases lock in destructor
* |longrightarrow| good for single lock
  
.. code-block:: c++
   :caption: ``std::lock_guard``

   ...
   // critical section
   {
     std::lock_guard<std::mutex> g(lock); // lock.lock()
     do_something_errorprone();
     do_more_of_it();
     // ~guard does lock.unlock();
   }
   ...

