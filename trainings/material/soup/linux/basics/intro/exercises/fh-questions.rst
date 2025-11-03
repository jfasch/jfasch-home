Quiz: Linux Basics
==================

User Space, Kernel Space
------------------------

* Kernel/user space: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * In kernel space there exists the concept of a process
       *
       * 
     * * In user space there exists the concept of a process
       * 
       *
     * * Interrupts are generally serviced in user space
       *
       * 
     * * Interrupts are generally serviced in kernel space
       * 
       *
     * * Scheduling of processes is done by the kernel
       * 
       *
     * * Address spaces are implemented in user space
       *
       * 

* How do programs communicate with the kernel? (One answer)

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * System calls
       * 
       *
     * * Message queues
       *
       * 
     * * IO ports
       *
       * 
     * * Reverse interrupts
       *
       * 

* File abstraction: which concepts are represented by file decriptors?
  
  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * Files
       * 
       *
     * * Network sockets
       * 
       *
     * * Timers
       * 
       *
     * * Serial/UART devices
       * 
       *
     * * Memory
       *
       * 
     * * The process stack
       *
       * 

* The term "blocking" describes which behavior? (One answer)

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * A process can *block* another for communication purposes
       *
       * 
     * * A process consumes no CPU time while it waits for an event to
         happen
       * 
       *
     * * The kernel blocks access to network resources to enhance
         system security
       *
       * 

Processes, Scheduling, and Virtual Memory
-----------------------------------------

* Scheduling: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * A timeslice is the amount of time that a process can run
         until it is suspended in favor of other processes
       * 
       *
     * * Fair scheduling ensures that network resources are evenly
         shared
       *
       * 
     * * On a single-CPU machine, no process may enter an infinite
         loop - or else, the entire machine will come to a halt
       *
       * 
     * * Fair scheduling ensures that every process gets its fair
         share of CPU resources
       * 
       *
     * * The scheduler gives processes the illusion that each of them
         owns the CPU
       * 
       *
     * * A context switch happens when one process enters a blocking
         system call
       * 
       *

* Virtual Memory: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * A process can own all memory in the system
       *
       * 
     * * The kernel is the owner of all memory in the system
       * 
       *
     * * All processes share a single address space
       *
       * 
     * * Each process in the system has its own address space
       * 
       *
     * * An address space is three-dimensional
       *
       * 

* Processes: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * A process is identified by its process ID
       * 
       *
     * * A process is identified by its pthread context number
       *
       * 
     * * Processes are arranged in a process hierarchy, starting at
         process 1
       * 
       *
     * * A process may have multiple parents
       *
       * 
     * * Every process has a parent process
       *
       * 
     * * Every process except process 1 has a parent process
       * 
       *

(:doc:`Solutions <fh-solutions>`)
