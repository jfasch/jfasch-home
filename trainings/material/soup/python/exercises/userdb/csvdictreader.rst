.. include:: <mmlalias.txt>


Exercise: Read CSV File (``csv.dictreader``)
============================================

Requirement
-----------

As a followup to :doc:`csvreader`, use the following table
(:download:`download CSV <Users-header-cp1252.csv>`) to read the user
records from.

.. csv-table:: :download:`Users-header-cp1252.csv`
   :align: left
   :file: Users-header-cp1252.csv
   :header-rows: 1
   :delim: ;
   :encoding: cp1252

Write a program ``read-userdb-header.py`` that reads that file row by
row (use Python's `csv.dictreader
<https://docs.python.org/3/library/csv.html>`__), and outputs the
*user records* like follows.

.. code-block:: console

   $ python read-userdb-header.py Users-header-cp1252.csv 
   ID:1, Firstname:Jörg;DI, Lastname:Faschingbauer, Date of birth: 19.6.1966
   ID:2, Firstname:Caro, Lastname:Faschingbauer, Date of birth: 25.4.1997
   ID:3, Firstname:Johanna, Lastname:Faschingbauer, Date of birth: 11.6.1995
   ID:4, Firstname:Philipp, Lastname:Lichtenberger, Date of birth: 6.4.1986
   ID:5, Firstname:Elizabeth II, Lastname:Queen, Date of birth: 1.1.1900

.. note:: 

   Btw, like in :doc:`csvreader`, the CSV file is encoded in
   ``cp1252``.
