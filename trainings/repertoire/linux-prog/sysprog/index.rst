.. meta::
   :description: Systems Programming in Linux: Network Programming,
                 Multithreading, Multiprocessing, Memory Management,
                 Shared Memory, Kernel Drivers
   :keywords: schulung, training, programming, embedded, linux, kernel
              driver, memory management, multithreading,
              multiprocessing, network, tcp-ip, udp


Linux Systems Programming (Course Series)
=========================================

.. sidebar::
   :class: jf-course-description-sidebar

   .. grid:: 1

      .. grid-item-card:: Duration: see each course
      .. grid-item-card:: :doc:`/trainings/info`
      .. grid-item-card:: 
   
	 .. dropdown:: Related Courses

	    * :doc:`basics`
	    * :doc:`network`
	    * :doc:`multithreading`
	    * :doc:`advanced`
	      
	    * :doc:`../linux-basics`
            * :doc:`../kernel-programming-basics`
            * :doc:`../embedded/embedded`
            * :doc:`../embedded/raspi-hands-on`

	 .. dropdown:: Slide Material

	    * :doc:`/trainings/material/soup/linux/sysprog/index`


Courses
-------

*Systems Programming in Linux* is a series of courses, each of about
two or three days worth of content (mixed lecture and exercises).

* :doc:`basics`. A big picture of Linux/UNIX programming is given,
  serving as the basis for all other courses in this series.

  * Shell intro
  * *Everything is a file*
  * Toolchain, and Debugging
  * Core concepts: processes, files and directories, and permissions

  .. toctree::
     :hidden:

     basics

* :doc:`network`. A thorough walkthrough of network programming.

  * Paradigms, and basic system calls (``socket()``, ``connect()``,
    ``bind()``, ``listen()``, ``accept()``)
  * TCP/IP networking: TCP and UDP communication
  * UNIX domain sockets
  * CAN-Bus networking (optional)
  * Async: ``select()``, ``poll()``, and ``epoll()``

  .. toctree::
     :hidden:
  
     network

* :doc:`multithreading`.

  * Introduction to `POSIX Threads
    <https://en.wikipedia.org/wiki/Pthreads>`__
  * Race conditions, and locking mechanisms
  * Communication mechanisms
  * Realtime

  .. toctree::
     :hidden:
  
     multithreading

* :doc:`advanced`.

  * Virtuelles memory
  * POSIX IPC: semaphore, message queues
  * Linux specific system calls: ``signalfd()``, ``timerfd_create()``,
    or ``eventfd()``

  .. toctree::
     :hidden:
  
     advanced

Prerequisites
-------------

Attendees should be fluent in C.
