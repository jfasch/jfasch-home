.. include:: <mmlalias.txt>


Blocking I/O (On A File): What is That?
=======================================

.. contents::
   :local:

.. sidebar:: Documentation

   * `man -s 2 open <https://man7.org/linux/man-pages/man2/open.2.html>`__
   * `man -s 2 read <https://man7.org/linux/man-pages/man2/read.2.html>`__
   * `man -s 2 write <https://man7.org/linux/man-pages/man2/write.2.html>`__
   * `man -s 2 close <https://man7.org/linux/man-pages/man2/close.2.html>`__

.. sidebar:: See Also

   * :doc:`/trainings/material/soup/linux/sysprog/basics/index`

Reading a File
--------------

* Reading something from disk is not a trivial task

  * Rotating (hence the name *disk*, alas)
  * Head positioning
  * *Interrupt* when done
  * Direct Memory Access (DMA), done by controller chip
  * *Interrupt* when done
  * |longrightarrow| requires a lot of coordination

* |longrightarrow| **abstractions** are in order
* |longrightarrow| a job for an *Operating System*

Abstractions
------------

* *What* do we read?

  * Bytes from *files*
  * Organized in *directories*
  * |longrightarrow| *File system*

* *How* do we read that?

  * Don't want to position heads, and rotate moving parts
  * Worse: don't want to hardwire my code to rotating disks. SSD?
    Network storage? RAM?
  * Don't want to handle interrupts
  * Don't even know what DMA is
  * |longrightarrow| Only want to *read* that *file*

Simplicity
----------

* System call: ``open()``
* System call: ``read()``
* System call: ``write()``
* System call: ``close()``

.. literalinclude:: read-file.c
   :language: c
   :caption: :download:`read-file.c`

Build, Run, Look
----------------

.. code-block:: console

   $ gcc -o read-file read-file.c 
   $ ls -l read-file
   -rwxrwxr-x. 1 jfasch jfasch 24608 Mar  5 17:46 read-file
   $ ./read-file
   root:x:0:0:root:/root:/bin/bash
   bin:x:1:1:bin:/bin:/sbin/nologin
   daemon:x:2:2:daemon:/sbin:/sbin/nologin
   ...

Watch: Run Under ``strace`` Supervision
---------------------------------------

See what it does ...

.. code-block:: console

   $ strace ./read-file
   openat(AT_FDCWD, "/etc/passwd", O_RDONLY) = 3
   read(3, "root:x:0:0:root:/root:/bin/bash\n"..., 1024) = 1024
   write(1, "root:x:0:0:root:/root:/bin/bash\n"..., 1024root:x:0:0:root:/root:/bin/bash
   read(3, "nager:/:/sbin/nologin\ncolord:x:9"..., 1024) = 698
   write(1, "nager:/:/sbin/nologin\ncolord:x:9"..., 698nager:/:/sbin/nologin
   read(3, "", 1024)                       = 0
   close(3)                                = 0

