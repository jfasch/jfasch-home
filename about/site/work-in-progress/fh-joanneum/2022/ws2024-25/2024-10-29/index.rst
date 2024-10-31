.. include:: <mmlalias.txt>


2024-10-29(6): Project: Git, C++, Status
========================================

.. contents::
   :local:

Crazy Car Software Architecture
-------------------------------

.. libreoffice:: architecture.odg


Project Status
--------------

:doc:`../project/motor-control-btn9960lv`
.........................................

* PWM test prog configures PWM pin, but leaves it in non-functional
  state after exit.

  * Fork there? Added test prog there? CMakery?
  * Perform manually the steps that the program makes
  * Look at program
  * Fix program
  * See how program should make use of `toolcase/base/sysfs-file.h
    <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/sysfs-file.h>`__
  * |longrightarrow| CMakery

:doc:`../project/servo-motor`
.............................

* Check WiringPi: fork there? WiringPi test prog there?

  Clarify WiringPi is not an option:

  * WiringPi test prog
  * If not: my Pi: ``~/myapp.c``
  * Explain ``/dev/mem`` (`man -s 4 mem
    <https://man7.org/linux/man-pages/man4/mem.4.html>`__)

* In the long term, we will have to use PCA9685A anyway: we need 3 PWM
  pins in total, and the Pi has (at most?) 2. Best to give up.

  * In case somebody want to try Pi nonetheless:
    https://github.com/dotnet/iot/blob/main/Documentation/raspi-pwm.md

    There appear to be clock issues ahead, as
    https://github.com/raspberrypi/linux/issues/1533
    indicates. Beware.

:doc:`../project/proximity-vl53l1x`
...................................

* Hmm. C++ needed. Wait a few hours, we'll get to that.
* |longrightarrow| what would a ``class VL53L1X`` look like?

:doc:`../project/gyroscope-bno055`
..................................

* Fork there? Test prog there? CMakery?
* Commandline program where we can try around
* |longrightarrow| what would a ``class BNO055`` look like?

Configuration Management (Err, Git)
-----------------------------------

* :doc:`/about/site/work-in-progress/fh-joanneum/2021/git/git`

C++: OO Basics
--------------

From
:doc:`/trainings/material/soup/cxx03/020-data-encapsulation/group` ...

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/c`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/initializer-list`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`

From
:doc:`/trainings/material/soup/cxx03/030-functions-and-methods/group` ...

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/040-this/topic`

Live hack that into the ubiquitous ``class point`` (see
`livecoding/point.cpp
<https://github.com/jfasch/FH-STECE2022/blob/main/livecoding/point.cpp>`__)


.. _fh-2022--2024-10-29-homework:

Homework Until 2024-11-05
-------------------------

.. contents::
   :local:

Intro
.....

**Sensors**

Two relatively autonomous tasks, :doc:`../project/proximity-vl53l1x`
and :doc:`../project/gyroscope-bno055`. Good luck |:ninja:|

**Motor Controls**

We have two PWM users, so we want to coordinate. Write a tool for it,

* :doc:`../project/sysfs-pwm`

``class SysFSPWMPin`` can then be used from

* :doc:`../project/motor-control-btn9960lv` and
* :doc:`../project/servo-motor`.

So please lets ...

* Sync your fork with upstream
* Read through specific "workpackage" descriptions below

(Talk about it here: :doc:`../2024-11-05/index`)

"Sync Your Fork" (Github term)
..............................

*Please update your fork with the upstream changes from*
https://github.com/jfasch/FH-STECE2022.

See :doc:`/about/site/work-in-progress/fh-joanneum/2021/git/git` about
that workflow, especially :ref:`fh-2021-git-sync-fork-from-upstream`.

What is new there:

* A failing unit test or two for :doc:`../project/sysfs-pwm`
* Fixes for ``proximity-vl53l1x``, see
  `proximity-vl53l1x/proximity-vl53l1x/bin/CMakeLists.txt
  <https://github.com/jfasch/FH-STECE2022/blob/main/proximity-vl53l1x/proximity-vl53l1x/bin/CMakeLists.txt>`__
* Fixes, and more tests for `class SysFSFile
  (toolcase/base/sysfs-file.h)
  <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/sysfs-file.h>`__
  where we can use common code from.

.. code-block:: console

   [jfasch@jflaptop ~/My-Builds/FH-STECE2022-x86_64]
   $ ./tests/fh-stece22-suite 
   ...
   [ RUN      ] sysfs_pwm_pin_suite.get_period
   /home/jfasch/My-Projects/FH-STECE2022/tests/sysfs-pwm-pin-tests.cpp:41: Failure
   Expected equality of these values:
     pin.period()
       Which is: -666
     PERIOD_NS_INIT
       Which is: 10000000
   
   [  FAILED  ] sysfs_pwm_pin_suite.get_period (0 ms)
   [ RUN      ] sysfs_pwm_pin_suite.add_your_own_tests_here
   /home/jfasch/My-Projects/FH-STECE2022/tests/sysfs-pwm-pin-tests.cpp:53: Failure
   Failed
   ...

Write ``class SysFSPWMPin`` (Group :doc:`../project/servo-motor`)
.................................................................

* Write ``class SysFSPWMPin`` (respectively, complete the skeleton
  `toolcase/base/sysfs-pwm-pin.h
  <https://github.com/jfasch/FH-STECE2022/blob/main/toolcase/base/sysfs-pwm-pin.h>`__)
* Requirements in `tests/sysfs-pwm-pin-tests.cpp
  <https://github.com/jfasch/FH-STECE2022/blob/main/tests/sysfs-pwm-pin-tests.cpp>`__

  **Use test suite during development, until all green**

  .. code-block:: console

     [jfasch@jflaptop ~/My-Builds/FH-STECE2022-x86_64]
     $ ./tests/fh-stece22-suite
     Running main() from /home/jfasch/My-Projects/FH-STECE2022/googletest/googletest/src/gtest_main.cc
     [==========] Running 5 tests from 2 test suites.
     [----------] Global test environment set-up.
     [----------] 4 tests from sysfs_file_suite
     [ RUN      ] sysfs_file_suite.read_int64_with_linefeed
     [       OK ] sysfs_file_suite.read_int64_with_linefeed (0 ms)
     [ RUN      ] sysfs_file_suite.read_int64_without_linefeed
     [       OK ] sysfs_file_suite.read_int64_without_linefeed (0 ms)
     [ RUN      ] sysfs_file_suite.write_int64
     [       OK ] sysfs_file_suite.write_int64 (0 ms)
     [ RUN      ] sysfs_file_suite.write_int64_truncate
     [       OK ] sysfs_file_suite.write_int64_truncate (0 ms)
     [----------] 4 tests from sysfs_file_suite (0 ms total)
     
     [----------] 1 test from sysfs_pwm_pin_suite
     [ RUN      ] sysfs_pwm_pin_suite.get_period
     /home/jfasch/My-Projects/FH-STECE2022/tests/sysfs-pwm-pin-tests.cpp:41: Failure
     Expected equality of these values:
       pin.period()
         Which is: -666
       PERIOD_NS_INIT
         Which is: 10000000
     
     [  FAILED  ] sysfs_pwm_pin_suite.get_period (0 ms)
     [----------] 1 test from sysfs_pwm_pin_suite (0 ms total)
     
     [----------] Global test environment tear-down
     [==========] 5 tests from 2 test suites ran. (0 ms total)
     [  PASSED  ] 4 tests.
     [  FAILED  ] 1 test, listed below:
     [  FAILED  ] sysfs_pwm_pin_suite.get_period
     
      1 FAILED TEST
    
* Test program in `bin/pwm-test.cpp
  <https://github.com/jfasch/FH-STECE2022/blob/main/bin/pwm-test.cpp>`__;
  feel free to modify

Halfbridge Horror (Group :doc:`../project/motor-control-btn9960lv`)
...................................................................

Tinker With Hardware, Think About Future.

* Figure out how to operate the halfbridges

  * Can we use a comparator to operate both in parallel, using one
    PWM?
  * Do we need two?
  * Ask for permission to publish a copy of the schematic and print
    under GPLv3 in our repo.

* Think about how this can be done in software

  * See :ref:`fh2022-motor-control-btn9960lv-software-interface` for
    an idea how it could look like

VL53L1X (Group :doc:`../project/proximity-vl53l1x`)
...................................................

* Make it work, simply

BNO055 (Group :doc:`../project/gyroscope-bno055`)
.................................................

* Figure out what we need, by trying around with the commandline
  program that you brought
* How could a ``class BNO055`` look like?
