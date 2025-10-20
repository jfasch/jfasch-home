.. ot-topic:: sysprog.fileio.open

.. include:: <mmlalias.txt>


``open()``: Opening Files
=========================

.. topic:: See also

   * :doc:`../file-input/index`
   * :doc:`../file-output/index`
   * :doc:`../create/index`

.. topic:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 close
     <https://man7.org/linux/man-pages/man2/close.2.html>`__

.. code-block:: c

   #include <fcntl.h>

   int open(const char *pathname, int flags);
   int open(const char *pathname, int flags, mode_t mode);

.. code-block:: c

   #include <unistd.h>
   
   int close(int fd);

Swiss Army Knife
----------------

Swiss army knife: multiple actions, governed by bitwise-or'ed flags:

* Create/Open/Truncate/...
* ``flags``: access intention - open for reading, writing, appending,
  ...
* Hundreds of others
* |longrightarrow| `man -s 2 open
  <https://man7.org/linux/man-pages/man2/open.2.html>`__ is a very
  hard read

``open()`` Flags
----------------

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/basics/permissions/basics`

**Intended Access**

* ``O_RDONLY``: Can only ``read()``; error on ``write()``
* ``O_WRONLY``: Can only ``write()``; error on ``read()``
* ``O_RDWR``: ...

**Creating a File**

* ``O_CREAT``: create if not exists, else simply open

  * If file is created, ``mode`` is used - file *permissions*

* ``O_CREAT|O_EXCL``: *exclusive creation*

  * *error* if file exists
  * |longrightarrow| to prevent race conditions when two parties try
    to create a file at the same time
  * security measure

**Miscellaneous**

* ``O_APPEND``: write access appends at the end
* ``O_TRUNC``: truncate file to zero length if already exists
* ``O_CLOEXEC``: ``exec()`` closes the file descriptor
  (|longrightarrow| later)

More About Each Of ``flags`` And ``mode``
-----------------------------------------

.. topic:: See also

   * :doc:`../file-input/index`
   * :doc:`../file-output/index`
   * :doc:`../create/index`
