.. include:: <mmlalias.txt>


Exercise: Refactoring - Extract Both CSV Formats Into Module
============================================================

Requirement
-----------

Create a module ``userdb_csv.py`` to be imported from whatever
program. That module will contain

* The function you created in :doc:`csvreader-function`
  :doc:`csvdictreader-function`; that is the function which reads our
  user database from a CSV file which has a header line.
* Modify both programs (``read-userdb.py`` and
  ``read-userdb-header.py``) to *import* the module, and to use the
  functions from there.

Test Code
---------

The following test (see
:doc:`/trainings/material/soup/python/swdev/pytest/intro` for how to
use it) can better express the requirement,

.. literalinclude:: code/tests/test_read_csv.py
   :caption: :download:`code/tests/test_read_csv.py`
   :language: python
