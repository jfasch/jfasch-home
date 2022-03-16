.. ot-exercise:: python.exercises.userdb.csvdictreader_function
   :dependencies: python.exercises.userdb.csvdictreader,
		  python.basics.python_0270_functions
		  
.. include:: <mmlalias.txt>


Exercise: Refactoring - Extract CSV Reading Into Function 
=========================================================

.. contents::
   :local:

Requirement
-----------

Following :doc:`csvdictreader`, refactor your code to not directly
output the user records as specified. 

Rather, create a function that reads the CSV file, and which is used
as follows in the main part of the program (the part that creates the
output which remains the same):

.. code-block:: python
   
   user_records = read_csv_header(filename)
   for rec in user_records:
       ... create output like before, no change ...
     

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.userdb.csvdictreader_function
