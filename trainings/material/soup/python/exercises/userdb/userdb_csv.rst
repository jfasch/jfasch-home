.. ot-exercise:: python.exercises.userdb.userdb_module
   :dependencies: python.exercises.userdb.csvdictreader_function,
		  python.exercises.userdb.csvreader,
		  python.advanced.modules
		  
.. include:: <mmlalias.txt>


Exercise: Refactoring - Extract Both CSV Formats Into Module
============================================================

.. contents::
   :local:

Requirement
-----------

Create a module ``userdb_csv.py`` to be imported from whatever
program. That module will contain

* The function you created in :doc:`csvdictreader-function`; that is
  the function which reads our user database from a CSV file which has
  a header line.
* A function (to be created likewise) that reads our user database
  from header-less CSV file. Extract that function from the solution
  to :doc:`csvreader`.
* Modify both programs (``read-userdb.py`` and
  ``read-userdb-header.py``) to *import* the module, and to use the
  functions from there.

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.userdb.userdb_module
