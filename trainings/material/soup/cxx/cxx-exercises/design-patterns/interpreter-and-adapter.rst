.. include:: <mmlalias.txt>


Exercise: Interpreter Combined With Adapter (And A Proxy)
=========================================================

.. contents::
   :local:

Motivation
----------

In :doc:`/trainings/material/soup/cxx/cxx-design-patterns/interpreter/index` we created a clas hierarchy to do arithmetic
calculations, based on literals and variables - *values*, all in all.

The venerable ``Sensor`` :doc:`hierarchy </trainings/material/soup/cxx/cxx-design-patterns/sensor-hierarchy>` that
we used in :doc:`/trainings/material/soup/cxx/cxx-exercises/design-patterns/adapter` and in :doc:`/trainings/material/soup/cxx/cxx-exercises/design-patterns/proxy-round`, for example,
contains a number of classes (to be extended by real-world sensors one
day), that also provide *values*.

Why not use a sensor as an ``Expression``?

.. image:: interpreter-sensor-adapter.png
   :scale: 50%

Requirement
-----------

In directory ``programs/``, add an executable that is built from the
following code:

.. literalinclude:: /trainings/material/soup/cxx/cxx-code/design-patterns-interpreter/programs/dynamic-measurement-language.cpp
   :caption: :download:`/trainings/material/soup/cxx/cxx-code/design-patterns-interpreter/programs/dynamic-measurement-language.cpp`
   :language: c++

