Linux Systems Programming: Virtual Memory, IPC, Shared Libraries
================================================================

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
	    * :doc:`multithreading`
	      
	    * :doc:`../linux-basics`
            * :doc:`../kernel-programming-basics`
            * :doc:`../embedded/embedded`
            * :doc:`../embedded/raspi-hands-on`

	 .. dropdown:: Slide Material

	    * PDF Slides, :download:`sysprog
              </trainings/material/pdf/020-linux-sysprog--en.pdf>`
	    * Live Hacking, :doc:`Signals
              </trainings/material/soup/linux/sysprog/sysprog_signals/screenplay>`
	    * Live Hacking, :doc:`IPC
              </trainings/material/soup/linux/sysprog/sysprog_ipc/screenplay>`

Especially on :doc:`resource constrained systems <../embedded/index>`
it is important to use resources consciously. This course gives
insight into topics like advanced memory managements techniques,
advanced CPU utilization techniques (spoiler: single threaded event
driven).

Course Outline
--------------

* **Virtual memory**. A key component in modern operating systems,
  virtual memory is usually invisible to the programmer - unless the
  programmer wonders why things are simple.

  * *Memory mappings*
  * *Visibility*: "Private" vs. "shared"
  * *Memory access permissions*
  * *System calls*: ``mmap``, ``mlock``, ``mlockall``, ...
  * *Realtime aspects*

* **POSIX IPC**. Mostly based upon virtual memory, POSIX IPC is a set
  of interprocess communication mechanisms that is worth a look.

  * *Shared memory*
  * *Semaphores*
  * *Message queues*

* **Linux-spezific system calls**. Good old UNIX file descriptors have
  always been used as abstrations for file-like communication media
  (e.g. :doc:`network sockets <network>`). Linux extends the
  abstraction in logical ways.

  * *Signal Handling*: ``signalfd``. Signals are events, so why not
    treat them as such?
  * *Timer*: ``timerfd_create``. Timers are events, so why not treat
    them as such?
  * *Events*: ``eventfd``. Pretty, simple, powerful.

* **Shared libraries**.

  * *ELF*: "Executable and Linkable Format"
  * *Automatic (implicit) library loading*
  * *Explicit loading*: ``dlopen()``, and "loading scopes"
  
Prerequisites
-------------

A solid understanding of the C programming language is helpful. Fun
with low-level hacking is required.
