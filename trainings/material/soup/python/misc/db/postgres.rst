.. include:: <mmlalias.txt>


DBAPI 2: PostgreSQL
===================

.. contents::
   :local:

DBAPI 2 Example: Postgres
-------------------------

* Does not come with Python installation
* |longrightarrow| http://initd.org/psycopg/
* Entry point: ``connect()``
* Parameters best seen in the C-API documentation
  (http://www.postgresql.org/docs/8.3/static/libpq-connect.html)
* ``connect(const char* conninfo)``: string containing ``name=value``
  pairs
* |longrightarrow| keyword arguments in ``psycopg2``

.. code-block:: python

   import psycopg2  
   connection = psycopg2.connect(
       host='localhost',
       dbname='schwammerldb',
       user='ich',
       password='secret')
