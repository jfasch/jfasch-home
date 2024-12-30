.. include:: <mmlalias.txt>

DMA (Slideshow)
===============

.. contents::
   :local:

For a much more comprehensive guide see

* https://www.kernel.org/doc/Documentation/DMA-API-HOWTO.txt
* https://www.kernel.org/doc/html/latest/core-api/dma-api.html


Address Types
-------------

* *Virtual address*

  * Everyting that can be accessed through pointers
  * |longrightarrow| MMU knows about it
  * Result of ``kmalloc()``, ``vmalloc()``, and friends

* *Physical address*

  * Not directly accessed by anyone
  * ``unsigned long``, usually
  * Used for example as input to mapping functions like ``ioremap()``
    (creates a *virtual address* to represent what is otherwise not
    accessible)

* *Device address*, or *DMA address*, *bus address*

  * Main memory address as seen by the device
  * Conceptually a mapping just like the MMU mapping

    * IOMMU in intelligent systems
    * Direct access to pysical addresses (*null* mapping) in dumb
      systems

  * ``dma_addr_t``

Physical Memory Allocation
--------------------------

Typically done in *page* granularity [#alloc_page]_ ...

.. list-table::
   :widths: auto
   :align: left

   * - ``struct page* alloc_page(unsigned int gfp_mask)``
     - Allocate a single page and return a struct address
   * - ``struct page* alloc_pages(unsigned int gfp_mask, unsigned int order)``
     - Allocate 2**order number of pages and returns a struct page
   * - ``unsigned long get_free_page(unsigned int gfp_mask)``
     - Allocate a single page, zero it and return a virtual address
   * - ``unsigned long __get_free_page(unsigned int gfp_mask)``
     -  Allocate a single page and return a virtual address
   * - ``unsigned long __get_free_pages(unsigned int gfp_mask, unsigned int order)``
     - Allocate 2order number of pages and return a virtual address
   * - ``struct page * __get_dma_pages(unsigned int gfp_mask, unsigned int order)``
     - Allocate 2**order number of pages from the DMA zone and return a struct page

Freeing is done using a similar set of functions ...

.. list-table::
   :widths: auto
   :align: left

   * - ``void __free_pages(struct page *page, unsigned int order)``
     - Free an order number of pages from the given page
   * - ``void __free_page(struct page *page)``
     - Free a single page
   * - ``void free_page(void *addr)``
     - Free a page from the given virtual address

DMA Mappings: Overview
----------------------

.. code-block:: c

   #include <linux/dma-mapping.h>

* *Consistent* (or *coherent*) mapping

  * Accessible in both directions; visible without any explicit flush
    operations
  * Usually set up at device/driver initialization time, to exchange
    management information such as DMA addresses for further
    streaming.

* *Streaming* mappings

  * Have a direction (to/from device)
  * Writes are not guaranteed to be visible to the receiving party
    (|longrightarrow| explicit flush)
  * Flush at "DMA done" interrupt (from device)
  * FLush by CPU (to device), usually signalled to the device by
    writing a device register

Consistent DMA Mappings
-----------------------

.. code-block:: c

   dma_addr_t dma_handle;

   void* cpu_addr = dma_alloc_coherent(dev, size, &dma_handle, gfp);
   dma_free_coherent(dev, size, cpu_addr, dma_handle);   

* ``dev``: ``struct device*`` (contained inside ``struct pci_dev`` and
  others)
* ``gfp``: ``GFP_KERNEL``, ``GFP_ATOMIC``, ...

Streaming Mappings: Direction
-----------------------------

*DMA direction*

* ``DMA_BIDIRECTIONAL``
* ``DMA_TO_DEVICE``
* ``DMA_FROM_DEVICE``

Streaming Mappings: To Virtual Address
--------------------------------------

*Create a DMA mapping to a virtual address*

.. code-block:: c

   dma_addr_t dma_handle = dma_map_single(dev, addr, size, direction);
   if (dma_mapping_error(dev, dma_handle)) { 
       /*fucked up*/
   }
   ... DMA operation ...
   dma_unmap_single(dev, dma_handle, size, direction);

Streaming Mappings: To Page
---------------------------

*Create a DMA mapping to a page*

.. code-block:: c

   dma_addr_t dma_handle = dma_map_page(dev, page, offset, size, direction);
   if (dma_mapping_error(dev, dma_handle)) { 
       /*fucked up*/
   }
   ... DMA operation ...
   dma_unmap_page(dev, dma_handle, size, direction);

Streaming Mappings: Scatterlists (1)
------------------------------------

* Larger DMA transfers usually involve multiple physically distributed
  (scattered) pages
* Represented by an *array* of ``struct scatterlist``

.. code-block:: c

   struct scatterlist {
       struct page *page;
       unsigned int offset;
       dma_addr_t dma_address;
       unsigned int length;
   };

* User fills in the known parts |longrightarrow| all but
  ``dma_address``

Streaming Mappings: Scatterlists (2)
------------------------------------

*Create mappings*

* Fill in DMA addresses
* Buckets used could be less than scatterlist size when adjacent pages
  are found

.. code-block:: c

   struct scatterlist sglist[100];
   struct scatterlist* sg_run;
   int i;
   int count = dma_map_sg(dev, sglist, 100, direction);
   // program into device
   for_each_sg(sglist, sg_run, count, i) {
       hw_address[i] = sg_dma_address(sg_run);
       hw_len[i] = sg_dma_len(sg_run);
   }

   ... DMA operation ...

   dma_unmap_sg(dev, sglist, nents /*NOT count!*/, direction);

Streaming Mappings: Syncing
---------------------------

* Unmapping does automatic flush of memory in the given direction
* Usually mapping are not recreated for every transfer
  |longrightarrow| explicit flush

.. code-block:: c

   dma_sync_single_for_cpu(dev, dma_handle, size, direction);
   dma_sync_sg_for_cpu(dev, sglist, nents, direction);



.. rubric:: Footnotes

.. [#alloc_page] Credit to Mel Gorman's incredibly helpful `page
                 allocation page
                 <https://www.kernel.org/doc/gorman/html/understand/understand009.html>`__
