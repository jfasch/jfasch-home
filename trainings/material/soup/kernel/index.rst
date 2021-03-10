.. include:: <mmlalias.txt>

Kernel Hacking
==============

.. contents::
   :local:

A put-together of kernel related topics.

Contents
--------

.. toctree::
   :maxdepth: 1
   :glob:

   */topic

Group Description
-----------------

.. jf-group:: kernel

.. jf-topicgraph::
   :entries: kernel

Sample Code Maintenance
-----------------------

* Github repo `here <https://github.com/jfasch/jf-kernel-course>`__
* Directory ``_morph`` holds ``my_driver.c``, which is the base for
  livehacking sessions
* ``my_driver.c`` is morphed as we go
* Branch *tree* (not merged back)

  * **Branch** ``my_driver_hello``

    .. list-table::
       :widths: auto
       :align: left

       * - *Topic*
	 - :doc:`hello-world/topic`
       * - *Branch*
	 - `my_driver_hello <https://github.com/jfasch/jf-kernel-course/tree/my_driver_hello>`__
       * - *Contents*
	 - * The root of everything
	   * ``Makefile``, build
	   * Module loading, ``init()``, ``exit()``.
       * - *Status*
	 - DONE

  * **Branch** ``my_driver_cdev_manual``

    .. list-table::
       :widths: auto
       :align: left

       * - *Topic*
         -  :doc:`cdev-manual/topic`
       * - *Branch*
	 - `my_driver_cdev_manual <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_manual>`__
       * - *Contents*
         - * History: *static* device numbers
           * Character device basics
       * - *Status*
         - DONE

  * **Branch** ``my_driver_cdev_dynamic_major``

    .. list-table::
       :widths: auto
       :align: left

       * - *Topic*
         -  :doc:`cdev-auto/topic`
       * - *Branch*
	 - `my_driver_cdev_dynamic_major <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_dynamic_major>`__
       * - *Contents*
         - * *Dynamic* device number allocation
           * ``devtmpfs`` and ``sysfs``
       * - *Status*
         - ...

  * **Branch** ``my_driver_cdev_file_operations``

    .. list-table::
       :widths: auto
       :align: left

       * - *Topic*
         - :doc:`cdev-file-operations/topic`
       * - *Branch*
	 - `my_driver_cdev_file_operations <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_file_operations>`__
       * - *Contents*
         - * History: *static* device numbers
           * Character device basics
	   * ``struct file_operations``
	   * ``open()``
	   * ``ioctl()`` and ``_IO*()`` macros
       * - *Status*
         - DONE

  * **Branch** ``my_driver_cdev_first_functionality``

    .. list-table::
       :widths: auto
       :align: left

       * - *Topic*
         - :doc:`cdev-first-functionality/topic`
       * - *Branch*
	 - `my_driver_cdev_first_functionality <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_first_functionality>`__
       * - *Contents*
	 - * Doubly linked list
	   * Basic OO
	   * Simple ``ioctl``
	   * Userspace ``ioctl`` usage
       * - *Status*
         - DONE

  * **Branch** ``my_driver_cdev_refactoring``

    .. list-table::
       :widths: auto
       :align: left

       * - *Topic*
         - :doc:`cdev-refactoring/topic`
       * - *Branch*
	 - `my_driver_cdev_refactoring <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_refactoring>`__
       * - *Contents*
	 - * Separate files
	   * *My Device* encapsulation of matters
	   * *My Device* as ``filp->private_data``
       * - *Status*
         - DONE

  * **Branch** ``my_driver_multiple_devices``

    .. list-table::
       :widths: auto
       :align: left

       * - *Topic*
         - :doc:`cdev-multiple-devices/topic`
       * - *Branch*
	 - `my_driver_multiple_devices <https://github.com/jfasch/jf-kernel-course/tree/my_driver_multiple_devices>`__
       * - *Contents*
	 - ...
       * - *Status*
         - ...

  * **Branch** ``my_driver_mutex``
 
    .. list-table::
       :widths: auto
       :align: left

       * - *Topic*
         -  :doc:`mutex-coding/topic`
       * - *Branch*
	 - `my_driver_mutex <https://github.com/jfasch/jf-kernel-course/tree/my_driver_mutex>`__
       * - *Contents*
         - * Race on unprotected lists
           * Mutex
	   * RT mutex
	   * "Interruptible"
       * - *Status*
	 - DONE

  * **Branch** ``my_driver_interrupt``
  
    .. list-table::
       :widths: auto
       :align: left
  
       * - *Topic*
	 -  :doc:`interrupt-coding/topic`
       * - *Branch*
	 - `my_driver_interrupt <https://github.com/jfasch/jf-kernel-course/tree/my_driver_interrupt>`__
       * - *Contents*
         - * Short GPIO introduction |longrightarrow|
             move to Raspi
           * Request and free IRQ
  	   * *Atomic*?
       * - *Status*
         - DONE

  * **Branch** ``my_driver_spinlock_atomic``.
  
    .. list-table::
       :widths: auto
       :align: left
  
       * - *Topic*
         - :doc:`spinlock-coding/topic`
       * - *Branch*
	 - `my_driver_spinlock_atomic <https://github.com/jfasch/jf-kernel-course/tree/my_driver_spinlock_atomic>`__
       * - *Contents*
         - * Spinlock usage
  	   * Spinlock caveats (sleep/atomic)
       * - *Status*
         - DONE
  
  * **Branch** ``my_driver_time_timer``.
  
    .. list-table::
       :widths: auto
       :align: left
  
       * - *Topic*
         - :doc:`time_timer-coding/topic`
       * - *Branch*
	 - `my_driver_time_timer <https://github.com/jfasch/jf-kernel-course/tree/my_driver_time_timer>`__
       * - *Contents*
         - * ``jiffies``
           * Timer wheel methods
       * - *Status*
         - DONE
  
  * **Branch** ``my_driver_workqueue``.
  
    .. list-table::
       :widths: auto
       :align: left
  
       * - *Topic*
         - :doc:`workqueue/topic`
       * - *Branch*
	 - `my_driver_workqueue <https://github.com/jfasch/jf-kernel-course/tree/my_driver_workqueue>`__
       * - *Contents*
         - * Workqueue
	   * Getting rid of atomic code
	   * Realtime priorities
       * - *Status*
         - DONE
  
  * **Branch** ``my_driver_usermem``.
  
    .. list-table::
       :widths: auto
       :align: left
  
       * - *Topic*
  	 - :doc:`usermem/topic`
       * - *Branch*
	 - `my_driver_usermem <https://github.com/jfasch/jf-kernel-course/tree/my_driver_usermem>`__
       * - *Contents*
         - * ``copy_{to,from}_user()``
       * - *Status*
         - DONE
 
  * **Branch** ``my_driver_waitqueue``.
 
    .. list-table::
       :widths: auto
       :align: left
 
       * - *Topic*
 	 - :doc:`waitqueue/topic`
       * - *Branch*
	 - `my_driver_waitqueue <https://github.com/jfasch/jf-kernel-course/tree/my_driver_waitqueue>`__
       * - *Contents*
 	 - * Wait queues
           * Blocking vs. nonblocking ``read()``
 	   * ``EAGAIN`` and EOF
 
       * - *Status*
         - DONE
 
Links
-----

* https://www.kernel.org/doc/
* https://www.kernel.org/doc/html/latest/
* `LDD3, O'Reilly
  <https://www.oreilly.com/openbook/linuxdrive3/book/>`__

To Do List
----------

* Networking

  https://www.cs.dartmouth.edu/~sergey/netreads/path-of-packet/Lab9_modified.pdf

* :download:`Kernel </trainings/material/pdf/400-kernel.pdf>`

  * Topic "Kernel Source"
  * "Kernel Modules"? Probably aggregate into :doc:`hello-world/topic`
  * "Kernel Internals"?

  * 0520-kernel-communication
  * 0521-kernel-kmalloc (GFP etc, **depend interrupts on it**)
  * 0525-kernel-io-memory
  * 0532-kernel-threaded-interrupts
  * 0710-kernel-preempt-rt

* Aggregate ``_morph/`` branches top-level
* Bring source code into slides/screenplays
* Userspace/kernel picture from sysprog.
* In topics that refer to github code, mention branch where code is
  maintained. (code-block caption)
* SEO

  * ``meta`` everywhere
  * sidebars with backlinks to this document
  * this document: course description

