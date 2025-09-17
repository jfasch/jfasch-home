.. include:: <mmlalias.txt>


Blocking I/O: On A Timer? WTF?
==============================

.. contents::
   :local:

.. sidebar:: Documentation

   * `man -s 2 timerfd_create <https://man7.org/linux/man-pages/man2/timerfd_create.2.html>`__
   * `man -s 2 timerfd_settime <https://man7.org/linux/man-pages/man2/timerfd_create.2.html>`__
   * `man -s 2 read <https://man7.org/linux/man-pages/man2/read.2.html>`__
   * `man -s 2 close <https://man7.org/linux/man-pages/man2/close.2.html>`__

.. sidebar:: See Also

   * :doc:`/trainings/material/soup/linux/sysprog/syscalls-and-errors/index`

Setup A Timer
-------------

* Configure timer interrupt
* Write to timer chip's registers
* Hm? How many timer chips do I have? 

  * Can I run out of timers chips?
  * Do I need to write my own "virtualized timer" library where I can
    multiplex many abstract timers onto a number of physical/hardware
    timers?
  * Architectural differences?

* |longrightarrow| a job for an *Operating System*

Abstractions
------------

* *What* do we read?

  * Number of expirations (a ``uint64_t``) |longrightarrow| timer
    intervals can be very short, so we could miss one expiration

* *How* do we read that?

  * I don't know, I just want `read()`` to work on timers.

Simplicity
----------

* System call: ``timerfd_create()``
* System call: ``timerfd_settime()``
* System call: ``read()``
* System call: ``close()``

.. literalinclude:: read-timer.c
   :language: c
   :caption: :download:`read-timer.c`

Build, Run, Look
----------------

.. code-block:: console

   $ gcc -o read-timer read-timer.c 
   $ ./read-timer 
   expired
   expired
   ...
