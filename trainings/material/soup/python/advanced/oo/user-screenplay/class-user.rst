.. ot-topic:: python.advanced.class_user
   :dependencies: python.advanced.oo.basics,
		  python.basics.python_0450_dictionaries,
		  python.basics.python_0270_functions

.. include:: <mmlalias.txt>

A Class For Users
=================

.. contents::
   :local:

Groundwork
----------

In the exercises
:doc:`/trainings/material/soup/python/exercises/userdb/csvreader-function`
and
:doc:`/trainings/material/soup/python/exercises/userdb/csvdictreader-function`,
we created two functions that returned lists of *user records*. A user
record is a dictionary of predefined form:

.. code-block:: python

   {
      'id': int(id),
      'firstname': firstname,
      'lastname': lastname,
      'birth': birth,
   }

Problem: Too Much Typing
------------------------

* Extracting members requires manual indexing

  .. code-block:: python
  
            users.append({
                'id': int(uid),
                'firstname': firstname,
                'lastname': lastname,
                'birth': birth,
            })


     for user in users:
         uid = userdict['ID']
         firstname = userdict['First name']
         lastname = userdict['Last name']
         birth = userdict['Date of Birth']
     
         print(f'ID:{uid}, Firstname:{firstname}, Lastname:{lastname}, Date of birth: {birth}')

* |longrightarrow| Error prone (typos all over)
* Construction of a user record is repeated code

  .. code-block:: python
  
     user = {

     }
