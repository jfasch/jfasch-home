.. include:: <mmlalias.txt>

Interrupts (Slideshow)
======================

.. contents::
   :local:

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

   irqreturn_t irq_handler(int irq, void *cookie) { ... }

* ``irq``: the interrupt number that is active
* ``cookie``: opque pointer, given as ``cookie`` when IRQ is requested
* Return value ...

** ``irqreturn_t`` values**

.. csv-table::
   :widths: auto
   :align: left

   ``IRQ_NONE``, interrupt was not from this device or was not handled (shared interrupt?)
   ``IRQ_HANDLED``, interrupt was handled by this device, *important!* (Else line may remain active)
   ``IRQ_WAKE_THREAD``, handler requests to wake the handler thread (for threaded interrupts)

Requesting (and Releasing) Interrupts (1)
-----------------------------------------

.. code-block:: c

   #include <linux/interrupt.h>

   int request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags, const char *name, void *cookie);
   const void* free_irq(unsigned int irq, void *cookie);

* ``irq``: the requested interrupt line
* ``handler``: interrupt handler to attach to ``irq``
* ``flags``: a *meaningful* combination of

   .. csv-table::
      :widths: auto
      :align: left
   
      ``IRQF_SHARED``, Multiple interrupts shared on same line
      ``IRQF_TRIGGER_RISING``, Edge triggered: rising
      ``IRQF_TRIGGER_FALLING``, Edge triggered: falling
      ``IRQF_TRIGGER_HIGH``, Level triggered: high
      ``IRQF_TRIGGER_LOW``, Level triggered: low

* ``name``: shows up in ``/proc/interrupts``
* ``cookie``: echoed back into interrupt handler when called

.. note::

   After successful call to ``request_irq()`` line is hot
   *immediately*

Documentation
-------------

.. sidebar:: Documentation

   .. list-table::
      :widths: auto
      :align: left
   
      * * `request_irq
          <https://www.kernel.org/doc/html/latest/core-api/genericirq.html#c.request_irq>`__
   
      * * `free_irq
	  <https://www.kernel.org/doc/html/latest/core-api/genericirq.html?highlight=free_irq#c.free_irq>`__
