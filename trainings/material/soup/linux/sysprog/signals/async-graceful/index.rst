.. include:: <mmlalias.txt>

Use Case: Graceful Termination
==============================

Problem
-------

* Program blocks inside a main loop, waiting for something (network
  packet, command on a named pipe or message queue, ...)
* ``SIGTERM`` (and ``SIGINT``, for that matter) should initiate a
  *clean* exit |longrightarrow| cleanup, proper database sync, ...
* |longrightarrow| Default disposition (immediate termination at
  signal arrival) is inappropriate

Solution
--------

* Set ``quit`` flag in signal handler
* Main loop's blocking call is interrupted (``EINTR``)
* Flag can be honored
* ``sig_atomic_t`` as per POSIX standard (simply ``int`` on Linux)

.. literalinclude:: code/graceful-termination.cpp
   :language: c++
   :caption: :download:`code/graceful-termination.cpp`
