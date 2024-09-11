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
   * :doc:`/trainings/repertoire/linux-prog/linux-basics`
   * :doc:`/trainings/repertoire/linux-prog/embedded/raspi-hands-on`
   * :doc:`/trainings/repertoire/linux-prog/bash`

   **Material**

   .. csv-table::

      PDF Slides, :download:`Linux Basics </trainings/material/pdf/010-linux-basics.pdf>`
      PDF Slides, :download:`Shell Scripting </trainings/material/pdf/100-shell-scripting.pdf>`
      PDF Slides, :download:`SSH (and much more) </trainings/material/pdf/200-misc.pdf>`

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

* Tools for text files

Day 3
.....

Day 3 will happen on 2020-11-17. Following topics are on the menu:

Basic *security*
````````````````

* Show ``telnetd`` running. Blah old insecure blah.

  .. code-block:: console

     $ netstat -tn
     Active Internet connections (w/o servers)
     Proto Recv-Q Send-Q Local Address           Foreign Address         State      
     tcp        0      0 192.168.3.70:22         192.168.3.1:34490       ESTABLISHED
     tcp        0    124 192.168.3.70:23         192.168.3.1:56062       ESTABLISHED

* Service configuration: ``sshd``

  .. code-block:: console

     $ systemctl enable sshd
     ==== AUTHENTICATING FOR org.freedesktop.systemd1.manage-unit-files ===
     Authentication is required to manage system service or unit files.
     Authenticating as: root
     Password: 

  * Hm, don't have a root password
  * Quickly recap *setuid*, using ``passwd`` and ``sudo``
  * ``sudo -i``, to become root
  * Set root password
  * Back to unprivileged ``pi``

    .. code-block:: console

       $ systemctl enable ssh

    (Supply root password)

  * Next: ``systemctl start sshd``
  * Login over ssh

* Generate and deploy keys (for better security and interactive use)

  * Windows/Putty: https://www.ssh.com/ssh/putty/windows/puttygen
  * Backup ``~/.ssh/``; create empty one
  * Generate keys
  * Deploy ``id_rsa.pub``: scp there, and append to (non-existing)
    ``.ssh/authorized_keys``. *Trivia time*: how append content to
    file?

    .. code-block:: console

       $ cat id_rsa.pub >> .ssh/authorized_keys

  * Demonstrate interactivity

* Create a non ``pi`` user with more restricted rights. Nothing, as a
  start. Enter GPIO.

Interlude: SD Card Setup (No Bloody Disk Imager)
````````````````````````````````````````````````

Hooray: *Everything is a file*

Raspberry SD card setup, *not* using any of these idiotic "Disk
Imager" programs (hey, they even recommend using one on Ubuntu!)

GPIO, using ``sysfs`` interface
```````````````````````````````

.. image:: GPIO-Pinout-Diagram-2.png

* `Kernel Documentation
  <https://www.kernel.org/doc/Documentation/gpio/sysfs.txt>`__
* Demo: scripting an LED blinker

In the Wild: Watchdog
`````````````````````

Use a `watchdog program <https://linux.die.net/man/8/watchdog>`__ to
check a script's output. Verify that a file is modified periodically,
for example. Write that script, based upon what we have learned in
this training.

Miscellaneous
`````````````

Reload a page in Chromium. Hm, not sure if this is Linux Basics.

TODO
----

* Document network setup (``Documentation/Training-Network.rst``);
  draw nice sketch

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
