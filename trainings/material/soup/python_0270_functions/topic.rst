.. include:: <mmlalias.txt>

Python: Functions
=================

.. contents::
   :local:

.. jf-topic:: python_0270_functions
   :dependencies: python_0140_variables

Why Functions?
--------------

**What is a function?**

* Sequence of statements
* Parameterizabe
* Can have a return value
* |longrightarrow| Can be used as an expression

**Why would one want to do this?**

* Code structuring
* Readability
* Maintainability
* Code reuse
* |longrightarrow| Libraries

An Example
----------

.. code-block:: python

   def maximum(a, b):
       if a < b:
           return b
       else:
           return a
   
   max = maximum(42, 666)

* ``def``: introduces function definition
* ``maximum``: function name
* ``a`` and ``b``: parameters
* ``return``: ends the function --- the *value* when used as
  expression

Sidenote: Pure Beauty
---------------------

**There is nothing special about functions**

* ``def`` is a *statement*
* Evaluated during regular program flow, just like other statements
* Creates a function object
* Points a *variable* to it - the function's name

.. code-block:: python

   >>> type(maximum)
   <class 'function'>
   >>> a = maximum
   >>> a(1,2)
   2

Parameters and Types
--------------------

**There is no compile-time type check**

* For good or bad
* ``maximum(a,b)``: can pass anything
* ... provided that ``a`` and ``b`` can be compared
  using ``<``
* *Late binding* |longrightarrow| runtime error
* |longrightarrow| More testing required
* |longrightarrow| Unit testing, module ``unittest``

.. code-block:: python

   >>> maximum(1, '1')
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
     File "<stdin>", line 2, in maximum
   TypeError: unorderable types: int() < str()

Default Parameters
------------------

For the most common case, *default values* may be specified ...

.. code-block:: python

   def program_exit(message, exitstatus=0):
       print(message, file=sys.stderr)
       sys.exit(exitstatus)
   
   program_exit('done')

Default parameters must come at the end of the parameter list ...

.. code-block:: python
   :caption: Syntax error

   def program_exit(exitstatus=0, message):
       ...

Default Parameters: Pitfalls
----------------------------

**Attention:** mutable default parameters may not do what one expects
...

.. code-block:: python

   def f(i, x=[]):
       x.append(i)
       return x
   
   print(f(1))
   print(f(2))

Produces ...

.. code-block:: python

   [1]
   [1, 2]

*Reason:** default value for a parameter *is part of the function
object* |longrightarrow| retains its value across calls
  
Keyword Arguments
-----------------

**Long parameter lists** ...

* Easy to confuse parameters
* Unreadable
* Unmaintainable

.. code-block:: python
   :caption: Function call with keyword arguments

   def velocity(length_m, time_s):
       return length_m / time_s
   
   v = velocity(2, 12) # what?
   v = velocity(time_s=2, length_m=12)

|longrightarrow| Very obvious to the reader!

Local and Global Variables
--------------------------

**Best explained using examples** ...

.. code-block:: python
   :caption: ``x`` only visible/alive inside ``f()``

   def f():
       x = 100
       return x

.. code-block:: python
   :caption: Error: no ``x`` found anywhere

   def f():
       return x

.. code-block:: python
   :caption: Using ``x`` from global scope

   x = 100
   def f():
       return x
  
.. code-block:: python
   :caption: ``x`` defined *globally* when ``f()`` called first time

   def f():
       global x
       x = 100
       ...

