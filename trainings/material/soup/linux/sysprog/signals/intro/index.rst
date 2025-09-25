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
