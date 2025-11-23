.. include:: <mmlalias.txt>


POSIX Timers: Overrun
=====================

.. topic:: Documentation

   * `man -s 2 timer_getoverrun
     <https://man7.org/linux/man-pages/man2/timer_getoverrun.2.html>`__

Timer Overrun
-------------

* Timers may expire without the user noticing

  * Scheduling gives no guarantees |longrightarrow| short-interval
    timers may expire multiple times before user notices
  * Timer signal may be blocked
  * ...

* At *timer expiration*, the user can query the "timer overrun count"
* *Important*: only valid at timer expiration (in the signal handler
  or thread function)
* Not valid during normal program flow

Code: Timer Overrun, *Wrong*
----------------------------

* Nanosecond timer
* Signal (``SIGRTMIN``) blocked |longrightarrow| no notification
* No overrun detected after 3 seconds
* |longrightarrow| *Wrong*

.. literalinclude:: code/overrun-wrong.cpp
   :language: c++
   :caption: :download:`code/overrun-wrong.cpp`

Code: Timer Overrun, *Right*
----------------------------

.. topic:: Trainer's note

   * Don't block signal (remove code)
   * Ask for overrun in signal handler

     * Need ``timer`` as global variable

.. literalinclude:: code/overrun-right.cpp
   :language: c++
   :caption: :download:`code/overrun-right.cpp`

Code: Timer Overrun, Linux Specific
-----------------------------------

.. topic:: Trainer's note

   * ``info->si_overrun``
   * Requires a ``SA_SIGINFO`` handler (see
     :doc:`/trainings/material/soup/linux/sysprog/timers/posix-siginfo/index`)
   * |longrightarrow| No global variable needed

.. literalinclude:: code/overrun-linux-specific.cpp
   :language: c++
   :caption: :download:`code/overrun-linux-specific.cpp`
