.. include:: <mmlalias.txt>

Fighting Parallelism: Mutex (Slideshow)
=======================================

.. contents::
   :local:

jjj Todo
--------

:download:`Kernel </trainings/material/pdf/400-kernel.pdf>`

* nested? recursive?
* interruptible?
* realtime mutex? stub topic for riority inheritance/inversion.
* trylock?

What Do We Have?
----------------

**jjj drawing**

* list of devices
* list of events per device
* all doubly linked lists

**Hm ... what if we add events concurrently?**

.. code-block:: console

   # for _ in $(seq 10); do
   >  while true; do
   >   ./test-inject-event 0
   >  done&
   > done

|longrightarrow| 10 processes hammer on poor event list 0

Consequences of Not Protecting
------------------------------

**Hell breaks loose ...**

.. code-block:: console

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

Enter Mutex
-----------

.. code-block:: c
   :caption: Type

   #include <linux/mutex.h>

   struct mutex my_mutex;

.. code-block:: c
   :caption: (Basic) operations

   mutex_init(&my_mutex);
   mutex_destroy(&my_mutex);
   mutex_lock(&my_mutex);
   mutex_lock_interruptible();
   mutex_lock_interruptible_nested();
   mutex_unlock(&my_mutex);

Usage?
------

**Problem:**

* Event list: *(doubly) linked list*
* Hammered on by 10 processes, in parallel
* Just like a toilet with no lock on the door
* |longrightarrow| **deploy lock!**

  * Best to put it into the data structure that it will protect

* Device list is also unprotected - somebody might add devices
  concurrently

(|longrightarrow| :doc:`screenplay`)
