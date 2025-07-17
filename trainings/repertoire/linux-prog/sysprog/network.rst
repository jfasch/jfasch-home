Linux Systems Programming: Network Programming
==============================================

.. sidebar::
   :class: jf-course-description-sidebar

   .. grid:: 1

      .. grid-item-card:: Duration: 2 Days
      .. grid-item-card:: :doc:`/trainings/info`
      .. grid-item-card:: 
   
	 .. dropdown:: Related Courses

	    * :doc:`index`
	    * :doc:`basics`
	    * :doc:`multithreading`
	    * :doc:`advanced`
	      
	    * :doc:`../linux-basics`
            * :doc:`../kernel-programming-basics`
            * :doc:`../embedded/embedded`
            * :doc:`../embedded/raspi-hands-on`

	 .. dropdown:: Slide Material

	    * PDF Slides, :download:`sysprog
              </trainings/material/pdf/020-linux-sysprog--en.pdf>`

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
