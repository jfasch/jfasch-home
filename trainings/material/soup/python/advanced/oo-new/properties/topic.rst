.. ot-topic:: python.advanced.oo_new.properties
   :dependencies: python.advanced.oo_new.classes_and_dicts

.. include:: <mmlalias.txt>


Properties
==========

.. contents::
   :local:

Motivation
----------

* Pythonicity: *attributes should be public*

  * Python is a language of consenting adults
  * Private would be a double underscore (``__``) prefix
    |longrightarrow| does not play well with inheritance
* Can add a property later if necessary

.. literalinclude:: properties-attr-write-access.py
   :caption: :download:`properties-attr-write-access.py`
   :language: python

.. command-output:: python properties-attr-write-access.py
   :cwd: .

Readonly Attributes
-------------------

* ``@property``
* Built-in decorator (:doc:`../../decorators/topic`)
* |longrightarrow| read-only attribute

.. literalinclude:: properties-attr-readonly-attributes.py
   :caption: :download:`properties-attr-readonly-attributes.py`
   :language: python

.. command-output:: python properties-attr-readonly-attributes.py
   :cwd: .

And Write Access?
-----------------

* ``@attrname.setter``
* Decorator around setter method ``attrname``

.. literalinclude:: properties-attr-write.py
   :caption: :download:`properties-attr-write.py`
   :language: python

.. command-output:: python properties-attr-write.py
   :cwd: .

Calculated Attributes
---------------------

.. literalinclude:: properties-calc-attr.py
   :caption: :download:`properties-calc-attr.py`
   :language: python

.. command-output:: python properties-calc-attr.py
   :cwd: .
