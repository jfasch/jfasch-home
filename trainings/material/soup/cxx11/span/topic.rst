.. include:: <mmlalias.txt>


``std::span``
=============

.. contents::
   :local:

.. sidebar:: Documentation

   * `std::span
     <https://en.cppreference.com/w/cpp/container/span.html>`__

Basic Usage
-----------

.. literalinclude:: code/basic_usage.cpp
   :caption: :download:`code/basic_usage.cpp`
   :language: c++

Is A Range
----------	      

.. literalinclude:: code/is_a_range.cpp
   :caption: :download:`code/is_a_range.cpp`
   :language: c++

Compile Time vs. Runtime ``.size()``
------------------------------------
  
.. literalinclude:: code/compiletime.cpp
   :caption: :download:`code/compiletime.cpp`
   :language: c++
  
.. literalinclude:: code/runtime.cpp
   :caption: :download:`code/runtime.cpp`
   :language: c++

Static vs. Dynamic Extent |longrightarrow| ``constexpr`` All The Things
-----------------------------------------------------------------------
  
.. literalinclude:: code/static_extent.cpp
   :caption: :download:`code/static_extent.cpp`
   :language: c++
  
.. literalinclude:: code/dynamic_extent.cpp
   :caption: :download:`code/dynamic_extent.cpp`
   :language: c++
