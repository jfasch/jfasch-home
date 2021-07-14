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
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/encapsulation-intro/topic`
* :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor/topic`

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

  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor/topic`
  
    The rest of it. Yesterday we only got to the plain ``point`` stuff
    where no resource management is necessary.
  
  * :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy/topic`

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

  * :doc:`/trainings/material/soup/cxx03/060-stl-containers/010-basics/topic`
  * :doc:`/trainings/material/soup/cxx03/060-stl-containers/020-sorting/topic`
  * :doc:`/trainings/material/soup/cxx03/060-stl-containers/030-searching/topic`
  * :doc:`/trainings/material/soup/cxx03/060-stl-containers/040-sequential-containers/topic`
  * :doc:`/trainings/material/soup/cxx03/060-stl-containers/050-associative-containers/topic`

Day 4
-----

* Debugging: how to, using VS Code *and* CMake
* GraphObj things, brought about by Tirol-Daniel. Polymorphism to be
  done.

  .. list-table::
     :align: left

     * *

         .. image:: wacom-sketches/graphobj-uml.png
	    :scale: 50%

     * *

         .. image:: wacom-sketches/graphobj-layout.png
	    :scale: 50%

     * *

         .. image:: wacom-sketches/graphobj-segv.png
	    :scale: 50%


Day 5
-----

Further Information
-------------------

TODO
----

* Add wacom sketches to slide material

  * Linear address space ->
    :doc:`/trainings/material/soup/c/050-pointers-and-arrays/010-pointers-and-addresses/topic`

    .. image:: wacom-sketches/addrspace.png
       :scale: 30%

  * Call by reference ->
    :doc:`/trainings/material/soup/c/060-structures/020-structures-and-functions/topic`

    .. image:: wacom-sketches/call-by-reference.png
       :scale: 30%

* Split
  :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor/topic`
  in two.

  * Plain ctor, initializer list.
  * Exercise ``circle``, ``sphere``, ``rect`` in the middle.
  * Resource management separated, as a preparation to what follows:
    :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy/topic`

* Exercise series

  * point in C
  * point in C++, members and ctors
  * shapes, based upon point (circle, triangle, rectangle, ...)

    * access methods

  * const correctness
  * operator overloading
