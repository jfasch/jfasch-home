.. include:: <mmlalias.txt>

Reverting Lines of a File
=========================

.. contents::
   :local:

.. ot-exercise:: python.exercises.legacy.revert
   :dependencies: python.exercises.legacy.wc,
		  python.basics.python_0500_files

Write a program ``revert.py`` that takes a filename from the
commandline, and outputs every line of the file with the line's
characters reversed. (Take care to strip off the linefeeds, or
otherwise the linefeed will come first in the reversed line.)

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.legacy.revert
