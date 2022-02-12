.. ot-topic:: cxx03.exercises_misc.reverse_string_solution
   :dependencies: cxx03.exercises_misc.reverse_string,
		  cxx03.stl.algorithm.reverse,
		  cxx03.stl.algorithm.reverse_copy


.. include:: <mmlalias.txt>


Solution: Reverse a String
==========================

.. contents::
   :local:

Naive
-----

.. literalinclude:: reverse-string-naive.cpp
   :caption: :download:`reverse-string-naive.cpp`
   :language: c++

Using ``std::reverse<>``
------------------------

.. sidebar::

   See
   :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/reverse`

.. literalinclude:: reverse-string-reverse.cpp
   :caption: :download:`reverse-string-reverse.cpp`
   :language: c++

Using ``std::reverse_copy<>``
-----------------------------

.. sidebar::

   See
   :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/reverse_copy`

.. literalinclude:: reverse-string-reverse-copy.cpp
   :caption: :download:`reverse-string-reverse-copy.cpp`
   :language: c++


.. ot-graph::
   :entries: cxx03.exercises_misc.reverse_string_solution
