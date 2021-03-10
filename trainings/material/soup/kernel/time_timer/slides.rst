.. include:: <mmlalias.txt>

Timer Management (Slideshow)
============================

.. contents::
   :local:

Original Timer API
------------------

* "Timer wheel"
* relies on ``jiffies`` (ticks per second, ``CONFIG_HZ``)
* updated by periodic timer tick
* |longrightarrow| not power friendly
* |longrightarrow| not very fine grained (100 - 1000 Hz)
* But simple!

.. attention::

   Timer callbacks run in *atomic* context!

``jiffies``
-----------

* Representation of *now*
* Updated by timer tick
* Nowadays, ``jiffies`` is maintained by the ``hrtimer`` subsystem

.. code-block:: c

   #include <linux/jiffies.h>

   extern unsigned long volatile jiffies;

   extern unsigned int jiffies_to_msecs(const unsigned long j);
   extern unsigned int jiffies_to_usecs(const unsigned long j);
   u64 jiffies_to_nsecs(const unsigned long j);
   unsigned long msecs_to_jiffies(const unsigned int m);
   unsigned long usecs_to_jiffies(const unsigned int u);
   long timespec64_to_jiffies(const struct timespec64 *value);
   void jiffies_to_timespec64(const unsigned long jiffies, struct timespec64 *value);

"Timer Wheel" Methods
---------------------

.. code-block:: c

   #include <linux/timer.h>

   struct timer_list my_timer;
   void timerfunc(struct timer_list *timer) { ... }

   void timer_setup(struct timer_list* timer, timerfunc, unsigned flags);
   void add_timer(struct timer_list* timer);
   int del_timer(struct timer_list *timer)   
   int del_timer_sync(struct timer_list *timer)

* ``del_timer_sync()`` waits until handler has finished running on any
  CPU
* ``my_timer.expires``: set to *absolute monotonic* jiffies
  (``expires`` = *number of jiffies from boot* into the future)

High Resolution Timers
----------------------

* `LWN article <https://lwn.net/Articles/167897/>`__
