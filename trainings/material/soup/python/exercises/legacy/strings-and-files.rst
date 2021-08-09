.. include:: <mmlalias.txt>

Strings, Files, ...
===================

.. contents::
   :local:

.. jf-exercise:: python.exercises.legacy.python_0510_exercises_strings_and_files
   :dependencies: python.exercises.legacy.python_0350_exercises, 
		  python.basics.python_0500_files

Exercises (1)
-------------

#. Write a program ``wc.py`` that takes a filename from the
   commandline and counts

   * Lines
   * Words
   * Characters

   and then outputs the gathered statistics to ``stdout``

#. Write a program ``revert.py`` that takes a filename from the
   commandline, and outputs every line of the file with the line's
   characters reversed. (Take care to strip off the linefeeds, or
   otherwise the linefeed will come first in the reversed line.)

#. Write a program ``distill.py`` that takes a filename from the
   commandline, and outputs only those lines that are not empty or
   don't entirely consist of a Python style comment.


Exercises (2)
-------------

#. Write a program ``user.py`` that takes one or more usernames from
   the commandline, looks them up in ``/etc/passwd``, and prints out
   the user records one after the other. The program should be
   optimized for speed and read ``/etc/passwd`` only once. The user
   records are pre-parsed as follows: the metadata (UID, home
   directory, etc.) go in a dictionary

   .. code-block:: python

      { 'uid': 1000,
        'gid': 1000,
        'home': '/home/jfasch',
        'shell': '/bin/bash'
      }

   The user records are sorted into another dictionary, with the
   user's login name as the key. It is that dictionary where the
   lookup is performed.
