.. include:: <mmlalias.txt>

Linux on Raspberry Pi
=====================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Start**

   * Tuesday 3.11.2020, 9:00
   * Wednesday 4.11.2020, 9:00
   * Tuesday 17.11.2020, 9:00

   **Official Descriptions**

   * `Raspberry Pi – Einführung in Embedded-Linux
     <https://www.tectrain.at/seminare/linux/unix-linux-fuer-entwickler/raspberry-pi-einfuehrung-in-embedded-linux>`__
   * `Linux Command Line – Basics
     <https://www.tectrain.at/seminare/linux/unix-linux-fuer-entwickler/linux-basis>`__
   * :doc:`/trainings/repertoire/linux-basics`
   * :doc:`/trainings/repertoire/raspi-hands-on`
   * :doc:`/trainings/repertoire/bash`

   **Material**

   .. csv-table::

      PDF Slides, :download:`Linux Basics </trainings/material/pdf/010-linux-basics.pdf>`
      PDF Slides, :download:`Shell Scripting </trainings/material/pdf/100-shell-scripting.pdf>`

Preparation
-----------

Cloud Machine
.............

A machine has been setup somewhere in The Cloud, as a way of working
together on one machine while we are physically far away from each
other.

The machine's OS is Debian 10.6 for that matter, which is similar to
what we'll encounter on the Raspberry - at least for the generic
*Linux* part of the training.

.. code-block:: console

   ssh training@34.91.249.217
   ... leave passphrase empty ...
   .. supply password sent in private email ...

Please try out your ``{login,connectivity,corporate firewall}``, and
send feedback accordingly.

Raspberry on Participant's Desks
................................

Please take care to have access to a Raspberry Pi.

This training is about using Raspberries to accomplish something. You
might want to try things out on the Raspberry while doing the training
exercises in the cloud.

Agenda
------

This is a preliminary list of topics that we will cover. Please send
suggestions to training@faschingbauer.co.at.

* Overview of concepts
* Commandline - the Bourne Shell
* Filesystem

  * File Types
  * Tools (``cp``, ``mv``, ``rm``, ...)
  * Permissions

* More Commandine

  * More Tools: ``grep``, ``find``, ``head``, ``tail``
  * IO Redirection
  * The Pipe
  * Archiving and Comressing (``gzip``/``bzip2``, ``tar``)

* Diagnosing

  * Processes: ``ps``, ``top``, and ``procfs`` (and *scheduling* in general)
  * Network: ``netstat`` and ``netcat``/``nc``

* Shell Scripting

  * Syntax and Concepts
  * Control Flow: ``if``, ``while``, ``case``
  * Functions, Blocks, and Subshells (optional, if there is time and
    interest)

* Raspberry Pi

  * GPIO subsystem
  * I2C: adding sensors (optional, if there is time and interest)
  * Serial/RS232 interface (optional, if there is time and interest)
