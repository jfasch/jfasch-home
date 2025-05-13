.. include:: <mmlalias.txt>


Exercise: Refactoring - Extract CSV Reading Into Function (``csv.dictreader``)
==============================================================================

.. contents::
   :local:

Requirement
-----------

Following :doc:`csvdictreader`, refactor ``read-userdb-header.py`` to
not directly output the user records as specified.

Rather, create a function that reads the CSV file, and returns a list
of user records - dictionaries with specified keys - of the form,

.. code-block:: python

   {
       'id': 2,    # int
       'firstname': 'Jörg',
       'lastname': 'Faschingbauer',
       'birth': '19.6.1966',
   }

That list is then used as follows in the main part of the program (the
part that creates the output which remains the same):

.. code-block:: python
   
   user_records = read_csv_header(filename)
   for rec in user_records:
       ... create output like before, no change ...
