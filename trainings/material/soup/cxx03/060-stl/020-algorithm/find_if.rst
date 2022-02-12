.. ot-topic:: cxx03.stl.algorithm.find_if
   :dependencies: cxx03.stl.algorithm.find

.. include:: <mmlalias.txt>


.. sidebar:: Documentation

   * `std::find_if
     <https://en.cppreference.com/w/cpp/algorithm/find>`__ @
     `cppreference.com <https://cppreference.com>`__
   * `std::find_if
     <http://www.cplusplus.com/reference/algorithm/find_if/>`__ @
     `cplusplus.com <https://cplusplus.com>`__

``find_if<>``: Sequential Search, Customizable
==============================================

.. contents::
   :local:

Live Hacking
------------

``if``, Using a Plain Function
..............................

.. literalinclude:: code/find_if.cpp
   :caption: :download:`code/find_if.cpp`
   :language: c++

``if``, Using a Functor Class
.............................

*And C++11 lambdas?*

.. literalinclude:: code/find_if-functor.cpp
   :caption: :download:`code/find_if-functor.cpp`
   :language: c++
