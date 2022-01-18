.. include:: <mmlalias.txt>

.. ot-exercise:: python.exercises.legacy.while_primeness
   :dependencies: python.exercises.legacy.cmdline_digit,
		  python.basics.python_0193_while


Exercise: Primeness (``while``)
===============================

Write a program that checks whether a given number is prime!

The number that the program checks can be given in two ways,

* As a commandline parameter (for non-interactive use)
* Prompted from the user, using the ``input()`` function

.. note::

   A number is prime, if ...

   * It is not equal to 1
   * It is only divisible by 1 and itself

.. code-block:: console

   $ python prime.py 7
   prime
   $ python prime.py 6
   not prime
   $ python prime.py 1
   not prime
   $ python prime.py 2
   prime

Dependencies
------------

.. ot-graph:: 
   :entries: python.exercises.legacy.while_primeness
   
