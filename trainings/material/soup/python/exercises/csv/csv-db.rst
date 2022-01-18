.. ot-exercise:: python.exercises.csv.csv_db
   :dependencies: python.exercises.csv.csv_db,
		  python.db.sqlite3,
		  python.basics.python_0139_commandline_argv
		  
.. include:: <mmlalias.txt>


Exercise: Read CSV File, Write into Sqlite3 Database
====================================================

.. contents::
   :local:

Requirement
-----------

Based on the outcome from :doc:`csv-module`, write two programs to
manipulate a :doc:`Sqlite3 database
</trainings/material/soup/python/misc/db/sqlite3>`.

#. A program that creates a database schema. We need this as a
   separate program because we want to create the database once, and
   insert into it the contents of potentially many CSV files.

   .. code-block:: console

      $ python create-schema.py /tmp/mydb.sqlite

#. Another program that inserts the contents of a CSV file into that
   database.

   .. code-block:: console

      $ python stock-to-db.py stock.csv /tmp/mydb.sqlite

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.csv.csv_db
