.. ot-exercise:: cxx03.exercises_userdb.user_const
   :dependencies: cxx03.exercises_userdb.user_access_methods,
		  cxx03.functions_and_methods.const,
		  cxx03.functions_and_methods.references

.. include:: <mmlalias.txt>


Exercise: Use ``const``
=======================

.. contents::
   :local:

Description
-----------

``class User`` has several shortcomings:

* Constructor parameters are passed *by copy*
* Access methods are returned *by copy*

Modify those to use ``const`` references!

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.user_const
