.. include:: <mmlalias.txt>

Functions: Global and Local Scope (Livehacking Screenplay)
==========================================================

.. contents::
   :local:

Undefined Variable
------------------

.. code-block:: python

   >>> def f():
   ...     print(x)
   ... 
   >>> f()
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
     File "<stdin>", line 2, in f
   NameError: name 'x' is not defined

Local Variable
--------------

.. code-block:: python

   >>> def f():
   ...     x = 1
   ...     print(x)
   ... 
   >>> f()
   1

**Discuss**: ``x`` ist *not* auomatically in global scope (like
 e.g. Javascript)

Global Variable
---------------

.. code-block:: python

   >>> def g():
   ...     print(globvar)
   ... 
   >>> globvar = 42
   >>> g()
   42

Local and Global Variable With Same Name
----------------------------------------

.. literalinclude:: code/30-local-global-same-name.py
   :caption: :download:`code/30-local-global-same-name.py`
   :language: python

.. code-block:: console

   $ python code/30-local-global-same-name.py
   local: 1
   global: 666

Assignment to Global Variable
-----------------------------

How do I assign to a global variable then, if assignment creates a
variable in local scope? |longrightarrow| ``global`` keyword

.. literalinclude:: code/40-global-assignment.py
   :caption: :download:`code/40-global-assignment.py`
   :language: python

.. code-block:: console

   $ python code/40-global-assignment.py
   assigned global: 1
   global: 1
