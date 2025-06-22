LightBarrier/GPIO
=================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/hardware/libgpiod/index`

Meetings/News
-------------

* 2025-06-17: :ref:`2025-06-17-libgpiod-fiasco`

Goal
----

Create a ``LightBarrier`` implementation ``LightBarrierGPIO`` that
uses ``libgpiod`` to read the state of the light barrier.

How
---

.. code-block:: c++

   class LightBarrierGPIO : public LightBarrier
   {
   public:
       LightBarrierGPIO(const std::string& gpiodevice, int line_number);
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
``LightBarrierGPIO`` to read the switch state and output its value.
