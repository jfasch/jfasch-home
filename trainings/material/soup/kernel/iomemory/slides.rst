.. include:: <mmlalias.txt>


IO Memory (Slideshow)
=====================

.. contents::
   :local:

I/O Memory
----------

**Device registers mapped into memory**

* Access is transparent to software
* Just like ordinary memory
* ... but the device listens
* |longrightarrow| side effects

**Implications**

* Performance optimization are made at every level
  
  * Compiler may reorder memory access
  * CPU may reorder memory access

* |longrightarrow| May twist order of access that's expected by device

I/O Memory: Reservation
-----------------------

**Memory "regions"**

* Reserved by drivers (physical address, length)
* Protection against accidental overlapping access
* Shows up in ``/proc/iomem``
* No effect otherwise

  * Access works without
  * *But: no reason not to use it*

.. code-block:: c

   #include <linux/ioport.h>
   
   struct resource *resource = request_mem_region(
      0x20200000, 180, "my-weird-driver");
   release_mem_region(0x20200000, 180);

Making I/O Memory Accessible
----------------------------

**I/O memory** ...

* Not directly accessible (as is physical memory in general)
* Not managed by ``struct page`` (|longrightarrow| later)
* *I/O Memory Mapping* must be created

.. code-block:: c

   #include <asm/io.h>
   
   void *base = ioremap(0x20200000, 180);
   iounmap(base);

Accessing I/O Memory
--------------------

**Set of access functions** that insert the right compiler and memory
barriers ...

* Reading

  * ``unsigned int ioread8(void *addr);``
  * ``unsigned int ioread16(void *addr);``
  * ``unsigned int ioread32(void *addr);``

* Writing

   * ``void iowrite8(u8 value, void *addr);``
  * ``void iowrite16(u16 value, void *addr);``
  * ``void iowrite32(u32 value void *addr);``

... and a lot more
