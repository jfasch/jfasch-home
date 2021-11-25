.. include:: <mmlalias.txt>

Exercise: Function: ``uniq()``
==============================

.. ot-exercise:: python.exercises.legacy.uniq_function
   :dependencies: python.exercises.legacy.function_primeness,
		  python.basics.python_0270_functions,
		  python.basics.python_0150_datatypes_overview_compound


Write a function ``uniq()`` that takes a sequence as input. It
returns a list with duplicate elements removed, and where the
contained elements appear in the same order that is present in the
input sequence. The input sequence remains unmodified.

The program structure could be something like follows ...

.. code-block:: python

   def uniq(l):
       # ... here a miracle has to happen ...
       return ... # the uniq-ified list
   
   input_list = [2, 3, 1, 10, 3, 3, 1, 10, 5, 2]
   output_list = uniq(input_list)
   
   for element in output_list:
       print(element)

The expected program output is as follows:

.. code-block:: console

   $ python uniq.py
   2
   3
   1
   10
   5


Dependencies
------------

.. ot-graph::
   :entries: python.exercises.legacy.uniq_function
