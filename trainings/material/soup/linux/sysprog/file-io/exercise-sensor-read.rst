Exercise: Read Temperature From Onewire Sensor
==============================================

.. contents:: 
   :local:

Onewire Basics
--------------

.. sidebar:: 

   **See also**

   * :doc:`/trainings/material/soup/linux/hardware/w1/topic`

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

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/process/exit/index`
   * :doc:`/trainings/material/soup/linux/sysprog/process/argv/index`
   * :doc:`/trainings/material/soup/linux/sysprog/syscalls/errorhandling/index`
   * :doc:`/trainings/material/soup/linux/sysprog/file-io/open/index`
   * :doc:`/trainings/material/soup/linux/sysprog/file-io/file-input/index`

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

.. note::

   * To convert a string (``argv[2]``) into an integer, the ``atoi()``
     function can be used (see `here
     <https://man7.org/linux/man-pages/man3/atoi.3.html>`__)
   * To put the process to sleep for an amount of time (in seconds),
     you use the ``sleep()`` function (see `here
     <https://man7.org/linux/man-pages/man3/sleep.3.html>`__)

CMake Build
...........

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`
   * :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/cross` 

* Read :doc:`/trainings/material/soup/linux/toolchain/cmake/local` for
  how to create a simple CMake project. 

  Note that the program in this
  exercise consists of only one source file, so you will omit the
  library stuff referenced there.
* Read
  :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
  and :doc:`/trainings/material/soup/linux/toolchain/cmake/cross` for cross-building a CMake project
* Add your file (``onewire-temperature.cpp`` is a likely name) to the
  project.

Test On The Target Machine
..........................

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/ssh/basics`
   * :doc:`/trainings/material/soup/linux/ssh/scp`

* Use ``scp`` to copy the program over. *Note* that you specify a
  non-default port (say, 2020) using the ``-P 2020`` option.
* Use ``ssh`` to login to the target and test

