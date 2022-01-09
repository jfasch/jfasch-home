.. ot-topic:: sysprog.scheduling.realtime_api
   :dependencies: sysprog.scheduling.realtime,
		  sysprog.posix_threads.mutex,
		  sysprog.posix_threads.lifecycle

.. include:: <mmlalias.txt>


Realtime API
============

.. contents::
   :local:

Scheduling Policies
-------------------

**Scheduling policies** determine the scheduler's way of assigning
CPUs ...

* ``SCHED_OTHER``: the fair world (*runnable* processes are only added
  to pool of all runnables)
* ``SCHED_FIFO`` (First-in first-out)

  * Process gets CPU immediately assigned
  * Remains on CPU until he relinquishes
  * ... or a higher prio process wants CPU

* ``SCHED_RR`` (Round Robin)

  * Like ``SCHED_FIFO``
  * Equal prio processes: short timeslices in round robin order

Scheduling Priorities
---------------------

* 0 ... Reserved for good old fair processes (``SCHED_OTHER``)
* 1 ... lowest realtime priority
* ...
* 99 ... highest realtime priority

What's Runnning On A System?
----------------------------

.. code-block: console

   $ ps -eo pid,rtprio,cmd
     PID RTPRIO CMD
       6      - [kworker/0:0H-mmc_complete]
      13     99 [migration/0]
      14      - [cpuhp/0]                       # hp = hotplug?
      15      - [cpuhp/1]
      16     99 [migration/1]
      20      - [cpuhp/2]
      21     99 [migration/2]
      25      - [cpuhp/3]
      26     99 [migration/3]
      ...
      59     50 [watchdogd]
      70      - [nvme-wq]                       # wq = workqueue
      71      - [nvme-reset-wq]
      72      - [nvme-delete-wq]
      86     50 [irq/48-mmc0]                   # IRQ thread
      88      - [mmc_complete]
      ...
    1143      - sshd: jfasch [priv]
 
Scheduling: System Calls
------------------------

**Manipulating scheduling attributes of a process:**

* `man 2 sched_setscheduler
  <https://man7.org/linux/man-pages/man2/sched_setscheduler.2.html>`__

  .. code-block:: c
    
     int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);
     int sched_getscheduler(pid_t pid);
     
     struct sched_param {
         int sched_priority;
     };

Scheduling: Threads (1)
-----------------------

**Manipulating scheduling attributes of an existing thread:**

* `man 3 pthread_setschedparam
  <https://man7.org/linux/man-pages/man3/pthread_getschedparam.3.html>`__

  .. code-block:: c

     pthread_setschedparam(
         pthread_t thread, int policy,
         const struct sched_param *param);
     pthread_getschedparam(
         pthread_t thread, int *policy,
	 struct sched_param *param);

Scheduling: Threads (2)
-----------------------

**Start a new thread with predefinied scheduling attributes:**

* `man 3 pthread_attr_setschedparam
  <https://man7.org/linux/man-pages/man3/pthread_attr_setschedparam.3.html>`__

  .. code-block:: c

     int pthread_attr_setschedparam(
         pthread_attr_t *attr,
	 const struct sched_param *param);

* `man 3 pthread_attr_setschedpolicy <https://man7.org/linux/man-pages/man3/pthread_attr_setschedpolicy.3.html>`__

  .. code-block:: c

     int pthread_attr_setschedpolicy(
         pthread_attr_t *attr, int policy);


.. _priority-inversion:

Priority Inversion
------------------

* `Wikipedia <https://en.wikipedia.org/wiki/Priority_inversion>`__
* `FreeRTOS
  <https://www.digikey.ee/en/maker/projects/introduction-to-rtos-solution-to-part-11-priority-inversion/abf4b8f7cd4a4c70bece35678d178321>`__

.. image:: priority-inversion.svg

Priority Inversion: Mutex Protocols (1)
---------------------------------------

**Solution, in spoken words:** at the time that C wants the mutex, A
has to carry on |longrightarrow| *protocol* between both, communicated
via the mutex

|longrightarrow| Mutex Attribute

* `man 3 pthread_mutexattr_setprotocol <https://man7.org/linux/man-pages/man3/pthread_mutexattr_setprotocol.3p.html>`__

  .. code-block:: c

     int pthread_mutexattr_setprotocol(
         pthread_mutexattr_t *attr,
	 int protocol);

**Protocols**

* ``PTHREAD_PRIO_INHERIT``: A's priority is temporarily* (until mutex
  is acquired) boosted to B's
* ``PTHREAD_PRIO_PROTECT``: A's priority is temporarily risen to a
  fixed limit |longrightarrow| `man 3 pthread_mutexattr_setprioceiling
  <https://man7.org/linux/man-pages/man3/pthread_mutexattr_setprioceiling.3p.html>`__

