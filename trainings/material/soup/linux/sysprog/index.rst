.. ot-group:: sysprog


Linux Systems Programming
=========================

..   * say something about where i learned unix (lesend am scheisshaus)
..   * blah these are the principles one should understand when doing
..     serious systems programming blah
..
..   * link material
..
..     * signals, and blocking IO, and the shell:
..       https://www.linusakesson.net/programming/tty/

Fundamentals
------------

This section covers the stone-old UNIX concepts that I love so much,
and that are still very active today - more than fifty years after The
Epoch. Linux has taken its freedom to expand where necessary
[#async-signals]_; knowing these concepts - Good Old UNIX, and modern
Linux - is a solid basis for serious Linux systems programming.

.. toctree::
   :maxdepth: 1

   syscalls/index
   file-io/index
   process/index
   signals/index
   eventloop/index

In The Queue: IPC, Multithreading, And More
-------------------------------------------

This is course material which has done its duty already. It is in the
queue for refactoring, so it will look like the "regular" material
above. It can be booked nonetheless; in this case the booked topics
will receive extra priority points for refactoring |:wink:|.

.. toctree::
   :maxdepth: 1

   posix-threads/index
   scheduling/index
   sysprog_events/topic
   sysprog_ipc/topic
   mmap/index
   ipc-mqueue/topic
   todo

Overview
--------

.. ot-graph::
   :entries: sysprog

Miscellanous Live Demos (And Other Stuff)
-----------------------------------------

.. toctree::
   :maxdepth: 1

   intro-hw/index
   blocking-io/index

Building Blocks For Sketches
----------------------------

.. image:: building-blocks.svg
   :scale: 40%


.. rubric:: Footnotes
.. [#async-signals] Asynchronous signal handling, for example, is
		    nothing that anybody really wants, let alone
		    asynchronous *timer* signal handling.
