.. ot-topic:: linux.basics.intro.overview.blocking_io_timer
   :dependencies: linux.basics.intro.overview.overview,
		  linux.basics.intro.overview.blocking_io_network

.. include:: <mmlalias.txt>


Blocking I/O: On A Timer? WTF?
==============================

.. contents::
   :local:

Setup A Timer
-------------

* Configure timer interrupt
* Write to timer chip's registers
* Hm? How many timer chips do I have? 

  * Can I run out of timers?
  * Do I need to write my own "virtualized timer" library where I can
    multiplex many abstract timers onto a number of physical/hardware
    timers?

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
