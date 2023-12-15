.. ot-topic:: cxx11.embedded_problems.classic_virtual
   :dependencies: cxx03.inheritance_oo.interface

.. include:: <mmlalias.txt>


Classic Virtual
===============

.. contents::
   :local:

Overview
--------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

* Classic polymorpism: common base class - *interface*
* *Virtual dispatch* per language support (this is what ``virtual`` is
  there for)
* **Type erasure**: not seeing derived types (a.k.a. *concrete types*)
  across the program - *only the interface*
* Easy to use: call base class pointer |longrightarrow| *dynamic dispatch*
* *Pro*: easy polymorphic use (e.g. store object of different derived
  type in an array of pointer-to-base-type)
* *Con*: code bloat, measured in binary size

Sensor Definitions
------------------

.. literalinclude:: code/classic-virtual/sensors.h
   :caption: :download:`code/classic-virtual/sensors.h`
   :language: c++

Virtual Access
--------------

This is easy - just call virtual method ...

.. literalinclude:: code/classic-virtual/virtual.h
   :caption: :download:`code/classic-virtual/virtual.h`
   :language: c++

Average Across Many
-------------------

.. literalinclude:: code/classic-virtual/avg.h
   :caption: :download:`code/classic-virtual/avg.h`
   :language: c++

Main Program
------------

.. literalinclude:: code/classic-virtual/main.cpp
   :caption: :download:`code/classic-virtual/main.cpp`
   :language: c++
