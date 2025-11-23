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
   posix-overrun/index
   timerfd/index
