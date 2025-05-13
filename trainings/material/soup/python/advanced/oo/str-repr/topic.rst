.. include:: <mmlalias.txt>


``str()`` And ``repr()``
========================

.. contents::
   :local:

Stringification And Representation
----------------------------------

* ``str(obj)``: nicely made-up string, used by e.g. ``print()``
* ``repr(obj)``: object *representation*, ideally suitable as
  ``eval()`` input
* Default: prints something useless (class name and object identity)

  .. jupyter-execute::
  
     class Person:
         def __init__(self, firstname, lastname):
             self.firstname = firstname
             self.lastname = lastname
  
     person = Person('Joerg', 'Faschingbauer')

* Expicitly calling ``str()`` on object

  .. jupyter-execute::

     str(person)

* Using ``print()`` with an object calls ``str()`` on is own

  .. jupyter-execute::

     print(person)

* ``repr()`` on an object

  .. jupyter-execute::

     repr(person)

* ``print()`` a list of objects |longrightarrow| uses ``repr()`` on
  list elements

  .. jupyter-execute::

     print([person])

Overloading ``str()`` And ``repr()``: ``__str__()``, ``__repr__()``
-------------------------------------------------------------------

* ``__str__()``: returns human readable string, describing the
  object. Called, for example, by ``print()``.
* ``__repr__()``: object representation. Usually the code to
  re-construct the object.

  .. jupyter-execute::
  
     class Person:
         def __init__(self, firstname, lastname):
             self.firstname = firstname
             self.lastname = lastname
     
         def __str__(self):
             return f'{self.firstname} {self.lastname}'
     
         def __repr__(self):
             return f'Person("{self.firstname}", "{self.lastname}")'
  
  .. jupyter-execute::
  
     person = Person('Joerg', 'Faschingbauer')

* ``str()`` (and ``print()``)

  .. jupyter-execute::
  
     str(person)
  
  .. jupyter-execute::
  
     print(person)

* ``repr()`` (and ``print()`` on lists)

  .. jupyter-execute::
  
     print(repr(person))
  
  .. jupyter-execute::
  
     print([person])


