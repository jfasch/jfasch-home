.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.smart_pointers.introduction_livehack
   :dependencies: cxx11.smart_pointers.introduction

(Trying To) Handwrite A Smart Pointer Class in C++ Before C++11
===============================================================

.. contents::
   :local:

Overview
--------

* Step by step build a "managed pointer" class, ``SmartPtr<T>``

  * |longrightarrow| Takes *single* ownership

* Managed objects: sensor of various kinds

**Step 1**

* Take ownership
* Mimick a pointer (``->``, ``*``)

**Step 2**

* Compiler-generated copy *bad*
* Crash
* |longrightarrow| ``std::auto_ptr`` style

  * "steal" from original
  * *non-const* copy and assignment

Sensors To Manage
-----------------

This set of hacks builds upon some semi-real-life sensor
implementations, ``RandomSensor`` and ``ConstantSensor``:

.. literalinclude:: code/sensors.h
   :caption: :download:`code/sensors.h`
   :language: c++

Basic Resource Management, Operator Overloading
-----------------------------------------------

* Take ownership
* Implement ``->`` and ``*`` operators
* Implement ``const`` versions of ``->`` and ``*`` operators

.. literalinclude:: code/handwritten-smart-ptr-basic.cpp
   :caption: :download:`code/handwritten-smart-ptr-basic.cpp`
   :language: c++

Copy Constructor And Assignment Operator (And Default Ctor)
-----------------------------------------------------------

**Naive approach** 

* Let compiler do the copy
* |longrightarrow| generally a bad idea

.. literalinclude:: code/handwritten-smart-ptr-copy-bad.cpp
   :caption: :download:`code/handwritten-smart-ptr-copy-bad.cpp`
   :language: c++

Crashes ...

.. code-block:: console

   $ ./c++11-smartptr --gtest_filter=handwritten_suite.copy_ctor_bad
   Running main() from /home/jfasch/work/jfasch-home/googletest/googletest/src/gtest_main.cc
   Note: Google Test filter = handwritten_suite.copy_ctor
   [==========] Running 1 test from 1 test suite.
   [----------] Global test environment set-up.
   [----------] 1 test from handwritten_suite
   [ RUN      ] handwritten_suite.copy_ctor
   Segmentation fault (core dumped)

.. code-block:: console

   $ ./c++11-smartptr --gtest_filter=handwritten_suite.assignment_operator_bad
   Running main() from /home/jfasch/work/jfasch-home/googletest/googletest/src/gtest_main.cc
   Note: Google Test filter = handwritten_suite.assignment_operator_bad
   [==========] Running 1 test from 1 test suite.
   [----------] Global test environment set-up.
   [----------] 1 test from handwritten_suite
   [ RUN      ] handwritten_suite.assignment_operator_bad
   Segmentation fault (core dumped)

:doc:`valgrind
</trainings/material/soup/c/090-program-sanity/080-valgrind/topic>` to
the rescue ...

* Reveals that it's actually a double free

  * |longrightarrow| At the end of the test case, where both pointers
    are destructed

* But this is not so obvious because non-existent ``vtable`` is being
  traversed

.. code-block:: console

   $ valgrind ./c++11-smartptr --gtest_filter=handwritten_suite.copy_ctor
   ... tons of output (because of polymorphism) ...

``auto_ptr`` Style
------------------

* Copy constructor and assignment operator *invalidate* source pointer
* |longrightarrow| one has to know!

.. literalinclude:: code/handwritten-smart-ptr-copy-autoptr-style.cpp
   :caption: :download:`code/handwritten-smart-ptr-copy-autoptr-style.cpp`
   :language: c++

Explicit ``move()`` Method Maybe?
---------------------------------

* Still no constructor possible that does that
* Maybe add a ``move()`` method that is called on the destiation
  object
* |longrightarrow| improves readability
* |longrightarrow| does not help with correctness

.. literalinclude:: code/handwritten-smart-ptr-explicit-move.cpp
   :caption: :download:`code/handwritten-smart-ptr-explicit-move.cpp`
   :language: c++

Stop!!!
-------

* But lets stop here ...
* ... and see what :doc:`uniqueptr` (and C++11) can do

