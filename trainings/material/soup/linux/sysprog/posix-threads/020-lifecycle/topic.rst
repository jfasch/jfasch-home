.. include:: <mmlalias.txt>


Thread Life Cycle
=================

Thread Life Cycle
-----------------

.. list-table::
   :align: left

   * * * ``pthread_create()`` creates new thread
       * *Start function* is called
       * Thread terminates
       * ``pthread_join()`` synchronizes with termination (fetches
         *exit status*)

       No parent/child relationship |longrightarrow| anybody can join

     * 

       .. image:: pthread-life-joinable-return.dia

Thread Creation
---------------

.. code-block:: c
   :caption: `man pthread_create <https://man7.org/linux/man-pages/man3/pthread_create.3.html>`__

   int pthread_create(
       pthread_t *thread, const pthread_attr_t *attr,
       void *(*start_routine) (void *), void *arg);

* ``thread``: ID of the new thread (*output parameter*)
* ``attr`` |longrightarrow| see later (``NULL`` |longrightarrow|
  default attribute)
* ``start_routine``: thread start function, ``void*/void*``
* ``arg``: parameter of the start function

Thread Termination (1)
----------------------

**Thread termination alternatives:**

* Return from start function
* ``pthread_exit()`` from somewhere inside the thread (cf. ``exit()``
  from a process)
* ``pthread_cancel()`` from outside (cf. ``kill()``)
* ``exit()`` of the entire process |longrightarrow| all contained
  threads are terminated

.. danger::

   Don't use ``pthread_cancel()`` unless you know what you are doing!

Thread Termination (2)
----------------------

Without any further ado: the manual ...

.. code-block:: c
   :caption: `man 3 pthread_exit <https://man7.org/linux/man-pages/man3/pthread_exit.3.html>`__

   void pthread_exit(void *retval);
  
.. code-block:: c
   :caption: `man 3 pthread_cancel <https://man7.org/linux/man-pages/man3/pthread_cancel.3.html>`__

   int pthread_cancel(pthread_t thread);

Exit Status, ``pthread_join()``
-------------------------------

**A thread's "exit status":**
  
* ``void*``, just like the start parameter |longrightarrow| more
  flexible than a process's ``int``.
* Parameter to ``pthread_exit()``
* Return type of the start function

.. code-block:: c
   :caption: `man 3 pthread_join <https://man7.org/linux/man-pages/man3/pthread_join.3.html>`__

   int pthread_join(pthread_t thread, void **retval);

Detached Threads
----------------

**Sometimes one does not want to use** ``pthread_join()``

* Rather, run a thread in the "background".
* "Detached" thread
* |longrightarrow| `Thread attribute
  <https://man7.org/linux/man-pages/man7/attributes.7.html>`__

.. code-block:: c
   :caption: `man 3 pthread_attr_setdetachstate <https://man7.org/linux/man-pages/man3/pthread_attr_setdetachstate.3.html>`__

   int pthread_attr_setdetachstate(
       pthread_attr_t *attr, int detachstate);
   PTHREAD_CREATE_DETACHED
     Threads that are created using attr will be created in a
     detached state.

* Detaching at runtime ...

.. code-block:: c
   :caption: `man 3 pthread_detach <https://man7.org/linux/man-pages/man3/pthread_detach.3.html>`__

   int pthread_detach(pthread_t thread);

Thread ID
---------

* ``pthread_create()`` returns ``pthread_t`` to the caller
* Thread ID of calling thread: ``pthread_self()``
* Compare using ``pthread_equal()``

.. code-block:: c
   :caption: `man 3 pthread_self <https://man7.org/linux/man-pages/man3/pthread_self.3.html>`__

   pthread_t pthread_self(void);

.. code-block:: c
   :caption: `man 3 pthread_equal <https://man7.org/linux/man-pages/man3/pthread_equal.3.html>`__

   int pthread_equal(pthread_t t1, pthread_t t2);

Scheduled Entities (1)
----------------------

Kernel maintains *scheduled entities* (Process IDs, "1:1 scheduling")

.. code-block:: console
   :caption: Threads inside ``firefox``

   $ ps -eLf|grep firefox
   $ ls -1 /proc/30650/task/
   13960
   13961
   ... (many  more) ...

Scheduled Entities (2)
----------------------

**Too bad:**

* Scheduled entity's ID *is not the same as* ``pthread_t``
* Correlation of OS threads and POSIX thread is Linux specific

.. code-block:: c
   :caption: `man 2 gettid <https://man7.org/linux/man-pages/man2/gettid.2.html>`__

   pid_t gettid(void);
