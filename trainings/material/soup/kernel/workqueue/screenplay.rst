.. include:: <mmlalias.txt>

Workqueue (Screenplay)
======================

.. contents::
   :local:

Add Workqueue
-------------

* Clearly per-device
* ``device.{h,c}``

  * ``wq`` member
  * Use ``create_workqueue()``, ``destroy_workqueue()``

.. code-block:: console

   # ps -efl|grep my_driver
   # ps -eo pid,cmd,rtprio,nice

Talk about realtime a bit.

Submit/Defer Work From Atomic Context
-------------------------------------

* ``device.{h,c}``: add ``struct work_struct`` right next to ``wq``
* Dummy work function (``printk()``)
* ``INIT_WORK()`` in device ctor
* Submit from atomic

  * Interrupt
  * Timer callback

* Check if called

.. code-block:: console

   # chrt -p 20 <pid>

Finish
------

* Interrupts at high rate (e.g. from a bouncing switch)
  |longrightarrow| some are dropped
* We did this to get rid of the spinlock

  * |longrightarrow| re-introduce mutex
