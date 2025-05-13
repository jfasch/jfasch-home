``UserDB::read()``: What If Done Twice?
=======================================

The semantics of ``UserDB::read()`` leaves many things open:

* Does it overwrite any content that is present in memory?
* Does it add new data to it?
* If so, what about duplicates?
