.. include:: <mmlalias.txt>


Introduction
============

* Refer to pictures in
  :doc:`/trainings/material/soup/linux/basics/io-redirection-pipes/pipes`
  and
  :doc:`/trainings/material/soup/linux/sysprog/process/unnamed-pipe-ipc/index`

.. image:: simple-pipe.svg
   :scale: 40%

.. image:: multiple-sources.svg
   :scale: 40%

Basic Functionality
-------------------

* Database inserts from stdin ``(id, firstname, lastname)``

.. literalinclude:: code/problem-basic.cpp
   :language: c++
   :caption: :download:`code/problem-basic.cpp`

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
