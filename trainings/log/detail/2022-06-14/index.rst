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
to it are given in these cases. Additional topics are given as plain
text, to be made into slide material.

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
     * Link
     * Done
   * * ``auto`` variants
     * Discuss relationship with ``auto``; make explicit how important
       it is to know how to use variants such as ``auto&`` and ``const
       auto&``
     * 
     *
   * * Structured Binding
     * C++ 17: `"Structured Binding"
       <https://en.cppreference.com/w/cpp/language/structured_binding>`__
       (just like Python's *Tuple Unpacking*)
     * 
     * 
   * * Live hacking: iteration over ``map<k,v>``
     * 
     *
     *
   * * Range-for temporary
     * While we are at it: ``for (T container=foo(); auto elem:
       container) {...}`` (see `here
       <https://en.cppreference.com/w/cpp/language/range-for>`__)
     * 
     * 
   * * ``if`` temporary variable
     * While we are at it: ``if (auto result=foo()) {...}``
       (|longrightarrow| ``std::optional<>``). This does not belong
       here, but it serves a similar purpose.
     * 
     *

auto Type Declarations
......................

* Material:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/020-auto-type-declaration/topic`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
     * Link
     * Done
   * * Discussion: readability, compiler errors
     * Bring live hacking examples accordingly
     * 
     * 
   * * Function return-type deduction
     * While we are at it: `Function return-type deduction
       <https://en.cppreference.com/w/cpp/language/function#Return_type_deduction>`__
     *
     *

Things That Simply Deserved Fixing Since Ages
---------------------------------------------

Brace Initialization
....................

* Material:
  :doc:`/trainings/material/soup/cxx11/020-new-language-features/030-brace-initialization/topic`

New OO keywords: override, final, default, delete
.................................................

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
     * Link
     * Done
   * * Slide material
     * Specification, short examples, and links
     * 
     *

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

Smart Pointers
--------------

* Material: :doc:`/trainings/material/soup/cxx11/030-smart-pointers/group`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
     * Link
     * Done
   * * Live hacking: ``unique_ptr<>``
     * Make a point in *explicit ownership transfer rules* (thereby
       whetting the appetite for the rather involved "RValue
       References" below)

       * Show how the compiler helps you in ownership transfer
	 (provided that error messages are understood)
       * Introduce ``std::move<>``
     *
     * x
   * * Live hacking: ``shared_ptr<>``
     * * Point is: *very decadent* (like Java, Python, ...)
       * But no-one helps you with reference cycles
     * 
     * x
   * * Live hacking: ``std::weak_ptr<>``
     * Slide material
     *
     * 
   * * Interface tables
     * 
     *
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
     * Link
     * Done
   * * Live hacking
     * * Cite ``std::auto_ptr<>`` from C++03; show possible
         implementation for-the-poor
       * Use ``&&`` to implement unique_ptr for-the-poor
     * 
     *
   * * Rules
     * * A move constructor for a class X is implicitly declared as defaulted exactly when

         * X does not have a user-declared copy constructor,
         * X does not have a user-declared copy assignment operator,
         * X does not have a user-declared move assignment operator,
         * X does not have a user-declared destructor, and
         * the move constructor would not be implicitly defined as deleted.

	 https://stackoverflow.com/questions/8283589/are-move-constructors-produced-automatically

     *
     *

Functions (``std::bind<>``, ``std::function<>``, Lambdas)
---------------------------------------------------------

* Material:
  :doc:`/trainings/material/soup/cxx11/040-bind-function/group`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
     * Link
     * Done
   * * Live Hacking: ``bind<>`` and ``function<>``
     * * Highlight difference between bind and function
         (single-purpose-but-efficient vs. polymorphic)
       * Show how to use Lambda as ``std::function`` replacement
         (gently introducing lambdas)
     *
     *
   * * Lambda slide material
     * Slide material: capture syntax, with examples. Cover extensions
       >11

       * https://en.wikipedia.org/wiki/C%2B%2B14#Lambda_capture_expressions
     * 
     *
   * * Live hacking: what is lambda?
     * * Problem: a class with members and a function call operator
         |longrightarrow| tedious
       * Solution: Lambda
     * 
     *
   * * Live hacking: capture by reference
     * * Capture by reference leads to dead references sooner or later
       * |longrightarrow| show how valgrind can detect such errors
	 (:doc:`valgrind
	 </trainings/material/soup/c/090-program-sanity/080-valgrind/topic>`)
     *
     *

Multithreading
--------------

* Material: :doc:`/trainings/material/soup/cxx11/050-multithreading/group`

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
     * Link
     * Done
   * * Discussion: Thread Objects
     * * Ctor starts code in thread -> plain function, std::function,
         lambda
       * No copy, only move (obviously)
       * ``join()``, ``detach()``: terminating before join? live hack
         that!
     * 
     * 
   * * Add scoped locking to :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/mutex`
     * * ``unique_lock`` (see-also condvar)
       * ``lock_guard``
     * 
     * 
   * * :doc:`/trainings/material/soup/cxx11/050-multithreading/040-locking-atomics/atomics`:
       add ``struct``
     * 
     * 
     * 
   * * Add literals to
       :doc:`/trainings/material/soup/cxx11/100-miscellaneous/010-chrono/topic`
     * ... and a "See also" to a literals live hackery
     * 
     * 
   * * Memory Model
     * See for example the unlocked ``answer``, ``answer_valid`` story
     *
     *
   * * Live hacking: :doc:`condition variables
       </trainings/material/soup/cxx11/050-multithreading/condition-variable>`
     * * implement queue
       * discuss wakeup latency
       * discuss realtime
     *
     *
   * * Semaphores (since 20)
     * * Distill from `semaphore <https://en.cppreference.com/w/cpp/thread/counting_semaphore>`__
       * Add "see-also"
	 :doc:`/trainings/material/soup/cxx11/050-multithreading/promise-future`
       * Add "see-also"
	 :doc:`/trainings/material/soup/cxx11/050-multithreading/condition-variable`
     * 
     * 

Exercise
--------

**TODO**

.. list-table::
   :align: left
   :widths: auto
   :header-rows: 1

   * * Topic
     * Description
     * Link
     * Done
   * * Larger exercise
     * Ideally split across topic covered so far

       * Multithreading
       * A ``std::map<>`` |longrightarrow| *range based for* with
	 *structured binding*, and much *auto*
       * Lambdas. distill something out of a larger set of measurement
         data, for example
       * ``promise<>/future<>`` to wait for the computation result

     * 
     *

Optional: Libraries, and Minor Language Features
------------------------------------------------

* new containers and algorithms (next to beginning somewhere)
* ``std::any<>``, ``std::optional<>``, ``std::variant<>``
* `File system library
  <https://en.cppreference.com/w/cpp/filesystem>`__
* :doc:`/trainings/material/soup/cxx11/100-miscellaneous/010-chrono/topic`

  * how to sleep

* `Regular expression library <https://en.cppreference.com/w/cpp/regex>`__

  * |longrightarrow| `(Raw) string literal
    <https://en.cppreference.com/w/cpp/language/string_literal>`__

* Raw Strings?

  * regex library excursion
  * python example
  * c++ example

* ``constexpr``, ``constexpr if`` (since C++17)

Important, To Be Done
---------------------

* vector emplace_back ...
* ``std::forward``
* ``std::array``
* std::ref, std::cref:
  https://stackoverflow.com/questions/11833070/when-is-the-use-of-stdref-necessary
