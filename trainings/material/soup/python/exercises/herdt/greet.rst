.. ot-exercise:: python.exercises.herdt.greeting
   :dependencies: python.exercises.herdt.max_numbers,
		  python.basics.python_0170_if

.. include:: <mmlalias.txt>


Exercise: Greeting, Depending on Time of Day
============================================

.. sidebar:: Documentation

   * `Python's input() function
     <https://docs.python.org/3/library/functions.html#input>`__

A greeting has to be composed automatically, based upon time of day
and sex.

* Use the ``input()`` function to prompt the user on ``stdin`` for
  three variables,

  * Name
  * Sex. Valid inputs are ``m`` (male) and ``f`` (female); both
    uppercase and lowercase characters are allowed. All other input
    leads to program termination (use ``sys.exit(1)`` for erroneous
    termination).
  * Hour of day. Valid inputs are number ``0`` through ``23``; all
    other input leads to program termination.

* Depending on the hour of day, the greeting starts with

  * ``0`` - ``9``: "Good morning, "
  * ``10`` - ``17``: "Good day, "
  * ``18`` - ``23``: "Good evening, "

* Depending on the sex, the greeting continues with "Mrs." or "Mr.".
* Last comes the name.
* Finally, the greeting is output on ``stdout``

.. code-block:: console

   $ python greet.py
   Name: Jörg
   Sex: f
   Hour of day: 22

   Good evening, Mrs. Jörg

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.herdt.greeting
