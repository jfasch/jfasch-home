.. jf-screenplay:: c++-ownership-raii

Screenplay: C++: Ownership/RAII
===============================

.. sidebar:: Contents

   .. contents::
      :local:

   **Code**: :doc:`code/index`

**RAII**: "Resource Acquisition is Initialization"

Allocate in Constructor
-----------------------

.. literalinclude:: code/10-alloc.cc
   :caption: :download:`code/10-alloc.cc`
   :language: c++
      
**Discussion**

* Memory leak (``valgrind`` etc)
* *initializer list*? Morph it.

Deallocate in Destructor - *Ownership*
--------------------------------------

.. literalinclude:: code/20-own.cc
   :caption: :download:`code/20-own.cc`
   :language: c++

**Discussion**

* *deterministic*: at end of scope - ``return``
* Array delete

Ownership: 2 x non-``const``
----------------------------

.. literalinclude:: code/30-maybe-own--non-const-non-const.cc
   :caption: :download:`code/30-maybe-own--non-const-non-const.cc`
   :language: c++

**Discussion**

* ``mem()`` is non-const
* as if ``_mem`` was ``public``
* anyone can modify/delete

Ownership: ``const`` Method
---------------------------

Add ``const`` to method ...

.. literalinclude:: code/40-maybe-own--const-method.cc
   :caption: :download:`code/40-maybe-own--const-method.cc`
   :language: c++

**Discussion**

* explain ``const`` method: *promise to not modify object*
* *exposing* a member publicly does *not* modify object
* **Don't do this!**

Ownership: 2 x ``const``
------------------------

Add ``const`` to ``mem()`` return type, and let compiler take you by
the hand,

.. _cpp-pointer-const-const-delete:

* ``const`` variable
* ``strcpy()``: lhs parameter, see ``man strcpy``
* ``delete[] whose`` **still possible! Don't do it!**

.. literalinclude:: code/50-own--const-const.cc
   :caption: :download:`code/50-own--const-const.cc`
   :language: c++
