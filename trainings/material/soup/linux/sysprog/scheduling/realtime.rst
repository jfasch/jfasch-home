.. ot-topic:: linux.sysprog.scheduling.realtime
   :dependencies: linux.sysprog.scheduling.wakeup_latency

.. include:: <mmlalias.txt>


Realtime
========

.. contents::
   :local:

Wakeup Latency, and Fair Scheduling
-----------------------------------

* *Scheduling decision*: "best" task
* In the fair world, everyone is equal

  * |longrightarrow| no guaranteed wakeup times
  * Might be that 100 tasks are chosen *before* the one that has the
    event pending

* ``nice`` can be used to make some "more equal"

Nice Value: Inexact Tuning
--------------------------

**Attention**: no guarantees |longrightarrow| no realtime!

* Specifies how "nice" a process is
* Between -20 (not nice) and +20 (very nice)
* +20 |longrightarrow| only runs when noone else wants the CPU
* Non-root user can only increase nice value ("become nicer")

Commands:

* `nice <https://man7.org/linux/man-pages/man1/nice.1.html>`__
* `renice <https://man7.org/linux/man-pages/man1/renice.1.html>`__

.. note::

   * *Nice values* give a false sense of realtime feeling
   * No guarantees!

Enter Realtime: Definition
--------------------------

**DIN 44300**

   Echtzeitbetrieb ist ein Betrieb eines Rechensystems, bei dem
   Programme zur Verarbeitung anfallender Daten ständig derart
   betriebsbereit sind, daß die Verarbeitungsergebnisse innerhalb
   einer vorgegebenen Zeitspanne verfügbar sind.

A-ha ... so *what* is Realtime?

* Realtime *is not* speed
* Realtime *is not* low latency
* Realtime *is* **determinism**

Realtime on Linux
-----------------

As opposed to *fair scheduling* ...

* When a realtime task becomes *runnable*, the system makes it
  *running* immediately - a lower priority task is *preempted* to
  steal the CPU

  * Fair scheduling just adds *runnable* task to set of all *runnable*
    tasks |longrightarrow| selects one from there when CPU becomes
    available
  * Ad *determinism*: whatever prevents the task from running is
    preempted, and the realtime task can run *immediately*

* Lower priority *running* task is pushed from its CPU, and realtime
  task is scheduled on that CPU
* |longrightarrow| inherently unfair
* |longrightarrow| requires root permission, obviously

**Immediately?** |longrightarrow| later!

Demo: Measuring Wakeup Latency
------------------------------

* `chrt <https://man7.org/linux/man-pages/man1/chrt.1.html>`__: run
  non-realtime-aware process with realtime attributes
* Simple (no programming necessary), but there is more to it

Run program with ``SCHED_FIFO`` (``-f``) realtime scheduling policy,
at priority 1 (lowest realtime prio). (See :doc:`realtime-api` for
details.)

.. code-block:: console

   $ sudo chrt -f 1 ./jitter.py 0.01 100
   mean: 0.000014s (0.013914ms, 13.91410827636698us)
   stdev: 0.000002s (0.002382ms, 2.3820173632900326us)

Immediately?
------------

Situations where preemption is difficult ...

* Holds a :doc:`spinlock
  </trainings/material/soup/kernel/spinlock/topic>`

  * |longrightarrow| preemption disabled, interrupts off
  * |longrightarrow| *brutal*

* An interrupt service routine (ISR) is running

  * Interrupt context is not preemptible
  * Only task ("process") context is

* There is always the risk of :ref:`priority inversion
  <priority-inversion>` (a deadlock scenario)

Immediately! |longrightarrow| ``PREEMPT_RT``
--------------------------------------------

* ``PREEMPT_RT`` - `"Realtime Preemption Patch"
  <https://rt.wiki.kernel.org/index.php/Main_Page>`__

  * Solutions to problems above
  * Very intrusive (e.g., spinlocks aren't spinlocks anymore, ISR's
    aren't ISR's anymore)
  
* Ongoing since early 2000 (`"Approaches to realtime Linux"
  <https://lwn.net/Articles/106010/>`__)
* Merged into mainline in 2021 (`"Realtime preemption locking core
  merged" <https://lwn.net/Articles/867919/>`__)
* Not enabled by most Linux distributions though (still too
  controversial)
