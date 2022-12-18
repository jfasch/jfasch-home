FH Lab Exam: OO Basics, Interfaces
==================================

.. contents::
   :local:

Setup, Exam Procedure
---------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx-exercises/project-setup`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

* :doc:`Setup project
  </trainings/material/soup/cxx-exercises/project-setup>`
* Build initial version :doc:`with CMake
  </trainings/material/soup/linux/toolchain/cmake/local>`
* See it fail initially

.. code-block:: console

   $ ./tests/cxx-exercises-shapes--suite 
   Running main() from googletest/googletest/src/gtest_main.cc
   [==========] Running 1 test from 1 test suite.
   [----------] Global test environment set-up.
   [----------] 1 test from initial_failure
   [ RUN      ] initial_failure.failit
   tests/initial-failure.cpp:5: Failure
   Failed
   [  FAILED  ] initial_failure.failit (0 ms)
   [----------] 1 test from initial_failure (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 1 test from 1 test suite ran. (0 ms total)
   [  PASSED  ] 0 tests.
   [  FAILED  ] 1 test, listed below:
   [  FAILED  ] initial_failure.failit
   
    1 FAILED TEST

* Remove the initial failure
* Implement the test cases that follow, one by one

Point
-----

Constructor and Getter Methods
..............................

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`
   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`
   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/030-const/topic`

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-ctor_and_getters.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-ctor_and_getters.cpp`
   :language: c++

Getters won't modify the objects (|longrightarrow| are usable on
``const Point`` objects)

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-ctor_and_getters_const.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-ctor_and_getters.cpp`
   :language: c++

Default Constructor
...................

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-default_ctor.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-default_ctor.cpp`
   :language: c++

Static Method: ``equal()``
..........................

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/060-static/topic`

A static method ``equal()`` compares two ``Point`` objects for
equality:

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-equal_method.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-equal_method.cpp`
   :language: c++

The method must be usable with ``const Point`` objects:

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-equal_method_const.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-equal_method.cpp`
   :language: c++

``operator==()``
................

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`

Overload the ``==`` operator to implement a more expressive way than
to call the ``equal()`` method:

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_equals.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_equals.cpp`
   :language: c++

The method must be usable with ``const Point`` objects:

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_equals_const.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_equals_const.cpp`
   :language: c++

Method: ``move()``
..................

``p.move(vector)`` modifies a ``Point`` object by ``vector``.

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-move_method.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-move_method.cpp`
   :language: c++

``operator+=()``
................

Overload the ``+=`` operator to implement a more expressive way than
to call the ``equal()`` method:

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_plus_equals.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_plus_equals.cpp`
   :language: c++

Static Method: ``add()``
........................

The static ``add()`` method creates a *new* ``Point`` object from its
two parameters:

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-add_method.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-add_method.cpp`
   :language: c++

The method must be usable with ``const Point`` objects (it does not
modify its parameters):

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-add_method_const.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-add_method.cpp`
   :language: c++

``operator+()``
...............

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_plus.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_plus.cpp`
   :language: c++

The operator must be usable with ``const Point`` objects (just like
``add()``, it does not modify its parameters):

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_plus_const.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/point_suite-operator_plus_const.cpp`
   :language: c++

Circle
------

A square is defined by:

* A ``Point``, the *center*
* Its *radius*

Constructor
...........

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/circle_suite-ctor_and_getters.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/circle_suite-ctor_and_getters.cpp`
   :language: c++

``operator==()``
................

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/circle_suite-ctor_and_getters_using_operator_equals.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/circle_suite-ctor_and_getters_using_operator_equals.cpp`
   :language: c++

Method: ``area()``
..................

.. sidebar::

   **The Value Of Pi**

   * C++20 comes with ``<numbers>``; you use ``std::numbers::pi``
   * If you cannot use C++20, you use ``3.14159`` literally

The ``area()`` method is used to calculate a ``Circle`` object's ... well ... area.

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/circle_suite-area.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/circle_suite-area.cpp`
   :language: c++

Computing the area of a shape does not modify the object:

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/circle_suite-area_const.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/circle_suite-area_const.cpp`
   :language: c++

Square
------

A square is defined by:

* A ``Point``, the *bottom left* corner
* Its *side length*

Constructor
...........

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/square_suite-ctor_and_getters.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/square_suite-ctor_and_getters.cpp`
   :language: c++

``operator==()``
................

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/square_suite-ctor_and_getters_using_operator_equals.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/square_suite-ctor_and_getters_using_operator_equals.cpp`
   :language: c++

Method: ``area()``
..................

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/square_suite-area.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/square_suite-area.cpp`
   :language: c++

Computing the area of a shape does not modify the object:

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/square_suite-area_const.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/square_suite-area_const.cpp`
   :language: c++

Interface: Shape
----------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`

Although ``Circle`` and ``Square`` are shapes - both have an
``area()`` method -, they cannot be used exchangeable. Lets change
that situation by defining an *interface*.

``Circle`` *Is-A* ``Shape``
...........................

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/shape_suite-circle_is_a_shape.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/shape_suite-circle_is_a_shape.cpp`
   :language: c++

``Square`` *Is-A* ``Shape``
...........................

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/shape_suite-square_is_a_shape.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/shape_suite-square_is_a_shape.cpp`
   :language: c++

Can Compute Area Of Any Shape
.............................

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/shape_suite-area_is_shape_functionality__circle.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/shape_suite-area_is_shape_functionality__circle.cpp`
   :language: c++

.. literalinclude:: /trainings/material/soup/cxx-code/oo-shapes/tests/shape_suite-area_is_shape_functionality__square.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/oo-shapes/tests/shape_suite-area_is_shape_functionality__square.cpp`
   :language: c++
