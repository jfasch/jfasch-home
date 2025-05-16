.. include:: <mmlalias.txt>


``SmartPtr`` With Move Semantics
================================

.. contents::
   :local:

Overview
--------

* Continue From ``SmartPtr`` With Explicit ``move()``
* Define "Return From Function Moves" requirement

Starting Point
--------------

.. literalinclude:: ../smart-pointers/code/handwritten-smart-ptr-explicit-move.cpp
   :caption: :download:`../smart-pointers/code/handwritten-smart-ptr-explicit-move.cpp`
   :language: c++

Return ``SmartPtr`` Object From Function
----------------------------------------

.. code-block:: c++

   SmartPtr<Sensor> create_constant_sensor(double temperature)
   {
       SmartPtr<Sensor> sp{new ConstantSensor{36.5}};
       return sp;
   }

* ``SmartPtr`` has copy ``delete`` d
* |longrightarrow| error
* But: compiler can prove that ``sp`` is unused after ``return``

|longrightarrow| Implement move constructor

.. literalinclude:: ../smart-pointers/code/handwritten-smart-ptr-return-from-function.cpp
   :caption: :download:`../smart-pointers/code/handwritten-smart-ptr-return-from-function.cpp`
   :language: c++

Assign ``SmartPtr`` Object |longrightarrow| Moved
-------------------------------------------------

.. code-block:: c++

   TEST(handwritten_suite, assignment)
   {
       SmartPtr<Sensor> a_sensor{new ConstantSensor{36.5}};
       SmartPtr<Sensor> another_sensor;
       another_sensor = a_sensor;
   }

* ``SmartPtr`` has assignment operator ``delete`` d
* |longrightarrow| error

**Attempt #1: implement move assignment**

Put correct ``SmartPtr`` implementation (see below), but fail to
``std::move()`` the assignee |longrightarrow| error

**Attempt #2: move**

.. literalinclude:: ../smart-pointers/code/handwritten-smart-ptr-assignment.cpp
   :caption: :download:`../smart-pointers/code/handwritten-smart-ptr-assignment.cpp`
   :language: c++
