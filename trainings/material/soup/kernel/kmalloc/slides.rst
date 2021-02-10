.. include:: <mmlalias.txt>

.. meta::
   :description: Slide deck: dynamic memory handling in the Linux
                 kernel
   :keywords: schulung, training, linux, kernel, kmalloc kfree,
              dynamic memory, memory, atomic

Dynamic Memory: ``kmalloc()`` (Slideshow)
=========================================

Dynamic Memory: ``kmalloc()``
-----------------------------

**Kernel heap implementation**

* Similar to userspace ``malloc()``
* |longrightarrow| Easy to use

.. code-block:: c

   #include <linux/slab.h>
   #include <linux/gfp.h>

   void *kmalloc(size_t size, gfp_t flags);
   void *kzalloc(size_t size, gfp_t flags)
   void kfree(const void *);

* Memory internally/transparently managed as set of pages
* Pages are not necessarily contiguous
* ``size`` greater than page size might be more difficult to allocate
* ``kzalloc()`` initializes memory with all zeroes

Dynamic Memory: Flags
---------------------

**Many flags to govern behaviour** ...

* ``GFP_KERNEL``: most commonly used

  * Might block (triggers swap activity, ...)
  * |longrightarrow| *can only be called in process context*

* ``GFP_ATOMIC``: for use in non-process context

  * Scarce resource
  * |longrightarrow| use is discouraged
  * |longrightarrow| later

Documentation
-------------

.. list-table::
   :widths: auto
   :align: left

   * * `kmalloc
       <https://www.kernel.org/doc/html/latest/core-api/mm-api.html?highlight=kmalloc#c.kmalloc>`__
   * * `kfree <https://www.kernel.org/doc/html/latest/core-api/mm-api.html?highlight=kfree#c.kfree>`__
   * * `kzalloc <https://www.kernel.org/doc/html/latest/core-api/mm-api.html?highlight=kzalloc#c.kzalloc>`__
