.. include:: <mmlalias.txt>

Accessing Userspace Memory (Slideshow)
======================================

.. contents::
   :local:


Address Spaces
--------------

**User Address Space**

* MMU programmed (configured) *per-process*
* Context switch includes re-programming MMU
* |longrightarrow| *Memory access violations*

**Kernel Address Space**

* Kernel can see all memory
* Userspace addresses?

Copying To and From Userspace
-----------------------------

.. code-block:: c

   #include <linux/uaccess.h>

   unsigned long copy_to_user(void __user * to,
                              const void * from,
 			      unsigned long n);
   unsigned long copy_from_user(void * to,
                                const void __user * from,
 				unsigned long n);

* Returns number of bytes *not transferred* |longrightarrow| 0 is ok
* Usually used directly in ``ioctl()`` implementation

  * |longrightarrow| return ``-EFAULT`` when soemthing has not been
    transferred
  * |longrightarrow| Calling process segfaults

Documentation
-------------

.. list-table::
   :widths: auto
   :align: left

   * * `copy_from_user
       <https://www.kernel.org/doc/htmldocs/kernel-api/API---copy-from-user.html>`__
   * * `copy_to_user
       <https://www.kernel.org/doc/htmldocs/kernel-api/API---copy-to-user.html>`__


