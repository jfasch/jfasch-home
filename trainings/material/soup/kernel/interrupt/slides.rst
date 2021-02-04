.. include:: <mmlalias.txt>

Interrupts (Slideshow)
======================

.. contents::
   :local:

Move to Raspberry Pi
--------------------

**Why?** Use simple GPIO lines as interrupt sources.

* :doc:`build kernel
  </trainings/material/soup/kernel/raspi-kernel-build/topic>`
* Build our module against that kernel. Use ``make`` parameters
  ``ARCH`` and ``CROSS_COMPILE`` from
  :doc:`/trainings/material/soup/kernel/raspi-kernel-build/topic`
* Load it |longrightarrow| fine
* No easy ``arm-linux-gnu`` ``glibc`` on Fedora, have to build on
  target

Give Up, Build on Target
------------------------

* Copy ``linux/`` from host to target
* Won't compile there because already configured for host

.. code-block:: console

   # apt install flex bison libssl-dev bc

.. code-block:: console

   $ make oldconfig
