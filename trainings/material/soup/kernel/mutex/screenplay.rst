.. include:: <mmlalias.txt>

Mutex (and RT Mutex) (Screenplay)
=================================

.. contents::
   :local:

What Do We Have?
----------------

**Drawing**

* list of devices
* list of events per device
* all doubly linked lists

**Hm ... what if we add events concurrently?**

Consequences of Not Protecting
------------------------------

.. code-block:: console
   :caption: 10 processes hammer on poor event list 0

   # for _ in $(seq 10); do
   >  while true; do
   >   ./test-inject-event 0
   >  done&
   > done

.. code-block:: console
   :caption: Hell breaks loose ...

   Nov 21 16:28:41 opfer kernel: list_del corruption. next->prev should be ffff91285ae68f00, but was ffff9128406cec00
   Nov 21 16:28:41 opfer kernel: ------------[ cut here ]------------
   Nov 21 16:28:41 opfer kernel: kernel BUG at lib/list_debug.c:54!
   ...
   Nov 21 16:28:41 opfer kernel: Call Trace:
   Nov 21 16:28:41 opfer kernel:  my_event_list_add+0x70/0xb0 [my_driver]
   Nov 21 16:28:41 opfer kernel:  my_ioctl+0x4c/0xdd [my_driver]
   Nov 21 16:28:41 opfer kernel:  ksys_ioctl+0x82/0xc0
   Nov 21 16:28:41 opfer kernel:  __x64_sys_ioctl+0x16/0x20
   Nov 21 16:28:41 opfer kernel:  do_syscall_64+0x4d/0x90
   Nov 21 16:28:41 opfer kernel:  entry_SYSCALL_64_after_hwframe+0x44/0xa9
   ...

Problem
-------

* Event list: *(doubly) linked list*
* Hammered on by 10 processes, in parallel
* Just like a toilet with no lock on the door
* |longrightarrow| **deploy lock!**

  * Best to put it into the data structure that it will protect

* Device list is also unprotected - somebody might add devices
  concurrently

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
* ``kmalloc()`` outside critical section!

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
