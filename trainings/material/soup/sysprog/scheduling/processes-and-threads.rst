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
   :caption: :download:`code/embedded-app-1-irq.cpp`
   :language: cpp

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

.. literalinclude:: code/embedded-app-2-irq.cpp
   :caption: :download:`code/embedded-app-2-irq.cpp`
   :language: cpp

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
  * Syncronous ways of sleeping
  * Arbitrary number of *virtual timers*, multiplexed on top of
    physical timer chips

* |longrightarrow| replace timer interrupts with synchronous loops in
  tasks

.. literalinclude:: code/embedded-app-tasks.cpp
   :caption: :download:`code/embedded-app-tasks.cpp`
   :language: cpp

.. code-block:: console

   $ g++ -o /tmp/embedded-app-tasks embedded-app-tasks.cpp -lrt -lpthread
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

Threads Are Great: More Functionality
-------------------------------------

* Not being interrupt driven anymore
* |longrightarrow| good
* |longrightarrow| flexible
* |longrightarrow| **lets add more functionality!**

Nonsense: switch terminal between reverse and normal

* Reverse: ``"\033[7m"``
* Normal: ``"\033[0m"``

.. literalinclude:: code/embedded-app-more-tasks.cpp
   :caption: :download:`code/embedded-app-more-tasks.cpp`
   :language: cpp

.. code-block:: console

   $ g++ -o /tmp/embedded-app-more-tasks embedded-app-more-tasks.cpp -lrt -lpthread
   $ /tmp/embedded-app-more-tasks
   ...

Are Threads Great?
------------------

* Cramming tons of functionality into a single program requires some
  programming skills

  * Program = Microcontroller

* Our program approaches 200 lines which is still manageable
  (functionality is trivial though)
* Need internet?
* Need filesystem?
* Need *<insert favorite feature>*?

**Worst case**: one thread causes a bug ... (hint: it's the unrelated
terminal flasher)

.. literalinclude:: code/embedded-app-more-tasks-buggy.cpp
   :caption: :download:`code/embedded-app-more-tasks-buggy.cpp`
   :language: cpp

.. code-block:: console

   $ g++ -o /tmp/embedded-app-more-tasks-buggy embedded-app-more-tasks-buggy.cpp -lrt -lpthread
   $ /tmp/embedded-app-more-tasks-buggy
   ...

Stability Considerations
------------------------

Three *tasks* (indepenently running entities)

#. Update status
#. Show status
#. Toggle terminal fore/background

Stability considerations

* The first two are related (communicate)
* The last one is complete unrelated - *it even causes a bug*

**Probably the latter requires a bit more isolation!**

Processes, Address Spaces
-------------------------

* `Memory Management Unit (MMU)
  <https://en.wikipedia.org/wiki/Memory_management_unit>`__
* Maps *virtual* addresses to *physical* addresses
* Adds memory *protections* (on a per-*page* granularity, usually 4K)

  * Read-only
  * Executable (contains CPU instructions)
  * ...

  |longrightarrow| Memory access exceptions, leading to program crash

* Enter **address spaces**

  * A *process* has its own address space
  * *Must not* access memory that it does not own; **Segmentation
    fault** (in `Unix terminology
    <https://en.wikipedia.org/wiki/Segmentation_fault>`__), or
    **Memory access violation**

Stabilizing
-----------

* Lets rip the offender out; "*decouple the rest from it*"
* Make a *single threaded* program that we start separately. Respectively,

  * Revert back to :download:`code/embedded-app-tasks.cpp`
  * Flash terminal in separate program

.. literalinclude:: code/flash-terminal.cpp
   :caption: :download:`code/flash-terminal.cpp`
   :language: cpp

.. code-block:: console

   $ g++ -o /tmp/flash-terminal flash-terminal.cpp
   $ /tmp/flash-terminal &         # <--- BACKGROUND, ON SAME TERMINAL!
   $ /tmp/embedded-app-tasks 
   ... stable terminal flashing here ...

