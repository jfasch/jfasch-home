.. include:: <mmlalias.txt>

Asynchronous Signal Handling
============================

.. _sysprog-signals-handler:

.. topic:: Documentation

   * `man -s 2 sigaction
     <https://man7.org/linux/man-pages/man2/sigaction.2.html>`__
   * `man -s 3 sigsetops
     <https://man7.org/linux/man-pages/man3/sigfillset.3.html>`__

.. topic:: Teacher's note

   Use first program from :doc:`../intro/index` (``stupid.cpp``) and
   modify as we go.

My First Signal Handler
-----------------------

* Discuss `sigaction()
  <https://man7.org/linux/man-pages/man2/sigaction.2.html>`__
  vs. `signal <https://man7.org/linux/man-pages/man2/signal.2.html>`__
  (deprecated)
* Discuss :ref:`"async-signal-safety"
  <sysprog-signals-async-signal-safe>` |longrightarrow| use
  ``write(STDOUT_FILENO, ...)``

.. literalinclude:: code/simple-handler.cpp
   :language: c++
   :caption: :download:`code/simple-handler.cpp`

Ignoring Signals
----------------

* Handler for ``SIGTERM`` does nothing (suppresses termination)
* |longrightarrow| Could just as well ignore

.. literalinclude:: code/ignore-term.cpp
   :language: c++
   :caption: :download:`code/ignore-term.cpp`

``SIGKILL`` Cannot Be Handled/Ignored
-------------------------------------

* Ignore both ``SIGTERM`` and ``SIGINT``
* |longrightarrow| No way to nicely request termination
* Send ``SIGSEGV`` that we already know from :doc:`the introduction
  <../intro/index>`
* Send ``SIGKILL``: cannot be handled/ignored

.. literalinclude:: code/ignore-term-int.cpp
   :language: c++
   :caption: :download:`code/ignore-term-int.cpp`

Interrupting System Calls
-------------------------

* Process context (as opposed to code in signal handlers) may want to
  react upon changes made by a signal handler
* |longrightarrow| Long-sleeping system calls are interrupted
* ``EINTR``/"Interrupted system call"
* Teacher: replace ``for(;;);`` with ``pause()`` (|longrightarrow|
  more efficient |:flushed:|)

.. literalinclude:: code/eintr.cpp
   :language: c++
   :caption: :download:`code/eintr.cpp`

Long-Sleeping System Calls: What Is That?
-----------------------------------------

Legalese from `man -s 7 signal
<https://man7.org/linux/man-pages/man7/signal.7.html>`__:

.. code-block:: text

   •  read(2), readv(2), write(2), writev(2), and ioctl(2) calls on  "slow"
      devices.   A "slow" device is one where the I/O call may block for an
      indefinite time, for example, a terminal, pipe, or socket.  If an I/O
      call on a slow device has already transferred some data by  the  time
      it  is  interrupted  by a signal handler, then the call will return a
      success status (normally, the number  of  bytes  transferred).   Note
      that  a  (local)  disk is not a slow device according to this defini‐
      tion; I/O operations on disk devices are not interrupted by signals.
   
   •  open(2), if it can block (e.g., when opening a FIFO; see fifo(7)).
   
   •  wait(2), wait3(2), wait4(2), waitid(2), and waitpid(2).
   
   •  Socket  interfaces:  accept(2),  connect(2),  recv(2),   recvfrom(2),
      recvmmsg(2), recvmsg(2), send(2), sendto(2), and sendmsg(2), unless a
      timeout has been set on the socket (see below).
   
   •  File  locking  interfaces: flock(2) and the F_SETLKW and F_OFD_SETLKW
      operations of fcntl(2)
   
   •  POSIX message queue  interfaces:  mq_receive(3),  mq_timedreceive(3),
      mq_send(3), and mq_timedsend(3).
   
   •  futex(2)  FUTEX_WAIT  (since  Linux 2.6.22; beforehand, always failed
      with EINTR).
   
   •  getrandom(2).
   
   •  pthread_mutex_lock(3), pthread_cond_wait(3), and related APIs.
   
   •  futex(2) FUTEX_WAIT_BITSET.
   
   •  POSIX semaphore interfaces: sem_wait(3) and  sem_timedwait(3)  (since
      Linux 2.6.22; beforehand, always failed with EINTR).
   
   •  read(2)  from an inotify(7) file descriptor (since Linux 3.8; before‐
      hand, always failed with EINTR).

Long-Sleeping: Waiting For Keypress
-----------------------------------

* Replace ``pause()`` with ``read(STDIN_FILENO, ...)``
* |longrightarrow| Wait for keypress

.. literalinclude:: code/eintr-wait-keypress.cpp
   :language: c++
   :caption: :download:`code/eintr-wait-keypress.cpp`

Handling ``EINTR`` Sanely? Manually Restarting Interrupted Call?
----------------------------------------------------------------

* Bigger (single-threaded) applications rarely block deep inside a
  call chain
* Event driven: main event loop blocks (and nothing else)
  |longrightarrow| central event/``EINTR`` handling
* If ``EINTR`` is seen somewhere inside a call chain |longrightarrow|
  restart what's been interrupted
* |longrightarrow| Dirty though!

.. literalinclude:: code/eintr-manual-restart.cpp
   :language: c++
   :caption: :download:`code/eintr-manual-restart.cpp`

Automatic Restart Interrupted Call
----------------------------------

* ``sigaction.sa_flags |= SA_RESTART``
* |longrightarrow| Automatic restart of system calls
* Complicated, not well defined |longrightarrow| avoid! (Teacher's opinion)

.. literalinclude:: code/eintr-auto-restart.cpp
   :language: c++
   :caption: :download:`code/eintr-auto-restart.cpp`

.. _sysprog-signals-async-signal-safe:

Async-Signal-Safety
-------------------

.. topic:: Documentation

   * `man -s 7 signal-safety
     <https://man7.org/linux/man-pages/man7/signal-safety.7.html>`__

.. topic:: Teacher's note

   Switch to ``SIGUSR1`` (``SIGTERM`` inappropriate)

* Signal handler runs in a context where nothing is allowed
* No ``malloc()``, no standard IO, no nothing
* No ``pthread`` 
* Basically: only system calls (see `here
  <https://man7.org/linux/man-pages/man7/signal-safety.7.html>`__)
* Possible solution: blocking signals when operating on shared data
  (see :ref:`below <sysprog-signals-sigmask>`)
* |longrightarrow| Complicated and error prone, *keep away!*

.. literalinclude:: code/async-signal-unsafe.cpp
   :language: c++
   :caption: :download:`code/async-signal-unsafe.cpp`

.. _sysprog-signals-sigmask:

Blocking Asynchronous Signal Delivery: Signal Mask
--------------------------------------------------

.. topic:: Documentation

   * `man -s 2 sigprocmask
     <https://man7.org/linux/man-pages/man2/sigprocmask.2.html>`__
   * `man -s 3 pthread_sigmask
     <https://man7.org/linux/man-pages/man3/pthread_sigmask.3.html>`__

* *Signal mask*: set of signals that are blocked from asynchronous
  delivery
* A signal that is blocked becomes *pending* on arrival
* Single threaded programs use `sigprocmask()
  <https://man7.org/linux/man-pages/man2/sigprocmask.2.html>`__:
  *unspecified in multithreaded programs!*
* Multithreaded programs use `pthread_sigmask()
  <https://man7.org/linux/man-pages/man3/pthread_sigmask.3.html>`__

From `man -s 2 sigprocmask
<https://man7.org/linux/man-pages/man2/sigprocmask.2.html>`__:

.. list-table:: 
   :align: left

   * * ``SIG_BLOCK``
     * The set of blocked signals is the union of the current set and
       the set argument.
   * * ``SIG_UNBLOCK``
     * The signals in set are removed from the current set of blocked
       signals.  It is permissible to attempt to unblock a signal
       which is not blocked.
   * * ``SIG_SETMASK``
     * The set of blocked signals is set to the argument set.

.. literalinclude:: code/sigmask.cpp
   :language: c++
   :caption: :download:`code/sigmask.cpp`

.. _sysprog-signals-sigpending:

Asking For Pending Signals
--------------------------

.. literalinclude:: code/sigpending.cpp
   :language: c++
   :caption: :download:`code/sigpending.cpp`

.. _sysprog-signals-rtsig:

Realtime Signals
----------------

.. topic:: Teacher's note

   * First, start the program :ref:`above
     <sysprog-signals-sigpending>` and send multiple instances of
     ``SIGUSR1``
   * Modify to use ``SIGRTMIN+5`` and show again

* Traditional signals are not queued
* Realtime signals are

.. literalinclude:: code/rtsig-queued.cpp
   :language: c++
   :caption: :download:`code/rtsig-queued.cpp`
