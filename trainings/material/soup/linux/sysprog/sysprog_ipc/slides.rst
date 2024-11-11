Slides: Sysprog: POSIX IPC
==========================

* **Unix IPC:** mechanisms to communicate between unrelated* processes

  * Semaphores
  * Shared memory
  * Message queues
  * *No sockets*

History: Two IPC Variants
-------------------------
  
* **System V IPC**

  * Cumbersome, unnecessarily complex API
  * Older -> more portable between Unixen

* **POSIX IPC**

  * Easy to use
  * Much of it implemented in userspace (through memory mapped files)
  * Optional feature in POSIX (fully supported in Linux though)

Object Names
------------

* **Communication between unrelated processes**

  * *Related*: none is a descendant of the other (``fork()``)
  * Cannot *inherit* object
  * Must be able to *locate* them

* **System-wide visibility via names**

  * Just like files
  * In fact, most IPC mechanisms *are* files (at least in Linux)
  * Consistently with leading slash: ``/some-object-name``

File Semantics
--------------
  
* **Objects look just like files**. For example,

  * ``shm_open()``, using the same flags as good ol' ``open()``
  * ``shm_unlink()`` to remove a shared memory segment, just like good
    ol' ``unlink()`` removes a file.

* **Handles are reference counted**

  * Shared memory: ``int`` - a true file descriptor
  * Message queue: ``mqd_t`` (typedef ``int``)
  * Incremented across ``fork()``, ``dup()`` etc.


.. Semaphores
.. -------------------------------------------------------------------------------------------

Semaphores
----------

**Communication and synchronization device**

* Bag of N elements 
* N items can be consumed without waiting
* (N+1)st consumer has to wait until an item is goiven back

**Creation parameter**

* Initial value N

`man -s 7 sem_overview
<http://man7.org/linux/man-pages/man7/sem_overview.7.html>`__

Open/Create: ``sem_open()``
---------------------------

.. code-block:: c

   sem_t *sem_open(const char *name, int oflag);
   sem_t *sem_open(const char *name, int oflag, 
                   mode_t mode, unsigned int value);

* Again: file semantics
* Like ``open()``, to calling "signatures"

  * *create*
  * *open*

* ``value``: initial value N (creation only)

`man -s 3 sem_open <https://linux.die.net/man/3/sem_open>`__

Communication: ``sem_wait()``, ``sem_post()``
---------------------------------------------

.. code-block:: c

   int sem_wait(sem_t *sem);
   int sem_trywait(sem_t *sem);
   int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
   int sem_post(sem_t *sem);

* *wait*: consume element; blocks if count is zero
* *post*: give element back

`man -s 3 sem_wait
<http://man7.org/linux/man-pages/man3/sem_wait.3.html>`__

`man -s 3 sem_post
<http://man7.org/linux/man-pages/man3/sem_post.3.html>`__

Closing/Removing: ``sem_close(), ``sem_unlink()``
-------------------------------------------------

.. code-block:: c

   int sem_close(sem_t *sem);
   int sem_unlink(const char *name);

* Boring (again) ...
* Analogy: ``close()`` and ``unlink()``.

`man -s 3 sem_close
<http://man7.org/linux/man-pages/man3/sem_close.3.html>`__

`man -s 3 sem_unlink
<http://man7.org/linux/man-pages/man3/sem_unlink.3.html>`__

Semaphores are Files
--------------------

.. code-block:: console

   $ ls -l /dev/shm/
   total 1604
   -rw------- ... sem.my-semaphore

* ``/dev/shm`` is a ``tmpfs`` instance
* ``sem.my-semaphore`` is a *regulare file* in it

  * Contains a flat structure, the semaphore

* ``sem_t`` encapsulates open file descriptor and ``void*`` (the
  mapped memory)


.. Shared Memory
.. -------------------------------------------------------------------------------------------

Shared Memory (1)
-----------------

.. code-block:: c

   int shm_open(const char *name, int oflag, mode_t mode);
   int shm_unlink(const char *name);

**POSIX shared memory** is almost non-existing ...

* Small wrapper around existing system calls
* ``shm_open()`` only dictates the object name (``/some-name``)

  * Explicitly returns a file descriptor

* ``shm_close()`` does not exist. Use ``close()``.

`man -s 7 shm_overview
<http://man7.org/linux/man-pages/man7/shm_overview.7.html>`__

Shared Memory (2)
-----------------

**Workflow**

* After creating (``shm_open()``), size is zero
* ``ftruncate()``, to adjust the size
* ``mmap()``, to create the mapping

As simple as it can get!

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
