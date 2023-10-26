.. ot-topic:: python.advanced.closures
   :dependencies: python.basics.python_0270_functions

.. include:: <mmlalias.txt>


Closures
========

.. contents::
   :local:

History
-------

* `Wikipedia
  <https://en.wikipedia.org/wiki/Closure_(computer_programming)>`__
* "A record storing a function together with an environment"

  * That is pretty much it!

* Dates back to early functional languages

  * LISP
  * Scheme

Today
-----

* Also available in modern languages

  * Javascript
  * C++: explicit capturing in *lambdas*
  * C#

* Definitely not unique to Python

  * Although `Wikipedia
    <https://en.wikipedia.org/wiki/Closure_(computer_programming)>`__
    starts out with Python examples

``def`` is a Statement
----------------------

* ``def`` create a variable (the function's name) that references a
  *function object*
* |longrightarrow| Functions are objects, just like integers are

.. jupyter-execute::

   def f():
       pass

   type(f)

* Variable assignment (of function objects)

.. jupyter-execute::

   def f():
       print('f called')
   
   g = f          # <--- assign one function to another
   g()            # <--- calls f (as g)

* ``def`` can be used anywhere - e.g. inside another function
* |longrightarrow| local function definition - *local variable*
* |longrightarrow| Functions can create *and return* other functions

Functions That Create Functions
-------------------------------

* A function that creates a function

.. jupyter-execute::

   def create_f():
       def f():
           print('inner f called')
       return f

* Create a function

.. jupyter-execute::

   inner = create_f()

* ``inner`` is a variable that references a function object
* Call it:
   
.. jupyter-execute::

   inner()

Inner Function Reaches Out To Global Scope
------------------------------------------

* Variables in global scope can be accessed by "inner" functions
* *No surprise*: global variables can be accessed by *any* function
* *No surprise*: global variables have program lifetime

.. jupyter-execute::

   glob = 666

   def create_f():
       def f():
           print('inner f called, glob is', glob)
       return f

* Calling the returned function reveals value of ``glob``

.. jupyter-execute::

   inner = create_f()
   inner()

And Intermediate Scope? |longrightarrow| *Closure*
--------------------------------------------------

* Semi global - variables in the *creating* scope
* Those do not outlive the creating function
* |longrightarrow| *Closure*

.. jupyter-execute::

   def create_f():
       intermediate = 1                # <--- captured in closure of f
       def f():
           print('inner f called, intermediate =', 
	         intermediate)         # <--- used *after* f has been returned
       return f

   inner = create_f()

* ``create_f()`` is over
* ``intermediate`` is long out of scope
* But is still alive in the *closure*

.. jupyter-execute::

   inner()

A Less Theoretical "Use Case"
-----------------------------

.. jupyter-execute::

   def create_print(msg):   # <--- parameters are local variables to the callee
       def p():
           print(msg)       # <--- local variable captured
       return p
   
   print_blah = create_print('blah')
   print_something = create_print('something')
   
   print_blah()
   print_something()

Scope Issues: Assignment to Global Scope (``global`` Keyword)
-------------------------------------------------------------

* First assignment creates variable *in local scope*
* The following is wrong! (At least if you want to assign to *global*
  ``g``)

.. jupyter-execute::

   g = 1
   
   def create_f():
       def f():
           g = 2            # <--- *local* variable created
           print('inner f called, g =', g)
       return f
   
   inner = create_f()
   inner()
   print('global g =', g)

* |longrightarrow| Global ``g`` still ``1``
* Fix: ``global`` keyword

.. jupyter-execute::

   g = 1
   
   def create_f():
       def f():
           global g         # <--- every mention of g means the *global* g
           g = 2
           print('inner f called, g =', g)
       return f
   
   inner = create_f()
   inner()
   print('global g =', g)

Scope Issues: Assignment to Intermediate Scope (``nonlocal`` Keyword)
---------------------------------------------------------------------

* And now, what about assignment to intermediate scope? To *a variable
  in the closure*?
* Who does this?
* Many non-obvious use cases, used to improve job security

.. jupyter-execute::

   def create():
       intermediate = 1
       def assign():
           nonlocal intermediate           # <--- that is the point! nonlocal!
	   intermediate = 2
           print('assign: intermediate =', intermediate)
       def check():
           print('check: intermediate =', intermediate)
       return assign, check
   
   assign, check = create()
   assign()
   check()
