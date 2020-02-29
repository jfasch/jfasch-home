Proposal
========

This is a proposal (sorry not a formal agenda) for a one-day training,
covering the following topics.

* IPC (the most part)
* Code review of **BEEEEEEP**
* Optional: advanced topics

.. contents::
   :local:

Unix is a broad field of diversity and history. Just like there are
many ways to do timers, there are many ways to do IPC (and by the way,
many ways to do pretty much everything). It is a developer's
responsiblity to choose the best solution to a problem.

To make good choices and keep your system sane, it is good to have an
overview of the mechanisms available, and an understanding of how they
interfere with programming paradigms. Making bad choices is easy,
especially because things appear to work in simple proof of concept
scenarios, and lead to heavy breakage in nontrivial scenarios. For
example, using `Unix signals
<https://en.wikipedia.org/wiki/Signal_(IPC)>`__ as a timer
notification mechanism is the `most inappropriate choice one can make
<https://en.wikipedia.org/wiki/Signal_(IPC)#Risks>`__ - unfortunately
the top search hits on Google suggest exactly that.

Signals
-------

Starting with the most basic and inappropriate form of IPC, explain
what that mechanism is, especially in a historic context, and what its
semantics are. Conclusion: stay away.

Posix IPC (and Virtual Memory)
------------------------------

The term IPC - *Inter Process Communication* - is used in Unix
terminology to mean any of

* Message queues
* Semaphores
* Shared memory

Historically there is another family of IPC mechanisms, System-V
IPC. That has the same focus, almost equally named artifacts, but is
rather awkward to use, and not entirely portable. Linux supports that
API as well, but no-one encourages its use anymore. In case Google
suggests you use System-V IPC: *stay away*.

In this section, we will also hear about memory management is done in
modern operating systems. Virtual memory is at the basis of
(process-shared) semaphores and shared memory, so it is crucial to
know how that works.

Unix Domain Sockets
-------------------

The socket API is not part of the *IPC* category of communication
mechanisms, simply because "IPC" predates sockets by over a decade.

Unix domain sockets are just one transport among the other ones
supported by the socket API (the most popular being TCP/IP).

Application in your Company
---------------------------

Lets reserve some time to make a collaborative code review of
**BEEEEEEP**.

Further Thoughts
----------------

If there's time (I doubt it because one day is already tight enough to
cover IPC), we can also talk about more advanced topics. Sockets are
represented in Unix as *file descriptors*, just like regular files and
many other communication mechanisms, so it makes sense to at least
give an overview.

* `Timer events <https://lwn.net/Articles/251413/>`__
* Signal events
* Event loops
