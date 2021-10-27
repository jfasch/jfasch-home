.. include:: <mmlalias.txt>

.. meta::
   :description: I2C (using LM73)
   :keywords: linux, inter intergrated circuit, i2c, sensors,
              lm-sensors, lm73, raspberry pi, raspi, userspace, hwmon,
              sysfs

Linux and I2C (using LM73 Temperature Sensor as Slave)
======================================================

.. ot-topic:: linux.hardware.i2c

.. contents::
   :local:

Overview
--------

This article shows how you use Linux to communicate with `I2C
<https://en.wikipedia.org/wiki/I%C2%B2C>`__ devices. We use ...

* Rasperry Pi because everything's easy there. This article's
  principles hold unmodified for other devices that run Linux (more
  handwork might be needed though).
* The *Hardware Monitoring* interface in ``/sys/class/hwmon``
* The `Texas Instruments LM73 <https://www.ti.com/product/LM73>`__
  temperature sensor.

Configuring I2C Master
----------------------

The Raspberry has two I2C host controllers ("masters") built-in. One
of those, ``i2c-0``, is dedicated to display and touch handling and is
of no relevance here.

The other, ``i2c-1``, is for maker's use. This is what this section is
about.

Enable I2C, Load BCM2835 Platform Driver
........................................

.. sidebar:: Raspberry Pi GPIO header pinout

   .. image:: ../common-images/raspi-pinout.png

By default, on *Raspberry Pi OS* everything's off. To turn something
on, you configure the bootloader to turn it on. The bootloader will
then pass the relevant information to the kernel which will react
accordingly - load the appropriate drivers, for example.

In ``/boot/config.txt`` insert the following line [#config_uncomment]_
...

.. code-block:: text

   dtparam=i2c_arm=on

The effect of enabling I2C is that

* pins *GPIO2* and *GPIO3* are not GPIO pins anymore, but rather their
  alternative configurations as *data* and *clock*, respectively, are
  enabled. See the pinout diagram.
* the platform I2C driver is loaded.

**Reboot**, and check:

.. code-block:: console
   :caption: I2C platform driver

   $ lsmod |grep i2c
   i2c_bcm2835            16384  0

We can see a userspace representation of the bus in ``sysfs``,

.. code-block:: console
   :caption: I2C bus #1 visible in ``sysfs``
   
   $ ls -l /sys/bus/i2c/devices/i2c-1
   lrwxrwxrwx 1 root root 0 Oct  4 12:43 /sys/bus/i2c/devices/i2c-1 -> ../../../devices/platform/soc/fe804000.i2c/i2c-1

.. note::

   You can use the ``raspi-config`` tool to do the same in a more
   comfortable manner. Here in this article, we do *not* use any of
   those decadent tools. These are Raspberry specific and not
   available on any other Linux device [#config-txt-decadent-enough]_.

   See `here
   <https://www.raspberrypi.org/documentation/computers/configuration.html>`__
   for decadent documentation of ``raspi-config``.

Enable Userspace I2C
....................

We will be using a `LM73 <https://www.ti.com/product/LM73>`__
temperature sensor, for which a kernel driver exists. This means it is
not strictly necessary to enable the I2C userspace interface - it is
helpful though if you want to do diagnostics such as scanning an I2C
bus for available devices.

Load the driver, ``i2c_dev``, manually first to see what is going
on. This will create a *character device* ``/dev/i2c-1`` which
represents the I2C bus #1.

.. code-block:: console

   # modprobe i2c-dev

.. code-block:: console

   $ ls -l /dev/i2c-1 
   crw-rw---- 1 root i2c 89, 1 Sep 29 14:27 /dev/i2c-1

We do not want to load ``i2c-dev`` manually everytime the Raspberry
has booted, so we write the module name in ``/etc/modules``,

.. code-block:: text
   :caption: ``/etc/modules``

   i2c-dev

.. note::

   The same is accomplished by creating a dedicated file, say
   ``/etc/modules-load.d/i2c``, with ``i2c-dev`` in it.

**Reboot**, and check if ``/etc/i2c-1`` is still there. We will later
see how to detect devices on it using the ``i2cdetect`` `tool
<https://linux.die.net/man/8/i2cdetect>`__.

Slave Device: LM73
------------------

.. sidebar:: Datasheet etc.

   * `LM73 at Texas Instruments <https://www.ti.com/product/LM73>`__
   * :download:`Datasheet <Thermometer_LM73.pdf>`

LM73 comes in a SOT-23 package which means that it is rather
small. Power can be supplied in a range between 2.7V and 5.5V. This is
practical since the Pi's I2C operating voltage is 3.3V; we use the
3.3V rail to power the chip.

During a larger project, I had to write a larger software package and,
among other tasks like PCI communication, talk to LM73. This is where
I decided to isolate the chip for easy testing, and came up with a PCB
to carry only the LM73 and a capacitor.

.. image:: breakout.jpg

The breakout board has a 10-pin IDC header with the following pin
assignments:

.. list-table::
   :align: left

   * * .. list-table::
          :align: left
	  :header-rows: 1

          * * IDC
            * LM73
          * * 6
            * 2 (GND)
          * * 1
            * 3 (VDD)
          * * 3
            * 6 (SMBDAT)
          * * 5
            * 4 (SMBCLK)

     * .. image:: 2x5-IDC-Pin-Numbering.png
     * .. image:: lm73-pinout.png

Optional: Address Selection
...........................

The LM73 lets you choose between three different addresses, via pin 1.

.. list-table::
   :align: left

   * * Left unconnected (floating)
     * ``0x48``
   * * Connected to GND
     * ``0x49``
   * * Connected to VDD
     * ``0x4A``

The breakout board takes this into account: a 3 pin header lets you
connect pins with a jumper.

Connecting LM73 to Raspberry Pi
-------------------------------

Given the above IDC header pinout, we can now connect to the Raspberry
Pi as follows:

.. list-table::
   :align: left
   :header-rows: 1

   * * Raspberry Pi Header
     * IDC/LM73
   * * 1 (3V3)
     * 1
   * * 6 (GND)
     * 6 (GND)
   * * 3 (SDA)
     * 3
   * * 5 (SCL)
     * 5

``i2c-tools``/``i2cdetect``: Diagnostics, Detecting Devices
-----------------------------------------------------------

Now we use the ``i2cdetect`` program from the ``i2c-tools`` `package
<https://i2c.wiki.kernel.org/index.php/I2C_Tools>`__ to check if
everything's connected correctly. I omitted the address jumper, so
LM73 pin 1 is left floating - the chip should appear on address
``0x48``.

Install the ``i2c-tools`` package,

.. code-block:: console
		
   # apt install i2c-tools

``i2c-tools`` brings a set of low-level programs to manipulate I2C
device registers. ``i2cdetect`` is a tool to "probe" a bus for
devices. Lets proble I2C bus 1 (i.e. ``/dev/i2c-1``),

.. code-block:: console

   $ i2cdetect -y 1 
        0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
   00:          -- -- -- -- -- -- -- -- -- -- -- -- -- 
   10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
   20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
   30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
   40: -- -- -- -- -- -- -- -- 48 -- -- -- -- -- -- -- 
   50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
   60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
   70: -- -- -- -- -- -- -- --                         

Voila, everything there - one device at address ``0x48``.

Using the Device: Talking I2C from Userspace
--------------------------------------------

Reading the :download:`datasheet <Thermometer_LM73.pdf>` thoroughly
[#datasheet-authors-mad]_, one can implement the device's protocol in
userspace. On the *bus* device ``/dev/i2c-1``, you kind of *connect*
to the device's address (``0x48``), and send bytes back and forth.

.. literalinclude:: LM73.py
   :caption: :download:`LM73.py`

Implementing the device's protocol in userspace is always possible for
I2C devices. See `the kernel documentation
<https://www.kernel.org/doc/html/latest/i2c/dev-interface.html>`__ for
detailed information - we are scratching only the surface here.

But this is rarely necessary because most devices are supported by
Linux out of the box, and LM73 is no exception.

Using the Device: ``hwmon`` - Hardware Monitoring
-------------------------------------------------

The Linux kernel comes with `a driver for LM73
<https://github.com/torvalds/linux/blob/master/drivers/hwmon/lm73.c>`__
(`documentation
<https://www.kernel.org/doc/html/latest/hwmon/lm73.html>`__). Sadly,
Raspberry Pi OS does not package that driver, so you have to build
your own kernel for this.

Building the Kernel, Enabling LM73
..................................

This is relatively easy; follow the `kernel build documentation
<https://www.raspberrypi.org/documentation/computers/linux_kernel.html#building>`__. In
short:

Install prerequisites (as root),

.. code-block:: console

   # apt install git bc bison flex libssl-dev make libncurses-dev

Clone the kernel,

.. code-block:: console

   $ git clone https://github.com/raspberrypi/linux
   $ git branch
   * rpi-5.10.y

Massage the configuration,

.. code-block:: console

   $ cd linux
   $ KERNEL=kernel7l
   $ make bcm2711_defconfig
   $ make menuconfig

Apply your changes in the following places:

* *General Setup / Local version - append to kernel release*: add
  something to differentiate your kernel from the prebuilt kernel. My
  choice is ``-v7l-jfasch``.
* *Device Drivers / Hardware Monitoring support / National
  Semiconductor LM73*: build as module ("``M``")

Next, build the kernel. Time for coffee,

.. code-block:: console

   $ make -j4 zImage modules dtbs

Install the kernel, and reboot (as root),

.. code-block:: console

   # make modules_install
   # cp arch/arm/boot/dts/*.dtb /boot/
   # cp arch/arm/boot/dts/overlays/*.dtb* /boot/overlays/
   # cp arch/arm/boot/dts/overlays/README /boot/overlays/
   # cp arch/arm/boot/zImage /boot/$KERNEL.img
   # reboot

Loading the Driver
..................

I2C is a simple protocol. PCI, at the other end of the protocol
complexity scale, supports automatic device identification via
*vendor* and *device* IDs, so device drivers can be automatically
loaded - *hotplugged*.

With I2C, we don't have such luck: *we* know what type of device sits
on each address, and *we* have to supply that information to the
kernel - triggering a kind of a "fake hotplug". Knowing that the
driver name is ``lm73``, and the chip is on address ``0x48``, as
*root* [#why_root_for_hotplug]_ do the following,

.. code-block:: console
   :caption: Announce LM73 at ``0x48``
		
   # echo lm73 0x48 > /sys/bus/i2c/devices/i2c-1/new_device

Device up and running. Consequentially, the new device is represented
as a directory in ``sysfs``,

.. code-block:: console

   $ ls -l /sys/bus/i2c/devices/1-0048/
   total 0
   -r--r--r-- 1 root root 4096 Oct  4 12:54 modalias
   -r--r--r-- 1 root root 4096 Oct  4 12:54 name
   drwxr-xr-x 2 root root    0 Oct  4 12:54 power
   lrwxrwxrwx 1 root root    0 Oct  4 12:54 subsystem -> ../../../../../../bus/i2c
   -rw-r--r-- 1 root root 4096 Oct  4 12:53 uevent

Hardware Monitoring (``hwmon``) Devices
.......................................

``/sys/bus/i2c/devices/1-0048/`` represents the device as a generic
I2C device. A different aspect of LM73 is that it is a temperature
sensor. There is an entire framework inside the kernel, ``hwmon``, to
cover such devices - no matter if they are Onewire or I2C (or ...)
devices, or if they are reachable via a CPU internal bus.

As such (a temperature sensor), the device appears under an
alternative location in ``sysfs``,

.. code-block:: console

   $ ls -l /sys/class/hwmon/hwmon3/
   total 0
   lrwxrwxrwx 1 root root    0 Oct  5 08:57 device -> ../../../1-0048
   -r--r--r-- 1 root root 4096 Oct  5 08:57 name
   drwxr-xr-x 2 root root    0 Oct  5 08:57 power
   lrwxrwxrwx 1 root root    0 Oct  5 08:57 subsystem -> ../../../../../../../../class/hwmon
   -r--r--r-- 1 root root 4096 Oct  5 08:57 temp1_input
   -rw-r--r-- 1 root root 4096 Oct  5 08:57 temp1_max
   -r--r--r-- 1 root root 4096 Oct  5 08:57 temp1_max_alarm
   -rw-r--r-- 1 root root 4096 Oct  5 08:57 temp1_min
   -r--r--r-- 1 root root 4096 Oct  5 08:57 temp1_min_alarm
   -rw-r--r-- 1 root root 4096 Oct  5 08:56 uevent
   -rw-r--r-- 1 root root 4096 Oct  5 08:57 update_interval

``temp1_input`` is what contains information for us (the temperature
in milli-celsius):

.. code-block:: console

   $ cat /sys/class/hwmon/hwmon1/temp1_input 
   22000

.. note::

   * **Question**: how do I know that it's my sensor in ``hwmon3``?
     ``hwmon1`` seems like a randomly/sequentially chosen name, and I
     assume the order is not always the same across boots.
   * **Answer**: correct. You can identify your sensor, though, by
     looking at the ``device`` symlink,

     .. code-block:: console

        $ ls -l /sys/class/hwmon/hwmon3/device
        lrwxrwxrwx 1 root root 0 Oct  5 08:57 /sys/class/hwmon/hwmon3/device -> ../../../1-0048

     Apparently, the nomenclature is ``<bus>-<address>``.

.. rubric:: Footnotes

.. [#config_uncomment] The line is already there, you only have to
                       uncomment it.
.. [#config-txt-decadent-enough] The functionality that the Raspberry
                                 bootloader (via ``/boot/config.txt``)
                                 brings is already decadent enough.
.. [#why_root_for_hotplug] While members of group ``i2c`` are
                           permitted to *talk* to I2C devices, adding
                           devices is considered an administrative
                           task.
.. [#datasheet-authors-mad] Beware, data sheet authors have a strange
                            kind of humor!
