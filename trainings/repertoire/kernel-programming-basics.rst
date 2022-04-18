.. meta::
   :description: A quickstart foor those who are fluent in C, and want
                 to learn how the linux kernel works internally
   :keywords: schulung, training, programming, c, linux, kernel, linux
              kernel, driver, kernel driver, module, hardware, pci,
              semaphore, mutex, spinlock, wait queue, waitqueue,
              device, character device, block device, interrupt,
              interrupt handler, isr, dma

Linux Kernel Driver Development
===============================

.. sidebar::

   .. list-table::
      :align: left

      * * **Duration**
	* 5 days
      * * **Course Language**
	* Heavy C
      * * **Booking**
	* training@faschingbauer.co.at
      * * **Course Material**
	* :doc:`/trainings/material/soup/kernel/group`
      * * **Source Code**
	* `jf-kernel-course
          <https://github.com/jfasch/jf-kernel-course>`__


First off: the Linux kernel cannot be taught in 5 days - no way.

Target audience of this course are experienced C programmers who want
to get an idea of what it means to be a "Linux kernel hacker". A
quickstart, giving an overview of the mechanisms that define the
kernel universe: parallelism, memory management, scheduling, interrupt
handling, to name only a few.

With this, and with a great dose of curiosity, you will find yourself
enabled to find your own way through the various subsystems inside the
Linux kernel.

Course Contents
---------------

* **Modules**. A *module* is dynamic shared object that is loaded into
  a running kernel. We cover its *initialization* on load,
  *deinitialization* at unload, and various other aspects like
  metadata and module dependencies.
* **Devices**. Hardware is represented in software as a
  *device*. Device special files (those in ``/dev/``) are used to give
  userspace an easy to use interface.
* **Synchronization mechanisms**. Unlike userpace, where the *process*
  abstraction implements the illusion of being alone, the kernel is a
  massively parallel program (things are further complicated by the
  presence of hardware interrupts). It is thus vital to know how to
  protect oneself against any kind of race condition.
* **Communication mechanisms**. Waiting for an event to occur - while
  not consuming any CPU time - is one of the most important
  responsibilities of any operating system.
* **Interrupt handling**. Hardware interrupts are something that an
  operating system cannot do without. Linux has a number of ways to
  deal with interrupts.
* **Direct memory access (DMA)**. Efficient communication between
  hardware devices and (processes running on) the CPU requires devices
  to be able to access CPU memory. Devices access main memory in
  different ways; we give an overview of the APIs that are available
  to implement each.
* **PCI**. PCI hardware is commonplace in today's computers. We
  explain how the PCI subsystem of the Linux kernel works.
  
Sample Project
--------------

An exercise project accompanies the course, giving the audience a
chance to get in touch with the mechanisms as they are covered.

See :doc:`here </trainings/material/soup/kernel/sample-project>` for a
trainer-centric view of what's to be done.
