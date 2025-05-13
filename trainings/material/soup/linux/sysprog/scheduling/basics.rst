.. include:: <mmlalias.txt>


Scheduling (and Multitasking)
=============================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/scheduling/basics`

Scheduling
----------

* *Scheduler*

  * Core kernel subsystem
  * Assigns CPU resources to *runnable* tasks (tasks that do *not*
    wait for anything; e.g. network I/O, timer)
  * Task: process or thread; kernel makes no difference (see
    :doc:`processes-and-threads` for difference and motivation)

* *Timeslicing*

  * Each task can run on the CPU for only a short period of time
    (variable, but lets say 20ms)
  * Many tasks |longrightarrow| illusion of parallelism, even on a
    single CPU

*Fairness* Criteria
-------------------

* No task must *starve* (not scheduled onto a CPU for a long time)
* Each task must receive an *equal CPU share*
* Among all *runnable* tasks, the "best" tasks is chosen to run next
* When a task becomes *runnable* (e.g. network packet arrived), it
  *does not run immediately*

  * Only added to set of *runnable* tasks |longrightarrow| scheduler
    picks "best" task when CPU becomes available
  * |longrightarrow| tasks not interrupted; can achieve more work
  * |longrightarrow| *throughput*

* Dynamic meaning of "best", based on usage patterns

  * |longrightarrow| *CPU bound* vs. *I/O bound*

*CPU bound* vs. *I/O bound*
---------------------------

* *CPU bound*

  * Task use up its timeslice |longrightarrow| *preempted* by
    scheduler

* *I/O bound*

  * Task mostly waits for something (e.g. network I/O, timer)
  * Wakes up for a short time period to process the event
  * Waits for next event |longrightarrow| no need to *preempt*

Demo: I/O vs CPU bound
----------------------

**I/O bound**: waits for timer to expire. Start one of it.

.. code-block:: console

   $ i=0; while true; do sleep 0.1; echo $i; i=$((i+1)); done

**CPU bound**: computes SHA1 checksum over infinite stream of
0-bytes. Start many.

.. code-block:: console

   $ sha1sum /dev/zero

.. note:: 

   Use ``top`` to show CPU usage

Scheduling Decision, Runnability
--------------------------------

* Question when a CPU has become available: *Which one do I pick next?*
* How do CPUs become available?

  * Preemption: a task has exhausted its timeslice. Still *runnable*,
    but not *running*.
  * Voluntarily: a task goes to sleep (wait for some external
    event). Not *runnable*.

* *Which one do I pick next?*

  * Not easily answered
  * CPU vs. I/O bound (|longrightarrow| dynamic prioritization)
  * Nice value (|longrightarrow| later)
  * Realtime (|longrightarrow| later)
