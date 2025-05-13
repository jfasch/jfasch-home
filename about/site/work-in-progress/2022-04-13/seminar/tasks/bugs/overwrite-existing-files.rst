Existing Files Are Overwritten
==============================

``UserDB::write()`` does not take care of existing files. Actually, it
uses ``O_TRUNC`` to explicitly **empty** existing files.

Find solutions; e.g. ...

* Pass a ``force_overwrite`` flag?
* Pass an open file descriptor?
* What's best?

