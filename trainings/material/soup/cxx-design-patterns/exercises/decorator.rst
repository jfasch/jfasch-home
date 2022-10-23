.. ot-exercise:: cxx_design_patterns.exercises.decorator
   :dependencies: cxx_design_patterns.exercises.adapter,
		  cxx_design_patterns.decorator,
		  cxx_design_patterns.uml

.. include:: <mmlalias.txt>


Exercise: Decorator
===================

.. contents::
   :local:

Motivation
----------

Based upon the situation described in :doc:`../decorator`, implement
*decorators* that add the following functionality to all classes in
our ``Sensor`` hierarchy:

* A ``name`` attribute

  * Intention: every sensor in a system should carry a name with it
  * *"We want it simple!"*

* A ``description`` attribute

  * Intention: every sensor should be able to describe what it does
    and what its configuration is
  * *"We want it debuggable!"*

Step 1: Realize Current Situation
---------------------------------

The original interface is used in current code. It is that current
code that must be left unmodified - ideally, current code must
continue to work *even without recompilation*.

A somewhat contrived (but representative) example of "current code" is
the ``average()`` function that computes an average value across a set
of sensors.

.. literalinclude:: code/tests/decorator-suite-starting-point.cpp
   :caption: :download:`code/tests/decorator-suite-starting-point.cpp`
   :language: c++

Step 2: Decorate ``ConstantSensor`` |longrightarrow| ``DecoratedConstantSensor``
--------------------------------------------------------------------------------

Create a wrapper that adds the required ``name`` and ``description``
attributes, in a way that makes the following test pass.

The intermediate ``class DecoratedSensor`` enables the proponents of
the added functionality to attach their own debugging/diagnostics code
to the system - **without any modification/pollution of existing
code**.

.. literalinclude:: code/tests/decorator-suite-const-sensor-added-functionality.cpp
   :caption: :download:`code/tests/decorator-suite-const-sensor-added-functionality.cpp`
   :language: c++

Step 3: Decorate ``RandomSensor`` |longrightarrow| ``DecoratedRandomSensor``
----------------------------------------------------------------------------

Same as step 2, only with ``RandomSensor``.

.. literalinclude:: code/tests/decorator-suite-random-sensor-added-functionality.cpp
   :caption: :download:`code/tests/decorator-suite-random-sensor-added-functionality.cpp`
   :language: c++

Step 4: Verify That ``DecoratedConstantSensor`` Can Be Used As ``Sensor``
-------------------------------------------------------------------------

The point in adding the ``DecoratedSensor`` sub-hierarchy to the
system is to extend existing functionality *without* any
*modification* thereof. In that sense, it must be possible to use a
decorator object *as-a* original object.

.. literalinclude:: code/tests/decorator-suite-const-sensor-is-a-sensor.cpp
   :caption: :download:`code/tests/decorator-suite-const-sensor-is-a-sensor.cpp`
   :language: c++

Step 5: Verify That ``DecoratedRandomSensor`` Can Be Used As ``Sensor``
-----------------------------------------------------------------------

Same as step 4, only with ``RandomSensor``.

.. literalinclude:: code/tests/decorator-suite-random-sensor-is-a-sensor.cpp
   :caption: :download:`code/tests/decorator-suite-random-sensor-is-a-sensor.cpp`
   :language: c++

Step 6: Verify That Current Situation Still Holds True
------------------------------------------------------

Proponents of the good old situation might want a proof that the
integrity of the system is still guaranteed, even though new
functionality has been added. Those proponents will sure want to see
the following test pass:

.. literalinclude:: code/tests/decorator-suite-decorated-used-in-legacy.cpp
   :caption: :download:`code/tests/decorator-suite-decorated-used-in-legacy.cpp`
   :language: c++
