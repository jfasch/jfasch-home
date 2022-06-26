.. ot-topic:: cxx03.functions_and_methods.exercise_class_rectangle

.. include:: <mmlalias.txt>


Exercise (FH): ``class rectangle``
==================================

.. contents::
   :local:

Building ``class rectangle`` Upon ``class point``
-------------------------------------------------

In the project you have set up in :doc:`class-point`, you'll find an a
test suite for a ``class rectangle``, again together with a sparse
implementation thereof.

Continuing the tradition of *test driven development*, continually
extend ``class rectangle`` by adding the following tests one by one.

.. literalinclude:: code/tests/rectangle-default-ctor.cpp
   :caption: :download:`code/tests/rectangle-default-ctor.cpp`
   :language: c++

.. literalinclude:: code/tests/rectangle-coordinates.cpp
   :caption: :download:`code/tests/rectangle-coordinates.cpp`
   :language: c++

.. literalinclude:: code/tests/rectangle-area.cpp
   :caption: :download:`code/tests/rectangle-area.cpp`
   :language: c++

.. literalinclude:: code/tests/rectangle-operator-eq-ne.cpp
   :caption: :download:`code/tests/rectangle-operator-eq-ne.cpp`
   :language: c++

.. literalinclude:: code/tests/rectangle-operator-plus-equal-vec.cpp
   :caption: :download:`code/tests/rectangle-operator-plus-equal-vec.cpp`
   :language: c++

.. literalinclude:: code/tests/rectangle-plus-vec.cpp
   :caption: :download:`code/tests/rectangle-plus-vec.cpp`
   :language: c++

.. literalinclude:: code/tests/rectangle-operator-ostream.cpp
   :caption: :download:`code/tests/rectangle-operator-ostream.cpp`
   :language: c++

