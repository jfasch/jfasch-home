.. include:: <mmlalias.txt>


Reading a File
==============

.. contents:: 
   :local:

Write a program that reads and parses files like this
(:download:`download <files/students.txt>`):

.. include:: files/students.txt
   :literal:

The program parses each line as a student record, consisting of

* Matriculation number
* First name
* Last name

Commandline
-----------

The program is invoked with the student database file name as its only
parameter,

.. code-block:: console

   $ path/to/repo/root/exercises/lastname.firstname/studentdb students.txt

Output
------

The program writes to standard output one line per student record,

.. note::

   Please take care that the output is *exactly* as shown (spaces are
   spaces, not tabs, for example). This greatly helps a future checker
   script.

.. code-block:: console

   $ path/to/repo/root/exercises/lastname.firstname/studentdb students.txt
   ...
   MatNr: 1810420029, Last name: Zwittnigg, First name: Florian
   MatNr: 666, Last name: Faschingbauer, First name: Jörg
   $


Further Information
-------------------

* Note that a line, when read from a file, still comes with a newline
  ("``\n``") at the end. You should rid of trailing newline, otherwise
  the last name will have a trailing newline. See ``str.rstrip()``
  (documentation `here
  <https://docs.python.org/3/library/stdtypes.html#str.rstrip>`__)
* Use ``str.split()`` on each line (documentation `here
  <https://docs.python.org/3/library/stdtypes.html#str.split>`__).
