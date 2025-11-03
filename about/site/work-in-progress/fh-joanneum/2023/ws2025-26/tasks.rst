.. include:: <mmlalias.txt>


Tasks: Rafactoring, Realtime Behavior, ...
==========================================

.. _fh-ws2023-task-panel:

Another Panel
-------------

See ``textualize``

Panel
-----

There is a panel somewhere ...

Integration Tests
-----------------

Somebody take care of the setup phase in ``run-door.cpp``. Based on
some configuration (commandline switch, like ``--simu``, ``--real``,
...), instantiate object *polymorphically*.

* ``InputSwitchMock``, ``InputSwitchGPIO``
* ``OutputSwitchMock``, ``OutputSwitchGPIO``
* ``MotorLED``, ``MotorStepper``, ``MotorMock``

Coordinate with :ref:`Panel task <fh-ws2023-task-panel>`.

Main ``run-door.cpp``: Instantiate HW/Mock Objects
--------------------------------------------------

* Define some (preliminary) config ``use_mock = {true|false}``, and
  pass that into ``main()``
* Based on that, instantiate mock or real-hw objects
* Bring it into ``Inputs()`` and ``Outputs()``

Graceful Termination
--------------------

* Signal handling, as explaind in course
* Before termination, call dtors of all objects that are alive in
  ``main()``

How to include files
--------------------

* ``file.cpp`` includes its own ``file.h``, or any other file *from
  the same directory*. Such files are included like ``#include ""``

  * *Right*: ``#include "file.h"``
  * *Wrong*: ``#include <door/file.h>``

  .. code-block:: console

     $ pwd
     /home/jfasch/My-Projects/FH-STECE2023/src/door
     $ grep 'door/' *.h *.cpp
     event-edge-detector.h:#include <door/input-switch.h>
     event-edge-detector.h:#include <door/timespec.h>
     outputs.h:#include <door/structs.h>
     outputs.h:#include <door/motor.h>
     event-edge-detector.cpp:#include <door/event-edge-detector.h>
     outputs.cpp:#include <door/motor.h>

* ``file.h`` or ``file.cpp`` in directory ``A`` includes
  ``anotherfile.h`` from directory ``B``

  * *Wrong*: ``#include <../B/anotherfile.h>``
  * *Right*: ``#include <B/anotherfile.h>`` - *and* a dependency
    declaration ``A -> B`` in ``A/CMakeLists.txt``

  .. code-block:: console

     $ pwd
     /home/jfasch/My-Projects/FH-STECE2023/tests
     $ grep 'include.*\.\.' *.cpp
     input-switch-gpio-tests.cpp:#include "../src/door/input-switch-gpio.h"
     light-barrier-gpio-tests.cpp:#include "../src/door/light-barrier-gpio.h"
     motorLED-tests.cpp:#include "../src/door/motorLED.h"
     motor-stepper-tests.cpp:#include "../src/door/motor-stepper.h"
     push-button-gpio-test.cpp:#include "../src/door/push-button-gpio.h"

Remove Light Barrier And Push Putton (In Favor Of ``{in,out}put-switch*``)
--------------------------------------------------------------------------

.. code-block:: console
   :caption: ``door/CMakeLists.txt``

   light-barrier.h
   light-barrier-mock.h
   light-barrier-mock.cpp
 
   push-button.h
   push-button-mock.h
   push-button-mock.cpp

SPS Machinery: State Machine Not As It Was Before
-------------------------------------------------

State ``OPENING`` not implemented as it was in old implementation. Old
code is still there in comments, but not implemented in the new
version.

Comment ``TEST(door_suite, straightforward_open)`` back in and see.

SPS Machinery: Cosmetics
------------------------

* ``class Inputs``: names ``_button`` / ``_button2`` and
  ``_lightbarrier`` / ``_lightbarrier2`` don't speak
* ``door/structs.h``
  
  * File naming could be done better
  * ``typedef`` not necessary in C++

Switches
--------

``src/door/input-switch-gpio.h``: ctor takes ``unsigned int*
line_number`` - why pointer? (output switch does *not*.)

ADC/ADS1115
-----------

* War da nicht eine Schwellwert-Trigger-Sache ausgemacht?
* What does PR's ``adc test works when joystick is not moved and fails
  if moved.`` mean?
* ``get_value()``: ``usleep(8 * 1000)`` is not good for realtime
  operation. can the device do continuous conversion?
* Clarify future use (motor is stuck)

Motor/Stepper
-------------

* ``writeData()``: use raw file IO
* Use ``OutputSwitchGPIO`` rather than ``libgpiod`` directly
