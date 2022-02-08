.. ot-exercise:: cxx03.exercises_userdb.userdb_vector_basic
   :dependencies: cxx03.exercises_userdb.user_default_ctor,
		  cxx03.stl.basics

.. include:: <mmlalias.txt>


Exercise: Use std::vector in UserDB
===================================

.. contents::
   :local:

Description
-----------

The original C implementation of our sophisticated user database is in
``userdb.h`` (:download:`download <../code-userdb-c/userdb.h>`)
``userdb.cpp`` (:download:`download <../code-userdb-c/userdb.cpp>`). It has
a number of shortcomings.

* Can contain only a maximum number of 10 users - *it has a C array of
  struct User* whose size happens to be 10.
* There is a ``userdb_init()`` function which must be called in order
  to initialize it properly.

Reimplement that ``struct UserDB`` as ``class UserDB``, as follows:

* The class uses a ``std::vector<User>`` instead of the plain old C
  array
* The class has a default constructor

In a test program (call it, say, ``userdb-main.cpp``, see below),
instantiate an object of ``class UserDB``. This is only to test that
all is implemented properly; we will implement the remaining methods
in a moment.

.. literalinclude:: userdb-main.cpp
   :caption: :download:`userdb-main.cpp`

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.userdb_vector_basic
