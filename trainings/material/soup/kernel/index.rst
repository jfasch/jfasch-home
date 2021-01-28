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

  * ``my_driver_hello``. :doc:`hello-world/topic`. 

    The root of everything. Module loading, ``init()``, ``exit()``.

    * ``my_driver_cdev_manual``. :doc:`cdev-manual/topic`

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

