.. include:: <mmlalias.txt>

Username/Password Check
=======================

.. contents::
   :local:

.. jf-exercise:: python.exercises.herdt.username_password
   :dependencies: python.exercises.herdt.swap,
		  python.basics.python_0120_helloworld,
		  python.basics.python_0140_variables,
		  python.basics.python_0150_datatypes_overview,
		  python.basics.python_0170_if,
		  python.basics.python_0130_syntax_etc

#. Write a program that

   * Uses the ``input()`` function to prompt the user for her username
     and password.
   * Verifies the input against a username/password combination that
     you hardcode in the program.
   * Outputs (to ``stdout``) either "Authentication successful" or
     "Authentication failed".
