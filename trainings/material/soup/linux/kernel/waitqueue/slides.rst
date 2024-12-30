.. include:: <mmlalias.txt>

Waiting for Something (Slideshow)
=================================

.. contents::
   :local:

Waiting for Something
---------------------

* Processes wait for something to happen

  * Network arrived
  * Switch pressed
  * Some event happened
  * ...

* *Polling*: busy looping, constantly checking the condition

  * |longrightarrow| power inefficient
  * |longrightarrow| stupid

* *Sleeping*

  * If that something hasn't yet happened, a process is put to sleep
  * A process that make the event happen, is supposed to wake any
    waiters

Wait Queues: Initializing
-------------------------

.. code-block:: c

   #include <linux/wait.h>

   struct wait_queue_head_t wq;
   init_waitqueue_head(&wq);

(No destructor)

Wait Queue: Waiting
-------------------

.. code-block:: c

   #include <linux/wait.h>
   #include <linux/sched.h>

   int wait_event(wq, something != 1);
   int wait_event_interruptible(wq, something != 1);
   int wait_event_timeout(wq, something != 1, timeout_jiffies);
   int wait_event_interruptible_timeout(wq, something != 1, timeout_jiffies);

*Note no pointers* |longrightarrow| obscure programming style in the
early days of Linux

Wait Queue: Waking
------------------

.. code-block:: c

   #include <linux/wait.h>
   #include <linux/sched.h>

   wake_up(&wq);
   wake_up_interruptible(&wq);

* ``wake_up_interruptible()`` wakes only processes in state
  ``TASK_INTERRUPTIBLE``
* ``wake_up()`` wakes all processes

Documentation
-------------

.. list-table::
   :widths: auto
   :align: left

   * * `wait_event
       <https://www.kernel.org/doc/html/v4.16/driver-api/basics.html?highlight=wait_event_interruptible#c.wait_event>`__
   * * `wait_event_interruptible
       <https://www.kernel.org/doc/html/v4.16/driver-api/basics.html?highlight=wait_event_interruptible#c.wait_event_interruptible>`__
   * * `wait_event_timeout
       <https://www.kernel.org/doc/html/v4.16/driver-api/basics.html?highlight=wait_event_timeout#c.wait_event_timeout>`__
   * * `wait_event_interruptible_timeout
       <https://www.kernel.org/doc/html/v4.16/driver-api/basics.html?highlight=wait_event_interruptible_timeout#c.wait_event_interruptible_timeout>`__
   * * `wake_up
       <https://www.kernel.org/doc/html/v4.16/driver-api/basics.html?highlight=wake_up#c.__wake_up>`__
   * * wake_up_interruptible hm?
