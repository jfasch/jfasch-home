.. include:: <mmlalias.txt>


Local Variables In Control Flow Statements
==========================================

.. contents::
   :local:

``if`` Locals: Basis
--------------------

.. literalinclude:: code/local-ctlflow-if-simple.cpp
   :caption: :download:`code/local-ctlflow-if-simple.cpp`
   :language: c++

``if`` Locals: Use Case: ``std::map<>`` Lookup
----------------------------------------------

.. literalinclude:: code/local-ctlflow-if-map-found.cpp
   :caption: :download:`code/local-ctlflow-if-map-found.cpp`
   :language: c++

``if`` Locals: Use Case: Scoped Locking
---------------------------------------

.. literalinclude:: code/local-ctlflow-if-refcount-lock.cpp
   :caption: :download:`code/local-ctlflow-if-refcount-lock.cpp`
   :language: c++

``for`` Locals: Good Old Times
------------------------------

Traditional ``for`` loop has always had locals

.. literalinclude:: code/locals-ctlflow-for-goodold.cpp
   :caption: :download:`code/locals-ctlflow-for-goodold.cpp`
   :language: c++

Range ``for`` Locals: Only Logical |longrightarrow| New In C++20
----------------------------------------------------------------

.. literalinclude:: code/locals-ctlflow-rangefor.cpp
   :caption: :download:`code/locals-ctlflow-rangefor.cpp`
   :language: c++
