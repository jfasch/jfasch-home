.. ot-topic:: python.advanced.decorators
   :dependencies: python.basics.python_0270_functions,
		  python.advanced.closures,
		  python.advanced.starargs

.. include:: <mmlalias.txt>


Decorators
==========

.. contents::
   :local:

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

What and How
------------

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

Closures Recap
--------------

.. jupyter-execute::

   def decorator(param):
       def wrapper():
           print('wrapper called, param =', param)
           return param
       return wrapper
   
   eins = decorator(1)
   zwei = decorator(2)
   blah = decorator('blah')
   
   print('eins', eins())
   print('zwei', zwei())
   print('blah', blah())

* Ignore names ``decorator``, ``wrapper``
* Think ``outer`` and ``inner``, or ``foo`` and ``bar``
* Decorator semantics will come next

Simple Decorator: Function Without Args
---------------------------------------

.. jupyter-execute::

   def decorator(func):
       def wrapper():
           print('wrapper called, func =', func.__name__)
           return func()
       return wrapper
   
   def f1():
       print('f1 called')
       return 1
   
   def f2():
       print('f2 called')
       return 2
   
   f1 = decorator(f1)
   f2 = decorator(f2)
   
   print('f1 returned', f1())
   print('f2 returned', f2())

* Modify ``decorator`` to take a function as parameter
* Print return values, and wrapping information

Decorators are Syntactic Sugar
------------------------------

.. jupyter-execute::

   def decorator(func):
       def wrapper():
           print('wrapper called, func =', func.__name__)
           return func()
       return wrapper
   
   @decorator
   def f1():
       print('f1 called')
       return 1
   
   @decorator
   def f2():
       print('f2 called')
       return 2
   
   print('f1 returned', f1())
   print('f2 returned', f2())


* Replace explicit wrapper call to ``decorator`` with "``@``" directly
  before function definitions
* Simply call functions (they are automatically wrapped)
* |longrightarrow| exactly the same
* *That's basically it*!

``*args``, ``**kwargs``: A Debug-Decorator
------------------------------------------

* Wrong

.. jupyter-execute::
   :raises:

   def debug(func):
       def wrapper():
           print('debug: func =', func.__name__)
           return func()
       return wrapper
   
   @debug
   def add(l, r):
       return l+r
   
   @debug
   def sub(l, r):
       return l-r
   
   print('add(1,2) returned', add(1,2))
   print('sub(1,2) returned', sub(1,2))

* Right

.. jupyter-execute::

   def debug(func):
       def wrapper(*args, **kwargs):
           print('debug: func =', func.__name__, args, kwargs)
           return func(*args, **kwargs)
       return wrapper
   
   @debug
   def add(l, r):
       return l+r
   
   @debug
   def sub(l, r):
       return l-r
   
   print('add(1,2) returned', add(1,2))
   print('sub(1,2) returned', sub(1,2))

Sideways: ``functools.wraps``
-----------------------------

* Ugly: wrapper's ``__name__`` attribute unreadable

.. jupyter-execute::

   def debug(func):
       def wrapper(*args, **kwargs):
           print('debug: func =', func.__name__, args, kwargs)
           return func(*args, **kwargs)
       return wrapper
   
   @debug
   def add(l, r):
       return l+r
   
   @debug
   def sub(l, r):
       return l-r
   
   print('add name:', add.__name__)
   print('sub name:', sub.__name__)

* Pretty: add description (copy metadata over)

.. jupyter-execute::

   import functools
   
   def debug(func):
       @functools.wraps(func)
       def wrapper(*args, **kwargs):
           print('debug: func =', func.__name__, args, kwargs)
           return func(*args, **kwargs)
       return wrapper
   
   @debug
   def add(l, r):
       return l+r
   
   @debug
   def sub(l, r):
       return l-r
   
   print('add name:', add.__name__)
   print('sub name:', sub.__name__)

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
