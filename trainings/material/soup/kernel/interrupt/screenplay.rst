.. include:: <mmlalias.txt>

Interrupts (Screenplay)
=======================

.. contents::
   :local:

jjj Todo
--------

* give source
* hammer on it via ``ioctl()``, and at the same time generate interrupts

  * discuss: "atomic context"

New ``ioctl``: ``MY_ACTIVATE_GPIO``
-----------------------------------

* Aha, third ``ioctl()`` parameter: ``unsigned long``
* Add ``ioctl`` with just a ``printk()`` on the kernel side
* Write test program, ``test-activate-gpio.c``

Interlude: ``_IO*()`` Macros
----------------------------

.. code-block:: console

   # ./test-activate-gpio 0 25
   ioctl: Bad address

* See :ref:`ioctl-strange-beast`
* Fix
* Emphasize on ``ioctl`` numbers |longrightarrow| ABI breakage

Request GPIO
------------

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
-----------------

* ``gpio_to_irq()``
* Implement dummy handler, only ``printk()``
* ``request_irq()``/``free_irq()``

Add hardware, check ``/proc/interrupts``


