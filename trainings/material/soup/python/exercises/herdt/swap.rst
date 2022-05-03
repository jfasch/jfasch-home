.. ot-exercise:: python.exercises.herdt.swap
   :dependencies: python.exercises.herdt.boolean,
		  python.basics.python_0140_variables,
		  python.basics.python_0150_datatypes_overview,
		  python.basics.python_0120_helloworld

.. include:: <mmlalias.txt>


Exercise: Swap Two Variables
============================

#. Write a program ``swap.py`` that exchanges (swaps) two variables
   ``var1`` and ``var2``, both ``str`` type.

   To output the values before and after the swap operation, use the
   ``print()`` function.

   .. code-block:: python

      var1 = 1
      var2 = 2

      print('Before:', var1, var2)
      # let the miracle happen: exchange the two variables!
      print('After:', var1, var2)

   Once the miracle took place, the output of the program should look
   like follows:

   .. code-block:: console

      $ python swap.py
      Before: 1 2
      After: 2 1

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.herdt.swap
