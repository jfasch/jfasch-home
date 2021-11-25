.. ot-exercise:: python.exercises.legacy.passwd
   :dependencies: python.exercises.legacy.distill,
		  python.basics.python_0500_files,
		  python.basics.python_0450_dictionaries,
		  python.basics.python_0210_indexing_slicing

.. include:: <mmlalias.txt>


Exercise: Parsing ``/etc/passwd``
=================================

.. contents::
   :local:

Requirement
-----------

Write a program ``getuser.py`` that takes a filename and one or more
usernames from the commandline, looks them up in ``/etc/passwd``, and
prints out the user records one after the other.

.. code-block:: console

   $ python getuser.py /etc/passwd root jfasch
   User: root
     UID: 0
     GID: 0
     Home: /root
     Shell: /bin/bash
   User: jfasch
     UID: 1000
     GID: 1000
     Home: /home/jfasch
     Shell: /bin/bash

Implementation Strategy
-----------------------

The ``/etc/passwd`` (:download:`download sample <passwd>`) is the UNIX
user database. The file is line-based (an old UNIX tradition), and
each line contains a user record:

.. code-block:: console

   ...
   root:x:0:0:root:/root:/bin/bash
   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash
   ...

Each line/record consists of seven fields, separated by colons
(``':'``), with the following meaning:

.. list-table::
   :header-rows: 1
   :widths: auto
   :align: left

   * * Field index
     * Field name
   * * 0
     * ``username``
   * * 1
     * ``password``. Encrypted password, ``x`` means that this can be
       found in ``/etc/shadow``.
   * * 2
     * ``uid``. User ID.
   * * 3
     * ``gid``. (Primary) group ID.
   * * 4
     * ``description``. Arbitrary descriptive text.
   * * 5
     * ``home``. Home directory.
   * * 6
     * ``shell``. Login shell.

The program should read ``/etc/passwd`` only once. Each line is a user
record, and should be broken up into a dictionary. For example, the
line

.. code-block:: console

   jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash

Would make it into a dictionary

.. code-block:: python

   { 'uid': 1000,
     'gid': 1000,
     'home': '/home/jfasch',
     'shell': '/bin/bash'
   }

All lines/dictionaries/records would be stored in a large *user
database* dictionary that would look like so,

.. code-block:: python

   userdatabase = {
       "root": {
           "uid": 0,
           "gid": 0,
           "home": "/root",
           "shell": "/bin/bash",
          },
       "jfasch": {
           "uid": 1000,
           "gid": 1000,
           "home": "/home/jfasch",
	   "shell": "/bin/bash",
          },
       ...
   }

It is that ``userdatabase`` that is finally used to lookup the
remaining *username* arguments to the program.
