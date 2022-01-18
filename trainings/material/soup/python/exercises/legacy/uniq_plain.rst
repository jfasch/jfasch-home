.. ot-exercise:: python.exercises.legacy.uniq_plain
   :dependencies: python.exercises.legacy.function_primeness,
		  python.basics.python_0270_functions,
		  python.basics.python_0150_datatypes_overview_compound

.. include:: <mmlalias.txt>


Exercise: Sort out Duplicates
=============================

Write a program that sorts out duplicates of a (hardcoded) list, like
so:

.. code-block:: python

   input_list = [2, 3, 1, 10, 3, 3, 1, 10, 5, 2]
   output_list = []

   for num in input_list:
       ... check if duplicate ...
       ... append to output_list if not ...
   
   for num in output_list:
       print(num)

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
   :entries: python.exercises.legacy.uniq_plain
