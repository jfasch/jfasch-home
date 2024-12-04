.. ot-topic:: cxx11.introduction.overview_livehacking_oo

.. include:: <mmlalias.txt>


A Live-Hacked Tour Around The New C++ (Including OO)
====================================================

.. sidebar:: C++ topics covered jjj

   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map` (and the STL in general)

   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-index-operator-bad`
   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-insert`

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`

   * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/group`

   pythonicity

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`

   even more pythonicity

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`
   * :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`


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

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map`

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
   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-insert`

* See :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-index-operator-bad`
* |longrightarrow| **A-ha**: this is why we had to implement default
  constructor
* **We don't want, though!**

Real Container Initialization: *Brace Initialization*
-----------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`

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

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`

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

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`

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

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/basics`

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

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/group`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-method`

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
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/polymorphism`

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

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`

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

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/destructor`
   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/virtual-destructor`

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

.. _cxx_overview_oo__iface_dogma:

OOP: The Interface, Put Dogmatically
------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/100-inheritance-oo-design/interface`

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

* Long story short: here's the final *polymorphic* version
* Note the extra cleanup step at the end |longrightarrow| fragile
  (easily forgotten)

.. literalinclude:: code-oo/todolist-polymorphic.cpp
   :caption: :download:`code-oo/todolist-polymorphic.cpp`
   :language: c++

Memory Management: Smart Pointers (Showing The Options)
-------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`

* Plan: no manual memory management

.. code-block:: c++
   :caption: **BAD**

   for (todo_list::const_iterator it=tdl.begin(); it!= tdl.end(); ++it)
       delete it->second;

* Explain
  :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* Explain
  :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`

Memory Management: ``std::unique_ptr<>`` In TodoList |longrightarrow| *No*
--------------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/group`

* Try to use it (failed code below)
* Explain ``std::initializer_list<>``
* Show ``std::map(std::initializer_list<value_type>)`` (`here
  <https://en.cppreference.com/w/cpp/container/map/map>`__)
  |longrightarrow| *by copy*
* |longrightarrow| ``std::unique_ptr<>`` is *move only*
* |longrightarrow| ``std::unique_ptr<>`` unusable in :doc:`brace
  initialization
  </trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group>`

.. literalinclude:: code-oo/todolist-unique-ptr.cpp
   :caption: :download:`code-oo/todolist-unique-ptr.cpp`
   :language: c++

Memory Management: ``std::shared_ptr<>`` In TodoList
----------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
   * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

* I do want :doc:`brace initialization
  </trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/group>`
* *And* I don't want to do manual memory management
* |longrightarrow| The only viable option is to use
  ``std::shared_ptr<>``

.. literalinclude:: code-oo/todolist-shared-ptr.cpp
   :caption: :download:`code-oo/todolist-shared-ptr.cpp`
   :language: c++

Readability: Long Type Names |longrightarrow| ``auto``
------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`

* ``std::map<std::string, std::shared_ptr<Item>::const_iterator``
* ... and more
* Compiler *knows* what the type of ``tdl.begin()`` is
* |longrightarrow| ``auto``

.. literalinclude:: code-oo/todolist-auto-wrong.cpp
   :caption: :download:`code-oo/todolist-auto-wrong.cpp`
   :language: c++

Pitfalls: ``auto``
------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`

* ``auto`` is only the base type (``const`` and ``&``) omitted
* ``tdl.begin()`` gives ``const_iterator`` if ``tdl`` is ``const``
* Non ``const`` otherwise
* |longrightarrow| ``tdl.cbegin()``

.. literalinclude:: code-oo/todolist-auto-right.cpp
   :caption: :download:`code-oo/todolist-auto-right.cpp`
   :language: c++

Readability: Tuple Unpacking (Err, Structured Binding)
------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`

* ``auto`` is required, obviously
* Transformation is trivial

.. literalinclude:: code-oo/todolist-structured-binding.cpp
   :caption: :download:`code-oo/todolist-structured-binding.cpp`
   :language: c++

Range Based ``for``
-------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`

* Iterator based loops? Pointer arithmetic? |longrightarrow| *NO*
* Element based iteration (Python's ``for``, C# ``foreach``)
* ... in combination with ``auto``

.. literalinclude:: code-oo/todolist-range-for.cpp
   :caption: :download:`code-oo/todolist-range-for.cpp`
   :language: c++

Full Classes Hierarchy For One Method ``doit()`` |longrightarrow| *NO* (Lambdas)
--------------------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/group`
   * :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`

* :ref:`Interfaces <cxx_overview_oo__iface_dogma>` are heavyweight

  * Readability suffers
  * Code bloat through ``virtual`` (RTTI - Run Time Type Information)

* Show what a *functor* is (class with overloaded ``operator()()``)
  (see :doc:`here
  </trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-is-functor>`)
* Turn functor into lambda
* |longrightarrow| Captures vs. functor members
* More syntax:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/lambda/lambda-capture`
* Show what a ``std::function<>`` can do

  * Plain old function
  * Functor
  * Lambda
  * ...

Wrap Up: TodoList, De-Overengineered
------------------------------------

* Transform classes to lambdas
* Interface *gone*
* Big fat class body *gone*
* Code bloat *gone*

.. literalinclude:: code-oo/todolist-lambda.cpp
   :caption: :download:`code-oo/todolist-lambda.cpp`
   :language: c++
