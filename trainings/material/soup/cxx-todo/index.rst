.. include:: <mmlalias.txt>


C++: TODO List
==============

Structural
----------

* Move C++03 and C++11, and "C++: Miscellaneous Live-Hacking" into new
  group, "C++"
* *Depend* c++11 on c++03, topic by topic
* Bring pieces of :doc:`/trainings/material/soup/cxx/index` to where
  they belong

STL, Containers and Algorithms
------------------------------

**Misc:**

* make UserDB_Map exercise refer to
  :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/multimap`
* extract back-insert-iterator thing, and link to
  :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/copy`,
  :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/reverse_copy`

OO
--

Make an exercise out of ``UserDB``/``UserDB_Vector``/``UserDB_Map``

Operator Overloading
--------------------

Using ``class Point``

* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/operator-overloading.cpp
* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/ostream-operator.cpp

Templates/Overloading
---------------------

* https://github.com/jfasch/2021-12-06/blob/main/live-hacking/overloading-max.cpp
* `Back to Basics: Function and Class Templates - Dan Saks - CppCon
  2019 <https://www.youtube.com/watch?v=LMP_sxOaz6g&t=534s>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/LMP_sxOaz6g" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
	     allowfullscreen>
     </iframe>

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

Dependencies
............

* Introduce dependencies from C++11 into C++03 into C
* Some subgroups. For example

  * Ownership, containing

    * ``explicit``. See `here
      <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/explicit.cpp>`__
      for a live-hacked explanation.
    * :doc:`/trainings/material/soup/cxx11/smart-pointers/introduction/topic`
    * :doc:`/trainings/material/soup/cxx11/smart-pointers/uniqueptr`

      Bring `this
      <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/unique_ptr.cpp>`__
      as a screenplay.

    * :doc:`/trainings/material/soup/cxx11/smart-pointers/sharedptr`
    * :doc:`/trainings/material/soup/cxx11/smart-pointers/040-closing-words/topic`

Exercise series
...............

* point in C
* point in C++, members and ctors
* shapes, based upon point (circle, triangle, rectangle, ...)

  * access methods

* const correctness
* operator overloading

Miscellaneous
.............

* Split
  :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`
  in two.

  * Plain ctor, initializer list.
  * Exercise ``circle``, ``sphere``, ``rect`` in the middle.
  * Resource management separated, as a preparation to what follows:
    :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`

