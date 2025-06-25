.. include:: <mmlalias.txt>


``std::weak_ptr``
=================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`../shared-ptr/topic`

.. sidebar:: Documentation

   * `std::weak_ptr
     <https://en.cppreference.com/w/cpp/memory/weak_ptr.html>`__

Spirit: Borrowed Reference That Could Be Invalid
------------------------------------------------

* Tied to a :doc:`shared pointer <../shared-ptr/topic>`
* Lightweight reference: shared pointer might become invalid (because
  all references are dropped)
* |longrightarrow| ask before use!

Basic Usage
-----------

* Thread safe

.. literalinclude:: code/basic.cpp
   :caption: :download:`code/basic.cpp`
   :language: c++

A Real-Life Example
-------------------

.. literalinclude:: code/demo-thread.cpp
   :caption: :download:`code/demo-thread.cpp`
   :language: c++
