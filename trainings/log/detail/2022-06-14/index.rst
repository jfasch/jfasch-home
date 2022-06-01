.. include:: <mmlalias.txt>


C++: A New Language Starting In 2011
====================================

.. toctree::
   :hidden:

   2022-05-11

.. contents::
   :local:

Following a list of topics to be covered in our two C++
trainings. Slide material already exists for most of the topics; links
to it are given in these cases.

Pythonicity (Thank You: Readablility and Writability)
-----------------------------------------------------

Range Based for Loops
.....................

* Material: :doc:`/trainings/material/soup/cxx11/020-new-language-features/040-range-based-for/topic`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * Structured Binding
     * * C++ 17: `"Structured Binding"
         <https://en.cppreference.com/w/cpp/language/structured_binding>`__
	 (just like Python's *Tuple Unpacking*)
       * `std::tuple <https://en.cppreference.com/w/cpp/utility/tuple>`__
       * `std::tie <https://en.cppreference.com/w/cpp/utility/tuple/tie>`__
       * `std::ignore <https://en.cppreference.com/w/cpp/utility/tuple/ignore>`__
   * * Live hacking: iteration over ``map<k,v>``
     * 
   * * Range-for temporary
     * While we are at it: ``for (T container=foo(); auto elem:
       container) {...}`` (see `here
       <https://en.cppreference.com/w/cpp/language/range-for>`__)
   * * ``if`` temporary variable
     * While we are at it: ``if (auto result=foo()) {...}``
       (|longrightarrow| ``std::optional<>``). This does not belong
       here, but it serves a similar purpose.
   * * See-also links
     * * auto/decltype
       * structured binding
       * tuple, tie, ignore

``auto``
........

* Material:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/auto`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * ``auto`` variants
     * Make explicit how important it is to know how to use variants
       such as ``auto&`` and ``const auto&``
   * * Discussion: readability, compiler errors
     * Bring live hacking examples accordingly
   * * Function return-type deduction
     * While we are at it: `Function return-type deduction
       <https://en.cppreference.com/w/cpp/language/function#Return_type_deduction>`__

Things That Simply Deserved Fixing Since Ages
---------------------------------------------

Brace Initialization
....................

* Material:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/topic`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * How to initialize container by myself: ``initializer_list``
     * https://en.cppreference.com/w/cpp/utility/initializer_list

New OO keywords: override, final, default, delete
.................................................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/override`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/final`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/delete`
* :doc:`/trainings/material/soup/cxx11/020-new-language-features/default`

Strongly Typed enum
...................

* Material:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/010-strongly-typed-enums/topic`

Delegating Constructor
......................

* Material:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/050-delegating-ctor/topic`

``nullptr``
...........

* Material: :doc:`/trainings/material/soup/cxx11/020-new-language-features/070-miscellaneous/topic`

Miscellaneous
.............

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * ``decltype``
     * https://en.cppreference.com/w/cpp/language/decltype
   * * ``constexpr``
     * https://en.cppreference.com/w/cpp/language/constexpr

Smart Pointers
--------------

From :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`:

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/introduction-livehack`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/weakptr`
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * Interface tables
     * 

Moving, “RValue References”
---------------------------

* Material:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/060-move/topic`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * Live hacking
     * * Cite ``std::auto_ptr<>`` from C++03; show possible
         implementation for-the-poor
       * Use ``&&`` to implement unique_ptr for-the-poor
   * * Rules
     * When is move generated by compiler?

Functions (``std::bind<>``, ``std::function<>``, Lambdas)
---------------------------------------------------------

From :doc:`/trainings/material/soup/cxx11/040-bind-function/group`:

* :doc:`/trainings/material/soup/cxx11/040-bind-function/010-bind/topic`
* :doc:`/trainings/material/soup/cxx11/040-bind-function/020-function/topic`
* Lambda (tbd)

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * Live Hacking: ``bind<>`` and ``function<>``
     * * Highlight difference between bind and function
         (single-purpose-but-efficient vs. polymorphic)
       * Show how to use Lambda as ``std::function`` replacement
         (gently introducing lambdas)
   * * Lambda slide material
     * Slide material: capture syntax, with examples. Cover extensions
       >11

       * https://en.wikipedia.org/wiki/C%2B%2B14#Lambda_capture_expressions
   * * Live hacking: what is lambda?
     * * Problem: a class with members and a function call operator
         |longrightarrow| tedious
       * Solution: Lambda
   * * Live hacking: capture by reference
     * * Capture by reference leads to dead references sooner or later
       * |longrightarrow| show how valgrind can detect such errors
	 (:doc:`valgrind
	 </trainings/material/soup/c/090-program-sanity/080-valgrind/topic>`)

Multithreading
--------------

From :doc:`/trainings/material/soup/cxx11/050-multithreading/group`:

* :doc:`/trainings/material/soup/cxx11/050-multithreading/010-introduction/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/020-thread/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/030-race-conditions/topic`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/scoped-locking`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
* :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * Discussion: Thread Objects
     * * Ctor starts code in thread -> plain function, std::function,
         lambda
       * No copy, only move (obviously)
       * ``join()``, ``detach()``: terminating before join? live hack
         that!
   * * Extend :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/scoped-locking`
     * * ``scoped_lock`` (see-also condvar)
       * ``unique_lock``
   * * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`:
       add ``struct`` specialization
     * 
   * * Add literals to
       :doc:`/trainings/material/soup/cxx11/100-miscellaneous/010-chrono/topic`
     * ... and a "See also" to a literals live hackery
   * * Memory Model
     * See for example the unlocked ``answer``, ``answer_valid`` story
   * * Semaphores (since 20)
     * * Distill from `semaphore <https://en.cppreference.com/w/cpp/thread/counting_semaphore>`__
       * Add "see-also"
	 :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
       * Add "see-also"
	 :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`

Exercise
--------

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * Larger exercise
     * Ideally split across topics covered so far

       * Multithreading
       * A ``std::map<>`` |longrightarrow| *range based for* with
	 *structured binding*, and much *auto*
       * Lambdas. distill something out of a larger set of measurement
         data, for example
       * ``promise<>/future<>`` to wait for the computation result

Miscellaneous
-------------

**TODO: Important**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * ``std::any<>``, ``std::optional<>``, ``std::variant<>``
     * 
   * * ``vector<>::emplace_back()``
     * 
   * * ``forward``
     * 
   * * ``array``
     * 
   * * ``ref``, ``cref``
     * 

**TODO: Optional**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
   * * new containers and algorithms (next to beginning somewhere)
     * 
   * * `File system library
       <https://en.cppreference.com/w/cpp/filesystem>`__
     * 
   * * ``chrono`` += how to sleep
     * Done in various live hacking session on the way; add to
       :doc:`slide material
       </trainings/material/soup/cxx11/100-miscellaneous/010-chrono/topic>`
   * * `Regular expression library
       <https://en.cppreference.com/w/cpp/regex>`__
     * `(Raw) string literal
       <https://en.cppreference.com/w/cpp/language/string_literal>`__
   * * ``constexpr``, ``constexpr if`` (since C++17)
     *
