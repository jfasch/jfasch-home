.. ot-exercise:: linux.basics.intro.fh_moodle_quiz
   :dependencies: linux.basics.intro.overview,
		  linux.sysprog.blocking_io.blocking_io_file,
		  linux.basics.intro.demo_everything_is_a_file,
		  linux.basics.intro.process


FH/Moodle Quiz: Linux Basics
============================

.. contents::
   :local:

Questions
---------

User Space, Kernel Space
........................

* Kernel/user space: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto

     * * In kernel space there exists the concept of a process
       * n
     * * In user space there exists the concept of a process
       * y
     * * Interrupts are generally serviced in user space
       * n
     * * Interrupts are generally serviced in kernel space
       * y
     * * Scheduling of processes is done by the kernel
       * y
     * * Address spaces are implemented in user space
       * n

* How do programs communicate with the kernel? (One answer)

  .. list-table::
     :align: left
     :widths: auto

     * * System calls
       * y
     * * Message queues
       * n
     * * IO ports
       * n
     * * Reverse interrupts
       * n

* File abstraction: which concepts are represented by file decriptors?
  
  .. list-table::
     :align: left
     :widths: auto

     * * Files
       * y
     * * Network sockets
       * y
     * * Timers
       * y
     * * Serial/UART devices
       * y
     * * Memory
       * n
     * * The process stack
       * n

* The term "blocking" describes which behavior? (One answer)

  .. list-table::
     :align: left
     :widths: auto

     * * A process can *block* another for communication purposes
       * n
     * * A process consumes no CPU time while it waits for an event to
         happen
       * y
     * * The kernel blocks access to network resources to enhance
         system security
       * n

Processes, Scheduling, and Virtual Memory
.........................................

* Scheduling: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto

     * * A timeslice is the amount of time that a process can run
         until it is suspended in favor of other processes
       * y
     * * Fair scheduling ensures that network resources are evenly
         shared
       * n
     * * On a single-CPU machine, no process may enter an infinite
         loop - or else, the entire machine will come to a halt
       * n
     * * Fair scheduling ensures that every process gets its fair
         share of CPU resources
       * y
     * * The scheduler gives processes the illusion that each of them
         owns the CPU
       * y
     * * A context switch happens when one process enters a blocking
         system call
       * y

* Virtual Memory: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto

    * * A process can own all memory in the system
      * n
    * * The kernel is the owner of all memory in the system
      * y
    * * All processes share a single address space
      * n
    * * Each process in the system has its own address space
      * y

* Processes: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto

     * * A process is identified by its process ID
       * y
     * * A process is identified by its pthread context number
       * n
     * * Processes are arranged in a process hierarchy, starting at
         process 1
       * y
     * * A process may have multiple parents
       * n
     * * Every process has a parent process
       * n
     * * Every process but process 1 has a parent process
       * y

Dependencies
------------

.. ot-graph::
   :entries: linux.basics.intro.fh_moodle_quiz
