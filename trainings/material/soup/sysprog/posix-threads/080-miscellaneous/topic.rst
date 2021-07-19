.. include:: <mmlalias.txt>

.. jf-topic:: sysprog.posix_threads.miscellaneous
   :dependencies: sysprog.posix_threads.exercise_condition_variable


Miscellaneous
=============

One-Time Initialization (1)
---------------------------

**Where's the bug?**

.. code-block:: c
   :caption: Bad code

   static X *global;
   
   void use_global()
   {
       if (global == NULL)
           global = new X;
       // ... use global ...
   }

One-Time Initialization (2)
---------------------------

.. code-block:: c
   :caption: Good code

   static pthread_once_t global_once = PTHREAD_ONCE_INIT;
   static X *global;
   static void init_global() { global = new X; }
   
   void use_global()
   {
       pthread_once(&global_once, init_global);
       // ... use global ...
   }

One-Time Initialization (3)
---------------------------

.. code-block:: c
   :caption: `man 3 pthread_once <https://linux.die.net/man/3/pthread_once>`__

   int pthread_once(pthread_once_t *once_control,
          void (*init_routine)(void));
   pthread_once_t once_control = PTHREAD_ONCE_INIT;

Thread Specific Data, Thread Local Storage
------------------------------------------

POSIX thread API for *Thread Specific Data* - per thread global
variables |longrightarrow| `man 3 pthread_key_create
<https://linux.die.net/man/3/pthread_key_create>`__ (including
example).

Non-portable alternative:

.. code-block:: c
   :caption: ``__thread Keyword``

   static __thread X* global;
