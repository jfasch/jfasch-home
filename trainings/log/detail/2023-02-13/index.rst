.. include:: <mmlalias.txt>

Linux Systems Programming (2023-02-13 - 2023-02-17)
===================================================

.. contents::
   :local:

Programming Environment
-----------------------

WSL For Core Linux Topics
.........................

If possible, we should use WSL for core Linux topics. Local editing in
Visual Studio Code, local compilation on a virtualized Ubuntu, local
running.

* :doc:`/trainings/material/soup/linux/basics/intro/wsl` (my own $0.02)
* `Microsoft: Set up a WSL development environment <https://learn.microsoft.com/en-us/windows/wsl/setup/environment>`__
* `Get started using Visual Studio Code with Windows Subsystem for
  Linux
  <https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-vscode>`__

Cross Development For Hardware Topics
.....................................

For the more involved hardware related topics, I'll bring a Raspberry
Pi and some network equipment and build up a local network where we
can log in from our PCs.

Please check that connecting to some foreign untrusted LAN is
permitted IT-wise.

More Detailed Topics
--------------------

Those will make it into the agenda below.

* GPIO overview: ``libgpiod`` (documentation `here
  <https://libgpiod.readthedocs.io/en/latest/index.html>`__)
* I2C by example

  * :doc:`/trainings/material/soup/linux/hardware/i2c/topic`
  * :doc:`/trainings/material/soup/linux/hardware/pwm/topic`

* Toolchain and cross compiling

  * :doc:`/trainings/material/soup/linux/toolchain/cross/basics`
  * :doc:`/blog/2022/09/cross-raspi`

Agenda (To Be Reworked)
-----------------------

Tag 1: Überblick
................

Ziel ist es, mit Hilfe der Shell/Commandline einen Überlick über die
Systemkonzepte zu vermitteln, ohne noch einen Strich zu
programmieren. Viele beziehungsweise alle dieser Konzepte werden in
den folgenden Kurstagen programmatisch behaldelt werden.

* :doc:`Konzepte und Terminologie
  </trainings/material/soup/linux/basics/intro/group>`
* :doc:`/trainings/material/soup/linux/basics/shell/group`
  (auszugsweise)
* :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/group`
* :doc:`/trainings/material/soup/linux/basics/permissions/group`
* :doc:`/trainings/material/soup/linux/ssh/group`

Tag 2: (File) I/O und Prozesse
..............................

Files und Prozesse sind die Eckpfeiler des UNIX-Designs. Sehr stabile
Konzepte, die seit ihrer "Erfindung" in den Siebzigerjahren des
vorigen Jahrtausends unverändert geblieben (ergo von MacOS, Linux,
Android, und anderen UNIXen für gut befunden wurden). Das Design wurde
in Linux unverändert erweitert, und vieles aus hardwarenaher
Programmierung (siehe unten) baut darauf auf.

* Prozesse (Kapitel "Processes" aus :download:`Systemnahe
  Programmierung (PDF)
  </trainings/material/pdf/020-linux-sysprog--en.pdf>`)
* System Calls, Blocking, und File I/O

  * :doc:`/trainings/material/soup/linux/sysprog/blocking-io/group`
  * :doc:`/trainings/material/soup/linux/sysprog/file-io/group`

Tag 3: Netzwerkprogrammierung (inklusive CAN-Bus)
.................................................

Siehe :doc:`/trainings/repertoire/sysprog/network`

* TCP/IP Networking: die vorhandenen Netzwerkschnittstellen (Ethernet,
  Wifi, ...) nutzen
* CAN-Bus (broadcast-only, aber eben Netzerk)
* Fortgeschrittene Paradigmen wie Event-Driven Programming

Tag 4: Multithreading, und Realtime
...................................

Siehe :doc:`/trainings/repertoire/sysprog/multithreading`

* Die Gefahren (Race Conditions) und deren Vermeidung (Mutexes)
* Kommunikationsmechanismen
* Atomics
* Realtime

.. note::

   Unter Umständen kann in diesem Zusammenhang auch auf die relevanten
   Neuerungen in C++ eingegangen werden

   * :doc:`/trainings/material/soup/cxx11/050-multithreading/group`

     * :doc:`/trainings/material/soup/cxx11/050-multithreading/020-thread/topic`
     * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`
     * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/scoped-locking`
     * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`
     * :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
     * :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`

Tag 5: Verschiedenes aus der Hardware-Ecke
..........................................

* Eine Auswahl aus
  :doc:`/trainings/material/soup/linux/hardware/group`
* USB aus dem Userspace
* Serielle Schnittstellen (UART): Einführung in `termios
  <https://www.man7.org/linux/man-pages/man3/termios.3.html>`__
