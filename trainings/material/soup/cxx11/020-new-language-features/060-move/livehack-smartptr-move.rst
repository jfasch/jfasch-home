.. ot-topic:: cxx11.new_language_features.livehack_smartptr_move
   :dependencies: cxx11.new_language_features.move.overview,
		  cxx11.smart_pointers.introduction_livehack

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

.. literalinclude:: ../../030-smart-pointers/code/handwritten-smart-ptr-explicit-move.cpp
   :caption: :download:`../../030-smart-pointers/code/handwritten-smart-ptr-explicit-move.cpp`
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

.. literalinclude:: ../../030-smart-pointers/code/handwritten-smart-ptr-return-from-function.cpp
   :caption: :download:`../../030-smart-pointers/code/handwritten-smart-ptr-return-from-function.cpp`
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

.. literalinclude:: ../../030-smart-pointers/code/handwritten-smart-ptr-assignment.cpp
   :caption: :download:`../../030-smart-pointers/code/handwritten-smart-ptr-assignment.cpp`
   :language: c++
