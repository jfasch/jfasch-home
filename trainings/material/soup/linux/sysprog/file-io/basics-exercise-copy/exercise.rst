Exercise: Copy A File
=====================

.. contents:: 
   :local:

Requirement
-----------

.. sidebar::

   **Topics**

   * The Whole Truth About ``open()``

     * :doc:`/trainings/material/soup/linux/sysprog/file-io/basics`
     * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_RDONLY`
     * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_WRONLY`
     * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_CREAT`
     * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_EXCL`

   * :doc:`/trainings/material/soup/linux/sysprog/process/exit-args-env/index`
   * :doc:`/trainings/material/soup/linux/sysprog/syscalls-and-errors/errorhandling/index`
   * :doc:`/trainings/material/soup/linux/basics/permissions/basics`

   **Manual Pages**

   * File I/O

     * `man -s 2 open
       <https://man7.org/linux/man-pages/man2/open.2.html>`__
     * `man -s 2 read
       <https://man7.org/linux/man-pages/man2/read.2.html>`__
     * `man -s 2 write
       <https://man7.org/linux/man-pages/man2/write.2.html>`__
     * `man -s 2 close
       <https://man7.org/linux/man-pages/man2/close.2.html>`__

   * Miscellaneous

     * `man -s 3 errno
       <https://man7.org/linux/man-pages/man3/errno.3.html>`__
     * `man -s 3 strerror
       <https://man7.org/linux/man-pages/man3/strerror.3.html>`__

Write a program ``cp-for-the-poor`` which exhibits the following
behavior:

* It interprets its two arguments as filenames, and copies the first
  to the second
* The first filename must be an existing file
* The second filename is the target of the copy
* No existing file must be overwritten
* *The program operates at the system call layer*. Use
  ``open()``/``read()``/``write()``/``close()``, and *not* anything
  from ``<stdio.h>``.

.. note::

   * Check for system call errors; see
     :doc:`/trainings/material/soup/linux/sysprog/syscalls-and-errors/errorhandling/index`
     for how to.
   * Make sure the program interprets its commandline correctly; see
     :doc:`/trainings/material/soup/linux/sysprog/process/exit-args-env/index`
     for how to.
   * Make sure the program returns exit statuses as specified below;
     see
     :doc:`/trainings/material/soup/linux/sysprog/process/exit-args-env/index`
     for how to.

Sunny Case: Source File Exists, Destination Does Not Exist
..........................................................

.. code-block:: console

   $ ./cp-for-the-poor /etc/passwd /tmp/passwd-copy
   $ echo $?
   0

(:download:`Test script (download) <requirement-sunny.sh>`)

Error: Wrong Number Of Arguments Specified
..........................................

.. code-block:: console

   $ ./cp-for-the-poor
   ./cp-for-the-poor: SRCFILE DSTFILE
   $ echo $?
   1

(:download:`Test script (download) <requirement-wrong-number-args.sh>`)

Error: Source File Does Not Exist
.................................

.. code-block:: console

   $ ./cp-for-the-poor /etc/passwd-not-there /tmp/some-file-that-does-not-exist
   /etc/passwd-not-there: No such file or directory
   $ echo $?
   2

(:download:`Test script (download) <requirement-source-not-exist.sh>`)

Error: Destination File Exists
..............................

Provided that ``/tmp/passwd-copy`` already exists [#create-file]_:

.. code-block:: console

   $ ./cp-for-the-poor /etc/passwd /tmp/passwd-copy
   /tmp/passwd-copy: File exists
   $ echo $?
   3

(:download:`Test script (download) <requirement-dest-exists.sh>`)

Error: Destination Directory Not Writable
.........................................

Provided that ``/etc`` is not writable (because you are not ``root``,
for example),

.. code-block:: console

   $ ./cp-for-the-poor /etc/passwd /etc/passwd-copy
   /etc/passwd-copy: Permission denied
   $ echo $?
   4

(:download:`Test script (download) <requirement-dest-dir-not-writeable.sh>`)

Submission
----------

* Create a directory ``exercise-1`` which contains all the source (C
  code, and CMake build instructions)
* From the parent directory of ``exercise-1``, package that directory

  .. code-block:: 

     $ tar -J -c -f submission.tar.xz exercise-1/

* Submit ``submission.tar.xz``


.. rubric:: Footnotes
.. [#create-file] If not, and you need one for testing purposes, you
                  create it like so:

		  .. code-block:: console

		     $ touch /tmp/passwd-copy

		  (Or by running the sunny case, of course)
