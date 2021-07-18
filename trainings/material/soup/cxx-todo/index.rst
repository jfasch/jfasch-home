C++: TODO List
==============

Complete Transcription of C++11
-------------------------------

Many of the chapter from the LaTex deck haven't yet been transcribed.

Dependencies
------------

* Introduce dependencies from C++11 into C++03 into C
* Some subgroups. For example

  * Ownership, containing

    * ``explicit``. See `here
      <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/explicit.cpp>`__
      for a live-hacked explanation.
    * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/010-introduction/topic`
    * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/020-unique-ptr/topic`

      Bring `this
      <https://github.com/jfasch/2021-06-14/blob/main/live-hacking/unique_ptr.cpp>`__
      as a screenplay.

    * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/030-shared-ptr/topic`
    * :doc:`/trainings/material/soup/cxx11/030-smart-pointers/040-closing-words/topic`

Exercise series
---------------

* point in C
* point in C++, members and ctors
* shapes, based upon point (circle, triangle, rectangle, ...)

  * access methods

* const correctness
* operator overloading

Miscellaneous
-------------

* Split
  :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor/topic`
  in two.

  * Plain ctor, initializer list.
  * Exercise ``circle``, ``sphere``, ``rect`` in the middle.
  * Resource management separated, as a preparation to what follows:
    :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/object-copy/topic`

