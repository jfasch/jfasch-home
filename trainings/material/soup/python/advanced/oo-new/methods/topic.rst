.. ot-topic:: python.advanced.oo_new.methods
   :dependencies: python.advanced.oo_new.classes_and_dicts

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

.. literalinclude:: method-object.py
   :caption: :download:`method-object.py`
   :language: python

.. command-output:: python method-object.py
   :cwd: .

Class Methods (``@classmethod``)
--------------------------------

* Not bound to an object
* Cannot be called on an object
* Rather, called on a class
* Implicit first parameter: the *class* object 
* Usually named ``cls`` (again, not necessarily)
* Cool when inheriting/specializing ``Person``

.. literalinclude:: method-class.py
   :caption: :download:`method-class.py`
   :language: python

.. command-output:: python method-class.py
   :cwd: .

Static Methods (``@staticmethod``)
----------------------------------

* Like ``@classmethod``
* Only without implicit parameter
* (Consequentially, does not play well with inheritance)

.. literalinclude:: method-static.py
   :caption: :download:`method-static.py`
   :language: python

.. command-output:: python method-static.py
   :cwd: .

