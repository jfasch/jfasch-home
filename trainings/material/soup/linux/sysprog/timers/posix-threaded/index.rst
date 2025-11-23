.. include:: <mmlalias.txt>


POSIX Timers: Threaded Notification
===================================

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/posix-threads/index`
   * :doc:`/trainings/material/soup/linux/sysprog/posix-threads/020-lifecycle/topic`

.. topic:: Documentation

   * `man -s 2 timer_create
     <https://man7.org/linux/man-pages/man2/timer_create.2.html>`__
   * `man -s 3 sigevent
     <https://man7.org/linux/man-pages/man3/sigevent.3type.html>`__

Signals Unwanted
----------------

* Signal handling is hard (see
  :ref:`sysprog-signals-async-signal-safe`)
* Creative ways have been found around its peculiarities
  (:doc:`/trainings/material/soup/linux/sysprog/signals/async-self-pipe/index`)
* Historically, :doc:`asynchronous delivery
  </trainings/material/soup/linux/sysprog/signals/async/index>` has
  been the only way to notify processes of something outside of their
  immediate control
* Well understood though

Threaded Timer Expiry Notification
----------------------------------

* Async signal safety is rather limiting
* :doc:`POSIX threads
  </trainings/material/soup/linux/sysprog/posix-threads/index>` run in
  a context that is easier
* Locking and communication primitives
* Came much later in history (around year 2000, long after epoch)
* |longrightarrow| Much easier communication from "callback function"
  into the rest of the process

.. code-block:: c

   sigevent event = {0};
   event.sigev_notify = SIGEV_THREAD;                     // <-- threaded delivery
   event.sigev_notify_function = handler;                 // <-- callback function 
   // event.sigev_notify_attributes = ...;                // <-- (optional) thread attributes

Code: Periodic Timer, Threaded
------------------------------

.. topic:: Trainer's note

   * Copy the program from :ref:`sysprog-timers-periodic-code`
   * Modify handler: ``union sigval``
   * ``timer_create()``: ``SIGEV_THREAD``
   * Remove ``sigaction()``

.. literalinclude:: code/periodic.cpp
   :language: c++
   :caption: :download:`code/periodic.cpp`

Drawback: Thread Creation
-------------------------

.. code-block:: text

   SIGEV_THREAD
          Notify the process by invoking sigev_notify_function "as  if"  it
          were  the start function of a new thread.  (Among the implementa‐
          tion possibilities here are that each  timer  notification  could
          result  in  the creation of a new thread, or that a single thread
          is created to receive all notifications.)  The  function  is  in‐
          voked with sigev_value as its sole argument.  If sigev_notify_at‐
          tributes  is not NULL, it should point to a pthread_attr_t struc‐
          ture  that  defines  attributes   for   the   new   thread   (see
          pthread_attr_init(3)).

* "each timer notification could result in the creation of a new
  thread"
* Exactly that is the case
* *Thread creation is not free*
* |longrightarrow| Might impose performance problems for high
  frequency timers

.. code-block:: console

   $ strace -f ./sysprog-timers-threaded-periodic
   ...
   [pid 1235513] clone3({flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, child_tid=0x7f270ba0d990, parent_tid=0x7f270ba0d990, exit_signal=0, stack=0x7f270b20d000, stack_size=0x7fff40, tls=0x7f270ba0d6c0} => {parent_tid=[1235530]}, 88) = 1235530
   ...
