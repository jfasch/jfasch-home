.. include:: <mmlalias.txt>

.. ot-topic:: sysprog.posix_threads.last_warning
   :dependencies: sysprog.posix_threads.miscellaneous


Last Warning
============

Last Warning (1)
----------------

**Multithreading does not go together well with** ``fork()``
  
* ``fork()`` copies the address space |longrightarrow| locked mutexes
* ``fork()`` leaves only the calling thread alive in the child

  * All others are gone

* If you have to use ``pthread_atfork()`` you're lost
* ``exec()`` is ok - everything's gone anyway.

  * But why the hell would one do this?

* Signals are not ok at all

Last Warning (2)
----------------

**Multithreading is dangerous!**
  
* It is sexy
* It is easy - a thread is created in no time (gosh: :doc:`C++11
  </trainings/material/soup/cxx11/group>`)
* There are race conditions *everywhere*
* Keep hands off cancellation
* Careful when sharing data structures |longrightarrow| global
  variables aren't bad for no reason
* **Debugging is nearly impossible**

Last Warning (3)
----------------

``man pthreads``: `legalese that deserves reading
<https://man7.org/linux/man-pages/man7/pthreads.7.html>`__

* "Thread-safe functions": please *please* read!
* "Async-cancel-safe functions" |longrightarrow| don't use
  cancellation

