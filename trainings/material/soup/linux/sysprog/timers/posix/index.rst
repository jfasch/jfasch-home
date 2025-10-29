POSIX Interval Timers
=====================

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/signals/index`
   * :doc:`/trainings/material/soup/linux/sysprog/posix-threads/index`

.. topic:: Documentation

   * `man -s 2 timer_create <https://man7.org/linux/man-pages/man2/timer_create.2.html>`__
   * `man -s 2 timer_delete <https://man7.org/linux/man-pages/man2/timer_delete.2.html>`__
   * `man -s 2 timer_settime
     <https://man7.org/linux/man-pages/man2/timer_settime.2.html>`__
   * `man -s 2 timer_gettime
     <https://man7.org/linux/man-pages/man2/timer_settime.2.html>`__
   * `man -s 2 timer_getoverrun
     <https://man7.org/linux/man-pages/man2/timer_getoverrun.2.html>`__

Overview
--------

* One-shot and periodic variants
* Nanosecond granularity
* Parameterizable clock (see
  :doc:`/trainings/material/soup/linux/sysprog/timers/clocks/index`)
* Absolute time-points and relative time-intervals
* Dynamically created (``timer_t``, see `here
  <https://man7.org/linux/man-pages/man3/timer_t.3type.html>`__)
* Notification using freely choosable signals (which can be waited for
  synchronously for that matter; see
  :doc:`/trainings/material/soup/linux/sysprog/signals/sync/index`)
* Notification using threads (see
  :doc:`/trainings/material/soup/linux/sysprog/posix-threads/index`)

Creation And Deletion
---------------------

.. topic:: Documentation

   * `man -s 2 timer_create
     <https://man7.org/linux/man-pages/man2/timer_create.2.html>`__
   * `man -s 2 timer_delete
     <https://man7.org/linux/man-pages/man2/timer_delete.2.html>`__
   * `man -s 3 sigevent
     <https://man7.org/linux/man-pages/man3/sigevent.3type.html>`__

.. code-block:: c

   #include <time.h>
   
   int timer_create(clockid_t clockid,
                    struct sigevent *_Nullable restrict sevp,
                    timer_t *restrict timerid);
   int timer_delete(timer_t timerid);

* "Callback" configuration via ``struct sigevent``
* Signal or thread
* Optional callback parameter

``struct sigevent``
-------------------

* ``struct sigevent`` - timer "callback" specification
* A bit convoluted
* Not all fields are valid in all circumstances

**Notification type**

* ``sigev_notify = SIGEV_SIGNAL`` 

  * ``sigev_signo``: signal number - user selectable,
    e.g. ``SIGRTMIN+7``, or ``SIGUSR1``
  * Important: even when a realtime signal is chosen (see :ref:`here
    <sysprog-signals-rtsig>`), *multiple expirations are not queued*

* ``sigev_notify = SIGEV_THREAD`` 

  * ``sigev_notify_function``: callback function called in a separate
    thread
  * ``sigev_notify_attributes``: attributes for thread creation (see
    :doc:`here
    </trainings/material/soup/linux/sysprog/posix-threads/020-lifecycle/topic>`)

* ``sigev_notify = SIGEV_NONE``: must poll using ``timer_gettime()``

**More callback information**

* ``sigev_value``, of type

  .. code-block:: c

     union sigval {
         int sival_int;
         void *sival_ptr;
     };

* ``SIGEV_SIGVAL``: passed to signal handler when installed as
  ``SA_SIGINFO`` (see later)
* ``SIGEV_THREAD``: passed as argument to thread callback function,
  ``sigev_notify_function`` (see later)
