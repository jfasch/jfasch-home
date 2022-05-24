.. include:: <mmlalias.txt>

.. ot-topic:: cxx11.smart_pointers.shared_ptr
   :dependencies: cxx11.smart_pointers.introduction


``std::shared_ptr<>``
=====================

``std::shared_ptr<>``: Not Unique
---------------------------------

**Ownership is not always clear ...**

* Rare occasions where shared ownership is the right design choice
* ... laziness, mostly
* If in doubt, say ``std::shared_ptr<>``

.. list-table::
   :align: left

   * * .. code-block:: c++

          #include <memory>
          std::shared_ptr<MyClass> ptr(
              new MyClass(666));

     * 

       .. image:: sharedptr.dia

``std::shared_ptr<>``: Copy
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

``std::shared_ptr<>`` vs. ``std::unique_ptr<>``
-----------------------------------------------

How do ``std::shared_ptr<>`` and ``std::unique_ptr<>`` compare?

* ``std::unique_ptr<>``

  * Small - size of a pointer
  * Operations compile away entirely
  * No excuse *not* to use it

* ``std::shared_ptr<>``

  * Size of two pointers
  * Copying manipulates the resource count
  * Copying manipulates non-adjacent memory locations

``std::shared_ptr<>``: Object Lifetime
--------------------------------------

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

``std::shared_ptr<>``: Juggling
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
