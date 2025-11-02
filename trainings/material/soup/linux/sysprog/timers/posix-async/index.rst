POSIX Timers: Asynchronous Notification
=======================================

Basics
------

* POSIX timers: ``timer_create()`` (and ``timer_delete()``, unshown in
  examples)

  * delivery/expiry: (async) signal, thread (-> later)
  * choose signal to use (*never* queued, not even rt signals)
  * setup handler for it (see
    :doc:`/trainings/material/soup/linux/sysprog/signals/async/index`)
  * ``timer_create()`` to send that signal on expiry

    * `man -s 3 sigevent
      <https://man7.org/linux/man-pages/man3/sigevent.3type.html>`__

    .. code-block:: c

       event.sigev_notify = SIGEV_SIGNAL;    // <-- alternatives?
       event.sigev_signo = SIGRTMIN;

One-shot Timers
---------------

* one shot (:download:`code/oneshot.cpp`)

  * ``it_interval`` is 0 -> oneshot
  * expiry at ``it_value``
  * nothing new regarding signals

Periodic Timers
---------------

* periodic (:download:`code/periodic.cpp`)

  * note ``it_interval`` not 0
  * wrap in infinite loop

``sigaction(SA_SIGINFO)``
.........................

* link to sync handling/``sigwaitinfo()``
* multiplexing multiple timers on one signal via siginfo_t

  * jjj link from signals/async
  * only 32 rt signals
  * might want to use more timers
  * continue from posix-periodic.cpp
  * add 2nd timer (and arm it differently)
  * remove "interrupted" in main loop
  * -> handler cannot say which
  * :download:`code/two-timers-problem.cpp`

  solution

  * :download:`code/two-timers-siginfo.cpp`
  * step 1: sigaction -> SA_SIGINFO, sa_sigaction (more info in
    handler)

    * handler signature: void(int sig, siginfo_t* info, void*)
    * in handler, use ``info->si_value``
    * make timer1, timer2 visible in signal handler (-> global)

  * event notification setup

    * event.sival_ptr = &timer{1,2} (-> handler's info->si_ptr)
