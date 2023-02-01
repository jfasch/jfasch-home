.. ot-topic:: linux.sysprog.intro_hw.sysfs_gpio

.. include:: <mmlalias.txt>


Intro: ``sysfs`` GPIO
=====================

.. contents::
   :local:

.. warning::

   The ``sysfs`` GPIO userspace interface is deprecated, and will be
   removed from the kernel eventually. However it's use is really
   simple, and it is used here as an introduction to the style how
   hardware access usually looks like in Linux.

.. sidebar::

   **Documentation**

   * https://www.kernel.org/doc/Documentation/gpio/sysfs.txt

``sysfs``?
----------

* *Virtual* filesystem

  * Exposes kernel information as ordinary file system entries
  * Files and directories, mainly

* Usually mounted on ``/sys``
* Exposes connected hardware to :doc:`userspace
  </trainings/material/soup/linux/basics/intro/overview>`
* Dedicated subtrees ...

  * ``/sys/bus/pci``
  * ``/sys/bus/spi``
  * ``/sys/bus/i2c``
  * ``/sys/class/pwm``
  * ``/sys/class/gpio``
  * ...

General Purpose IO (GPIO)
-------------------------

* IO pins, accessible by :doc:`userspace
  </trainings/material/soup/linux/basics/intro/overview>`
* Rooted at ``/sys/class/gpio``

.. code-block:: console

   $ ls -l /sys/class/gpio/
   total 0
   --w--w---- 1 root gpio 4096 Feb  1 12:31 export
   lrwxrwxrwx 1 root gpio    0 Jan 31 16:16 gpiochip0 -> ../../devices/platform/soc/fe200000.gpio/gpio/gpiochip0
   lrwxrwxrwx 1 root gpio    0 Jan 31 16:16 gpiochip488 -> ../../devices/platform/soc/fe804000.i2c/i2c-1/1-0040/gpio/gpiochip488
   lrwxrwxrwx 1 root gpio    0 Jan 31 16:16 gpiochip504 -> ../../devices/platform/soc/soc:firmware/soc:firmware:gpio/gpio/gpiochip504
   --w--w---- 1 root gpio 4096 Feb  1 13:10 unexport

* Very simple access: reading and writing files
* |longrightarrow| no programming - shell only

Requesting A GPIO Pin
---------------------

* By default, GPIO pins are only used by kernel drivers
* |longrightarrow| explicit *export*

.. code-block:: console
   :caption: Requesting GPIO #26

   $ echo 26 > /sys/class/gpio/export 

* |longrightarrow| New directory ``gpio26`` in ``/sys/class/gpio``

.. code-block:: console

   $ ls -l /sys/class/gpio/gpio26/
   total 0
   -rw-rw---- 1 root gpio 4096 Feb  1 13:15 active_low
   lrwxrwxrwx 1 root gpio    0 Feb  1 13:15 device -> ../../../gpiochip0
   -rw-rw---- 1 root gpio 4096 Feb  1 13:15 direction
   -rw-rw---- 1 root gpio 4096 Feb  1 13:15 edge
   drwxrwxr-x 2 root gpio    0 Feb  1 13:15 power
   lrwxrwxrwx 1 root gpio    0 Feb  1 13:15 subsystem -> ../../../../../../../class/gpio
   -rw-rw-r-- 1 root gpio 4096 Feb  1 13:15 uevent
   -rw-rw---- 1 root gpio 4096 Feb  1 13:15 value

GPIO Attributes As Files
------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * File
     * Meaning
   * * ``direction``
     * Configured as input (``in``) or output (``out``)
   * * ``value``
     * ``0`` or ``1``
   * * ``edge``
     * Interrupt configuration: ``none``, ``rising``, ``falling``,
       ``both`` |longrightarrow| *Events* from the ``value`` file, via
       ``select()``, ``poll()``, or ``epoll()``
   * * ``active_low``
     * Inverts the meaning of ``value`` and ``edge``
