Embedded Computing
==================

.. contents::
   :local:

.. toctree::
   :hidden:

   ec
   embedded-computing-1
   embedded-computing-2

   cxx
   mt
   linux
   python

   cxx_build
   cxx_iface
   linux_dev_mgmt
   linux_exercise_sensors
   git
   linux_basics
   cxx_oo_basics
   linux_exercise_avg_sensor
   cxx_unittest
   linux_exercise_led_display
   linux_gpio
   mt_wait
   mt_lock
   exercise_mt_race_fixed
   exercise_mt_race
   linux_exercise_avg_sensor_parallel

   py_basics
   py_exercise_avg_display
   py_exercise_sensors
   py_web
   py_web_sensors

   2021-SS-Stundenplan

Overview
--------

Knwoledge Transferred
.....................

Knowledge from "Computer Science and Programming (1+2)" and "Embedded
Systems" is picked up and unified.

* **Large scale software development**, covering topics like

  * Test Driven Development
  * Object Oriented Design
  * Configuration Management

* **Linux** (*Operating System Concepts*). Bare metal operating
  systems are intentionally *simple* - as a result, they are generally
  less *powerful*. Linux, being a *general purpose OS*, has a number
  of features every developer wants if the software becomes larger,

  * *Address space separation* through the concept of *processes*: an
    abstraction of a crucial piece of hardware, the *Memory Management
    Unit (MMU)*.
  * A sophisticated yet simple *permission system*.
  * Natively supports a great variety of file systems and storage
    media.
  * Natively supports *The Internet*.
  * Natively supports optional realtime capabilities (on a per-process
    basis).
  * Depending on the underlying hardware platform, Linux offers
    support *non-PC type hardware* which is popular in the embedded
    world.

* **Python** (*Programming language alternatives*). Embedded
  applications are historically written in C/C++ which is hard. It is
  often more appropriate to prototype functionality in a higher level
  language like `Python <https://www.python.org/>`__, or even use that
  as final production language.

Course Setup
............

The `Raspberry Pi <https://www.raspberrypi.org/>`__ is used as work
environment *and* hardware platform.

* It comes with a fully functional Linux distribution (based on
  `Debian <https://www.debian.org/>`__).
* It supports hardware that is en vogue in embedded applications, like
  GPIO, I2C, SPI, serial, and others.

Details
-------

See :doc:`here <ec>` for a complete overview of the course structure.
  
Embedded Computing 1
....................

(:doc:`Details <embedded-computing-1>`)

* **Groundwork**. To lay the groundwork for an instructive set of
  programming exercises, the following topics are covered up-front:

  * :doc:`cxx_build`
  * :doc:`git`
  * :doc:`cxx_oo_basics`
  * :doc:`cxx_unittest`
  * :doc:`linux_basics`
  * :doc:`linux_dev_mgmt`

* **Exercises and Making**. Above topics are consolidated by a set of
  programming exercises that involve relatively simple hardware
  makery. See :doc:`here <embedded-computing-1>` for the details.
* **Multithreading**. Although this is not exactly beginner stuff,
  everybody does it (wrong). It makes sense to clarify the do's and
  don'ts :doc:`early on <mt>`, and to consolidate the matter in
  another set of exercises.


Embedded Computing 2
....................

(:doc:`Details <embedded-computing-2>`)

* **Python interoduction**. :doc:`Introduce a new language.
  </trainings/material/soup/python/python-basics>`
* **Rewrite exercises**. Based on what was accomplished in C++, in
  "Embedded Computing 1", translate those exercises into an equivalent
  set written in Python (and see how simple this is).
* **Web programming**. Using the :doc:`Flask <py_web>` web framework,
  write a :doc:`web application to visualize sensor data
  <py_web_sensors>`.
* **More advanced topics**. Use Python libraries, for example

  * Network programming
  * Exchange documents using JSON and/or CSV/Excel
  * Database access

* **Linux Kernel Drivers** maybe?
