.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.smart_pointers.shared_ptr
   :dependencies: cxx11.smart_pointers.introduction,
		  cxx11.smart_pointers.unique_ptr


``std::shared_ptr``
===================

.. contents::
   :local:

``std::shared_ptr``: Not Unique
---------------------------------

.. sidebar::

   **Documentation**

   * `std::shared_ptr
     <https://en.cppreference.com/w/cpp/memory/shared_ptr>`__

**Ownership is not always clear ...**

* Rare occasions where shared ownership is the right design choice
* ... laziness, mostly
* If in doubt, say ``std::shared_ptr``

.. list-table::
   :align: left

   * * .. code-block:: c++

          #include <memory>
          std::shared_ptr<MyClass> ptr(
              new MyClass(666));

     * 

       .. image:: sharedptr.dia

``std::shared_ptr``: Copy
---------------------------

**Copying** is what shared pointer are there for

.. list-table:: 
   :align: left

   * * .. code-block:: c++

          shared_ptr<MyClass> ptr(
              new MyClass(666));
          shared_ptr<MyClass> copy1 = ptr;
          shared_ptr<MyClass> copy2 = copy1;

     * 

       .. image:: sharedptr-copy.dia

``std::shared_ptr`` vs. ``std::unique_ptr``
-----------------------------------------------

How do ``std::shared_ptr`` and ``std::unique_ptr`` compare?

* ``std::unique_ptr``

  * Small - size of a pointer
  * Operations compile away entirely
  * No excuse *not* to use it
  * Have to think more though

* ``std::shared_ptr``

  * Size of two pointers
  * Copying manipulates the resource count
  * Copying manipulates non-adjacent memory locations
  * Usage is very easy (no ``std::move`` and such)

  .. attention::

     * Cyclic references possible! 
     * No *garbage collection* as in Java
     * |longrightarrow| Leak!!

     See below ...

``std::shared_ptr``: Object Lifetime
------------------------------------

**How long does the pointed-to object live?**

* Reference count is used to track share ownership
* When reference count drops to zero, the object is *not referenced anymore*
* |longrightarrow| deleted

**Examining the reference count**

.. code-block:: c++

   shared_ptr<MyClass> ptr(new MyClass(666));
   auto refcount = ptr->use_count();

.. attention::

   Do not make any decisions based on it - at least not when the
   pointer is shared among multiple threads!

``std::shared_ptr``: Juggling
-------------------------------

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

Demo: Basic Usage
-----------------

.. literalinclude:: code/shared-ptr-basic.cpp
   :caption: :download:`code/shared-ptr-basic.cpp`
   :language: c++

Demo: ``std::make_shared``
--------------------------

.. literalinclude:: code/shared-ptr-basic-make_shared.cpp
   :caption: :download:`code/shared-ptr-basic-make_shared.cpp`
   :language: c++

Demo: Cyclic References
-----------------------

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
   
