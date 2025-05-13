Dirty Upgrade Path
==================

.. contents::
   :local:

Goal
----

* First shot at a kernel upgrade, as lightweight as possible.

  * During the I2S/DAC bringup massacre (the heart of the project)
    that will follow, we will repeat this step a number of times.

* Therefore:

  * No debian packaging yet
  * Only upgrading the kernel the hard way. No distro, no packaging,
    no nothing. Just kernel, modules, and Bootloader config.
  * Maybe one or two scripts to speed it up

Steps
-----

* ``make oldconfig``: Debian kernel config, together with the Yocto
  kernel tree. Massage, build.
* Build
* Copy into Qemu box

  * Adjust Grub config for dual booting both the stable and Yocto
    kernels

* Repeat until runs
  
