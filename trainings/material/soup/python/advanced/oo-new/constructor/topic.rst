.. ot-topic:: python.advanced.oo_new.constructor
   :dependencies: python.advanced.oo_new.classes_and_dicts

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

.. literalinclude:: constructor.py
   :caption: :download:`constructor.py`
   :language: python

.. command-output:: python constructor.py
   :cwd: .

And ``self``?
-------------

* ``class Person`` |longrightarrow| object of type ``type``
* Types are callable |longrightarrow| creates *instance*
* If class has ``__init__`` method defined, then that is called to
  *initialize* the object
* *Invoked* with two parameters

  .. code-block:: python

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
