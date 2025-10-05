.. include:: <mmlalias.txt>


Embedded Linux Systems Programming (2023-02-13 - 2023-02-17)
============================================================

.. contents::
   :local:

.. sidebar::

   **Dates and Times**

   * Start on Monday 2023-02-13 9:00

   **Github Repository**

   * https://github.com/jfasch/2023-02-13

   **Toolchain (Raspberry Cross Build)**

   * Toolchain archive: `armv8-rpi4-linux-gnueabihf.tar.xz
     <https://drive.google.com/file/d/1FJvnLGbHwAABy0DgVfRvSqDnuqK5aloZ/view?usp=sharing>`__
   * CMake toolchain file: :download:`armv8-rpi4-linux-gnueabihf.cmake`

   **PDF slides (unmaintained)**

   * Systems Programming: :download:`020-linux-sysprog--en.pdf
     </trainings/material/pdf/020-linux-sysprog--en.pdf>`
   * CMake: :download:`045-cmake.pdf
     </trainings/material/pdf/045-cmake.pdf>`

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

Please check that connecting the course participants' PCs to some
foreign untrusted LAN is permitted IT-wise.

Day 1: Overview
---------------

Introductory Live Hacking
.........................

Hammering on a GPIO pin: a typical example of how hardware access
works on Linux (from
:doc:`/trainings/material/soup/linux/sysprog/intro-hw/index`).

* :doc:`/trainings/material/soup/linux/sysprog/intro-hw/sysfs-gpio`
* :doc:`/trainings/material/soup/linux/sysprog/intro-hw/get`
* :doc:`/trainings/material/soup/linux/sysprog/intro-hw/watch`

The Shell
.........

Using the Shell's commandline, an overview is given about Unix system
concepts like *processes*, *files*, and *permissions*. Many if not all
of these concepts will be viewed programmatically in the remainder of
the course. It will be no surprise, for example, that communication
with hardware has to do with file I/O.

* From :doc:`/trainings/material/soup/linux/basics/intro/index`

  * :doc:`/trainings/material/soup/linux/basics/intro/overview`
  * :doc:`/trainings/material/soup/linux/basics/intro/demo-everything-is-a-file`
  * :doc:`/trainings/material/soup/linux/basics/intro/process`
  * :doc:`/trainings/material/soup/linux/basics/intro/process-tree`
  * :doc:`/trainings/material/soup/linux/basics/intro/environment`

* From :doc:`/trainings/material/soup/linux/basics/shell/index`

  * :doc:`/trainings/material/soup/linux/basics/shell/commandline`
  * :doc:`/trainings/material/soup/linux/basics/shell/paths`
  * :doc:`/trainings/material/soup/linux/basics/shell/special-paths`
  * :doc:`/trainings/material/soup/linux/basics/shell/ls`
  * :doc:`/trainings/material/soup/linux/basics/shell/cwd`
  * :doc:`/trainings/material/soup/linux/basics/shell/file_dir_create_rm`
  * :doc:`/trainings/material/soup/linux/basics/shell/cp`
  * :doc:`/trainings/material/soup/linux/basics/shell/mv`
  * Exercises (from
    :doc:`/trainings/material/soup/linux/basics/shell/exercises/ls/index`)

    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/ls/etc-passwd-size`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/ls/dev-types`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/ls/home-permissions`

  * Exercises (from
    :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/index`)

    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/mkdir-p-rm-r`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-create-files`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-copy-files`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/echo-move-files`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/verify-hierarchy`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/copy-tree`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-tree`
    * :doc:`/trainings/material/soup/linux/basics/shell/exercises/cp-mv-mkdir-rm/rm-rf`

Day 2
-----

Processes Quick Walk-Through
............................

* From :doc:`/trainings/material/soup/linux/sysprog/index`

  * :doc:`/trainings/material/soup/linux/sysprog/process/exit-args-env/index`
  * :doc:`/trainings/material/soup/linux/sysprog/process/tree/index`

Permissions
...........

From :doc:`/trainings/material/soup/linux/basics/permissions/index`

* :doc:`/trainings/material/soup/linux/basics/permissions/basics`
* :doc:`/trainings/material/soup/linux/basics/permissions/setuid`
* :doc:`/trainings/material/soup/linux/basics/permissions/setuid-livedemo`
* :doc:`/trainings/material/soup/linux/basics/permissions/umask`
* :doc:`/trainings/material/soup/linux/basics/permissions/sticky`
* :doc:`/trainings/material/soup/linux/basics/permissions/exercises/index`

Development: CMake Quick Intro, And Git Quick Intro
...................................................

* Setup Github project for local build: https://github.com/jfasch/2023-02-13
* |longrightarrow| See instructions on that page

File IO
.......

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/linux/sysprog/index`

* From :doc:`/trainings/material/soup/linux/sysprog/syscalls-and-errors/index`

  * :doc:`/trainings/material/soup/linux/sysprog/syscalls-and-errors/syscalls/index`
  * :doc:`/trainings/material/soup/linux/sysprog/syscalls-and-errors/errorhandling/index`

* From :doc:`/trainings/material/soup/linux/sysprog/file-io/index`

  * :doc:`/trainings/material/soup/linux/sysprog/file-io/file-descriptors/index`
  * :doc:`/trainings/material/soup/linux/sysprog/file-io/open-read-write-close/index`

Day 3
-----

UART
....

.. sidebar::

   * `man -s 1 stty
     <https://man7.org/linux/man-pages/man1/stty.1.html>`__
   * `man -s 3 termios
     <https://www.man7.org/linux/man-pages/man3/termios.3.html>`__
   * `man -s 2 ioctl_tty
     <https://man7.org/linux/man-pages/man2/ioctl_tty.2.html>`__
   * `man -s 8 setserial <https://linux.die.net/man/8/setserial>`__
   * ``setserial`` source code on `Github
     <https://github.com/Distrotech/setserial>`__
   * Linux kernel source code (e.g. on `Github
     <https://github.com/torvalds/linux>`__): `drivers/tty/tty_io.c
     <https://github.com/torvalds/linux/blob/master/drivers/tty/tty_io.c>`__

* First try: four programs, two on either side (``cat``, and ``echo``)

  * |longrightarrow| weird output when used bidirectionally
  * Enable "raw mode" |:thinking:| |longrightarrow| `man -s 1 stty
    <https://man7.org/linux/man-pages/man1/stty.1.html>`__
  * |longrightarrow| no special character handling in terminal
    driver. *Want no terminal, want naked UART IO!!*
  * |longrightarrow| weird output still weird, but less so

* Dedicated input and output programs

  * `tty-read.cpp
    <https://github.com/jfasch/2023-02-13/blob/main/livehacking/tty-read.cpp>`__
  * `tty-write.cpp
    <https://github.com/jfasch/2023-02-13/blob/main/livehacking/tty-read.cpp>`__
  * First w/o ``termios`` and
    ``TIOCGSERIAL``/``TIOCSSERIAL``/``ASYNC_LOW_LATENCY``
  * |longrightarrow| better

* Add ``cfmakeraw()`` programmatically (the "non-cooked mode" from
  `man -s 1 stty
  <https://man7.org/linux/man-pages/man1/stty.1.html>`__)

  * |longrightarrow| **this is what we want to see!**

* "Realtime": ``setserial /dev/ttyUSB0 low_latency`` (`man -s 8
  setserial <https://linux.die.net/man/8/setserial>`__), only
  programmatically

  * ``setserial`` source code on `Github
    <https://github.com/Distrotech/setserial>`__
  * Linux kernel source code: `drivers/tty/tty_io.c
    <https://github.com/torvalds/linux/blob/master/drivers/tty/tty_io.c>`__
  * ``ioctl(fd, TIOCGSERIAL, &serial_struct)``
  * ``serial_struct.flags |= ASYNC_LOW_LATENCY``
  * ``ioctl(fd, TIOCSSERIAL, &serial_struct)``

* `tty-bidir-threads.cpp
  <https://github.com/jfasch/2023-02-13/blob/main/livehacking/tty-bidir-threads.cpp>`__:
  not separate programs on different fds; two threads hammering on one
  fd
* Livehacking: transform that into event-driven (`tty-bidir-events.cpp
  <https://github.com/jfasch/2023-02-13/blob/main/livehacking/tty-bidir-events.cpp>`__)

SUSI
....

* `Advantec Marketingese <https://youtu.be/FmbXboI7slQ>`__. **Security
  is the "S" in IoT** ... that library requires you to run your code
  as root. Considered cool nonetheless, and marketed heavily by
  Advantec.

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/FmbXboI7slQ" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     allowfullscreen>
     </iframe>

  |:middle_finger:|

Exercise
........

.. sidebar::

   **Github Repository**

   * https://github.com/jfasch/2023-02-13
   * Especially ``mycat.cpp``:
     https://github.com/jfasch/2023-02-13/blob/main/exercises/mycat.cpp

Modify that program such that it mimicks ``cat``:

* Is given on single filename argument
* Opens that file
* Reads its content, and outputs it on *standard output*

.. code-block:: console

   $ ./mycat /etc/passwd
   ... contents of /etc/passwd here ...

Cross Development
.................

* From :doc:`/trainings/material/soup/linux/toolchain/index`

  * :doc:`/trainings/material/soup/linux/toolchain/basics/topic`
  * :doc:`/trainings/material/soup/linux/toolchain/separate-compilation/topic`
  * :doc:`/trainings/material/soup/linux/toolchain/static-library/topic`
  * :doc:`/trainings/material/soup/linux/toolchain/shared-libraries/topic`
  * :doc:`/trainings/material/soup/linux/toolchain/cross/index`
  * :doc:`/trainings/material/soup/misc/cmake/index`
  * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`
  * :doc:`/trainings/material/soup/linux/toolchain/cmake/cross`
  * :doc:`/trainings/material/soup/linux/toolchain/exercises/index`

* Establish a custom built toolchain for Raspberry Pi cross
  development (from
  :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/index`)

  * :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`
  * Unpacking the toolchain archive:
    :doc:`/trainings/material/soup/linux/basics/archiving-compression/index`

  Have a look into how toolchains are made:

  * :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-build-details`
  * :doc:`/trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-build-docker-fedora`

Day 4
-----

Secure Shell (SSH)
..................

* From :doc:`/trainings/material/soup/linux/ssh/index` ...

  * :doc:`/trainings/material/soup/linux/ssh/basics`
  * :doc:`/trainings/material/soup/linux/ssh/key-pair`
  * :doc:`/trainings/material/soup/linux/ssh/scp`
  * :doc:`/trainings/material/soup/linux/ssh/sshfs`

Miscellaneous Hardware
......................

* From :doc:`/trainings/material/soup/linux/hardware/index`

  * :doc:`/trainings/material/soup/linux/hardware/can/index`
  * :doc:`/trainings/material/soup/linux/hardware/w1/topic`
  * :doc:`/trainings/material/soup/linux/hardware/i2c/topic`
  * :doc:`/trainings/material/soup/linux/hardware/pwm/topic`

Group Exercise
..............

* Send sensor values (:doc:`W1
  </trainings/material/soup/linux/hardware/w1/topic>`, and
  :doc:`userspace LM73
  </trainings/material/soup/linux/hardware/i2c/topic>`) over CAN
* Receive values, and show via a :doc:`PWM'd LED
  </trainings/material/soup/linux/hardware/pwm/topic>`

Day 5
-----

* Some OO: PWM display (`display-pwm.h
  <https://github.com/jfasch/2023-02-13/blob/main/company/display-pwm.h>`__,
  `display-pwm.cpp
  <https://github.com/jfasch/2023-02-13/blob/main/company/display-pwm.cpp>`__),
  and associated program (`show-pwm-temperature.cpp
  <https://github.com/jfasch/2023-02-13/blob/main/company-bin/show-pwm-temperature.cpp>`__
* Show sine wave: `show-pwm-temperature-sine.cpp
  <https://github.com/jfasch/2023-02-13/blob/main/company-bin/show-pwm-temperature-sine.cpp>`__
* Realtime sine waves on 2 LEDs (see ``make_realtime()`` in
  `show-pwm-temperature-sine.cpp
  <https://github.com/jfasch/2023-02-13/blob/main/company-bin/show-pwm-temperature-sine.cpp>`__)
* More OO? Writing temperature to CAN could be viewed as another kind
  of display. A little C++ interfacery ( `display.h
  <https://github.com/jfasch/2023-02-13/blob/main/company/display.h>`__,
  leading to `display-can.h
  <https://github.com/jfasch/2023-02-13/blob/main/company/display-can.h>`__,
  `display-can.cpp
  <https://github.com/jfasch/2023-02-13/blob/main/company/display-can.cpp>`__)

  * |longrightarrow| *is-a* Display

* CIFS/Samba: mounting a Windows share on Linux:
  https://automationadmin.com/2016/12/mounting-a-samba-share-in-fedora/#gsc.tab=0

Untold
------

More From The Commandline
.........................

.. sidebar::

   **See also**

   * Shell scripting: :download:`100-shell-scripting.pdf
     </trainings/material/pdf/100-shell-scripting.pdf>`

* From :doc:`/trainings/material/soup/linux/basics/shell/index`

  * :doc:`/trainings/material/soup/linux/basics/shell/links`
  * :doc:`/trainings/material/soup/linux/basics/shell/configfiles`

* From :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/index`

  * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/io-redirection`
  * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/io-redirection-swap-stdout-stderr`
  * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/pipes`
  * :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/exercises`

Multithreading (And C++)
........................

From :doc:`/trainings/repertoire/linux-prog/sysprog/multithreading`:

* Race Conditions, and prevention thereof (mutexes)
* Communication mechanisms (condition variable)
* Atomics
* Realtime

From :doc:`/trainings/material/soup/cxx/cxx11/multithreading/index`

* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/scoped-locking`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/040-locking-atomics/atomics`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/promise-future`
* :doc:`/trainings/material/soup/cxx/cxx11/multithreading/condition-variable`
