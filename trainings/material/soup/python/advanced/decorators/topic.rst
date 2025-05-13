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

A Simple Minded Function
------------------------

.. jupyter-execute::

   def f():
       print('f called (inside the function)')
       return 42

   f()

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
       def wrapper():
           print(func.__name__, 'called (says wrapper)')
           return func()
       return wrapper

Decorators are Syntactic Sugar
------------------------------

* Lets decorate ``f()``

.. jupyter-execute::

   f = debug(f)
   f()

* This is too much typing
* Why explicitly *replace* a function?

* Want decadence!
* |longrightarrow| ``@debug`` is the same as ``f = debug(f)``!

.. jupyter-execute::

   @debug
   def f():
       return 42

.. jupyter-execute::

   f()

Problem: Arbitrary Function Arguments
-------------------------------------

* Currently, ``wrapper()`` cannot does not take *any* arguments
* |longrightarrow| cannot wrap *any* function

.. jupyter-execute::
   :raises:

   @debug
   def add(a, b):         # <--- takes 2 arguments
       return a+b
   
   add(1,2)

``*args``, ``**kwargs`` To The Rescue
-------------------------------------

.. sidebar::

   **See also**

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

* ``wrapper()`` can wrap anything
* Can ``@debug`` anything now

.. jupyter-execute::

   @debug
   def add(a, b):
       return a+b
   
   add(1,2)

Sideways: ``functools.wraps``
-----------------------------

* Ugly: wrapper's ``__name__`` attribute unreadable
* It's just ``wrapper`` inside local scope

.. jupyter-execute::

   add.__name__

* Fix: copy wrapped function's metadata over
* |longrightarrow| ``@functools.wraps``: a decorator for decorators

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
   
       def __call__(self, func):        # <--- __call__() implements () (calls) on objects of "class debug"
           @functools.wraps(func)
           def wrapper(*args, **kwargs):
               print(f'{self.msg}: func = {func.__name__}, {args}, {kwargs}')
               return func(*args, **kwargs)
           return wrapper
   
   @debug('wtf')                        # <--- here
   def add(l, r):
       return l+r
   
   @debug('gosh')                       # <--- and here
   def sub(l, r):
       return l-r
   
   print('add(1,2) = ', add(1,2))
   print('sub(1,2) = ', sub(1,2))
