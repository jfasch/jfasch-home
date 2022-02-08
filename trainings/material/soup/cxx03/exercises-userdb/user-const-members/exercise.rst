.. ot-exercise:: cxx03.exercises_userdb.user_const_members
   :dependencies: cxx03.exercises_userdb.user_ctor,
		  cxx03.data_encapsulation.ctor_dtor

.. include:: <mmlalias.txt>


Exercise: ``const`` Members
===========================

.. contents::
   :local:

Description
-----------

``class User`` has public members ``age``, ``firstname``, and
``lastname``. Everyone can read them which is ok architectonically
(the class has no secrets, and it is only there to hold these data.

What's not ok, architectonically, is that everyone is allowed to
overwrite any of the members.

* Use the ``const`` keyword to make ``age``, ``firstname``, and
  ``lastname`` *read-only*.
* Try to compile - this will fail.
* Try to understand the compiler's error messages (many). Hint: what
  it tries to say is that you have to *initialize* the members, rather
  than *assign* to them.
* |longrightarrow| use an *initializer list* (see
  :doc:`/trainings/material/soup/cxx03/020-data-encapsulation/ctor-dtor/topic`)

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.user_const_members
