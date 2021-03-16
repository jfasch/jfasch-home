.. include:: <mmlalias.txt>

Workqueue (Slideshow)
=====================

.. contents::
   :local:

Workqueue: Motivation
---------------------

* Kernel thread |longrightarrow| has a process ID, and is thus
  schedulable
* |longrightarrow| *process context*
* Commonly used to defer (postpone) work from atomic context
* Optional thread pool: one work queue per CPU

Creating/Destroying a Workqueue
-------------------------------

.. code-block:: c

   #include <linux/workqueue.h>

   struct workqueue_struct* create_workqueue(const char* name);
   void destroy_workqueue(struct workqueue_struct* wq);

What is Work?
-------------

.. code-block:: c
   :caption: ``struct work_struct``

   #include <linux/workqueue.h>

   struct work_struct;
   typedef void (*work_func_t)(struct work_struct *work);
   INIT_WORK(struct work_struct* work, work_func_t);

* Basically, a function pointer
* Usually part of a larger structure

  * |longrightarrow| ``container_of()``-like dance

Submitting Work
---------------

.. code-block:: c

   #include <linux/workqueue.h>

   bool queue_work(struct workqueue_struct* wq, struct work_struct* work);

* *Returns* ``false`` if work is already submitted (and doesn't submit
  it again)
* *Returns* ``true`` if work has been successfully submitted

**What's this?**

* Work cannot be submitted twice, with different parameters
* Typically used to call a function on something which *contains* work
  (|longrightarrow| ``container_of()``)
* Function has to decide itself
