.. include:: <mmlalias.txt>

Interrupts (Slideshow)
======================

.. contents::
   :local:

.. sidebar:: Source

   `See Github
   <https://github.com/jfasch/jf-kernel-course/tree/my_driver_interrupt/_morph>`__

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

Interrupt Facts
---------------

* Interrupt context is not *scheduled*
* No sleeping API calls allowed
* Not easily debugged
* Not easy in general
* No prioritization

**But** ...

* Threaded interrupt handlers
* ... thanks to ``PREEMPT_RT`` slowly being integrated in mainline

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
   ``IRQ_WAKE_THREAD``, handler requests to wake the handler thread (for threaded interrupts)

Requesting (and Releasing) Interrupts (1)
-----------------------------------------

.. code-block:: c

   #include <linux/interrupt.h>

   int request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags, const char *name, void *cookie);
   const void* free_irq(unsigned int irq, void *cookie);

**``flags`` values**

.. csv-table::
   :widths: auto
   :align: left

   ``IRQF_SHARED``, Multiple interrupts shared on same line
   ``IRQF_TRIGGER_RISING``, Edge triggered: rising
   ``IRQF_TRIGGER_FALLING``, Edge triggered: falling
   ``IRQF_TRIGGER_HIGH``, Level triggered: high
   ``IRQF_TRIGGER_LOW``, Level triggered: low

* *Attention*: after successful call to ``request_irq()`` line is hot
  *immediately*

Requesting (and Releasing) Interrupts (2)
-----------------------------------------

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
