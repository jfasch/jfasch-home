Pressure Sensor
===============

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/hardware/i2c/topic`
   * `BMP280
     <https://www.bosch-sensortec.com/products/environmental-sensors/pressure-sensors/bmp280/>`__

Goal
----

To implement safety use cases in our door project, we use a pressure
sensor to detect whether an obstacle keeps the door from closing.

There are a number of sensors out there. `BMP280
<https://www.adafruit.com/product/992?srsltid=AfmBOoqShGmpYOcCqbhDK51qpYma0MBmB6BmW-ecs_8WmXb0ZUZkYy0U>`__
comes with a nice breakout, it looks like a good candidate to try.

How
---

I2C devices speak a protocol over SDA/SCL which is documented in the
device's data sheet. Lets use ``/dev/i2c-1`` (a software
representation of Raspberry's I2C pins) to implement that protocol in
userspace - inside a class which looks roughly like so ...

.. code-block:: c++

   class BMP280
   {
   public:
       BMP280(const std::string& i2c_dev, unsigned address);
   };

* ``i2c_dev``: the I2C device node, e.g. ``/dev/i2c-1``
* ``address``: the device's address on the bus

Testing
-------

This is not easily unit tested. Write a test program in ``tests/``
that uses an object of type ``BMP280`` to communicate with the device.
