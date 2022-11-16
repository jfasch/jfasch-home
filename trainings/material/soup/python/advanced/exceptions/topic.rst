.. ot-topic:: python.advanced.exceptions
   :dependencies: python.basics.python_0140_variables,
		  python.basics.python_0270_functions,
		  python.advanced.oo.inheritance

.. include:: <mmlalias.txt>


Exception Handling
==================

.. contents::
   :local:

Introduction
------------

Keywords that cover blocks:

* ``try``: try to execute potentially harmful code - *might raise exceptions*
* ``except``: react on those exceptions - *catch* them
* ``finally``: executed in *any* case, no matter if raised or not
* ``else``: executed if *no* exceptions was raised

A few examples are in order ...

Basic Exception Handling: ``try``, ``except``
---------------------------------------------

* Catching an exception *no matter what*

.. jupyter-execute::

   try:
       f = open('file-that-does-not-exist.txt')
   except:                     # <--- unconditionally catching *any* error
       print('bad luck')

* Usually not a good idea: covers other more severe errors

.. jupyter-execute::

   try:
       print(a_variable)       # <--- raises NameError!
       f = open('file-that-does-not-exist.txt')
   except:
       print('bad luck')

* |longrightarrow| catch exception *by their type*

Built-In Exception Hierarchy
----------------------------

.. sidebar::

   * :doc:`python:library/exceptions`

.. line-block::

   BaseException
    ├── BaseExceptionGroup
    ├── GeneratorExit
    ├── KeyboardInterrupt
    ├── SystemExit
    └── Exception
         ├── ArithmeticError
         │    ├── FloatingPointError
         │    ├── OverflowError
         │    └── ZeroDivisionError
         ├── AssertionError
         ├── AttributeError
         ├── BufferError
         ├── EOFError
         ├── ExceptionGroup [BaseExceptionGroup]
         ├── ImportError
         │    └── ModuleNotFoundError
         ├── LookupError
         │    ├── IndexError
         │    └── KeyError
         ├── MemoryError
         ├── NameError
         │    └── UnboundLocalError
         ├── OSError
         │    ├── BlockingIOError
         │    ├── ChildProcessError
         │    ├── ConnectionError
         │    │    ├── BrokenPipeError
         │    │    ├── ConnectionAbortedError
         │    │    ├── ConnectionRefusedError
         │    │    └── ConnectionResetError
         │    ├── FileExistsError
         │    ├── FileNotFoundError
         │    ├── InterruptedError
         │    ├── IsADirectoryError
         │    ├── NotADirectoryError
         │    ├── PermissionError
         │    ├── ProcessLookupError
         │    └── TimeoutError
         ├── ReferenceError
         ├── RuntimeError
         │    ├── NotImplementedError
         │    └── RecursionError
         ├── StopAsyncIteration
         ├── StopIteration
         ├── SyntaxError
         │    └── IndentationError
         │         └── TabError
         ├── SystemError
         ├── TypeError
         ├── ValueError
         │    └── UnicodeError
         │         ├── UnicodeDecodeError
         │         ├── UnicodeEncodeError
         │         └── UnicodeTranslateError
         └── Warning
              ├── BytesWarning
              ├── DeprecationWarning
              ├── EncodingWarning
              ├── FutureWarning
              ├── ImportWarning
              ├── PendingDeprecationWarning
              ├── ResourceWarning
              ├── RuntimeWarning
              ├── SyntaxWarning
              ├── UnicodeWarning
              └── UserWarning

Exceptions Are Objects
----------------------

.. sidebar::

   **See also**

   * :doc:`../oo/inheritance/topic`

* Start with very base class
* An *object* of (at least) type ``BaseException``

.. jupyter-execute::

   try:
       f = open('file-that-does-not-exist.txt')
   except BaseException as e:    # <--- base class of all exception
       print('bad luck:', e)     # <--- bad luck, because e

``class Exception``
-------------------

From :doc:`python:library/exceptions`

     Exception

         All built-in, non-system-exiting exceptions are derived from this
         class. All user-defined exceptions should also be derived from
         this class.


Pitfall: Bad ecept order jjj
----------------------------

.. sidebar::

   * :doc:`../../misc/encoding/topic`

* encodingerror
* is-a exception






Exception Hierarchy
-------------------




Why Exceptions?
---------------

.. list-table::
   :align: left

   * - **Deal:**

       * Return ``< 0`` on error
       * Caller has to check
       * Caller has to pass error on

     - .. code-block:: python

          def do_much(this, that):
              if do_this(this) < 0:
                  return -1
              if do_that(that) < 0:
                  return -1
              return 0
          
          def do_this(this):
              if this == 2:
                  return -1
              else:
                  return 9
          
          def do_that(that):
              if that == 5:
                  return -1
              else:
                  return 'blah'

Exception Handling
------------------

**Plan is:** write less code |Longrightarrow| cleaner code

.. code-block:: python

   def do_much(this, that):
       do_this(this)
       do_that(that)
   
   try:
       do_much(1, 5)
   except MyError as e:
       print('Error:', e.msg,
             file=sys.stderr)

   def do_this(this):
       if this == 2:
           raise MyError('this is 2')
       else:
           return 9
   
   def do_that(that):
       if that == 5:
           raise MyError('that is 5')
       else:
           return 'blah'

Exceptions
----------

**Exceptions are objects** ...

* Python 2: can be anything
* Python 3: must be *derived* from ``class BaseException``

  * User defined exception *should* be derived from ``Exception``

* |longrightarrow| *Object oriented programming*

.. code-block:: python

   class MyError(Exception):
       def __init__(self, msg):
           self.msg = msg

Catching All Exceptions
-----------------------

.. code-block:: python

   a_dict = {}
   try:
       print(a_dict['novalidkey'])
   except:   # KeyError
       print("d'oh!")


* Catches *everything* no matter what
* Hides severe programming errors
* |longrightarrow| use only if you really know you want

.. code-block:: python

   try:
       print(nonexisting_name)
   except:   # NameError
       print("d'oh!")

Catching Exceptions By Type
---------------------------

.. code-block:: python

   a_dict = {}
   try:
       print(a_dict['novalidkey'])
   except KeyError:
       print("d'oh!")

* ``NameError`` (and *most* others) passes through

  * ... and terminate the program unless caught higher in the call
    chain

* Very specific |longrightarrow| best used punctually

Catching Exceptions By Multiple Types
-------------------------------------

.. code-block:: python

   a_dict = {}
   try:
       print(a_dict[int('aaa')])
   except (KeyError, ValueError):
       print("d'oh!")

* (Btw, the exception list is an *iterable* of *type objects*)
* As always: reflect your intentions
* Is the handling the same in both cases?

  * I'd say very rarely

Storing the Exception's Value
-----------------------------

* Many exceptions' only information is their type
* |longrightarrow| "A ``KeyError`` happened!"
* Sometimes exceptions carry additional information

.. code-block:: python

   class MyError(Exception):
       def __init__(self, msg):
           self.msg = msg
   
   def do_something():
       raise MyError('it failed')
   
   try:
       do_something()
   except MyError as e:
       print(e.msg)

Order of Except-Clauses (1)
---------------------------

* Except-Clauses are processed top-down
* |longrightarrow| Very important when exceptions are related/inherited
* ``MyError`` *is a* ``Exception``

.. code-block:: python
  
   class MyError(Exception):
       def __init__(self, msg):
           self.msg = msg
     
   def do_something():
       raise MyError('it failed')

Order of Except-Clauses (2)
---------------------------

.. list-table::
   :align: left

   * - .. code-block:: python
          :caption: Wrong

          try:
              do_something()
          except Exception as e:
              print('unexpected')
          except MyError as e:
              print(e.msg)
          

       * ``MyError`` is a ``Exception``
       * |longrightarrow| eats all ``MyError`` objects
       * |longrightarrow| ``MyError`` never caught

     - .. code-block:: python
          :caption: Right

          try:
              do_something()
          except MyError as e:
              print(e.msg)
          except Exception as e:
              print('unexpected')

       **Rule:**

       * Catch the *most specific* exception first
