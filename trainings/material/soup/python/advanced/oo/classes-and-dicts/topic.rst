.. ot-topic:: python.advanced.oo.classes_and_dicts
   :dependencies: python.basics.python_0150_datatypes_overview_compound

.. include:: <mmlalias.txt>


Classes And Dictionaries
========================

.. contents::
   :local:

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

.. literalinclude:: classes-and-dicts-dict.py
   :caption: :download:`classes-and-dicts-dict.py`
   :language: python

.. command-output:: python classes-and-dicts-dict.py
   :cwd: .

* Much writing
* Many opportunities for bus/typos
* |longrightarrow| **BAD!**

Enter Classes: An Empty Class, And Its Effects
----------------------------------------------

.. literalinclude:: classes-and-dicts-enter-class.py
   :caption: :download:`classes-and-dicts-enter-class.py`
   :language: python

.. command-output:: python classes-and-dicts-enter-class.py
   :cwd: .

**Better**, because ...

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

.. literalinclude:: classes-and-dicts-dynamic-access.py
   :caption: :download:`classes-and-dicts-dynamic-access.py`
   :language: python

.. command-output:: python classes-and-dicts-dynamic-access.py
   :cwd: .
