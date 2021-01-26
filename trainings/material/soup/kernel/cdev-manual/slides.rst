.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: a demo module for basic character device
                 usage
   :keywords: schulung, training, linux, kernel, module, character
              device, cdev, mknod, alloc_chrdev_region

Character Devices (Manual Node Creation) (Slideshow)
====================================================

.. contents::
   :local:

Major and Minor Numbers: User's View
------------------------------------

jjj 

* See how ``/dev/mem`` has ``major=1``, ``minor=1``
* Refer to ``/dev/null``: ``drivers/char/mem.c``
* It's the numbers that count, not the names (``/dev/mem``)
* ``mknod blah c 1 3`` |longrightarrow| ``/dev/null``

Major and Minor Numbers: Kernel Space
-------------------------------------

jjj

dev_t

MINOR
MAJOR
MKDEV

Device Numbers: Hardcoding
--------------------------

* old way: hardcoded major
* Refer to ``/dev/null``: ``drivers/char/mem.c``

jjjj

.. code-block:: c

   int register_chrdev_region(dev_t, unsigned count, const char* drivername);
   void unregister_chrdev_region(dev_t, unsigned count);

jjj see livehacking blah ENXIO

Character Device
----------------

jjj man pages

* ``cdev_init()``: fops blah later
* ``cdev_add()``: attention device is live/hot immediately








