.. include:: <mmlalias.txt>


``signalfd`` Integration
========================

Additional Feature: Graceful Termination (``SIGTERM``, ``SIGINT``)
------------------------------------------------------------------

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/signals/intro/index`
   * :ref:`sysprog-signals-async-signal-safe`
   * :doc:`/trainings/material/soup/linux/sysprog/signals/async-self-pipe/index`

.. topic:: Trainer's note

   Copy signal handler code from
   :doc:`/trainings/material/soup/linux/sysprog/signals/async-graceful/index`,
   and adapt.

.. literalinclude:: code/problem-graceful-termination.cpp
   :language: c++
   :caption: :download:`code/problem-graceful-termination.cpp`

Additional Feature: Commit/Rollback (``SIGUSR1``, ``SIGUSR2``)
--------------------------------------------------------------

* ``SIGUSR1``: ``commit+log+debug`` request asynchronously (by the
  auditor?)
* ``SIGUSR2``: ``rollback``

.. literalinclude:: code/problem-commit-rollback.cpp
   :language: c++
   :caption: :download:`code/problem-commit-rollback.cpp`
