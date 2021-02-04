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
	   - 


      #. major/minor numbers |longrightarrow| ``/proc/devices``
      #. Character devices, all manual |longrightarrow| ``mknod``

      * ``my_driver_module_params``. Major number as module parameter.
      * ``my_driver_cdev_dynamic_major``. :doc:`cdev-auto/topic`.
        ``sysfs``, class, device, blah.

	* ``my_driver_cdev_file_operations``. ``struct
 	  file_operations``.

	  Only dummy operations

	  * ``my_driver_cdev_first_functionality``. ``linux/list.h``,
            ``kmalloc()``.

	    * ``my_driver_cdev_refactoring``

	      :doc:`/trainings/material/soup/kernel/cdev-refactoring/topic`

	      * ``my_driver_multiple_devices``

		:doc:`/trainings/material/soup/kernel/cdev-multiple-devices/topic`

		* ``my_driver_mutex``

		  :doc:`/trainings/material/soup/kernel/mutex/topic`

		  * ``my_driver_interrupt``. Move to raspi, see how
                    cross compilation works.

		    :doc:`/trainings/material/soup/kernel/interrupt/topic`

Links
-----

jjj clean this up

* https://www.kernel.org/doc/
* https://www.kernel.org/doc/html/latest/

  blah search blah sphinx blah

To Do List
----------

* Aggregate ``_morph/`` branches top-level
* Bring source code into slides/screenplays
* Userspace/kernel picture from sysprog.
* In topics that refer to github code, mention branch where code is
  maintained. (code-block caption)
* SEO

  * ``meta`` everywhere
  * sidebars with backlinks to this document
  * this document: course description

