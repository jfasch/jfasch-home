.. meta::
   :description: The Linux PWM Userspace Interface
   :keywords: linux, onewire, w1, DS18B20, raspberry pi, raspi,
              userspace, hwmon, sysfs

OneWire Userspace Interface (using DS18B20)
===========================================

.. contents::
   :local:

Overview
--------

This article shows how you use Linux to communicate with `Onewire
<https://en.wikipedia.org/wiki/1-Wire>`__ devices. We use the

* ``w1-gpio`` bitbanging driver as the bus master.
* `DS18B20 <https://www.maximintegrated.com/en/products/DS18B20>`__
  Onewire temperature sensor as a slave device.
* Rasperry Pi because everything's easy there. This article's
  principles hold unmodified for other devices that run Linux (more
  handwork might be needed though - Pi's ``/boot/config.txt`` is
  really cool).

A `Onewire <https://en.wikipedia.org/wiki/1-Wire>`__ device has three
wires attached to it: data, ground, and power. Data and ground are
mandatory, obviously. Power is optional; if omitted, the device is
said to be operated in *parasitic mode*.

``w1-gpio``: Bitbanging (Master)
--------------------------------

Lacking a hardware Onewire master (the Raspi does not have one
built-in), we use a software implementation of the Onewire protocol -
the ``w1-gpio`` kernel driver. You dedicate one GPIO to act as the
data line, and the kernel driver is then used to `bitbang
<https://en.wikipedia.org/wiki/Bit_banging>`__ the Onewire protocol in
and out of the CPU.

Configuration is easy: say you want to use GPIO 21 as data line. In
``/boot/config.txt`` you write,

.. code-block:: console

   dtoverlay=w1-gpio,gpiopin=21

.. note::

   Reboot the Pi, and the kernel will load the driver and configure
   the GPIO accordingly.

DS18B20 (Slave)
---------------

.. list-table::
   :align: left

   * * The `DS18B20
       <https://www.maximintegrated.com/en/products/DS18B20>`__
       Onewire temperature sensor is a popular device. You can find
       parts that come prepackaged in a metal case; these are still
       affordable, and really easy to deploy.
     * .. figure:: ds18b20-packaged.jpg
          :align: left
	  :alt: DS18B20 (packaged)

Wiring
------

.. note::

   Though not exatly necessary |:wink:|, it makes sense to halt and
   power off the Pi before connecting the sensor.

.. list-table::
   :align: left
   :header-rows: 1

   * * Professional Diagram
     * Decadent Pi Addon
   * * .. image:: wiring.png
     * .. image:: wiring-photo.jpg

Using the Device
----------------

In most if not all cases, Linux presents hardware as a set of regular
files in ``sysfs``. 

As a Generic Onewire Device
...........................

Onewire masters automatically enumerate their buses, by definition -
so our device should show up automatically in a dedicated directory
``/sys/bus/w1/devices/<manufacturer>-<device-address>``. (If all is
well; see below for caveats.)

.. code-block:: console

   $ ls -l /sys/bus/w1/devices/28-01144fe7b4aa/
   total 0
   -rw-r--r-- 1 root root 4096 Sep 22 12:19 alarms
   -rw-r--r-- 1 root root 4096 Sep 22 12:19 conv_time
   lrwxrwxrwx 1 root root    0 Sep 22 12:19 driver -> ../../../bus/w1/drivers/w1_slave_driver
   --w------- 1 root root 4096 Sep 22 12:19 eeprom
   -r--r--r-- 1 root root 4096 Sep 22 12:19 ext_power
   -rw-r--r-- 1 root root 4096 Sep 22 12:19 features
   drwxr-xr-x 3 root root    0 Sep 22 12:16 hwmon
   -r--r--r-- 1 root root 4096 Sep 22 12:19 id
   -r--r--r-- 1 root root 4096 Sep 22 12:19 name
   drwxr-xr-x 2 root root    0 Sep 22 12:19 power
   -rw-r--r-- 1 root root 4096 Sep 22 12:19 resolution
   lrwxrwxrwx 1 root root    0 Sep 22 12:16 subsystem -> ../../../bus/w1
   -r--r--r-- 1 root root 4096 Sep 22 12:19 temperature
   -rw-r--r-- 1 root root 4096 Sep 22 12:16 uevent
   -rw-r--r-- 1 root root 4096 Sep 22 12:19 w1_slave

A file that is common to all Onewire devices (not only temperature
sensors) is ``w1_slave``, which already contains all we need: the
temperature in milli-celsius (22750).

.. code-block:: console

   $ cat /sys/bus/w1/devices/28-01144fe7b4aa/w1_slave 
   6c 01 4b 46 7f ff 0c 10 2b : crc=2b YES
   6c 01 4b 46 7f ff 0c 10 2b t=22750

As a Hardware Monitoring (``hwmon``) Device
...........................................

A different aspect to our sensor, DS18B20, is that it is a temperature
sensor. There is an entire framework inside the kernel, ``hwmon``, to
cover such devices - no matter if they are Onewire or I2C (or ...)
devices, or if they are reachable via a CPU internal bus.

As such (a temperature sensor), the device appears under an
alternative location in ``sysfs``,

.. code-block:: console

   $ ls -l /sys/class/hwmon/hwmon1/
   total 0
   lrwxrwxrwx 1 root root    0 Sep 22 14:44 device -> ../../../28-01144fe7b4aa
   -r--r--r-- 1 root root 4096 Sep 22 14:44 name
   drwxr-xr-x 2 root root    0 Sep 22 14:44 power
   lrwxrwxrwx 1 root root    0 Sep 22 14:44 subsystem -> ../../../../../class/hwmon
   -r--r--r-- 1 root root 4096 Sep 22 14:44 temp1_input
   -rw-r--r-- 1 root root 4096 Sep 22 12:16 uevent

``temp1_input`` is what contains information for us (again, the
temperature in milli-celsius):

.. code-block:: console

   $ cat /sys/class/hwmon/hwmon1/temp1_input 
   22750

.. note::

   * **Question**: how do I know that it's my sensor in ``hwmon1``?
     ``hwmon1`` seems like a randomly/sequentially chosen name, and I
     assume the order is not always the same across boots.
   * **Answer**: correct. But the address of the sensor (that is how
     you identify your devices in the end) is globally unique. You can
     use that to find the correct ``/sys/class/hwmon/`` subdirectory.

     .. code-block:: console

	$ ls -l /sys/class/hwmon/hwmon1/device
	lrwxrwxrwx 1 root root 0 Sep 22 14:44 /sys/class/hwmon/hwmon1/device -> ../../../28-01144fe7b4aa

Caveats
-------

Topology
........

For stability, a Onewire setup should not exhibit a star
topology. Rather, it is best to have a long line, with only short
branches off of it where the sensors are attached.

Maxim Integrated has a tutorial, `Guidelines for Reliable Long Line
1-Wire Networks
<https://www.maximintegrated.com/en/app-notes/index.mvp/id/148>`__. There
they define the terms *radious* and *weight*; it is definitely worth
reading.

Error Symptoms
..............

* **Devices disappear**, and are replaced by ones that are named like
  ``00-0c4000000000``. Here, ``00`` is the family which is completely
  bogus; for example, 28 (hex) would be the expected family. (I
  believe 0x28 stands for "Dallas").

* **Reading fails a CRC check**,

  .. code-block:: console

     $ cat /sys/bus/w1/devices/28-02131d9920aa/w1_slave 
     20 01 4b 46 7f ff 0c 10 5d : crc=5d NO
     20 01 4b 46 7f ff 0c 10 5d t=18000

* **Reading gives me a temperature of 0 degrees.**

  .. code-block:: console

     $ cat /sys/bus/w1/devices/28-011432f138f9/w1_slave 
     00 00 00 00 00 00 00 00 00 : crc=00 YES
     00 00 00 00 00 00 00 00 00 t=0

  This is the worst thermometer error you can encounter because it
  does not declare himself as such. One can imagine what sorts of
  heating control misbehavior a room temperature of zero degrees would
  cause.

In my experience [#not-a-hw-guy]_, the bitbanging driver is only good
for the most trivial setups. As soon as you have a larger
installation, you'll see errors of the above sort over and over.

Over time, I was able to reduce the instabilities by cutting the
initial star topology down to what I describe above. Still, there were
some glitches from time to time. I blame those on the bitbanging in
software. Onewire is a slow and easy protocol, but there are still
timing constraints that might not be met in some cases.

Sure, I could have tried the Linux realtime options to get better
response and timing guarantees. On the other hand, heating control is
something that is exactly the opposite of realtime. If a pump is
turned on a minute too late, still nothing burns down - this is not a
nuclear power plant.

So no: no realtime wanted. Especially because it would have been just
another tryout.

Links
-----

* `Kernel Onewire documentation
  <https://www.kernel.org/doc/html/latest/w1/w1-generic.html>`__
* `DS18B20 datasheet
  <https://www.maximintegrated.com/en/products/DS18B20>`__

.. rubric:: Footnotes

.. [#not-a-hw-guy] I am not a hardware expert.
