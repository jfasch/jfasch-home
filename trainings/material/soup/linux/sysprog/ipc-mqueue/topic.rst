.. include:: <mmlalias.txt>


POSIX Message Queues
====================

.. toctree::
   :maxdepth: 1

.. libreoffice:: mqueue.odg

Overview
--------

.. sidebar:: Documentation

   * `man -s 7 mq_overview
     <http://man7.org/linux/man-pages/man7/mq_overview.7.html>`__

* **Message queue parameters**
  
  * Maximum number of messages
  * Maximum size of a single message
  * *Realtime guarantees* (memory is never swapped out)

* **Message priorities**
  
  * Messages are sent with a priority
  * Higher prioritized messages overtake lower prioritized messages
  * Linux: 0 through 32768-1 (POSIX: 0 through 31)

* **Linux Specific**

  * The POSIX API tries to differentiate itself from file IO
  * Although very similar
  * |longrightarrow| Message queue descriptors (``mqd_t``) *are* file
    descriptors
  * |longrightarrow| Usable in event loops (`man -s 2 select
    <https://man7.org/linux/man-pages/man2/select.2.html>`__, `man -s
    2 poll <https://man7.org/linux/man-pages/man2/poll.2.html>`__,
    `man -s 7 epoll
    <https://man7.org/linux/man-pages/man7/epoll.7.html>`__)

Setup: Message Queue Creation
-----------------------------

.. sidebar:: Documentation

   * `man -s 3 mq_open
     <https://man7.org/linux/man-pages/man3/mq_open.3.html>`__

* `mq_open <https://man7.org/linux/man-pages/man3/mq_open.3.html>`__
  is used for creating *and* opening (much like `man -s 2 open
  <https://man7.org/linux/man-pages/man2/open.2.html>`__)
* When ``flags`` contains ``O_CREAT`` ...

  * ``mode`` is required (permissions, see `man -s 2 open
    <https://man7.org/linux/man-pages/man2/open.2.html>`__)
  * ``attr`` is required

.. literalinclude:: code/create.cpp
   :caption: :download:`create.cpp <code/create.cpp>`
   :language: c++

``mqueue`` File System
----------------------

* Message queues *are* visible as files, actually (just a little
  funny)
* |longrightarrow| ``mqueue`` filesystem
* Usually mounted on ``/dev/mqueue``

.. code-block:: console

   # mkdir /dev/mqueue
   # mount -t mqueue none /dev/mqueue

* All message queues visible in ``/dev/mqueue``

.. code-block:: console

   $ ls -l /dev/mqueue/
   ...
   -rw-r--r--. 1 jfasch jfasch 80 Nov 11 09:08 my-queue
   ...

* File content: metadata |longrightarrow| *great for debugging*

  * ``QSIZE``: number of contained (unread) *bytes* (*not* messages)
  * ``NOTIFY, SIGNO, NOTIFY_PID``: historical baggage (nobody uses
    signals for notification anymore)

.. code-block:: console

   $ cat /dev/mqueue/my-queue 
   QSIZE:0          NOTIFY:0     SIGNO:0     NOTIFY_PID:0     

Teardown: Message Queue Deletion
--------------------------------

.. sidebar:: Documentation

   * `man -s 3 mq_unlink
     <https://man7.org/linux/man-pages/man3/mq_unlink.3.html>`__

* Just like `man -s 2 unlink
  <https://man7.org/linux/man-pages/man2/unlink.2.html>`__

.. literalinclude:: code/unlink.cpp
   :caption: :download:`unlink.cpp <code/unlink.cpp>`
   :language: c++

* ``rm`` would work too (on Linux)

.. code-block:: console

   $ rm /dev/mqueue/my-queue

Usage: Open An Existing Message Queue, And Produce Into It
----------------------------------------------------------

.. sidebar:: Documentation

   * `man -s 3 mq_open
     <https://man7.org/linux/man-pages/man3/mq_open.3.html>`__
   * `man -s 3 mq_send
     <https://man7.org/linux/man-pages/man3/mq_send.3.html>`__

* Open for writing: ``flags`` contains ``O_WRONLY``
* Use `mq_send
  <https://man7.org/linux/man-pages/man3/mq_send.3.html>`__ to produce
  a message into queue |longrightarrow| ``priority``
* *Attention*: ``mq_send()`` returns 0 on success (not the number of
  bytes written)

.. literalinclude:: code/produce.cpp
   :caption: :download:`unlink.cpp <code/produce.cpp>`
   :language: c++

* |longrightarrow| Eight bytes in queue

.. code-block:: console

   $ cat /dev/mqueue/my-queue 
   QSIZE:8          NOTIFY:0     SIGNO:0     NOTIFY_PID:0   

Usage: Open An Existing Message Queue, And Consume From It
----------------------------------------------------------

.. sidebar:: Documentation

   * `man -s 3 mq_open
     <https://man7.org/linux/man-pages/man3/mq_open.3.html>`__
   * `man -s 3 mq_receive
     <https://man7.org/linux/man-pages/man3/mq_receive.3.html>`__

* Open for reading: ``flags`` contains ``O_RDONLY``
* Use `mq_receive
  <https://man7.org/linux/man-pages/man3/mq_receive.3.html>`__ to
  consume a message from queue |longrightarrow| ``priority``

.. literalinclude:: code/consume.cpp
   :caption: :download:`consume.cpp <code/consume.cpp>`
   :language: c++

* |longrightarrow| Queue now empty

.. code-block:: console

   $ cat /dev/mqueue/my-queue 
   QSIZE:0          NOTIFY:0     SIGNO:0     NOTIFY_PID:0   

**Do Not Use**: ``mq_notify()``
-------------------------------

.. sidebar:: Documentation

   * `man -s 3 mq_notify
     <https://man7.org/linux/man-pages/man3/mq_notify.3.html>`__

**Obscure feature ...**

* Only shown because of its obscurity
* Specification *predates* that of event loops
* Guess what ... **SIGNALS**
* Please read yourself and be disturbed!
