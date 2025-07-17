Linux Systems Programming: Multithreading
=========================================

.. sidebar::
   :class: jf-course-description-sidebar

   .. grid:: 1

      .. grid-item-card:: Duration: 2 Days
      .. grid-item-card:: :doc:`/trainings/info`
      .. grid-item-card:: 
   
	 .. dropdown:: Related Courses

	    * :doc:`index`
	    * :doc:`basics`
	    * :doc:`network`
	    * :doc:`advanced`
	      
	    * :doc:`../linux-basics`
            * :doc:`../kernel-programming-basics`
            * :doc:`../embedded/embedded`
            * :doc:`../embedded/raspi-hands-on`

	 .. dropdown:: Slide Material

	    * PDF Slides, :download:`sysprog
              </trainings/material/pdf/020-linux-sysprog--en.pdf>`

Parallel programming is hard - this is no different on Linux. This
course gives a solid overview of multithreading on Linux (POSIX
threads, basically), and its mechanisms for synchronization and
communication. Ah, yes, realtime.

.. image:: salad-mt-small.jpg
   :alt: Applied Multithreading
   :align: right

Course Outline
--------------

* **Thread lifecycle**. Once started, threads need to be managed, and
  sometimes they also need to be terminated.

  * Thread creation
  * *Joinable* vs. *detached*
  * Thread termination
  * Thread attributes: realtime properties

* **Raceconditions, and avoidance**. In the face of multithreading,
  all code you write can only be wrong. Why is that?

  * Load-Modify-Store: the mother of all raceconditions
  * Mutexes: types (e.g. normal vs. recursive), usage
  * Atomic operations on builtin types

* **Communication mechanisms**. Understanding *condition variables*

  * Principles: the lost wakeup bug
  * Exercise: a handwritten message queue
  * Exercise: mimicking WIN32 auto reset events

* **Miscellaneous**.

  * One-time initialization
  * Thread Specific Data (Thread Local Storage)

* **Realtime**. Yes, Linux is a realtime OS.

  * Scheduling policies: FIFO, round robin, batch, deadline ...
  * Scheduling priorities
  * Bugs, bugs: priority inversion, and avoidance
  
Prerequisites
-------------

A solid understanding of the C programming language is helpful. Fun
with low-level hacking is required.
