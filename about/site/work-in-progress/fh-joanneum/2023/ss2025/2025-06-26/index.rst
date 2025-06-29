.. include:: <mmlalias.txt>


2025-06-26 (3 VO): Project Standup, Exam
========================================

.. contents::
   :local:

.. toctree::
   :hidden:

   exam

Didactic Masterplan
-------------------

* What are we doing here?

  Poll in millisecond intervals, reading input-switch levels and
  sensor values. From that, we determine input-switch level
  transitions (edges), and then deduce state transitions.

  This is stupid - input-switch edges are in fact *events* into our
  state machine. This is what *interrupts* are there for, at the
  hardware level.

* Can that be done better?

  Yes. Events in Linux are throughout representable as file
  descriptors (timers, signals, incoming and outgoing network traffic,
  GPIOs and their edges). On top of one can do *event driven
  programming* using for example the aptly named `poll system call
  <https://man7.org/linux/man-pages/man2/poll.2.html>`__ to watch
  multiple file descriptor for events.

* What else is in the masterplan?

  * More OS knowledge is in order. We know how to program C++, and
    know roughly what we are doing. But who knows

    * what an `ioctl <https://man7.org/linux/man-pages/man2/ioctl.2.html>`__ is?
    * how to create a process and to communicate with it over a pipe
      from which further events can be read into the parent process?
    * how to treat a `timer file descriptor
      <https://man7.org/linux/man-pages/man2/timerfd_create.2.html>`__?

  * Likewise, more C++ knowledge is in order.

    * Should we really be able to *copy* an object that maintains a
      file descriptor (like the I2C sensors that we use)? Whose
      destructor would then be responsible to close the file
      descriptor?
    * Are there safer ways to pass objects than by-pointer?

Standup
-------

* Talk about outcome from :doc:`../2025-06-24/index`
* Talk about followup tasks (and their deadlines)

  * :doc:`../tasks/motor-stepper`
  * :doc:`../tasks/input-output-switch`
  * ADC usage for error "door motor somehow stuck"
  * Ideas?

Exam
----

* :doc:`exam`
