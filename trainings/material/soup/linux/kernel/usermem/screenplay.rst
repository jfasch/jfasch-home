.. include:: <mmlalias.txt>

Accessing Userspace Memory (Screenplay)
=======================================

.. contents::
   :local:

New ``ioctl``: ``GET_ONE_EVENT``
--------------------------------

* Add ioctl
* Wonder what the output parameter could be |longrightarrow|
  discussion

  * An event, obviously
  * ``struct my_event`` has ``list_head`` member |longrightarrow| only
    valid in kernel
  * Extract user-relevant data into ``misc.h``: ``struct my_event`` is
    for *user*, struct ``my_event_node`` is for *kernel*

Getting One Event
-----------------

Start out like so ...

.. code-block:: c

   case MY_GET_ONE_EVENT: {
       if (dev->events.nevents > 0) {
           ...
       }
   }

* |longrightarrow| *race condition*
* |longrightarrow| new method ``bool my_device_get_one_event()``

  * |longrightarrow| new method ``bool my_event_get_one_event()``

``copy_to_user()``
------------------

* Draw diagram, *user space memory*
* Use ``copy_to_user()`` to transfer event to userspace

  * ``-EFAULT``

Userspace Test Program
----------------------

* trivial
