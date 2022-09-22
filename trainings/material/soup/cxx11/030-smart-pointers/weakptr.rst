.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.smart_pointers.weak_ptr
   :dependencies: cxx11.smart_pointers.introduction,
		  cxx11.smart_pointers.shared_ptr


``std::weak_ptr``
=================

.. contents::
   :local:

Spirit: Borrowed Reference That Could Be Invalid
------------------------------------------------

* Tied to a :doc:`shared pointer <sharedptr>`
* Lightweight reference: shared pointer might become invalid (because
  all references are dropped)
* |longrightarrow| ask before use!

Methods
-------

.. sidebar:: 

   **Documentation**

   * `std::weak_ptr
     <https://en.cppreference.com/w/cpp/memory/weak_ptr>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Method
     * Description
   * * ``std::weak_ptr()``
     * Not tied to any shared pointer
   * * ``std::weak_ptr(const std::weak_ptr&)``
     * Copy constructor
   * * ``std::weak_ptr(std::weak_ptr&& from)``
     * Move constructor; ``from`` is not tied to any shared pointer
       afterwards (see
       :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move-pf/group`)
   * * ``std::weak_ptr(const std::shared_ptr& that)``
     * Tie constructed object to ``that``
   * * ``reset()``
     * Untie
   * * ``lock()``
     * Creates a ``std::shared_ptr`` that references the managed
       object

Basic Usage
-----------

.. literalinclude:: code/weak-ptr-basic.cpp
   :caption: :download:`code/weak-ptr-basic.cpp`
   :language: c++

A Real-Life Example
-------------------

.. literalinclude:: code/weak-ptr-demo-thread.cpp
   :caption: :download:`code/weak-ptr-demo-thread.cpp`
   :language: c++
