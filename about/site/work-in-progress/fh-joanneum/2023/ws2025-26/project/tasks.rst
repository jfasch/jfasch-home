.. include:: <mmlalias.txt>

Tasks
=====

.. contents::
   :local:

.. _fh-2025-assignments:


..    * * ref task
..      * **ReinRaus**
..      * **Abrissbirne**
..      * **DieSeinigen**
..      * **Knepferldrucker**
..      * **HighPressure**
..      * **DingsbumsSPS**
..      * **NukeIt**





.. * **ReinRaus**    :ref:`fh-ws2025-26-task-sysfs-gpio`
.. * **Abrissbirne**  :ref:`fh-ws2025-26-task-struct-refact`, :ref:`fh-ws2025-26-task-how-to-include-files`
.. * **DieSeinigen** :ref:`fh-ws2025-26-task-testrack`
.. * **Knepferldrucker** :ref:`fh-ws2025-26-task-copy-delete`, :ref:`fh-ws2025-26-task-rm-light-push`
.. * **HighPressure** :ref:`fh-ws2025-26-task-ads1115` adc unification
.. * **DingsbumsSPS**

..   * :ref:`fh-ws2025-26-task-graceful-termination`
..   * inputs etc mit adc jungs klaeren



   
.. .. list-table:: 
..    :align: left
..    :header-rows: 1
.. 
..    * * Team
..      * Assigment
..    * * **ReinRaus**
..      * :ref:`fh-ws2025-26-task-sysfs-gpio`
..    * * **Abrissbirne**
..      * :ref:`fh-ws2025-26-task-struct-refact`,
..        :ref:`fh-ws2025-26-task-how-to-include-files`
..    * * **DieSeinigen**
..      * :ref:`fh-ws2025-26-task-testrack`
..    * * **Knepferldrucker**
..      * :ref:`fh-ws2025-26-task-copy-delete`,
..        :ref:`fh-ws2025-26-task-rm-light-push`
..    * * **HighPressure**
..      * :ref:`fh-ws2025-26-task-ads1115`
..    * * **DingsbumsSPS**
..      * :ref:`fh-ws2025-26-task-graceful-termination`

Small Linux (Busybox)
---------------------

* ramdisk, early boot
* -> Yocto

.. _fh-ws2025-26-task-graceful-termination:

Graceful Termination (Done)
---------------------------

**DingsbumsSPS**

* In ``bin/run-door.cpp`` introduce signal handling for ``SIGINT`` and
  ``SIGTERM``
* ... to terminate gracefully, drop out of the main loop
* Before exit, perform necessary cleanup (done by destructors,
  mostly), and print a "bye" message.

.. _fh-ws2025-26-task-sysfs-gpio:

``sysfs`` GPIO (Done)
---------------------

**Reinraus**

* Yet another ``{In,Out}putSwitch`` implementation
* Advantage: relieves us (for a moment) from the pain of ``libgpiod``.
* There is this one loopback test where one IO sees *immediately* the
  update of another - this is fragile, we want to see that test pass
  :-)
* Probably write some nice helper routines to read/write typical sysfs
  files

*please* 

.. topic:: See also

   From :doc:`/trainings/material/soup/linux/sysprog/intro-hw/index`

   * :doc:`/trainings/material/soup/linux/sysprog/intro-hw/sysfs-gpio`
   * :doc:`/trainings/material/soup/linux/sysprog/intro-hw/get`

     Careful on export:

     .. code-block:: shell

        # export GPIO
        echo $GPIO > /sys/class/gpio/export
        
        # give system time to export GPIO (sadly, this is an asynchronous
        # operation)
        sleep 1

.. _fh-ws2025-26-task-struct-refact:

Structural Refactoring (Ongoing)
--------------------------------

**Abrissbirne**

.. topic:: Documentation

   * `A ReStructuredText Primer
     <https://docutils.sourceforge.io/docs/ref/rst/directives.html>`__
   * `reStructuredText Directives
     <https://docutils.sourceforge.io/docs/ref/rst/directives.html>`__
     (spoiler: ``image`` or ``figure``)

.. topic:: Discussion notes

   **2025-11-10**

   * submodules, starting with ``utilities/timespec.{h,cpp}``
   * structural, focus on user/programmer comphrendability
   * e.g. ``motor`` would then consist of: interface, mock, led,
     stepper
   * nodes with dependencies nonetheless
   * most depend on ``utilities``, for example
   * Drawback of cramming interface, lightweight implementations
     (e.g. mocks) into *the same library*: code size.

     If only the interface, or a lightweight implementation, is
     needed, the *entire library* is among the dependencies -
     including all its heavyweight (regarding code size) members.

     That superfluous code will not be loaded into memory though -
     this is done on-demand when the code is executed. (See
     :doc:`/trainings/material/soup/linux/toolchain/basics/topic`.)
   * If it hurts, we can modify anyway. Jetzt kemmas scho.

     Can be worse though: `How the XZ backdoor works
     <https://lwn.net/Articles/967192/>`__, especially the role of
     libsystemd.

* Konzept: structure diagram, dependency diagram in gh/README.rst
* Include paths? Siehe task :ref:`fh-ws2025-26-task-how-to-include-files`
* Dependencies (``cmake --graphviz``), see :ref:`cmake-graphviz`
* Coordinate with other teams

  * Communicate major upstream updates to pull/sync
  * ``#include`` rules, see :ref:`fh-ws2025-26-task-how-to-include-files`
  * ...

* Remove ``libgpiod`` usage from unit tests
* Rollout of ``{In,Out}putSwitch``, and especially of
  ``{In,Out}putSwitchGPIO``, we are for a moment safe from
  ``libgpiod`` woes.

  Eliminate all uses of ``libgpiod``, in favor of the
  ``{In,Out}putSwitch`` interface.

  * ``MotorLED`` (if not yet done)
  * ``MotorStepper`` (if not yet done)


.. _fh-ws2025-26-task-testrack:

Test Rack (Ongoing)
-------------------

**DieSeinigen**

* Define the software implications of using this as door environment
* How do we create input to *our* inputs? See
  ``src/door/structs.h``. Discuss with PLC guys (aka DingsbumsSPS)
* How would ``Motor`` interface be implemented?
* ``jfasch`` to ask ``msallok`` if we can borrow the panel for
  integration tests, occasionally

.. _fh-ws2025-26-task-analog-sensor:

Analog Sensor Interface (Ongoing)
---------------------------------

Unify pressure sensor and adc (1115) under the hood of one
``AnalogSensor`` interface where you can use ``get_value() ->
double``.

.. plantuml::
       
   @startuml
   
   interface AnalogSensor {
     + double get_value()
   }

   class PressureSensorBMP { }
   class ADC1115 {}
   class MockSensor {}

   AnalogSensor <|.. PressureSensorBMP
   AnalogSensor <|.. ADC1115
   AnalogSensor <|.. MockSensor
   
   @enduml

.. _fh-ws2025-26-task-integration-tests:

Integration Tests (Ongoing)
---------------------------

.. topic:: Coordinate!

   See :ref:`Panel task <fh-ws2025-26-task-testrack>`.

* Based on some configuration (commandline switch, like ``--test``, or
  variations like ``--half-real``), instantiate objects
  *polymorphically*.
* To instantiate these objects, you need to define hardware parameters
  
  * GPIO pins. Coordinate with :ref:`fh-ws2025-26-task-sysfs-gpio` for
    sysfs GPIO parameters, and probably find a way to unify those with
    the future ``libgpiod`` parameters.
  * I2C bus numbers and addresses for pressure sensor and ADC
    (coordinate with these guys regarding parameterization)
  * PWM config. how's that done? need to define a PWM task that makes
    something like this true:

    * ``period``, set at the beginning (of what), used throughout
      lifetime
    * Users would then probably measure their share of the period in
      percent
    * Or, like the stepper motor, be constructed with a proposed
      duty_cycle for each of forward, backward, stop, like

      .. code-block:: c++

         PWMPin pwm(/*chip=*/0, /*channel=*/0, /*period=*/10_000_000);
         OutputSwitchGPIOSysfs direction = ... ; // oder so
         OutputSwitchGPIOSysfs wasnoch = ... ; // fuer was war der zweite gleich?
   
         MotorStepper motor(&pwm, &direction, &wasnoch,
	                    /*left=*/2_000_000, /*idle=*/5_000_000, /*right=*/8_000_000);
   
         motor.forward(); // <-- see what happens

* Anyway: one we have polymorphic HW objects, we can pass those into
  ``Inputs()`` and ``Outputs()``

.. _fh-ws2025-26-task-copy-delete:

``=delete`` Copy Where Appropriate (Done)
-----------------------------------------

**Knepferldrucker**

.. topic:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/oo/delete`

* Find out list of such candidates (all the GPIO switches, supposedly,
  as a start)
* Discuss
* Fix

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

RFID Reader?
------------

* Flipper Zero as a starting point (read payload with something that
  works)
* Raspi/I2C to a reader device
* Open/close as reader devices

.. _fh-ws2025-26-task-how-to-include-files:

How to include files (Done)
---------------------------

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

.. _fh-ws2025-26-task-rm-light-push:

Remove Light Barrier And Push Putton (Done)
-------------------------------------------

**Knepferldrucker**

Remove entirely:

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

.. _fh-ws2025-26-task-ads1115:

ADC/ADS1115 (Ongoing)
---------------------

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
