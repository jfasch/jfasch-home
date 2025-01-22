.. include:: <mmlalias.txt>


A Simple Client/Server Scenario
===============================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`file-mappings`
   * :doc:`/trainings/material/soup/linux/sysprog/posix-threads/040-mutex/topic`

Idea: One Chunk Of Data, And A Mutex
------------------------------------

.. sidebar:: Documentation

   * `man -s 2 mmap
     <https://man7.org/linux/man-pages/man2/mmap.2.html>`__
   * `man -s 3 pthread_mutexattr_setpshared
     <https://man7.org/linux/man-pages/man3/pthread_mutexattr_setpshared.3.html>`

* Shared data ...

  .. code-block:: c++

     struct Data
     {
         struct pthread_mutex_t lock;
         char name[32];
	 int value;
	 int valid;
     };

* Protected by a mutex |longrightarrow| *process shared*

Server: Initialize Shared Data, Poll For Data
---------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/file-io/example-O_EXCL`
   * :ref:`sysprog-ftruncate`

* Open shared file
* Truncate it to hold one ``struct Data`` item
* ``mmap``
* Initialize ``valid`` flag
* Initialize mutex |longrightarrow| *process shared*
* Loop: every second, see if valid (properly taking and releasing
  mutex)

.. literalinclude:: code/file-mapping-polling-server.cpp
   :caption: :download:`code/file-mapping-polling-server.cpp`
   :language: c++

Client: Produce Data
--------------------

* Open file ``O_RDWR``: need to lock mutex (otherwise write-only)
* ``mmap``
* Put data into shared memory (properly taking and releasing mutex)

.. literalinclude:: code/file-mapping-polling-client.cpp
   :caption: :download:`code/file-mapping-polling-client.cpp`
   :language: c++
