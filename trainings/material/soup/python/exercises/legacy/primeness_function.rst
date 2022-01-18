.. ot-exercise:: python.exercises.legacy.function_primeness
   :dependencies: python.exercises.legacy.max_numbers_function,
		  python.basics.python_0270_functions,
		  python.basics.python_0139_commandline_argv

.. include:: <mmlalias.txt>


Exercise: Primeness (Function)
==============================

Modify the prime number detection program from :doc:`here
</trainings/material/soup/python/exercises/legacy/while_primeness>`
or :doc:`here
</trainings/material/soup/python/exercises/legacy/for_primeness>` as follows.

* Push the *prime number checking algorithm* into a function.
  (``is_prime()`` is a likely name for that function.)

  * The function takes one parameter: the number to check for
    primeness.
  * The function returns whether the number-to-check is prime (a
    boolean value)
  * The function does not have any side effects, like printing on the
    console, or use ``sys.exit()`` to terminate the process. All that
    must be done by *the caller*.

The rest of the program (taking the number from the commandline, or
using ``input()`` to prompt the user for the number) remains
intact. The only change is that the new function is called with the
number as parameter, rather than implement the algorithm in top level
code.

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.legacy.function_primeness
