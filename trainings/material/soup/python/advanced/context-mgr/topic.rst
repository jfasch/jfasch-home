.. ot-topic:: python.advanced.context_mgr
   :dependencies: python.advanced.oo.classes_and_dicts,
		  python.advanced.exceptions,
		  python.advanced.iteration_generation

.. include:: <mmlalias.txt>


Context Managers: The ``with`` Statement
========================================

.. contents::
   :local:

Why?
----

* Python is *garbage collected*
* Actually, does not make any guarantees when resources are freed
  (though C-Python does refcounting, deterministically)
* Usually not a problem with memory-only data (like ``list``,
  ``dict``, etc)
* Want more deterministic behavior for other resources
* *Automatic* cleanup |longrightarrow| exception safety
* |longrightarrow| simplicity

Example: Open File
------------------

.. sidebar::

   **Documentation**

   * :doc:`python:library/functions`

* The prototypical example
* ``open()`` return value (a ``io.TextIOWrapper`` instance) can be
  used as a *context manager*
* |longrightarrow| ``with``

.. jupyter-execute::

   with open('/etc/passwd') as f:
       for line in f:
           if 'jfasch' in line:
               print(line)

Without ``with``, this would have to look more ugly:

.. jupyter-execute::

   try:
       f = open('/etc/passwd')
       for line in f:
           if 'jfasch' in line:
               print(line)
   finally:
       f.close()

Example: Temporary Directory
----------------------------

.. sidebar::

   **Documentation**

   * :doc:`python:library/tempfile`

* Create a ``tar`` archive file in a temporary directory
* Nested ``with`` blocks
* |longrightarrow| hard to get manual cleanup right 
* |longrightarrow| ``with`` to the rescue

 .. literalinclude:: tar-tmpdir.py
   :caption: :download:`tar-tmpdir.py`
   :language: python

Example: Multiple ``with`` Items
--------------------------------

* ``with`` not contrained to only one managed object
* Arbitrarily many objects possible

.. jupyter-execute::

   with open('/etc/passwd') as p, open('/etc/group') as g:
       # do something with p and g
       pass

Under The Hood: *Context Manager*
---------------------------------

* Anything that has methods ``__enter__`` and ``__exit__``
* ``__enter__``: returns the *target* - the variable which is set by
  ``as``
* ``__exit__``: *cleans up resources*, and receives exception context
  if any

  * Exception ignored if returns ``True``
  * Exception re-raised if returns ``False``

* Example: manual ``open()`` context manager

.. jupyter-execute::
   :raises:

   class OpenForReading:
       def __init__(self, filename):
           self.filename = filename
   
       def __enter__(self):
           self.file = open(self.filename)
           return self.file      # <--- becomes 'f' in 'as f'
       def __exit__(self, exc_type, exc_value, exc_tb):
           self.file.close()
           return False          # <--- re-raise exception
   
   with OpenForReading('/etc/passwd') as f:
       # do something with f
       raise RuntimeError('bad luck')

Example: Monkeypatching The ``print`` Function
----------------------------------------------

.. sidebar::

   **See also**

   * :doc:`../starargs/topic`

.. jupyter-execute::

   class PrefixPrint:
       def __init__(self, prefix):
           self.prefix = prefix
   
       def myprint(self, *args, **kwargs):
           my_args = (self.prefix,) + args
           self.orig_print(*my_args, **kwargs)
   
       def __enter__(self):
           global print
           self.orig_print = print
           print = self.myprint
   
       def __exit__(self, exc_type, exc_val, exc_tb):
           global print
           print = self.orig_print
	   return True
   
   print('cool')
   with PrefixPrint('MEGA:'):
       print('even cooler')
   
Still Much Typing |longrightarrow| ``@contextlib.contextmanager``
-----------------------------------------------------------------

.. sidebar::

   **See also**

   * :doc:`../iteration-generation/topic`
   * :doc:`../decorators/topic`

* ``__enter__`` and ``__exit__`` still too clumsy
* |longrightarrow| using ``yield`` to split a function in half
* Usually using ``try`` and ``finally`` for setup and teardown
* Example: distilling ``OpenForReading()`` to a minimum

.. jupyter-execute::

   import contextlib
   
   @contextlib.contextmanager
   def OpenForReading(filename):
       try:
           file = open(filename)
           yield file            # <--- becomes 'f' in 'as f'
	                         # <--- continuing here after 'with' block has run
       finally:
           file.close()

More Involved: Using Closures To Implement ``PrefixPrint``
----------------------------------------------------------

.. jupyter-execute::

   import contextlib
   
   @contextlib.contextmanager
   def PrefixPrint(prefix):
       def myprint(*args, **kwargs):
           pfxargs = (prefix,)+args
           orig_print(*pfxargs, **kwargs)

       global print
   
       try:
           orig_print = print
           print = myprint
           yield
       finally:
           print = orig_print
   
   with PrefixPrint('MEGA:'):
       print('hallo')
   
