.. ot-topic:: linux.sysprog.basics.errorhandling
   :dependencies: linux.sysprog.basics.syscalls

.. include:: <mmlalias.txt>


Error Handling
==============

.. contents::
   :local:

.. sidebar:: Documentation

   * `man -s 3 errno
     <https://man7.org/linux/man-pages/man3/errno.3.html>`__

The ``errno`` Variable
----------------------

On error, system calls (and most C library functions) return -1 and
set the *global* variable ``errno``.

.. code-block:: c
   :caption: Error handling with system calls

   ssize_t n = read(fd, buffer, sizeof(buffer));
   if (n == -1)
       if (errno == EINTR) {
           /* interrupted system call, retry possible */
	   ...
       }
       else {
           /* abort, reporting the error */
	   ...
       }

``errno`` Is A *Global* Variable
--------------------------------

**Where's the bug?**

.. code-block:: c
   :caption: Bad Error Handling

   ssize_t n = read(fd, buffer, sizeof(buffer));
   if (n == -1) {
       fprintf(stderr, "Error %d\n", errno);
       if (errno == EINTR)
           /* ... */
   }

Helper Functions
----------------

.. list-table:: 
   :align: left
   :widths: auto
   :header-rows: 1

   * * Prototype
     * Description
     * Documentation
   * * ``void perror(const char *s)`` 
     * Message to ``stderr``, beginning with ``s``
     * `man -s 3 perror
       <https://man7.org/linux/man-pages/man3/perror.3.html>`__
   * * ``char *strerror(int errnum)``
     * *Modifiable* pointer to error description
     * `man -s 3 strerror
       <https://man7.org/linux/man-pages/man3/strerror.3.html>`__
   * * ``char *strerror_r(int errnum, char *buf, size_t buflen)``
     * Cleanest alternative: ``_r`` |longrightarrow| "reentrant"
       (thread safe)
     * `man -s 3 strerror_r
       <https://man7.org/linux/man-pages/man3/strerror.3.html>`__

.. code-block:: c
   :caption: Error output

   if (n == -1)
       perror("read()");
