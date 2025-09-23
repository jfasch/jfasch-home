.. include:: <mmlalias.txt>


Introduction
============

.. topic:: Documentation

   * `man -s 7 signal
     <https://man7.org/linux/man-pages/man7/signal.7.html>`__

Notification To Processes
-------------------------

* Integer value with predefined meaning (termination request, invalid
  memory access, ...)
* Sent to a process (or a process group)
* Either by another process

  .. image:: inter-process.svg
     :scale: 40%

* Or by the kernel

  .. image:: kernel-process.svg
     :scale: 40%



* Traditional: async

  * Default actions
  * signal vs sigaction

  * Disposition

       Term   Default action is to terminate the process.

       Ign    Default action is to ignore the signal.

       Core   Default action is to terminate the process  and  dump  core  (see
              core(5)).

       Stop   Default action is to stop the process.

       Cont   Default  action  is  to  continue  the process if it is currently
              stopped.

    * async-signal-safety

* sync -> later

* Generate: kill, raise, sigqueue (-> rt-signals)

* Use case: graceful termination

Details
-------

