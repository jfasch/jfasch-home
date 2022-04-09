.. ot-exercise:: python.exercises.herdt.max_numbers
   :dependencies: python.exercises.herdt.swap,
		  python.basics.python_0140_variables,
		  python.basics.python_0170_if,
		  python.basics.python_0139_commandline_argv

.. include:: <mmlalias.txt>


Exercise: Determine Maximum of Two Numbers
==========================================

Write a program that

* Takes two numbers from the :doc:`commandline
  </trainings/material/soup/python/basics/python_0139_commandline_argv/topic>`. *Remember*:
  commandline arguments can only be strings, so those have to be
  :ref:`converted to numbers <python-datatype-conversions>`.
* Determines the maximum of the numbers.
* Outputs the maximum.

.. code-block::

   $ python maximum.py 42 123
   123

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.herdt.max_numbers
