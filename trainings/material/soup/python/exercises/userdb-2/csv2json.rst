Exercise: Convert User Records To JSON
======================================

Plan
----

Combine the two rock-stable functions from the previous exercises
:doc:`read-csv-dicts` and :doc:`write-json-dicts` into something that
we can sell for money. Write a program ``csv2json.py`` that converts a
user database from CSV format into a more modern JSON format.

Additional complication: Doze user simply click the "Export" button in
Excel, having no idea what *encoding* is. Sure they won't tell you
that the CSV file that you receive is encoded in ``cp1252``.

How
---

Download a sample database :download:`code/users-cp1252.db`. Call the
program to read that file, and convert it into another file, like so:

.. code-block:: console

   $ python csv2json.py users-cp1252.db users.json

Check the output; it should look something like this:

.. code-block:: console

   $ cat users.json 
   [{"id": 666, "firstname": "J\u00f6rg", "lastname": "Faschingbauer", "birth": "1966-06-19"}, {"id": 42, "firstname": "Caro", "lastname": "Faschingbauer", "birth": "1997-04-25"}, {"id": 7, "firstname": "Johanna", "lastname": "Faschingbauer", "birth": "1995-06-11"}, {"id": 1024, "firstname": "Philipp", "lastname": "Lichtenberger", "birth": "1986-04-06"}](jfasch-home) 
