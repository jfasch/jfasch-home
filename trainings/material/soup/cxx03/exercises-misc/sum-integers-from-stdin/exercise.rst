.. ot-exercise:: cxx03.exercises_misc.sum_integers_from_stdin

.. include:: <mmlalias.txt>


Exercise: Sum of Integers Coming From ``cin``
=============================================

.. contents::
   :local:

Description
-----------

Write a program (lets call it ``sum-ints``) that

* reads a sequence of integer numbers from standard input (``std::cin``), line by line
* store them in a ``std::vector<int>``
* outputs the sum of these numbers when standard input's end is
  reached [#eof]_

The program is typically called this way:

.. code-block:: console

   $ ./sum-ints
   666
   42
   7
   ^D             <--- EOF on standard input
   715

.. note::

   The following demo program shows how to handle the End-Of-File
   condition. It reads numbers from standard input (and echoes them to
   standard output) until EOF is reached.
   
   .. literalinclude:: cin-int.cpp
      :caption: :download:`cin-int.cpp`


.. rubric:: Footnotes

.. [#eof] Standard input's End-Of-File (EOF) is reached when the user
	  type :kbd:`ctrl` + :kbd:`d` (Unix) or :kbd:`ctrl` + :kbd:`z`

Dependencies
------------

.. ot-graph::
   :entries: cxx03.exercises_misc.sum_integers_from_stdin



