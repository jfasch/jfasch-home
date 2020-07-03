.. include:: <mmlalias.txt>

Python: DBAPI 2
===============

.. contents::
   :local:

.. jf-topic:: python_5500_dbapi2
   :dependencies: python_1200_modules, python_0220_for,
                  python.python_1010_generators_yield

Database Interfaces
-------------------

There are as many database interfaces for Python as there are
databases ...

.. list-table::
   :align: left

   * - **SQL**:

       * ODBC (generic)
       * ADO (generic)
       * MySQL
       * Oracle
       * PostgreSQL
       * Informix
       * SQLite
       * ...

     - **Others**:

       * BerkeleyDB
       * MongoDB
       * ...

|longrightarrow| People want a common interface

DBAPI 2.0
---------

* Programming interface for SQL databases
* In fact only a *recommendation* for database interface authors

  * ... but there's the BDFL

Defines what a database interface has to have ...

* *Connection*: initial point of all database operations
* *Cursor*: context of a database operation. More than one cursor
  possible.
* *Data types*: e.g. ``sqlite3.Date(1966,6,19)``

Caveat: Transaction Lifetime
----------------------------

DBAPI module use the underlying database's "native interface"
|longrightarrow| *transaction semantics is not portable across
different databases*

**Neutral (DBAPI 2.0) Definition**

* One connection has *at most one* transaction |longrightarrow|
  transaction lifetime dictated by connection
* Once a cursor is created, a transaction is started
* The connection methods ``commit()`` and ``rollback()`` close a
  transaction
* A cursor's ``.execute()`` method creates a transaction if one does
  not exist
* Deleting a connection triggers a transaction's ``rollback()`` method

  * |longrightarrow| *Don't forget* ``connection.commit()``!

Caveat: Isolation
-----------------

* Modifications on different cursors of the same connection are
  generally visible to each other
* Not all databases implement strong isolation among different
  *connections*
* *Isolation level* settings are specific to database implementations
