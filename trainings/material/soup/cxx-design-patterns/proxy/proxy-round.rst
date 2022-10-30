.. ot-exercise:: cxx_design_patterns.proxy_round
   :dependencies: cxx_design_patterns.proxy,
		  cxx_design_patterns.uml,
		  cxx_design_patterns.sensor_hierarchy


Exercise: Proxy (Rounding Thermometer)
======================================

.. contents::
   :local:

Given the existing ``Sensor`` hierarchy, invent a new class
``RoundingSensor`` that takes the measurement from an existing sensor,
and returns that measurement rounded to the nearest integer.

Invent that new sensor in a way that it fullfills the following
requirements:

.. literalinclude:: ../code/tests-trainee/proxy-round-suite.cpp
   :caption: :download:`../code/tests-trainee/proxy-round-suite.cpp`
   :language: c++
