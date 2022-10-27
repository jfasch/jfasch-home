.. ot-topic:: cxx_design_patterns.abstract_factory
   :dependencies: cxx_design_patterns.singleton,
		  cxx03.inheritance_oo.interface,
		  cxx_design_patterns.uml,
		  cxx_design_patterns.sensor_hierarchy

.. include:: <mmlalias.txt>


Abstract Factory
================

.. contents::
   :local:

Problem
-------

Object instantiation should not make core code depend on a concrete
implementation. Instead, core code should depend on abstractions.

*Abstract Factory* is such a *dependency inversion* mechanism.

Solution
--------

.. image:: exercises/abstract-factory-hierarchy.png
   :scale: 40%

Exercise
--------

:doc:`exercises/abstract-factory`

