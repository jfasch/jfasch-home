.. include:: <mmlalias.txt>


Threads Introduction
====================

Operating System Primitives
---------------------------

* C++ does not *implement* threads
* They only wrap OS primitives

  * POSIX Threads |longrightarrow| `man pthreads
    <https://man7.org/linux/man-pages/man7/pthreads.7.html>`__
  * Windows |longrightarrow| MSDN
  * Embedded OSen?

There Be Dragons
----------------

**Threads are the work of the devil!**

* Everything that used to be correct in a singlethreaded world is
  questionable in the face of threads
* *Race conditions*, even in the most innocent looking places

**Corollary:**

* A project that was designed without threads in mind is useless with threads
* Multithreading has to be planned *from the beginning*
* Creation of a new thread must be justified before God

*That being said ...*
