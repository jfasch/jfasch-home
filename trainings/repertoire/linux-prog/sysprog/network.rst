Linux Systems Programming: Network Programming
==============================================

.. contents::
   :local:

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
	* 2 days
      * * **Language**
	* Trainer language is English or German
      * * **Material**
	* * PDF Slides, :download:`sysprog </trainings/material/pdf/020-linux-sysprog--en.pdf>`
      * * **Related**
	* * :doc:`basics`
	  * :doc:`advanced`
	  * :doc:`multithreading`
	  * :doc:`/trainings/repertoire/linux-prog/linux-basics`
      * * **Booking**
	* :doc:`/trainings/booking`


This course covers the socket interface and some of the protocols that
are supported by it, together with the programming paradigms that are
common with networking.

Course Outline
--------------

* **Network programming basics**. The socket interface is defined in
  abstract terms, not mentioning any of TCP/IP, or Bluetooth or ... . 

  * *Systemcalls*: ``socket()``, ``connect()``, ``bind()``,
    ``listen()``, ``accept()``
  * *Stream communication*: connection establishment and communication
  * *Datagrams*: connectionless communication
  * *Error scenarios*
  * *Adress families*

* **TCP/IP**. Network programming on The Internet

  * TCP and UDP
  * Address conversion routines
  * DNS-Lookup
  * IPv4 and IPv6

* **UNIX Domain Sockets**. An interprocess communication mechanism for
  processes running on the same machine.
* **CAN-Bus**. CAN (Controller Area Network) fits itself into the
  Linux network stack.
* **Event loops (select/poll/epoll)**.

  * Event driven programming
  * Nonblocking connection establishment
  * Nonblocking IO
  * Other applications of events: timers (via timer file descriptors),
    events (via event file descriptors)

Prerequisites
-------------

A solid understanding of the C programming language is helpful. Fun
with low-level hacking is required.
