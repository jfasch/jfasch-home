.. meta::
   :description: This live-hacking screenplay is a guide for myself to
                 repeatably, didactically, demonstrate how POSIX IPC
                 (semaphores, shared memory, message queues) work on
                 Linux
   :keywords: linux, systemnah, schulung, training, programming, ipc,
              shared memory, semaphore, message queue

POSIX IPC (Live Hacking Screenplay)
===================================

.. sidebar:: Contents

   .. contents::
      :local:

Virtual Memory, ``mmap()``
--------------------------

* First, read ``/etc/passwd`` using regular file IO
* Discuss copy from/to kernel space
* Basic ``mmap()`` demo: read ``/etc/passwd`` by creating a *mapping*
  and only using memory access.

.. literalinclude:: shm-code/010-mmap.cc
   :caption: :download:`shm-code/010-mmap.cc`
   :language: c++

* Give explanation of mappings
* Discuss copy -> whiteboard sketch
* Show ``/proc/<pid>/maps``
* ``strace`` to see how address space is prepared
* File mappings vs. anonymous

POSIX Shared Memory
-------------------

Show how *POSIX Shared Memory* is nothing but ``mmap()`` with
predefined filenames. Here we show three programs,

* One creates a shared memory segment
* One writes into that memory; *produces*
* One reads from it; *consumes*

.. note::

   Producer and consumer do *not* use any locking. If multiple
   producers are run, then this will lead to lost increments. (This is
   what semaphores are there for.)

Create Shared Memory Segment
............................

* Using ``shm_open()`` with ``O_CREAT``
* Ends up as a file in ``/dev/shm/`` (a ``tmpfs`` instance)
* Zero size after create.
* Use ``ftruncate()`` to resize as appropriate

.. literalinclude:: shm-code/020-shm-create.cc
   :caption: :download:`shm-code/020-shm-create.cc`
   :language: c++

Produce into Shared Memory
..........................

* Using ``MAP_SHARED`` (as opposed to ``MAP_PRIVATE`` which makes
  write operations *copy-on-write*)
* Opens ``O_RDWR``: incrementing a counter requires reading it first.

.. literalinclude:: shm-code/030-shm-produce.cc
   :caption: :download:`shm-code/030-shm-produce.cc`
   :language: c++

Consume from Shared Memory
.......................... 

.. literalinclude:: shm-code/040-shm-consume.cc
   :caption: :download:`shm-code/040-shm-consume.cc`
   :language: c++

POSIX Semaphores
----------------

Analogous to the shared memory demo above, this is a scenario where
two parties use ``post`` and ``wait()`` on a semaphore.

Create Semaphore
................

We create a semaphore with initial value 7 (7 ``wait`` operations
without blocking).

.. literalinclude:: shm-code/100-sem-create.cc
   :caption: :download:`shm-code/100-sem-create.cc`
   :language: c++

Wait
....

.. literalinclude:: shm-code/110-sem-wait.cc
   :caption: :download:`shm-code/110-sem-wait.cc`
   :language: c++

Post
....

.. literalinclude:: shm-code/120-sem-post.cc
   :caption: :download:`shm-code/120-sem-post.cc`
   :language: c++

POSIX Message Queues
--------------------

Another three program scenario

* Create
* Produce
* Consume

Create
......

* Gotcha: names have to start with '/'
* Think about messages. Common sense is to communicate flat C structs.
* Measurement sample: (channel, timestamp, value). Think about sizes
  and datatypes. Alignment :-)
* Create the queue
* Mount the mqueue-fs, and look into it,

  .. code-block:: shell

     # mkdir mqueue-mount
     # mount -t mqueue blah mqueue-mount

.. literalinclude:: mq-code/010-mq-create.cc
   :caption: :download:`mq-code/010-mq-create.cc`
   :language: c++

Produce
.......

Produce a number of items, and see what mqueue-fs says.

.. literalinclude:: mq-code/020-mq-produce.cc
   :caption: :download:`mq-code/020-mq-produce.cc`
   :language: c++

Consume
.......

Show how a read blocks when queue is empty.

.. literalinclude:: mq-code/030-mq-consume.cc
   :caption: :download:`mq-code/030-mq-consume.cc`
   :language: c++

