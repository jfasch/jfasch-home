.. ot-task:: clean_code.refactoring.pass_store_in_ctor
   :dependencies: clean_code.refactoring.backingstore_monolithic


Load From BackingStore in Constructor
=====================================

Finally eliminate that entire ``read()`` and ``write()`` mess. It is
semantically unclear regarding overwrite. Instead,

* Pass an instance of ``BackingStore`` to ``UserDB``'s constructor,
  which will then load its contents from the ``BackingStore``.
* Eliminate the ``read()`` method.
* Rename ``write()`` to ``sync()``
