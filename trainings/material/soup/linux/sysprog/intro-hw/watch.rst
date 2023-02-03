.. ot-topic:: linux.sysprog.intro_hw.watch
   :dependencies: linux.sysprog.intro_hw.get,
		  linux.sysprog.intro_hw.sysfs_gpio

.. include:: <mmlalias.txt>


Interrupts In Userspace
=======================

.. contents::
   :local:

Manual Configuration
--------------------

* Request GPIO 26, and configure as *input* (see :doc:`sysfs-gpio`)
* Configure interrupts

.. code-block:: console

   $ echo falling > /sys/class/gpio/gpio26/edge

* And now?
* |longrightarrow| Need programming; shell is not made for advanced
  concepts

C Program: Configuration, Event Loop
------------------------------------

.. literalinclude:: /trainings/material/soup/linux/sysprog/code/blink/sysfs/blink-watch-sysfs.cpp
   :caption: :download:`/trainings/material/soup/linux/sysprog/code/blink/sysfs/blink-watch-sysfs.cpp`
   :language: c++
