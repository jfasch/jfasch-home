.. include:: <mmlalias.txt>


Tasks: Rafactoring, Realtime Behavior, ...
==========================================

.. contents::
   :local:

Small Linux (Busybox)
---------------------

* ramdisk, early boot
* -> Yocto

Graceful Termination
--------------------

**DingsbumsSPS**

* In ``bin/run-door.cpp`` introduce signal handling for ``SIGINT`` and
  ``SIGTERM``
* ... to terminate gracefully, drop out of the main loop
* Before exit, perform necessary cleanup (done my destructors,
  mostly), and print a "bye" message.

Eliminate Direct ``libgpiod`` Uses
----------------------------------

Rollout of ``{In,Out}putSwitch``, and especially of
``{In,Out}putSwitchGPIO``, we are for a moment safe from ``libgpiod``
woes.

Eliminate all uses of ``libgpiod``, in favor of the
``{In,Out}putSwitch`` interface.

* ``MotorLED``
* ``MotorStepper``

``sysfs`` GPIO
--------------

**Reinraus**

* Yet another ``{In,Out}putSwitch`` implementation
* Advantage: relieves us (for a moment) from the pain of ``libgpiod``.
* There is this one loopback test where one IO sees *immediately* the
  update of another - this is fragile, we want to see that test pass
  :-)

.. _fh-ws2023-task-struct-refact:

Structural Refactoring
----------------------

**Abrissbirne**

.. topic:: Documentation

   * `A ReStructuredText Primer
     <https://docutils.sourceforge.io/docs/ref/rst/directives.html>`__
   * `reStructuredText Directives
     <https://docutils.sourceforge.io/docs/ref/rst/directives.html>`__
     (spoiler: ``image`` or ``figure``) ``image``)

* Konzept: structure diagram, dependency diagram in gh/README.rst
* Include paths? Siehe task :ref:`fh-ws2025-task-how-to-include-files`
* Dependencies (``cmake --graphviz``), see :ref:`cmake-graphviz`
* Coordinate with other teams

  * Communicate major upstream updates to pull/sync
  * ``#include`` rules, see :ref:fh-ws2025-task-how-to-include-files`
  * ...

* Remove ``libgpiod`` usage from unit tests

Utilities
---------

At the level of ``src/door/timespec.{h,cpp}`` ...

* File-IO encapsulation: in sysfs we read and write lots of small
  files. 

  * ``{read,write}_int()``, convenience wrapper
  * ``{read,write}_string()``, convenience wrapper
  * :doc:`Move semantics
    </trainings/material/soup/cxx/cxx11/move/index>`
  * Exceptions: define base exception centrally, for the entire door
    project, and refine to ``OSError`` exception (see
    :doc:`/trainings/material/soup/linux/sysprog/syscalls/errorhandling/index`)
    that is thrown from this module.
  * Write tests: `GoogleTest Assertions Reference
    <https://google.github.io/googletest/reference/assertions.html>`__
    (search for ``ASSERT_THROW(statement,exception_type)``)

Initially, put it flat in ``src/door``, and coordinate with
:ref:`fh-ws2023-task-struct-refact`. Could put more into that module
(the interfaces?).

Test Rack
---------

**DieSeinigen**

* Define the software implications of using this as door environment
* How do we create input to *our* inputs? See
  ``src/door/structs.h``. Discuss with PLC guys.
* How would ``Motor`` interface be implemented?

``=delete`` Copy Where Appropriate
----------------------------------

**Knepferldrucker**

.. topic:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/oo/delete`

* Find out list of such candidates (all the GPIO switches, supposedly,
  as a start)
* Discuss
* Fix

.. _fh-ws2023-task-panel:

A *Textual* User Interface
--------------------------

(See https://www.textualize.io/)

Write a management application (reachable over the terminal/SSH) for
tasks like

* Log viewing. Requires that we have a log somewhere; could have one
  that is e.g. buried in :doc:`python:library/sqlite3`
* Input event injection (e.g. "close-button" pressed)
* Various hardware testing features, like moving the motor back and
  forth and measure various things
* ...

Panel
-----

There is a panel somewhere in the PLC world ...

RFID Reader?
------------

* Flipper Zero as a starting point (read payload with something that
  works)
* Raspi/I2C to a reader device
* Open/close as reader devices

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

.. _fh-ws2025-task-how-to-include-files:

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

**Knepferldrucker**

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

**HighPressure**

* Da war eine Schwellwert-Trigger-Sache ausgemacht!
* What does PR's ``adc test works when joystick is not moved and fails
  if moved.`` mean?
* ``get_value()``: ``usleep(8 * 1000)`` is not good for realtime
  operation. can the device do continuous conversion?
* Clarify future use (motor is stuck)

Motor/Stepper
-------------

* ``writeData()``: use raw file IO
* Use ``OutputSwitchGPIO`` rather than ``libgpiod`` directly
