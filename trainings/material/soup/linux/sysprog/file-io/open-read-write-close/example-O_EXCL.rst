.. include:: <mmlalias.txt>


``O_EXCL``: Creating A File, But Failing If It Already Exists
=============================================================

.. contents::
   :local:

Is "Create or Open" Always Wanted?
----------------------------------

.. sidebar:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 write
     <https://man7.org/linux/man-pages/man2/write.2.html>`__
   * `man -s 3 perror
     <https://man7.org/linux/man-pages/man3/perror.3.html>`__

In :doc:`example-O_CREAT`, we created a file if it didn't exist - or
just opened it if it existed. This is not always the desired behavior:
sometimes a program might want to be sure that a file that it creates
is not there, or fail - preventing an accidental overwrite of existing
data. This is exactly what the ``O_EXCL`` flag (in combination with
``O_CREAT``) is there for.

The following program 

* Creates a *new file* by using ``O_CREAT | O_EXCL``, in combination
  with ``O_WRONLY``
* writes a number of bytes to it

.. literalinclude:: code/example-O_EXCL.c
   :caption: :download:`code/example-O_EXCL.c`
   :language: c

.. code-block:: console
   :caption: Build it

   $ gcc -o example-O_EXCL example-O_EXCL.c

Sunny Case: File Does Not Exist
-------------------------------

.. code-block:: console

   $ ./example-O_EXCL /tmp/another-file-that-does-not-exist
   $ ls -l /tmp/another-file-that-does-not-exist
   -rw-rw-r--. 1 jfasch jfasch 7 May 15 22:16 /tmp/another-file-that-does-not-exist
   $ cat /tmp/another-file-that-does-not-exist
   Howdy

Error: File Exists
------------------

.. code-block:: console

   $ ./example-O_EXCL /tmp/another-file-that-does-not-exist
   open: File exists
