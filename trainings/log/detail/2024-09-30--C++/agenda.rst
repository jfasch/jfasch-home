.. include:: <mmlalias.txt>


C++: A Wild Ride (2024-09-30 - 2024-10-04)
==========================================

.. contents::
   :local:

.. _livehacking-intro:

"New" vs. "Old" C++: An Overview
--------------------------------

C++ is a huge pile of language constructs built on top of each other,
always backwards compatible with its origins. In 2011, C++ got a major
overhaul which is still ongoing. It is not always easy for someone who
is new to C++ to understand why things are how they are.

:doc:`/trainings/material/soup/cxx11/010-introduction/overview-livehacking`
tries to draw the boundary between the old and new C++.

"New" C++: Syntactic Goodies (Pythonicity)
------------------------------------------

From
:doc:`/trainings/material/soup/cxx11/020-new-language-features/group`:

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`

  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/intro`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/implementor-view`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/mess`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/010-strongly-typed-enums/topic`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/050-delegating-ctor/topic`

Back To The Beginnings Of C++: What Everybody Has To Know
---------------------------------------------------------

From C To C++
.............

From
:doc:`/trainings/material/soup/cxx03/020-data-encapsulation/group`

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/c`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/initializer-list`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/copy-basics`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`

Classes And Methods (And Functions)
...................................

From
:doc:`/trainings/material/soup/cxx03/030-functions-and-methods/group`

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/010-overloading/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/040-this/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/060-static/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/065-static-member-variables/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`

Templates
.........

From :doc:`/trainings/material/soup/cxx03/050-templates/group`

* :doc:`/trainings/material/soup/cxx03/050-templates/010-function-templates/topic`
* :doc:`/trainings/material/soup/cxx03/050-templates/020-class-templates/topic`

Exercises
.........

* Sensor classes, independent types
* A (template) function to calculate the average of a number of sensor
  instances
* Sensor "configuration": a ``std::map`` (see :ref:`livehacking-intro`
  how this is done) of shape ``sensor-name -> sensor*``, encapsulated
  in a class

  |longrightarrow| :doc:`/trainings/material/soup/unittest/group`

Inheritance, And Interfaces
...........................

From
:doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`

* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/private-protected`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

Exercises
.........

* Refactoring

  * Sensor classes, being-an interface type
  * Funtion ``average()`` accepts different kinds of
    sensors
  * Sensor config, ditto

* Data logger, initial version.

  Everybody has understood how ``average()`` works (using the sensor
  *interface*). Write a program that take a sensor configuration, and
  repeatedly writes measured values to ``std::cout``.

Overengineering (Err, OO Design)
--------------------------------

Exercises
.........

What's bad about logging to ``std::cout``? (Answer: not easily
replaced with different logging targets.)

*Dependency Injection* and *Dependency Inversion* (and the Strategy
Pattern) are different words for one things: software structure.

Idea ...

* Define another interface: logging target (and make ``std::cout``
  logging its first concrete implementation)

  Discuss MQTT, or SQLite3, ...

* Define a data logger main loop class

More Design Patterns
....................

From :doc:`/trainings/material/soup/cxx-design-patterns/group`:

* :doc:`/trainings/material/soup/cxx-design-patterns/singleton/singleton`
* :doc:`/trainings/material/soup/cxx-design-patterns/adapter/adapter`
* :doc:`/trainings/material/soup/cxx-design-patterns/proxy/proxy`
* :doc:`/trainings/material/soup/cxx-design-patterns/composite/composite`
* Builder

More C++ >= 11
--------------

OO Features
...........

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`

Memory Management
.................

From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`:

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`, and :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

Exercise
........

Convert all interface usage to ``std::shared_ptr<>`` (``Sensor*``,
``LoggingTarget*``)

Move Semantics, And Perfect Forwarding
......................................

From
:doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/group`:

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/afterword`

Same syntax, different meaning ...

* :doc:`/trainings/material/soup/cxx11/035-perfect-forwarding/topic`

Exercise
........

Convert all interface usage to ``std::unique_ptr<>`` (``Sensor*``,
``LoggingTarget*``)

Functional: An Alternative To Full Polymorphism
...............................................

* :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`

Going Embedded
--------------

* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/group`
* :doc:`/trainings/material/soup/cxx11/drafts/crtp`

Optional Topics
---------------

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/055-constexpr/topic`
* :doc:`/trainings/material/soup/cxx03/060-stl/group`
* Excerpts from :doc:`/trainings/material/soup/cmake/intro/group` and
  :doc:`/trainings/material/soup/cmake/advanced/group`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/group`
* From :doc:`/trainings/material/soup/c/100-performance/group`

  * :doc:`/trainings/material/soup/c/100-performance/010-introduction/topic`
  * :doc:`/trainings/material/soup/c/100-performance/020-computebound/topic`
  * :doc:`/trainings/material/soup/c/100-performance/030-memory/topic`

* Warum sollen c-casts vermieden werden?
* Projektaufbau
* Verwendung von statischen Libraries? -> CMake
* Projekt review
