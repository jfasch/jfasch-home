.. include:: <mmlalias.txt>


Synchronous Signal Handling
===========================

.. topic:: Documentation

   * `man -s 3 sigwait
     <https://man7.org/linux/man-pages/man3/sigwait.3.html>`__
   * `man -s 2 sigwaitinfo
     <https://man7.org/linux/man-pages/man2/sigtimedwait.2.html>`__
   * `man -s 2 sigtimedwait
     <https://man7.org/linux/man-pages/man2/sigtimedwait.2.html>`__

.. _sysprog-signals-block:

Waiting (Blocking) For Signals
------------------------------

* ``sigwait()`` (and friends) *synchronously wait* for a signal
* |longrightarrow| No async delivery, no async-signal-safety concerns
* |longrightarrow| All fine
* Use case: in a multithreaded program, it is probably best to
  dedicate one thread to signal handling, using ``sigwait()`` or
  similar.

Example: Self-Pipe Trick, Revisited
-----------------------------------

.. topic:: Trainer's note

   * Copy program from :doc:`../async-self-pipe/index`, replace
     handler and stuff with ``sigwait()``
   * Don't block signals initially, seeing ``SIGTERM``'s default
     disposition (terminate). Only then block it.

.. literalinclude:: code/sigwait.cpp
   :language: c++
   :caption: :download:`code/sigwait.cpp`
