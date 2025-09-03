.. include:: <mmlalias.txt>


Screenplay: Inserting Elements
==============================

.. contents::
   :local:

Subscript Operator
------------------

.. literalinclude:: code/map-insert-subscript.cpp
   :language: c++
   :caption: :download:`code/map-insert-subscript.cpp`

``insert()``
------------

* Takes a pair ``(key, value)``
* Returns a pair ``(iterator, bool)``
* Good old pre C++11 way of handling all that

  .. literalinclude:: code/map-insert-insert-pre11.cpp
     :language: c++
     :caption: :download:`code/map-insert-insert-pre11.cpp`

* Same, using :doc:`C++11 auto
  </trainings/material/soup/cxx/cxx11/auto/topic>`

  .. literalinclude:: code/map-insert-insert-auto.cpp
     :language: c++
     :caption: :download:`code/map-insert-insert-auto.cpp`

* Same, using :doc:`C++17 Structured Binding
  </trainings/material/soup/cxx/cxx11/structured-binding/topic>`

  .. literalinclude:: code/map-insert-insert-structured-binding.cpp
     :language: c++
     :caption: :download:`code/map-insert-insert-structured-binding.cpp`
