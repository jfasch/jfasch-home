Raspberry Pi: Building the Kernel
=================================

.. toctree::
   :maxdepth: 1

   story

Todo jjj
--------

* https://www.raspberrypi.org/documentation/linux/kernel/building.md

  (Story is not quite up to date)

* Toolchain (on Fedora)

  .. code-block:: console

     # dnf install binutils-arm-linux-gnu gcc-arm-linux-gnu

* Kernel source

  .. code-block:: console
     :caption: On the Raspi ...

     $ uname -r
     5.4.83-v7+

  .. code-block:: console

     $ git clone https://github.com/raspberrypi/linux
     $ cd linux/
     $ git checkout --track remotes/origin/rpi-5.4.y

  Fix ``EXTRAVERSION``

    .. code-block:: console
       :caption: Toplevel ``Makefile``

       VERSION = 5
       PATCHLEVEL = 4
       SUBLEVEL = 83
       EXTRAVERSION = -v7

* Build

  * Use config from running Pi kernel

    .. code-block:: console
       :caption: On the Pi ...

       # modprobe configs
       # ls -l /proc/config.gz

    Copy and unzip that into kernel root, as ``.config``

    .. code-block:: console
       :caption: On host ...

       $ make ARCH=arm CROSS_COMPILE=arm-linux-gnu- oldconfig

  * Build

    .. code-block:: console
       :caption: On host ...

       $ make ARCH=arm CROSS_COMPILE=arm-linux-gnu- zImage modules dtbs


