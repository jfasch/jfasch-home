.. ot-exercise:: cxx.exercises.oo_switches.switch_mock_nopoly
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

.. literalinclude:: /trainings/material/soup/cxx-code/switches-core-nopoly/tests/switch-mock-nopoly-basic.cpp
   :language: c++
   :caption: :download:`Download switch-mock-nopoly-basic.cpp
	     </trainings/material/soup/cxx-code/switches-core-nopoly/tests/switch-mock-nopoly-basic.cpp>`

Topics Covered
--------------

.. ot-graph::
   :entries: cxx.exercises.oo_switches.switch_mock_nopoly
