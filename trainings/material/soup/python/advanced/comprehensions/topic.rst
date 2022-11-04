.. ot-topic:: python.advanced.comprehensions
   :dependencies: python.basics.python_0150_datatypes_overview_compound

.. include:: <mmlalias.txt>


Comprehensions (List, Dictionary, Set)
======================================

.. contents::
   :local:

Intro
-----

* Python is expressive
* Clear syntax for everything
* Sometimes a bit short to the point
* |longrightarrow| Comprehensions, consequentially

Simplest: List Comprehension
----------------------------

.. jupyter-execute::

   l = []
   for i in range(5):
       l.append(i**2)
       
   l

This is clumsy. Want dedicated sytax!

.. jupyter-execute::

   [i**2 for i in range(5)]

Even with an included if statement ...

.. jupyter-execute::

   [i**2 for i in range(5) if i%2==0]

.. jupyter-execute::

   %matplotlib inline
   import matplotlib.pyplot as plt

   x = list(range(5))
   y = [i**2 for i in x]
   plt.plot(x, y)
   plt.show()

Dictionary Comprehension
------------------------

.. jupyter-execute::

   {i: i**2 for i in range(5)}

.. jupyter-execute::

   {i: i**2 for i in range(5) if i%2==0}

Set Comprehension
-----------------

.. jupyter-execute::

   {i for i in range(5)}

.. jupyter-execute::

   {i for i in range(5) if i%2 == 0}
