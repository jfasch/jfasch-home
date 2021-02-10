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

      * **Branch** ``my_driver_cdev_dynamic_major``

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

	* **Branch** ``my_driver_cdev_file_operations``

          .. list-table::
             :widths: auto
             :align: left
      
             * - *Topic*
               - :doc:`cdev-file-operations/topic`
             * - *Contents*
               - * History: *static* device numbers
                 * Character device basics
		 * ``struct file_operations``
		 * ``open()``
		 * ``ioctl()`` and ``_IO*()`` macros
             * - *Status*
               - DONE

	  * **Branch** ``my_driver_cdev_first_functionality``
            ``kmalloc()``.

	    * :doc:`/trainings/material/soup/kernel/cdev-first-functionality/topic`
	    * ``<linux/list.h>``
	    * ``kmalloc()`` (dependency)

	    * **Branch** ``my_driver_cdev_refactoring``

	      :doc:`/trainings/material/soup/kernel/cdev-refactoring/topic`

	      Module params

	      * **Branch** ``my_driver_multiple_devices``

		:doc:`/trainings/material/soup/kernel/cdev-multiple-devices/topic`

		* **Branch** ``my_driver_mutex``

                  .. list-table::
                     :widths: auto
                     :align: left
              
                     * - *Topic*
                       -  :doc:`mutex/topic`
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
                         -  :doc:`interrupt/topic`
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
                           - :doc:`spinlock/topic`
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

* `LDD3, O'Reilly
  <https://www.oreilly.com/openbook/linuxdrive3/book/>`__

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

