.. include:: <mmlalias.txt>


C/C++ Programming (2021-12-06 - 2021-12-10, 2022-01-24 - 2022-02-04)
====================================================================

.. sidebar::

   **Contents**

   .. contents::
      :local:

   **Material**

   * :doc:`Course Description </trainings/repertoire/c-like/c>`
   * :doc:`Slide Material </trainings/material/soup/c/index>`

   **Git**

   * Please create `GitHub <https://github.com/>`__ account
   * `Create access token
     <https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token>`__
   * Clone our repository (https://github.com/jfasch/2021-12-06):

     .. code-block:: console

	$ git clone https://github.com/jfasch/2021-12-06

2021-12-06
----------

* :doc:`/trainings/material/soup/c/010-introduction/000-installation/topic`
* :doc:`/trainings/material/soup/c/010-introduction/010-introduction/topic`
* :doc:`/trainings/material/soup/c/010-introduction/020-getting-started/topic`
* :doc:`/trainings/material/soup/c/010-introduction/030-variables-and-arithmetic-expressions/topic`
* Pointers, Arrays, and Commandline

  .. image:: images/argv.png
     :scale: 40%

* :doc:`/trainings/material/soup/c/010-introduction/040-exercise-fahrenheit-float/topic`
* :doc:`/trainings/material/soup/c/010-introduction/050-the-for-statement/topic`
* :doc:`/trainings/material/soup/c/010-introduction/060-exercise-fahrenheit-for/topic`

  Solutions:

  * `fahrenheit-for.c <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-for.c>`__
  * `fahrenheit-for-reverse.c <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-for-reverse.c>`__
  * `fahrenheit-for-float.cpp <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-for-float.cpp>`__

2021-12-07
----------

* :doc:`/trainings/material/soup/c/010-introduction/070-symbolic-constants/topic`
* :doc:`/trainings/material/soup/c/010-introduction/080-exercise-fahrenheit-cpp/topic`

  Solutions:
  
  * `fahrenheit-nonconst.cpp (a stupid bug) <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-nonconst.cpp>`__
  * `fahrenheit-const.cpp (using C preprocessor macros to prevent stupid bug) <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/fahrenheit-const.cpp>`__

* :doc:`/trainings/material/soup/c/010-introduction/090-character-input-and-output/topic`
* :doc:`/trainings/material/soup/c/010-introduction/100-exercise-wc/topic`
* :doc:`/trainings/material/soup/c/010-introduction/110-arrays/topic`
* :doc:`/trainings/material/soup/c/010-introduction/120-exercise-histogram/topic`

  .. image:: images/ascii-counter.png
     :scale: 40%

  * Solution: `histogram.cpp <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/histogram.cpp>`__

2021-12-08
----------

* Reiterating on
  :doc:`/trainings/material/soup/c/010-introduction/120-exercise-histogram/topic`

  * ``while ((c = getchar()) != EOF) { ... }``: assignment has a value (DRY: *don't repeat yourself*)
  * Arrays (and everything else) in C are not range checked
    |longrightarrow| input needs verification
  * How far can I write past the end of an array? |longrightarrow|
    `out-of-bounds-write.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/out-of-bounds-write.cpp>`__

    * From the histogram example: what happens if we receive an
      ``iso-8859-1`` Umlaut character, say "ö". That character is sure
      not within range ``[0,128)``.

      .. image:: images/out-of-bounds-write.png
	 :scale: 40%

    * From the smaller-scale `canary
      <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/out-of-bounds-write.cpp>`__
      example.

      .. image:: images/out-of-bounds-write-canary.png
	 :scale: 40%

  * Aside: C has no ``bool`` datatype (C++ has) |longrightarrow|
    `infinite-loop.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/infinite-loop.cpp>`__
	     
* :doc:`/trainings/material/soup/c/010-introduction/130-functions/topic`
* :doc:`/trainings/material/soup/c/010-introduction/140-exercise-power-declaration/topic`

  Solution: `power.c
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/power.c>`__

* :doc:`/trainings/material/soup/c/010-introduction/150-character-arrays/topic`

  Char array (i.e., string) walkthrough: `strings-wtf.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/strings-wtf.cpp>`__

  Massacre using ``strcpy`` ...

  .. image:: images/strcpy-massacre.png
     :scale: 40%

* :doc:`/trainings/material/soup/c/010-introduction/160-exercise-string-read-line/topic`
* :doc:`/trainings/material/soup/c/010-introduction/170-external-variables-and-scope/topic`

  Global variables: `global-vs-local.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/global-vs-local.cpp>`__

* :doc:`/trainings/material/soup/c/020-types-operators-expressions/010-introduction/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/020-variable-names/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/030-data-types-and-sizes/topic`
* :doc:`/trainings/material/soup/c/020-types-operators-expressions/080-type-conversions/topic`

  Demo code: `type-system.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/type-system.cpp>`__

  Massacre resulting from mixing signed and unsigned integers ...

  .. image:: images/signed-unsigned-massacre.png
     :scale: 40%

* :doc:`/trainings/material/soup/c/050-pointers-and-arrays/index`

  * :doc:`/trainings/material/soup/c/050-pointers-and-arrays/010-pointers-and-addresses/topic`
  
    * `pointer-basics.cpp
      <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/pointer-basics.cpp>`__
    * `pointer-brainfuck.cpp
      <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/pointer-brainfuck.cpp>`__
  
  * :doc:`/trainings/material/soup/c/050-pointers-and-arrays/030-exercise-swap/topic`
  
    * Fix that to actually swap the *caller's* variables:
      `swap-nok.cpp
      <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/swap-nok.cpp>`__

2021-12-09
----------

* Morning wakeup, talking about what happened, questions

  * Reiterate on `canary
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/out-of-bounds-write.cpp>`__
    and memory errors in general. Security holes, blah, blah. C is the
    root of all evil.
  
    .. image:: images/out-of-bounds-write-canary.png
       :scale: 40%

  * ``argv``; that double pointer thing.

    Compose an array like ``argv`` manually (`argv-manually.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/argv-manually.cpp>`__)

    .. image:: images/argv-manual.png
       :scale: 40%

  * Double pointers, generally

    `double-pointer.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/double-pointer.cpp>`__

    .. image:: images/pointer-pointer.png
       :scale: 40%

  * Pointer arithmetic, killing canaries sitting in a row next to an
    integer

    .. image:: images/pointer-arith.png
       :scale: 40%

  * The same can happen to a function's return address

    .. image:: images/return-address-massacre.png
       :scale: 40%

  * Useful use of pointers: singly linked list

    .. image:: images/singly-linked-list.png
       :scale: 40%

* Resolve :doc:`/trainings/material/soup/c/050-pointers-and-arrays/030-exercise-swap/topic`

  * `swap-nok.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/swap-nok.cpp>`__
  * *Not* working

    .. image:: images/swap-nok.png
       :scale: 40%

  * Working

    .. image:: images/swap-ok.png
       :scale: 40%

* Continuing with :doc:`/trainings/material/soup/c/050-pointers-and-arrays/index`

  * :doc:`/trainings/material/soup/c/050-pointers-and-arrays/040-pointers-and-arrays/topic`
  * :doc:`/trainings/material/soup/c/050-pointers-and-arrays/050-command-line-arguments/topic`

    Hack a little ``argv`` example

* :doc:`/trainings/material/soup/c/060-structures/index`

  * :doc:`/trainings/material/soup/c/060-structures/010-basics-of-structures/topic`
  * :doc:`/trainings/material/soup/c/060-structures/020-structures-and-functions/topic`
  * :doc:`/trainings/material/soup/c/060-structures/030-typedef/topic`

* :doc:`/trainings/material/soup/c/040-functions-and-program-structure/index`
* Pointer Recap: `pointer-recap.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/pointer-recap.cpp>`__

2022-01-24
----------

Undefined Behavior
..................

*Undefined behavior* ist commonplace in C. C++ takes long turns to get
undefined behavior out of the way. For example:

* Array bounds read/write

  * It is perfectly ok to read and write past the boundaries of an
    array. At least this is ok for the compiler; occasionally the
    program will exhibit *undefined behavior* - for example when you
    write into variables in the neighborhood. See
    `undefined-behavior.c
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/undefined-behavior.c>`__.
  * C++ brings data structures like ``std::vector`` that can do this
    better. See `undefined-behavior-c++.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/undefined-behavior-c%2B%2B.cpp>`__.

* Integer overflow bugs are the norm - happily mix signedness and
  unsignedness, happily mix various integer widths. See
  `overflow-recap.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/overflow-recap.cpp>`__.

* Structures (``struct``) recap; `struct-recap.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/struct-recap.cpp>`__,
  again with an array bounds write.
* Pointers recap; `pointer-recap-recap.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/pointer-recap-recap.cpp>`__.
* Functions recap; `power-recap.c
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/power-recap.c>`__.

Modularization
..............

* What's that *separate compilation unit* thing? How do we use the C
  preprocessor? *Dogmatically introducing include guards!*

  * :doc:`/trainings/material/soup/c/040-functions-and-program-structure/010-basics-of-functions/topic`
  * :doc:`/trainings/material/soup/c/040-functions-and-program-structure/020-external-variables/topic`
  * :doc:`/trainings/material/soup/c/040-functions-and-program-structure/030-header-files/topic`

  See an example (in C, largely) `here
  <https://github.com/jfasch/2021-12-06/tree/main/userdb>`__.

2022-01-25
----------

C++ and OO (Classes)
....................

* :doc:`/trainings/material/soup/cxx03/001-introduction/topic`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-default`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-custom`

  * :doc:`/trainings/material/soup/cxx03/exercises-userdb/user-to-cxx-ctor/exercise`

Modularization (again)
......................

* :doc:`/trainings/material/soup/c/040-functions-and-program-structure/040-static-variables/topic`

  Livehacking this: 

  * `One file <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/lifetime-visibility.cpp>`__
  * `Another file <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/second-accessor.cpp>`__

2022-01-26
----------

Modularization: Repeating Important Topics (Quickly)
....................................................

* :doc:`/trainings/material/soup/c/040-functions-and-program-structure/020-external-variables/topic`
* :doc:`/trainings/material/soup/c/040-functions-and-program-structure/030-header-files/topic`
* :doc:`/trainings/material/soup/c/040-functions-and-program-structure/050-c-preprocessor/topic`
* :doc:`/trainings/material/soup/c/040-functions-and-program-structure/060-c-preprocessor-advanced/topic`

  Livehacking: `Solving the problem (duplicate includes) step by step:
  include guards
  <https://github.com/jfasch/2021-12-06/tree/main/live-hacking/c-preprocessor>`__

Classes (continued)
...................

* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`

  * Livehacking: `Writing a string class by hand: resource management
    and copy
    <https://github.com/jfasch/2021-12-06/tree/main/live-hacking/mystring>`__
    
  
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/010-overloading/topic`

  Livehacking:

  * `Overloading the max() function
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/overloading-max.cpp>`__
  * `Using std::string's overloaded comparison operators
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/string.cpp>`__
  * `Explaining "immediate if"
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/iif.cpp>`__

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`

  * :doc:`/trainings/material/soup/cxx03/exercises-userdb/user-simple-method/exercise`

2022-01-27
----------

* Good-morning-exercise:
  :doc:`/trainings/material/soup/cxx03/exercises-userdb/user-access-methods/exercise`

  (See
  :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
  for ``private`` and *access methods*)

  Solution see `here
  <https://github.com/jfasch/2021-12-06/tree/main/exercises/joerg/userdb>`__

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`

  Livehacking

  * ``const`` in ol' C: `const-c.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/const-c.cpp>`__
  * ``const`` in C++: `const-cpp.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/const-cpp.cpp>`__

  Exercise

  * :doc:`/trainings/material/soup/cxx03/exercises-userdb/user-const/exercise`

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/040-this/topic`
* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`

  Livehacking: excursion, back to *parameter passing*

  * ``swap()``, revisited using references instead of pointers:
    `parameter-passing.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/parameter-passing.cpp>`__
  * Using ``const`` with ``struct`` types:
    `parameter-passing-struct.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/parameter-passing-struct.cpp>`__

  .. image:: pass-by-reference.png
     :scale: 40%
  
* `Temporaries
  <https://stackoverflow.com/questions/15130338/what-are-c-temporaries>`__,
  by example. See `live-hacking/mystring/temporary.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/mystring/temporary.cpp>`__.

2022-01-28
----------

* :doc:`/trainings/material/soup/cxx03/exercises-userdb/user-default-ctor/exercise`

Standard Template Library: Container Templates
..............................................

* :doc:`/trainings/material/soup/cxx03/060-stl/010-basics/topic`

  Livehacking: pointer arithmetic, using a C array of ``struct User``:
  `user-pointerarith.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/userdb/user-pointerarith.cpp>`__

* :doc:`/trainings/material/soup/cxx03/exercises-userdb/userdb-vector/exercise`
* :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/sort`
* :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/binary_search`
* :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/lower_bound`
* :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/index`

2022-01-31
----------

* :doc:`/trainings/material/soup/cxx03/exercises-userdb/userdb-insert/exercise`
* :doc:`/trainings/material/soup/cxx03/exercises-userdb/userdb-search/exercise`

2022-02-01
----------

Algorithms
..........

* ``std::copy``; `copy.cpp <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/copy.cpp>`__

  .. image:: images/binary-search.png
     :scale: 40%
  
* ``std::find``;  `find.cpp <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/find.cpp>`__
* ``std::find_if``; `find_if.cpp <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/find_if.cpp>`__
* ``std::sort``; `sort.cpp <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/sort.cpp>`__
* ``std::binary_search``; `binary_search.cpp <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/binary_search.cpp>`__

  .. image:: images/binary-search.png
     :scale: 40%

Functors
........

* Using ``std::for_each``; `for_each-functor.cpp <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/for_each-functor.cpp>`__
* Using ``std::find_if``; `find_if-functor.cpp <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/find_if-functor.cpp>`__

Operator Overloading
....................

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`
* Live-hacking: `operator-overloading.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/operator-overloading.cpp>`__

Unified Modeling Language (UML)
...............................

`Wikipedia
<https://en.wikipedia.org/wiki/Unified_Modeling_Language>`__

* UML class diagrams

  .. image:: images/uml-class.png
     :scale: 40%

* UML sequence diagrams

  .. image:: images/uml-sequence.png
     :scale: 40%
  
Exercise (Using All From Today)
...............................

* :doc:`/trainings/material/soup/cxx03/exercises-userdb/userdb-search-find_if/exercise`

  For those who chose to return a pointer from
  ``UserDB::search_by_lastname()`` ... this is how to convert a
  ``const_iterator`` to a pointer:

  .. image:: images/iterator-2-pointer.png
     :scale: 40%

2022-02-02
----------

* Resolve exercise from yesterday

Associative Container: ``std::map``
...................................

* Functors: overloading ``operator()()``

  * *Binary function*: ``bool operator(l, r)``, as required for
    example by `std::sort
    <https://www.cplusplus.com/reference/algorithm/sort>`__

    * Problem: `calloperator-problem.cpp
      <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/calloperator-problem.cpp>`__
    * Solution: `calloperator-solution.cpp
      <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/calloperator-solution.cpp>`__

  * ``std::sort<>()``, the problem: using a binary *function*:
    `sort-problem.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/sort-problem.cpp>`__
  * Solution: write a *functor class* (still not pretty, too much
    coding): `sort-solution.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/sort-solution.cpp>`__
  * Introducing *Lambda*: `sort-lambda.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/sort-lambda.cpp>`__

* :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/index`

  Not much in there though |longrightarrow| live hacking

Exceptions, and Exception Handling
..................................

* :doc:`/trainings/material/soup/cxx03/040-exceptions/010-basics/topic`
* :doc:`/trainings/material/soup/cxx03/040-exceptions/020-try-catch/topic`
* :doc:`/trainings/material/soup/cxx03/exercises-userdb/userdb-search-notfound-exception/exercise`
* Livehacking

  * Original problem: clumsy (but comprehensive) C-style error
    handling (using a return value to transport the error, and an
    "output parameter" for the actual result). `exceptions.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exceptions.cpp>`__
  * Only slightly better: using ``std::pair<>`` to transport both
    error and result as return value. `exception-pair.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exception-pair.cpp>`__
  * Throwing ``std::exception`` (and not catching
    it). `exception-exc.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exception-exc.cpp>`__
  * Catching ``std::exception``. `exception-handling.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exception-handling.cpp>`__
  * Replacing ``std::exception`` with a custom
    exception. `exceptions-custom.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exceptions-custom.cpp>`__

2022-02-03
----------

* ``operator<<(std::ostream&)``: how to, using (again) ``class
  Point``: `live-hacking/ostream-operator.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/ostream-operator.cpp>`__

* :doc:`/trainings/material/soup/cxx03/exercises-misc/american-flag/exercise`

  One possible solution, `american-flag.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/american-flag.cpp>`__. Slightly
  over-engineered, to show how you write your own ``operator<<()``.

* :doc:`/trainings/material/soup/cxx03/060-stl/exercises/reverse-string/exercise`

  Solution alternatives:

  * Manual, index-based iteration, naively using
    ``string::operator+=()``: `reverse-string-naive.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/reverse-string-naive.cpp>`__
  * In-place modification using ``std::reverse<>()``:
    `reverse-string-reverse.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/reverse-string-reverse.cpp>`__
  * ``std::reverse_copy<>()``: `reverse-string-reverse-copy.cpp
    <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/reverse-string-reverse-copy.cpp>`__

* :doc:`/trainings/material/soup/cxx03/exercises-misc/sum-integers-from-stdin/exercise`

  Solution (a history of iteration in C++, to the point where we do
  not iterate but use std::accumulate<>() instead): `sum-ints.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/sum-ints.cpp>`__

* Exit status again: `live-hacking/exit-status.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exit-status.cpp>`__

* Explaining libraries, and how they are created with CMake:
  `exercises/joerg/userdb/CMakeLists.txt
  <https://github.com/jfasch/2021-12-06/blob/main/exercises/joerg/userdb/CMakeLists.txt>`__

2022-02-04
----------

C++11: A New Language
.....................

* :doc:`/trainings/material/soup/cxx11/020-new-language-features/index`

Dynamic Allocation, Smart Pointers
..................................

* Dynamic memory allocation
* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/index`

Multithreading
..............

* :doc:`/trainings/material/soup/cxx11/050-multithreading/index`
* :doc:`/trainings/material/soup/linux/sysprog/posix-threads/040-mutex/topic`

Live hacked:

* Basics: `thread-basics.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/thread-basics.cpp>`__
* Start parameters: `thread-with-start-parameters.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/thread-with-start-parameters.cpp>`__
* Lost increment (aka "Mother of All Race Conditions"):
  `thread-lost-increment.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/thread-lost-increment.cpp>`__
* Using a mutex ("toilet door lock"):
  `thread-no-lost-increment-mutex.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/thread-no-lost-increment-mutex.cpp>`__
* Same, but encapsulating the racy integer together with a mutex in a
  class that behaves like an integer:
  `thread-no-lost-increment-mutex-beautiful.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/thread-no-lost-increment-mutex-beautiful.cpp>`__
* For integers, though, there is a better way to safety - *atomics*:
  `thread-no-lost-increment-atomic-fast.cpp
  <https://github.com/jfasch/2021-12-06/blob/main/live-hacking/thread-no-lost-increment-atomic-fast.cpp>`__

2022-02-07: Start of Exercise Week
----------------------------------

* Moving to Linux: `WSL2
  <https://docs.microsoft.com/en-us/windows/wsl/install>`__
* Install prerequisites

  .. code-block:: console

     $ sudo apt install cmake build-essential libsqlite3-dev libboost-all-dev libgtk-3-dev

* Unit testing framework documentation: `Boost Test Library: The Unit
  Test Framework
  <https://www.boost.org/doc/libs/1_43_0/libs/test/doc/html/utf.html>`__
* ``class UserDB`` is now an *interface*

  .. image:: images/userdb-iface.png
     :scale: 40%

* Into the wild ...

  * Requirements not defined in prosaic words anymore: *test driven
    development*
  * Roman going mad: using `wxWidgets <https://www.wxwidgets.org/>`__
    to build a GUI on top of our user database
  * ...
