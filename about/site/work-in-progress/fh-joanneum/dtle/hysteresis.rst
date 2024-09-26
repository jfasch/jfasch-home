.. include:: <mmlalias.txt>


Exercise: ``Hysteresis``
========================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Requirement
-----------

Implement a class ``Hysteresis`` (a Thermostat) that works as follows.

* It uses a sensor (``MockSensor``) to measure the temperature
* It controls a switch (a ``MockSwitch``)
* If the temperature falls below a certain configurable *low*
  threshold, the switch is set to *on* (heating is turned *on*)
* If the temperature rises above a certain configurable *high*
  threshold, the switch is set to *off* (heating is turned *on*)

Use the following tests to drive you through the exercise:

.. literalinclude:: code/tests/hysteresis-nop_when_within_range.cpp
   :language: c++
   :caption: :download:`Download hysteresis-nop_when_within_range.cpp
	     <code/tests/hysteresis-nop_when_within_range.cpp>`

.. literalinclude:: code/tests/hysteresis-falls_below_range.cpp
   :language: c++
   :caption: :download:`Download
             hysteresis-falls_below_range.cpp
             <code/tests/hysteresis-falls_below_range.cpp>`

.. literalinclude:: code/tests/hysteresis-rises_above_range.cpp
   :language: c++
   :caption: :download:`Download hysteresis-rises_above_range.cpp
             <code/tests/hysteresis-rises_above_range.cpp>`

.. literalinclude:: code/tests/hysteresis-rises_above_range_when_on.cpp
   :language: c++
   :caption: :download:`Download
             hysteresis-rises_above_range_when_on.cpp
             <code/tests/hysteresis-rises_above_range_when_on.cpp>`

Work Instructions
-----------------

In the following, ``~/My-Projects`` and ``~/My-Builds`` are
placeholders for directory name that you may choose.

* ``~/My-Projects`` contains code written by *you*
* ``~/My-Builds`` contains *builds*, i.e. material that can be removed
  and recreated

Preparation
...........

* Download dtle-2024.tar.bz2 jjj
* Unpack into source directory

  .. code-block:: console

     $ cd ~/My-Projects
     $ tar -x -j -f path/to/dtle-2024.tar.bz2

* Create build directory, and change into it

  .. code-block:: console

     $ mkdir ~/My-Builds/dtle-2024-build
     $ cd ~/My-Builds/dtle-2024-build

* Build what you downloaded (CWD is ~/My-Builds/dtle-2024-build)

  .. code-block:: console

     $ pwd
     $ ~/My-Builds/dtle-2024-build
     $ cmake ~/My-Projects/dtle-2024
     ... roedel ...
     $ make
     ... roedel ...

* Check project state: test failures

  .. code-block:: console

     $ pwd
     $ ~/My-Builds/dtle-2024-build
     $ ./tests/dtle-hysteresis-suite 
     Running main() from ~/My-Projects/dtle-2024/googletest/googletest/src/gtest_main.cc
     [==========] Running 4 tests from 1 test suite.
     [----------] Global test environment set-up.
     [----------] 4 tests from hysteresis_suite
     [ RUN      ] hysteresis_suite.falls_below_range
     ~/My-Projects/dtle-2024/tests/hysteresis-falls_below_range.cpp:20: Failure
     Expected equality of these values:
       switcH.state()
         Which is: 1
       MockSwitch::ON
         Which is: 0
     
     [  FAILED  ] hysteresis_suite.falls_below_range (0 ms)
     [ RUN      ] hysteresis_suite.nop_when_within_range
     [       OK ] hysteresis_suite.nop_when_within_range (0 ms)
     [ RUN      ] hysteresis_suite.rises_above_range
     [       OK ] hysteresis_suite.rises_above_range (0 ms)
     [ RUN      ] hysteresis_suite.rises_above_range_when_on
     ~/My-Projects/dtle-2024/tests/hysteresis-rises_above_range_when_on.cpp:17: Failure
     Expected equality of these values:
       switcH.state()
         Which is: 1
       MockSwitch::ON
         Which is: 0
     
     [  FAILED  ] hysteresis_suite.rises_above_range_when_on (0 ms)
     [----------] 4 tests from hysteresis_suite (0 ms total)
     
     [----------] Global test environment tear-down
     [==========] 4 tests from 1 test suite ran. (0 ms total)
     [  PASSED  ] 2 tests.
     [  FAILED  ] 2 tests, listed below:
     [  FAILED  ] hysteresis_suite.falls_below_range
     [  FAILED  ] hysteresis_suite.rises_above_range_when_on
     
      2 FAILED TESTS
    
Implementation
..............

* In ``~/My-Project/toolcase``, you'll find two files, 

  * ``hysteresis.h``
  * ``hysteresis.cpp``

  Fix the code in these files.

  **These are the only files that must be modified! Do not modify anything else!**

* Repeat the cycle

  * Modify code
  * Build (``make``)
  * Test (``./tests/dtle-hysteresis-suite``)

  until all tests are green

  .. code-block:: console

     $ ./tests/dtle-hysteresis-suite 
     Running main() from ~/My-Projects/dtle-2024/googletest/googletest/src/gtest_main.cc
     [==========] Running 4 tests from 1 test suite.
     [----------] Global test environment set-up.
     [----------] 4 tests from hysteresis_suite
     [ RUN      ] hysteresis_suite.falls_below_range
     [       OK ] hysteresis_suite.falls_below_range (0 ms)
     [ RUN      ] hysteresis_suite.nop_when_within_range
     [       OK ] hysteresis_suite.nop_when_within_range (0 ms)
     [ RUN      ] hysteresis_suite.rises_above_range
     [       OK ] hysteresis_suite.rises_above_range (0 ms)
     [ RUN      ] hysteresis_suite.rises_above_range_when_on
     [       OK ] hysteresis_suite.rises_above_range_when_on (0 ms)
     [----------] 4 tests from hysteresis_suite (0 ms total)
     
     [----------] Global test environment tear-down
     [==========] 4 tests from 1 test suite ran. (0 ms total)
     [  PASSED  ] 4 tests.
