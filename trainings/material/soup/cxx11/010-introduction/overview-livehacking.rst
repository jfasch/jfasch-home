.. ot-topic:: cxx11.introduction.overview_livehacking
   :dependencies: cxx11.introduction.history

.. include:: <mmlalias.txt>


Overview (Live Hacking)
=======================

A sketch of something purely nonsense, only there to walk through *The
New C++*

* To-Do list: names, and associated items
* Items are strings initially
* Slowly morphed into things that actually do something
  (|longrightarrow| ``<functional>``, and lambdas)
* Ending up in a multithreading massacre
* ... nicely encapsulated in a class

.. contents::
   :local:

C++03 To-Do List Version
------------------------

* Using ``std::map<std::string,std::string>`` as clumsy as in the
  nature of C++03
* No *initialization*, only default constructor (|longrightarrow|
  empty), and explicit fill at runtime
* Iterators - although I find pointer arithmetic cool, that taste is
  not shared by many

.. literalinclude:: code/c++-intro-010-c++03-version.cpp
   :caption: :download:`code/c++-intro-010-c++03-version.cpp`
   :language: c++

Real Container Initialization
-----------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/topic`

* Think C's "array of ``struct``" initialization
* ``std::map`` is *initialized*
* Almost feels like Python: ``dict([(1, "one"), (2, "two")])``

.. literalinclude:: code/c++-intro-020-brace-initialization.cpp
   :caption: :download:`code/c++-intro-020-brace-initialization.cpp`
   :language: c++

Long ``iterator`` Type Names |longrightarrow| ``auto``
------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`

* Annoying: long ``iterator`` names
* ``typedef`` is of limited help

.. literalinclude:: code/c++-intro-030-auto-iterator.cpp
   :caption: :download:`code/c++-intro-030-auto-iterator.cpp`
   :language: c++

More ``auto``: Unpacking ``std::pair``
--------------------------------------

* More explicit type names
* ``std::pair`` 's ``first``, ``second``

.. literalinclude:: code/c++-intro-040-auto-pair.cpp
   :caption: :download:`code/c++-intro-040-auto-pair.cpp`
   :language: c++

Pitfall: Plain ``auto`` Creates Copy |longrightarrow| ``const auto&``
---------------------------------------------------------------------

* ``auto`` is only the base type
* Here: deducing the type of ``std::pair`` members
* On functions/methods: ignores any ``const``, any ``&``

.. literalinclude:: code/c++-intro-050-const-auto-ref-pair.cpp
   :caption: :download:`code/c++-intro-050-const-auto-ref-pair.cpp`
   :language: c++

Iterators Are So Old-School: *Range Based For*
----------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for`
   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/range-based-for-map`

* C's ``for`` loops are only brutal syntactic sugar for ``while``
* This can be done better
* "I only want to see each element that's in it!" |longrightarrow|
  *Pythonicity!*
* Using ``auto`` all over
* |longrightarrow| ``const auto&``, obviously

.. literalinclude:: code/c++-intro-060-range-based-for-pair.cpp
   :caption: :download:`code/c++-intro-060-range-based-for-pair.cpp`
   :language: c++

Still Too Old-School: Want Python's *Tuple Unpacking*
-----------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/cxx11/020-new-language-features/structured-binding`

* Annoying: manually unpacking ``std::pair`` 's ``first``, ``second``
* In Python there they have *tuple unpacking*: ``for k, v in tdl.items(): ...``
* |longrightarrow| *want that!*
* ``const auto&`` as always
* **Yay, can omit the braces around for-body!**

.. literalinclude:: code/c++-intro-070-range-based-for-tuple-unpack.cpp
   :caption: :download:`code/c++-intro-070-range-based-for-tuple-unpack.cpp`
   :language: c++

What If To-Do List Items Can Really Do Something? |longrightarrow| Functions
----------------------------------------------------------------------------

* Strings "Up, 1 .. 10", and "Down, 1000 .. 980" are not really
  unambiguous
* Lets write functions, and run them


jjjjjj
------

* write functions instead, to call later

  * void up_0_to_99()
  * void down_1000_to_900()

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(1s);

  map<string, void(*)()>

  * second loop, executing the functions
  * replace void(*)() with std::function<void()>
  * with this, introduce lambda -> write the functions as we need them

* threads

  using todo_list_item = std::pair<std::function<void()>, std::shared_ptr<std::thread>>;
  using todo_list = std::map<std::string /*name*/, todo_list_item>;

* too much inline coding -> encapsulate

  * final
  * variant as map's value type
