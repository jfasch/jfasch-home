.. ot-task:: clean_code.refactoring.backingstore_monolithic
   :dependencies: clean_code.refactoring.store_enum_switch


``UserDB`` Responsibilities: ``read()``, ``write()``
====================================================

Should the file format be the responsibility of something that is
mainly an in-memory database?

Create a class ``BackingStore`` that is used to

* Read records from, into ``UserDB``
* Write records to, from inside ``UserDB``

Instead of passing ``filename`` and ``format`` to ``UserDB::read()``
and ``UserDB::write()``, pass a ``BackingStore`` instance instead.
