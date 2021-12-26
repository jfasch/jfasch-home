.. ot-topic:: python.advanced.oo.implementation_inheritance
   :dependencies: python.advanced.oo.basics

.. include:: <mmlalias.txt>


From Duck Typing to Implementation Inheritance
==============================================

.. contents::
   :local:

Duck Typed, Unrelated, But Similar
----------------------------------

* Two *unrelated* classes: ``Duck``, ``Goose``

  * Both ``quack()`` and ``walk()`` differently, but similar
  * Both ``live()`` similarly, too

.. literalinclude:: duck-and-goose.py
   :caption: :download:`duck-and-goose.py`

Sharing Code via Common Base Class
----------------------------------

.. literalinclude:: duck-and-goose-related.py
   :caption: :download:`duck-and-goose-related.py`

Base Class Attribute: Initialize Base Using ``super()``
-------------------------------------------------------

.. literalinclude:: duck-and-goose-baseattr.py
   :caption: :download:`duck-and-goose-baseattr.py`
