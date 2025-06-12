Motor/GPIO (Simulating Motor With LEDs)
=======================================

.. contents;:
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/hardware/libgpiod/index`

Goal
----

Create a ``Motor`` implementation, ``MotorLED``, that does not rreally
drive a motor. Rather it uses two LEDs - ``forward`` and
``backward`` - that are used as indicators for the motor driving
direction. Both off means "motor idle". The LEDs are driven using
``libgpiod``.

How
---

.. code-block:: c++

   class MotorLED : public Motor
   {
   public:
       MotorLED(const std::string& gpiodevice, int line_number_forward, int line_number_backward);
       ...
   };

* ``gpiodevice`` is for example ``/dev/gpiochip0``
* ``line_number_forward`` and ``line_number_backward`` are the numbers
  of the respective GPIO line (see for example the Raspberry Pi pinout
  diagram)

Use the ``libgpiod`` library to implement the ``forward()``,
``backward()``, and ``stop()`` methods.

Testing
-------

Real hardware cannot be tested using unit tests (at least not
easily). Write a test program (in ``tests/``) that uses ``MotorLED``
to manipulate the LED states.
