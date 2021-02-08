.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: a demo module for basic character device
                 usage
   :keywords: schulung, training, linux, kernel, module, character
              device, cdev, mknod, alloc_chrdev_region

Character Device Basics (Slideshow)
===================================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_cdev_manual/_morph>`__

Major and Minor Numbers: User's View
------------------------------------

.. code-block:: console

  $ ls -l /dev/{mem,null}
  crw-r-----. 1 root kmem 1, 1 Jan 18 13:29 /dev/mem
  crw-rw-rw-. 1 root root 1, 3 Jan 18 13:29 /dev/null

* See how ``/dev/mem`` has ``major=1``, ``minor=1``
* Refer to ``/dev/null``: ``drivers/char/mem.c``
* It's the numbers that count, not the names (``/dev/mem``)
* ``mknod blah c 1 3`` |longrightarrow| ``/dev/null``

Major and Minor Numbers: Kernel Space
-------------------------------------

* ``dev_t``: an opaque *thing* (``unsigned int``)
* Holds major and minor numbers

.. code-block:: console

   #include <linux/cdev.h>

   dev_t majmin = MKDEV(1,3);
   unsigned major = MAJOR(majmin);
   unsigned minor = MINOR(majmin);

History: Hardcoded Device Numbers (1)
-------------------------------------

Before going public with a character device,

* Reserve its major number
* ... together with a range of minor numbers

.. code-block:: c

   #include <linux/fs.h>

   int register_chrdev_region(dev_t, unsigned count, const char* drivername);
   void unregister_chrdev_region(dev_t, unsigned count);

.. sidebar:: Documentation

   .. list-table::
      :widths: auto
      :align: left
   
      * * `register_chrdev_region
          <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=register_chrdev_region#c.register_chrdev_region>`__
   
      * * `unregister_chrdev_region
          <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=register_chrdev_region#c.unregister_chrdev_region>`__

History: Hardcoded Device Numbers (2)
-------------------------------------

.. code-block:: c
   :caption: Reserve numbers for the ``mem`` driver

   err = register_chrdev_region(MKDEV(1, 1), 17, "mem");
   if (err) ...

This reserves the range ``(1,1)`` to ``(1,17)``

.. code-block:: c
   :caption: Free numbers

   unregister_chrdev_region(MKDEV(1,3), 17);

Character Device (1)
--------------------

Once we have the device numbers guaranteed, a *device* is created.

.. code-block:: c

   #include <linux/cdev.h>
   #include <linux/fs.h> /*struct file_operations*/

   void cdev_init(struct cdev *cdev, const struct file_operations *fops);
   int cdev_add(struct cdev *p, dev_t dev, unsigned count);
   void cdev_del(struct cdev *p);

* ``cdev_init()`` initializes a ``struct cdev``
* ``cdev_add()`` goes live with it (``dev`` and ``count`` semantics as
  in ``register_chrdev_region()``)
* ``cdev_del()`` is the inverse of ``cdev_add()``

.. sidebar:: Documentation

   .. list-table::
      :widths: auto
      :align: left
   
      * * `cdev_init
          <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=cdev_init#c.cdev_init>`__
      * * `cdev_add
          <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=cdev_add#c.cdev_add>`__
      * * `cdev_del
          <https://www.kernel.org/doc/html/latest/core-api/kernel-api.html?highlight=cdev_del#c.cdev_del>`__

Character Device (2)
--------------------

.. code-block:: c

   #include <linux/cdev.h>
   #include <linux/fs.h>

   struct file_operations my_fops = { ... };
   struct cdev my_cdev;

   cdev_init(&my_cdev, &my_fops);
   err = cdev_add(&my_cdev, MKDEV(1, 1), 17);
   if (err) ...

And User Space?
---------------

**So what?**

* ``cdev_add()`` *goes live* with the device
* We only see pairs of ``(major,minor)`` in the driver code
* ``major`` is the driver's "ID"
* ``minor`` is the "functionality" within that driver
* *So how does a user reach the device ``(1,3)``*?

**Answer**

.. code-block:: console

   # mknod /some/path/to/devicefile c 1 3
