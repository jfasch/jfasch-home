.. include:: <mmlalias.txt>


2025-04-07 (3 VO): Introduction
===============================

.. contents::
   :local:

Quiz
----

* `Moodle: how much I like my studies
  <https://moodle-24-25.fh-joanneum.at/mod/evoting/view.php?id=62415>`__
* `Moodle: how good I program
  <https://moodle-24-25.fh-joanneum.at/mod/evoting/view.php?id=62416>`__

Intro: Course Contents
----------------------

Live demo of what's going to happen in the next two semsters ...

* Command line usage: basic commands, file types, special files
* SSH usage: interactive login to my home Raspberry (:doc:`more on SSH
  </trainings/material/soup/linux/ssh/group>`)
* ``sysfs`` GPIO demo

  * See :doc:`here
    </trainings/material/soup/linux/sysprog/intro-hw/sysfs-gpio>` for
    more about ``sysfs`` GPIO)
  * Make an LED (on GPIO 21 / 533) blink:

    .. code-block:: shell

       $ v=0; while true; do sleep 0.5; v=$(($v+1)); v=$(($v%1)); echo $v > /sys/class/gpio/gpio533/value; done

  * See :doc:`here </about/site/recipes/camera-ssh>` how to transfer a
    live movie of a blinking LED from my home desk to the FH
    auditorium.

* Outlook: systems programming. Rewrite the above shell snippet in C
  (`here
  <https://github.com/jfasch/FH-STECE2023/blob/main/blink.cpp>`__)
* Talk about last year's project: `Crazy Car on Linux
  <https://fh-stece2022.readthedocs.io>`__

Homework
--------

Install Linux
.............

We want to work on our own laptops, using Linux. Three options:

* You have native Linux installed on the laptop. Nothing to do but
  install a number of packages. See below.
* Use Teiniker's VirtualBox Debian image. Should have everything
  installed that we need.
* Install :doc:`/trainings/material/soup/linux/basics/intro/wsl`. This
  is more lightweight than a full VM; it installs Ubuntu Linux inside
  Windows, and sets up an easy integration path between the host and
  guest operating systems.

Install Programs
................

Whichever Linux you use, please take care that the following programs
are installed:

* ``git``
* ``gcc`` and ``g++``
* ``cmake``
* ``make``
* `Visual Studio Code <https://code.visualstudio.com/>`__

  * If you chose WSL, you install the Windows version of Code, *on
    Windows*
  * If you chose Teiniker's VirtualBox/Debian, you install the Linux
    version of Code inside it

On Debian/Ubuntu, there exists the meta-package
``build-essential``. Installing this single package pulls in all the
required programs (except Code) and more.

On Debian/Ubuntu, you install ``git`` (for example) by saying

.. code-block:: console
		
   $ sudo apt install git
