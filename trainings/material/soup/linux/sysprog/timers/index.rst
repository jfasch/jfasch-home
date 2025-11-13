.. ot-group:: sysprog.timer

Time, Clocks, Timers And Notification
=====================================

Time is a complex topic, even with computers omitted from the
picture. This section, naturally, discusses how time - and timers
(notifications of time-related events) - are handled in Linux.

Starting with a discussion of *clock* variants, and various ways to
*synchronously* defer execution, we try to cover the vast amount of
*notification* possibilities. (I'll try to not be too judgy on the
way, but you might know my preferences anyway regarding
:doc:`asynchronous signal delivery <../signals/async/index>`.)

.. topic:: Under development

   This section is still under development. The sheer amount of rabbit
   holes (e.g. POSIX timer overrun semantics, or the implications of
   selecting POSIX *threaded* delivery) makes it challenging to
   provide conclusive material *that is still interesting*.

.. toctree::
   :maxdepth: 1

   clocks/index
   historical/index
   posix-intro/index
   posix-oneshot-periodic/index
   posix-siginfo/index
   posix-threaded/index
   timerfd/index

Details
-------

.. _sysprog-posix-timer-limit:

Limits, Anywhere?
.................

* max # timers: :download:`code/posix-maxtimers.cpp` -> 62207

  .. code-block:: console

     $ ulimit -a
     ...
     pending signals                     (-i) 62209
     ...

  From `man -s 2 timer_create
  <https://man7.org/linux/man-pages/man2/timer_create.2.html>`__

  .. code-block:: text
     :caption: ``NOTES`` section

     The kernel preallocates a "queued real-time signal" for each
     timer created using timer_create().  Consequently, the number of
     timers is limited by the RLIMIT_SIGPENDING resource limit (see
     setrlimit(2)).

Timer Overrun
.............

Continue from :download:`code/posix-overrun.cpp`

