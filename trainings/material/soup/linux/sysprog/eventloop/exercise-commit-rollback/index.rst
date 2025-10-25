.. include:: <mmlalias.txt>


Exercise: Commit/Rollback Via ``SIGUSR1``/``SIGUSR2``
=====================================================

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/signals/signalfd/index`
   * :doc:`/trainings/material/soup/linux/sysprog/signals/index`
   * :doc:`/trainings/material/soup/linux/sysprog/eventloop/poll-cpp/index`

In :doc:`the last exercise <../exercise-graceful-termination/index>`,
we added graceful termination to our :doc:`database application
</trainings/material/soup/linux/sysprog/eventloop/poll-cpp/index>`. The
application then has a chance to commit the changes before exiting.

Lets add more commit/rollback logic to the application so that it
reacts on two more signals, ``SIGUSR1`` and ``SIGUSR2``.

* ``SIGUSR1`` commits the database
* ``SIGUSR2`` rolls back the database
