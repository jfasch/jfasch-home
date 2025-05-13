.. include:: <mmlalias.txt>


Positional and Keyword Arguments
================================

.. contents::
   :local:

.. sidebar::

   **See also**

   * :doc:`../decorators/topic`

Traditional Function Call
-------------------------

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

Supplying Function Arguments Dynamically
----------------------------------------

* Positional arguments: *sequence*

  .. jupyter-execute::
     
     args = [1, 2]    
     f(*args)

  Any sequence is sufficient - e.g. ``range()``

  .. jupyter-execute::
     
     args = range(1, 3)
     f(*args)

* Keyword arguments: *mapping* (usually ``dict``)

  .. jupyter-execute::
     
     kwargs = {'a':1, 'b':2}
     f(**kwargs)

Functions That Takes Arbitrary Number Of Positional Arguments
-------------------------------------------------------------

* The other way around: not *passing* parameters dynamically, but
  *accepting* them dynamically
* "Starargs": ``*args`` function parameter
* ``args`` is just a common name, can be arbitrary

.. jupyter-execute::
  
   def f(*args):                     # <--- starargs
       print(args, type(args))       # <--- will print *tuple*

* Called traditionally, with positional arguments
* *Any number of arguments possible*

.. jupyter-execute::
  
   f(1, 2)
   f(1, 2, 3)

Functions That Take Arbitrary Keyword Arguments
-----------------------------------------------

* Much like positional args, but keyword args and ``dict``
* "Starstarargs": ``**kwargs`` function parameter
* Again, ``kwargs`` is just a common name, can be arbitrary

.. jupyter-execute::
  
   def f(**kwargs):                  # <--- starstarargs
       print(kwargs, type(kwargs))   # <--- will print *dict*

* Called traditionally, with keyword arguments
* *Any number of arguments possible*

.. jupyter-execute::
  
   f(a=1, b=2)
   f(a=1, b=2, c=3)

And Arbitrary Positional *And* Keyword Arguments?
-------------------------------------------------

* Rule: positional Arguments must come before keyword arguments

.. jupyter-execute::
  
   def f(*args, **kwargs):
       print(args)
       print(kwargs)
   
   f(1, 2, a=3, b=4)

Ultimate Dynamicity: Arbitrary Positional And Keyword Arguments
---------------------------------------------------------------

* Pass-through: accept any number and of arguments
* Pass them on as they were passed
* Typical usecase: :doc:`decorators <../decorators/topic>`

.. jupyter-execute::
  
   def f(*args, **kwargs):
       print(*args, **kwargs)
   
   f(1, 2, end='\n(done)\n')            # <--- actually, this *is* print

Use Case: A Better ``print()``
------------------------------

* Works like ``print()``
* Has a number of bells and whistles of its own
* |longrightarrow| ``indent``

.. jupyter-execute::
  
   import sys
   
   def my_print(*args, **kwargs):
       indent = kwargs.pop('indent')    # <--- remove from kwargs
       if indent is not None:
           args = (' '*indent,) + args
       print(*args, **kwargs)           # <--- pass rest to print
   
   my_print(1, 2, 
            end='\n(done)\n',           # <--- consumed by print
            indent=4,                   # <--- consumed by my_print
            )
