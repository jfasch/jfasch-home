.. include:: <mmlalias.txt>

The C++ Programming Language (2021-07-12 - 2021-07-16)
======================================================

.. sidebar:: *Training Information*

   **Course Description**

   `tecTrain
   <https://www.tectrain.at/seminare/seminar-themen/programmierung/c-grundlagen>`__

   **Material**

   .. list-table::
      :align: left
      :header-rows: 1
      :stub-columns: 1

      * *
	* Slides
	* OpenTraining
      * * C
	* :download:`C </trainings/material/pdf/050-c.pdf>`
	* :doc:`/trainings/material/soup/c/group`
      * * C++03
	* :download:`C++03 </trainings/material/pdf/055-c++03.pdf>`
	* :doc:`/trainings/material/soup/cxx03/group`
      * * C++11
	* :download:`C++11 </trainings/material/pdf/056-c++11.pdf>`
	* :doc:`/trainings/material/soup/cxx11/group`
      * * CMake
	* :download:`CMake </trainings/material/pdf/045-cmake.pdf>`
	*
      * * Make
	* :download:`Make </trainings/material/pdf/040-gnu-make.pdf>`
	*
      * * Design Patterns
	* :download:`Design Patterns </trainings/material/pdf/060-design-patterns-unittests.pdf>`
	*

   **Code**

   `Github Repository <https://github.com/jfasch/2021-06-14>`__

.. contents::
   :local:

Day 1
-----

Setup for the new kids
......................

* `C/C++ for Visual Studio Code <https://code.visualstudio.com/docs/languages/cpp>`__
* `Get started with CMake Tools on Linux
  <https://code.visualstudio.com/docs/cpp/cmake-linux>`__
* `CMake download <https://cmake.org/download/>`__

Recapitulate some C
...................

* :doc:`/trainings/material/soup/c/060-structures/010-basics-of-structures/topic`
* :doc:`/trainings/material/soup/c/060-structures/020-structures-and-functions/topic`
* :doc:`/trainings/material/soup/c/090-program-sanity/030-discrete-values/topic`
* :doc:`/trainings/material/soup/c/050-pointers-and-arrays/010-pointers-and-addresses/topic`

  * Daniel:

    * Question: so I could store the address of an integer in an
      integer?
    * Answer: the C compiler would let you (if he's nice he can issue
      a warning), but this is not what you want. Because you'd lose
      half of the 64-bit pointer value when you store it in a (32-bit)
      integer.

    `daniels-frage.c <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/daniels-frage.c>`__

* :doc:`/trainings/material/soup/c/050-pointers-and-arrays/020-pointers-and-function-arguments/topic`
* :doc:`/trainings/material/soup/c/050-pointers-and-arrays/040-pointers-and-arrays/topic`

`Group project <https://github.com/jfasch/2021-06-14>`__ review
...............................................................

* `Basis: db.h <https://github.com/jfasch/2021-06-14/blob/main/group-project/db.h>`__
* External (non-builtin) functionality: CSV export

  * `csv.h <https://github.com/jfasch/2021-06-14/blob/main/group-project/csv.h>`__
  * `Program: csv-export.c
    <https://github.com/jfasch/2021-06-14/blob/main/group-project/csv-export.c>`__

* Bleeding edge base functionality: `Search by lastname
  <https://github.com/jfasch/2021-06-14/blob/main/group-project/julia.h>`__

Jump into C++
.............

* :doc:`/trainings/material/soup/cxx03/001-introduction/topic`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/cpp-introduction`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`

Exercise
........

On Github, there is a directory `OO-Point
<https://github.com/jfasch/2021-06-14/tree/main/OO-Point>`__. Starting
from the ``point`` implementation, write comparable classes

* ``circle``, containing a method ``circle::area()``
* ``rect``, also containing a method ``circle::area()``
* ``sphere`` (in 2D :-) ), also containing a method ``circle::area()``

Make the associated test programs run:

* `circle-test.cpp
  <https://github.com/jfasch/2021-06-14/blob/main/OO-Point/circle-test.cpp>`__
* `rect-test.cpp
  <https://github.com/jfasch/2021-06-14/blob/main/OO-Point/rect-test.cpp>`__
* `sphere-test.cpp
  <https://github.com/jfasch/2021-06-14/blob/main/OO-Point/sphere-test.cpp>`__

run.

Day 2
-----

Regular Topics
..............

* Preprocessor, to clear up Julia's *include guard* question. Sigh.

  * :doc:`/trainings/material/soup/c/040-functions-and-program-structure/050-c-preprocessor/topic`
  * Only as a reference in case somebody needs token pasting and such:
    :doc:`/trainings/material/soup/c/040-functions-and-program-structure/060-c-preprocessor-advanced/topic`
  * :doc:`/trainings/material/soup/c/040-functions-and-program-structure/030-header-files/topic`

* Constructor, Destructor, Copy

  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor`
  
    The rest of it. Yesterday we only got to the plain ``point`` stuff
    where no resource management is necessary.
  
  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy`

* Functions and Methods
    
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/010-overloading/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/020-methods/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/030-const/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/040-this/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/060-static/topic`
  * :doc:`/trainings/material/soup/cxx03/030-functions-and-methods/070-operators/topic`

Exercises
.........

  * ``point::operator==()``
  * ``rect::operator+=()``
  * ``static double point::distance(const point&, const point&)``

Day 3
-----

Exercises
.........

Finish exercises from day 2

Regular Topics
..............

* Templates

  * :doc:`/trainings/material/soup/cxx03/050-templates/010-function-templates/topic`
  * :doc:`/trainings/material/soup/cxx03/050-templates/020-class-templates/topic`

* Standard Template Library: Container Templates

  * :doc:`/trainings/material/soup/cxx03/060-stl/010-basics/topic`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/sort`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/find`
  * :doc:`/trainings/material/soup/cxx03/060-stl/020-algorithm/binary_search`
  * :doc:`/trainings/material/soup/cxx03/060-stl/040-sequential-containers/group`
  * :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/group`

Toolchain: C/C++ Build (How Complicated Can Things Be?)
.......................................................

  .. list-table::
     :align: left

     * * 
         .. image:: wacom-sketches/include-graph.png
	    :scale: 50%

       * Trying to get ``#include`` dependencies right. Respectively,
         what you're up to when you want to write a ``Makefile`` (or
         more of those) :download:`by hand </trainings/material/pdf/040-gnu-make.pdf>`.

     * * 
         .. image:: wacom-sketches/toolchain-cmake.png
	    :scale: 50%

       * Using :doc:`CMake </trainings/repertoire/cmake>` to do manage
         the build. What is still left to the developer is to define "module"
         dependencies.

Exercises: Using the C++ Toolbox
................................

* Starting to morph the `"user database" from the C course
  <https://github.com/jfasch/2021-06-14/tree/main/db-c>`__ (a month
  ago) into `something more object oriented
  <https://github.com/jfasch/2021-06-14/tree/main/db-cpp>`__.

Day 4
-----

Finish First "User Database" Functionality
..........................................

* ``UserDB::has_lastname()``, using ``std::find_if()``

Unit Testing
............

Current state is, we're writing one program to test one
aspect/requirement. This is something that can be `formalized
<https://www.amazon.de/Test-Driven-Development-Example-Signature/dp/0321146530>`__
(/me big fan of things that are so simple).

Install `Google's unittesting framework (on Doze, sadly)
<https://medium.com/swlh/google-test-installation-guide-for-c-in-windows-for-visual-studio-code-2b2e66352456>`__,
and start to use it.

GTest Installation
..................

Clone `GitHub repository <https://github.com/google/googletest>`__:

.. code-block:: console

   $ git clone https://github.com/google/googletest.git

**Build**

* Build with VS Code: open directory, and hit CMake build botton
* Build by hand

.. code-block:: console

   $ cd googletest
   $ cmake .

**Install**

* Copy ``lib/*.a`` to MinGW installation ``..../lib`` directory
* Copy ``include/gtest/`` to MinGW installation ``..../include``
  directory

Git Workflows
.............

.. list-table::
   :align: left

   * * **Central workflow**. Much like SVN's, except that local
       commits are possible.

       .. image:: wacom-sketches/git-workflow-central.png
	  :scale: 50%

   * * **Distributed workflow**. (At least, one
       possibility). Resembles Github "pull requests".

       .. image:: wacom-sketches/git-workflow-distributed.png
	  :scale: 50%

Exercises
.........

* Torture them with even more requirements that they need to implement

Regular Topics
..............

* `Functors
  <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/functor.cpp>`__
* Exceptions

  * :doc:`/trainings/material/soup/cxx03/040-exceptions/010-basics/topic`
  * :doc:`/trainings/material/soup/cxx03/040-exceptions/020-try-catch/topic`

  Live-hacked, rudimentarily, into our project. See `here
  <https://github.com/jfasch/2021-06-14/blob/main/db-cpp/db-find.cpp>`__
  for the *exception handling* part.

Day 5
-----

* References recap
  (:doc:`/trainings/material/soup/cxx03/030-functions-and-methods/050-references/topic`)
* ``explicit``: another C++ trap/bug (automatic conversion), fixed by
  an ad-hoc solution - the ``explicit`` keyword, bolted onto what's
  there. `Here's
  <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/explicit.cpp>`__
  a live-hacked explanation of it.

  It has gotten a bit larger becauser I used it as an introduction to
  recource management and smart pointers.
* Pointer classes ("smart pointers")

  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`

    Although ``std::unique_ptr<>`` is the simpler of the two in what
    it does, its usage is more involved. Ownership transfer (this is
    what I like about it) is implemented using the outright genius
    :doc:`"move" mechanism (since C++11)
    </trainings/material/soup/cxx11/020-new-language-features/060-move/group>`,
    and one needs to know a bit when the compiler fails to enforce the
    ownership transfer contract.

    Live-hacked that `here
    <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/unique_ptr.cpp>`__.

  * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`

    Didn't go through it in great detail (time was over
    anyway). Shared ownership, though, is easier explained than
    *unique* ownership: "just don't think about it". (Should have
    mentioned reference cycles, to make things more complicated :-) ).

Day X
-----

Smart Pointers, Recap
.....................

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/uniqueptr`

  .. image:: wacom-sketches/ptr-unique.png
     :scale: 50%

* :doc:`/trainings/material/soup/cxx11/030-smart-pointers/sharedptr`

  .. image:: wacom-sketches/ptr-shared.png
     :scale: 50%

``std::map``
............

* :doc:`/trainings/material/soup/cxx03/060-stl/050-associative-containers/group`. Livehackingly
  building an index into our `user database <https://github.com/jfasch/2021-06-14/blob/main/db-cpp/db.hpp>`__

OO, and Polymorphism
....................

* Interface ``class shape``, `shape.h <https://github.com/jfasch/2021-06-14/blob/main/OO-Point/shape.h>`__
* Concrete implementation of that, `rect.h
  <https://github.com/jfasch/2021-06-14/blob/main/OO-Point/rect.h>`__,
  `circle.h
  <https://github.com/jfasch/2021-06-14/blob/main/OO-Point/circle.h>`__

  .. list-table::
     :align: left


     * *

         .. image:: wacom-sketches/oo-interface.png
	    :scale: 50%

     * *

         .. image:: wacom-sketches/oo-vector-of-pointer.png
	    :scale: 50%

* Composite pattern: `sketch.h <https://github.com/jfasch/2021-06-14/blob/main/OO-Point/sketch.h>`__

  .. list-table::
     :align: left


     * *

         .. image:: wacom-sketches/oo-composite-shape.png
	    :scale: 50%

     * *

         .. image:: wacom-sketches/oo-composite-shape2.png
	    :scale: 50%

     * *

         .. image:: wacom-sketches/oo-composite-objects.png
	    :scale: 50%

     * *

         .. image:: wacom-sketches/oo-composite-fs.png
	    :scale: 50%

