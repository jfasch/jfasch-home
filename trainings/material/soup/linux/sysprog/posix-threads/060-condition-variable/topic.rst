.. include:: <mmlalias.txt>


Communication: Condition Variable
=================================

Condition Variable (1)
----------------------

.. sidebar::

   **Documentation**

   * `pthread_cond_init
     <https://linux.die.net/man/3/pthread_cond_init>`__
   * `pthread_cond_destroy
     <https://linux.die.net/man/3/pthread_cond_destroy>`__
   * `pthread_cond_wait
     <https://linux.die.net/man/3/pthread_cond_wait>`__
   * `pthread_cond_signal
     <https://linux.die.net/man/3/pthread_cond_signal>`__
   * `pthread_cond_broadcast
     <https://linux.die.net/man/3/pthread_cond_broadcast>`__

**Communication**: 

* One thread waits for a certain event to happen
* The event is produced by another thread
* The waiting thread does not consume and CPU time while waiting (polling is dumb)
* Solution in Windows: *WIN32 Events* (auto-reset, manual-reset)

**POSIX is different:** *Condition Variable*

* No state (as opposed to WIN32 Events --- set/unset)
* Operations ``wait()`` and ``signal()``
* Useless on its own
* Building block to build custom communication mechanisms around
  custom conditions

Condition Variable (2)
----------------------

**Sample conditions** (*predicates*, in POSIX parlance):
  
* Event has been set
* Message queue is not empty anymore
* Message queue is not full anymore
* Semaphore count is not zero anymore
* ...

Condition is coupled with a state which is protected by a *mutex*. For
example:

* Boolean flag "set/unset"
* Message queue implementation (linked list?)

Condition Variable: ``wait()``
------------------------------

.. code-block:: c
   :caption: `man 3 pthread_cond_wait <https://linux.die.net/man/3/pthread_cond_wait>`__

   int pthread_cond_wait(
       pthread_cond_t *cond,
       pthread_mutex_t *mutex);

.. danger::

   In an **atomic** operation (otherwise |longrightarrow| "Lost
   Wakeup")

* Releases mutex
* Suspends caller until condition variable is *signaled* by another
  thread

Condition Variable: ``signal()``
--------------------------------

.. code-block:: c
   :caption: `man 3 pthread_cond_signal <https://linux.die.net/man/3/pthread_cond_signal>`__

   int pthread_cond_signal(pthread_cond_t *cond);

Again, in an **atomic** operation:

* Wakes one waiter if any
* Lets him acquire the mutex

Example: WIN32 Auto Reset Event (1)
-----------------------------------

.. code-block:: c
   :caption: Setting the event

   void set_autoreset_event(Event* ev)
   {
       pthread_mutex_lock(&ev->mutex);
       ev->value = 1;
       pthread_mutex_unlock(&ev->mutex);
       pthread_cond_signal(&ev->is_set);
   }

Example: WIN32 Auto Reset Event (2)
-----------------------------------

.. code-block:: c
   :caption: Waiting for the event

   void wait_autoreset_event(Event* ev)
   {
       pthread_mutex_lock(&ev->mutex);
       while (ev->value != 1) {
           pthread_cond_wait(&ev->is_set, &ev->mutex);
           /* mutex acquiriert */
       }
       ev->value = 0; /* "autoreset" */
       pthread_mutex_unlock(&ev->mutex);
   }

Condition Variable: Checking the Predicate
------------------------------------------

**Use** ``while`` **instead of** ``if`` **, because ...**
  
* Spurious wakeups are possible (for example if the PThread
  implementation is using signals internally)
* Multiple waiters are woken (broadcast)

  * Predicate is true, but the first thread invalidates it immediately

Condition Variable: Initialization
----------------------------------

.. code-block:: c
   :caption: `man 3 pthread_cond_init <https://linux.die.net/man/3/pthread_cond_init>`__

   int pthread_cond_destroy(pthread_cond_t *cond);
   int pthread_cond_init(pthread_cond_t *cond,
          const pthread_condattr_t *attr);
   pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
  
* Dynamic initialization using
  ``pthread_cond_init()``/``pthread_cond_destroy()``
* ``attr == NULL`` |longrightarrow| default condition variable
* Static initialization using ``PTHREAD_COND_INITIALIZER``

Condition Variable: Miscellaneous
---------------------------------

.. code-block:: c
   :caption: `man 3 pthread_cond_broadcast <https://linux.die.net/man/3/pthread_cond_broadcast>`__

   int pthread_cond_broadcast(pthread_cond_t *cond);

.. code-block:: c
   :caption: `man 3 pthread_cond_timedwait <https://linux.die.net/man/3/pthread_cond_wait>`__

   int pthread_cond_timedwait(
       pthread_cond_t *cond,
       pthread_mutex_t *mutex,
       const struct timespec *abstime);
