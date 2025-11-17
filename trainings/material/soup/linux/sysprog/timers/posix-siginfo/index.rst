.. include:: <mmlalias.txt>


POSIX Timers: Additional Information (``siginfo_t``)
====================================================

.. topic:: Trainer's note

   Continue with the oneshot timer demo program from
   :ref:`sysprog-timers-oneshot-code`
   (:doc:`../posix-oneshot-periodic/index`)

``siginfo_t``: A Bag Of Further Information
-------------------------------------------

.. topic:: Documentation

   * `man -s 2 sigaction
     <https://man7.org/linux/man-pages/man2/sigaction.2.html>`__
     (search for ``siginfo_t``)

* Look into `man -s 2 sigaction
  <https://man7.org/linux/man-pages/man2/sigaction.2.html>`__
* That structure contains a whole lot of information across all
  signals (for example, ``SIGSEGV`` populates a number of hardware
  specific fields)
* What remains for our purposes: ``union sigval`` containing either an
  ``int`` or a ``void*``
* Specified in ``timer_create(..., struct sigevent*, ...)``
* Echoed back in signal handler

  * ``sigaction``: ``SA_SIGINFO``
  * Together with a different handler

.. code-block:: c

   #include <signal.h>

   siginfo_t {
       ...
       union sigval si_value;
       ...
   };

   union sigval {
       int             sival_int;
       void           *sival_ptr;
   };


Code: Pass Additional Expiry Information
----------------------------------------

.. literalinclude:: code/siginfo.cpp
   :language: c++
   :caption: :download:`code/siginfo.cpp`

Use Case: Multiple Timers, Single Signal Handler
------------------------------------------------

* Can create more timers than signals available
* |longrightarrow| Use *one* signal for multiple timers

.. topic:: Trainer's note

   * Create two timers
   * Both onto ``SIGRTMIN``
   * ``timer_t`` objects must be global (shared between main and
     handler)
   * Pass a pointer to the timer (``sigval.sival_ptr = &timer1``) for
     ``SA_SIGINFO`` semantics
   * Configure periodic timers

.. literalinclude:: code/two-timers-siginfo.cpp
   :language: c++
   :caption: :download:`code/two-timers-siginfo.cpp`
