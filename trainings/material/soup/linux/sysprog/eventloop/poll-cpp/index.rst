.. ot-topic:: sysprog.eventloop.poll_cpp
   :dependencies: sysprog.eventloop.poll

.. include:: <mmlalias.txt>


A Naive C++ Eventloop (Based Upon ``poll()``)
=============================================

Eventloop
---------

.. topic:: Remark: this is not modern C++

   In nowadays C++, such a simple callback like "there's input to be
   done on file descriptor ``fd``" would not require an interface (see
   :doc:`/trainings/material/soup/cxx/cxx03/inheritance-oo-design/index`
   for more), but only a lambda (:doc:`here
   </trainings/material/soup/cxx/cxx11/lambda/index>`) or some other
   functional (:doc:`here
   </trainings/material/soup/cxx/cxx11/bind-function/020-function/topic>`)
   object.

   I'll use C++ conservatively though, in a way that is comprehensible
   to those who are not so fluent in that language.

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
