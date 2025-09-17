.. include:: <mmlalias.txt>


``O_RDONLY``: Reading a File
============================

.. contents::
   :local:

Me and ``/etc/passwd``
----------------------

.. sidebar:: Topics
   
   * :doc:`overview`

Who am I?

.. code-block:: console

   $ id
   $ id
   uid=1000(jfasch) gid=1000(jfasch) groups=1000(jfasch),10(wheel),18(dialout)

A-Ha: being user ``jfasch`` who belongs to groups ``jfasch``,
``wheel``, and ``dialout``.

And ``/etc/passwd``?

.. code-block:: console

   $ ls -l /etc/passwd
   -rw-r--r--. 1 root root 2746 Mar  3 14:12 /etc/passwd

A-ha: Read-writable by user ``root``, readable by members of group
``root``, and by all others.

So, I (being among the others for the purpose of ``/etc/passwd``
access), I'll be able to read that file. Lets do that: read the entire
file, and write it to *standard output*.

Code: Reading A File
--------------------

.. sidebar:: Topics

   * :doc:`overview`
   * :doc:`../../process/exit-args-env/index`
   * :doc:`../../syscalls-and-errors/errorhandling/index`

.. sidebar:: Documentation

   * `man -s 2 open
     <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 read
     <https://man7.org/linux/man-pages/man2/read.2.html>`__
   * `man -s 2 write
     <https://man7.org/linux/man-pages/man2/write.2.html>`__
   * `man -s 2 close
     <https://man7.org/linux/man-pages/man2/close.2.html>`__
   * `man -s 3 perror
     <https://man7.org/linux/man-pages/man3/perror.3.html>`__

The following program 

* opens the file (doing basic :doc:`error handling
  <../../syscalls-and-errors/errorhandling/index>` which is always a good idea)

  * It is at the time of ``open()`` -ing a file where you *declare*
    that you intend to read from it! This is the time where the system
    checks your intentions against the file's permissions.

* reads its contents in a loop, again handling errors
* checks the end-of-file (EOF) condition - a read of 0 bytes says that
  there will come no more
* writes the bytes that it reads to *standard output*, using the
  predefined ``STDOUT_FILENO`` macro (which expands to file decriptor
  ``1``)
* returns the exit status ``0`` if all is well, and arbitrarily chosen
  numbers for the different error situations that it may encounter

.. literalinclude:: code/example-O_RDONLY.c
   :caption: :download:`code/example-O_RDONLY.c`
   :language: c

.. code-block:: console
   :caption: Build it

   $ gcc -o example-O_RDONLY example-O_RDONLY.c

Sunny Case: Reading ``/etc/passwd``
-----------------------------------

As we saw, ``/etc/passwd`` is readable for all others, so this should
be ok:

.. code-block:: console

   $ ./example-O_RDONLY /etc/passwd
   root:x:0:0:root:/root:/bin/bash
   bin:x:1:1:bin:/bin:/sbin/nologin
   ...

.. note::

   The program read the file in chunks of 128 bytes in a loop. What we
   see is that ``read()`` continues where the previous ``read()`` left
   off.

   See

   * :doc:`../duplicate` for an explanation of what's going on in the
     system to make this happen
   * :doc:`../misc` for alternative ways of reading a file that do not
     exhibit this behaviour (which is intended in most cases)

Error: File Not Readable
------------------------

.. sidebar:: Documentation

   * `man -s 5 shadow
     <https://man7.org/linux/man-pages/man5/shadow.5.html>`__

A file that is certainly not readable for anybody on any Linux system
is ``/etc/shadow``:

.. code-block:: console

   $ ls -l /etc/shadow
   ----------. 1 root root 1352 Mar  3 14:12 /etc/shadow

Proper error handling around ``open()`` now will detect exactly that ...

.. code-block:: console

   $ ./example-O_RDONLY /etc/shadow
   open: Permission denied

Error: File Not Even There
--------------------------

Likewise, ``open()`` obviously fails if the file does not exist:

.. code-block:: console

   $ ./example-O_RDONLY something-thats-not-there
   open: No such file or directory

