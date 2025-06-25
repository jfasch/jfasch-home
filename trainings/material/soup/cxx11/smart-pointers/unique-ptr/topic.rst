.. include:: <mmlalias.txt>


``std::unique_ptr``
=====================

.. contents::
   :local:


The Spirit Of ``std::unique_ptr``
---------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/move/index`

.. sidebar:: Documentation

   * `std::unique_ptr
     <https://en.cppreference.com/w/cpp/memory/unique_ptr>`__
   * `std::make_unique
     <https://en.cppreference.com/w/cpp/memory/make_unique>`__

* *Unique* resource ownership: only one pointer object is responsible
  for deallocation of the referenced object
* No simple pointer *copy* allowed

  * |longrightarrow| would create second reference

* Explicit ownership transfer needed |longrightarrow| *Move-only*
* Implicit ownership transfer only when compiler can prove that no
  harm is done
* ``unique_ptr`` is only one (though important) user of a new language
  feature: :doc:`/trainings/material/soup/cxx11/move/index`

.. _cxx11_unique_ptr_create:

Creating ``std::unique_ptr`` Instances
--------------------------------------

.. sidebar:: Documentation
	     
   * `std::unique_ptr
     <https://en.cppreference.com/w/cpp/memory/unique_ptr.html>`__
   * `std::make_unique
     <https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique.html>`__

.. sidebar:: See also

   * :ref:`cxx11_shared_ptr_create`

* Raw pointer at the basis
* ``std::unique_ptr<>`` wrapped around
* |longrightarrow| controlled/deterministic deallocation

.. literalinclude:: code/basic_creation.cpp
   :caption: :download:`code/basic_creation.cpp`
   :language: c++

* More condensed usage: ``std::make_unique<T>()``
* Convenience function that

  * allocates ``T``, using ``new``
  * *forwards* its arguments to ``T``'s constructor

.. literalinclude:: code/more_condensed_creation.cpp
   :caption: :download:`code/more_condensed_creation.cpp`
   :language: c++

Inhibited: Copying ``std::unique_ptr`` Instances
------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/oo/delete`

* Uniqueness: no two pointers can point to the same object
* |longrightarrow| Copy constructor (and assignment operator) are
  *deleted*

.. literalinclude:: code/copy_inhibited.cpp
   :caption: :download:`code/copy_inhibited.cpp`
   :language: c++

* Compiler error: copy constructor is *deleted*
* (Same with copy assignment)

.. code-block:: console

   error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = BigData; _Dp = std::default_delete<BigData>]’
       8 |     auto copy = pdata;                                 // <-- copy initializer inhibited
         |                 ^~~~~

Inhibited: Pass By Copy
-----------------------

* Consequence: *pass-by-copy* is also inhibited

.. literalinclude:: code/pass_by_copy_inhibited.cpp
   :caption: :download:`code/pass_by_copy_inhibited.cpp`
   :language: c++

.. code-block:: console

   error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = BigData; _Dp = std::default_delete<BigData>]’
      13 |     foo(pdata);                                        // <-- copy initializer inhibited
         |     ~~~^~~~~~~


Passing Temporary Objects Are *Moved* Automatically
---------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/move/index`

* Compiler knows that a temprary object has no name
* |longrightarrow| Cannot be known to anyone but the compiler
* |longrightarrow| Compiler can do with it what he wants
* |longrightarrow| *Move* it into the function's parameter (see
  :doc:`here </trainings/material/soup/cxx11/move/index>`)

.. literalinclude:: code/temporary_object_moved.cpp
   :caption: :download:`code/temporary_object_moved.cpp`
   :language: c++

``std::move()``: Moving Objects Explicitly
------------------------------------------

* Developer might decide that they don't need a variable anymore
* |longrightarrow| Explicit move using ``std::move()``
* **Moved-from object is in invalid state afterwards**
* In case of ``std::unique_ptr``: ``nullptr``

.. literalinclude:: code/pass_by_copy_explicit_move.cpp
   :caption: :download:`code/pass_by_copy_explicit_move.cpp`
   :language: c++

Object Access: ``std::unique_ptr`` Behaves Like A Pointer
---------------------------------------------------------

* Has overloaded operators that make it behave like a pointer
* ``operator->()``
* ``operator*()``

.. literalinclude:: code/is_a_pointer.cpp
   :caption: :download:`code/is_a_pointer.cpp`
   :language: c++

.. _cxx11_unique_ptr_raw_access_get:

Raw Pointer Access: ``.get()``
------------------------------

.. sidebar:: See also

   * :ref:`cxx11_shared_ptr_raw_access_get`

* Not the plan
* Sometimes needed though
* |longrightarrow| Careful!

.. literalinclude:: code/raw_pointer_get.cpp
   :caption: :download:`code/raw_pointer_get.cpp`
   :language: c++

Re-Gaining Control: ``.release()``
----------------------------------

* Return pointed-to object to caller
* Modifies ``std::unique_ptr`` object to not point to anything
* Caller now responsible for object deallocation

.. literalinclude:: code/raw_pointer_release.cpp
   :caption: :download:`code/raw_pointer_release.cpp`
   :language: c++

.. _cxx11_unique_ptr_reset:

Deallocation *Before* Pointer Destruction: ``.reset()``
-------------------------------------------------------

.. sidebar:: See also

   * :ref:`cxx11_shared_ptr_reset`

* Nulling out pointer object
* With all consequences: pointed-to object deallocated
* Pointer object still alive but invalid

.. literalinclude:: code/reset.cpp
   :caption: :download:`code/reset.cpp`
   :language: c++

* Variant: exchanging pointer-to object with different (or even same)
  object

.. literalinclude:: code/reset_exchange.cpp
   :caption: :download:`code/reset_exchange.cpp`
   :language: c++

.. _cxx11_unique_ptr_custom_deleter:

Custom Deleter
--------------

.. sidebar:: See also

   * :ref:`cxx11_shared_ptr_custom_deleter`

* Additional template parameter ``Deleter``

  * Callable
  * Signature ``void(T*)``

* Additional constructor parameter of that type

.. literalinclude:: code/custom_deleter.cpp
   :caption: :download:`code/custom_deleter.cpp`
   :language: c++
