.. include:: <mmlalias.txt>

.. ot-topic:: sysprog.posix_threads.mutex
   :dependencies: sysprog.posix_threads.exercise_pthcreate_racecondition


Synchronization
===============

.. sidebar::

   .. contents::
      :local:

   **See also**

   * :doc:`../locked-trylock`

Race Conditions (1)
-------------------

.. sidebar::

   * Race condition (Python): :download:`here <lost-increment.py>`
   * No race condition (Python): :download:`here
     <no-lost-increment.py>`

.. list-table::
   :align: left

   * * Suppose ``inc()`` is executed by at least two threads in
       parallel:

       .. code-block:: c
	  :caption: Very bad code

          static int global;
          
          void inc()
          {
              global++;
          }

     * 
       ====== ====     ====== ====  ===========
       **CPU A**         **CPU B**  **Memory**
       -----------     -----------  -----------
       Instr   Loc     Instr   Loc  Glob
       load     42     -       -     42 
       -        42     load    42    42 
       inc      43     -       -     42 
       -        43     inc     43    42 
       -        43     store   43    43 
       store    43     -       43    43 
       ====== ====     ====== ====  ===========

       * The variable ``global`` has seen **only one increment!!**
       * *Load/Modify/Store Conflict*
       * The most basic race condition

Race Conditions (2)
-------------------

**Imagine more complex data structures (linked lists, trees)**: if
incrementing a dumb integer bears a race condition, then what can we
expect in a multithreaded world?

* No single data structure of C++'s Standard Template Library is thread safe
* ``std::string``'s copy constructor and assignment operator are
  thread safe (*GCC's Standard C++ Library* |longrightarrow| *not* by
  standard)
* ``std::string``'s other methods are *not* thread safe
* *stdio* and *iostream* are thread safe (by standard since C++11)

Mutex (1)
---------

.. code-block:: c
   :caption: `man 3 pthread_mutex_init <https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html>`__

   int pthread_mutex_init(pthread_mutex_t *mutex,
          const pthread_mutexattr_t *attr);
   int pthread_mutex_destroy(pthread_mutex_t *mutex);
   pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

* Dynamic initialization using
  ``pthread_mutex_init()/``pthread_mutex_destroy()``
* ``attr == NULL`` |longrightarrow| default mutex (|longrightarrow|
  later)
* Static initialization using ``PTHREAD_MUTEX_INITIALIZER``

Mutex (2)
---------

.. code-block:: c
   :caption: `man 3 pthread_mutex_lock <https://linux.die.net/man/3/pthread_mutex_lock>`__

   int pthread_mutex_lock(pthread_mutex_t *mutex);
   int pthread_mutex_trylock(pthread_mutex_t *mutex);
   int pthread_mutex_unlock(pthread_mutex_t *mutex);

* Simple lock/unlock must be enough
* *If you find yourself using "trylock", then something's wrong**
* *Polling is never right!*

Mutex (3)
---------

.. code-block:: c
   :caption: Better code

   static pthread_mutex_t global_mutex = 
       PTHREAD_MUTEX_INITIALIZER;
   static int global;
   
   void inc()
   {
       /* error handling omitted */
       pthread_mutex_lock(&global_mutex);
       global++;
       pthread_mutex_unlock(&global_mutex);
   }

Mutex Types
-----------

.. code-block:: c
   :caption: `man 3 pthread_mutexattr_settype <https://linux.die.net/man/3/pthread_mutexattr_settype>`__

   int pthread_mutexattr_settype(
       pthread_mutexattr_t *attr, int type);

* ``PTHREAD_MUTEX_NORMAL``: no checks, no nothing. Same thread locks
  mutex twice in a row before unlock |longrightarrow| *Deadlock*.
* ``PTHREAD_MUTEX_ERRORCHECK``: Deadlock check; unlocking a mutex
  locked by another thread |longrightarrow| *Error*
* ``PTHREAD_MUTEX_RECURSIVE``: owner can lock same mutex twice
* ``PTHREAD_MUTEX_DEFAULT`` |longrightarrow| ``PTHREAD_MUTEX_NORMAL``

Atomic Instructions
-------------------

Simple integers don't need a mutex

.. code-block:: c
   :caption: ``fetch_and_add()``

   static int global;
   
   void inc()
   {
       __sync_fetch_and_add(&global, 1);
   }

More |longrightarrow| ``info gcc``, GCC manual
