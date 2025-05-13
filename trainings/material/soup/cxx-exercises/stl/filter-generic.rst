.. include:: <mmlalias.txt>


Exercise: Generic Filter
========================

.. contents::
   :local:

Base upon :doc:`filter-odd` and/or :doc:`filter-greater-10`, write a
filter that lets the user supply a function that decides whether an
alement is filtered of not.

**Hint:** the decision-function's prototype is ``bool
func(element)``. The parameter type of the ``filter()`` function for
that function is ``bool(*func)(int)``. (``func`` is the name of the
passed function as it is used inside the ``filter()`` body.)

.. literalinclude:: /trainings/material/soup/cxx-code/stl-exercises/tests/test-filter-generic.cpp
   :caption: :download:`/trainings/material/soup/cxx-code/stl-exercises/tests/test-filter-generic.cpp`
   :language: c++
