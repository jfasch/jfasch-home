.. ot-topic:: sysprog.signal.async_selfpipe
   :dependencies: sysprog.signal.async

.. include:: <mmlalias.txt>

Use Case: Self-Pipe Trick
=========================

Problem
-------

* Want to do more in signal handlers
* Probably not a good idea: cannot do more in signal handlers (see
  :ref:`here <sysprog-signals-async-signal-safe>`)

Solution
--------

* Defer signal handling to main loop
* Transport medium: `pipe
  <https://man7.org/linux/man-pages/man2/pipe.2.html>`__ between
  signal handler context and program context

.. literalinclude:: code/self-pipe.cpp
   :language: c++
   :caption: :download:`code/self-pipe.cpp`
