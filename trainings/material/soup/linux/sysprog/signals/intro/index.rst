.. include:: <mmlalias.txt>


Introduction
============

.. topic:: Documentation

   * `man -s 7 signal
     <https://man7.org/linux/man-pages/man7/signal.7.html>`__

Throwing Numbers At Processes
-----------------------------

* Signal: integer number with predefined meaning
* Termination request, invalid memory access, ...
* Sent to a process (or a process group, or a thread inside a process)
* Either by another process

  .. image:: inter-process.svg
     :scale: 40%

* Or by the kernel

  .. image:: kernel-process.svg
     :scale: 40%

How Are Signals Received?
-------------------------

* Default: :doc:`asynchronous signal delivery <../async/index>`

  * In history, asynchronous delivery was implemented first (right at
    epoch)
  * Process may establish a :ref:`signal handler
    <sysprog-signals-handler>`
  * Interrupts process flow |longrightarrow| :ref:`race conditions
    <sysprog-signals-async-signal-safe>`
  * Hard to get right - much like writing interrupt service routines

* :doc:`Synchronous delivery <../sync/index>`

  * Wait *synchronously* until signal is delivered
  * Immediate question: what if the program wants to do something
    else?
  * |longrightarrow| Dedicate a separate thread to signal handling

* Event driven programs can use ``signalfd()``

A Little Terminology
--------------------

.. topic:: Documentation

   * `man -s 7 signal
     <https://man7.org/linux/man-pages/man7/signal.7.html>`__

* **Generate**: to send a signal. Processes can send a signal by using
  dedicated system calls like `kill()
  <https://man7.org/linux/man-pages/man2/kill.2.html>`__,
  `pthread_kill()
  <https://man7.org/linux/man-pages/man3/pthread_kill.3.html>`__,
  `sigqueue()
  <https://man7.org/linux/man-pages/man3/sigqueue.3.html>`__

* **Pending**: a signal is said to be pending until the process reacts
  on it. Reasons may be:

  * Signal is **blocked** by the process (:ref:`more
    <sysprog-signals-block>`)
  * The process is scheduled out, either because another process is
    running on the CPU, or because it is not runnable at all

* **"Traditional" signals** are not *queued* against the process
  |longrightarrow| multiple arrivals go unnoticed
* **Realtime signals** *are* queued (see :ref:`here
  <sysprog-signals-rtsig>` for more

  * No predefined meanings like traditional signals
  * ``SIGRTMIN`` up to ``SIGRTMAX`` (32 on Linux)

* **Disposition**: determines how the process reacts on the
  signal. From (`man -s 7 signal
  <https://man7.org/linux/man-pages/man7/signal.7.html>`__):

  .. list-table::
     
     * * Term
       * Default action is to terminate the process.
     * * Ign
       * Default action is to ignore the signal.
     * * Core
       * Default action is to terminate the process and dump core (see
         `core(5)
         <https://www.man7.org/linux/man-pages/man5/core.5.html>`__).
     * * Stop
       * Default action is to stop the process.
     * * Cont
       * Default action is to continue the process if it is currently
         stopped.

List Of Signals
---------------

From `man -s 7 signal
<https://man7.org/linux/man-pages/man7/signal.7.html>`__:

.. note::

   The signals SIGKILL and SIGSTOP cannot be caught, blocked, or
   ignored.

.. code-block:: text

   Signal      Standard   Action   Comment
   ────────────────────────────────────────────────────────────────────────
   SIGABRT      P1990      Core    Abort signal from abort(3)
   SIGALRM      P1990      Term    Timer signal from alarm(2)
   SIGBUS       P2001      Core    Bus error (bad memory access)
   SIGCHLD      P1990      Ign     Child stopped or terminated
   SIGCLD         -        Ign     A synonym for SIGCHLD
   SIGCONT      P1990      Cont    Continue if stopped
   SIGEMT         -        Term    Emulator trap
   SIGFPE       P1990      Core    Floating-point exception
   SIGHUP       P1990      Term    Hangup detected on controlling terminal
                                   or death of controlling process
   SIGILL       P1990      Core    Illegal Instruction
   SIGINFO        -                A synonym for SIGPWR
   SIGINT       P1990      Term    Interrupt from keyboard
   SIGIO          -        Term    I/O now possible (4.2BSD)
   SIGIOT         -        Core    IOT trap. A synonym for SIGABRT
   SIGKILL      P1990      Term    Kill signal
   SIGLOST        -        Term    File lock lost (unused)
   SIGPIPE      P1990      Term    Broken pipe: write to pipe with no
                                   readers; see pipe(7)
   SIGPOLL      P2001      Term    Pollable event (Sys V);
                                   synonym for SIGIO
   SIGPROF      P2001      Term    Profiling timer expired
   SIGPWR         -        Term    Power failure (System V)
   SIGQUIT      P1990      Core    Quit from keyboard
   SIGSEGV      P1990      Core    Invalid memory reference
   SIGSTKFLT      -        Term    Stack fault on coprocessor (unused)
   SIGSTOP      P1990      Stop    Stop process
   SIGTSTP      P1990      Stop    Stop typed at terminal
   SIGSYS       P2001      Core    Bad system call (SVr4);
                                   see also seccomp(2)
   SIGTERM      P1990      Term    Termination signal
   SIGTRAP      P2001      Core    Trace/breakpoint trap
   SIGTTIN      P1990      Stop    Terminal input for background process
   SIGTTOU      P1990      Stop    Terminal output for background process
   SIGUNUSED      -        Core    Synonymous with SIGSYS
   SIGURG       P2001      Ign     Urgent condition on socket (4.2BSD)
   SIGUSR1      P1990      Term    User-defined signal 1
   SIGUSR2      P1990      Term    User-defined signal 2
   SIGVTALRM    P2001      Term    Virtual alarm clock (4.2BSD)
   SIGXCPU      P2001      Core    CPU time limit exceeded (4.2BSD);
                                   see setrlimit(2)
   SIGXFSZ      P2001      Core    File size limit exceeded (4.2BSD);
                                   see setrlimit(2)
   SIGWINCH       -        Ign     Window resize signal (4.3BSD, Sun)
   
Examples: "Term" And "Core"
---------------------------

.. literalinclude:: code/stupid.cpp
   :language: c++
   :caption: :download:`code/stupid.cpp`

* Send ``SIGTERM``
* Press ``Ctrl-C`` |longrightarrow| ``SIGINT``

.. literalinclude:: code/segv.cpp
   :language: c++
   :caption: :download:`code/segv.cpp`

.. literalinclude:: code/fpe.cpp
   :language: c++
   :caption: :download:`code/fpe.cpp`

* ``SIGSEGV`` and ``SIGFPE`` (``target_compile_options(prog PRIVATE
  -Wno-div-by-zero``)
* Better to not handle (denial of reality)
* Talk about core dumps
* Show in ``gdb``

.. code-block:: console

   $ cat /proc/sys/kernel/core_pattern
   $ sudo sh -c 'echo core > /proc/sys/kernel/core_pattern'
