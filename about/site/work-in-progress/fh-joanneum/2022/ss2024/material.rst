.. include:: <mmlalias.txt>


Embedded Computing 1 (STECE-2022): Material
===========================================

.. contents::
   :local:

.. sidebar::

   * Github project: https://github.com/jfasch/FH-STECE2022

Block 1: Linux, and Working With Remote/Embedded Devices
--------------------------------------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Date
     * #Units
     * Topics
   * * 2024-03-04
     * 6
     * 
       * **Quiz**

	 * `Moodle: how much I like my studies
           <https://moodle-23-24.fh-joanneum.at/mod/feedback/view.php?id=47767>`__
	 * `Moodle: how good I program
           <https://moodle-23-24.fh-joanneum.at/mod/feedback/view.php?id=47929>`__

       * **Intro: Course Contents**

	 * Raspberry Pi: Not-So-Embedded Linux System

	   * SSH login on the Pi: ``ssh -p 2020
             firstname.lastname@jfasch.bounceme.net`` (and activate
             camera; see :doc:`here </about/site/recipes/camera-ssh>`)
	   * :doc:`/trainings/material/soup/linux/hardware/w1/topic`
	   * `Sysfs GPIO (deprecated)
             <https://www.kernel.org/doc/Documentation/gpio/sysfs.txt>`__
	   * :doc:`/trainings/material/soup/linux/hardware/pwm/topic`
	   * Outlook: project in winter semester (:doc:`gluehwein`)

	 * System interaction from the shell

	   * ``cat``?
	   * ``echo``?
	   * ``>``?
	   * ``strace``!

	 * Writing my own programs to combine functionality, and add
           logic

	   * On PC, read CPU temperatures
	   * On PC, driving PWM channel based on temperature
             |longrightarrow| *there is no PWM on a PC!*
	   * Cross compilation, and deployment
	   * And Python?

       * **Material: OS Concepts**

         * :doc:`/trainings/material/soup/linux/basics/intro/overview`
           (from
           :doc:`/trainings/material/soup/linux/basics/intro/group`)
         * **Everything is a file**

           * :doc:`/trainings/material/soup/linux/basics/intro/demo-everything-is-a-file` (from :doc:`/trainings/material/soup/linux/basics/intro/group`)
           * Reading temperature sensor values (from :doc:`/trainings/material/soup/linux/hardware/w1/topic`)
	   * :doc:`/trainings/material/soup/linux/sysprog/intro-hw/sysfs-gpio`

	 * **Processes**

           * :doc:`/trainings/material/soup/linux/basics/intro/process` (from :doc:`/trainings/material/soup/linux/basics/intro/group`)
           * :doc:`/trainings/material/soup/linux/sysprog/process/commandline` (from :doc:`/trainings/material/soup/linux/sysprog/process/group`)
           * :doc:`/trainings/material/soup/linux/sysprog/process/tree` (from :doc:`/trainings/material/soup/linux/sysprog/process/group`)

       * **Homework**

	 Working
	 :doc:`/trainings/material/soup/linux/basics/intro/wsl`
	 installation until next time around.

   * * Date
     * #Units
     * Topics
   * * 2024-03-18
     * 6
     * * :doc:`/trainings/material/soup/linux/ssh/group` (Exercises!)
	 
Block 2: C on Linux: Local and *Cross* Development
--------------------------------------------------

Block 3: C++
------------

