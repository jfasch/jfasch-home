.. include:: <mmlalias.txt>


Classes And Dictionaries
========================

Facts Up-Front
--------------

* ``class`` is a statement
* Creates a class
* Actually: a shorthand for creating a *type*
* A class is *callable*

  * Creates an object (|longrightarrow| ``self``)
  * Calls ``__init__`` on it (see :doc:`../constructor/topic`)

Using Raw Dictionaries As Objects
---------------------------------

* Raw dictionary to hold attributes

  .. jupyter-execute::
  
     person = {}

* ``str`` type keys as *attributes*

  .. jupyter-execute::
  
     person['firstname'] = 'Joerg'
     person['lastname'] = 'Faschingbauer'

* Attribute access is clumsy
   
  .. jupyter-execute::
  
     person['firstname']

* The type of the object does not refect that it is a *person*
   
  .. jupyter-execute::
  
     type(person)
   
* Much writing
* Many opportunities for bugs/typos
* |longrightarrow| **BAD!**

Enter Classes: An Empty Class, And Its Effects
----------------------------------------------

Better notation for the same thing: ``class``

* Create empty class (one without *class attributes* and *methods*)

  .. jupyter-execute::
  
     class Person:
         pass

* Classes are first-class object |longrightarrow| have a type

  .. jupyter-execute::
  
     type(Person)

  |longrightarrow| A-ha! Created a new type, obviously

* Objects are instantiated by *calling* their type

  .. jupyter-execute::
  
     person = Person()
     type(person)

Attributes
----------

* Setting attributes

  .. jupyter-execute::
  
     person.firstname = 'Joerg'
     person.lastname = 'Faschingbauer'

* Getting attributes

  .. jupyter-execute::
  
     person.firstname

* Unknown attribute access

  .. jupyter-execute::
     :raises:
  
     person.svnr                   # <--- attribute 'svnr' does not exist

Summary: Classes Or Raw Dictionaries
------------------------------------

* Definitely less typing 
* Objects have type other than ``dict``
* Classes are *callable* |longrightarrow| creates *instance* of it
  (the object)

Dynamic Attribute Access
------------------------

.. attention::

   Do not overuse! (Except to save your job maybe)

* ``hasattr()``
* ``getattr()``
* ``setattr()``
* ``dir()``
* ``obj.__dict__``

  .. jupyter-execute::
  
     class Person:
         pass
     
     person = Person()
     person.firstname = 'Joerg'
     person.lastname = 'Faschingbauer'

  .. jupyter-execute::
  
     hasattr(person, 'firstname')

  .. jupyter-execute::
  
     getattr(person, 'firstname')

  .. jupyter-execute::
  
     hasattr(person, 'svnr')

  .. jupyter-execute::
     :raises:

     getattr(person, 'svnr')

  .. jupyter-execute::
  
     setattr(person, 'svnr', '1037190666')

  .. jupyter-execute::
  
     print('Boing, now having an ID', person.svnr)
