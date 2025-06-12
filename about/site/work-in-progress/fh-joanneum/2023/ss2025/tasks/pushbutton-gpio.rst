PushButton/GPIO
===============

.. contents;:
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/hardware/libgpiod/index`

Goal
----

Create a ``PushButton`` implementation ``PushButtonGPIO`` that uses
``libgpiod`` to read the switch states.

How
---

.. code-block:: c++

   class PushButtonGPIO : public PushButton
   {
   public:
       PushButtonGPIO(const std::string& gpiodevice, int line_number);
       ...
   };

* ``gpiodevice`` is for example ``/dev/gpiochip0``
* ``line_number`` is the number of the GPIO line (see for example the
  Raspberry Pi pinout diagram)

Use the ``libgpiod`` library to implement the ``get_state()`` method.

Testing
-------

Real hardware cannot be tested using unit tests (at least not
easily). Write a test program (in ``tests/``) that uses
``PushButtonGPIO`` to read the switch state and output its value.
