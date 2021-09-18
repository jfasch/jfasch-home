.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.smart_pointers.unique_ptr
   :dependencies: cxx11.smart_pointers.introduction


``std::unique_ptr<>``
=====================

Simplest: ``std::unique_ptr<>``
-------------------------------

.. code-block:: c++

   #include <memory>

.. code-block:: c++

   void do_something() {
       std::unique_ptr<MyClass> tmp(new MyClass(666));
       do_something_with(tmp.get());
       ...
   }

* Destructor called at every return path
* No leaks

``std::unique_ptr<>``: Basic Usage
----------------------------------

* ``std::unique_ptr<>`` is a pointer
* |longrightarrow| supports ``->`` and ``*`` operators in a natural
  way

.. code-block:: c++

   ptr->do_something();
   MyClass copy = *ptr;

``std::unique_ptr<>``: Ownership (1)
------------------------------------

**Question:** who is responsible to delete the object?

**Answer:**

* If there is only one that points to it, then he's responsible
* **If two point to it, then both are responsible**
  
.. list-table::
   :align: left

   * * .. code-block:: c++

          unique_ptr<MyClass> owner(
              new MyClass(666));

     * 

       .. image:: uniqueptr-ownership.dia

   * * **Just don't do it!**

       .. code-block:: c++

          MyClass* tmp = new MyClass(666);
          unique_ptr<MyClass> owner1(tmp);
          unique_ptr<MyClass> owner2(tmp);

     * 

       .. image:: uniqueptr-duplicate-ownership.dia

``std::unique_ptr<>``: Ownership (2)
------------------------------------

**Shared ownership:** how else? |longrightarrow| Copy!

.. code-block:: c++

   unique_ptr<MyClass> owner(new MyClass(666));
   unique_ptr<MyClass> another_owner = owner;

.. code-block:: console
   :caption: Compilation error

   ... error: use of deleted function ...
  
**Good news ...**

* ``std::unique_ptr<>`` is not copyable
* Only movable

``std::unique_ptr<>``: Ownership Transfer
-----------------------------------------

**"Unique"** means that there can only be *one* owner

Passing a ``std::unique_ptr<>`` ...

.. code-block:: c++

   void do_something_with(unique_ptr<MyClass> c);
   void do_something()
   {
       unique_ptr<MyClass> owner(new MyClass(666));
       do_something_with(owner);
   }

.. code-block:: console
   :caption: Compilation error

   error: use of deleted function  ... (copy) ...

``std::unique_ptr<>``: Ownership Transfer
-----------------------------------------

**Back in C times ...**

* Ownership conflict
* No solution but to be careful
* C++ 11: no implicit transfer when using smart pointers
  |longrightarrow| compiler support for correctness
* |longrightarrow| **Clarity, no ambiguity**

**Explicit ownership transfer:** ``std::move``

.. code-block:: c++

   void do_something_with(unique_ptr<MyClass> c);
   void do_something()
   {
       unique_ptr<MyClass> owner(new MyClass(666));
       do_something_with(std::move(owner));
       assert(owner == nullptr); // owner has given up ownership
   }

``std::unique_ptr<>``: Juggling
-------------------------------

**Clearing**

.. code-block:: c++

   unique_ptr<MyClass> owner(new MyClass(666));
   owner.reset(); // deletes object

**Filling**

.. code-block:: c++

   unique_ptr<MyClass> owner;
   owner.reset(new MyClass(666));

**Stealing**

.. code-block:: c++

   unique_ptr<MyClass> owner(new MyClass(666));
   MyClass* obj = owner.release();

``std::make_unique<>``: Pure Decadence
--------------------------------------

**Lazyness**

* C++ 11 brings lots of tools to save you keystrokes
* e.g. ``auto``

.. code-block:: c++

   auto ptr = make_unique<MyClass>(666);
