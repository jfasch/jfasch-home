.. include:: <mmlalias.txt>


``collections.namedtuple``
==========================

.. topic:: nDocumentation

   * `collections
     <https://docs.python.org/3/library/collections.html>`__

Shortcut For Simple Data-Holding Classes
----------------------------------------

* Much writing for a simple data holder

  .. jupyter-execute::
  
     class Person:
         def __init__(self, firstname, lastname):
             self.firstname = firstname
             self.lastname = lastname
  
     person = Person('Joerg', 'Faschingbauer')
     print(person.firstname, person.lastname)

* Written shorter (and with much more features - but read on)

  .. jupyter-execute::
  
     from collections import namedtuple
     Person = namedtuple('Person', ('firstname', 'lastname'))
     
     person = Person('Joerg', 'Faschingbauer')
     print(person.firstname, person.lastname)
   
Constructing From Iterable: ``_make()``
---------------------------------------

* Data-holding classes are popular with tabular data (:doc:`CSV
  <../../../misc/csv/topic>`, :doc:`databases <../../../misc/db/index>`, ...)
* Rows are *iterable*
* |longrightarrow| ``someclass._make()``
* Example: rows read from a CSV file

  .. jupyter-execute::
  
     persons_from_csv = [
         ['Joerg', 'Faschingbauer'],
         ['Caro', 'Faschingbauer'],
     ]

* Turning each into a ``Person`` object

  .. jupyter-execute::
  
     for person in map(Person._make, persons_from_csv):
         print(person.firstname, person.lastname)

Convert To ``dict``: ``_asdict()``
----------------------------------

.. jupyter-execute::
  
   person = Person('Joerg', 'Faschingbauer')
   person_dict = person._asdict()
   person_dict
