.. include:: <mmlalias.txt>


Exercise: Insert a User into UserDB
===================================

.. contents::
   :local:

Description
-----------

The original C implementation to insert a User into the database is
declared as follows,

.. code-block:: c

   void userdb_insert(struct UserDB* userdb, struct User*);

In C, This is as pretty as it can get. In C++, we can do better.

In ``class UserDB``, implement a method

.. code-block:: c++

   class UserDB
   {
   public:
       ...
       void insert(const User& user);
       ...
   };

That method simply *appends* ``user`` to the ``std::vector`` that we
created in :doc:`../userdb-vector/exercise`.

Test this using the following program (feel free to use your own
version of it):

.. literalinclude:: test-userdb-insert.cpp
   :caption: :download:`test-userdb-insert.cpp`
