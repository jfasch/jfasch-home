.. include:: <mmlalias.txt>


Exercise: Mocking Switch (Non-Polymorphic)
==========================================

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

.. literalinclude:: /trainings/material/soup/cxx-exercises/nopoly-switch-mock/code/tests/switch-mock-nopoly-basic.cpp
   :language: c++
   :caption: :download:`Download switch-mock-nopoly-basic.cpp
	     </trainings/material/soup/cxx-exercises/nopoly-switch-mock/code/tests/switch-mock-nopoly-basic.cpp>`
