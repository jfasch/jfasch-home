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
* :doc:`/trainings/material/soup/cxx-design-patterns/singleton/singleton`

  * :doc:`/trainings/material/soup/cxx-design-patterns/singleton/singleton-inflexible`
  * :doc:`/trainings/material/soup/cxx-design-patterns/singleton/singleton-flexible`
  * :doc:`/trainings/material/soup/cxx-design-patterns/singleton/singleton-flexible-strict`

* :doc:`/trainings/material/soup/cxx-design-patterns/adapter/adapter`
* :doc:`/trainings/material/soup/cxx-design-patterns/proxy/proxy`

  * :doc:`/trainings/material/soup/cxx-design-patterns/proxy/proxy-round`
  * :doc:`/trainings/material/soup/cxx-design-patterns/proxy/proxy-remote`
    (That with the ``ServerThread`` |:thinking:|)

Tuesday
.......

* :doc:`/trainings/material/soup/cxx-design-patterns/composite/composite`
* :doc:`/trainings/material/soup/cxx-design-patterns/command/command`
* :doc:`/trainings/material/soup/cxx-design-patterns/interpreter`

  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/interpreter`

Wednesday
.........

* Continuing with :doc:`/trainings/material/soup/cxx-design-patterns/interpreter` ...

  * :doc:`/trainings/material/soup/cxx-design-patterns/exercises/interpreter-and-adapter`

* :doc:`/trainings/material/soup/cxx-design-patterns/observer`
* :doc:`/trainings/material/soup/cxx-design-patterns/abstract-factory`
* Builder maybe (sensors and switches?)
* Maybe: see how large ``if-elif-else`` (creational) chains can be
  decomposed into ... plugins? Plugging modules dynamically? Into
  existing software? ``dlopen()``, ``dlsym()``?
* Unit Testing and Test Driven Development?
* C++11 if there's time?

  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`
  * :doc:`/trainings/material/soup/cxx11/050-multithreading/group`
  * New syntactical constructs like *structured binding*, *range based
    for*, ``auto``
