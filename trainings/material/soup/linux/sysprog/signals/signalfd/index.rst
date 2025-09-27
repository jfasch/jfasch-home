.. include:: <mmlalias.txt>


Event Loop Support: ``signalfd()``
==================================

.. topic:: Documentation

   * `man -s 2 signalfd
     <https://man7.org/linux/man-pages/man2/signalfd.2.html>`__

Basic Operation
---------------

.. code-block:: console

   #include <sys/signalfd.h>

   int signalfd(int fd, const sigset_t *mask, int flags);

* Signals received as *events*, via file descriptor

  * |longrightarrow| Perfect fit for event loop programming

* If ``fd == -1``, a new file descriptor is created
* If ``fd >= 0`` (another signal FD), its mask is replaced with the
  supplied ``mask``
* ``flags``: ``SFD_NONBLOCK``, ``SFD_CLOEXEC``
* ``read()`` on the ``fd`` into an array of ``signalfd_siginfo``
  structures
* Best to choose array size according to number of handled signals
  |longrightarrow| read all possible pending signals in one swoop

  * Different for realtime signals: these are queued

Example: A Better ``sigwaitinfo()``
-----------------------------------

.. topic:: Trainer's note

   Copy program from :doc:`../sync/index`, and replace ``sigwait()``
   with ``signalfd()``

* Show normal operation
* Suspend process
* Demonstrate how ``SIGUSR1`` and ``SIGUSR2`` are received together
  with one call to ``read()``
* Two instances of say ``SIGUSR1`` overwrite each other (standard
  signals vs. realtime signals)

.. literalinclude:: code/signalfd.cpp
   :language: c++
   :caption: :download:`code/signalfd.cpp`
