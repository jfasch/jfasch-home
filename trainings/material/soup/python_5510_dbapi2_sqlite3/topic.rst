.. include:: <mmlalias.txt>

DBAPI 2: ``sqlite3``
====================

.. contents::
   :local:

.. jf-topic:: python.python_5510_dbapi2_sqlite3
   :dependencies: python.python_5500_dbapi2

SQLite3
-------

* Lightweight database implementation
* No big fat server, no client
* Relatively small C library - linkable by programs
* Used by ...

    * Android apps for configuration
    * Firefox to store history, bookmarks, whatever
    * ...

* Extremely cool for ...

  * Prototyping
  * Unit testing - *In-Memory database*

* *Bundled as DBAPI2 module in Python*

SQLite3 Connection
------------------

.. code-block:: python
   :caption: Creating a database connection

   import sqlite3
   dbapi2 = sqlite3
   connection = dbapi2.connect('/tmp/database')

**Observations ...**

* "Rename" module to ``dbapi2`` to ease porting to other DBAPI2
  implementations (not necessary but cool)
* ``dbapi2.connect('/tmp/database')`` creates database if necessary
  |longrightarrow| be careful
* ``':memory:'`` creates an in-memory database |longrightarrow| cool
  for use in unit tests

SQLite3: Cursors and Statements
-------------------------------

.. code-block:: python
   :caption: Creating a cursor

   cursor = connection.cursor()

.. code-block:: python
   :caption: Creating a table

   cursor.execute('create table schwammerln ('
                  '  name text, '
                  '  typ text, '
                  '  giftig boolean, '
                  '  geniessbar boolean)')
   connection.commit()

**Observations ...**

* It's SQL
* Commit is not necessary with SQLite3 - but could be with DBMS with a
  higher isolation level

SQLite3: Filling the Database
-----------------------------

.. code-block:: python

   cursor.execute('insert into schwammerln '
    'values ("Steinpilz", "Roehren", 0, 1)')
   cursor.execute('insert into schwammerln '
    'values ("Speisetaeubling", "Lamellen", 0, 1)')
   cursor.execute('insert into schwammerln '
    'values ("Speitaeubling", "Lamellen", 0, 0)')
   cursor.execute('insert into schwammerln '
    'values ("Eierschwammerl", "Lamellen", 0, 1)')
   cursor.execute('insert into schwammerln '
    'values ("Teufelsroehrling", "Roehren", 1, 0)')

(``connection.commit()`` as appropriate)

SQLite3: Queries - Result Set
-----------------------------

.. code-block:: python

   resultset = cursor.execute(
       'select * from schwammerln '
       'where typ = "Roehren"')
   for row in resultset:
       print row

.. code-block:: python
   :caption: Output

   (u'Steinpilz', u'Roehren', 0, 1)
   (u'Teufelsroehrling', u'Roehren', 1, 0)

* A result set is *iterable*, and thus consumable *only once*

SQLite3: Bind Parameters
------------------------

* Same statement, used repeatedly with varying *parameters*
* Naive implementation: Python string substitution
* Can be done better ...

.. code-block:: python
  
   cursor.execute('select * from schwammerln '
     'where typ = ?', ("Roehren",))

* Native interfaces are generally able to pre-calculate and optimize
  ("schedule") SQL statements
* SQL-Injection attacks
