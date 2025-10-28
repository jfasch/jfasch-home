.. ot-group:: sysprog.timer

Timers
======

* ``alarm()``

  * since epoch
  * ``SIGALRM`` -> default disposition "terminate"
  * only whole-second granularity
  * only one timer
  * -> relatively useless

  uses

  * watchdog maybe

* ``setitimer()`` (look into it more, just to be able to say this is
  crap)

  * alarm, only multiplexed more flexibly onto multiple timer
    singletons

* ``timer_create()`` (and ``timer_delete()``, unshown in examples)

  * choose signal to use
  * setup handler for it (see :doc:`../signals/async/index`)
  * ``timer_create()`` to send that signal on expiry

    * `man -s 3 sigevent
      <https://man7.org/linux/man-pages/man3/sigevent.3type.html>`__

    .. code-block:: c

       event.sigev_notify = SIGEV_SIGNAL;    // <-- alternatives?
       event.sigev_signo = SIGRTMIN;

    

  * one shot (:download:`code/async-signal-timer-oneshot.cpp`)
  * periodic (:download:`code/async-signal-timer-periodic.cpp`)

  delivery

  * async
  * thread
