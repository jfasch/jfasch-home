Embedded Software Development: Hardware, Realtime, and Memory Management
========================================================================

.. contents::
   :local:

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
	* 5 days
      * * **Language**
	* Trainer language is English or German
      * * **Related**
	* * :doc:`raspi-hands-on`
	  * :doc:`../linux-basics`
	  * :doc:`../sysprog/index`
	  * :doc:`../kernel-programming-basics`
      * * **Booking**
	* :doc:`/trainings/info`


Linux, being "a flavor of UNIX", builds upon the strong concepts of
that OS family. Yet Linux has proven to be an embedded OS too -
hardware support is amazingly complete, realtime capabilities are in
place, memory management is as fine grained as embedded developers
like it.

This course introduces into the OS and its system programming APIs,
with an emphasis on typical embedded topics like hardware, memory
management, and realtime.

Target Audience
---------------

* **Embedded software developers**
* **Electronic engineers** who work together with software developers,
  and occasionally have to get in touch with what those produce
* **System architects** whose job is to make good decisions

Attendees are invited to bring their own material - development boards
with their favorite processor architecture, breadboards, and all
that's needed for tinkering. Usually the trainer brings a couple of
Raspberry Pi computers, a pile of sensors, and wiring material.

Course Outline
--------------

* **Linux and the commandline** (taken from :doc:`this course
  <../linux-basics>`). 

  * Remote login with SSH
  * Basics: the shell, and tools like ``sed``, ``grep``, ``find`` ...
  * Diagnosing problems: ``netstat`` and ``ss``, ``top``, dedicated
    filesystems like ``procfs`` and ``sysfs``, the ``strace`` tool,
    ...

* **Programming** (taken from :doc:`../sysprog/index`).

  * Files and file IO. Be aware that file descriptors can describe
    almost anything (not just open files), and that the *file* IO
    topic is just the beginning. (:doc:`More
    ... </trainings/repertoire/linux-prog/sysprog/basics>`)
  * Processes. Address spaces and scheduling. (:doc:`More
    ... </trainings/repertoire/linux-prog/sysprog/basics>`)
  * Multithreading. (:doc:`More
    ... </trainings/repertoire/linux-prog/sysprog/multithreading>`)
  * Network programming. The socket interface not only covers TCP/IP,
    but also Bluetooth, CAN, and other protocols. (:doc:`More
    ... </trainings/repertoire/linux-prog/sysprog/network>`)
  * Memory Management. Virtual memory: shared memory, memory mapped
    IO, and IPC techniques. (:doc:`More
    ... </trainings/repertoire/linux-prog/sysprog/advanced>`)
  * Realtime. Linux is a realtime OS, and we'll learn what that means
      (:doc:`More
      ... </trainings/repertoire/linux-prog/sysprog/multithreading>`)
  * Kernel hacking. Not the center of this course, but it's always
    good to know how things that I use are implemented. (:doc:`More
    ... </trainings/repertoire/linux-prog/kernel-programming-basics>`)

* **Hardware**.

  * The General Purpose IO (GPIO) subsystem.
  * I2C userspace API
  * SPI userspace API
  * CAN, via the socket API ("SocketCAN")
  * UART communication

Prerequisites
-------------

* Programming experience in C and/or Python
* A feel for hardware
