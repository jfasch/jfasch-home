.. include:: <mmlalias.txt>


Files: ``open/read/write/close`` (Overview)
===========================================

``open()``
----------

.. sidebar:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 close
     <https://man7.org/linux/man-pages/man2/close.2.html>`__

Swiss army knife: multiple actions, governed by bitwise-or'ed flags:

* Create/Open/Truncate/...
* Access intention ("mode"): open for reading, writing, both
* Hundreds of others

.. code-block:: c

       #include <fcntl.h>

       int open(const char *pathname, int flags);
       int open(const char *pathname, int flags, mode_t mode);

``open()`` Flags
----------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/basics/permissions/basics`

**Access Mode**

.. sidebar:: Examples

   * :doc:`example-O_RDONLY`
   * :doc:`example-O_WRONLY`

* ``O_RDONLY``: Can only ``read()``; error on ``write()``
* ``O_WRONLY``: Can only ``write()``; error on ``read()``
* ``O_RDWR``: ...

**Creating a File**

* ``O_CREAT``: create if not exists, else simply open
* ``O_CREAT|O_EXCL``: *exclusive creation*

  * *error* if file exists
  * |longrightarrow| to prevent race conditions when two parties try
    to create a file at the smae time
  * security measure

**Miscellaneous**

* ``O_APPEND``: write access appends at the end
* ``O_TRUNC``: truncate file to zero length if already exists
* ``O_CLOEXEC``: ``exec()`` closes the file descriptor
  (|longrightarrow| later)

``read()``
----------

.. sidebar:: Documentation

   * `man -s 2 read
     <https://man7.org/linux/man-pages/man2/read.2.html>`__

.. code-block:: c

   #include <unistd.h>

   ssize_t read(int fd, void *buf, size_t count);

* Return value: number of bytes read (-1 on error, :doc:`as always
  </trainings/material/soup/linux/sysprog/syscalls-and-errors/errorhandling/index>`)
* ``0`` is *End of File* (EOF)
* Can read less than ``count`` (usually with network I/O)

``write()``
-----------

.. sidebar:: Documentation

   * `man -s 2 write
     <https://man7.org/linux/man-pages/man2/write.2.html>`__

.. code-block:: c

   #include <unistd.h>

   ssize_t write(int fd, const void *buf, size_t count);

* Return value: number of bytes written (-1 on error, :doc:`as always
  </trainings/material/soup/linux/sysprog/syscalls-and-errors/errorhandling/index>`)
* Can write less than ``count`` (usually with network I/O)
* ``SIGPIPE`` (process termination) when ...

  * Writing to a network connection that has been closed by peer
  * Writing to a pipe where receiver end has closed/exited (hence
    ``SIGPIPE``)

