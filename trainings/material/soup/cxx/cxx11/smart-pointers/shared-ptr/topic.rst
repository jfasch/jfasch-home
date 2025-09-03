.. include:: <mmlalias.txt>


``std::shared_ptr``
===================

.. contents::
   :local:

The Spirit Of ``std::shared_ptr``
---------------------------------

.. sidebar::

   **Documentation**

   * `std::shared_ptr
     <https://en.cppreference.com/w/cpp/memory/shared_ptr>`__
   * `std::make_shared
     <https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared>`__

* *Shared* ownership: multiple pointer objects reference one object
  that is shared
* Pointer copy creates one more reference

  * |longrightarrow| Increases *reference count*

* Last remaining reference is responsible for deallocation

Notes About Thread Safety
-------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/atomic-shared-ptr/topic`
   * :doc:`/trainings/material/soup/cxx/cxx11/multithreading/memory-model/topic`

* **Reference count is thread-safe**
* |longrightarrow| Creating new references (i.e. copying pointer
  objects) is a little more expensive than a simple integer increment
* **Pointer object itself is not thread-safe**
* |longrightarrow| Concurrent writes lead to *undefined behavior*
* See
  :doc:`/trainings/material/soup/cxx/cxx11/multithreading/atomic-shared-ptr/topic`
  for a "workaround"

.. _cxx11_shared_ptr_create:

Creating ``std::shared_ptr`` Instances
--------------------------------------

.. sidebar:: See also

   * :ref:`cxx11_unique_ptr_create`

* Raw pointer at the basis
* ``std::shared_ptr<>`` wrapped around
* |longrightarrow| "Control block" created: *reference count*
* Reference count initialized to *one*

.. literalinclude:: code/basic_creation.cpp
   :caption: :download:`code/basic_creation.cpp`
   :language: c++

.. image:: sharedptr.dia
   :scale: 50%

* More condensed usage (just like ``std::unique_ptr<>``)
* Convenience function: allocates object of type T, and forward
  arguments to constructor

.. literalinclude:: code/more_condensed_creation.cpp
   :caption: :download:`code/more_condensed_creation.cpp`
   :language: c++

Copying ``std::shared_ptr`` Instances
-------------------------------------

* **Copying** is what shared pointers are there for
* Each pointer copy adds one reference to the object

.. literalinclude:: code/copy.cpp
   :caption: :download:`code/copy.cpp`
   :language: c++

.. image:: sharedptr-copy.dia
   :scale: 50%

Object Lifetime ("Garbage Collection")
--------------------------------------

**How long does the pointed-to object live?**

* Reference count is used to track shared ownership
* When reference count drops to zero, the object is *not referenced
  anymore*
* |longrightarrow| deallocated

**Examining the reference count**

* The zero-transition of the reference count *is the only event in the
  object lifecycle that can be counted on*
* **Everything else is dangerous when the object is shared across
  threads**

.. literalinclude:: code/refcount_if.cpp
   :caption: :download:`code/refcount_if.cpp`
   :language: c++

.. _cxx11_shared_ptr_raw_access_get:

Raw Pointer Access: ``.get()``
------------------------------

.. sidebar:: See also

   * :ref:`cxx11_unique_ptr_raw_access_get`

* Not the plan
* Sometimes needed though
* ⟶ Careful!

.. literalinclude:: code/raw_pointer_get.cpp
   :caption: :download:`code/raw_pointer_get.cpp`
   :language: c++

.. _cxx11_shared_ptr_reset:

Unreferencing Objects: ``.reset()``
-----------------------------------

.. sidebar:: See also

   * :ref:`cxx11_unique_ptr_reset`

* Nulling out pointer object
* Drop reference on object (decrease reference count)

.. literalinclude:: code/reset.cpp
   :caption: :download:`code/reset.cpp`
   :language: c++

* Variant: exchanging pointer-to object with different (or even same)
  object

.. literalinclude:: code/reset_exchange.cpp
   :caption: :download:`code/reset_exchange.cpp`
   :language: c++

.. _cxx11_shared_ptr_custom_deleter:

Custom Deleter
--------------

.. sidebar:: See also

   * :ref:`cxx11_unique_ptr_custom_deleter`

* Deleter *not* part of the type - as opposed to ``std::unique_ptr``
* |longrightarrow| would prevent sharing, obviously
* Delete stored in control block
* |longrightarrow| Each shared object can have its own deleter
* ``.get_deleter()``

.. literalinclude:: code/custom_deleter.cpp
   :caption: :download:`code/custom_deleter.cpp`
   :language: c++

Cyclic References
-----------------

.. sidebar:: See also

   * :doc:`../weak-ptr/topic`

* Cyclic references are *not* detected
* |longrightarrow| *Memory leak*

.. literalinclude:: code/cyclic.cpp
   :caption: :download:`code/cyclic.cpp`
   :language: c++

.. code-block:: console

   $ valgrind ./c++11-shared-ptr-cyclic 
   ...
   ==888857== HEAP SUMMARY:
   ==888857==     in use at exit: 40 bytes in 2 blocks
   ==888857==   total heap usage: 3 allocs, 1 frees, 73,768 bytes allocated
   ==888857== 
   ==888857== LEAK SUMMARY:
   ==888857==    definitely lost: 16 bytes in 1 blocks
   ==888857==    indirectly lost: 24 bytes in 1 blocks
   ==888857==      possibly lost: 0 bytes in 0 blocks
   ==888857==    still reachable: 0 bytes in 0 blocks
   ==888857==         suppressed: 0 bytes in 0 blocks
   ...
