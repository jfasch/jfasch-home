.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: a demo module to show how a driver
                 creates a character device
   :keywords: schulung, training, linux, kernel, module, character
              device, cdev, device_create

Character Devices (Automatic Node Creation) (Slideshow)
=======================================================

.. contents::
   :local:

Dynamic Device Numbers
----------------------

jjj

* From ``register_chrdev_region()`` to ``alloc_chrdev_region()``

  * blah

https://www.kernel.org/doc/htmldocs/kernel-api/API-alloc-chrdev-region.html

.. code-block:: c

   int alloc_chrdev_region(
       dev_t * dev,
       unsigned baseminor,
       unsigned count,
       const char * name);

Problem: ``mknod`` Parameters?
------------------------------

* Enter ``devtmpfs`` (and ``sysfs``)
* ``/dev`` is-a ``devtmpfs``

* jjj sysfs

Device Classes
--------------



Devices
-------

* ``device_create()``: register character devices with sysfs

  https://www.kernel.org/doc/html/latest/driver-api/infrastructure.html?highlight=device_create#c.device_create

  * return value? |longrightarrow| ``BUG_ON()``
  * Module loading: ``ERROR: Unknown symbol in module``

    * Only exported to modules with GPL compatible license
      |longrightarrow| ``MODULE_LICENSE("GPL");``

