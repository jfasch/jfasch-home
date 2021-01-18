.. include:: <mmlalias.txt>

Exercises: Lists, Loops, Functions
==================================

.. jf-topic:: python.basics.python_0275_exercises
   :dependencies: python.basics.python_0195_exercises, 
		  python.basics.python_0193_while, 
		  python.basics.python_0220_for, 
		  python.basics.python_0270_functions,
		  python.basics.python_0150_datatypes_overview,
		  python.basics.python_0150_datatypes_overview_compound

Exercises
---------

#. Modify the prime number detection program from one of the previous
   exercises: make the prime number detection a function, and call the
   function instead. The function (``is_prime()`` is a likely name)
   takes a number, and returns a boolean value as appropriate.
#. Write a function ``uniq()`` that takes a sequence as input. It
   returns a list with duplicate elements removed, and where the
   contained elements appear in the same order that is present in the
   input sequence. The input sequence remains unmodified.
#. Write a function ``join()`` that takes a string list ``strings``
   and a string ``separator`` as parameter. It joins ``strings``
   together into a single string, using ``separator`` as a
   separator. For example,

   * ``join(['Hello', 'World'], '-')`` returns ``'Hello-World'``
   * ``join(['Hello'], '-')`` returns ``'Hello'``
