.. include:: <mmlalias.txt>

.. ot-topic:: linux.sysprog.posix_threads.basics
   :dependencies: linux.sysprog.scheduling.basics


Basics
======

Why Threads?
------------

``fork()`` **is so beautiful**
  
* New process
* New address space
* |longrightarrow| no race conditions
* |longrightarrow| simple is beautiful!


**But ...**
  
* Process creation is expensive
* Separate address space |longrightarrow| communication is cumbersome
* Portability: Windows has no idea

Typical Uses
------------

* Use of multiple processors for compute-intensive calculation
* One is force to use a library that blocks

  * A no-go in a GUI application for example
  * Push it in a thread, call it there, and communicate with the
    thread however you feel best
  * Communication |longrightarrow| later

* Blocking I/O

  * Like the blocking library: push it in a dedicated thread
  * But there are better anti-naive solutions (Unix is not Windows)

Overview
--------

* Creating threads
* Synchronisation: *Mutex*
* Communication: *Condition variable*
* Thread specific data (a.k.a. thread local storage)
* One-time initialization

Legal (1)
---------

**Threads of one process share the following resources:**
  
* Process memory
* PID and PPID
* Credentials
* Open files
* Signal *handler*
* Umask, Current Working Directory, etc.
* ...

Legal (2)
---------

**Threads have the following attributes of their own:**
  
* Thread ID (TID)

  * Scheduler only cares about *threads*
  * A process is just a container (which happens to have the ID of the
    *main thread*)

* Stack
* ``errno``
* Signal **mask**
* Thread specific data (TSD)
* ...

POSIX Thread API
----------------

* POSIX thread API is not implemented in the kernel

  * User space library
  * ``man 3 ...``
  * ``strace`` is of limited use

* ``errno`` is thread spezific |longrightarrow| "semi-global"
* No PThread function sets ``errno``

  * They generally return what otherwise would be ``-errno``
  * *Thank you!*

* ``gcc -pthread``

  * Defines macro ``_REENTRANT``
  * Links ``-lpthread``
  * C++: thread safe initialization of local ``static``
