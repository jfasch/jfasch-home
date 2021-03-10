.. include:: <mmlalias.txt>

Coding: Raspi GPIO Interrupts (Slideshow)
=========================================

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
.................

* :doc:`build kernel
  </trainings/material/soup/kernel/raspi-kernel-build/topic>`
* Build our module against that kernel. Use ``make`` parameters
  ``ARCH`` and ``CROSS_COMPILE`` from
  :doc:`/trainings/material/soup/kernel/raspi-kernel-build/topic`
* Load it |longrightarrow| fine

Cross Compilation Sucks
.......................

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


Implement New Event Type: Interrupt
-----------------------------------

New ``ioctl``: ``MY_ACTIVATE_GPIO``
...................................

* Aha, third ``ioctl()`` parameter: ``unsigned long``
* Add ``ioctl`` with just a ``printk()`` on the kernel side
* Write test program, ``test-activate-gpio.c``

Interlude: ``_IO*()`` Macros
............................

.. code-block:: console

   # ./test-activate-gpio 0 25
   ioctl: Bad address

* See :ref:`ioctl-strange-beast`
* Fix
* Emphasize on ``ioctl`` numbers |longrightarrow| ABI breakage

Request GPIO
............

* Add new ``my_device`` method, ``my_device_activate_gpio()``, and
  call right into it

  * ``gpio_request()`` (and ``gpio_direction_input()``)
  * ``gpio_free()`` in ``_destroy()``

* Check

  .. code-block:: console

     # cat /sys/kernel/debug/gpio
     gpiochip0: GPIOs 0-53, parent: platform/3f200000.gpio, pinctrl-bcm2835:
      gpio-25  (                    |my_driver           ) in  lo 

* Unload driver |longrightarrow| gone

Request Interrupt
.................

* ``gpio_to_irq()``
* Implement dummy handler, only ``printk()``
* ``request_irq()``/``free_irq()``

Add hardware, check ``/proc/interrupts``

Test
....

* Press switch |longrightarrow| works
* Hammer on it via ``ioctl()``, and at the same time generate
  interrupts

  * Discuss: "atomic context"
  * Discuss: "sleep while atomic"
