Exercise: Reading A Sensor (Driven By Tests)
============================================

.. contents::
   :local:

Setup
-----

Clone, setup, and build https://github.com/jfasch/FH-STECE2022 (see
instructions on the project page)

``exercises/02-sensor``: Exercise Structure
-------------------------------------------

In ``exercises/02-sensor`` there exist the following directories,

* ``bin/`` has ``read-sensor.c`` - the main program (see below)
* ``lib/`` has the library - the sensor implementation
* ``tests/`` has the unit tests that define the sensor functionality

We start by running the tests - *these remain unchanged*, and fixing
``lib/sensor.c`` until all tests are green. Only then we implement
``bin/read-sensor.c``.

``tests/suite-sensor.cpp``: Unit Tests (Requirements Definition)
----------------------------------------------------------------

In the ``tests/`` directory,

.. code-block:: console

   $ pwd                           # <--- build directory
   /home/jfasch/My-Builds/FH-STECE2022-x86_64
   $ ./exercises/02-sensor/tests/02-sensor-tests 
   ... OMG: all tests fail! ...

Now we can start to fix ``lib/sensor.c`` until the test are green.

``lib/sensor.c``: Sensor Implementation
---------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/basics/errorhandling`

.. sidebar:: Documentation

   * `man -s 3 sscanf
     <https://man7.org/linux/man-pages/man3/sscanf.3.html>`__
   * `man -s 3 errno
     <https://man7.org/linux/man-pages/man3/errno.3.html>`__
   * `The Valgrind Quick Start Guide
     <https://valgrind.org/docs/manual/quick-start.html>`__

Fix until tests are green.

**Hints**

* The relevant ``errno`` values are

  * ``ENOENT``
  * ``EACCES``

* See `man -s 3 sscanf
  <https://man7.org/linux/man-pages/man3/sscanf.3.html>`__ for string
  to integer conversion.
* Use the ``valgrind`` (`The Valgrind Quick Start Guide
  <https://valgrind.org/docs/manual/quick-start.html>`__) tool to
  check for errors.

  .. code-block:: console

     $ valgrind --track-fds=yes ./exercises/02-sensor/tests/02-sensor-tests 
     ... leaks ...

* Especially, try hard to close the file descriptor in any case.

``bin/read-sensor.c``: Sensor Reading Program (But Wait!)
---------------------------------------------------------

The final goal is to have a program that can read a sensor value. In
fact, it is supposed to read a file like
``/sys/bus/w1/devices/28-02131d959eaa/temperature`` that contains the
temperature in milli degrees Celsius.

.. code-block:: console

   $ cat /sys/bus/w1/devices/28-02131d959eaa/temperature
   21340
   $ ./exercises/02-sensor/bin/read-sensor /sys/bus/w1/devices/28-02131d959eaa/temperature
   21.34

But lets not use hardware until we go into the integration test
phase. We can just as well read an ordinary file instead,

.. code-block:: console

   $ echo 21340 > /tmp/temperature
   $ ./exercises/02-sensor/bin/read-sensor /tmp/temperature
   21.34

That program should read the sensor file, and output the temperature
in a floating point format, representing degrees in Celsius.

The program should not open and the file in its ``main()`` function,
but rather use a function ``read_temperature()`` that we define in the
next step.

Submission
----------

The entire project source is submitted. You have a ``FH-STECE2022/``
directory somewhere which is the cloned project's root, and this is
what's in the submitted tar file.

.. code-block:: 

   $ tar -J -c -f submission.tar.xz FH-STECE2022/

* Submit ``submission.tar.xz``

.. attention::

   * **Build outside the source tree!**
   * **Only source code is submitted!**
