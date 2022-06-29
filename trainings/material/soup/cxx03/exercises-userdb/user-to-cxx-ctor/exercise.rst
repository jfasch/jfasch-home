.. ot-exercise:: cxx03.exercises_userdb.user_ctor
   :dependencies: cxx03.data_encapsulation.ctor_custom,
		  cxx03.standard_library_miscellanea.string

.. include:: <mmlalias.txt>


Exercise: Transform ``struct User`` Into A Class
================================================

.. contents::
   :local:

Description
-----------

The files ``user.h`` (:download:`download <../code-userdb-c/user.h>`) and
``user.cpp`` (:download:`download <../code-userdb-c/user.cpp>`) contain
declaration and definition of ``struct User``: the structure
definition, and the implementation of the *constructor*. The structure
is written in C, in an object oriented style. Transform that
``struct`` into an equivalent C++ ``class``.

* Identify opportunities for C++ transformation

  * C++ brings ``std::string``. See `here
    <https://en.cppreference.com/w/cpp/string/basic_string>`__ for
    documentation.
  * The C function ``user_init()`` looks like a *constructor*: it
    *initializes* an object of ``struct User``.

* Copy both files into your work directory for transformation.
* Use the following main program for testing (you are free to modify
  according to you own testing wishes).

  .. literalinclude:: user-main.cpp
     :language: c++
     :caption: :download:`user-main.cpp`

* In your work directory's ``CMakeLists.txt``, add the following to
  build program ``user-main``:

  .. code-block:: console
     :caption: ``CMakeLists.txt``

     ADD_EXECUTABLE(user-main user-main.cpp user.cpp)

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.user_ctor
