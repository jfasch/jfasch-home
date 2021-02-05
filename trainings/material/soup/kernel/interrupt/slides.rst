.. include:: <mmlalias.txt>

Interrupts (Slideshow)
======================

.. contents::
   :local:

Move to Raspberry Pi, Cross Compiling
-------------------------------------

**Why?** Use simple GPIO lines as interrupt sources.

.. list-table::
   :widths: auto
   :align: left

   * - .. image:: GPIO-Pinout-Diagram-2.png
          :scale: 30%
     - .. image:: schematic.png
          :scale: 30%

Cross Compilation
-----------------

* :doc:`build kernel
  </trainings/material/soup/kernel/raspi-kernel-build/topic>`
* Build our module against that kernel. Use ``make`` parameters
  ``ARCH`` and ``CROSS_COMPILE`` from
  :doc:`/trainings/material/soup/kernel/raspi-kernel-build/topic`
* Load it |longrightarrow| fine

Cross Compilation Sucks
-----------------------

* No easy ``arm-linux-gnu`` ``glibc`` on Fedora, have to build on
  target


* Copy ``linux/`` from host to target
* Won't compile there because already configured for host

.. code-block:: console

   # apt install flex bison libssl-dev bc

.. code-block:: console

   $ make oldconfig

.. _ioctl-strange-beast:

``ioctl()`` Is A Strange Beast
------------------------------

* History-laden
* Historically, hardcoding major an minor number led to conflicts
  between devices (so they say)
* Safety measure: ``ioctl`` request numbers need to be endoded

  * Type information of 3rd argument
  * Direction

* Currently not the case: ``enum my_ioctl_requests`` starts at 0, just
  like ``enum``'s do by default

``_IO*()`` Macros
-----------------

.. code-block:: c
   :caption: <linux/ioctl.h>

   /*
    * Used to create numbers.
    *
    * NOTE: _IOW means userland is writing and kernel is reading. _IOR
    * means userland is reading and kernel is writing.
    */
   #define _IO(type,nr)		_IOC(_IOC_NONE,(type),(nr),0)
   #define _IOR(type,nr,size)	_IOC(_IOC_READ,(type),(nr),(_IOC_TYPECHECK(size)))
   #define _IOW(type,nr,size)	_IOC(_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))
   #define _IOWR(type,nr,size)	_IOC(_IOC_READ|_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))

* ``type``: some (arbitrary?) "magic number"
* ``nr``: actual ``ioctl`` request
* ``size``: the C type, *not* the size (OMG)

.. code-block:: c

``_IO*()`` Macros: Usage
------------------------

.. code-block:: c

   enum my_ioctls
   {
       DO_THIS = _IO(666, 0), /* no argument */
       DO_THAT = _IOW(666, 1, int), /* user to kernel, int argument */
   };

Short (Legacy) GPIO API Introduction
------------------------------------

.. code-block:: c

   #include <linux/gpio.h>

   int gpio_request(unsigned gpio, const char *label);
   void gpio_free(unsigned gpio);
   int gpio_direction_input(unsigned gpio);
   int gpio_direction_output(unsigned gpio, int value);
   int gpio_to_irq(unsigned gpio);

.. note::

   Check ``/sys/kernel/debug/gpio``!

.. sidebar:: Documentation

   * Legacy API: `LWN article <https://lwn.net/Articles/532714/>`__
   * Legacy API: `Kernel doc
     <https://www.kernel.org/doc/html/latest/driver-api/gpio/legacy.html>`__
   * Descriptor based (``gpiod``) API: `LWN article
     <https://lwn.net/Articles/533632/>`__

Interrupt Service Routine
-------------------------

.. code-block:: c

   #include <linux/interrupt.h>

   irqreturn_t irq_handler(int irq, void *userdata) { ... }

* ``irq``: the interrupt number that is active
* ``userdata``: set when requesting the IRQ
* Return value ...

** ``irqreturn_t`` values**

.. csv-table::
   :widths: auto
   :align: left

   ``IRQ_NONE``, interrupt was not from this device or was not handled (shared interrupt?)
   ``IRQ_HANDLED``, interrupt was handled by this device
   ``IRQ_WAKE_THREAD``, handler requests to wake the handler thread

Requesting (and Releasing) Interrupts
-------------------------------------

.. code-block:: c

   #include <linux/interrupt.h>

   int request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags, const char *name, void *cookie);
   const void* free_irq(unsigned int irq, void *cookie);

**``flags`` values**

.. csv-table::
   :widths: auto
   :align: left

   ``IRQF_TRIGGER_RISING``, Edge triggered: rising
   ``IRQF_TRIGGER_FALLING``, Edge triggered: falling
   ``IRQF_TRIGGER_HIGH``, Level triggered: high
   ``IRQF_TRIGGER_LOW``, Level triggered: low

.. note::

   Check ``/proc/interrupts``!

.. sidebar:: Documentation

   .. list-table::
      :widths: auto
      :align: left
   
      * * `request_irq
          <https://www.kernel.org/doc/html/latest/core-api/genericirq.html#c.request_irq>`__
   
      * * `free_irq
	  <https://www.kernel.org/doc/html/latest/core-api/genericirq.html?highlight=free_irq#c.free_irq>`__
