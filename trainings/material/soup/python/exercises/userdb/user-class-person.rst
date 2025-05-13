.. include:: <mmlalias.txt>


Exercise: Away From Raw Dictionaries
====================================

.. contents::
   :local:

Requirement
-----------

Up to the past two iterations (:doc:`userdb_csv` and
:doc:`user_json`), we have represented the *Persons* as raw
dictionaries of the following form:

.. code-block:: python

   {
       'id': 2,    # int
       'firstname': 'Jörg',
       'lastname': 'Faschingbauer',
       'birth': '19.6.1966',
   }

Now that we know what classes are, and which benefits they bring
(:doc:`/trainings/material/soup/python/advanced/oo/classes-and-dicts/topic`),
lets

* design a ``class Person``
* re-implement all of the CSV stuff, by creating a parallel set of
  function that return ``Person`` objects instead of those
  dictionaries

.. note::

   The lovely :doc:`collections.namedtuple
   </trainings/material/soup/python/advanced/oo/namedtuple/topic>`
   can be used to solve that problem.

Test Code
---------

The following tests cover the required ``class Person`` changes. 

.. literalinclude:: code/tests/test_noheader_person.py
   :caption: :download:`code/tests/test_noheader_person.py`
   :language: python

.. literalinclude:: code/tests/test_header_person.py
   :caption: :download:`code/tests/test_header_person.py`
   :language: python

.. literalinclude:: code/tests/test_user_json_person.py
   :caption: :download:`code/tests/test_user_json_person.py`
   :language: python
