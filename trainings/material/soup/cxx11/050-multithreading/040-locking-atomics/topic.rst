.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.multithreading.locking_atomics
   :dependencies: cxx11.multithreading.race_conditions, 
		  linux.sysprog.posix_threads.mutex


Locking and Atomics
===================

Mutex
-----

**Exclusive lock**

* Can be taken by *only one thread*
* Methods:

  * lock: take (and possibly wait for) lock
  * unlock
  * try lock: take lock, or return error if locked

.. code-block:: c++

   #include <mutex>
   std::mutex lock;
   
   lock.lock();
   ... critical section ...
   lock.unlock();

Scoped Locking (1)
------------------

**What if a critical section throws?**

.. code-block:: c++

   lock.lock();
   do_something_errorprone(); // possibly throws
   do_more_of_it(); // possibly throws
   lock.unlock();

* Lock remains locked
* |longrightarrow| Deadlock

Scoped Locking (2)
------------------

**Deterministic destructors**

* Objects are destroyed *at end of block*
* Unlike Java, Python, ... (garbage collection)
* |longrightarrow| **Exception safety!**
  
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

Mutex: Pros and Cons
--------------------

**Mutexes are expensive**

* *Context switch* on wait |longrightarrow| expensive
* Can only be used in thread context
* Interrupts *cannot wait*
* |longrightarrow| *Never share mutexed objects with an interrupt routine!*
* |longrightarrow| *Undefined behavior*

**Mutexes are easy**

* Can protect arbitrarily long critical sections

Atomic Instructions (1)
-----------------------

Simple integers don't need a mutex |longrightarrow| *atomic
instructions*

.. code-block:: c++
   :caption: GCC: atomic built-ins

   static int global;
   void inc() {
     __sync_fetch_and_add(&global, 1);
   }

.. code-block:: c++
   :caption: Windows

   static LONG global;
   void inc() {
     InterlockedIncrement(&global);   
   }

Atomic Instructions (2)
-----------------------

.. code-block:: c++

   #include <atomic>
   std::atomic<int> global(0);
   void inc() {
     global++;
   }
  
* Specializations for all types that are capable

Self-Deadlocks (1)
------------------

**Deadlocks**: one more dimension in bug-space

* Usually between two threads
* **Self-deadlock**: between one thread

.. code-block:: c++
   :caption: The most obvious self-deadlock

   std::mutex lock;
   ...
   lock.lock();
   lock.lock(); // wait forever

Self-Deadlocks (2)
------------------

*(Only slightly) more intelligent ways to lock the same mutex twice
...*

* Calling a callback while holding the lock

  * *What?*
  * *Passing control to untrusted code when critical??*

* Public method uses another public method of the same object

  * |longrightarrow| Safer: distinguish between "locked" (public) and
    "unlocked" (private) methods
  * "locked" may only use "unlocked"

|longrightarrow| Design decision

Working Around Self-Deadlocks: Recursive Mutex
----------------------------------------------

**Recursive mutex ...**

* Same thread can enter an arbitrary number of times
* Has to exit exactly as many times to release the mutex for *other*
  threads

.. code-block:: c++
   :caption: The most obvious self-deadlock

   std::recursive_mutex lock;
   ...
   lock.lock(); // locked for others
   lock.lock(); // granted
   // ...
   lock.unlock();
   lock.unlock(); // released for others
