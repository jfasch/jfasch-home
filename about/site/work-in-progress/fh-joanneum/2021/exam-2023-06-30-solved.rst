SS2023: Exam 2023-06-30 (Solved)
================================

.. list-table::
   :align: left

   * * **Name**
     * 

UNIX/Linux Concepts
-------------------

(From
:doc:`/trainings/material/soup/linux/basics/intro/exercises/fh-questions`)

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Statement
     * True
     * False
   * * In kernel space there exists the concept of a process
     *
     * n
   * * In user space there exists the concept of a process
     * y
     *
   * * Interrupts are generally serviced in user space
     *
     * n
   * * Interrupts are generally serviced in kernel space
     * y
     *
   * * Scheduling of processes is done by the kernel
     * y
     *
   * * Address spaces are implemented in user space
     *
     * n
   * * A process can own all memory in the system
     *
     * n
   * * The kernel is the owner of all memory in the system
     * y
     *
   * * All processes share a single address space
     *
     * n
   * * Each process in the system has its own address space
     * y
     *
   * * An address space is three-dimensional
     *
     * n
   * * A process is identified by its process ID
     * y
     *
   * * A process is identified by its pthread context number
     *
     * n
   * * Processes are arranged in a process hierarchy, starting at
       process 1
     * y
     *
   * * A process may have multiple parents
     *
     * n
   * * Every process has a parent process
     *
     * n
   * * Every process except process 1 has a parent process
     * y
     *
   * * A timeslice is the amount of time that a process can run
       until it is suspended in favor of other processes
     * y
     *
   * * Fair scheduling ensures that network resources are evenly
       shared
     *
     * n
   * * On a single-CPU machine, no process may enter an infinite
       loop - or else, the entire machine will come to a halt
     *
     * n
   * * Fair scheduling ensures that every process gets its fair
       share of CPU resources
     * y
     *
   * * The scheduler gives processes the illusion that each of them
       owns the CPU
     * y
     *
   * * A context switch happens when one process enters a blocking
       system call
     * y
     *

Toolchain
---------

(From :doc:`/trainings/material/soup/linux/toolchain/exercises/fh-questions`)

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
     * n
   * * The compiler turns a single source file into an object
       (``.o``) file
     * y
     *
   * * Object files are not executable
     * y
     *
   * * Object files are executable
     *
     * n
   * * The linker combines multiple object files together into one
       executable
     * y
     *
   * * The linker combines multiple object files together into a
       static library
     * 
     * n

C++
---

(From
:doc:`/trainings/material/soup/cxx/cxx03/exercises-misc/fh-questions`)

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Statement
     * True
     * False
   * * When an action is said to lead to *undefined behavior*, this
       means that the program *will* crash
     *
     * n
   * * When an action is said to lead to *undefined behavior*, this
       means that the program *could* crash
     * y
     *
   * * When an action is said to lead to *undefined behavior*, this
       means that the program *will* continue but *will* wreak havoc on
       its data
     *
     * n
   * * When an action is said to lead to *undefined behavior*, this
       means that the program *could* continue but *could* wreak havoc
       on its data
     * y
     *
   * * A variable declared ``const`` can only be initialized and
       never modified.
     * y
     *
   * * A variable of type ``int`` which is declared ``const`` is
       initialized to 0 if no initializer is given.
     *
     * n
   * * Class members cannot be declared ``const``
     *
     * n
   * * ``const`` class member variables can be initialized in the
       constructor body
     *
     * n
   * * A *method* declared ``const`` promises to the compiler (and
       the caller) that a call to it does not modify the object it
       is called on
     * y
     *
   * * Declaring a class constructor ``const`` leads to undefined
       behavior
     *
     * n
   * * A reference variable can be left uninitialized
     *
     * n
   * * A caller that passes a variable to a function/method as a
       reference must take into account that the variable could be
       modified
     * y
     *
   * * A caller that passes a variable to a function/method as a
       ``const`` reference must take into account that the variable
       could be modified
     *
     * n
   * * A default constructor initializes an object when no
       initialization parameters are given
     * y
     *
   * * ``std::vector<>`` guarantees that it keeps elements in
       contiguous memory
     * y
     *
   * * In a ``std::vector<>`` instance that contains three elements,
       accessing index 3 (``vec[3]``) leads to undefined behavior
     * y
     *
   * * In a ``std::vector<>`` instance that contains three elements,
       accessing index 0 (``vec[0]``) leads to undefined behavior
     *
     * n
