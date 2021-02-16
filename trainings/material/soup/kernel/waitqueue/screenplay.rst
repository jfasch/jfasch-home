.. include:: <mmlalias.txt>

Waiting for Something (Screenplay)
==================================

.. contents::
   :local:

``read()`` Not Implemented
--------------------------

* Use ``strace`` to show what ``cat`` does
* |longrightarrow| ``ENOSYS``, likely (``read()`` not implemented)

Implementing ``read()`` Naively
-------------------------------

* ``read()``, nonblocking version (see
  :doc:`../cdev-file-operations/topic`)
* implement same functionality as ``MY_GET_ONE_EVENT``
* size check of buffer |longrightarrow| ``-EINVAL`` (just like
  ``read()`` on a `timerfd
  <https://man7.org/linux/man-pages/man2/timerfd_create.2.html>`__
* *Get* one event, and copy that to the *userspace buffer* supplied by
  read.
* Return 0 if nothing's there

*Discussion*: What If Nothing's There?
--------------------------------------

* 0 is usually *end of file* |longrightarrow| ``cat`` terminates
* ``EAGAIN`` is normally returned in such cases
* but file descriptor has to be marked non-blocking, *by convention*
* Write userspace test program ``test-read-events.c``

  * Reads until EOF or error

* |longrightarrow| return ``-EAGAIN`` if nothing's there

  * Check how test program behaves

Implementing ``O_NONBLOCK``
---------------------------

* Check blocking-status of file descriptor

  .. code-block:: c

     filp->f_flags & O_NONBLOCK

* If non-blocking, enter the code that we have now
* Else |longrightarrow| *wait*, hm

* Add parameter to ``test-read-events.c``:
  ``blocking``/``nonblocking``

  * Test the wait
