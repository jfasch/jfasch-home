Signals: Slides
===============

.. overview
.. --------------------------------------------------------------------

Overview
--------

Signals are *poor* notifications to a process

* Number between 1 and 31
* Sent from a process to another process ($\to$ permissions)
* Hardware exception. E.g. floatingpoint, memory access ...
* Special terminal events

  .. csv-table::

     ``Ctrl-C``, ``SIGINT``, *interrupt*
     ``Ctrl-Z``, ``SIGTSTP``, *suspend*

* Software events

  .. csv-table::

     timer runs off, ``SIGALRM``


Terminology
-----------

* *Generate*. A signal is sent.
* *Deliver*. The signal is received by a process
  (*delivered by the kernel*). The *signal handler* (see later jjjjj) is run.
* *Pending*. A signal is pending on a process until it is delivered.
* *Blocked*. A process refuses to get a signal delivered (he "blocks"
  the signal).
* *Signal Mask*. The set of signals that are blocked by a process.

Default Actions
---------------

All signals have a predefined *default action*
  
* The signal is ignored. E.g. ``SIGCHLD``.
* Process termination. *Abnormal Process Termination*, as opposed to
  ``exit()``. With or without *core dump*.
* The process is stopped or continued.

Important Signals
-----------------

.. code-block:: shell

   $ man -s 7 signal
   $ kill -l
   ... signals here ...

.. sidebar:: Link

   `man -s 7 signal
   <http://man7.org/linux/man-pages/man7/signal.7.html>`__.

.. csv-table::
   :header: Signal, Default Action, Reason

   ``SIGABRT``, Terminate (core dump), E.g. ``assert()``
   ``SIGSEGV``, Terminate (core dump), Access violation
   ``SIGBUS``, Terminate (core dump), Access violation
   ``SIGILL``, Terminate (core dump), Bogus function pointer
   ``SIGFPE``, Terminate (core dump), Floating point
   ``SIGINT``, Terminate, ``Ctrl-C``
   ``SIGTERM``, Terminate, Explicit ``kill``
   ``SIGPIPE``, Terminate, Write to pipe/socket
   ``SIGCHLD``, Ignore, Child death

Sending Signals
---------------

.. code-block:: c

   int kill(pid_t pid, int sig);

.. sidebar:: Link

   `man -s 2 kill
   <http://man7.org/linux/man-pages/man2/kill.2.html>`__
  
``pid`` specifies where the signal goes to

* ``pid > 0``: process
* ``pid == -1``: *Broadcast*; every process the sender has permissions
  to. Except ``init`` and the sender itself.
* ``pid == 0`` or ``pid < -1``: process group

Warning!
--------

.. danger::

   * Signals are no toy
   * Signals are no communication medium
   * **Signal handlers are executing in a context that has nothing to
     do with normal program context -> asynchronous**
   * One does not install a signal handler for
     e.g. ``SIGSEGV``
   * One does not ignore ``SIGSEGV``
   * One does not block ``SIGSEGV``
   * ...



.. signal mask: blocking signals
.. --------------------------------------------------------------------

Signal Set: ``sigset_t``
------------------------

* Signal Set: set of signals (obviously). Signals are numbered 1 through 31
* ``sigset_t`` is an ``int``, actually

.. sidebar:: Link

   `man -s 3 sigsetops <https://linux.die.net/man/3/sigsetops>`__

.. code-block:: c

   int sigemptyset(sigset_t *set);
   int sigfillset(sigset_t *set);
   int sigaddset(sigset_t *set, int signum);
   int sigdelset(sigset_t *set, int signum);
   int sigismember(const sigset_t *set, int signum);

The *Signal Mask* (1)
---------------------

**Signal Mask:**
  
* Process attribute (more exactly: *thread*)
* Specifies which signals are blocked
* Signal that have been sent to a process but which he blocks
  remain *pending*

**Pending signals:**

* Get *delivered* as soon as they are unblocked
* Signals of the same type don't pile up at the receiver

  * two ``SIGINT`` are only *delivered* once

The *Signal Mask* (2)
---------------------

**Setting/modifying the signal mask:**
  
.. code-block:: c

   int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

.. sidebar:: Links

   * `man -s 2 sigprocmask
     <http://man7.org/linux/man-pages/man2/sigprocmask.2.html>`__
   * `man -s 2 sigpending
     <http://man7.org/linux/man-pages/man2/sigpending.2.html>`__

**Pending Signals:**
  
.. code-block:: c

   int sigpending(sigset_t *set);



.. signal handlers
.. --------------------------------------------------------------------

Signal Handlers
---------------

To change the *default action* of a signal one installs a *signal
handler* - Pointer to a function with the following signature:

.. code-block:: c

   void handler(int sig);

Installing a Signal Handler
---------------------------

.. code-block:: c

   struct sigaction {
       void     (*sa_handler)(int);
       sigset_t   sa_mask;
       int        sa_flags;
   };
   int sigaction(int signum,
       const struct sigaction *act,
       struct sigaction *oldact);

.. sidebar:: Link

   `man -s 2 sigaction
   <http://man7.org/linux/man-pages/man2/sigaction.2.html>`__

**Special sa_handler values:**

* ``SIG_IGN``: ignore the signal
* ``SIG_DFL``: restore default action

Effects of Signal Delivery
--------------------------

E.g. terminate a program based upon the value of a flag (by dropping
out of a loop) that is set in a signal handler. Use ...

.. code-block:: c

   volatile sig_atomic_t flag;

* Blocking system calls (e.g. ``read()`` or write()``) return an error
  when they have been interrupted by a signal
* ``errno`` is ``EINTR``

Last Warning!
-------------

**Signals are delivered asynchronously**

* In a signal handler, only *async-signal-safe*
  functions can be used
* Practically only system calls

.. sidebar:: Link

   `man -s 7 signal-safety
   <http://man7.org/linux/man-pages/man7/signal-safety.7.html>`__

The following functions (among many others) are *not*
async-signal-safe:

* ``printf()``, ``sprintf()`` (everything from ``stdio.h`` and
  ``iostream``, respectively)
* ``malloc()``, ``free()`` etc.
* ``exit()`` (``_exit()`` is safe)
* Everything from ``pthread.h``



.. exercises
.. --------------------------------------------------------------------

Exercise: Signals
-----------------

**Write a program that ...**
  
* ... reads from ``STDIN_FILENO`` in a loop, and outputs
  what was read to ``STDOUT_FILENO``. Imagine that this is a
  replacement for an immensely important work which can block -
  the program blocks on ``STDIN_FILENO``.
* On program termination, the program has to do important
  cleanup work - it has to catch at least ``SIGINT`` and
  ``SIGTERM``.
* Our cleanup work is to safely - *not* in the signal
  handler - write "Goodbye!" to standard output.

