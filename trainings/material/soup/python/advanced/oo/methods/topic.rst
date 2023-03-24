.. ot-topic:: python.advanced.oo.methods
   :dependencies: python.advanced.oo.classes_and_dicts

.. include:: <mmlalias.txt>


Methods
=======

.. contents::
   :local:

Object Methods
--------------

* Methods called on *objects* have implicit first parameter
* ... the *object* the method *is called on*
* Usually called ``self`` (not a must though; see :doc:`../constructor/topic`)

.. jupyter-execute::

   class Person:
       def __init__(self, firstname, lastname):
           self.firstname = firstname
           self.lastname = lastname
           
       def say_hello(self, phrase):
           return f'{phrase} {self.firstname} {self.lastname}'

.. jupyter-execute::

   joerg = Person('Joerg', 'Faschingbauer')
   joerg.say_hello("Howdy, I'm")

Class Methods (``@classmethod``)
--------------------------------

* Not bound to an object
* Cannot be called on an object
* Rather, called on a class
* Implicit first parameter: the *class* object 
* Usually named ``cls`` (again, not necessarily)
* Cool when inheriting/specializing ``Person``

.. jupyter-execute::

   class Person:
       def __init__(self, firstname, lastname):
           self.firstname = firstname
           self.lastname = lastname
           
       @classmethod
       def make_child(cls, firstname, parent1, parent2):
           # ---- vvv --- not hardwiring class Person
           return cls(firstname, f'{parent1.lastname}-{parent2.lastname}')

.. jupyter-execute::

   mother = Person('Isolde', 'Haubentaucher')
   father = Person('Joerg', 'Faschingbauer')

   child = Person.make_child('Alex', mother, father)

Static Methods (``@staticmethod``)
----------------------------------

* Like ``@classmethod``
* Only without implicit parameter
* (Consequentially, does not play well with inheritance)

.. jupyter-execute::

   class Person:
       def __init__(self, firstname, lastname):
           self.firstname = firstname
           self.lastname = lastname
           
       @staticmethod
       def make_child(firstname, parent1, parent2):
           # ---- vvvvvv --- hardwiring class Person
           return Person(firstname, f'{parent1.lastname}-{parent2.lastname}')

* Used the same as ``classmethod``

.. jupyter-execute::

   mother = Person('Isolde', 'Haubentaucher')
   father = Person('Joerg', 'Faschingbauer')
   
   child = Person.make_child('Alex', mother, father)
