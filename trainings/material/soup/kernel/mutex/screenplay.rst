.. include:: <mmlalias.txt>

Fighting Parallelism: Mutex (Screenplay)
========================================

.. contents::
   :local:

Protect Event List
------------------

.. code-block:: c
 
   struct my_event_list
   {
       struct mutex lock;
       struct list_head events;
       unsigned nevents;
   };

* Init in ``init()``
* ``destroy()``: how can that be called in parallel?
* Protect all other methods
* ``kmalloc()`` outside critical section?

Protect Device List
-------------------

.. code-block:: c
 
   struct my_device_list
   {
       struct mutex lock;
       struct list_head devices;
   };

* Just the same
* Take care of multiple return paths
