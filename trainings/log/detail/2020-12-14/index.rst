.. include:: <mmlalias.txt>

Linux Kernel Driver Development Basics (14.12.2020)
===================================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Start**

   (To be negotiated)

   **Official Description**

   :doc:`/trainings/repertoire/kernel-programming-basics`

   **Material**

   * `Github Repository <https://github.com/jfasch/jf-kernel-course>`__

Agenda
------

The training will be based upon
:doc:`/trainings/repertoire/kernel-programming-basics`.

* **Modules**

  * Driver initialization and deinitialization
  * Module loading and unloading

* **Devices**

  * Device special files
  * ``sysfs``
  * Communicating with user space

* **Synchroniztion Mechanisms**.

  * Semaphore
  * Mutex
  * Spinlock
  * Read Copy Update (RCU)

* **Communication Mechanisms**: Wait Queues
* **Interrupt Handling and "Bottom Halves"**

  * SoftIRQ
  * Tasklet
  * Threaded IRSs

* **Memory management**

  * ``kmalloc()`` and friends
  * Accessing user space memory

* `DMA API
  <https://www.kernel.org/doc/Documentation/DMA-API-HOWTO.txt>`__

  * Physical and virtual CPU addresses
  * DMA/Bus addresses
  * DMA mappings: *consistent/coherent* vs. *streaming*

* **PCI Subsystem**

  * Device initialization
  * Register ("BAR") access

* Das Network-Subsystem/NAPI

Books
-----

* `Linux Device Drivers, Third Edition
  <https://lwn.net/Kernel/LDD3/>`__
