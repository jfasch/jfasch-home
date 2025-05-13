.. include:: <mmlalias.txt>


Exercise: Read CSV File (``csv.reader``)
========================================

.. contents::
   :local:

Requirement
-----------

Use the following table (:download:`download CSV
<Users-noheader-cp1252.csv>`) as input for *user records*,

.. csv-table:: :download:`Users-noheader-cp1252.csv`
   :align: left
   :file: Users-noheader-cp1252.csv
   :delim: ;
   :encoding: cp1252

Write a program ``read-userdb-noheader.py`` that reads that file row
by row (use Python's `csv.reader
<https://docs.python.org/3/library/csv.html>`__), and outputs the
*user records* like follows.

.. code-block:: console

   $ python read-userdb-noheader.py Users-noheader-cp1252.csv 
   ID:1, Firstname:Jörg;DI, Lastname:Faschingbauer, Date of birth: 19.6.1966
   ID:2, Firstname:Caro, Lastname:Faschingbauer, Date of birth: 25.4.1997
   ID:3, Firstname:Johanna, Lastname:Faschingbauer, Date of birth: 11.6.1995
   ID:4, Firstname:Philipp, Lastname:Lichtenberger, Date of birth: 6.4.1986
   ID:5, Firstname:Elizabeth II, Lastname:Queen, Date of birth: 1.1.1900

.. note:: 

   Btw, the CSV file is encoded in ``cp1252`` [#doze-encoding]_.


.. rubric:: Footnotes

.. [#doze-encoding] A `historic baggage
                    <https://de.wikipedia.org/wiki/Windows-1252>`__
                    that comes with Microsoft, sigh. It still appears
                    to be the default encoding when creating Excel CSV
                    exports.
