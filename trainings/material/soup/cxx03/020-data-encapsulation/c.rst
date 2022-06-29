.. ot-topic:: cxx03.data_encapsulation.c
   :dependencies: cxx03.introduction

.. include:: <mmlalias.txt>


Object Oriented Programming In Good Ol' C
=========================================

.. contents::
   :local:

C Is Simple, So Why C++?
------------------------

* ``struct`` to aggregate related things into a new type

  * *Copy* supported by compiler

* Functions to add functionality
* Pointers to pass things *by reference* (e.g. for *modifying*
  functionality)
* C struct initialization

  * If used |longrightarrow| good
  * If unused |longrightarrow| uninitialized

``struct point``: Something That Looks Like A Point
---------------------------------------------------

* Initialization can be done
* *But need not!*

.. literalinclude:: code/c-struct-initialization.cpp
   :caption: :download:`code/c-struct-initialization.cpp`
   :language: c++

Good Style: Explicit Initialization Functions
---------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`

* C++ *constructor* initializes an object
* Object referred to as ``this`` (part of C++ syntax)
* In C, everything is explicit
* |longrightarrow| pointer to object (usually given as first
  parameter)

**Default Constructor**

.. literalinclude:: code/c-default-constructor-init.cpp
   :caption: :download:`code/c-default-constructor-init.cpp`
   :language: c++

Alternative ...

* Something that does not let things uninitialized
* Expensive though if objects are larger (return *by copy*)

.. literalinclude:: code/c-default-constructor-create.cpp
   :caption: :download:`code/c-default-constructor-create.cpp`
   :language: c++

**Constructor**: initialize a ``struct point`` with its coordinates

.. literalinclude:: code/c-constructor.cpp
   :caption: :download:`code/c-constructor.cpp`
   :language: c++

Comparison Functions: (In)Equality
----------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`

* Compare two points
* Parameters (``lhs`` and ``rhs``) passed *by copy* (a ``struct
  point`` is 8 bytes in size which is the size of a pointer)
* A rather clumsy way to express ``==`` and ``!=``

.. literalinclude:: code/c-eq-ne.cpp
   :caption: :download:`code/c-eq-ne.cpp`
   :language: c++

Moving Points
-------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`

* *Move* operation modifies object
* |longrightarrow| passed as (non-const) *pointer*
* A rather clumsy way to express ``+=``

.. literalinclude:: code/c-move.cpp
   :caption: :download:`code/c-move.cpp`
   :language: c++

Vector Addition and Subtraction
-------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`

* Creates a new point out of two points which are left unmodified
* Pass by copy (again because size of ``struct point`` is rather
  small)
* Return by copy

.. literalinclude:: code/c-add-sub.cpp
   :caption: :download:`code/c-add-sub.cpp`
   :language: c++

Distance Of Two Points
----------------------

* Points passed *by copy*

.. literalinclude:: code/c-distance.cpp
   :caption: :download:`code/c-distance.cpp`
   :language: c++

Length Of A Point's Position Vector
-----------------------------------

* Computation does not modify the object
* |longrightarrow| pass by ``const`` pointer

.. literalinclude:: code/c-abs.cpp
   :caption: :download:`code/c-abs.cpp`
   :language: c++


Summary: Is C Good Enough?
--------------------------

* Members are public

  .. code-block:: c

     struct point p = {42, 7};
     ...
     p.x = 666;   // unwanted at times

  * |longrightarrow| Bugs are only a matter of time
  * Counter argument: "Real programmers don't write bugs"

* Function just hang around

  * ``point_add()`` is the *addition operator* which *belongs to*
    ``struct point``
  * Just nobody knows

* Inconsistent parameter passing schema: how is *the object* passed?

  .. code-block:: c

     double point_abs(const point* self);
     point point_sub(point lhs, point rhs);

* Clean/consistent initialization wanted

  * *Constructor* (and *destructor*)
  * Error checking

* Overloaded operators - e.g. addition of two ``struct point`` objects
  using the addition operator ``+``
* *Methods* on *Objects*, like moving a point: ``p.abs();``
