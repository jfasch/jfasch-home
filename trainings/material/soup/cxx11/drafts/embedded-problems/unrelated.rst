.. ot-topic:: cxx11.embedded_problems.unrelated
   :dependencies: cxx11.embedded_problems.related_no_virtual

.. include:: <mmlalias.txt>


Unrelated (Duck-Typed)
======================

.. contents::
   :local:

Overview
--------

.. sidebar::

   * :doc:`/trainings/material/soup/python/advanced/oo/abc/topic`

* Alternative to common base class ...
* ... which is too much writing
* |longrightarrow| Good ol' C ``union``
* (Pointer-only though)
* *Manual* virtual dispatch (see
  :download:`code/unrelated/virtual.h`): ``switch`` based on type field.

Sensor Definitions
------------------

.. literalinclude:: code/unrelated/sensors.h
   :caption: :download:`code/unrelated/sensors.h`
   :language: c++

Virtual Access
--------------

.. literalinclude:: code/unrelated/virtual.h
   :caption: :download:`code/unrelated/virtual.h`
   :language: c++

Average Across Many
-------------------

.. literalinclude:: code/unrelated/avg.h
   :caption: :download:`code/unrelated/avg.h`
   :language: c++

Main Program
------------

.. literalinclude:: code/unrelated/main.cpp
   :caption: :download:`code/unrelated/main.cpp`
   :language: c++
