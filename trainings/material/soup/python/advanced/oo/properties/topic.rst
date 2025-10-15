.. include:: <mmlalias.txt>


Properties
==========

Motivation
----------

* Pythonicity: *attributes should be public*

  * Python is a language of consenting adults
  * Private would be a double underscore (``__``) prefix
    |longrightarrow| does not play well with inheritance

  .. jupyter-execute::
  
     class Person:
         'class with attributes left unprotected'
         def __init__(self, firstname, lastname):
             self.firstname = firstname
             self.lastname = lastname

* Can add a property later if necessary

  .. jupyter-execute::
  
     person = Person('Joerg', 'Faschingbauer')
     person.lastname = 'Haubentaucher'    # <--- write access possible but unwanted

Readonly Attributes
-------------------

* ``@property``
* Built-in decorator (:doc:`../../decorators/topic`)
* |longrightarrow| read-only attribute

  .. jupyter-execute::
  
     class Person:
         def __init__(self, firstname, lastname):
             self._firstname = firstname
             self._lastname = lastname
     
         @property
         def firstname(self):
             return self._firstname
     
         @property
         def lastname(self):
             return self._lastname

* Attributes are protected

  .. jupyter-execute::
     :raises:
  
     person = Person('Joerg', 'Faschingbauer')
     person.lastname = 'Haubentaucher'

And Write Access?
-----------------

* ``@attrname.setter``
* Decorator around setter method ``attrname``

  .. jupyter-execute::
  
     class Person:
         def __init__(self, firstname, lastname):
             self._firstname = firstname
             self._lastname = lastname
     
         @property
         def firstname(self):
             return self._firstname
     
         @property
         def lastname(self):
             return self._lastname
     
         @lastname.setter
         def lastname(self, n):
             if n == 'Haubentaucher':
                 self._lastname = n
             else:
                 raise AttributeError('no!')

* Fine grained access control on attribute

  .. jupyter-execute::
  
     person = Person('Joerg', 'Faschingbauer')
     person.lastname = 'Haubentaucher'

  .. jupyter-execute::
     :raises:
  
     person.lastname = 'Meier'

Calculated Attributes
---------------------

.. jupyter-execute::

   class Person:
       def __init__(self, firstname, lastname):
           self.firstname = firstname
           self.lastname = lastname
   
       @property
       def fullname(self):
           return f'{self.firstname} {self.lastname}'

.. jupyter-execute::

   person = Person('Joerg', 'Faschingbauer')
   person.fullname
