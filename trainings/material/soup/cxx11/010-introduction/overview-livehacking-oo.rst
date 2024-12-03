.. ot-topic:: cxx11.introduction.overview_livehacking_oo

.. include:: <mmlalias.txt>


A Live-Hacked Tour Around The New C++ (Including OO)
====================================================

.. sidebar:: See also

   * :doc:`overview-livehacking`

.. sidebar:: jjj todo

   * Better description
   * check pitfall numbers
   * Link to leica course

A variation of :doc:`overview-livehacking`, omitting threading (and
:doc:`std::variant
</trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/variant>`
for that matter). Instead, we cover

* C++ "object oriented programming" (what's an *interface*?), C++11
  features to fix it (``= delete``, ``= default``, ``override``, and
  ``final``).
* All object orientation is then eliminated in favor of :doc:`lambda
  </trainings/material/soup/cxx11/020-new-language-features/lambda/group>`
  and :doc:`std::function
  </trainings/material/soup/cxx11/040-bind-function/020-function/topic>`.

See the following table of contents for the full topic coverage.

.. contents::
   :local:

C++03 To-Do List Version
------------------------

* Using ``std::map<std::string,std::string>`` as clumsy as is the
  nature of C++03
* No *initialization*, only default constructor (|longrightarrow|
  empty), and explicit fill at runtime
* Iterators - although I find pointer arithmetic cool, that taste is
  not shared by many

.. literalinclude:: code-oo/todolist-orig.cpp
   :caption: :download:`code-oo/todolist-orig.cpp`
   :language: c++

.. code-block:: console

   $ ./c++-intro-overview-oo-todolist-orig 
   NAME: down 1000 to 980, DESC: prefix: 'DOWN', count down from 1000 to 980, interval 0.5 second
   NAME: up 1 to 10, DESC: prefix: 'UP', count up from 1 to 10, interval 1 second

Encapsulate ``std::map`` Value In ``class Item`` (Pitfall)
----------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`

* Encapsulate value part of te map into something more approachable,
  for later extension
* Obvious implementation of ``class Item`` (only a wrapper around
  ``std::string``)

  .. code-block:: c++
  
     class Item
     {
     public:
         Item(const std::string& descr) : _descr(descr) {}
         void doit() const
         {
             std::cout << _descr;
         }
     private:
         std::string _descr;
     };

* Not enough, compiler complains (in its usual painful way) that
  ``Item`` needs a default constructor.

  .. code-block:: console

     ... 10 kilometers omitted ...
     /usr/include/c++/13/tuple:2268:9: error: no matching function for call to ‘Item::Item()’
      2268 |         second(std::forward<_Args2>(std::get<_Indexes2>(__tuple2))...)
           |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* Not (yet) entirely clear, but adding a default constructor is a
  workaround

  .. literalinclude:: code-oo/todolist-item-def-ctor-wtf.cpp
     :caption: :download:`code-oo/todolist-item-def-ctor-wtf.cpp`
     :language: c++

Pitfall #1: Accessing ``std::map`` Using Its ``operator[]``
-----------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-index-operator-bad`

* See :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-index-operator-bad`
* |longrightarrow| **A-ha**: this is why we had to implement default
  constructor
* **We don't want, though!**

Real Container Initialization: *Brace Initialization*
-----------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`
   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-insert`

* I don't want ``class Item`` to have a default constructor (I don't use it)
* I don't want to use :doc:`std::map::insert()
  </trainings/material/soup/cxx03/060-stl/050-associative-containers/map-insert>`
  either
* I want my map to be ``const``, **and initialized with content**
* |longrightarrow|
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`

.. literalinclude:: code-oo/todolist-const.cpp
   :caption: :download:`code-oo/todolist-const.cpp`
   :language: c++

.. _cxx11-overview-interfaces:

OOP (Towards *The Interface Dogma*): Two Kinds Of Items, Two Classes
--------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`

* Naive way: implement two *non-related* classes

  * To the "UP" item class, add a member ``prefix``, for later (slicing)
  * Be naive for that entire section, until we actually understand the
    *dogma*

* Omit constructors and members (there's only ``doit()`` methods)
* |longrightarrow| wonder how to get two distinct types into the map
* |longrightarrow| intermediate, non-functional, version

.. literalinclude:: code-oo/todolist-items-non-compiling.cpp
   :caption: :download:`code-oo/todolist-items-non-compiling.cpp`
   :language: c++

.. _cxx11-overview-inheritance:

OOP: Inheritance (Make It Compile, But Not Yet Work)
----------------------------------------------------

* Radically, just to get objects into the map: derive from base
  ``class Item``
* What to do in base class? |longrightarrow| output nonsense
* Talk about whats going on (see :ref:`next slide
  <cxx11-overview-inheritance-slicing>`

.. literalinclude:: code-oo/todolist-items-non-working.cpp
   :caption: :download:`code-oo/todolist-items-non-working.cpp`
   :language: c++

* Only ``Item::doit()`` is called
* Derived functionality not reached

.. code-block:: console

   $ ./c++-intro-overview-oo-todolist-items-non-working 
   NAME: down 1000 to 980, don't know what to do
   NAME: up 1 to 10, don't know what to do

.. _cxx11-overview-inheritance-slicing:

OOP: Analysis: The Perils Of Inheritance - *Slicing*
----------------------------------------------------

* Clarify: comment out todolist, and explain sideways
* C++ permits one to *copy* an object of derived type onto an object
  of base type
* Question: what if derived has additional members? Adds to the size
  of base?
* |longrightarrow| *slicing*
* |longrightarrow| mostly undesired, *but legal*

.. literalinclude:: code-oo/todolist-sideway-slicing.cpp
   :caption: :download:`code-oo/todolist-sideway-slicing.cpp`
   :language: c++

.. _cxx11-overview-inheritance-pointer-conversion:

OOP: Analysis: The Perils Of Inheritance - Automatic Pointer Type Conversion
----------------------------------------------------------------------------

* Better than *copying* objects of different sizes onto each other:
  *automatic type conversion*
* *The Plan*
* Still not perfect
* Nothing gets lost: only pointers are copied, the information in the
  derived object is still there
* Still not working though
* |longrightarrow| Derived class functionality not reachable

.. literalinclude:: code-oo/todolist-sideway-pointer-type-conversion.cpp
   :caption: :download:`code-oo/todolist-sideway-pointer-type-conversion.cpp`
   :language: c++

.. _cxx11-overview-inheritance-pointer-virtual:

OOP: Key To Polymorphism: ``virtual``
-------------------------------------

* Makes ``base->doit()`` magically work
* By adding runtime type information
* |longrightarrow| *dynamic method dispatch*, depending on concrete
  type
* |longrightarrow| Extension mechanism

.. literalinclude:: code-oo/todolist-sideway-virtual.cpp
   :caption: :download:`code-oo/todolist-sideway-virtual.cpp`
   :language: c++

OOP: Pitfall #N: Incorrectly Implement Derived Class Method
-----------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`

.. sidebar:: Trainer's note

   GCC (``gcc (GCC) 13.3.1 20240913 (Red Hat 13.3.1-3)`` as of this
   writing) is smart enough to warn about such cases. Turn that off
   with ``-Wno-overloaded-virtual``.

* Someone comes along and only understands ``void doit()``
* (``const`` not considered important to many)
* |longrightarrow| New method; different from ``void doit() const``

.. literalinclude:: code-oo/todolist-sideway-false-override.cpp
   :caption: :download:`code-oo/todolist-sideway-false-override.cpp`
   :language: c++

OOP: Pitfall #N: Solution: That's What ``override`` Is There For
----------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`

* ``override`` attached by *user* of base class (*implementor* of
  derived class)
* Makes the intent clear

.. literalinclude:: code-oo/todolist-sideway-override.cpp
   :caption: :download:`code-oo/todolist-sideway-override.cpp`
   :language: c++

.. code-block:: console

   todolist-sideway-override.cpp:17:10: error: ‘void YetAnotherItem::doit()’ marked ‘override’, but does not override
      17 |     void doit() override
         |          ^~~~

OOP: Pure Virtual Methods ("I Don't Know What ``class Item`` Would Do")
-----------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

* Implementation of ``Item::doit()`` is purely dummy
* Should not be there in the first place
* Pure virtual method: ``virtual void doit() const = 0``
* |longrightarrow| In fact, *is not there*
* |longrightarrow| *Forces* derived classes to implement it
* Btw., makes ``override`` redundant if only single-level inheritance
  is used

.. literalinclude:: code-oo/todolist-sideway-pure-virtual.cpp
   :caption: :download:`code-oo/todolist-sideway-pure-virtual.cpp`
   :language: c++

OOP: Pitfall #N+1: Derived Class Destructor (1)
-----------------------------------------------

* Destructors are special
* Lets be naive ...

.. literalinclude:: code-oo/todolist-sideway-nonvirtual-dtor.cpp
   :caption: :download:`code-oo/todolist-sideway-nonvirtual-dtor.cpp`
   :language: c++

* Runs as expected
* No memory leaks

.. code-block:: console

   $ ./c++-intro-overview-oo-todolist-sideway-nonvirtual-dtor 
   Allocated space for: blah(jfasch-home)

.. code-block:: console

   $ valgrind ./c++-intro-overview-oo-todolist-sideway-nonvirtual-dtor 
   ...
   HEAP SUMMARY:
       in use at exit: 0 bytes in 0 blocks
   ...

OOP: Pitfall #N+1: Derived Class Destructor (2)
-----------------------------------------------

* But what if we call destructor via base class?
* Much like with methods |longrightarrow| derived destructor not
  reached
* |longrightarrow| ``virtual destructor``
* Cannot be pure virtual

  * Destructors are special
  * Called from most derived upwards to base
  * |longrightarrow| Interface must have "do nothing" dtor
    implementation

.. literalinclude:: code-oo/todolist-sideway-virtual-dtor.cpp
   :caption: :download:`code-oo/todolist-sideway-virtual-dtor.cpp`
   :language: c++

OOP: The Interface, Put Dogmatically
------------------------------------

.. code-block:: c++

   class Interface
   {
   public:
       virtual ~Implementation() = default;
       virtual void doit() const = 0;
   };
      
   class Implementation : public Interface
   {
   public:
       ~Implementation() override ...                     // <-- optional
       void doit() const override ...                     // <-- mandatory
   };

Wrap Up: Polymorpic Todolist
----------------------------

.. literalinclude:: code-oo/todolist-polymorphic.cpp
   :caption: :download:`code-oo/todolist-polymorphic.cpp`
   :language: c++


.. .. Long ``iterator`` Type Names |longrightarrow| ``auto``
.. .. ------------------------------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
.. .. 
.. .. * Annoying: long ``iterator`` names
.. .. * ``typedef`` is of limited help
.. .. * |longrightarrow| ``auto``
.. .. 
.. .. .. literalinclude:: code-oo/todolist-auto.cpp
.. ..    :caption: :download:`code-oo/todolist-auto.cpp`
.. ..    :language: c++

.. .. More ``auto``: Unpacking ``std::pair``
.. .. --------------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
.. .. 
.. .. * More explicit type names
.. .. * ``std::pair`` 's ``first``, ``second``
.. .. 
.. .. .. literalinclude:: code/c++-intro-040-auto-pair.cpp
.. ..    :caption: :download:`code/c++-intro-040-auto-pair.cpp`
.. ..    :language: c++
.. .. 
.. .. Pitfall: Plain ``auto`` Creates Copy |longrightarrow| ``const auto&``
.. .. ---------------------------------------------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
.. .. 
.. .. * ``auto`` is only the base type
.. .. * Here: deducing the type of ``std::pair`` members
.. .. * On functions/methods: ignores any ``const``, any ``&``
.. .. 
.. .. .. literalinclude:: code/c++-intro-050-const-auto-ref-pair.cpp
.. ..    :caption: :download:`code/c++-intro-050-const-auto-ref-pair.cpp`
.. ..    :language: c++
.. .. 
.. .. Iterators Are So Old-School: *Range Based For*
.. .. ----------------------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for-map`
.. .. 
.. .. * C's ``for`` loops are only brutal syntactic sugar for ``while``
.. .. * This can be done better
.. .. * "I only want to see each element that's in it!" |longrightarrow|
.. ..   *Pythonicity!*
.. .. * Using ``auto`` all over
.. .. * |longrightarrow| ``const auto&``, obviously
.. .. 
.. .. .. literalinclude:: code/c++-intro-060-range-based-for-pair.cpp
.. ..    :caption: :download:`code/c++-intro-060-range-based-for-pair.cpp`
.. ..    :language: c++
.. .. 
.. .. Still Too Old-School: Want Python's *Tuple Unpacking*
.. .. -----------------------------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
.. .. 
.. .. * Annoying: manually unpacking ``std::pair`` 's ``first``, ``second``
.. .. * In Python there they have *tuple unpacking*: ``for k, v in tdl.items(): ...``
.. .. * |longrightarrow| *want that!*
.. .. * ``const auto&`` as always
.. .. * **Yay, can omit the braces around for-body!**
.. .. 
.. .. .. literalinclude:: code/c++-intro-070-range-based-for-tuple-unpack.cpp
.. ..    :caption: :download:`code/c++-intro-070-range-based-for-tuple-unpack.cpp`
.. ..    :language: c++
.. .. 
.. .. What If To-Do List Items Can Really Do Something? |longrightarrow| Functions
.. .. ----------------------------------------------------------------------------
.. .. 
.. .. .. sidebar:: 
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/100-miscellaneous/010-chrono/topic`
.. .. 
.. .. * Strings "Up, 1 .. 10", and "Down, 1000 .. 980" are not really
.. ..   unambiguous
.. .. * Lets write unambiguous functions (``void(*)()``), and run them
.. .. * New thing: ``<chrono>``, and its *literals*
.. .. 
.. ..   .. code-block:: 
.. .. 
.. ..      #include <chrono>
.. .. 
.. ..      using namespace std::chrono_literals;
.. ..      std::this_thread::sleep_for(1s);
.. .. 
.. .. .. literalinclude:: code/c++-intro-080-real-functions.cpp
.. ..    :caption: :download:`code/c++-intro-080-real-functions.cpp`
.. ..    :language: c++
.. .. 
.. .. Function Pointers Are Old-School |longrightarrow| ``std::function``
.. .. -------------------------------------------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/040-bind-function/010-bind/topic`
.. ..    * :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`
.. .. 
.. .. * Replace ``void(*)()`` with ``std::function`` (``<functional>``)
.. .. * |longrightarrow| can take *any* callable
.. .. 
.. .. .. literalinclude:: code/c++-intro-090-std-function.cpp
.. ..    :caption: :download:`code/c++-intro-090-std-function.cpp`
.. ..    :language: c++
.. .. 
.. .. Definitely *Not* Old-School: *Lambda*
.. .. -------------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`
.. .. 
.. .. * ``up_1_to_10()`` and ``down_1000_to_980()`` are *one-shot functions*
.. .. * Make only sense at one point: part of a todo list
.. .. * Want to define them *where I use them*
.. .. * |longrightarrow| :doc:`Lambda
.. ..   </trainings/material/soup/cxx11/020-new-language-features/lambda/group>`
.. .. 
.. .. .. note::
.. .. 
.. ..    See how ``std::function<void()>`` can take a lambda, as long as the
.. ..    signature fits!
.. .. 
.. .. .. literalinclude:: code/c++-intro-100-lambda.cpp
.. ..    :caption: :download:`code/c++-intro-100-lambda.cpp`
.. ..    :language: c++
.. .. 
.. .. Inevitable: Threads
.. .. -------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/050-multithreading/group`
.. .. 
.. .. * Threads are not a toy
.. .. * Far too easy in C++ since 2011
.. .. * Morph todo-item into
.. ..   ``std::pair<std::function<void()>, std::shared_ptr<std::thread>>``
.. .. * Start in a loop
.. .. * Join in another loop
.. .. 
.. .. .. literalinclude:: code/c++-intro-110-threads.cpp
.. ..    :caption: :download:`code/c++-intro-110-threads.cpp`
.. ..    :language: c++
.. .. 
.. .. Unions? ``std::variant``!
.. .. -------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/100-miscellaneous/any-variant-optional/variant`
.. .. 
.. .. * Why use ``std::pair<std::function<void()>,
.. ..   std::shared_ptr<std::thread>>`` when only either function or thread
.. ..   is active?
.. .. * |longrightarrow| ``std::variant``
.. .. 
.. .. .. literalinclude:: code/c++-intro-120-variant.cpp
.. ..    :caption: :download:`code/c++-intro-120-variant.cpp`
.. ..    :language: c++
.. .. 
.. .. Wrapping All That Into A Class
.. .. ------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`
.. .. 
.. .. * This is getting too big |longrightarrow| encapsulate into ``class
.. ..   TodoList``
.. .. * Copying an object that maintains threads shouldn't be possible.
.. .. * Copy is possible though: for technical reasons we had to use
.. ..   ``std::shared_ptr<std::thread>``
.. .. * ``= delete``
.. .. 
.. .. .. literalinclude:: code/c++-intro-130-class-nocopy.cpp
.. ..    :caption: :download:`code/c++-intro-130-class-nocopy.cpp`
.. ..    :language: c++
.. .. 
.. .. Architectural Considerations: No Implementation Inheritance Wanted
.. .. ------------------------------------------------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`
.. .. 
.. .. * Clean architecture does not do too much implementation inheritance
.. ..   (at least, OO evangelists say so)
.. .. * Let inhibit that |longrightarrow| make the class ``final``
.. .. 
.. .. .. literalinclude:: code/c++-intro-140-final.cpp
.. ..    :caption: :download:`code/c++-intro-140-final.cpp`
.. ..    :language: c++
.. .. 
.. .. Wrapping Up: Initializer
.. .. ------------------------
.. .. 
.. .. .. sidebar::
.. .. 
.. ..    **See also**
.. .. 
.. ..    * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`
.. .. 
.. .. * Lost the ability to *initialize* a ``TodoList`` object
.. ..   (|longrightarrow| ``add_item()``)
.. .. * Add that
.. .. * Done!
.. .. 
.. .. .. note::
.. .. 
.. ..    ``std::map`` member type is ``std::pair<const keytype,
.. ..    valuetype>``; take that into account when specifying the
.. ..    initializer list's shape.
.. .. 
.. .. .. literalinclude:: code/c++-intro-150-initializer-list.cpp
.. ..    :caption: :download:`code/c++-intro-150-initializer-list.cpp`
.. ..    :language: c++
.. .. 
