.. ot-exercise:: cxx.exercises.oo_switches.switch_mock
   :dependencies: cxx03.data_encapsulation.classes_objects,
		  linux.toolchain.cmake_local

.. include:: <mmlalias.txt>


Exercise: Mocking Switch
=========================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
   * :doc:`/trainings/material/soup/linux/toolchain/cmake/local`

Requirements
------------

Implement a switch class which does not access any real hardware, but
rather will be used for testing ("mocking").


/trainings/material/soup/cxx-code/switches-core/tests/switch-mock-suite.cpp

.. literalinclude:: /trainings/material/soup/cxx-code/switches-core/tests/switch-mock-suite.cpp
   :language: c++
   :caption: :download:`Download switch-mock-suite.cpp
             </trainings/material/soup/cxx-code/switches-core/tests/switch-mock-suite.cpp>`

Topics Covered
--------------

.. ot-graph::
   :entries: cxx.exercises.oo_switches.switch_mock
