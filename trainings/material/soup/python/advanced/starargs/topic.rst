.. ot-topic:: python.advanced.starargs
   :dependencies: python.basics.python_0270_functions

.. include:: <mmlalias.txt>


Positional and Keyword Arguments
================================

.. contents::
   :local:

Plain Function with Positional Arguments
----------------------------------------

* An ordinary function, taking two parameters ``a`` and ``b``

.. jupyter-execute::

   def f(a, b):
       print(a, b)

* Called with positional arguments

.. jupyter-execute::
   
   f(1, 2)

* Called with keyword arguments

.. jupyter-execute::
   
   f(a=3, b=4)

Function That Takes Arbitrary Number Of Arguments
-------------------------------------------------

* *Starargs*: positional arguments
* |longrightarrow| Passed as ``tuple``

.. jupyter-execute::
   
   def f(*args):
       print(args, type(args))    # <--- prints single tuple
   
   f(1, 2, 3)

* A-ha: positional arguments passed as tuple
* ``args`` parameter is a tuple

Unpacking Starargs?
-------------------

* "Unpack" tuple as positional arguments?

.. jupyter-execute::
   
   def f(*args):
       print(*args)               # <--- prints three distinct values
   
   f(1, 2, 3)

* Works with any sequence, not just arguments coming in

.. jupyter-execute::
   
   l = [1,2,3]
   print(*l)                      # <--- prints three distinct values

And Keyword Arguments?
----------------------

* ``*args``: positional parameters (unnamed)
* Keyword arguments done differently
* |longrightarrow| *Starstarargs*

.. jupyter-execute::
   
   def f(**kwargs):
       print(kwargs)
   
   f(a=1, b=2)

* A-ha: similar to ``*args``, ``**kwargs`` is passed as dictionary
* And unpacking |longrightarrow| same: ``**``

.. jupyter-execute::
   
   def f(a, b):
       print(a, b)

   d = { 'a': 1, 'b': 2 }
   f(**d)

Most Dynamic: Both ``*args, **kwargs``?
---------------------------------------

.. sidebar::

   **See also**

   * :doc:`../decorators/topic`

* Ultimate pass-through function
* Can take everything
* Should not be overused IMO (to much dynamicity is not good)
* |longrightarrow| :doc:`../decorators/topic`

.. note:: 

   Rule: positional args must come before keyword args

.. jupyter-execute::
   
   def f(*args, **kwargs):
       print('args:', args)
       print('kwargs:', kwargs)
   
   f(1, 2, 3, a=7, b=42, c='hallo', blah={'eins', 'zwei'})

