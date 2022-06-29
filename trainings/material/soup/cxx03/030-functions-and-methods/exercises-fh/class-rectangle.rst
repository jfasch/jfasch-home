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

.. important::

   Whenever an object of ``class rectangle`` is passed as a parameter,
   do not pass that object *by copy*! **Use references instead!**

Default Constructor
...................

.. literalinclude:: code/tests/rectangle-default-ctor.cpp
   :caption: :download:`code/tests/rectangle-default-ctor.cpp`
   :language: c++

Coordinates
...........

.. literalinclude:: code/tests/rectangle-coordinates.cpp
   :caption: :download:`code/tests/rectangle-coordinates.cpp`
   :language: c++

Width, Height, Area
...................

.. literalinclude:: code/tests/rectangle-area.cpp
   :caption: :download:`code/tests/rectangle-area.cpp`
   :language: c++

(In-)Equality
.............

In addition to make the test run, please 

* implement that one in the ``rectangle.cpp`` file
* do *not* pass the right hand side operand *by copy* (rationale: a
  rectangle is 16 bytes in size, so passing objects by reference is
  cheaper [#not-true-generally]_).

.. literalinclude:: code/tests/rectangle-operator-eq-ne.cpp
   :caption: :download:`code/tests/rectangle-operator-eq-ne.cpp`
   :language: c++

``+=``
......

Implement that one in the ``rectangle.cpp`` file, please.

.. literalinclude:: code/tests/rectangle-operator-plus-equal-vec.cpp
   :caption: :download:`code/tests/rectangle-operator-plus-equal-vec.cpp`
   :language: c++

``+``
.....

Implement that one in the ``rectangle.cpp`` file, please.

.. literalinclude:: code/tests/rectangle-plus-vec.cpp
   :caption: :download:`code/tests/rectangle-plus-vec.cpp`
   :language: c++

``<<`` (``std::ostream``)
.........................

Implement that one in the ``rectangle.cpp`` file, please.

.. literalinclude:: code/tests/rectangle-operator-ostream.cpp
   :caption: :download:`code/tests/rectangle-operator-ostream.cpp`
   :language: c++



.. rubric:: Footnotes

.. [#not-true-generally] The claim that passing 16-byte-size objects
                         by reference (and accessing them through that
                         reference later) is cheaper than simply
                         copying the objects is not entirey proven
                         though. Lets do it anyway for didactical
                         reasons!
