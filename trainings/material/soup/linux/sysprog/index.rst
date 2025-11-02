.. ot-group:: sysprog


Linux Systems Programming
=========================

The material below covers "what an :doc:`old UNIX greybeard
</about/myself/index>` knows about his favorite OS". It is not to be
seen as classical slide material, but rather as support material for
didactical live programming [#slides-boring]_.

Training courses are always composed individually from what's there
(maybe combined with select topics from
:doc:`/trainings/material/soup/linux/basics/index`), see :doc:`here
for how to book </trainings/info>`.

..   * link material
..
..     * signals, and blocking IO, and the shell:
..       https://www.linusakesson.net/programming/tty/

Fundamentals
------------

This section covers the stone-old UNIX concepts
[#richard-stevens-late]_ that Linux has expanded where necessary
(:doc:`embedded hardware is just a file too
</trainings/material/soup/linux/hardware/index>`). It forms the
absolute basis for any kind of serious system level programming.

.. topic:: Contents

   .. toctree::
      :maxdepth: 1
   
      syscalls/index
      file-io/index
      process/index
      signals/index
      timers/index
      eventloop/index

Multithreading
--------------

**Outdated** This is course material which has done its duty
already. It is in the queue for refactoring, so it will look like the
"regular" material above. It can be booked nonetheless; in this case
the booked topics will receive extra priority points for refactoring
|:wink:|.

.. topic:: Contents

   .. toctree::
      :maxdepth: 1
   
      posix-threads/index

Inter Process Communication
---------------------------

**Outdated** This is course material which has done its duty
already. It is in the queue for refactoring, so it will look like the
"regular" material above. It can be booked nonetheless; in this case
the booked topics will receive extra priority points for refactoring
|:wink:|.

.. topic:: Contents

   .. toctree::
      :maxdepth: 1
   
      mmap/index
      sysprog_ipc/topic
      ipc-mqueue/topic

Scheduling And Realtime
-----------------------

**Outdated** This is course material which has done its duty
already. It is in the queue for refactoring, so it will look like the
"regular" material above. It can be booked nonetheless; in this case
the booked topics will receive extra priority points for refactoring
|:wink:|.

.. topic:: Contents

   .. toctree::
      :maxdepth: 1
   
      scheduling/index

Graphical Overview
------------------

.. ot-graph::
   :entries: sysprog

Ad-Hoc Live Demos
-----------------

.. toctree::
   :maxdepth: 1

   intro-hw/index
   blocking-io/index

Building Blocks For Sketches
----------------------------

.. image:: building-blocks.svg
   :scale: 40%


.. rubric:: Footnotes
.. [#richard-stevens-late] The books by W. Richard Stevens impressed
                           me when I was young, partly because they
                           are easily read cover-to-cover. They are
                           not quite up-to-date anymore, but I still
                           have to mention them. Check out `Advanced
                           Programming in the Unix Environment
                           <https://en.wikipedia.org/wiki/Advanced_Programming_in_the_Unix_Environment>`__
                           and `UNIX Network Programming
                           <https://en.wikipedia.org/wiki/UNIX_Network_Programming>`__.
.. [#slides-boring] I a course, I use to quickly explain what the
                    topic of the next hour (or so) is. Then I'll start
                    to program, and while I program I explain what I
                    do, and discuss matters. I consider this much more
                    satisfying than a frontal lecture.
