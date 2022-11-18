.. ot-exercise:: python.exercises.legacy.distill
   :dependencies: python.exercises.legacy.revert,
		  python.basics.python_0500_files,
		  python.basics.python_0139_commandline_argv

.. include:: <mmlalias.txt>


Exercise: Eliminate Empty/Comment-Only Lines
============================================

.. contents::
   :local:

Write a program ``distill.py`` that takes a filename from the
commandline.

* Open that file for reading
* Output (to ``stdout``) every line that ...

  * ... is not empty (i.e., does not entirely consist of whitespace)
  * ... does not entirely consist of a Python style comment (and is
    otherwise empty)

Example
-------

Take as a test case the following content, and write it into a file
``distill-test.txt`` (or :download:`download it <distill-test.txt>`).

.. literalinclude:: distill-test.txt
   :caption: :download:`distill-test.txt`

Run your program ``distill.py`` on that file. The program's output
should look as follows.

.. code-block:: console

   $ python distill.py distill-test.txt
   visible content     # though with a comment
   the previous line contains two TAB characters
         starts at column >0, but is visible
   the previousline is entirely empty

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.legacy.distill
