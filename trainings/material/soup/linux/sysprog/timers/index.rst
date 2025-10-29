.. ot-group:: sysprog.timer

Time, Clocks, Timers And Notification
=====================================

.. toctree::
   :maxdepth: 1

   clocks/index
   historical/index
   posix/index

.. nanosleep, clock_nanosleep

.. gettimeofday
.. clock_gettime


Basics
------

* POSIX timers: ``timer_create()`` (and ``timer_delete()``, unshown in
  examples)

  * delivery/expiry: (async) signal, thread (-> later)
  * choose signal to use (*never* queued, not even rt signals)
  * setup handler for it (see :doc:`../signals/async/index`)
  * ``timer_create()`` to send that signal on expiry

    * `man -s 3 sigevent
      <https://man7.org/linux/man-pages/man3/sigevent.3type.html>`__

    .. code-block:: c

       event.sigev_notify = SIGEV_SIGNAL;    // <-- alternatives?
       event.sigev_signo = SIGRTMIN;

* one shot (:download:`code/posix-oneshot.cpp`)

  * ``it_interval`` is 0 -> oneshot
  * expiry at ``it_value``
  * nothing new regarding signals

* periodic (:download:`code/posix-periodic.cpp`)

  * note ``it_interval`` not 0
  * wrap in infinite loop

* thread notification

Details
-------

* thread notification: is a new thread created? `man -s 3 sigevent
  <https://man7.org/linux/man-pages/man3/sigevent.3type.html>`__ says
  that it could, but otherwise nothing usable.

* multiplexing multiple timers on one signal via siginfo_t

  * jjj link from signals/async
  * only 32 rt signals
  * might want to use more timers
  * continue from posix-periodic.cpp
  * add 2nd timer (and arm it differently)
  * remove "interrupted" in main loop
  * -> handler cannot say which

  * -> :download:`code/posix-2timers.cpp`

  solution

  * step 1: sigaction -> SA_SIGINFO, sa_sigaction (more info in
    handler)

    * handler signature: void(int sig, siginfo_t* info, void*)
    * in handler, use ``info->si_value``
    * make timer1, timer2 visible in signal handler (-> global)

  * event notification setup

    * event.sival_ptr = &timer{1,2} (-> handler's info->si_ptr)

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
     timer created using timer_create().  Consequently, the number
     of timers is limited by the RLIMIT_SIGPENDING resource limit
     (see setrlimit(2)).

* overrun
