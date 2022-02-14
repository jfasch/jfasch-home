.. ot-topic:: ecproposal.ec1.linux.dev_mgmt
   :dependencies: ecproposal.ec1.linux.basics

Linux Hardware Device Management
================================

Given knowledge of the I2C and Onewire hardware protocols, learn how
to treat such devices from userspace on Linux.

There are different aspects to device management, at least regarding
I2C, Onewire, and the semantic aspect of *being a sensor device*

* I2C communication from userspace: using the `I2C bus devices
  <https://www.kernel.org/doc/Documentation/i2c/dev-interface>`__
* Onewire communication from userspace: `the Onewire filesystem
  <https://www.kernel.org/doc/html/latest//w1/index.html>`__
* ``hwmon``, covering *sensor devices* in a generalized way (`here
  <https://www.kernel.org/doc/Documentation/hwmon/sysfs-interface>`__)
