.. include:: <mmlalias.txt>

Digit to English Word
=====================

.. jf-exercise:: python.exercises.cmdline_digit
   :dependencies: python.exercises.mixed_list_keyerror,
		  python.basics.python_0120_helloworld,
		  python.basics.python_0130_syntax_etc,
		  python.basics.python_0140_variables,
		  python.basics.python_0150_datatypes_overview,
		  python.basics.python_0150_datatypes_overview_compound

Write a program ``digit`` that takes a single digit as commandline
parameter. Print the English word for that digit. 

.. code-block:: console

   $ ./digit 7
   seven

* Use a dictionary (key: ``int``, value: ``str``) for the translation.
* Valid inputs are digits ``0`` - ``9``. Outputs are the
  corresponding *lowercase* english words for that digit.

Dependencies
------------

.. jf-topicgraph::
   :entries: python.exercises.cmdline_digit
