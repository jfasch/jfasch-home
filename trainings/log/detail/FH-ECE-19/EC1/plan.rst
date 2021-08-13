Plan for Summer 2021
====================

`Embedded Computing 1
<https://www.fh-joanneum.at/elektronik-und-computer-engineering/bachelor/en/course/embedded-computing-1/190420404-embedded-computing-1-2019/ss/2020/>`__
(and 2) stands for "Embedded Device Development with Linux". We will
see how embedded development is done for Linux, what Linux is, what
tools exist, how hardware is accessed. Starting with C and C++
development, we will quickly move over to Python, a more comfortable
and more powerful language.

So much for the plan. See :doc:`here <index>` for a record of what's
actually going on.

.. contents::
   :local:

Linux Introduction
------------------

.. sidebar:: Slides

   * :download:`Linux Basics (PDF) </trainings/material/pdf/010-linux-basics.pdf>`
   * :download:`Linux Systems Programming (PDF) </trainings/material/pdf/020-linux-sysprog--en.pdf>`

* **Get familiar with the commandline**

  This is what you will be using a lot during Embedded Linux
  development.

  We will be using a :doc:`cloud machine <cloud-computer>` in the warm
  up lessons, and will move to the `Raspberry
  <https://www.raspberrypi.org/>`__ once we start developing.

* **Learn Linux system concepts**

  As a developer, you will have to be familiar with the system you are
  developing for.

  * Processes and address spaces
  * File system
  * Permissions
  * More

C/C++ Development
-----------------

.. sidebar:: Slides

   * :download:`C (PDF) </trainings/material/pdf/050-c.pdf>`
   * :download:`C++03 (PDF) </trainings/material/pdf/055-c++03.pdf>`
   * :download:`C++11 (PDF) </trainings/material/pdf/056-c++11.pdf>`
   * :download:`GNU Make (PDF) </trainings/material/pdf/040-gnu-make.pdf>`
   * :download:`CMake (PDF) </trainings/material/pdf/045-cmake.pdf>`

* **Cross Development with C**

  Build on a Linux PC (in a Linux VM on a Windows PC, likely), run on
  device.

* **C++ Introduction**

  * Why C++?
  * Basics: classes, constructors and destructors, object copy
  * Resource management: *smart pointers*
  * Container templates

Python Development
------------------

.. sidebar:: Slides

   * :download:`Python (PDF) </trainings/material/pdf/300-python.pdf>`
   * :doc:`Python (HTML, more alive than PDF)
     </trainings/material/soup/python/group>`

* **Language Introduction**

  * Basics: variables, data types, control flow (``if``, ``while``,
    ``for``)
  * Modularization: functions, modules, and packages
  * Excerpts from `The Python Standard Library
    <https://docs.python.org/3/py-modindex.html>`__

* **Hardware Access**

  * General purpose IO (GPIO)
  * I2C
  * OneWire
  * Maybe others
