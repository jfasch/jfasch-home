.. ot-exercise:: linux.sysprog.fileio.exercise_w1_sensor
   :dependencies: linux.sysprog.fileio.basics,
		  linux.sysprog.basics.errorhandling,
		  linux.basics.permissions.basics


Exercise: Read Temperature From Onewire Sensor
==============================================

.. contents:: 
   :local:

Onewire Basics
--------------

Have no fear: the setup is done already (see :doc:`here
</trainings/material/soup/linux/hardware/w1/topic>`). In short,
Onewire sensor values are read like so,

.. code-block:: console

   $ cat /sys/bus/w1/devices/28-02131d959eaa/temperature 

``28-02131d959eaa`` is a directory that contains a number of metadata
(represented as files). Of course the name of the directory may be
different between settings. Here ``28`` is the vendor number (Dallas,
I believe), and ``02131d959eaa`` is the device address which is unique
across all devices in the world.

Requirement
-----------

Program
.......

Write a program ``onewire-temperature`` that reads a sensor's
temperature periodically. It takes two arguments,

* Temperature filename
  (``/sys/bus/w1/devices/28-02131d959eaa/temperature`` in case of the
  above example)
* Interval in seconds

.. code-block:: console

   $ ./onewire-temperature /sys/bus/w1/devices/28-02131d959eaa/temperature 2
   24625
   24562
   ...

CMake Build
...........

* Package the program's source code with a ``CMakeLists.txt`` file
  that builds the program from its source
* Put both in a directory ``exercise-sensor-read``
* Pack that directory into a XZ compressed tar archive
  ``exercise-sensor-read.tar.xz``

  .. code-block:: console

     $ tar Jcf exercise-sensor-read.tar.xz exercise-sensor-read

It is that archive that is then uploaded.

Hints, Documentation
--------------------

**File I/O**

* :doc:`/trainings/material/soup/linux/sysprog/file-io/basics`
* :doc:`/trainings/material/soup/linux/sysprog/basics/errorhandling`
* :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_RDONLY`

**Commandline Arguments**

* :doc:`/trainings/material/soup/linux/sysprog/process/commandline`
* To convert a string (``argv[2]``) into an integer, the ``atoi()``
  function can be used (see `here
  <https://man7.org/linux/man-pages/man3/atoi.3.html>`__)
* To put the process to sleep for an amount of time (in seconds), you
  use the ``sleep()`` function (see `here
  <https://man7.org/linux/man-pages/man3/sleep.3.html>`__)

**Build**

* :doc:`/trainings/material/soup/linux/toolchain/cmake/local`. Note
  that the program in this exercise consists of only one source file,
  so you will omit the library stuff referenced there.
* :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`
