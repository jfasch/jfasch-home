.. ot-exercise:: cxx03.functions_and_methods.exercise_class_point3d
   :dependencies: cxx03.functions_and_methods.exercise_class_point

.. include:: <mmlalias.txt>


Exercise (FH): ``class point3d``
==================================

.. contents::
   :local:

Building ``class rectangle`` Upon ``class point``
-------------------------------------------------

In the project you have set up in :doc:`class-point`, you'll find an a
test suite for a ``class point3d``, together with an empty
``point3d.{h,cpp}`` combo.

Continuing the tradition of *test driven development*, continually
extend ``class point3d`` by adding the following tests one by one.

Default Constructor
...................

.. sidebar::

   **Topics**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`

Use the C++11 ``= default`` and initialize the members at their
definition. (See :doc:`here
</trainings/material/soup/cxx03/020-data-encapsulation/ctor-default>`)

.. literalinclude:: code/tests/point3d-default_ctor.cpp
   :caption: :download:`code/tests/point3d-default_ctor.cpp`
   :language: c++

Coordinates
...........

.. literalinclude:: code/tests/point3d-coordinates_ctor.cpp
   :caption: :download:`code/tests/point3d-coordinates_ctor.cpp`
   :language: c++

(In-)Equality
.............

* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/point3d-operator_eq_ne.cpp
   :caption: :download:`code/tests/point3d-operator_eq_ne.cpp`
   :language: c++

``+=``
......

* Implement that one in the ``point3d.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/point3d-operator_pluseq.cpp
   :caption: :download:`code/tests/point3d-operator_pluseq.cpp`
   :language: c++

``-=``
......

* Implement that one in the ``point3d.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/point3d-operator_minuseq.cpp
   :caption: :download:`code/tests/point3d-operator_minuseq.cpp`
   :language: c++

``+``
.....

* Implement that one in the ``point3d.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/point3d-operator_plus.cpp
   :caption: :download:`code/tests/point3d-operator_plus.cpp`
   :language: c++

``-``
.....

* Implement that one in the ``point3d.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/point3d-operator_minus.cpp
   :caption: :download:`code/tests/point3d-operator_minus.cpp`
   :language: c++

Unary ``-``
...........

.. literalinclude:: code/tests/point3d-operator_unary_minus.cpp
   :caption: :download:`code/tests/point3d-operator_unary_minus.cpp`
   :language: c++

``<<`` (``std::ostream``)
.........................

* Implement that one in the ``point3d.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/point3d-operator_ostream.cpp
   :caption: :download:`code/tests/point3d-operator_ostream.cpp`
   :language: c++

Absolute Value
..............

.. sidebar::

   **Documentation**

   * `sqrt() <https://en.cppreference.com/w/cpp/numeric/math/sqrt>`__

* Implement that one in the ``point3d.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.
* Use the ``std::sqrt()`` function from ``<cmath>`` to compute a
  square root.

.. literalinclude:: code/tests/point3d-abs.cpp
   :caption: :download:`code/tests/point3d-abs.cpp`
   :language: c++

Distance Between Two Points
...........................

.. literalinclude:: code/tests/point3d-distance.cpp
   :caption: :download:`code/tests/point3d-distance.cpp`
   :language: c++



.. rubric:: Footnotes

.. [#not-true-generally] The claim that passing
                         larger-than-pointer-size objects by reference
                         (and accessing them through that reference
                         later) is cheaper than simply copying the
                         objects is not entirey proven though. Lets do
                         it anyway for didactical reasons!
