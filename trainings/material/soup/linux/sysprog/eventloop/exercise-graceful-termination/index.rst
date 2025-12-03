.. include:: <mmlalias.txt>


Exercise: Graceful Termination Via ``SIGTERM``/``SIGINT``
=========================================================

.. topic:: See also

   * :doc:`/trainings/material/soup/linux/sysprog/signals/signalfd/index`
   * :doc:`/trainings/material/soup/linux/sysprog/signals/index`
   * :doc:`/trainings/material/soup/linux/sysprog/eventloop/poll-cpp/index`

Exercise
--------

Our :doc:`database application
</trainings/material/soup/linux/sysprog/eventloop/poll-cpp/index>`
still does not commit the database when terminated like processes are
usually terminated,

.. image:: ../../eventloop-idea.svg
   :scale: 20%
   :align: right

* ``Ctrl-C`` from the terminal, when run in foreground (``SIGINT`` is
  delivered)
* ``kill <PID>`` from another process; the shell, usually (``SIGTERM``
  is delivered)

Add to the application another ``InputHandler`` implementation (lets
give it the name ``GracefulTerminator``). That implementation uses a
:doc:`signalfd instance
</trainings/material/soup/linux/sysprog/signals/signalfd/index>` to
request ``SIGINT`` and ``SIGTERM`` delivery via a file descriptor. 

Add a method ``GracefulTerminator::hookup(Eventloop&)`` which does
everything that is necessary to make the event loop aware of the file
descriptor. See
:doc:`/trainings/material/soup/linux/sysprog/eventloop/poll-cpp/stdin-db-code`
and
:doc:`/trainings/material/soup/linux/sysprog/eventloop/poll-cpp/udp-db-code`
for how such a ``hookup()`` method is usually implemented

Solution
--------

.. literalinclude:: code/graceful-term.h
   :language: c++
   :caption: :download:`code/graceful-term.h`

.. literalinclude:: code/graceful-term.cpp
   :language: c++
   :caption: :download:`code/graceful-term.cpp`

.. literalinclude:: code/main.cpp
   :language: c++
   :caption: :download:`code/main.cpp`
