.. include:: <mmlalias.txt>


C++ Courses: To Do List
=======================

* :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`: 
  bring ``swap()`` example from livehacking
* Write down ``const`` exercise ``User``: how to transform pointers
  into references.

STL, Containers and Algorithms
------------------------------

* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/string.cpp

Algorithms
..........

* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/copy.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/binary_search.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/find.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/find_if.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/find_if-functor.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/for_each-functor.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/sort.cpp


Containers
..........

* ``std::vector<>``:
  https://github.com/jfasch/2021-12-06/blob/main/live-hacking/vector.cpp
* ``std::map<>``:
  https://github.com/jfasch/2021-12-06/blob/main/live-hacking/map.cpp

Exercise: Reverse a String
..........................

* Naive. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/reverse-string-naive.cpp
* ``std::reverse<>``
  (in-place). https://github.com/jfasch/2021-12-06/blob/main/live-hacking/reverse-string-reverse.cpp
* ``std::reverse_copy`` - DOES NOT
  ALLOCATE!. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/reverse-string-reverse-copy.cpp

Operator Overloading
--------------------

Using ``class Point``

* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/operator-overloading.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/ostream-operator.cpp

Templates/Overloading
---------------------

* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/overloading-max.cpp

Exceptions
----------

* C style error handling. One return value and one output
  parameter. Ugly. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exceptions.cpp
* Only slightly better: pack both into one
  ``std::pair<>``. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exception-pair.cpp
* Throwing ``std::exception``, uncaught (|longrightarrow|
  terminates). https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exception-exc.cpp
* Handling
  ``std::exception``. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exception-handling.cpp
* Custom exceptions; order of
  handling. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/exceptions/exceptions-custom.cpp

Functors: Overloading the Function Call Operator
------------------------------------------------

(Better not use integers, better use custom class. User?)

* Function with 3 parameters: "How to order 2
  numbers". https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/calloperator-problem.cpp
* ... but want only two |longrightarrow| class with
  ``operator()()``. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/calloperator-solution.cpp
* Sort takes comparison function with two arguments. Hardcode one (and
  be hardcoded to one particular sort
  order). https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/sort-problem.cpp
* Functor given to ``std::sort<>()``:
  https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/sort-solution.cpp
* Doing all this with
  Lambda. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/functors/sort-lambda.cpp

Threads
-------

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
* Deadlock. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/deadlock.cpp

C++ >= 11
---------

* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/range-based-for.cpp
* Building a sum in 1000 different ways (from *completely old-school*
  to *range based for* to
  ``std::accumulate<>()``. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/sum-ints.cpp

  * Same with
    strings. https://github.com/jfasch/2021-12-06/blob/main/live-hacking/sum-strings.cpp

Smart Pointers
..............

* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/unique-ptr.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/shared-ptr.cpp
