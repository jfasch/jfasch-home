.. ot-topic:: linux.sysprog.fileio.misc
   :dependencies: linux.sysprog.fileio.basics

.. include:: <mmlalias.txt>


Miscellaneous
=============

.. contents::
   :local:

I/O without Offset Manipulation
-------------------------------

.. sidebar:: Documentation

   * `man -s 2 pread <https://man7.org/linux/man-pages/man2/pwrite.2.html>`__
   * `man -s 2 pwrite <https://man7.org/linux/man-pages/man2/pwrite.2.html>`__

.. code-block:: c

   #include <unistd.h>

   ssize_t pread(int fd, void *buf, size_t count, off_t offset);
   ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);

* ``read()`` and ``write()`` have been made for *sequential* access
* Random access only together with ``lseek()``
* Inefficient
* Not *atomic* |longrightarrow| race conditions!

Scatter/Gather I/O
------------------

.. sidebar:: Documentation

   * `man -s 2 readv <https://man7.org/linux/man-pages/man2/readv.2.html>`__
   * `man -s 2 writev <https://man7.org/linux/man-pages/man2/readv.2.html>`__

.. code-block:: c

   #include <sys/uio.h>

   ssize_t readv(int fd, const struct iovec *iov, int iovcnt);
   ssize_t writev(int fd, const struct iovec *iov, int iovcnt);

* Often data is not present in one contiguous block

  * E.g. layered protocols

* |longrightarrow| Copy pieces together, or issue repeated small system calls
* |longrightarrow| Scatter/Gather I/O

Scatter/Gather I/O, without Offset Manipulation
-----------------------------------------------

.. sidebar:: Documentation

   * `man -s 2 preadv <https://man7.org/linux/man-pages/man2/readv.2.html>`__
   * `man -s 2 pwritev <https://man7.org/linux/man-pages/man2/readv.2.html>`__

.. code-block:: c

   #include <sys/uio.h>

   ssize_t preadv(int fd, const struct iovec *iov, int iovcnt,
                  off_t offset);
   ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt,
                   off_t offset);

Truncating Files
----------------

.. sidebar:: Documentation

   * `man -s 2 truncate <https://man7.org/linux/man-pages/man2/truncate.2.html>`__
   * `man -s 2 ftruncate <https://man7.org/linux/man-pages/man2/truncate.2.html>`__

.. code-block:: c

   #include <unistd.h>

   int truncate(const char *path, off_t length);
   int ftruncate(int fd, off_t length);

* Truncating a file ...
* ... or create a hole (|longrightarrow| ``lseek()``)

File Descriptors - Allocation
-----------------------------

Value of the next file descriptors is not arbitrarily chosen
|longrightarrow| next free slot, starting at 0.

.. code-block:: c
   :caption: Filedescriptor Allocation

   close(STDIN_FILENO);
   int fd = open("/dev/null", O_WRONLY);
   assert(fd == 0);
