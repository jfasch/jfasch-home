.. include:: <mmlalias.txt>

Linux Systems Programming (2023-02-13 - 2023-02-17)
===================================================

.. contents::
   :local:

.. sidebar::

   **Dates and Times**

   * Start on Monday 2023-02-13 9:00

   **Github Repository**

   * https://github.com/jfasch/2023-02-13

   **Toolchain (Raspberry Cross Build)**

   * Toolchain archive: `armv8-rpi4-linux-gnueabihf.tar.xz
     <https://drive.google.com/file/d/1FJvnLGbHwAABy0DgVfRvSqDnuqK5aloZ/view?usp=sharing>`
   * CMake toolchain file: :download:`armv8-rpi4-linux-gnueabihf.cmake`

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

Agenda
------

Day 1: Overview
...............

Introductory Live Hacking
`````````````````````````

Hammering on a GPIO pin: a typical example of how hardware access
works on Linux (from
:doc:`/trainings/material/soup/linux/sysprog/intro-hw/group`).

* :doc:`/trainings/material/soup/linux/sysprog/intro-hw/sysfs-gpio`
* :doc:`/trainings/material/soup/linux/sysprog/intro-hw/get`
* :doc:`/trainings/material/soup/linux/sysprog/intro-hw/watch`

The Shell
`````````

Using the Shell's commandline, an overview is given about Unix system
concepts like *processes*, *files*, and *permissions*. Many if not all
of these concepts will be viewed programmatically in the remainder of
the course. It will be no surprise, for example, that communication
with hardware has to do with file I/O.

* From :doc:`/trainings/material/soup/linux/basics/intro/group`

  * :doc:`/trainings/material/soup/linux/basics/intro/overview`
  * :doc:`/trainings/material/soup/linux/basics/intro/demo-everything-is-a-file`
  * :doc:`/trainings/material/soup/linux/basics/intro/process`
  * :doc:`/trainings/material/soup/linux/basics/intro/process-tree`
  * :doc:`/trainings/material/soup/linux/basics/intro/environment`
  * :doc:`/trainings/material/soup/linux/basics/intro/login`

* From :doc:`/trainings/material/soup/linux/basics/shell/group`

  * :doc:`/trainings/material/soup/linux/basics/shell/commandline`
  * :doc:`/trainings/material/soup/linux/basics/shell/paths`
  * :doc:`/trainings/material/soup/linux/basics/shell/ls`
  * :doc:`/trainings/material/soup/linux/basics/shell/cwd`
  * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`
  * :doc:`/trainings/material/soup/linux/basics/shell/cp`
  * :doc:`/trainings/material/soup/linux/basics/shell/mv`
  * :doc:`/trainings/material/soup/linux/basics/shell/links`
  * :doc:`/trainings/material/soup/linux/basics/shell/configfiles`

* From :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/group`

  * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/io-redirection`
  * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/io-redirection-swap-stdout-stderr`
  * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/pipes`
  * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/exercises`

* From :doc:`/trainings/material/soup/linux/basics/permissions/group`

  * :doc:`/trainings/material/soup/linux/basics/permissions/basics`
  * :doc:`/trainings/material/soup/linux/basics/permissions/setuid`
  * :doc:`/trainings/material/soup/linux/basics/permissions/setuid-livedemo`
  * :doc:`/trainings/material/soup/linux/basics/permissions/umask`
  * :doc:`/trainings/material/soup/linux/basics/permissions/sticky`

Secure Shell (SSH)
``````````````````

* From :doc:`/trainings/material/soup/linux/ssh/group` ...

  * :doc:`/trainings/material/soup/linux/ssh/basics`
  * :doc:`/trainings/material/soup/linux/ssh/key-pair`
  * :doc:`/trainings/material/soup/linux/ssh/scp`
  * :doc:`/trainings/material/soup/linux/ssh/sshfs`

Cross Development
`````````````````

An overview of the *toolchain* is given - a collection of tools
(compiler, linker, ...) to transform C/C++ source code into running
executables.

This is followed by an introduction to `CMake <cmake.org>`_, a higher
level build tool that solves many problems that both hand-written
``Makefile`` hacks and IDE-clickabout builds have.

Last, a bit more involved, we see how cross development is
done. Together with :doc:`/trainings/material/soup/linux/ssh/group`,
this enables us to build software for devices that show a different
architecture that the development machine.

* From :doc:`/trainings/material/soup/linux/toolchain/group`

  * :doc:`/trainings/material/soup/linux/toolchain/basics/topic`
  * :doc:`/trainings/material/soup/linux/toolchain/separate-compilation/topic`
  * :doc:`/trainings/material/soup/linux/toolchain/static-library/topic`
  * :doc:`/trainings/material/soup/linux/toolchain/shared-libraries/topic`
  * :doc:`/trainings/material/soup/linux/toolchain/cross/group`
  * :doc:`/trainings/material/soup/linux/toolchain/cmake/stub-cmake-course`
  * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`
  * :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`
  * :doc:`/trainings/material/soup/linux/toolchain/exercises/group`

* Bringing a :doc:`self-made cross toolchain for the Raspberry
  </blog/2022/09/cross-raspi>`

Day 2: File I/O and Processes
.............................

Files and processes are the cornerstones of the Unix design - concepts
that have proven very stable since their invention in the seventies of
the past century. They have driven the evolution of Linux (and MacOS
and Android, for what it's worth), and many of Linux's hardware
related capabilities build upon those.

* Processes (chapter "Processes" from :download:`Linux Systems
  Programming (PDF) (download)
  </trainings/material/pdf/020-linux-sysprog--en.pdf>`)
* System Calls, Blocking, und File I/O

  * :doc:`/trainings/material/soup/linux/sysprog/blocking-io/group`
  * :doc:`/trainings/material/soup/linux/sysprog/file-io/group`

Day 3: Network Programming (including CAN-Bus)
..............................................

Siehe :doc:`/trainings/repertoire/sysprog/network`

* TCP/IP Networking
* :doc:`/trainings/material/soup/linux/hardware/can/group`
* Advanced topics: event driven programming

Day 4: Multithreading, and Realtime
...................................

From :doc:`/trainings/repertoire/sysprog/multithreading`:

* Race Conditions, and prevention thereof (mutexes)
* Communication mechanisms (condition variable)
* Atomics
* Realtime

.. note::

   Maybe we should have a look at how threading is done in :doc:`C++
   11 </trainings/material/soup/cxx11/group>` ...

   From :doc:`/trainings/material/soup/cxx11/050-multithreading/group`

   * :doc:`/trainings/material/soup/cxx11/050-multithreading/020-thread/topic`
   * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`
   * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/scoped-locking`
   * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`
   * :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
   * :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`

Day 5: Miscellaneous Hardware Topics
....................................

* Serial interfaces (UART): introduction in `termios
  <https://www.man7.org/linux/man-pages/man3/termios.3.html>`__
* GPIO overview: ``libgpiod`` (documentation `here
  <https://libgpiod.readthedocs.io/en/latest/index.html>`__)
* From :doc:`/trainings/material/soup/linux/hardware/group`

  * :doc:`/trainings/material/soup/linux/hardware/can/group`
  * :doc:`/trainings/material/soup/linux/hardware/w1/topic`
  * :doc:`/trainings/material/soup/linux/hardware/i2c/topic`
  * :doc:`/trainings/material/soup/linux/hardware/pwm/topic`
