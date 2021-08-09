.. include:: <mmlalias.txt>

Parsing ``/etc/passwd``
=======================

.. contents::
   :local:

.. jf-exercise:: python.exercises.legacy.passwd
   :dependencies: python.exercises.legacy.distill,
		  python.basics.python_0500_files


Write a program ``user.py`` that takes one or more usernames from the
commandline, looks them up in ``/etc/passwd``, and prints out the user
records one after the other. The program should be optimized for speed
and read ``/etc/passwd`` only once. The user records are pre-parsed as
follows: the metadata (UID, home directory, etc.) go in a dictionary

.. code-block:: python

   { 'uid': 1000,
     'gid': 1000,
     'home': '/home/jfasch',
     'shell': '/bin/bash'
   }

The user records are sorted into another dictionary, with the user's
login name as the key. It is that dictionary where the lookup is
performed.
