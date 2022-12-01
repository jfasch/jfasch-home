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

* **Usually not a good idea**: covers other more severe errors

.. jupyter-execute::

   try:
       print(a_variable)       # <--- raises NameError!
       f = open('file-that-does-not-exist.txt')
   except:
       print('bad luck')

* |longrightarrow| catch exception *by their type*

Catching Exceptions By Type
---------------------------

* More specific reaction on errors: *by type*
* E.g.: ``open()`` raises ``FileNotFoundError`` when ... well ... file
  is not found

  .. jupyter-execute::
  
     try:
         f = open('file-that-does-not-exist.txt')
     except FileNotFoundError:
         print('file not there')

Exception Objects
-----------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/oo/str-repr/topic`

* Exceptions are objects
* Can carry anything that's relevant to the error
* Usually implement ``__str__()`` |longrightarrow| printable

.. jupyter-execute::
  
   try:
       f = open('file-that-does-not-exist.txt')
   except FileNotFoundError as e:
       print('file not there:', e)

Catching Multiple Exception Types: Exception List
-------------------------------------------------

* Different error at the same level: ``PermissionError``
* E.g. when a file has no read permissions

.. jupyter-execute::
   :hide-code:
   :hide-output:

   import os
   
   try:
       open('/tmp/some-file.txt', 'w')
   except OSError: pass
   os.chmod('/tmp/some-file.txt', 0)

.. program-output:: ls -l /tmp/some-file.txt

.. jupyter-execute::

   try:
       open('/tmp/some-file.txt')
   except PermissionError as e:
       print('bad luck on permissions:', e)

* Catching both ``FileNotFoundError`` and ``PermissionError`` at once

.. jupyter-execute::

   try:
       open('/tmp/some-file.txt')
   except (FileNotFoundError, PermissionError) as e:
       print('either file not there, or bad luck on permissions:', e)

Catching Multiple Exception Types: Multiple ``except`` Clauses
--------------------------------------------------------------

* Specific handling of a number of different exceptions
* |longrightarrow| multiple ``except`` clauses in a row

.. jupyter-execute::

   try:
       open('/tmp/some-file.txt')
   except FileNotFoundError as e:
       print('file not there:', e)
   except PermissionError as e:
       print('bad luck on permissions:', e)

Catching Multiple Exception Types: By Base Type
-----------------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/oo/inheritance/topic`

* Both ``FileNotFoundError`` and ``PermissionError`` are
  :doc:`subclasses
  </trainings/material/soup/python/advanced/oo/inheritance/topic>` of
  ``OSError``

.. code-block:: console

   ...
    └── OSError
         ├── FileNotFoundError
         ├── ... many more ...
         └── PermissionError

* |longrightarrow| Catching ``OSError`` covers both

.. jupyter-execute::

   try:
       open('/tmp/some-file.txt')
   except OSError as e:            # <--- FileNotFoundError and PermissionError (and ...)
       print('bad luck, OS-wise:', e)

Important: Order Of ``except`` Clauses
--------------------------------------

* ``except`` clauses are evaluated in order of appearance
* Traversal stops at first match
* *The following is generally unwanted*
* |longrightarrow| ``OSError`` swallows any ``open()`` error,
  preventing specific handling of ``FileNotFoundError`` and
  ``PermissionError``

.. jupyter-execute::
 
   try:
       open('/tmp/some-file.txt')       # <--- raises PermissionError
   except OSError as e:                 # <--- matches PermissionError (which is-a OSError)
       print('bad luck, OS-wise:', e)
   except FileNotFoundError as e:       # <--- skipped
       print('file not there:', e)
   except PermissionError as e:         # <--- skipped
       print('bad luck on permissions:', e)

* Put more specific errors at the top
* Base classes at the bottom
* |longrightarrow| *sort by specificity*
* |longrightarrow| fallback error handling

.. jupyter-execute::
 
   try:
       open('/tmp/some-file.txt')
   except FileNotFoundError as e:
       print('file not there:', e)
   except PermissionError as e:
       print('bad luck on permissions:', e)
   except OSError as e:               # <--- fallback for other types of OSError
       print('bad luck, OS-wise:', e)

Built-In Exception Hierarchy
----------------------------

.. sidebar::

   **Documentation**

   * :doc:`python:library/exceptions`

* ``BaseException`` is the root of all exceptions
* ``Exception`` is the root of all non-system-exiting exceptions
* User-defined exceptions should derive from ``Exception``
* (Not a hard rule though)

.. code-block:: console

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

Raising Exceptions
------------------

* ``raise`` an exception object
* Exception object is an instance of a class - the exception's class
* No secret here: exceptions are objects like anything else
* Can only ``raise`` subtypes of ``BaseException`` though

.. jupyter-execute::
   :raises:

   def maybe_fail(answer):
       if answer != 42:
           raise RuntimeError('wrong answer')
   
   maybe_fail(666)

Re-Raising Exceptions
---------------------

* Want to only shortly intercept an exception on its way through
* Otherwise pass it on unmodified
* |longrightarrow| a lone ``raise`` statement

.. jupyter-execute::
   :raises:

   def maybe_fail(answer):
       if answer != 42:
           raise RuntimeError('wrong answer')

   try:
      maybe_fail(666)
   except RuntimeError as e:
      print('argh!')
      raise             # <--- re-raise same exception


User-Defined Exceptions
-----------------------

* Built-in exceptions can be raised in user code
* |longrightarrow| ``RuntimeError`` is a good candidate when defining
  one's own exception hierarchy is too much work
* Not always enough though
* Convention, not law: *derive user-defined exceptions from*
  ``Exception``

Minimal hierarchy - just the types are of interest ...

.. jupyter-execute::

   class MySubsystemError(Exception):
       pass
   
   class ReallyBadError(MySubsystemError):
       pass
   
   class SomeOtherError(MySubsystemError):
       pass

User-Defined Exceptions: More
-----------------------------

* Why not store common data (e.g. ``OSError`` has a ``errno``
  attribute) ...
* A possible error scheme would be as follows

.. jupyter-execute::

   (DefinitelyBad, EvenWorse, CollapsingTheWorld) = range(1, 4)
   
   class MySubsystemError(Exception):           # <--- common base class for all subsystem errors
       def __init__(self, msg, errorcode):
           super().__init__(msg)
           self.errorcode = errorcode
       def __str__(self):
           return super().__str__() + f' ({self.errorcode})'
   
   class ReallyBadError(MySubsystemError):      # <--- one error
       pass
   
   class SomeOtherError(MySubsystemError):      # <--- another error
       pass

* The "subsystem" implementation

.. jupyter-execute::

   def foo(answer):
       if answer != 42:
           raise ReallyBadError(f'Bad answer: {answer}', DefinitelyBad)

* "subsystem" usage

.. jupyter-execute::

   try:
       foo(666)
   except MySubsystemError as e:                # <--- only interested in base type
       print(e)

``else``: Executed If No Exception
----------------------------------

* *Separation of concerns*
* Executed if no exception was raised
* Must come directly after ``except`` clauses (and before ``finally``
  if any)
* (Sadly) a syntax error if no ``except`` clause is present

.. jupyter-execute::

   try:
       open('/etc/passwd')        # <--- succeeds
   except OSError as e:           # <--- must be there (syntax error otherwise)
       print('bad luck, OS-wise:', e)
   else:
       print('all well')

``finally``: Executed Regardless Of Exception
---------------------------------------------

* *Separation of concerns*
* Error-unrelated things done in ``finally`` block
* Executed regardless if an exception was raised or not
* Must come last (after any ``except`` and ``else`` clauses)
* Here the error case:

.. jupyter-execute::

   try:
       open('/tmp/some-file.txt')           # <--- fails
   except OSError as e:
       print('bad luck, OS-wise:', e)
   finally:
       print('doing error-unrelated stuff')

* And the sunny case

.. jupyter-execute::

   try:
       open('/etc/passwd')                  # <--- succeeds
   except OSError as e:
       print('bad luck, OS-wise:', e)
   finally:
       print('doing error-unrelated stuff')

