SS2024: Exam 2024-06-28 (Handout)
=================================

.. list-table::
   :align: left

   * * **Name**
     * 

Linux: OS Concepts
------------------

(From
:doc:`/trainings/material/soup/linux/basics/intro/exercises/fh-questions`)

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

Toolchain
---------

(From :doc:`/trainings/material/soup/linux/toolchain/exercises/fh-questions`)

* Compiler: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * The compiler combines multiple object files together into one
         executable
       * 
       * 
     * * The compiler turns a single source file into an object
         (``.o``) file
       * 
       *
     * * Object files are not executable
       * 
       *
     * * Object files are executable
       *
       * 

* Linker: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * The linker combines multiple object files together into one
         executable
       * 
       *
     * * The linker combines multiple object files together into a
         static library
       * 
       * 

* Cross: which of the following statements are true?

  .. list-table::
     :align: left
     :widths: auto
     :header-rows: 1

     * * Statement
       * True
       * False
     * * The cross compiler is an executable that runs on the build
         machine
       * 
       *
     * * The cross compiler is an executable that runs on the target
         machine
       * 
       *
     * * The cross compiler is linked against the C runtime
         (``libc.so``). That file is contained in the *sysroot*.
       * 
       * 
     * * The output that is produced by a cross toolchain runs on the
         target machine.
       * 
       * 
     * * The output that is produced by a cross toolchain is linked
         against the C runtime (``libc.so``). That file is contained
         in the *sysroot*.
       * 
       * 
