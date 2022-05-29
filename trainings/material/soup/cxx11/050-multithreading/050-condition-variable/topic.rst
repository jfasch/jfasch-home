.. ot-topic:: cxx11.multithreading.condition_variable
   :dependencies: cxx11.multithreading.mutex,
		  linux.sysprog.posix_threads.condition_variable

.. include:: <mmlalias.txt>


Condition Variables
===================

Condition Variables
-------------------

**Condition Variable**

* The most basic communication device
* Everything else can be built around it (and a mutex)

  * Semaphores
  * Events
  * Message queues
  * Promises and futures (|longrightarrow| later)

Condition Variables: By Example
-------------------------------

.. literalinclude:: condvar-message-queue.cc
   :caption: :download:`condvar-message-queue.cc`

.. danger::

   ``while`` instead of ``if`` |longrightarrow| *Spurious Wakeups!*

More Communication: Future
--------------------------

**Problem:**

* Worker thread calculates *something* in the background
* Somebody waits (synchronizes) for that *something* to become ready
* That *something* will become ready *in the future*

**Solution:** 

* Condition variable and mutex
* encapsulated in a "future" device.
* Manually coded here for fun ...

.. literalinclude:: condvar-future.cc
   :caption: :download:`condvar-future.cc`

