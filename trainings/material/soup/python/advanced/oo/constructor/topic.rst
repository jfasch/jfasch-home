.. ot-topic:: python.advanced.oo.constructor
   :dependencies: python.advanced.oo.classes_and_dicts

.. include:: <mmlalias.txt>


Constructor
===========

.. contents::
   :local:

Motivation
----------

* Manually setting attributes (as in :doc:`../classes-and-dicts/topic`) is clumsy
* Typos/bugs ahead
* |longrightarrow| want a well-defined object *initialization*
* |longrightarrow| want to require user to pass ``firstname`` and
  ``lastname``

.. jupyter-execute::

   class Person:
       def __init__(self, firstname, lastname):
           self.firstname = firstname
           self.lastname = lastname

* Calling the type |longrightarrow| ``__init__()``

.. jupyter-execute::

   person = Person('Joerg', 'Faschingbauer')
   f'firstname: {person.firstname}, {person.lastname}'

And ``self``?
-------------

* ``class Person`` |longrightarrow| object of type ``type``
* Types are callable |longrightarrow| creates *instance*
* If class has ``__init__`` method defined, then that is called to
  *initialize* the object
* *Invoked* with two parameters

  .. jupyter-execute::

     person = Person('Joerg', 'Faschingbauer')

* *Called* with three parameters

  .. code-block:: python

     class Person:
         def __init__(self, firstname, lastname):
	     ...

  * The object being constructed
  * The *instance* under construction

* Object being initialized: ``self`` (name ``self`` is only
  convention)
