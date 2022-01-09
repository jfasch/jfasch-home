.. ot-topic:: sysprog.scheduling.processes_and_threads
   :dependencies: sysprog.scheduling.basics

.. include:: <mmlalias.txt>



Tasks? Processes? Threads?
==========================

.. contents::
   :local:

Tasks
-----

* In userspace, there is no such thing as a task
* Only processes and threads
* Kernel/scheduler is different

  * Process *is-a* task
  * Thread *is-a* task

* Tasks are *scheduled*

A Typical Bare Metal Application
--------------------------------

**Back in Time, Back in Technology**

* One timer interrupt with two responsibilities

  * Update status
  * Show status

.. literalinclude:: code/embedded-app-1-irq.cpp

.. code-block:: console

   $ g++ -o /tmp/embedded-app-1-irq embedded-app-1-irq.cpp -lrt
   $ /tmp/embedded-app-1-irq 
   ----------
   ----------
   ----------
   ----------
   ----------
   ----------
   ----------
   ----------
   ----------
   ----------
   /---------        <---- rising
   //--------
   ///-------
   ////------
   /////-----
   //////----
   ^C
   
Hm. Need Another Timer Interrupt!
---------------------------------

* Update rates and display rates are the same currently
* Want them to diverge for whatever reason
* |longrightarrow| "update" timer (0.5s, and a separate "show" timer
  (1s)

.. literalinclude:: code/embedded-app-1-irq.cpp

.. code-block:: console

   $ g++ -o /tmp/embedded-app-1-irq embedded-app-2-irq.cpp -lrt
   $ /tmp/embedded-app-2-irq 
   ----------
   ----------
   ----------
   ----------
   ----------
   ----------
   //--------
   ////------
   //////----
   ////////--
   //////////
   \\////////
   ^C

(Missing every second status update, roughly)

Away From Interrupts: Use An Operating System
---------------------------------------------

* I want to do periodic actions
* Number of actions will soon exceed number of timer chips
* |longrightarrow| need something more capable
* |longrightarrow| an Embedded OS

  * `FreeRTOS <https://www.freertos.org/>`__ is a popular choice these
    days

* Embedded OSen typically come with

  * *Tasks* and a *task scheduler*
  * Syncronous way of sleeping

* |longrightarrow| replace timer interrupts with synchronous loops in
  tasks

.. literalinclude:: code/embedded-app-tasks.cpp

.. code-block:: console

   $ g++ -o /tmp/embedded-app-tasks embedded-app-tasks.cpp -lrt
   $ /tmp/embedded-app-tasks
   ...

Tasks?
------

* Great win: one process with two tasks (threads)
* Lets do some introspection

.. code-block:: console

   $ ps -efl|grep embedded-app-tasks
   0 S jfasch    231765  225819  0  80   0 -  5635 -      17:47 pts/4    00:00:00 /tmp/embedded-app-tasks
   $ ps -L 231765
       PID     LWP TTY      STAT   TIME COMMAND
    231765  231765 pts/4    Sl+    0:00 /tmp/embedded-app-tasks
    231765  231766 pts/4    Sl+    0:00 /tmp/embedded-app-tasks
    231765  231767 pts/4    Sl+    0:00 /tmp/embedded-app-tasks

* ``strace``: `system call tracer
  <https://en.wikipedia.org/wiki/Strace>`__

.. code-block:: console
   :caption: main thread

   $ strace -p 231765
   strace: Process 231765 attached
   pause(
   
.. code-block:: console
   :caption: update thread

   $ strace -p 231766
   strace: Process 231766 attached
   restart_syscall(<... resuming interrupted read ...>) = 0
   clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=0, tv_nsec=500000000}, NULL) = 0
   ...

.. code-block:: console
   :caption: show thread

   $ strace -p 231767
   strace: Process 231767 attached
   restart_syscall(<... resuming interrupted read ...>) = 0
   write(1, "\\\\\\\\\\\\////\n\0", 12)    = 12
   ...
