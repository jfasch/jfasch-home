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

.. .. code-block:: console
.. 
..    ssh training@34.91.249.217
..    ... leave passphrase empty ...
..    .. supply password sent in private email ...

.. code-block:: console

   ssh training@35.246.179.112
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

Log
---

Day 1
.....

(From the PDF slides)

* Building blocks (complete)
* Demo sessions (complete)
* Bash (complete)
* Filesystem

  * Paths
  * Directories
  * Symbolic links
  * Current working directory
  * Directory listings
  * Copying and moving

Day 2
.....

* Filesystem

  * Owner, permissions
  * ``find``

* Tools for text files (complete)

Day 3
.....

Day 3 will happen on 2020-11-17. Following topics are on the menu:

* Basic *security*. Such as ...

  * Creating a non ``pi`` user with more restricted rights
  * Disallowing passowrd login with SSH
  * Public key authentication with SSH
  * ``netstat`` to see which ports are open

* *Everything is a file*: Raspberry SD card setup, *not* using any of
  these idiotic "Disk Imager" programs (hey, they even recommend using
  one on Ubuntu!)
* GPIO subsystem using the ``sysfs`` interface from the shell
* Use a `watchdog program <https://linux.die.net/man/8/watchdog>`__ to
  check a script's output. Verify that a file is modified
  periodically, for example. Write that script, based upon what we
  have learned in this training.

Support Material
----------------

* Bourne Again Shell (``bash``)

  * :download:`Short Cheat Sheet </trainings/material/misc/bash-help-sheet.pdf>`
  * :download:`Long Cheat Sheet
    </trainings/material/misc/readline-emacs-editing-mode-cheat-sheet.pdf>`
  * `Briana's Bash Tutorial: How to Use the Command Line in Linux, Windows, and Mac <https://www.youtube.com/watch?v=BFMyUgF6I8Y>`__

    .. raw:: html

       <iframe 
           width="560" 
	   height="315" 
	   src="https://www.youtube.com/embed/BFMyUgF6I8Y" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	   allowfullscreen>
       </iframe>

  * `Everything You Need to Know About $PATH in Bash <https://www.youtube.com/watch?v=rJMFxIbDe-g>`__

    .. raw:: html

       <iframe 
           width="560" 
	   height="315" 
	   src="https://www.youtube.com/embed/rJMFxIbDe-g" 
	   frameborder="0" 
	   allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	   allowfullscreen>
       </iframe>
