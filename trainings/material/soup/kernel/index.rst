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
         * - *Contents*
           - * History: *static* device numbers
             * Character device basics
         * - *Status*
           - DONE

      * **Branch**
        ``my_driver_cdev_dynamic_major``. :doc:`cdev-auto/topic`.
        ``sysfs``, class, device, blah.

        .. list-table::
	   :widths: auto
           :align: left
    
           * - *Topic*
             -  :doc:`cdev-auto/topic`
           * - *Contents*
             - * *Dynamic* device number allocation
               * ``devtmpfs`` and ``sysfs``
           * - *Status*
             - ...

	* **Branch** ``my_driver_cdev_file_operations``. ``struct
 	  file_operations``.

	  :doc:`/trainings/material/soup/kernel/cdev-file-operations/topic`
          (only dummy operations)

	  * **Branch** ``my_driver_cdev_first_functionality``. ``linux/list.h``,
            ``kmalloc()``.

	    :doc:`/trainings/material/soup/kernel/cdev-first-functionality/topic`

	    * **Branch** ``my_driver_cdev_refactoring``

	      :doc:`/trainings/material/soup/kernel/cdev-refactoring/topic`

	      Module params

	      * **Branch** ``my_driver_multiple_devices``

		:doc:`/trainings/material/soup/kernel/cdev-multiple-devices/topic`

		* **Branch** ``my_driver_mutex``

		  :doc:`/trainings/material/soup/kernel/mutex/topic`

		  * **Branch** ``my_driver_interrupt``. Move to raspi,
                    see how cross compilation works.

		    :doc:`/trainings/material/soup/kernel/interrupt/topic`

                    * **Branch** ``my_driver_spinlock_atomic``.
  
                      :doc:`/trainings/material/soup/kernel/spinlock-atomic/topic`

		      * **Branch** ``my_driver_time_timer``.
  
                        .. list-table::
                           :widths: auto
                           :align: left
                    
                           * - *Topic*
                             - :doc:`time_timer/topic`
                           * - *Contents*
                             - * ``jiffies``
                               * Timer wheel methods
                           * - *Status*
                             - DONE

Links
-----

jjj clean this up

* https://www.kernel.org/doc/
* https://www.kernel.org/doc/html/latest/

  blah search blah sphinx blah

To Do List
----------

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

