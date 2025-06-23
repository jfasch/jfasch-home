.. include:: <mmlalias.txt>


A One-Day Overview Of C++
=========================

.. sidebar:: Topics covered

   *Language basics*

   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map` (and the STL in general)
   * :doc:`/trainings/material/soup/cxx11/brace-initialization/index`
   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index` (including C++11 goodies like ``override``, ``final``, ``= delete``, ...)

   *Memory management*

   * :doc:`/trainings/material/soup/cxx11/smart-pointers/index`
   * :doc:`/trainings/material/soup/cxx11/move/index`

   *Pythonic features*
     
   * :doc:`/trainings/material/soup/cxx11/auto/topic`
   * :doc:`/trainings/material/soup/cxx11/structured-binding/topic`
   * :doc:`/trainings/material/soup/cxx11/range-for/range-based-for`

   *New language directions*

   * :doc:`/trainings/material/soup/cxx11/lambda/index`
   * :doc:`/trainings/material/soup/cxx11/bind-function/020-function/topic`

A one-day ride through C++ for those who can take it. Course format is
"trainer hacks/speaks, audience speaks up to comment/ask/discuss".

The intent of this course [#tweakable]_ is not to teach C++
[#unteachable]_, but rather to give an overview of it to experienced
programmers. For example, 

* Different teams who already use C++ come together in the course, and
  develop a common viewpoint and vocabulary.
* Those who come from C (or an entirely different language?) want to
  see what they're up to.

This is not a slide deck, but rather can be seen as a live-coding
"screenplay" that is used by the :doc:`trainer </about/myself/index>`
to not get too far off track. It starts with an old-style (pre C++11)
version of a nonsense program, which is continuously modified into
something completely different (which does not make much more sense
either).

I wrote this up after a number of iterations of the talk (:doc:`here's
another version of it <overview-livehacking>`). C++ cannot be taught
in just one day; that seems to be clear to the companies that have
booked the courses. (See :doc:`here for one such course
</trainings/log/detail/2024-11-19--C++-One-Day/index>`)



.. contents::
   :depth: 1
   :local:

.. _cxx11-overview-cxx03:

C++03 Todo-List
---------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map`

* Todo-list: a key-value store
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

.. _cxx11-overview-class-item-encap:

Pitfall: Encapsulate ``std::map`` Value In ``class Item``
---------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/oo/default`
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

.. _cxx11-overview-class-item-encap-pitfall:

Pitfall: Accessing ``std::map`` Using Its ``operator[]``
--------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-index-operator-bad`
   * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-insert`

* See :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/map-index-operator-bad`
* |longrightarrow| **A-ha**: this is why we had to implement default
  constructor
* **We don't want, though!**

.. _cxx11-overview-brace-init:

Real Container Initialization: *Brace Initialization*
-----------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/brace-initialization/index`

* I don't want ``class Item`` to have a default constructor (I don't use it)
* I don't want to use :doc:`std::map::insert()
  </trainings/material/soup/cxx03/060-stl/050-associative-containers/map-insert>`
  either
* I want my map to be ``const``, **and initialized with content**
* |longrightarrow|
  :doc:`/trainings/material/soup/cxx11/brace-initialization/index`

.. literalinclude:: code-oo/todolist-const.cpp
   :caption: :download:`code-oo/todolist-const.cpp`
   :language: c++

.. _cxx11-overview-interfaces:
.. _cxx11-overview-towards-interface-dogma:

OOP: Towards *The Interface Dogma*
----------------------------------

.. contents::
   :local:

.. _cxx11-overview-towards-interface-dogma-two-classes:

Two Kinds Of Items, Two Classes
...............................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index`

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
.. _cxx11-overview-towards-interface-dogma-inheritance:

Inheritance (Make It Compile, But Not Yet Work)
...............................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index`
   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/basics`

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
.. _cxx11-overview-towards-interface-dogma-slicing:

Analysis: The Perils Of Inheritance - *Slicing*
...............................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index`
   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/basics`

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
.. _cxx11-overview-towards-interface-dogma-pointer-conversion:

Analysis: The Perils Of Inheritance - Automatic Pointer Type Conversion
.......................................................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index`
   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/basics`

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
.. _cxx11-overview-towards-interface-dogma-virtual:

Key To Polymorphism: ``virtual``
................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/index`
   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/virtual-method`

* Makes ``base->doit()`` magically work
* By adding runtime type information
* |longrightarrow| *dynamic method dispatch*, depending on concrete
  type
* |longrightarrow| Extension mechanism

.. literalinclude:: code-oo/todolist-sideway-virtual.cpp
   :caption: :download:`code-oo/todolist-sideway-virtual.cpp`
   :language: c++

.. _cxx11-overview-towards-interface-dogma-not-overriding:

Pitfall: Incorrectly Implement Derived Class Method
...................................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/oo/override`

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

.. _cxx11-overview-towards-interface-dogma-override:

Solution: That's What ``override`` Is There For
...............................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/oo/override`

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

.. _cxx11-overview-towards-interface-dogma-pure-virtual:

Pure Virtual Methods ("I Don't Know What ``class Item`` Would Do")
..................................................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/interface`
   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/pure-virtual`

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

.. _cxx11-overview-towards-interface-dogma-derived-dtor-1:

Pitfall: Derived Class Destructor (1)
.....................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/interface`
   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/destructor`

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

.. _cxx11-overview-towards-interface-dogma-derived-dtor-2:

Pitfall: Derived Class Destructor (2)
.....................................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/interface`
   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/destructor`

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
.. _cxx11-overview-towards-interface-dogma-done:

The Interface, Put Dogmatically
...............................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/inheritance-oo-design/interface`

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

.. _cxx11-overview-polymorphic-todolist:

Wrap Up: Polymorpic Todolist
----------------------------

* Long story short: here's the final *polymorphic* version
* Note the extra cleanup step at the end |longrightarrow| fragile
  (easily forgotten)

.. literalinclude:: code-oo/todolist-polymorphic.cpp
   :caption: :download:`code-oo/todolist-polymorphic.cpp`
   :language: c++

.. _cxx11-overview-smart-pointers:

Memory Management: Smart Pointers (Showing The Options)
-------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/smart-pointers/index`

* Plan: no manual memory management

.. code-block:: c++
   :caption: **BAD**

   for (todo_list::const_iterator it=tdl.begin(); it!= tdl.end(); ++it)
       delete it->second;

* Explain
  :doc:`/trainings/material/soup/cxx11/smart-pointers/shared-ptr/topic`
* Explain
  :doc:`/trainings/material/soup/cxx11/smart-pointers/unique-ptr/topic`

.. _cxx11-overview-unique-ptr:

Memory Management: ``std::unique_ptr<>`` In TodoList |longrightarrow| *No*
--------------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/brace-initialization/index`
   * :doc:`/trainings/material/soup/cxx11/move/index`

* Try to use it (failed code below)
* Explain ``std::initializer_list<>``
* Show ``std::map(std::initializer_list<value_type>)`` (`here
  <https://en.cppreference.com/w/cpp/container/map/map>`__)
  |longrightarrow| *by copy*
* |longrightarrow| ``std::unique_ptr<>`` is *move only*
* |longrightarrow| ``std::unique_ptr<>`` unusable in :doc:`brace
  initialization
  </trainings/material/soup/cxx11/brace-initialization/index>`

.. literalinclude:: code-oo/todolist-unique-ptr.cpp
   :caption: :download:`code-oo/todolist-unique-ptr.cpp`
   :language: c++

.. _cxx11-overview-move:

A Short Deviation: Move Semantics
---------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/move/index`

* At that time, a little deviation into :doc:`move semantics
  </trainings/material/soup/cxx11/move/index>`
  is in order
* |longrightarrow| This helps understand the compiler when he tries to
  just say "no" but fails

.. _cxx11-overview-shared-ptr:

Memory Management: ``std::shared_ptr<>`` In TodoList
----------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/smart-pointers/shared-ptr/topic`
   * :doc:`/trainings/material/soup/cxx11/smart-pointers/040-closing-words/topic`

* I do want :doc:`brace initialization
  </trainings/material/soup/cxx11/brace-initialization/index>`
* *And* I don't want to do manual memory management
* |longrightarrow| The only viable option is to use
  ``std::shared_ptr<>``

.. literalinclude:: code-oo/todolist-shared-ptr.cpp
   :caption: :download:`code-oo/todolist-shared-ptr.cpp`
   :language: c++

.. _cxx11-overview-auto:

Readability: Long Type Names |longrightarrow| ``auto``
------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/auto/topic`

* ``std::map<std::string, std::shared_ptr<Item>::const_iterator``
* ... and more
* Compiler *knows* what the type of ``tdl.begin()`` is
* |longrightarrow| ``auto``

.. literalinclude:: code-oo/todolist-auto-wrong.cpp
   :caption: :download:`code-oo/todolist-auto-wrong.cpp`
   :language: c++

.. _cxx11-overview-auto-pitfalls:

Pitfalls: ``auto``
------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/auto/topic`

* ``auto`` is only the base type (``const`` and ``&``) omitted
* ``tdl.begin()`` gives ``const_iterator`` if ``tdl`` is ``const``
* Non ``const`` otherwise
* |longrightarrow| ``tdl.cbegin()``

.. literalinclude:: code-oo/todolist-auto-right.cpp
   :caption: :download:`code-oo/todolist-auto-right.cpp`
   :language: c++

.. _cxx11-overview-structured-binding:

Readability: Tuple Unpacking (Err, Structured Binding)
------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/structured-binding/topic`

* ``auto`` is required, obviously
* Transformation is trivial

.. literalinclude:: code-oo/todolist-structured-binding.cpp
   :caption: :download:`code-oo/todolist-structured-binding.cpp`
   :language: c++

.. _cxx11-overview-range-based-for:

Range Based ``for``
-------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/range-for/range-based-for`

* Iterator based loops? Pointer arithmetic? |longrightarrow| *NO*
* Element based iteration (Python's ``for``, C# ``foreach``)
* ... in combination with ``auto``

.. literalinclude:: code-oo/todolist-range-for.cpp
   :caption: :download:`code-oo/todolist-range-for.cpp`
   :language: c++

.. _cxx11-overview-lambda:

Full Classes Hierarchy For One Method ``doit()`` |longrightarrow| *NO* (Lambdas)
--------------------------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/lambda/index`
   * :doc:`/trainings/material/soup/cxx11/bind-function/020-function/topic`

* :ref:`Interfaces <cxx_overview_oo__iface_dogma>` are heavyweight

  * Readability suffers
  * Code bloat through ``virtual`` (RTTI - Run Time Type Information)

* Show what a *functor* is (class with overloaded ``operator()()``)
  (see :doc:`here
  </trainings/material/soup/cxx11/lambda/lambda-is-functor>`)
* Turn functor into lambda
* |longrightarrow| Captures vs. functor members
* More syntax:
  :doc:`/trainings/material/soup/cxx11/lambda/lambda-capture`
* Show what a ``std::function<>`` can do

  * Plain old function
  * Functor
  * Lambda
  * ...

.. _cxx11-overview-lambda-todolist:

Wrap Up: TodoList, De-Overengineered
------------------------------------

* Transform classes to lambdas
* Interface *gone*
* Big fat class body *gone*
* Code bloat *gone*

.. literalinclude:: code-oo/todolist-lambda.cpp
   :caption: :download:`code-oo/todolist-lambda.cpp`
   :language: c++


.. rubric:: Footnotes
.. [#tweakable] The course can be adapted to your organization as you
                like it. Omit topics that are not relevant for you,
                and replace them with others like :doc:`threading
                </trainings/material/soup/cxx11/multithreading/index>`,
                for example.

		See :doc:`here </trainings/material/soup/index>` for
		what's there overall.

.. [#unteachable] C++'s nature is that it is nearly unteachable -
                  teaching it in one day is especially unrealistic.
