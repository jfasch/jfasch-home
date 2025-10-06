.. include:: <mmlalias.txt>


Embedded Computing 1 (STECE-2023): Winter
=========================================

.. contents::
   :local:

.. sidebar:: Git repo

   https://github.com/jfasch/FH-STECE2023

Lectures, By Date
-----------------

.. toctree::

   2025-10-07/index

Lectures
--------

* Syscalls, error handling, and raw file IO
* C++ copy horror (-> move)

  * ``src/door/input-switch-gpio.h`` as an example
  * demonstrate crash on home pi

* Realtime, and parallelism

  * Small sensor program (ADS1115? BMP?), timing a sensor read -> not
    immediate
  * Enter ``fork()``

Work Queue (*Very* Informal)
----------------------------

How to include files
....................

* ``file.cpp`` includes its own ``file.h``, or ``anotherfile.h``
  from the same directory (or any include inside one directory)

  * *Wrong*: ``#include <door/file.h>``
  * *Right*: ``#include "file.h"``

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
..........................................................................

.. code-block:: console
   :caption: ``door/CMakeLists.txt``

   light-barrier.h
   light-barrier-mock.h
   light-barrier-mock.cpp
 
   push-button.h
   push-button-mock.h
   push-button-mock.cpp

SPS Machinery: State Machine Not As Is Was Before
.................................................

State ``OPENING`` not implemented as it was in old implementation. Old
code is still there in comments, but not implemented in the new
version.

Comment ``TEST(door_suite, straightforward_open)`` back in and see.

SPS Machinery: Cosmetics
........................

* ``class Inputs``: names ``_button`` / ``_button2`` and
  ``_lightbarrier`` / ``_lightbarrier2`` don't speak
* ``door/structs.h``
  
  * File naming could be done better
  * ``typedef`` not necessary in C++

Switches
........

``src/door/input-switch-gpio.h``: ctor takes ``unsigned int*
line_number`` - why pointer? (output switch does *not*.)

ADC/ADS1115
...........

* War da nicht eine Schwellwert-Trigger-Sache ausgemacht?
* What does PR's ``adc test works when joystick is not moved and fails
  if moved.`` mean?
* ``get_value()``: ``usleep(8 * 1000)`` is not good for realtime
  operation. can the device do continuous conversion?
* Clarify future use (motor is stuck)

Motor/Stepper
.............

* writeData(): use raw file IO
* Use OutputSwitchGPIO rather than libgpiod directly
