.. ot-exercise:: design_patterns.exercises.composite
   :dependencies: design_patterns.exercises.proxy_round,
		  design_patterns.composite

Exercise: Composite
===================

.. contents::
   :local:

Based upon the problem described in :doc:`../composite`, implement the
following test:

.. literalinclude:: code/tests/composite-suite-basic.cpp
   :caption: :download:`code/tests/composite-suite-basic.cpp`
   :language: c++

Maybe, as a C++ 11 excursion, lets implement real *initialization*,
and omit the ``add()`` method. This way it becomes impossible to
``add()`` another member to the composite object at the time it is
already being used.

.. literalinclude:: code/tests/composite-suite-initializer-list.cpp
   :caption: :download:`code/tests/composite-suite-initializer-list.cpp`
   :language: c++
