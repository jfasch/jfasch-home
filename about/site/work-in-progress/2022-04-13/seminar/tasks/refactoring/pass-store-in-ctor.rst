Load From BackingStore in Constructor
=====================================

There are a number of problems with the ``UserDB::read()`` method. See
:doc:`../bugs/overwrite-store-content-on-read` for an obvious symptom
of a design mismatch.

Apparently ``UserDB`` works best if it loads its contents from a
``BackingStore`` at most once.

This is best accomplished by passing it a ``BackingStore`` instance in
its constructor. The constructor loads the internal store, and the
``read()`` method can be removed.

If the constructor would also store the ``BackingStore`` in a private
member, ``write()`` could be relieved from all its arguments. Maybe
``write()`` should also be renamed to ``sync()`` which would be a
better name IMHO.
