Technical Background
====================

.. contents::
   :local:

Linux Systems Programming
-------------------------

.. sidebar:: Training Courses

   * :doc:`/trainings/repertoire/linux-prog/linux-basics`
   * :doc:`/trainings/repertoire/linux-prog/sysprog/index`

I :doc:`grew up <cv-de>` with the good (?) old commercial Unixen,
having fun ... err, specializing ... at the bottom of user space. The
fun continued when Linux took over and consequently improved on Unix
concepts (see for example `signalfd
<https://man7.org/linux/man-pages/man2/signalfd.2.html>`__, `eventfd
<https://man7.org/linux/man-pages/man2/eventfd.2.html>`__, `timerfd
<https://man7.org/linux/man-pages/man2/timerfd_create.2.html>`__, and
`epoll
<https://man7.org/linux/man-pages/man2/epoll_create.2.html>`__).

* Realtime
* Network programming
* Interprocess communication
* Event loop programming (best done in Python using lovely
  ``asyncio``)
* Multithreading
* Memory management

Embedded Linux
--------------

.. sidebar:: Training Courses

   * :doc:`/trainings/repertoire/linux-prog/embedded/embedded`
   * :doc:`/trainings/repertoire/linux-prog/embedded/raspi-hands-on`
   * :doc:`/trainings/material/soup/linux/toolchain/index`

No wonder I got torn into the Embedded space. ``/dev/i2c-*``,
``/dev/spi.*``, what a fun it was to speak with devices from ordinary
programs. Of course, "Embedded" is more - low resources for example,
but that's another story.

* I2C (in-kernel and userspace)
* SPI (in-kernel and userspace)
* GPIO (in-kernel and userspace)
* Serial interfaces (RS232, RS485)
* USB (host and device, mit `libusb <https://libusb.info/>`__ and
  `GadgetFS
  <https://www.kernel.org/doc/html/v5.8/driver-api/usb/gadget.html>`__)
* `Yocto <https://www.yoctoproject.org/>`__

Linux Kernel
------------

.. sidebar:: Training Courses

   * :doc:`/trainings/repertoire/linux-prog/kernel-programming-basics`

Naturally, out of curiosity and a couple of customer projects, I got
into kernel programming. The kernel is a different beast, and
*implementing* user space is rather interesting.

Programming Languages
---------------------

.. sidebar:: Training Courses

   * :doc:`/trainings/repertoire/python/index`
   * :doc:`/trainings/repertoire/c-like/c`
   * :doc:`/trainings/repertoire/c-like/c-advanced`
   * :doc:`/trainings/repertoire/c-like/cxx`
   * :doc:`/trainings/material/soup/cxx/cxx11/index`
   * :doc:`/trainings/repertoire/linux-prog/bash`

Over the years, many programming languages happened. C++ is my mother
tongue, and I still enjoy using it. Uncomfortable with its complexity
*and teachability*, I haven't unlearned it like Perl - C is much more
to the point though. Python is my all-time favorite. Shell is fun
too - it is teachable *and* weird enough to be much fun (and it
reflects in a rather creative way the Unix concepts that I like so
much).

Software Development At Large
-----------------------------

.. sidebar:: Training Courses

   * :doc:`/trainings/repertoire/misc/make`
   * :doc:`/trainings/material/soup/misc/cmake/index`
   * :doc:`/trainings/repertoire/misc/unittests`

In my non-freelance life, I've been in roles called "architect". I
have also been in roles like "team lead", but that's not what I really
am [#team_lead]_ - I'm a programmer with a feel for the larger view.

* Object oriented programming
* Unit Testing and Test Driven Development (out of conviction)
* Build tools and packaging

.. rubric:: Footnotes
.. [#team_lead] Once you start to give colleagues technical guidance,
                your bosses will soon want you to give them
                administrative guidance. Watch out! Be careful!
