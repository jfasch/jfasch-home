.. ot-exercise:: cxx_design_patterns.exercises.interpreter_and_adapter
   :dependencies: cxx_design_patterns.adapter,
		  cxx_design_patterns.interpreter,
		  cxx_design_patterns.sensor_hierarchy

.. include:: <mmlalias.txt>


Exercise: Interpreter Combined With Adapter (And A Proxy)
=========================================================

.. contents::
   :local:

Motivation
----------

In :doc:`interpreter` we created a clas hierarchy to do arithmetic
calculations, based on literals and variables - *values*, all in all.

The venerable ``Sensor`` :doc:`hierarchy <../sensor-hierarchy>` that
we used in :doc:`../adapter` and in :doc:`proxy-round`, for example,
contains a number of classes (to be extended by real-world sensors one
day), that also provide *values*.

Why not use a sensor as an ``Expression``?

.. image:: interpreter-sensor-adapter.png
   :scale: 50%

Requirement
-----------

In directory ``programs/``, add an executable that is built from the
following code:

.. literalinclude:: code/programs/dynamic-measurement-language.cpp
   :caption: :download:`code/programs/dynamic-measurement-language.cpp`
   :language: c++

