.. ot-topic:: sysprog.eventloop.poll_cpp
   :dependencies: sysprog.eventloop.poll

.. include:: <mmlalias.txt>


A Naive C++ Eventloop (Based Upon ``poll()``)
=============================================

Eventloop
---------

.. literalinclude:: code/eventloop.h
   :language: c++
   :caption: :download:`code/eventloop.h`

.. literalinclude:: code/eventloop.cpp
   :language: c++
   :caption: :download:`code/eventloop.cpp`

Solution
--------

See :ref:`underengineered C solution <sysprog-eventloop-poll-solution>`

.. literalinclude:: code/db-two-sources-eventloop.cpp
   :language: c++
   :caption: :download:`code/db-two-sources-eventloop.cpp`
