.. include:: <mmlalias.txt>

PCI (Slideshow)
===============

.. contents::
   :local:

See `Linux Kernel Documentation
<https://www.kernel.org/doc/html/latest/PCI/index.html>`__ for
something more comprehensive.

First and Foremost
------------------

* Driver brings the PCI IDs it is responsible for
* Driver installation registers ID-to-driver mapping in
  ``/lib/modules/$(uname -r)`` (see `depmod(8)
  <https://man7.org/linux/man-pages/man8/depmod.8.html>`__)
* ``udevd`` looks ID up when device is seen, and loads driver
* Kernel PCI subsystem calls ``probe()`` method (see later)

.. code-block:: c

   #include <linux/pci.h>

   static struct pci_device_id my_ids[] = {
       {PCI_DEVICE(0xdead, 0xbeef)},
       {PCI_DEVICE(0xdead, 0xbeee)}
   };

   MODULE_DEVICE_TABLE(pci, my_ids);

.. note::

   This happens during driver *build*

PCI Driver Methods
------------------

.. list-table::
   :widths: auto
   :align: left

   * - ``probe()``
     - Called when device inserted (or during boot when enumerated)
   * - ``remove()``
     - Called when device is removed
   * - ``suspend()``
     - Called when device is suspended
   * - ``resume()``
     - Called when device is resumed
   * - ...
     - and many more (see ``linux/pci.h``)

.. code-block:: c

   static int my_probe(struct pci_dev *dev, const struct pci_device_id *id) { ... }
   static void my_remove(struct pci_dev *dev) { ... }
   static int my_suspend(struct pci_dev *dev, pm_message_t state) { ... }
   static int my_resume(struct pci_dev *dev) { ... }
   static void my_shutdown(struct pci_dev *dev) { ... }

PCI Driver Structure, and the ``init()`` Method
-----------------------------------------------

.. code-block:: c

   static struct pci_driver my_driver = {
       .name = "my-driver",
       .id_table = my_ids,
       .probe = my_probe,
       .remove = my_remove,
       .suspend = my_suspend,
       .resume = my_resume,
   };
   
   static int my_init(void)
   {
       int err = pci_register_driver(&my_driver);
       /* ... */
   }

* ``id_table`` should not be ``NULL``, and ideally should contain what
  was registered statically with ``MODULE_DEVICE_TABLE()`` (at least I
  cannot see a reason why not)
* ``probe()`` is called immediately afterwards

PCI Device Structure, and the ``probe()`` Method
------------------------------------------------

Once the driver is initialized (and the ``probe()`` method has been
registered), the PCI subsystem ...

* creates and fills in a ``struct pci_dev`` structure for the device
* calls the driver's ``probe()`` method to present the device to the
  driver

The structure is huge, and only sparsely documented; here some
prominent members (things are always more complicated than it might
appear).

.. code-block:: c

   struct pci_dev {
       unsigned short vendor;
       unsigned short device;
       unsigned short subsystem_vendor;
       unsigned short subsystem_device;
       u64 dma_mask;
       unsigned int irq;
       struct resource resource[DEVICE_COUNT_RESOURCE];
   };

* DMA |longrightarrow| later
* ``irq`` as in :doc:`../interrupt/topic`
* ``resource``: PCI resources, or *Base Address Registers (BARs)*

The ``probe()`` Method: Responsibilities
----------------------------------------

* ``int err = pci_enable_device(pdev);``

  * Low level bus wizardry
  * Device wakeup if appropriate

* ``int err = pci_request_regions(pdev, "my-driver");``
   
  * Reserves BARs as being used by name

* ``pci_set_master(pdev);``

  * Device is *bus master*
  * Necessary if driver will do DMA
  * Remember to call ``pci_clear_master()`` on unload

* ``int err = pci_set_dma_mask(pdev, mask);``

  * Decide whether to do 32 bit or 64 bit DMA
  * Default: 32 bit (as per PCI spec)

* ``pci_set_drvdata(pdev, context);``

  * ``void* context`` is set in ``pdev``
  * Usually points to a driver specific device structure
  * Much like ``private_data`` in ``struct file``
