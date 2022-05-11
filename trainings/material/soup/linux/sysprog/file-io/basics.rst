.. ot-topic:: linux.sysprog.fileio.basics
   :dependencies: linux.sysprog.basics.groupnode,
		  linux.basics.permissions.basics

.. include:: <mmlalias.txt>


File I/O: Basics
================

.. contents::
   :local:

File Descriptors
----------------

* Universal *handle* for everything that's got to do with I/O
* Type: ``int``
* *File* is only one shape of I/O
* Alternative shapes

  * Pipes
  * Sockets
  * FIFOs
  * Terminals
  * Device Special Files |longrightarrow| entry point into arbitrary
    kernel drivers

.. sidebar:: Documentation

   * `man -s 2 signalfd
     <https://man7.org/linux/man-pages/man2/signalfd.2.html>`__
   * `man -s 2 timerfd_create
     <https://man7.org/linux/man-pages/man2/timerfd_create.2.html>`__
   * `man -s 2 eventfd
     <https://man7.org/linux/man-pages/man2/eventfd.2.html>`__

* Linux specific ingenuities: ``signalfd()``, ``timerfd_create()``,
  ``eventfd()``

Standard Filedescriptors
------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Number
     * POSIX Macro
     * ``stdio.h`` equivalent
   * * 0
     * ``STDIN_FILENO``
     * ``stdin``
   * * 1
     * ``STDOUT_FILENO``
     * ``stdout``
   * * 2
     * ``STDERR_FILENO``
     * ``stderr``

* Interactive shell: all three associated with terminal
* Standard input and output used for I/O redirection and pipes
* Standard error receives errors, warnings, and debug output

.. caution::

   Windows-Programmers: no errors, warnings, and debug output to
   *standard output*!!

File I/O: System Calls
----------------------

.. list-table::
   :align: left
   :widths: auto

   * * ``open()``
     * Opens a file (or creates it |longrightarrow| tons of flags)
   * * ``read()``
     * Reads bytes
   * * ``write()``
     * Writes bytes
   * * ``close()``
     * Closes the file

``open()`` creates file descriptors that are associated with path
names (files, named pipes, device special files, ...). Other
"factory" functions ...

Network programming:

* ``connect()``
* ``accept()``

Miscellaneous:

* ``pipe()``
* ``timerfd_create()``
* ...


``open()``
----------

.. sidebar:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 close
     <https://man7.org/linux/man-pages/man2/close.2.html>`__

.. code-block:: c

       #include <fcntl.h>

       int open(const char *pathname, int flags);
       int open(const char *pathname, int flags, mode_t mode);

Swiss army knife among system calls. Multiple actions, governed by
bitwise-or'ed flags:

* Create/Open/Truncate/...
* Access mode (Read, Write)
* Hundreds of others

``open()`` Flags
----------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/basics/permissions/basics`

**Access Mode**

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
  </trainings/material/soup/linux/sysprog/basics/errorhandling>`)
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
  </trainings/material/soup/linux/sysprog/basics/errorhandling>`)
* Can write less than ``count`` (usually with network I/O)
* ``SIGPIPE`` (process termination) when ...

  * Writing on a network connection that has been closed by peer
  * Writing on a pip where receiver end has exited (hence ``SIGPIPE``)

File Offset: ``lseek()``
------------------------

.. sidebar:: Documentation

   * `man -s 2 lseek
     <https://man7.org/linux/man-pages/man2/lseek.2.html>`__

.. code-block:: c

   #include <unistd.h>

   off_t lseek(int fd, off_t offset, int whence);

``read()`` and ``write()`` manipulate the *offset* (position where the
next operation begins).

**Explicit positioning**. ``whence`` is one of

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Macro
     * Description
   * * ``SEEK_SET``
     * The file offset is set to offset bytes.
   * * ``SEEK_CUR``
     * The file offset is set to its current location plus offset
       bytes.
   * * ``SEEK_END``
     * The file offset is set to the size of the file plus offset
       bytes.

**Obscure feature**: *files with holes*

* positioning *beyond file size*
* write to that position
* |longrightarrow| *holes*, occupying no space
* ``read()`` across a hole give 0-bytes

The Rest: ``ioctl()``
---------------------

.. sidebar:: Documentation

   * `man -s 2 ioctl
     <https://man7.org/linux/man-pages/man2/ioctl.2.html>`__

.. code-block:: c

   #include <sys/ioctl.h>

   int ioctl(int fd, unsigned long request, ...);

* *Tunnel* for functionality not declarable as I/O
* Most commonly used to communicate with drivers (e.g.: "Open that CD
  drive!")
* Mostly deprecated nowadays (though easily implemented in a driver)
* Better (because more obvious): use ``/proc`` and ``/sys``
