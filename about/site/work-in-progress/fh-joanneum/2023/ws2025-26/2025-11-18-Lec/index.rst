.. include:: <mmlalias.txt>


2025-11-18 (3 Lec): Project Talk, C++ Pointer Types
===================================================

Project "Presentations"
-----------------------

Lets talk about what has happened, and what will happen next.

* State machine
* Structural refactoring: ``libdoor`` has gotten too big
* Test rack
* ``AnalogSensor`` hierarchy

C++ Pointer Types
-----------------

From :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/index`:

* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/introduction/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/shared-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/unique-ptr/topic`
* :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/closing-words/topic`

Livehacking Script
``````````````````

* Start with this:

.. literalinclude:: ../livehacking/pointer-types-start.cpp
   :language: c++
   :caption: :download:`../livehacking/pointer-types-start.cpp`

* Commandline args "mock"/"random"
* Explain why dynamic allocation needed (object lifetime, debugging
  etc.)
* Missing ``delete`` |longrightarrow| ``valgrind``
* Return before delete, or exeption |longrightarrow| ``valgrind``
* Comment out for a moment, and show ``std::shared_ptr<Sensor>`` and
  derived types
  :doc:`/trainings/material/soup/cxx/cxx11/smart-pointers/shared-ptr/topic`
* Fix using ``std::shared_ptr<>``, *including* ``Averager`` ctor

And ``std::unique_ptr<>``?

* Comment out again
* Show ``std::unique_ptr<>`` like before, *including* move(-only)
  semantics
* Consequences of using ``std::unique_ptr<>``?
