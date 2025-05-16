.. include:: <mmlalias.txt>


C++: Advanced Topics (2023-12-04 - 2023-12-06)
==============================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda

.. sidebar::

   **Github Repository**

   * https://github.com/jfasch/2023-12-04

   **Original Agenda** 

   * :doc:`agenda`

Day 1: Introduction: C++, A New Language
----------------------------------------

* :doc:`/trainings/material/soup/cxx11/010-introduction/overview-livehacking`

Pythonicity
...........

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-for/range-based-for`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`

Brace Initialization
....................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/intro`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/implementor-view`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/mess`

New OO Features
...............

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`

Functions: ``std::function<>``, Lambdas
.......................................

From :doc:`/trainings/material/soup/cxx11/040-bind-function/index`:

* :doc:`/trainings/material/soup/cxx11/040-bind-function/010-bind/topic`
* :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/index`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor-pitfall`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`

Day 2: Simply Getting Stuff Done
--------------------------------

Classic Polymorphism: Interfaces
................................

:doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/index`

* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

Look over sensor hierachy in our project:

* `sensor.h
  <https://github.com/jfasch/2023-12-04/blob/main/toolcase/sensor.h>`__
* `sensor-w1.h
  <https://github.com/jfasch/2023-12-04/blob/main/toolcase/sensor-w1.h>`__
* `sensor-mock.h
  <https://github.com/jfasch/2023-12-04/blob/main/toolcase/sensor-mock.h>`__

Smart Pointers
..............

From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/index`

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

Move Semantics
..............

From :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/afterword`

Day 3: All The Rest
-------------------

Morning Wakeup
..............

Interfaces, And OO Design: ``Kochtopf`` And The Cloud
`````````````````````````````````````````````````````

* Show ``switch.h``: convenience methods in interface are possible :-)
* Show Kochtopf component

  Discuss design issues, e.g.

  * Relationship between controls and component (``this``, ``friend``)
  * ``PowerControl::start()`` vs. ``set_state()``
  * ``TemperatureControl::get_target_temperature()`` |longrightarrow|
    ``Hysteresis``

  Discuss threading

  * ``std::unique_ptr<>`` as member keeps component from being
    copyable
  * ``[this]``
  * ``_running`` |longrightarrow| ``std::atomic<>``
  * Shutdown?

* Show test fixture
* What about sensor temperature? Add
  ``KochtopfTemperatureControl::get_current_temperature()``
  (|longrightarrow| ``override``)

* *This would not be easy without TDD* |:point_up:|
* Discuss *technical debt*: ``Kochtopf`` has hardwired range of 2

Moving, Roundup
```````````````

* Discuss L/R-Values, and what compiler generates when (from
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`)
* Hack a ``String``

  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-string-move`

Containers And Algorithms
.........................

From :doc:`/trainings/material/soup/cxx03/060-stl/index`

* :doc:`/trainings/material/soup/cxx03/060-stl/010-basics/topic`
* :doc:`/trainings/material/soup/cxx03/060-stl/015-vector-copy-etc/topic`
* :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/index`
* :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/index`
* :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/index`

And Embedded?
.............

* :doc:`/trainings/material/soup/cxx11/drafts/embedded-problems/index`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/constexpr-constinit-consteval/constexpr`

Still Untold
------------

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/010-strongly-typed-enums/topic`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/050-delegating-ctor/topic`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/070-miscellaneous/topic`
* :doc:`/trainings/material/soup/c/080-advanced-language-features/030-alignment/topic`
