.. include:: <mmlalias.txt>

Context Managers (Slideshow)
============================

Problem
-------

* Resource cleanup
* Python is *garbage collected*
* Cleanup does happen but nobody can say when |longrightarrow| not
  *deterministic*

Solution: The ``with`` Statement
--------------------------------

.. code-block:: python

   with open('/etc/passwd') as f:
       ... use f ...

* Interpreter "talks to" user-supplied code
* Much like the *iterator protocol*
* Many creative uses
* ``contextlib``: pool of creativity,
  https://docs.python.org/3/library/contextlib.html
