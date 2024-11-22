.. ot-topic:: cxx11.introduction.overview_livehacking_oo

.. include:: <mmlalias.txt>


A Live-Hacked Tour Around The New C++ (Including OO)
====================================================

.. sidebar:: See also

   * :doc:`overview-livehacking`

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

Encapsulate ``std::map`` Value Side in ``class Item``: Pitfall #1
-----------------------------------------------------------------

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`
   * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`

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

     ... 10 kilemeters omitted ...
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
* |longrightarrow| **A-ha**: this is why we had to implemnt default
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
.. .. 
.. .. .. literalinclude:: code/c++-intro-030-auto-iterator.cpp
.. ..    :caption: :download:`code/c++-intro-030-auto-iterator.cpp`
.. ..    :language: c++
.. .. 
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
