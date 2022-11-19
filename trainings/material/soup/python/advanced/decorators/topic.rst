.. ot-topic:: python.advanced.decorators
   :dependencies: python.basics.python_0270_functions,
		  python.advanced.closures,
		  python.advanced.starargs

.. include:: <mmlalias.txt>


Decorators
==========

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`../starargs/topic`
   * :doc:`../closures/topic`

The Ominous "``@``"
-------------------

* Special syntax |longrightarrow| only syntactic sugar
* Used to *wrap* existing functions/methods

  * Without modifying them

* Examples

  * ``@functools.total_ordering`` (see :doc:`here
    <../oo/operator-overloading/topic>`)
  * Debugging: printing function name and arguments
  * Timing information: time spent inside a function
  * Adding a D-Bus interface to a plain Python class
  * Defining Flask URL routes to call Python functions
  * ...

Decorators Overview
-------------------

* Only syntactic sugar for inner functions/closures (see
  :doc:`../closures/topic`)
* Can be implemented as functions

.. code-block:: python

   @debug
   def bar(a, b, c):
       ...

* Can be implemented as classes (usually when decorator is
  parameterized |longrightarrow| state needs to be remembered)

.. code-block:: python

   @debug(prefix)
   def bar(a, b, c):
       ...

Decorator Basics
----------------

.. sidebar::

   **See also**

   * :doc:`../closures/topic`

* Something that creates a function to wrap another function
* Wrapped function passed as argument
* That is the whole point

.. jupyter-execute::

   def debug(func):
       def wrapper(*args, **kwargs):
           print(func.__name__, 'called:', args, kwargs)
           return func(*args, **kwargs)
       return wrapper

* Can ``@debug`` anything now

.. jupyter-execute::

   @debug
   def add(a, b):
       return a+b
   
   add(1,2)

Decorators are Syntactic Sugar
------------------------------

* This is too much typing
* Why explicitly *replace* a function?

.. jupyter-execute::

   def f():
       print('f called')
       return 42
   f = debug(f)

* Want decadence!

.. jupyter-execute::

   @debug
   def f():
       return 42

Problem: Arbitrary Function Arguments
-------------------------------------

* Currently, ``wrapper()`` cannot does not take any arguments
* |longrightarrow| cannot wrap *any* function

.. jupyter-execute::
   :raises:

   @debug
   def add(a, b):
       return a+b
   
   add(1,2)

``*args``, ``**kwargs`` To The Rescue
-------------------------------------

.. sidebar::

   * :doc:`../starargs/topic`

* A wrapper needs to accept *anything* that the wrapped function can
  take
* As generic as possible
* |longrightarrow| :doc:`starargs <../starargs/topic>`

.. jupyter-execute::

   def debug(func):
       def wrapper(*args, **kwargs):       # <--- accept anything
           print(func.__name__, 'called:', args, kwargs)
           return func(*args, **kwargs)    # <--- pass anything
       return wrapper

* Can wrap anything

.. jupyter-execute::

   @debug
   def add(a, b):
       return a+b
   
   add(1,2)

Sideways: ``functools.wraps``
-----------------------------

* Ugly: wrapper's ``__name__`` attribute unreadable

.. jupyter-execute::

   add.__name__

* Pretty: add description (copy metadata over)
* ``@functools.wraps``: a decorator for decorators

.. jupyter-execute::

   import functools
   
   def debug(func):
       @functools.wraps(func)           # <--- copy func metadata over to wrapper
       def wrapper(*args, **kwargs):
           print(func.__name__, 'called:', args, kwargs)
           return func(*args, **kwargs)
       return wrapper

* Now any decorated/wrapped function has all it needs

.. jupyter-execute::

   @debug
   def add(a, b):
       return a+b
   
   add.__name__

Class Decorator: ``debug()`` with prefix
----------------------------------------

.. jupyter-execute::

   import functools
   
   class debug:
       def __init__(self, msg):
           self.msg = msg
   
       def __call__(self, func):
           @functools.wraps(func)
           def wrapper(*args, **kwargs):
               print(f'{self.msg}: func = {func.__name__}, {args}, {kwargs}')
               return func(*args, **kwargs)
           return wrapper
   
   @debug('wtf')
   def add(l, r):
       return l+r
   
   @debug('gosh')
   def sub(l, r):
       return l-r
   
   print('add(1,2) = ', add(1,2))
   print('sub(1,2) = ', sub(1,2))
