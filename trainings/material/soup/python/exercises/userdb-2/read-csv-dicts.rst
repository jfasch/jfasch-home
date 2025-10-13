Exercise: Split Strings To User Dictionaries
============================================

.. topic:: See also

   * :doc:`/trainings/material/soup/python/basics/python_0320_strings_methods/topic`

Plan
----

User records are defined as lines of a file, where each line has the
format

.. code-block:: text

   666:Jörg:Faschingbauer:1966-06-19

Our project, among other functionality, will provide a parsing routine
that can read such lines, and create python *user records* as
dictionaries of the form

.. code-block:: python

   {
       'id': 666,      # <-- int
       'firstname': 'Jörg',
       'lastname': 'Faschingbauer',
       'birth': '1966-06-19',
   }

How
---

In a project directory of your choice, create an empty file
``userdb.py``. This file is a *module* which is supposed to contain
project related functionality. Several programs will use that module's
contents, later in this exercise series.

At this stage in the project, lets only make sure that ``userdb``
works as intended, before combining the provided items (functions and
classes) into programs that we can sell for money. We do this by
writing *unit tests*.

Download the file below into the same directory that contains
``userdb.py``.

.. literalinclude:: code/test_read_userdicts_from_colon_separated_values.py
   :caption: :download:`code/test_read_userdicts_from_colon_separated_values.py`
   :language: python

Run the test (see below). It will complain that the functionality it
is testing does not even exist, let alone does it fulfill any further
requirements.

It is your task now to implement the required function
(``read_users_from_colon_separated_values()``) in ``userdb.py``, until
everthing is green.

Do not modify the test, unless you discover severe errors - in this
case, talk to your trainer and we will bend the requirements together.

.. code-block:: console

   $ python -m pytest
   ========================================================================== test session starts ==========================================================================
   platform linux -- Python 3.13.7, pytest-8.4.2, pluggy-1.6.0
   rootdir: /home/jfasch/My-Projects/jfasch-home/trainings/material/soup/python/exercises/userdb-2/code
   collected 1 item                                                                                                                                                        
   
   test_read_userdicts_from_colon_separated_values.py F                                                                                                                  [100%]
   
   =============================================================================== FAILURES ================================================================================
   ______________________________________________________________ test_read_userdicts_from_colon_separated_values __________________________________________________________
   
       def test_read_userdicts_from_colon_separated_values():
           input = [                                          # <-- file-like (iterable)
               '666:Jörg:Faschingbauer:1966-06-19\n',
               '42:Caro:Faschingbauer:1997-04-25\n',
               '7:Johanna:Faschingbauer:1995-06-11\n',
               '1024:Philipp:Lichtenberger:1986-04-06\n',
           ]
       
   >       persons = userdb.read_userdicts_from_colon_separated_values(input)
                     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   E       AttributeError: module 'userdb' has no attribute 'read_userdicts_from_colon_separated_values'
   
   test_read_userdicts_from_colon_separated_values.py:11: AttributeError
   ======================================================================== short test summary info ========================================================================
   FAILED test_read_userdicts_from_colon_separated_values.py::test_read_userdicts_from_colon_separated_values - AttributeError: module 'userdb' has no attribute 'read_userdicts_from_colon_separated_values'
   =========================================================================== 1 failed in 0.03s ===========================================================================
   (jfasch-home) jfasch@laptop:~/My-Projects/jfasch-home/trainings/material/soup/python/exercises/userdb-2/code$ 
   

