.. include:: <mmlalias.txt>


Screenplay: ``std::map`` Initialization And Inserting
=====================================================

.. contents::
   :local:

Definining The Type
-------------------

* Inline as you need it

  .. literalinclude:: code/map-instantiate-explicit.cpp
     :language: c++
     :caption: :download:`code/map-instantiate-explicit.cpp`

* Better, mostly, using ``using``

  .. literalinclude:: code/map-instantiate-using.cpp
     :language: c++
     :caption: :download:`code/map-instantiate-using.cpp`

* Ah, member types

  .. literalinclude:: code/map-instantiate-member-types.cpp
     :language: c++
     :caption: :download:`code/map-instantiate-member-types.cpp`

Initialization
--------------

* Pre C++11, there is only default ctor
* Elements are added *at runtime*, using ``push_back()``

  .. literalinclude:: code/map-initialize-pre11.cpp
     :language: c++
     :caption: :download:`code/map-initialize-pre11.cpp`

* C++11:
  :doc:`/trainings/material/soup/cxx11/brace-initialization/index`
* |longrightarrow| ``const`` non-default-constructed object

  .. literalinclude:: code/map-initialize-11.cpp
     :language: c++
     :caption: :download:`code/map-initialize-11.cpp`
