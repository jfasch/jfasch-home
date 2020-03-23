Signals (Slides)
================

.. sidebar:: Slideshow

   :download:`sysprog-signals-slides.s5.html`

.. overview
.. --------------------------------------------------------------------

Signals are *poor* notifications to a process

* Number between 1 and 31
* Sent to a process *from another process*
* Sent to a process *by the kernel*

Example Signals
---------------

  .. csv-table::

     ``SIGINT``, ``Ctrl-C``, termination
     ``SIGTSTP``, ``Ctrl-Z``, suspend
     ``SIGTERM``, ``kill <pid>``, termination
     ``SIGALRM``, Timer expiration, termination

* Many more
* Beware of ``SIGALRM``. There better ways of timer management,
  nowadays.

Terminology
-----------

* *Generate*. A signal is sent.
* *Deliver*. The signal is received by a process (*delivered by the
  kernel*). The *signal handler* is run.
* *Pending*. A signal is pending on a process until it is delivered.
* *Blocked*. A process refuses to get a signal delivered (he "blocks"
  the signal).
* *Signal Mask*. The set of signals that are blocked by a process.

`man -s 7 signal
<http://man7.org/linux/man-pages/man7/signal.7.html>`__.

Default Actions
---------------

All signals have a predefined *default action*
  
* The signal is ignored. E.g. ``SIGCHLD``.
* Process termination. *Abnormal Process Termination*, as opposed to
  ``exit()``. With or without *core dump*.
* The process is stopped or continued.

Important Signals
-----------------

.. csv-table::
   :header: Signal, Default Action, Reason

   ``SIGABRT``, Terminate(core), E.g. ``assert()``
   ``SIGSEGV``, Terminate(core), Access violation
   ``SIGBUS``, Terminate(core), Access violation
   ``SIGILL``, Terminate(core), Bogus function pointer
   ``SIGFPE``, Terminate(core), Floating point
   ``SIGINT``, Terminate, ``Ctrl-C``
   ``SIGTERM``, Terminate, Explicit ``kill``
   ``SIGPIPE``, Terminate, Write to pipe/socket
   ``SIGCHLD``, Ignore, Child death

Sending, Commandline
--------------------

.. code-block:: console

   $ kill -l
   ... signals here ...
   $ kill 1234   # to PID
   $ kill -SEGV 1234   # kill as if segfaulted
   $ killall firefox

`man -s 1 kill <http://man7.org/linux/man-pages/man1/kill.1.html>`__


Sending Signals, Programmatically
---------------------------------

.. code-block:: c

   int kill(pid_t pid, int sig);

* ``pid`` specifies where the signal goes to
* ``pid > 0``: process
* ``pid == -1``: *Broadcast*; every process the sender has permissions
  to. Except ``init`` and the sender itself.
* ``pid == 0`` or ``pid < -1``: process group

`man -s 2 kill <http://man7.org/linux/man-pages/man2/kill.2.html>`__

Warning!
--------

* Signals are no toy
* Signals are no communication medium
* **Signal handlers are executing in a context that has nothing to do
  with normal program context -> asynchronous**
* One does not install a signal handler for e.g. ``SIGSEGV``
* One does not ignore ``SIGSEGV``
* One does not block ``SIGSEGV``
* ...

.. signal mask: blocking signals
.. --------------------------------------------------------------------

Blocking Signals: *Signal Mask*
-------------------------------

**Signal Mask**
  
* Process attribute (more exactly: *thread*)
* Specifies which signals are blocked
* Signals that have been sent to a process but which are blocked
  remain *pending*
* *Pending signals* are *delivered* as soon as they are unblocked
* Signals of the same type don't pile up at the receiver

  * two ``SIGINT`` are only *delivered* once

*Signal Mask* Manipulation
--------------------------

.. code-block:: c

   int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

* Blocks all signal from ``set``
* Returns previously blocked signals in ``oldset``
* **Behavior unspecified** in multithreaded programs (use
  ``pthread_sigmask()``)

`man -s 2 sigprocmask
<http://man7.org/linux/man-pages/man2/sigprocmask.2.html>`__

Pending Signals
---------------

.. code-block:: c

   int sigpending(sigset_t *set);

Boring ...

`man -s 2 sigpending
<http://man7.org/linux/man-pages/man2/sigpending.2.html>`__


Signal Set: ``sigset_t``
------------------------

.. code-block:: c

   int sigemptyset(sigset_t *set);
   int sigfillset(sigset_t *set);
   int sigaddset(sigset_t *set, int signum);
   int sigdelset(sigset_t *set, int signum);
   int sigismember(const sigset_t *set, int signum);

* Signal Set: set of signals (obviously). Signals are numbered 1
  through 31
* ``sigset_t`` is an ``int``, actually. A *bitmask*.

`man -s 3 sigsetops <https://linux.die.net/man/3/sigsetops>`__

.. signal handlers
.. --------------------------------------------------------------------

Signal Handlers
---------------

* **Default action** is sufficient in most cases

  * ``SIGSEGV`` crashes and dumps core
  * ``SIGINT`` (Ctrl-C) terminates

* **Customizing signal reception**: install *signal handler*

  * Pointer to C function

.. code-block:: c

   void handler(int sig);

Installing a Signal Handler (1)
-------------------------------

.. code-block:: c

   struct sigaction {
       void     (*sa_handler)(int);
       sigset_t   sa_mask;
       int        sa_flags;
   };
   int sigaction(int signum,
       const struct sigaction *act,
       struct sigaction *oldact);

`man -s 2 sigaction
<http://man7.org/linux/man-pages/man2/sigaction.2.html>`__

Installing a Signal Handler (2)
-------------------------------

* **Special sa_handler values**

  * ``SIG_IGN``: ignore the signal
  * ``SIG_DFL``: restore default action

* **Historical baggage**

  .. code-block:: c

     sighandler_t signal(int signum, sighandler_t handler);

  * Unclear semantics
  * Not portable

Effects of Signal Delivery
--------------------------

E.g. terminate a program based upon the value of a flag (by dropping
out of a loop) that is set in a signal handler. Use ...

.. code-block:: c

   volatile sig_atomic_t flag;

* Blocking system calls (e.g. ``read()`` or ``write()``) return an
  error when they have been interrupted by a signal
* ``errno`` is ``EINTR``

Last Warning!
-------------

**Signals are delivered asynchronously**

* Much like hardware interrupts (only in software)
* Literally *nothing* is legal

  * Only *async-signal-safe* functions can be used
  * Practically only system calls

`man -s 7 signal-safety
<http://man7.org/linux/man-pages/man7/signal-safety.7.html>`__

WTF Async Signal Safe?
----------------------

**The following functions (among many others) are not
async-signal-safe**

* ``printf()``, ``sprintf()`` (everything from ``stdio.h`` and
  ``iostream``, respectively)
* ``malloc()``, ``free()`` etc.
* ``exit()`` (``_exit()`` is safe because a system call)
* Everything from ``pthread.h``

.. exercises
.. --------------------------------------------------------------------

Exercise: Signals
-----------------

**Write a program that ...**
  
* ... reads from ``STDIN_FILENO`` in a loop, and outputs what was read
  to ``STDOUT_FILENO``. Imagine that this is a replacement for an
  immensely important work which can block - the program blocks on
  ``STDIN_FILENO``.
* On program termination, the program has to do important cleanup
  work - it has to catch at least ``SIGINT`` and ``SIGTERM``.
* Our cleanup work is to safely - *not* in the signal handler - write
  "Goodbye!" to standard output.

