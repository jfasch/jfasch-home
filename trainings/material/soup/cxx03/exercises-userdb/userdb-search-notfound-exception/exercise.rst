.. ot-exercise:: cxx03.exercises_userdb.userdb_search_notfound_exception
   :dependencies: cxx03.exercises_userdb.userdb_search_find_if,
		  cxx03.exceptions.try_catch

.. include:: <mmlalias.txt>


Exercise: Search, "User Not Found" Exception
============================================

.. contents::
   :local:

What's Wrong?
-------------

In
:doc:`/trainings/material/soup/cxx03/exercises-userdb/userdb-search/exercise`
we chose to implement the ``UserDB::search_by_lastname()`` method to
return an instance of ``User``,

.. code-block:: c++

   class UserDB
   {
   public:
       ...
       User search_by_lastname(const std::string& lastname) const;
       ...
   };

This leads to unnatural coding in the *not-found* case: an
empty/invalid user has to be returned:

.. code-block:: c++

   User UserDB::search_by_lastname(const std::string& lastname) const
   {
       for (size_t i=0; i<_users.size(); i++)
           if (_users[i].lastname() == lastname)
               return _users[i];    // ok, we have something that we can return
   
       return User();    // unnatural: what user is that?
   }

*Why is that unnatural?*

* I only want to give something that I own. If that was possible, I
  could return a ``const User&`` instead of a fat copy of something
  that I artificially create (and destroy soon thereafter).
* If the caller wants to differentiate between "found" and "not found"
  (occasionally callers exhibit such desires), currently this has to
  be done by checking the validity of the returned object (using
  wrinkles such as ``User::isvalid()``):

  .. code-block:: c++

     User user = db.search_by_lastname("Faschingbauer");
     if (user.isvalid()) {
         // do something with it
     }
     else {
         // error handling, possibly
     }

Exercise
--------

* Create a new file, ``errors.h`` (which will hold all future
  *exception* classes).
* In that file, implement (inline only) a custom exception, ``class UserNotFound`` (see
  :doc:`here
  </trainings/material/soup/cxx03/040-exceptions/020-try-catch/topic>`
  for how to create a custom exception).
* Modify ``UserDB::search_by_lastname()`` to throw an instance of it
  in the not-found case.
* Test this using the program below (feel free to use your own version
  of it):

.. literalinclude:: test-userdb-search-notfound.cpp
   :caption: :download:`test-userdb-search-notfound.cpp`

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.userdb_search_notfound_exception
