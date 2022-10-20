.. ot-exercise:: design_patterns.exercises.proxy_round
   :dependencies: design_patterns.proxy

Exercise: Proxy (Rounding Thermometer)
======================================

.. contents::
   :local:

Given the existing ``Sensor`` hierarchy, invent a new class
``RoundingSensor`` that takes the measurement from an existing sensor,
and returns that measurement rounded to the nearest integer.

Invent that new sensor in a way that it fullfills the following
requirements:

.. literalinclude:: code/proxy-round-suite.cpp
   :caption: :download:`code/proxy-round-suite.cpp`
   :language: c++

