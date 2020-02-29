Screenplay
==========

.. contents::
   :local:

Signals
-------

Barebones Naive Program
.......................

* ``pause()``: sit and wait for something to happen. A signal for
  example.
* Output PID for convenience (``getpid()``)
* Discuss "Default actions", see `man 7 signal
  <http://man7.org/linux/man-pages/man7/signal.7.html>`__.

  * ``kill TERM <pid>`` -> terminated
  * ``kill SEGV <pid>`` -> core (discuss)
  * Show exit status `!= 0`

* Discuss core (post mortem debugging)

  .. code-block:: shell

     $ cat /proc/sys/kernel/core_pattern 
     |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %h

  Hmm. Don't want them to send that core home.

  .. code-block:: shell

     # echo core > /proc/sys/kernel/core_pattern

  Better yet, to prevent conflicts (many processes dumping to ``core``
  simultaneously)

  .. code-block:: shell

     # echo core.%p > /proc/sys/kernel/core_pattern

.. literalinclude:: Code/signals/010-signal-basics.cc
   :language: c++

Signal Handler
..............

* ``termination_handler()``: *signal handler*
* Why does it jump through hoops for simple output on stderr? See `man
  7 signal-safety
  <http://man7.org/linux/man-pages/man7/signal-safety.7.html>`__.
* Installed as handler for ``SIGTERM``

  * Still only ``pause()``, in linear flow, no loop
  * Terminates -> why? Show fallthrough, cout after pause
  * Discuss ``errno``, ``EINTR``, and error handling in general
  * Introduce loop around pause
  * Install as ``SIGINT``. No second terminal necessary to ``kill
    <pid>``, but rather ``Control-C`` in controlling terminal.

* Termination

  * ``bool quit`` -> NO! ``sig_atomic_t``
  * ``while (!quit) ... pause ...``

* Fix crap

  * cout in signal handler context
  * ``sig_atomic_t quit``
  * Error handling. Fail when trying to comprehend bloody ``signal()``
    return value. Use ``sigaction`` from here on.
  * ``sigaction``: why is complicated better than simple?

.. literalinclude:: Code/signals/020-signal-handler.cc
   :language: c++

Alarm
.....

* Add ``alarm()`` periodic handler (i.e. re-arm in signal handler)
* See how ``pause()`` is still interrupted

.. literalinclude:: Code/signals/030-signal-termination-alarm.cc
   :language: c++

Multithreading
..............

Multithreading and signals: *There Be Dragons*. Hmm. How.

Innocent Multithreaded Program
``````````````````````````````

Consumes from n pipes, in n threads, and writes to stdout.

.. literalinclude:: Code/signals/040-mt-pipe.cc
   :language: c++


Add ``SIGALRM``
```````````````

Add alarm handling to that. **Be puzzled why system calls are not
interrupted in pipe threads as one would expect.**

.. literalinclude:: Code/signals/050-mt-pipe-alarm.cc
   :language: c++

Write a standalone single-threaded program and see system call
interrupted.

.. literalinclude:: Code/signals/051-st-pipe-alarm.cc
   :language: c++

**Discuss**

* ``man open`` says ``EINTR`` on pipe
* ``man alarm`` says delivered to calling *process*

.. danger::

   So WTF?

Virtual Memory, ``mmap()``
--------------------------

Basic ``mmap()`` demo. Read ``/etc/passwd`` by creating a *mapping*
and only using memory access.

.. literalinclude:: Code/shm/010-mmap.cc
   :language: c++

* Give explanation of mappings
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

.. literalinclude:: Code/shm/020-shm-create.cc
   :language: c++

Produce into Shared Memory
..........................

* Using ``MAP_SHARED`` (as opposed to ``MAP_PRIVATE`` which makes
  write operations *copy-on-write*)
* Opens ``O_RDWR``: incrementing a counter requires reading it first.

.. literalinclude:: Code/shm/030-shm-produce.cc
   :language: c++

Consume from Shared Memory
.......................... 

.. literalinclude:: Code/shm/040-shm-consume.cc
   :language: c++

POSIX Semaphores
----------------

Analogous to the shared memory demo above, this is a scenario where
two parties use ``post`` and ``wait()`` on a semaphore.

Create Semaphore
................

We create a semaphore with initial value 7 (7 ``wait`` operations
without blocking).

.. literalinclude:: Code/shm/100-sem-create.cc
   :language: c++

Wait
....

.. literalinclude:: Code/shm/110-sem-wait.cc
   :language: c++

Post
....

.. literalinclude:: Code/shm/120-sem-post.cc
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

.. literalinclude:: Code/mq/010-mq-create.cc
   :language: c++

Produce
.......

Produce a number of items, and see what mqueue-fs says.

.. literalinclude:: Code/mq/020-mq-produce.cc
   :language: c++

Consume
.......

Show how a read blocks when queue is empty.

.. literalinclude:: Code/mq/030-mq-consume.cc
   :language: c++

