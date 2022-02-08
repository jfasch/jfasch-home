.. ot-exercise:: cxx03.exercises_userdb.user_default_ctor
   :dependencies: cxx03.exercises_userdb.user_const,
		  cxx03.data_encapsulation.ctor_dtor

.. include:: <mmlalias.txt>


Exercise: Default Constructor (was: Arrays of Objects)
======================================================

.. contents::
   :local:

Description
-----------

Download and (try to) compile the following code:

.. literalinclude:: user-array.cpp
   :caption: :download:`user-array.cpp`

Does it work? (No)

C++, when arrays of objects (i.e. *instances of classes*) are created,
the array members must be *initialized* |longrightarrow| their
constructors are called.

*Solution*: add a default constructor to ``class User``

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.user_const
