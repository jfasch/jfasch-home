.. include:: <mmlalias.txt>


Exercise (FH): ``class cuboid``
===============================

.. contents::
   :local:

Building ``class cuboid`` Upon ``class point3d``
------------------------------------------------

In the project you have set up in :doc:`class-point`, you'll find an a
test suite for a ``class cuboid``, together with an empty
``cuboid.{h,cpp}`` combo.

Continuing the tradition of *test driven development*, continually
extend ``class cuboid`` by adding the following tests one by one.

Default Constructor
...................

.. sidebar::

   **Topics**

   * :doc:`/trainings/material/soup/cxx/cxx03/020-data-encapsulation/ctor-default`

Use the C++11 ``= default`` and initialize the members at their
definition. (See :doc:`here
</trainings/material/soup/cxx/cxx03/020-data-encapsulation/ctor-default>`)

.. literalinclude:: code/tests/cuboid-default_ctor.cpp
   :caption: :download:`code/tests/cuboid-default_ctor.cpp`
   :language: c++

Custom Constructor
..................

.. literalinclude:: code/tests/cuboid-point_whl_ctor.cpp
   :caption: :download:`code/tests/cuboid-point_whl_ctor.cpp`
   :language: c++

(In-)Equality
.............

* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/cuboid-operator_eq_ne.cpp
   :caption: :download:`code/tests/cuboid-operator_eq_ne.cpp`
   :language: c++

``+=``
......

* Implement that one in the ``cuboid.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/cuboid-operator_pluseq.cpp
   :caption: :download:`code/tests/cuboid-operator_pluseq.cpp`
   :language: c++

``-=``
......

* Implement that one in the ``cuboid.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/cuboid-operator_minuseq.cpp
   :caption: :download:`code/tests/cuboid-operator_minuseq.cpp`
   :language: c++

``+``
.....

* Implement that one in the ``cuboid.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/cuboid-operator_plus.cpp
   :caption: :download:`code/tests/cuboid-operator_plus.cpp`
   :language: c++

``-``
.....

* Implement that one in the ``cuboid.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/cuboid-operator_minus.cpp
   :caption: :download:`code/tests/cuboid-operator_minus.cpp`
   :language: c++

``<<`` (``std::ostream``)
.........................

* Implement that one in the ``cuboid.cpp`` file, please.
* Do *not* pass the right hand side operand *by copy*
  [#not-true-generally]_.

.. literalinclude:: code/tests/cuboid-operator_ostream.cpp
   :caption: :download:`code/tests/cuboid-operator_ostream.cpp`
   :language: c++

Surface
.......

.. literalinclude:: code/tests/cuboid-surface.cpp
   :caption: :download:`code/tests/cuboid-surface.cpp`
   :language: c++

Volume
......

.. literalinclude:: code/tests/cuboid-volume.cpp
   :caption: :download:`code/tests/cuboid-volume.cpp`
   :language: c++



.. rubric:: Footnotes

.. [#not-true-generally] The claim that passing
                         larger-than-pointer-size objects by reference
                         (and accessing them through that reference
                         later) is cheaper than simply copying the
                         objects is not entirey proven though. Lets do
                         it anyway for didactical reasons!
