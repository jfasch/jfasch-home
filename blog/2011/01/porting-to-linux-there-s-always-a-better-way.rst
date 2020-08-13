.. post:: 2011-01-07
   :category: linux, embedded
   :author: Jörg Faschingbauer
   :location: Hart bei Graz, Austria
   :language: en

Porting to Linux (There's Always A Better Way)
==============================================

.. sidebar:: Contents

   .. contents::
      :local:

Over the past months I met a couple of people who are relatively new
to Linux. For one, I've been to Germany doing courses on Linux -
naturally the audience in such a course is new to Linux. For another,
I have one and a half customers here in Austria who are mainly doing
microcontroller work and who don't have a clue of Linux.

Many of these people have code which they have written and maintained
over a long time, and which has a value. The code runs happily on bare
metal, or on a minimal OS like Segger embOS, Enea OSE, VxWorks, or
even Windows CE. No way rewriting it just because of Linux.

Well, there's no need to. It's just not trivial to choose the right
mechanisms. Linux (and Unix in general) offers so many choices to mess
things up right from the beginning. And it's quite likely that things
are in fact messed up, which is what I learned from the people I met.

"Good Old Device Firmware" is quite limited in what it can use.

* It is a statically linked blob of executable code.
* It operates in a single address space (there's generally no idea
  what an address space is, so there is only one).
* It has interrupts hammering on it.
* If there is an OS, then chances are that there are multiple
  processes that are scheduled by the OS. Often processes communicate
  by dumping messages into each other's message queues.
* Locking mechanisms. In the presence of interrupts you need to
  disable them if need be. If processes are used, there are generally
  semaphores available in one or more flavors.
* It's these simple concepts where the confusion starts. For example,
  in Linux/Unix a process is probably not what you want - you rather
  want a thread instead. When you search for the term "message queue"
  you will find *several* mechanisms, *none of which* are what you
  want. You'll notice sooner or later that you chose the wrong
  concept, but it's maybe too late to revert - causing your Linux port
  to fail over the years. (In my opinion it's never too late to
  revert, but that's a different kind of story.)

In the remainder I'll try to give a list of recipes for porting to
Linux. I hope that it will help you speed up the porting project, by
avoiding severe mistakes right at the beginning. The list cannot be
complete - it's just a blog post after all. But I do hope it will give
you a bigger picture than you already have, and that it provides you
with the starting points for your own research (which you will have to
do unless you want to hire me as a consultant :-).

Processes are Threads
---------------------

In the embedded OS world, you use the word "process" to refer to an
entity that is scheduled by the OS. There is no such thing as separate
address spaces and memory protection in such systems (these OS's are
initially designed for cheap MMU-less processors).

So, what people generally want is *threads*. *Processes* in Unix refer
to address space separation and memory protection, so don't get misled
only by the term. The Unix way of multithreading is POSIX threads
(pthreads for short). On Linux, ``man pthreads`` will tell you
more. Better yet, buy yourself a copy of a `PThreads Programming
<http://oreilly.com/catalog/9781565921153>`__ book. Read that book
twice. Threading has lots of pitfalls, and it is crucial to understand
these. (I have seen people create five threads to solve a simple
data-acquisition-and-network-communication problem where they didn't
know what a mutex was.)

Signals Aren't Messages
-----------------------

Don't use Unix signals for communication. They have very few in common
with what's called a *signal* in RTOSs. (In the RTOS world, *signals*
are often called *messages*.)

.. sidebar:: References

   * :doc:`Slide material: UNIX signals
     </trainings/material/soup/sysprog/sysprog_signals/slides>`
   * :doc:`Demo code: UNIX signals
     </trainings/material/soup/sysprog/sysprog_signals/screenplay>`

In Unix, signals are commonly used to tear down a process (*not* a
thread), giving it a chance to perform proper cleanup before
exit. There are other uses of signals as well, such as notification of
memory protection violation (the dreaded "segmentation fault") and
other programming errors.

The problem with signal handling is that signals arrive in a special
context which you probably know as "interrupt context" in your
OS. Consequently, your options are very limited in a signal
handler. You cannot use most of the functions that are available from
the C runtime library!

If you still feel that you need to use signals, then perform the
following steps.

* Think twice. Why do you need signals? There's probably a better way.
* Read ``man -s 7 signal`` for more. **Pay special attention to the
  section about async-signal-safe functions** (note that none of the
  ``pthread_`` functions appears in the list).
* Try to defer processing from the signal handler into the regular
  course of your application. For example, you can use the "self pipe"
  trick (Google sure knows about it.)
* Forget about asynchronous signal delivery and use one of the``
  sigwait``, ``sigwaitinfo``, and ``sigtimedwait`` system calls. This
  way you suspend the execution of one thread until a signal is
  caught, thus turning signal handling into a *synchronous*
  approach. You'd have to dedicate an entire thread to signal handling
  though.
* An alternative way of synchronous signal handling is to use the new
  ``signalfd`` system call. Its semantics are the same as
  ``sigwaitinfo``, only you use a file descriptor as an "event
  source". You can embed this file descriptor among other event
  sources in an event driven application, using ``select``, ``poll``,
  or ``epoll``. See below for more.

Message Queues aren't Message Queues
------------------------------------

.. sidebar:: References

   * :doc:`Slide material: POSIX message queues
     </trainings/material/soup/sysprog/sysprog_ipc/slides>`
   * :doc:`Demo code: POSIX message queues
     </trainings/material/soup/sysprog/sysprog_ipc/screenplay>`

Chances are that the threads (err, processes) of your OS communicate
via messages queues over which messages (err, signals) are sent. A
naive Google search ("Linux message queues") will lead you to POSIX
and System V message queues, both of which are inter process
communication (IPC) mechanisms. This is probably not what you want, as
your messages need not be transferred across different address
spaces. Intra process message queues are normally built on top of
pthread primitives. You can find a sample such implementation `here
<http://jf-linuxtools.git.sourceforge.net/git/gitweb.cgi?p=jf-linuxtools/jf-linuxtools;a=blob;f=pthread/base/message-queue.h>`__.

Semaphores and Mutexes
----------------------

.. sidebar:: References

   * :doc:`Slide material: POSIX semaphores
     </trainings/material/soup/sysprog/sysprog_ipc/slides>`
   * :doc:`Demo code: POSIX semaphores
     </trainings/material/soup/sysprog/sysprog_ipc/screenplay>`

Many of those OSs out there have semaphores as the one and only
synchronisation mechanism. Linux has semaphores - System V and POSIX
style. Again these are probably not what you want. You are likely to
initialize your semaphores with a count of one and use it as a *binary
semaphore*. This is what a pthread mutex is for instead.

See ``man pthread_mutex_init`` for more.

Confusing note for those porting from Windows: A *critical section* is
the region that is protected by a mutex, although a
``CRITICAL_SECTION`` is the closest Windows pendant to a mutex.

Timers
------

Timers are hard, not only on Linux.

In most embedded OSs, timers expire as interrupts which are then
handled by the application. Sometimes there is the possibility to let
the OS send you a message (err, signal) on timer expiration.

There are multiple APIs for timers, most of which (``setitimer``,
``timer_create``) require you to use signals (Unix signals this
time) - see above for the drawbacks to this approach. Unfortunately a
straightforward Google search will lead you to these APIs.

An alternative is to simply defer the execution of a thread for a
specified amount of time, using ``nanosleep``. Another alternative is
to use ``timerfd_create`` and friends in conjunction with ``select``
or ``poll``, and embed timers into an event driven application. (See
below for event loops based on file descriptors. See `here
<http://jf-linuxtools.git.sourceforge.net/git/gitweb.cgi?p=jf-linuxtools/jf-linuxtools;a=blob;f=linux-events/events/timer.h>`__
for a sample implementation of such a thing.)

You can always build your own structures around whatever timer
mechanism and emulate the behavior of your OS on Linux. This might
require quite a bit of understanding of Linux programming, though.

Polling
-------

Polling for something to happen is generally the most stupid thing to
do, not only on Linux. The are cases (screwed hardware for example)
where there is no other way, but otherwise there's always a better
way.

I have seen people set a flag in one process (err, thread), and poll
for it every millisecond from another thread. I know, a millisecond is
an eternity in nowadays' processors - but I can imagine that there are
more flags of that sort being polled for, in a moderately complex
program. After all, it's *events* that these flags communicate. Some
OSs have an "event flag" mechanism which tries to achieve exactly
that, albeit a bit more intelligently - for example without the need
for polling, and without losing events through race conditions.

There's a big wealth of mechanisms in Linux to communicate events. Use
message queues (see above), for example. Build your own "event flag"
mechanism by using PThreads primitives (but not before you have read
the book).

Event Dispatching
-----------------

On Unix, *everything is a file*. Entire disks are represented as
files, partitions are, network sockets are, arbitrary devices are (for
example, serial/UART lines). Regular files are, naturally. On Linux,
even timers and Unix signals can be represented as files, as I
mentioned previously. Every open file is represented as a *file
descriptor*. File descriptors can be read from and written to, using
the ``read`` and ``write`` system calls, regardless of their type.

For people who are new to Unix, this may come as a surprise: you can
read from a serial line as if it were a network connection, and you
can read from a network connection as if it were a regular
file. (Anyone tried that on Windows?)

This fact alone is something you can take advantage of in your porting
project.

Now what has this got to do with *event dispatching*? Consider the
following types of *events* that regularly happen on an OS:

* Network connection has data to be read.
* Network connection can be written to without blocking (or, "local
  TCP buffer just got emptied" or so).
* Same with serial IO (open ``/dev/ttyS0`` or so just like a regular
  file), as with any kind of stream connection.
* A timer has expired.
* A signal has arrived.
* An arbitrary event happened (check out the ``eventfd`` system call;
  I didn't mention it).
* Even USB events are delivered via files. (It's just a bit more
  complicated because USB is a bit more complicated; there's `libusb
  <http://www.libusb.org/>`__ there to handle this.).
* Most drivers for hardware devices deliver the device interrupts as
  events through file descriptors (you open ``/dev/blah`` just like a
  regular file), nicely telling you "Hey, I've got to tell you
  something!".

There is a set of system calls that are used to wait for events on
*multiple* file descriptor, namely ``select``,`` poll``, and
``epoll``. Note that these system call put the calling process (err,
thread) to sleep until something happens - the name ``poll`` has
nothing to do with polling as we know it.

So, depending on your application, you might find it relatively easy
to use either of these system calls. Build a bit of an infrastructure
around it, like registering and unregistering callbacks, and you will
be able to comfortably use these extremely exciting mechanisms. (Or
take `my own infrastructure
<http://jf-linuxtools.git.sourceforge.net/git/gitweb.cgi?p=jf-linuxtools/jf-linuxtools;a=blob;f=events/dispatcher.h>`__. Or
take anybody else's, mine's not the only - it's just the best.)

One last note: look at the desktop environment of your choice. It's
made up of a hundred or so processes (no, not threads). Under Gnome,
which is what I use, there's a process called`` gnome-panel``, for
example. Try out ``strace -p <pid of gnome-panel>;``, direct the mouse
over the panel, and see what happens: ``poll`` all over.

Interrupts
----------

One of the primary goals of an OS is to shield you from
hardware. There a clear separation between *user space* and *kernel
space*. User space uses system calls to talk to the kernel. No
interrupts in user space. Basta. (Don't even think about using
signals!)

If you have hardware that nobody else has, then chances are you will
have to deal with it yourself and write a driver for it. That's about
the only case where you'll get in touch with interrupts and have to
learn kernel programming. But this is a completely different story,
and a different world. Definitely fun.

Nevertheless, I suggest you stay away from kernel programming just
because it is fun. Debugging is much harder there. A buggy user space
program crashes, possibly leaving you with a core dump that you can
examine with a debugger (well, GDB). Everything else will remain
running. A buggy kernel crashes, leaving nothing running. This is what
*I* call hard.

On Linux, there are a couple of hardware interfaces exported to
userspace. I already mentioned `userspace USB
<http://www.libusb.org/>`__. There is a similar thing to implement USB
*devices* in user space, called `GadgetFS
<http://www.linux-usb.org/gadget>`__.

For others, look inside the kernel documentation, part of the kernel
source, in the ``Documentation/`` directory. (Usually, the kernel
source is installed in ``/usr/src/linux/``.) Or simply ask Google.

For example, check out the userspace I2C and SPI interfaces described
in ``Documentation/i2c/dev-interface`` and
``Documentation/spi/spidev``.

Realtime
--------

Well, realtime ... what's that? To put it bluntly, Linux is realtime
capable.

By default, Linux schedules processes ("scheduled entities", so to
say - threads as well as processes) *in a fair way*. This is, everyone
gets its fair share of CPU resources. As such, there are no guarantees
given as to when a process is scheduled, and whether its deadlines are
met.

**However:**

You can make any process realtime-scheduled, by calling
``sched_setscheduler()``. You can make threads realtime-scheduled,
selectively, by creating them with the appropriate attributes (see
``pthread_attr_setschedparam()``, and read the book :-).

Realtime-processes are scheduled *immediately* when they become
runnable (unless a higher priority process is runnable as well, of
course). And by immediate I mean immediate - and that's what *I* call
realtime. No fairness involved anymore, definitely not nice
anymore. And therefore potentially harmful.

Basically, there's two realtime scheduling policies to choose from:

* ``SCHED_FIFO``. The process runs until it puts itself to sleep
  (waiting for something to happen), or until it is interrupted by a
  process which has an even higher priority.
* ``SCHED_RR``. Processes in the same priority level alternate in a
  round robin manner, with very short timeslices. As with
  ``SCHED_FIFO``, they are interrupted by higher priority processes.

Check out the man pages, and read the book. No joke. Doing realtime
scheduling is crying for trouble. Even more so if code is involved
where you don't know 100% exactly what it does. It might go into an
infinite loop, at best. At worst, it will trigger race conditions only
under certain circumstances, or bring up deadlock
situations. Naturally, this kind of errors does not show up during
in-house testing where you are able to inspect and fix them, but
rather months later, at your customer's site.

That's it been for now. I could possibly add a couple more items to
this list, right now. Deployment comes to mind (What's a firmware
image in Linux? Will I be minimal? Do I use `BusyBox
<http://busybox.net/>`__ and `uClibc <http://www.uclibc.org/>`__?),
build issues (Shared libraries? Static? What, how, why?). I could add
another couple more items if I you give me a minute.

If you have read through this list, you'll see what I mean: take care
to choose the right mechanisms. Don't start coding immediately because
there's no time left in the project. Thinking twice and investigating
will save you from spending even more time later in the project. (But
what am I telling you?)
