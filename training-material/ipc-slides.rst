POSIX IPC: Slides
=================

.. basics
.. -------------------------------------------------------------------------------------------

Inter Process Communication (IPC) (1)
-------------------------------------

**Traditional Unix IPC:** mechanisms to communicate between unrelated
*processes*

* Semaphores
* Shared memory
* Message queues

*Unrelated*: not related via parent/child relationships

Inter Process Communication (IPC) (2)
-------------------------------------

**History: two IPC variants ...**
  
* *System V IPC*

  * Cumbersome, unnecessarily complex API
  * Older -> more portable between Unixen

* *POSIX IPC*

  * Easy to use
  * Much of it implemented in userspace (through memory mapped files)
  * Optional feature in POSIX (fully supported in Linux though)

**We're doing POSIX!**

POSIX IPC: Overview
-------------------

**IPC object names:**

* System-wide visibility -> just like files
* Consistently like so: ``/some-object-name``

**API:**
  
* Semaphores, shared memory and message queues are opened just like
  files. E.g. ``shm_open()``, using the same flags.
* Just like file descriptors, all types are reference counted.


.. Message Queues
.. -------------------------------------------------------------------------------------------

Message Queues
--------------

**Message queue creation parameters:**
  
* Maximum number of messages
* Maximum size of a single message
* *Realtime guarantees*

**Message priorities:**
  
* Messages are sent with a priority
* Higher prioritized messages overtake lower prioritized messages

.. sidebar:: Link

   `man -s 7 mq_overview
   <http://man7.org/linux/man-pages/man7/mq_overview.7.html>`__

Open/Create: ``mq_open()``
--------------------------

.. code-block:: c

   mqd_t mq_open(const char *name, int oflag);
   mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);

.. sidebar:: Link

   `man -s 3 mq_open
   <http://man7.org/linux/man-pages/man2/mq_open.2.html>`__

In ``attr`` the only relevant members are ``mq_flags``, ``mq_maxmsg``
and ``mq_msgsize``.

Sending/Receiving: ``mq_send()``, ``mq_receive()``
--------------------------------------------------

.. code-block:: c

   int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned msg_prio);
   ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned *msg_prio);

.. sidebar:: Links

   * `man -s 3 mq_receive
     <http://man7.org/linux/man-pages/man3/mq_receive.3.html>`__
   * `man -s 3 mq_send
     <http://man7.org/linux/man-pages/man3/mq_send.3.html>`__

Closing/Removing: ``mq_close()``, ``mq_unlink()``
-------------------------------------------------

.. code-block:: c

   int mq_close(mqd_t mqdes);
   int mq_unlink(const char *name);

.. sidebar:: Links

   * `man -s 3 mq_close
     <http://man7.org/linux/man-pages/man3/mq_close.3.html>`__
   * `man -s 3 mq_unlink
     <http://man7.org/linux/man-pages/man3/mq_unlink.3.html>`__

  Analogy: ``close()`` and unlink()``.


Notification: ``mq_notify()``
-----------------------------

**Notification: obscure feature, only shown because of its obscurity
...**

.. code-block:: c

   int mq_notify(mqd_t mqdes, const struct sigevent *sevp);

Please read yourself and be disturbed!

.. sidebar:: Link

   `man -s 3 mq_notify
   <http://man7.org/linux/man-pages/man3/mq_notify.3.html>`__

Message Queues are Files
------------------------

**Obvious implementation:** (provided there's OS infrastructure)
  
* Message queues are implemented as files
* Virtual filesystem - ``mqueue``

Notifications can be received more elegantly - ``select()``,
``poll()``, ``epoll``!

Message Queue Filesystem: ``mqueue``
------------------------------------

**Message queues visible as files:** the *mqueue* filesystem

.. code-block:: shell
  
   # mount -t mqueue blah /mnt/mqueue
   # ls -l /mnt/mqueue/my-queue
   -rw------- ... /mnt/mqueue/my-queue
   # cat /mnt/mqueue/my-queue
   QSIZE:0          NOTIFY:0     SIGNO:0     NOTIFY_PID:0     


.. Semaphores
.. -------------------------------------------------------------------------------------------

Semaphores
----------

**Creation parameter:**

* Initial value

.. sidebar:: Link
  
   `man -s 7 sem_overview
   <http://man7.org/linux/man-pages/man7/sem_overview.7.html>`__

Open/Create: ``sem_open()``
---------------------------

.. code-block:: c

   sem_t *sem_open(const char *name, int oflag);
   sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);

.. sidebar:: Link

   `man -s 3 sem_open <https://linux.die.net/man/3/sem_open>`__

Communication: ``sem_wait()``, ``sem_post()``
---------------------------------------------

.. code-block:: c

   int sem_wait(sem_t *sem);
   int sem_trywait(sem_t *sem);
   int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);

.. sidebar:: Link

   `man -s 3 sem_wait
   <http://man7.org/linux/man-pages/man3/sem_wait.3.html>`__

.. code-block:: c

   int sem_post(sem_t *sem);

.. sidebar:: Link

   `man -s 3 sem_post
   <http://man7.org/linux/man-pages/man3/sem_post.3.html>`__

Closing/Removing: ``sem_close(), ``sem_unlink()``
-------------------------------------------------

.. code-block:: c

   int sem_close(sem_t *sem);
   int sem_unlink(const char *name);

.. sidebar:: Links

   * `man -s 3 sem_close
     <http://man7.org/linux/man-pages/man3/sem_close.3.html>`__
   * `man -s 3 sem_unlink
     <http://man7.org/linux/man-pages/man3/sem_unlink.3.html>`__

  Analogy: ``close()`` and ``unlink()``,

Semaphores are Files
--------------------

* Implemented as file mappings
* ``sem_t`` encapsulates open file descriptor and ``void*`` (the
  mapped memory)
* ``/dev/shm`` is a ``tmpfs`` instance

.. code-block:: shell

   $ ls -l /dev/shm/
   total 1604
   -rw------- ... sem.my-semaphore


.. Shared Memory
.. -------------------------------------------------------------------------------------------

Shared Memory (1)
-----------------

**POSIX shared memory** is almost non-existing ...

* Small wrapper around existing system calls
* `` shm_open()``. Does not even pretend to be something
  special -> explicitly returns a file descriptor
* ``shm_close()``

.. sidebar:: Link

   `man -s 7 shm_overview
   <http://man7.org/linux/man-pages/man7/shm_overview.7.html>`__

Shared Memory (2)
-----------------

**Further steps:**

* ``ftruncate()``, to adjust the size
* ``mmap()``, to create the mapping

The only reason for the ``shm_*`` is the "where" -> ``/dev/shm``

.. exercise
.. -------------------------------------------------------------------------------------------

Exercise: POSIX Message Queues
------------------------------

**Add a POSIX message queue to our server like follows**
  
* The client (to be written) opens an existing message queue,
  sends a message, and closes the queue afterwards.
* The server

  * creates the message queue in the startup phase
  * receives (file descriptor based) notifications in the main loop,
    and reads and outputs messages just like the others
  * closes and removes the queue in the shutdown phase
