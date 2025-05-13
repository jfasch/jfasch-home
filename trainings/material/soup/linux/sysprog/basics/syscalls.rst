.. include:: <mmlalias.txt>


System Calls vs. Library Functions
==================================

.. contents::
   :local:

System Calls
------------

.. sidebar:: Documentation

   * `man -s 2 intro (big picture)
     <https://man7.org/linux/man-pages/man2/intro.2.html>`__
   * `man -s 2 syscalls (syscall overview page)
     <https://man7.org/linux/man-pages/man2/syscalls.2.html>`__
   * `man -s 2 syscall (the syscall macro)
     <https://man7.org/linux/man-pages/man2/syscall.2.html>`__

The kernel is not a library |longrightarrow| no direct function calls,
but rather *System Calls*.

* Entry points into the kernel
* Every system call has a unique number and a fixed set of parameters
  and registers (ABI)
* Changes context from user mode to kernel mode
* Implementation is CPU specific (software interrupt ...)
* Numbers, parameters, etc. are Linux specific
* |longrightarrow| "kernel acts on behalf of a process"

System Calls And The C-Library
------------------------------

.. list-table::
   :align: left
   :widths: auto
   
   * * System calls are never used directly by a program ...

       .. code-block:: c
	  :caption: syscall wrapper: ``write()``

          #include <unistd.h>
          int main() {
              write(1, "hallo\n", 6);
              return 0;
          }

     * .. image:: syscalls-libc.svg
          :scale: 50%

Library Function Or System Call?
--------------------------------

Distinction is not always clear |longrightarrow| manual pages

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * System calls (``man -s 2 ...``)
     * *No* system calls (``man -s 3 ...``)
   * * * ``write()`` (`man -s 2 write
         <https://man7.org/linux/man-pages/man2/write.2.html>`__)
       * ``read()`` (`man -s 2 read
         <https://man7.org/linux/man-pages/man2/read.2.html>`__)
       * ``connect()`` (`man -s 2 connect
         <https://man7.org/linux/man-pages/man2/connect.2.html>`__)
       * ...
     * * ``malloc()`` (`man -s 3 malloc
         <https://man7.org/linux/man-pages/man3/malloc.3.html>`__)
       * ``printf()`` (`man -s 3 printf <https://man7.org/linux/man-pages/man3/printf.3.html>`__)
       * ``getaddrinfo()`` (`man -s 3 getaddrinfo <https://man7.org/linux/man-pages/man3/getaddrinfo.3.html>`__
       *  ...

Manual Pages
------------

``man [section] name``

For example: ``man man`` |longrightarrow|

#. User Commands
#. System Calls
#. C Library Functions
#. Devices and Special Files
#. File Formats and Conventions
#. Games et. Al.
#. Miscellanea
#. System Administration tools and Daemons
