.. include:: <mmlalias.txt>


Non-Virtual, But Related
========================

.. contents::
   :local:

Overview
--------

* Goal: eliminate ``virtual``
* Need dynamic dispatch though (want to store base types
  polymorphically)
* Base class
* ``static_cast<>``, based on a type field that is stored in base
  class
* *Manual* virtual dispatch (see
  :download:`code/unrelated/virtual.h`): ``switch`` based on type field.

Sensor Definitions
------------------

.. literalinclude:: code/related-no-virtual/sensors.h
   :caption: :download:`code/related-no-virtual/sensors.h`
   :language: c++

Virtual Access
--------------

.. literalinclude:: code/related-no-virtual/virtual.h
   :caption: :download:`code/related-no-virtual/virtual.h`
   :language: c++

Average Across Many
-------------------

.. literalinclude:: code/related-no-virtual/avg.h
   :caption: :download:`code/related-no-virtual/avg.h`
   :language: c++

Main Program
------------

.. literalinclude:: code/related-no-virtual/main.cpp
   :caption: :download:`code/related-no-virtual/main.cpp`
   :language: c++
