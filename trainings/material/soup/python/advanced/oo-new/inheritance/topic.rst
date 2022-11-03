.. ot-topic:: python.advanced.oo_new.inheritance
   :dependencies: python.advanced.oo_new.classes_and_dicts,
		  python.advanced.oo_new.constructor

.. include:: <mmlalias.txt>


Inheritance
===========

.. contents::
   :local:

Extending Existing Classes
--------------------------

* ``Person`` is not enough
* Want ``Employee``
* *is-a* ``Person``, but with additional features
* |longrightarrow| *Implementation inheritance*

.. literalinclude:: employee-basic.py
   :caption: :download:`employee-basic.py`
   :language: python

*Method Resolution Order*: How Is ``__init__()`` Found?
-------------------------------------------------------

* ``Employee``: no ``__init__()``
* ``Person``: found
* |longrightarrow| ``Person.__init__()`` called

Additional Feature: Salary
--------------------------

* ``Employee`` needs its own constructor (added ``salary``)
* Calls base classe constructor |longrightarrow| ``super()``

.. literalinclude:: employee-salary.py
   :caption: :download:`employee-salary.py`
   :language: python

.. command-output:: python employee-salary.py
   :cwd: .

Want Manager
------------

.. literalinclude:: manager.py
   :caption: :download:`manager.py`
   :language: python

.. command-output:: python manager.py
   :cwd: .

Introspecting Inheritance: ``isinstance()``, ``issubclass()``
-------------------------------------------------------------

* ``isinstance(object, cls)``: is ``object`` an instance of ``cls``
  (or of a base class thereof)?
* ``issubclass(cls, parentcls)``: is ``cls`` a subclass of
  ``parentcls``?

  * Funnily a class is considered a subclass of itself

.. literalinclude:: manager-introspection.py
   :caption: :download:`manager-introspection.py`
   :language: python

.. command-output:: python manager-introspection.py
   :cwd: .

Add ``__str__()``, Creatively
-----------------------------

.. literalinclude:: manager-str.py
   :caption: :download:`manager-str.py`
   :language: python

.. command-output:: python manager-str.py
   :cwd: .

