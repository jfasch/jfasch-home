.. include:: <mmlalias.txt>

Primeness (Function)
====================

.. jf-exercise:: python.exercises.legacy.function_primeness
   :dependencies: python.exercises.legacy.for_primeness,
		  python.basics.python_0270_functions

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

The rest of the program (taking the number from the commandline, or
using ``input()`` to prompt the user for the number) remains
intact. The only change is that the new function is called with the
number as parameter, rather than implement the algorithm in top level
code.

Dependencies
------------

.. jf-topicgraph::
   :entries: python.exercises.legacy.function_primeness
