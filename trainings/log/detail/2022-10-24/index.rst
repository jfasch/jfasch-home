.. include:: <mmlalias.txt>


Design- and Architectural Patterns With C++ (2022-10-24 - 2022-10-26)
=====================================================================

.. contents::
   :local:

.. sidebar::

   * Original Course Description:
     :doc:`/trainings/repertoire/design-patterns`
   * :doc:`/trainings/material/soup/cxx-design-patterns/group`
   * :download:`Design Patterns (PDF)
     </trainings/material/pdf/060-design-patterns-unittests.pdf>`
   * `Github Repository <https://github.com/jfasch/2022-10-24>`__


Log
---

Monday
......

* :doc:`C++ Interfaces </trainings/material/soup/cxx03/100-inheritance-oo-design/group>`
* :doc:`/trainings/material/soup/cxx-design-patterns/uml`
* :doc:`/trainings/material/soup/cxx-design-patterns/singleton`

  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/singleton-inflexible`
  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/singleton-flexible`
  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/singleton-flexible-strict`

* :doc:`/trainings/material/soup/cxx-design-patterns/adapter`

  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/adapter`

* :doc:`/trainings/material/soup/cxx-design-patterns/proxy`

  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/proxy-round`
  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/proxy-remote`
    (That with the ``ServerThread`` |:thinking:|)

Tuesday
.......

* :doc:`/trainings/material/soup/cxx-design-patterns/composite`

  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/composite`

* :doc:`/trainings/material/soup/cxx-design-patterns/command`

  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/command`

* :doc:`/trainings/material/soup/cxx-design-patterns/interpreter`

  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/interpreter`
  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/interpreter-and-adapter`

Wednesday
.........

* :doc:`/trainings/material/soup/cxx-design-patterns/abstract-factory`
* Builder maybe (sensors and switches?)
* Visitor is a must have
* 
* Maybe: see how large ``if-elif-else`` (creational) chains can be
  decomposed into ... plugins? Plugging modules dynamically? Into
  existing software? ``dlopen()``, ``dlsym()``?
* Unit Testing and Test Driven Development?
* C++11 if there's time?

  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`
  * :doc:`/trainings/material/soup/cxx11/050-multithreading/group`
  * New syntactical constructs like *structured binding*, *range based
    for*, ``auto``

Agenda
------

OO Basics
.........

* Interfaces, Inheritance
* UML short introduction: *is-a*, *has-a* (aggregation, composition),
  *knows-a* (association)

SOLID - OO Principles, Metrics
..............................

* Single Responsibility
* Open/Closed
* Liskov Substitution
* Interface Segregation
* Dependency Inversion
* Metric: Cyclomatic Complexity

Creational Patterns
...................

* Singleton
* Abstract Factory
* Builder

Test Driven Development Short Introduction
..........................................

* Test Cases and Test Suites
* Test Runners

Structural Patterns
...................

* Adapter
* Bridge
* Composite
* Proxy

Behavioral Patterns
...................

* Command
* Interpreter
* Observer
* Visitor
