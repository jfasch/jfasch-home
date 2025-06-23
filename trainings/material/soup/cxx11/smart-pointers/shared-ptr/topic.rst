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

   * :doc:`/trainings/material/soup/cxx11/multithreading/atomic-shared-ptr/topic`
   * :doc:`/trainings/material/soup/cxx11/multithreading/memory-model/topic`

* **Reference count is thread-safe**
* |longrightarrow| Creating new references (i.e. copying pointer
  objects) is a little more expensive than a simple integer increment
* **Pointer object itself is not thread-safe**
* |longrightarrow| Concurrent writes lead to *undefined behavior*
* See
  :doc:`/trainings/material/soup/cxx11/multithreading/atomic-shared-ptr/topic`
  for a "workaround"

Creating ``std::shared_ptr`` Instances
--------------------------------------

.. sidebar:: See also

   * :doc:`../unique-ptr/topic`

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






jjj Methods
-----------

Object of type ``std::shared_ptr`` behave like pointers in any respect
(``->``, ``*``, copy, ...), except that they have methods:

.. sidebar:: 

   **Documentation**

   * `std::shared_ptr
     <https://en.cppreference.com/w/cpp/memory/shared_ptr>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Method
     * Description
   * * ``std::shared_ptr()``
     * Initializes to ``nullptr``
   * * ``std::shared_ptr(T* pointer)``
     * Initializes to ``pointer`` (but see :ref:`std::make_shared
       <make_shared>` instead); refcount is 1
   * * ``std::shared_ptr(std::shared_ptr&& from)``
     * Move constructor; ``from`` is empty afterwards (see
       :doc:`/trainings/material/soup/cxx11/move/index`)
   * * ``reset(T* pointer)``
     * Replaces the managed object if any, possibly deleting it if
       refcount reaches zero. ``pointer`` can be ``nullptr``
   * * ``get()``
     * Pointer to currently managed object


jjj ``std::shared_ptr``: Juggling
---------------------------------

.. list-table::
   :align: left

   * * **Clearing**: ``reset()``

       .. code-block:: c++

          shared_ptr<MyClass> ptr(
              new MyClass(666));
          auto copy = ptr;
          ptr.reset();

     * * Decrements reference count
       * Only if it becomes zero, object is deleted

   * * **Filling**: ``reset()``

       .. code-block:: c++

          shared_ptr<MyClass> ptr;
	  ptr.reset(new MyClass(666));

     * * Makes an empty pointer the initial reference

jjj Demo: Basic Usage
---------------------

.. literalinclude:: code/shared-ptr-basic.cpp
   :caption: :download:`code/shared-ptr-basic.cpp`
   :language: c++

.. _make_shared:

jjj Demo: ``std::make_shared``
------------------------------

.. literalinclude:: code/shared-ptr-basic-make_shared.cpp
   :caption: :download:`code/shared-ptr-basic-make_shared.cpp`
   :language: c++

jjj Demo: Cyclic References
---------------------------

.. literalinclude:: code/shared-ptr-cyclic.cpp
   :caption: :download:`code/shared-ptr-cyclic.cpp`
   :language: c++

.. code-block:: console

   $ valgrind ./c++11-smartptr --gtest_filter=shared_ptr_suite.cyclic_reference
   ==303549== Memcheck, a memory error detector
   ==303549== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
   ==303549== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
   ==303549== Command: ./c++11-smartptr --gtest_filter=shared_ptr_suite.cyclic_reference
   ==303549== 
   Running main() from /home/jfasch/work/jfasch-home/googletest/googletest/src/gtest_main.cc
   Note: Google Test filter = shared_ptr_suite.cyclic_reference
   [==========] Running 1 test from 1 test suite.
   [----------] Global test environment set-up.
   [----------] 1 test from shared_ptr_suite
   [ RUN      ] shared_ptr_suite.cyclic_reference
   [       OK ] shared_ptr_suite.cyclic_reference (8 ms)
   [----------] 1 test from shared_ptr_suite (13 ms total)
   
   [----------] Global test environment tear-down
   [==========] 1 test from 1 test suite ran. (38 ms total)
   [  PASSED  ] 1 test.
   ==303549== 
   ==303549== HEAP SUMMARY:
   ==303549==     in use at exit: 40 bytes in 2 blocks
   ==303549==   total heap usage: 515 allocs, 513 frees, 134,791 bytes allocated
   ==303549== 
   ==303549== LEAK SUMMARY:
   ==303549==    definitely lost: 16 bytes in 1 blocks
   ==303549==    indirectly lost: 24 bytes in 1 blocks
   ==303549==      possibly lost: 0 bytes in 0 blocks
   ==303549==    still reachable: 0 bytes in 0 blocks
   ==303549==         suppressed: 0 bytes in 0 blocks
   ==303549== Rerun with --leak-check=full to see details of leaked memory
   ==303549== 
   ==303549== For lists of detected and suppressed errors, rerun with: -s
   ==303549== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
   
