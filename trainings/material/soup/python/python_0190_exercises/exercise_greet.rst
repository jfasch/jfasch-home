.. include:: <mmlalias.txt>

Greeting, Depending on Time of Day
==================================

.. contents::
   :local:

.. jf-exercise:: python.basics.exercises.greeting
   :dependencies: python.basics.python_0120_helloworld,
		  python.basics.python_0140_variables,
		  python.basics.python_0150_datatypes_overview,
		  python.basics.python_0170_if,
		  python.basics.exercises.boolean

#. A greeting has to be composed automatically, based upon time of day
   and sex.

   * Use the ``input()`` function to prompt the user on ``stdin`` for
     three variables,

     * Name
     * Sex. Valid inputs are ``m`` (male) and ``f`` (female); all
       other input leads to program termination.
     * Hour of day. Valid inputs are number ``0`` through ``23``; all
       other input leads to program termination.

   * Depending on the hour of day, the greeting starts with

     * ``0`` - ``9``: "Good morning, "
     * ``10`` - ``17``: "Good day, "
     * ``18`` - ``23``: "Good evening, "

   * Depending on the sex, the greeting continues with "Mrs." or
     "Mr.".
   * Last comes the name.
   * Finally, the greeting is output on ``stdout``
