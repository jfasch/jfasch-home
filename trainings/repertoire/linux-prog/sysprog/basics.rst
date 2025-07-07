Linux Systems Programming: Introduction
=======================================

.. contents::
   :local:

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
	* 2 days
      * * **Language**
	* Trainer language is English or German
      * * **Material**
	* * :doc:`/trainings/material/soup/python/basics/index`
	  * :doc:`Complete Python material
            </trainings/material/soup/python/index>`
      * * **Related**
	* * :doc:`/trainings/material/soup/linux/sysprog/index`
	  * PDF Slides, :download:`sysprog
            </trainings/material/pdf/020-linux-sysprog--en.pdf>`
      * * **Booking**
	* :doc:`/trainings/info`


This introductory course gives an overview of the OS, the
interconnections between its concepts, and how to program it.

Course Outline
--------------

* **The Shell**. Being UNIX's first user interface, it is intimately
  tied to the system and a good instrument to get insight into it. The
  course gets you started in shell usage.
* **OS concepts, and system calls**. Exploring the system, still using
  the shell.

  * Processes (and the ``/proc`` filesystem), filesystems,
    IO-redirection, ...
  * ``strace``: introspecting the system call interface
  * Several examples of *Everything is a File* - probably UNIX's
    strongest concept, and how Linux extends it

* **The toolchain**. Learn how to build your programs.

  * Compiler, Linker
  * Debugger
  * Static and shared libraries
  * Executables
  * :doc:`GNU Make <../../misc/make>`

* **Programming**. Many small exercises bring you through the course
  content.

  * Processes: ``fork/exec/wait``, signal handling
  * Filesystem: ``open/read/write/close``
  * Filedescriptors, and associated system calls
  
Prerequisites
-------------

A solid understanding of the C programming language is helpful. Fun
with low-level hacking is required.
