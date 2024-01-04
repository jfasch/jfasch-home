.. ot-exercise:: python.exercises.userdb.user_json
   :dependencies: python.exercises.userdb.userdb_module
		  
.. include:: <mmlalias.txt>


Exercise: Convert User Record To JSON And Back
==============================================

.. contents::
   :local:

Requirement
-----------

.. sidebar::

   **Documentation**

   * :doc:`python:library/json`

In :doc:`userdb_csv`, we created a set of routines around user records
of the following form:

.. code-block:: python

   {
       'id': 2,    # int
       'firstname': 'Jörg',
       'lastname': 'Faschingbauer',
       'birth': '19.6.1966',
   }

Preparing for MQTT communication (:doc:`mqtt-publish-csv`), it is
advisable to create a module ``userdb_json.py`` that defines a transport
format for transmission that is

* Converted to before sending
* Converted from after receiving

Usage is envisioned as follows:

.. code-block:: python

   import userdb_csv
   import userdb_json

   for user in userdb_csv.read_csv_noheader('some.csv'):   # could be ANY source, of course
       json_str = userdb_json.to_json(user)
       ... publish json_str to MQTT topic ...

Test Code
---------

The following test (see
:doc:`/trainings/material/soup/python/swdev/pytest/intro` for how to
use it) can better express the requirement,

.. literalinclude:: code/tests/test_user_json.py
   :caption: :download:`code/tests/test_user_json.py`
   :language: python

Dependencies
------------

.. ot-graph::
   :entries: python.exercises.userdb.user_json
