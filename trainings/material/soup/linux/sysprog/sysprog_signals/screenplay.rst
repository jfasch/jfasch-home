.. meta::
   :description: This live-hacking screenplay is a guide for myself to
                 repeatably, didactically, demonstrate how UNIX
                 signals work - yes there are Linux specific details
   :keywords: linux, systemnah, schulung, training, programming,
              signals

Screenplay: Sysprog: Signals
============================

.. sidebar:: Inhalt

   .. contents::
      :local:

   **Code**: :doc:`code/index`

Barebones Naive Program
-----------------------

* ``pause()``: sit and wait for something to happen. A signal for
  example.
* Output PID for convenience (``getpid()``)
* Discuss "Default actions", see `man 7 signal
  <http://man7.org/linux/man-pages/man7/signal.7.html>`__.

  * ``kill TERM <pid>`` -> terminated
  * ``kill SEGV <pid>`` -> core (discuss)
  * Show exit status `!= 0`

* Discuss core (post mortem debugging)

  .. code-block:: console

     $ cat /proc/sys/kernel/core_pattern 
     |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %h

  Hmm. Don't want them to send that core home.

  .. code-block:: console

     # echo core > /proc/sys/kernel/core_pattern

  Better yet, to prevent conflicts (many processes dumping to ``core``
  simultaneously)

  .. code-block:: console

     # echo core.%p > /proc/sys/kernel/core_pattern

.. literalinclude:: code/010-signal-basics.cc
   :caption: :download:`code/010-signal-basics.cc`
   :language: c++

Signal Handler
--------------

* ``termination_handler()``: *signal handler*
* Start with printf(), promising the worst
* Installed as handler for ``SIGTERM``

  * Using ``signal()``, knowing that it is bad.
  * Still only ``pause()``, in linear flow, no loop
  * Terminates -> why? Show fallthrough, cout after pause
  * Discuss ``errno``, ``EINTR``, and error handling in general
  * Introduce loop around pause
  * Install as ``SIGINT``. No second terminal necessary to ``kill
    <pid>``, but rather ``Control-C`` in controlling terminal.

* Termination

  * ``bool quit`` -> NO! ``sig_atomic_t``
  * ``while (!quit) ... pause ...``

* Fix crap

  * **cout in signal handler context**. Jump through hoops for simple
    output on ``STDOUT_FILENO``. See `man 7 signal-safety
    <http://man7.org/linux/man-pages/man7/signal-safety.7.html>`__.
  * ``sig_atomic_t quit``
  * **Error handling**. Fail when trying to comprehend bloody
    ``signal()`` return value. Use ``sigaction()`` from here on.
  * ``sigaction()``: why is complicated better than simple?

.. literalinclude:: code/020-signal-handler.cc
   :caption: :download:`code/020-signal-handler.cc`
   :language: c++

Alarm
-----

* Add ``alarm()`` periodic handler (i.e. re-arm in signal handler)
* See how ``pause()`` is still interrupted

.. literalinclude:: code/030-signal-termination-alarm.cc
   :caption: :download:`code/030-signal-termination-alarm.cc`
   :language: c++

Alarm (Louder)
--------------

* Dangerous ``man signal-safety``
* See below for threading issues

Synchronous Delivery
--------------------

.. literalinclude:: code/035-synchronous-delivery.c
   :caption: :download:`code/035-synchronous-delivery.c`
   :language: c

Multithreading
--------------

Multithreading and signals: *There Be Dragons*. Hmm. How.

Innocent Multithreaded Program
..............................

Consumes from n pipes, in n threads, and writes to stdout.

.. literalinclude:: code/040-mt-pipe.cc
   :caption: :download:`code/040-mt-pipe.cc`
   :language: c++


Add ``SIGALRM``
...............

Add alarm handling to that. **Be puzzled why system calls are not
interrupted in pipe threads as one would expect.**

.. literalinclude:: code/050-mt-pipe-alarm.cc
   :caption: :download:`code/050-mt-pipe-alarm.cc`
   :language: c++

Write a standalone single-threaded program and see system call
interrupted.

.. literalinclude:: code/051-st-pipe-alarm.cc
   :caption: :download:`code/051-st-pipe-alarm.cc`
   :language: c++

**Discuss**

* ``man open`` says ``EINTR`` on pipe
* ``man alarm`` says delivered to calling *process*
* Signal delivery changes significantly when threads are thrown
  in. Much of the semantics seems to be undefined. See for example
  `man sigprocmask
  <http://man7.org/linux/man-pages/man2/sigprocmask.2.html>`__, where
  they say,

     "sigprocmask() is used to fetch and/or change the signal mask of
     the calling **thread**."

  but then,

     "The use of sigprocmask() is **unspecified in a multithreaded
     process**; see pthread_sigmask(3)."

.. danger::

   *So WTF?* Stay away!

