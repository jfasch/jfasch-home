.. ot-exercise:: cxx03.exercises_misc.passwd_parser
   :dependencies: cxx03.standard_library_miscellanea.string,
		  cxx03.exceptions.try_catch

.. include:: <mmlalias.txt>


Exercise: Parse A Line From ``/etc/passwd``
===========================================

.. contents::
   :local:

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/900-standard-library-miscellanea/string/topic`
   * :doc:`/trainings/material/soup/cxx03/040-exceptions/020-try-catch/topic`

Problem
-------

.. sidebar:: Documentation

   * `man -s 5 passwd
     <https://man7.org/linux/man-pages/man5/passwd.5.html>`__

``/etc/passwd`` contains lines of the form 

.. code-block:: text

   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

We want to parse such content conveniently in C++ [#nih]_

Requirements
------------

Library Function (``lib/parse-passwd.cpp``)
...........................................

Write a function

.. code-block:: c++

   User parse_passwd_line(std::string line);

* The parameter ``line`` is one line as read from ``/etc/passwd``
* On success, the function returns an object of type ``User``
  (definition see below)
* On failure, the function throws an exception object of type
  ``PasswdError`` (definition see below)

The header file ``lib/parse-passwd.h`` contains the type definitions
and the function declaration, the implementation file
``lib/parse-passwd.cpp`` contains only the function skeleton which
does nothing, **and which has to be implemented**.

.. important::

   ``lib/parse-passwd.cpp`` is the only file that must be modified in
   this exercise!

.. literalinclude:: code/lib/parse-passwd.h
   :caption: ``lib/parse-passwd.h`` (:download:`download
	     <code/lib/parse-passwd.h>`)
   :language: c++

Tests (``tests/suite-passwd-line.cpp``)
.......................................

The specification of the ``parse_passwd_line()`` function is in
``./tests/suite-passwd-line.cpp``. The other test suites in ``tests/``
are implementation hints (see below).

Hints
-----

How To Proceed
..............

* Comment out all tests
* Build the project
* In a top-down manner ...

  * Comment back in one test after the other
  * Fix ``parse_passwd_line()`` until the current succeeds

During the implementation of ``parse_passwd_line()`` you will need to
use

* ``User`` objects that are returned on success from the function
* ``PasswdError`` objects that are thrown as exceptions from the
  function
* Miscellaneous ``std::string`` functionality to dissect a line

``User`` Usage (``tests/suite-passwd-user.cpp``)
................................................

``parse_passwd_line()`` returns an object of type ``User``. See below
how such objects are initialized and used.

.. literalinclude:: code/tests/suite-passwd-user.cpp
   :caption: ``tests/suite-passwd-user.cpp`` (:download:`download
             <code/tests/suite-passwd-user.cpp>`)
   :language: c++

``PasswdError`` Usage (``tests/suite-passwd-error.cpp``)
........................................................

The exception type ``PasswdError`` has a nested ``enum`` type, which
is a bit hard to use for C++ beginners. See
``tests/suite-passwd-error.cpp`` for usage examples - especially how
you use the type in a ``throw`` statement.

.. literalinclude:: code/tests/suite-passwd-error.cpp
   :caption: ``tests/suite-passwd-error.cpp`` (:download:`download
             <code/tests/suite-passwd-error.cpp>`)
   :language: c++

``std::string`` Usage
.....................

.. sidebar:: See also

   * :doc:`/trainings/material/soup/cxx03/900-standard-library-miscellanea/string/topic`

.. sidebar:: Documentation

   * `std::string::find()
     <https://en.cppreference.com/w/cpp/string/basic_string/find>`__
   * `std::string::substr()
     <https://en.cppreference.com/w/cpp/string/basic_string/substr>`__
   * `std::stoi()
     <https://en.cppreference.com/w/cpp/string/basic_string/stol>`__

Dissecting lines like

.. code-block:: text

   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

will likely require the following tools.

* Searching for the field delimiter ``':'``. See `std::string::find()
  <https://en.cppreference.com/w/cpp/string/basic_string/find>`__. Take
  care of *not-found* conditions; ``s.npos`` is typically returned by
  string searches.
* Given start and end positions of a fields, you need to take a
  substring. See `std::string::substr()
  <https://en.cppreference.com/w/cpp/string/basic_string/substr>`__.
* Numeric fields (UID and GID) have to be converted from strings. See
  `std::stoi()
  <https://en.cppreference.com/w/cpp/string/basic_string/stol>`__. Don't
  forget to handle error conditions (see the example in the
  corresponding section in
  :doc:`/trainings/material/soup/cxx03/900-standard-library-miscellanea/string/topic`)

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_misc.passwd_parser

.. rubric:: Footnotes

.. [#nih] We are reinventing the wheel: such a parser exists and is
          available on every Unix system. See `man -s 3 getpwent
          <https://man7.org/linux/man-pages/man3/getpwent.3.html>`__
