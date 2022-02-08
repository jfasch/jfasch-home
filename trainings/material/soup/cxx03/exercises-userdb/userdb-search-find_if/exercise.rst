.. ot-exercise:: cxx03.exercises_userdb.userdb_search_find_if
   :dependencies: cxx03.exercises_userdb.userdb_search		  

.. include:: <mmlalias.txt>


Exercise: Search a User By Lastname (``std::find_if``)
======================================================

.. contents::
   :local:

Description
-----------

In the previous exercise, :doc:`../userdb-search/exercise`, we used
the original (C) search implementation, which has a number of
shortcomings,

* uses a manual loop over the C array
* is not quite readable

Fix that, and replace the manual search code with ``std::find_if`` to
do the same.

.. sidebar::

   See `here <http://cplusplus.com/reference/algorithm/find_if/>`__
   for documentation on ``std::find_if``.

Testing requires no additional code (we did not change anything that
is user-visible). The test program from the previous exercise is
sufficient - if that works, our change did not break anything.

.. literalinclude:: ../userdb-search/test-userdb-search.cpp
   :caption: :download:`../userdb-search/test-userdb-search.cpp`

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_userdb.userdb_search_find_if
