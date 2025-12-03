.. include:: <mmlalias.txt>


Timer File Descriptors
======================

.. topic:: Work in progress

   jjj complete this

.. topic:: Documentation

   * `man -s 2 timerfd_create
     <https://man7.org/linux/man-pages/man2/timerfd_create.2.html>`__

.. code-block:: c

   #include <sys/timerfd.h>
   
   int timerfd_create(int clockid, int flags);
   
   int timerfd_settime(int fd, int flags,
                       const struct itimerspec *new_value,
                       struct itimerspec *_Nullable old_value);
   int timerfd_gettime(int fd, struct itimerspec *curr_value);


The Idea
--------

* :doc:`File descriptors emit events
  </trainings/material/soup/linux/sysprog/eventloop/index>`

  * Incoming data ready
  * Signal is pending (see :doc:`here
    </trainings/material/soup/linux/sysprog/signals/signalfd/index>`)
  * Edge interrupt detected on IO pin
  * ...

* Timer expiration is an event too
* |longrightarrow| What if we could represent a timer by a file
  descriptor?

Timer *Events*: Far Superior
----------------------------

Timer expiration delivery options, according to POSIX:

* :doc:`Signals
  </trainings/material/soup/linux/sysprog/signals/index>` are not a
  solution to anything
* :doc:`Threads
  </trainings/material/soup/linux/sysprog/posix-threads/index>`
  *might* solve problems but are still hard
* |longrightarrow| This is not creative!
* :doc:`Event driven programming
  </trainings/material/soup/linux/sysprog/eventloop/index>` ...

  * Not simple, mentally (state machines all over)
  * Technically *far* superior

creation
--------

* no callback specification (``struct sigevent``)
* -> no callbacks
* event multiplexing :doc:`../../eventloop/index`
* flags: "nonblocking", "cloexec"


.. _sysprog-timerdf-oneshot-code:

oneshot
-------

.. topic:: Trainer's note

   * Start with :ref:`sysprog-timers-oneshot-code`
   * Remove all signal things

.. literalinclude:: code/oneshot.cpp
   :language: c++
   :caption: :download:`code/oneshot.cpp`

periodic
--------

.. topic:: Trainer's note

   * Continue from :ref:`sysprog-timerdf-oneshot-code`
   * Copy ``timer_settime`` from :ref:`sysprog-timers-periodic-code`
   * Loop around expiry
   * jjj show overrun (1ns interval)

.. literalinclude:: code/periodic.cpp
   :language: c++
   :caption: :download:`code/periodic.cpp`

closing words
-------------

* Be aware that there is a limit to open files which is much lower
  than the :ref:`limit to POSIX timers <sysprog-posix-timer-limit>`

