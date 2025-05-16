.. include:: <mmlalias.txt>


``std::unique_ptr``
=====================

.. contents::
   :local:


The Spirit Of ``std::unique_ptr``
---------------------------------

.. sidebar:: 

   **Documentation**

   * `std::unique_ptr
     <https://en.cppreference.com/w/cpp/memory/unique_ptr>`__
   * `std::make_unique
     <https://en.cppreference.com/w/cpp/memory/make_unique>`__

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`

* *Unique* resource ownership: only one pointer object is responsible
  for deleting the referenced object
* No simple pointer *copy* allowed
* |longrightarrow| would create second reference
* Explicit ownership transfer needed
* Only implicit when compiler can prove that no harm is done
* ``unique_ptr`` is only one (though important) user of a new language
  feature:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`

Methods
-------

Object of type ``std::unique_ptr`` behave like pointers in any respect
(``->``, ``*``, copy, ...), except that they have methods:

.. sidebar:: 

   **Documentation**

   * `std::unique_ptr
     <https://en.cppreference.com/w/cpp/memory/unique_ptr>`__

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Method
     * Description
   * * ``std::unique_ptr()``
     * Initializes to ``nullptr``
   * * ``std::unique_ptr(T* pointer)``
     * Initializes to ``pointer`` (but see :ref:`std::make_unique
       <make_unique>` instead)
   * * ``std::unique_ptr(std::unique_ptr&& from)``
     * Move constructor; ``from`` is empty afterwards (see
       :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`)
   * * ``release()``
     * Returns pointer to managed object, *and releases ownership*
   * * ``reset(T* pointer)``
     * Takes ownership of ``pointer`` (can be ``nullptr``), and
       deletes currently owned pointer (if any)
   * * ``get()``
     * Pointer to currently owned object

Basic Usage: Prevent Leaks
--------------------------

.. literalinclude:: code/unique-ptr-basic.cpp
   :caption: :download:`code/unique-ptr-basic.cpp`
   :language: c++

* All looks well: pointers safely wrapped in ``std::unique_ptr<>``
* |longrightarrow| most basic intention
* It's just that little chance that something might throw between
  allocation and wrap

Eliminate Chance Of Leakage |longrightarrow| *Ownership*
--------------------------------------------------------

Straightforward try to prevent leaks:

.. literalinclude:: code/unique-ptr-ownership-error.cpp
   :caption: :download:`code/unique-ptr-ownership-error.cpp`
   :language: c++

* Apparently cannot simply assign one unique pointer onto another
* Remember: *one single owner*
* |longrightarrow| assignment would create a second
* |longrightarrow| compiler helps us!

.. code-block:: console

   /home/jfasch/work/jfasch-home/trainings/material/soup/cxx11/030-smart-pointers/code/unique-ptr-ownership-error.cpp: In member function ‘virtual void unique_ptr_suite_ownership_error_Test::TestBody()’:
   /home/jfasch/work/jfasch-home/trainings/material/soup/cxx11/030-smart-pointers/code/unique-ptr-ownership-error.cpp:17:24: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Sensor; _Dp = std::default_delete<Sensor>]’
      17 |     sensors["rand1"] = rs1;
         |                        ^~~
   In file included from /usr/include/c++/11/memory:76,
                    from /home/jfasch/work/jfasch-home/googletest/googletest/include/gtest/gtest.h:54,
                    from /home/jfasch/work/jfasch-home/trainings/material/soup/cxx11/030-smart-pointers/code/unique-ptr-ownership-error.cpp:3:
   /usr/include/c++/11/bits/unique_ptr.h:469:19: note: declared here
     469 |       unique_ptr& operator=(const unique_ptr&) = delete;
         |                   ^~~~~~~~

* |longrightarrow| Copy not possible!
* Who would be responsible to destroy the object?
* **Ownership violation**

Saving Keystrokes: ``std::make_unique<>()``
-------------------------------------------

.. sidebar:: 

   **Documentation**

   * `std::make_unique
     <https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique>`__
     (since C++14)

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`

* Too much typing here:

  .. literalinclude:: code/unique-ptr-verbose-ctor.cpp
     :caption: :download:`code/unique-ptr-verbose-ctor.cpp`
     :language: c++

* ``std::make_unique`` to the rescue:

  .. literalinclude:: code/unique-ptr-make-unique.cpp
     :caption: :download:`code/unique-ptr-make-unique.cpp`
     :language: c++

Explicitly Acknowledging Ownership Transfer: ``std::move()``
------------------------------------------------------------

.. sidebar::

   **Documentation**

   * `std::move <https://en.cppreference.com/w/cpp/utility/move>`__

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`

* What is needed is a way of *explicit ownership tranfer*
* |longrightarrow| Acknowledging terms and conditions
* |longrightarrow| Moved-from pointer object becomes invalid
* This is not specific to ``unique_ptr`` |longrightarrow|
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`

.. literalinclude:: code/unique-ptr-ownership-move.cpp
   :caption: :download:`code/unique-ptr-ownership-move.cpp`
   :language: c++

.. _make_unique:

Compiler Can Prove: Implicit Ownership Transfer
-----------------------------------------------

.. sidebar:: 

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`

* Function returns an object *by copy*
* |longrightarrow| compiler knows that that object will never be used
  anymore
* To the caller this object appears as *R-Value* (something that
  cannot be assigned to)
* Enter :doc:`"R-Value References"
  </trainings/material/soup/cxx11/020-new-language-features/060-move/index>`
* ``unique_ptr`` has a constructor that can accept an R-Value
  reference
* |longrightarrow| ``&&``
* "Move-Constructor"

  .. code-block:: c++

     unique_ptr(unique_ptr&& u) noexcept;

.. literalinclude:: code/unique-ptr-implicit-ownership-transfer.cpp
   :caption: :download:`code/unique-ptr-implicit-ownership-transfer.cpp`
   :language: c++

So ``unique_ptr``'s move constructor is responsible for handling
ownership transfer.

How To Write Code That Can Take Ownership?
------------------------------------------

.. sidebar:: 

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`

* Ok, ``unique_ptr`` is programmed to take ownership if possible
* What if I have code that wants to take ownership of a ``unique_ptr``
  (or any type that I can move from, for that matter)?
* |longrightarrow| Write my own *move constructor*

.. literalinclude:: code/unique-ptr-taking-ownership-own-code.cpp
   :caption: :download:`code/unique-ptr-taking-ownership-own-code.cpp`
   :language: c++

.. attention:: 

   **Pitfall alert**

   .. code-block:: c++

      HoldsASensor(std::unique_ptr<Sensor>&& s)
      : _sensor(std::move(s)) {}

   Note that the parameter ``s`` is an *lvalue*, for that matter - it
   has a name. So ``std::move()`` is *necessary*. ``std::unique_ptr``
   does not support copy, by nature, so the code won't sompile
   anyway. Other types may (``std::string``, for example). **There be
   dragons!**

   See
   :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/index`
   for more.

Manipulating Pointer Content
----------------------------

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Method
     * Description
   * * ``T* get()``
     * returns contained pointer
   * * ``reset(T* = nullptr)``
     * Deletes contained pointer, takes ownership of new pointer
   * * ``release()``
     * Returns contained pointer, releasing ownership

.. literalinclude:: code/unique-ptr-release-reset.cpp
   :caption: :download:`code/unique-ptr-release-reset.cpp`
   :language: c++


