.. include:: <mmlalias.txt>


Duplicating (Whats Going On?)
=============================

.. contents::
   :local:

File Descriptors, Open File, I-Node
-----------------------------------

.. list-table::
   :align: left
   :widths: auto

   * * File descriptor is a *handle* to a more complex structure
       inside the kernel

       **Open File**

       * Offset
       * Flags

       **I-Node**

       * Type
       * Block list
       * ...

     * .. image:: filenum.svg
          :scale: 60%

File Descriptors and Inheritance
--------------------------------

.. list-table::
   :align: left
   :widths: auto

   * * * A call to \texttt{fork()} inherits file descriptors
       * |longrightarrow| reference counted copy of the same *Open File*
       * |longrightarrow| Processes share flags and offset!
       * File closed (*open file* freed) only when last copy is closed
     * .. image:: filenum-fork.svg
          :scale: 60%

Duplicating File Descriptors
----------------------------

.. sidebar:: Documentation

   * `man -s 2 dup
     <https://man7.org/linux/man-pages/man2/dup.2.html>`__
   * `man -s 2 dup2
     <https://man7.org/linux/man-pages/man2/dup2.2.html>`__

.. list-table::
   :align: left
   :widths: auto

   * * .. code-block:: c

          #include <unistd.h>

          int dup(int oldfd);

       * Return: new file descriptor

       .. code-block:: c

          #include <unistd.h>

	  int dup2(int oldfd, int newfd);

       * ``newfd`` already open/occupied |longrightarrow| implicit
         ``close()``

     * .. image:: filenum-dup.svg
          :scale: 60%

Example: Shell Stdout-Redirection (1)
-------------------------------------

.. code-block:: console

   $ /bin/echo Hello > /dev/null

* Redirection is a shell responsibility ``/bin/bash``
* ``echo`` writes "Hello" to standard output
* ... and does not want/have to care where it actually goes

Example: Shell Stdout-Redirection (2)
-------------------------------------

.. code-block:: console

   $ strace -f bash -c '/bin/echo Hallo > /dev/null'
   [3722] open("/dev/null", O_WRONLY|O_...) = 3
   [3722] dup2(3, 1) = 1
   [3722] close(3) = 0
   [3722] execve("/bin/echo", ...) = 0

(``fork()``, ``exec()``, ``wait()`` omitted for clarity.)

Example: Shell Stdout-Redirection (3)
-------------------------------------

.. list-table::
   :align: left
   :widths: auto

   * * .. code-block:: c

          open("/dev/null")

       .. image:: filenum-redir-1.svg
          :scale: 60%

     * .. code-block:: c
    
          dup2(3, 1)

       .. image:: filenum-redir-2.svg
          :scale: 60%

     * .. code-block:: c

          close(3)

       .. image:: filenum-redir-3.svg
          :scale: 60%
