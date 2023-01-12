.. include:: <mmlalias.txt>


Screenplay: Removing (Erasing) Elements
=======================================

.. contents::
   :local:

By Pointer (Err, Iterator)
--------------------------

* Have to have an iterator pointing to to-be-removed element
* Usually by some find operation

.. literalinclude:: code/map-erase-iter.cpp
   :language: c++
   :caption: :download:`code/map-erase-iter.cpp`

By Key
------

.. literalinclude:: code/map-erase-key.cpp
   :language: c++
   :caption: :download:`code/map-erase-key.cpp`
