POSIX Timers: Arming (Oneshot/Periodic)
=======================================

To show how to setup ("arm") oneshot and periodic timers, this section
uses *signals* as a timer expiration delivery mechanism. There is also
a "threaded" delivery, this will be covered in
:doc:`../posix-threaded/index`. The mechanism how timer are armed
stays the same, no matter what delivery option is used.

Basics
------

* POSIX timers: ``timer_create()`` (and ``timer_delete()``, mostly
  unused in examples)
* Highly configurable (via ``struct sigevent``)
* Choose signal to use

  * Signals that are used for timer expiry notification are *never*
    queued - not even realtime signals (see
    :ref:`sysprog-signals-rtsig`)

.. topic:: Documentation

   * `man -s 3 sigevent
     <https://man7.org/linux/man-pages/man3/sigevent.3type.html>`__

.. code-block:: c

   event.sigev_notify = SIGEV_SIGNAL;       // <-- notification type (SIGEV_THREAD?)
   event.sigev_signo = SIGRTMIN;            // <-- send SIGRTMIN at expiry

* Setup handler for signal (see
  :doc:`/trainings/material/soup/linux/sysprog/signals/async/index`)
* Arm timer using ``timer_settime()``

Arming: ``struct itimerspec``
-----------------------------

.. topic:: Documentation

   * `man -s 2 timer_settime
     <https://man7.org/linux/man-pages/man2/timer_settime.2.html>`__
   * `man -s 3type itimerspec
     <https://man7.org/linux/man-pages/man3/itimerspec.3type.html>`__
   * `man -s 3type timespec
     <https://man7.org/linux/man-pages/man3/itimerspec.3type.html>`__

.. code-block:: c

   #include <time.h>
   
   struct timespec {
       time_t     tv_sec;   /* Seconds */
       /* ... */  tv_nsec;  /* Nanoseconds [0, 999'999'999] */
   };

   struct itimerspec {
       struct timespec  it_interval;  /* Interval for periodic timer */
       struct timespec  it_value;     /* Initial expiration */
   };

* ``it_interval``: periodic timer
* {0,0} for one-shot timer

.. _sysprog-timers-oneshot-code:

Code: One-shot Timers
---------------------

.. literalinclude:: code/oneshot.cpp
   :language: c++
   :caption: :download:`code/oneshot.cpp`

.. _sysprog-timers-periodic-code:

Code: Periodic Timers
---------------------

.. literalinclude:: code/periodic.cpp
   :language: c++
   :caption: :download:`code/periodic.cpp`
