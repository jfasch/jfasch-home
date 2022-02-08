.. ot-exercise:: cxx03.exercises_userdb.userdb_search
   :dependencies: cxx03.exercises_userdb.userdb_insert

.. include:: <mmlalias.txt>


Exercise: Search a User By Lastname
===================================

.. contents::
   :local:

Description
-----------

The original C implementation (:download:`download userdb.h
<../code-userdb-c/userdb.h>`, :download:`download userdb.cpp
<../code-userdb-c/userdb.cpp>` to search a user is by equality of her
*lastname*:

.. code-block:: c

   struct User* userdb_search_by_lastname(struct UserDB*, char lastname[]);

As always, in C this can be done better: in ``class UserDB``,
implement a method

.. code-block:: c++

   class UserDB
   {
   public:
       ...
       User search_by_lastname(const std::string& lastname) const;
       ...
   };

``search_by_lastname()`` returns the first user whose lastname is
``lastname``. If there are multiple users with that name, the rest
goes undetected.

Test this using the following program (feel free to use your own
version of it):

.. literalinclude:: test-userdb-search.cpp
   :caption: :download:`test-userdb-search.cpp`

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.userdb_search
