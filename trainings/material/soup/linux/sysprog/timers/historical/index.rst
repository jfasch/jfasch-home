Obsolete Timer APIs
===================

From The Epoch: ``alarm()``
---------------------------

.. topic:: Documentation

   * `man -s 2 alarm
     <https://man7.org/linux/man-pages/man2/alarm.2.html>`__

* Only one timer per process

  * Repeated calls to ``alarm()`` cancel a previously set alarm timer

* One-second granularity
* Expiry notification: ``SIGALRM``

.. literalinclude:: code/alarm.cpp
   :language: c++
   :caption: :download:`code/alarm.cpp`

Evolution: Interval Timers
--------------------------

.. topic:: Documentation

   * `man -s 2 setitimer
     <https://man7.org/linux/man-pages/man2/setitimer.2.html>`__

* Not only one, but three per-process timers available
* Drawbacks

  * Definition predates suspend/resume
  * Not immune against time sets (e.g. NTP)
  * Conflict with ``alarm()`` timers

.. list-table::
   :align: left

   * * ``ITIMER_REAL``
     * Wall clock time; ``SIGALRM`` at expiration
   * * ``ITIMER_VIRTUAL``
     * Profiling: counts user-mode CPU time; ``SIGVTALRM`` at
       expiration
   * * ``ITIMER_PROF``
     * Profiling: counts total CPU time (user and system); ``SIGPROF``
       at expiration

* All in all: very limited still
