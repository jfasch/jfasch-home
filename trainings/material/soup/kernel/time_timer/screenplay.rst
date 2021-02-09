.. include:: <mmlalias.txt>

Timer Management (Screenplay)
=============================

.. contents::
   :local:

Per-Event Timestamp
-------------------

* Realtime vs. monotonic
* ``jiffies`` is *current monotonic time*
* Modify ``my_event``

  * have a timestamp in ``jiffies`` form
  * determined in ``my_event_list_add()``

Discussion: Deferred Events
---------------------------

* ``ioctl()`` to add a deferred event
* Can we have multiple deferred events pending?

  * |longrightarrow| lets have only one for now. Otherwise we'd have
    to maintain a list somehow.

* Who's responsible for maintaining the timer/work?

  * |longrightarrow| ``struct my_device``

Add Timer
---------

* New ``ioctl``: ``MY_INJECT_DEFERRED_EVENT``, a milliseconds
  parameter
* ``my_device_add_deferred_event()``
* Userspace: ``test-inject-deferred-event.c``
* Test

Gotcha: Cleanup Running Timer
-----------------------------

* Inject deferred event: 10s
* ``rmmod my_driver``
* Wait until panic

**Fix**

* ``my_device_destroy()``: ``del_timer_sync()``

**Questions**

* What if somebody injects an event while a deferred event is pending?

  * Try it out |longrightarrow| panic

* What if no event is pending altogether? Can I delete a timer that is
  not running? (Documentation is not at all clear |longrightarrow|
  paranoia)

  * Try it out |longrightarrow| work (appears to work)

**Answer**

* Naive: flag and *no locking*
* *Bad* |longrightarrow| Spinlock (timers run in interrupt context)





* Refact (symmetry): ``my_device_add_event()``, and call that from
  ``MY_INJECT_EVENT``
