.. include:: <mmlalias.txt>


Composite
=========

.. contents::
   :local:

Examples
--------

Unix Filesystem
...............

A typical directory structure:

.. image:: 73-composite-unixfs.dia
   :scale: 40%

A hypthetical class diagram:

.. image:: 73-composite-unixfs-uml.png

Boolean Expressions
...................

.. image:: 73-composite-boolexpr-uml.png

Thermometers, And Average Calculation
.....................................

.. image:: 73-composite-thermometer-uml.png

Exercise
--------

Implement the following test:

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-composite/tests/composite-suite-basic.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-composite/tests/composite-suite-basic.cpp`
   :language: c++

Maybe, as a C++ 11 excursion, lets implement real *initialization*,
and omit the ``add()`` method. This way it becomes impossible to
``add()`` another member to the composite object at the time it is
already being used.

.. note::

   This step is optional!

.. literalinclude:: /trainings/material/soup/cxx-code/design-patterns-composite/tests/composite-suite-initializer-list.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/design-patterns-composite/tests/composite-suite-initializer-list.cpp`
   :language: c++
