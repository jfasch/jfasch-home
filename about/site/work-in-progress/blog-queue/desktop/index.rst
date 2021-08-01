JF Desktop
==========

Overview
--------

jjj pictures, overview sketch - scenes

Scenes
------

0
.

.. code-block:: console

   $ python
   Python 3.9.4 (default, Apr  6 2021, 00:00:00) 
   [GCC 11.0.1 20210324 (Red Hat 11.0.1-0)] on linux
   Type "help", "copyright", "credits" or "license" for more information.
   >>> b = 194
   >>> c = 284
   >>> import math
   >>> a = math.sqrt(c**2 - b**2)
   >>> A = a*b/2
   >>> hc = 2*A/c
   >>> w = math.sqrt(a**2 - hc**2)
   >>> w
   151.47887323943658
   >>> hc
   141.68327693172083

Idea: Rectangular Triangle Calculator
.....................................

.. code-block:: 

   def triangular_rectangle():
       # transform (a,b,c,hc) (can be None) into fully valid (a,b,c,hc)
       return (None,)*4

L
.

R
.

X
.

* jjj picture **X**: a,b,c,alpha,beta,gamma
* jjj picture: winkelmesser

.. code-block::

   >>> alpha = 134 - 90
   >>> beta = alpha + 90
   >>> gamma = 90
   >>> alpha, beta, gamma
   (44, 134, 90)
   >>> 
   >>> a = 945
   >>> b = 408
   >>> c = 350
   >>> d = 965
   >>> 
   >>> a, b, c, d
   (945, 408, 350, 965)

Y
.
