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
commandline, and outputs only those lines that are not empty or don't
entirely consist of a Python style comment.

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.legacy.distill
