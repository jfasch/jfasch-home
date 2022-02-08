.. ot-exercise:: cxx03.exercises_userdb.user_access_methods
   :dependencies: cxx03.exercises_userdb.user_simple_method,
		  cxx03.functions_and_methods.methods

.. include:: <mmlalias.txt>


Exercise: Access Methods for Members
====================================

.. contents::
   :local:

Description
-----------

In exercise :doc:`../user-simple-method/exercise`, you had to modify
``class User``: you removed the ``const`` specifier from the ``age``
member. ``age`` is still ``public``, which gives everybody permission
to write to ``age`` - not only class methods.

Introduce a ``private`` section, and put *all* (not just ``age``) into
that section. This will break all code that accesses members
directly. 

**Fix that**: introduce *access methods* for the members.

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.user_access_methods
