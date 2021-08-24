.. include:: <mmlalias.txt>

Digit to English Word
=====================

.. jf-exercise:: python.exercises.legacy.cmdline_digit
   :dependencies: python.exercises.legacy.dict_keyerror,
		  python.basics.python_0120_helloworld,
		  python.basics.python_0150_datatypes_overview_compound

Write a program ``digit.py`` that takes a single digit as commandline
parameter. Print the English word for that digit. 

.. code-block:: console

   $ python digit.py 7
   seven

* Use a dictionary (key: ``int``, value: ``str``) for the translation.
* Valid inputs are digits ``0`` - ``9``. Outputs are the
  corresponding *lowercase* english words for that digit.

Dependencies
------------

.. jf-topicgraph::
   :entries: python.exercises.legacy.cmdline_digit
