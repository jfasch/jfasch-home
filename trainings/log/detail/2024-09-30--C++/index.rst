.. include:: <mmlalias.txt>


C++: A Wild Ride (2024-09-30 - 2024-10-04)
==========================================

.. contents::
   :local:

.. toctree::
   :hidden:

   agenda

.. sidebar::

   **Github Repository**

   * https://github.com/jfasch/2024-09-30

   **Original Agenda** 

   * :doc:`agenda`


Day 1
-----
     
"New" vs. "Old" C++: An Overview
................................

C++ is a huge pile of language constructs built on top of each other,
always backwards compatible with its origins. In 2011, C++ got a major
overhaul which is still ongoing. It is not always easy for someone who
is new to C++ to understand why things are how they are.

:doc:`/trainings/material/soup/cxx11/010-introduction/overview-livehacking`
tries to draw the boundary between the old and new C++.

(Omitting material from threading onwards)

Basic C++: Classes
..................

From
:doc:`/trainings/material/soup/cxx03/020-data-encapsulation/group`

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/c`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/010-overloading/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/040-this/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`

See `livehacking/point.cpp
<https://github.com/jfasch/2024-09-30/blob/main/livehacking/point.cpp>`__

Exercise
........

Implement a temperature sensor class which resembles an embedded thing
that uses memory-mapped registers

* Requirements: `tests/raw-mem-sensor.cpp
  <https://github.com/jfasch/2024-09-30/blob/main/tests/raw-mem-sensor.cpp>`__
* "Hardware" definition see `toolcase/base/plat.h
  <https://github.com/jfasch/2024-09-30/blob/main/toolcase/base/plat.h>`__
* Implementation to be done in `toolcase/base/raw-mem-sensor.h
  <https://github.com/jfasch/2024-09-30/blob/main/toolcase/base/raw-mem-sensor.h>`__

See `toolcase/base/raw-mem-sensor.h
<https://github.com/jfasch/2024-09-30/blob/main/toolcase/base/raw-mem-sensor.h>`__
and `toolcase/base/raw-mem-sensor.cpp
<https://github.com/jfasch/2024-09-30/blob/main/toolcase/base/raw-mem-sensor.cpp>`__

Day 2
-----

Morning Wakeup
..............

* Complete yesterday's exercise. Put implementation into separate
  ``.cpp`` file, and discuss. See `toolcase/base/raw-mem-sensor.h
  <https://github.com/jfasch/2024-09-30/blob/main/toolcase/base/raw-mem-sensor.h>`__
  and `toolcase/base/raw-mem-sensor.cpp
  <https://github.com/jfasch/2024-09-30/blob/main/toolcase/base/raw-mem-sensor.cpp>`__

* ``explicit``: which problem does *that* solve again? See
  `livehacking/explicit.cpp
  <https://github.com/jfasch/2024-09-30/blob/main/livehacking/explicit.cpp>`__

More About Classes
..................

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`

  * Show ``int i{};``
  * Show how default ctor uses that
  * Show how default ctor is not generated when explicit ctor is in place
  * :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`

  See

  * ``int`` "constructor": `livehacking/int-ctor.cpp>
    <https://github.com/jfasch/2024-09-30/blob/main/livehacking/int-ctor.cpp>`__
  * Usage in default constructor instantiation:
    `livehacking/point-default-init.cpp
    <https://github.com/jfasch/2024-09-30/blob/main/livehacking/point-default-init.cpp>`__

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`, 
  :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/initializer-list`

  * ``class point``: Show how code does not compile when members are
    ``const``
  * |longrightarrow|
    :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/initializer-list`

  See `livehacking/point-const-members.cpp
  <https://github.com/jfasch/2024-09-30/blob/main/livehacking/point-const-members.cpp>`__

Preparing for 2nd exercise (``class FileSensor``)
.................................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/unittest/group`
   * :doc:`/trainings/material/soup/cxx11/filesystem/topic`
   * :doc:`/trainings/material/soup/linux/hardware/w1/topic`

* Sketch a test for a sensor that reads from a file

  Much like Linux presents temperature sensors (see for example
  :doc:`/trainings/material/soup/linux/hardware/w1/topic`)

* :doc:`/trainings/material/soup/unittest/unittest_gtest_fixture/screenplay` 
  (from :doc:`/trainings/material/soup/unittest/group`)
* :doc:`/trainings/material/soup/cxx11/filesystem/topic`
* ``<fstream>`` short livehack

Exercise: ``class FileSensor``
..............................

Implement based on test which we agreed upon earlier.

Day 3
-----

Morning Wakeup
..............

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cmake/intro/libraries` (from
     :doc:`/trainings/repertoire/misc/cmake`)

* Recap: ``= default``, brace initialization, member initialization,
  "``vector`` anomaly"
* Show CMake dependencies (``.dot``
  files). :doc:`/trainings/material/soup/cmake/intro/libraries`

Inheritance, And Polymorphism
.............................

From :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`

* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/private-protected`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`
* :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

C++11: additional keywords

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`

Livehacked outcome in `livehacking/inheritance.cpp
<https://github.com/jfasch/2024-09-30/blob/main/livehacking/inheritance.cpp>`__

Exercise
........

* Like
  :doc:`/trainings/material/soup/cxx-exercises/sensor-interface/sensor-interface`,
  but with our sensors.
* Wild hacking jjj uml diagram of everything

Day 4
-----

Morning Wakeup
..............

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cmake/advanced/code-generators/screenplay` (from :doc:`/trainings/repertoire/misc/cmake`)


* ``#include`` coding guidelies: e.g. ``toolcase/base/CoutSink.h`` has
  ``#include <base/IDataSink.h>``

  * Discuss ``""`` vs. ``<>``
  * ``toolcase/base/CMakeLists.txt``:
    ``target_include_directories(... INTERFACE ...)``

* Project structure: split ``toolcase/base``

  * No-dependency, and basic interfaces in ``toolcase/base``
  * Separate nodes (``add_library()``) for CAN, CSV, ``SensorReader``

Code Generation With CMake
..........................

* Show how config (sensor, sink) can be brought in more statically, at
  link time |longrightarrow| manual prototype
* Generate code? |longrightarrow|
  :doc:`/trainings/material/soup/cmake/advanced/code-generators/screenplay`

Project Work (Tests err Requirements)
.....................................

* CSV error tests (file not found, appending to existing file
  vs. overwriting)

  |longrightarrow| ``std::expected``

* ``SensorReader`` tests? |longrightarrow|
  ``SensorReader::one()``. How about more loops, with abstracted time?
  Discuss!

Resource Management: Copy And Move
..................................

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/copy-basics`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`


* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/overview`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/livehack-using-string-move`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/afterword`

.. .. error handling bei get_temperature() -> std::expected(?)

.. .. cmake and dependencies   

.. .. copy/assign -> spaeter
