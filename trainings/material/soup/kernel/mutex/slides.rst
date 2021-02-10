.. include:: <mmlalias.txt>

Mutex (and RT Mutex) (Slideshow)
================================

.. contents::
   :local:

.. sidebar:: Source

   `See Github <https://github.com/jfasch/jf-kernel-course/tree/my_driver_mutex/_morph>`__

Locking in the Kernel
---------------------

**Userspace parallelism is simple** ...

* *All* code is preemptible
* ... no way to disable preemption
* Critical sections are best protected by a mutex ``pthread_mutex_t``)

**Kernel parallelism is different** ...

* Schedulable code

  * Processes in kernel mode
  * kernel threads

* Non-schedulable code

  * Interrupt service routines
  * Other atomic code (spinlock holders)

Mutual Exclusion: Mutex
-----------------------

**Process context vs. process context**

* Classic mutex semantics
* Binary semaphore
* If held, arriving processes have to wait - they are scheduled*

.. code-block:: c

   #include <linux/mutex.h>
   struct mutex mutex;

.. code-block:: c
   :caption: OO-like constructor and destructor

   mutex_init(&mutex);
   mutex_destroy(&mutex);

Mutex: Locking (1)
------------------

**Locking** is done in many different ways ...

.. code-block:: c

   mutex_lock(&mutex);

**Preferred version**: *interruptible*

.. code-block:: c

   int error = mutex_lock_interruptible(&mutex);

* Puts the caller to sleep if lock is held by someone else

  * Attention: no protection against self-deadlock!

* "Interruptible": return ``-EINTR`` ("Interrupted system call") if
  process receives a signal

  * Good old Unix

* Uninterruptible sleeps should be used with care

Mutex: Locking (2)
------------------

**Recursive locking** ...

.. code-block:: c

   int error = mutex_lock_interruptible_nested(&mutex);

* Same process may lock multiple times (no deadlock)
* Must unlock as many times
* Use is questionable though

**Polling** ...

.. code-block:: c

   int error = mutex_trylock(&mutex);

* Lock if not held
* Otherwise, return ``-EAGAIN`` immediately
* Use is even more questionable than recursive

Mutex: Releasing
----------------

**At the end of the critical section** ...

.. code-block:: c

   mutex_unlock(&mutex);

* Releases the lock
* Wakes up waiter if any

Realtime Mutex
--------------

**``struct mutex`` does not support priority inheritance**

Linus Torvalds does not like realtime ...

    "Friends don't let friends use priority inheritance. Just don't do
    it. If you really need it, your system is broken anyway."

* `LWN article
  <https://lwn.net/Articles/178253/}{\texttt{lwn.net/Articles/178253/>`__
* Features from the ``PREEMPT_RT`` tree keep trickling in
* |longrightarrow| "Realtime" mutex with priority inheritance
* Used just like ordinary mutex

.. code-block:: c

   #include <linux/rtmutex.h>
   struct rt_mutex mutex;
