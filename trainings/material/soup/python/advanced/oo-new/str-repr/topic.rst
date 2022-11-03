.. ot-topic:: python.advanced.oo_new.str_repr
   :dependencies: python.advanced.oo_new.methods

.. include:: <mmlalias.txt>


``str()`` And ``repr()``
========================

.. contents::
   :local:

Stringification And Representation
----------------------------------

* ``str(obj)``: nicely made-up string, used by e.g. ``print()``
* ``repr(obj)``: object *representation*, ideally suitable as
  ``eval()`` input
* Default: prints something useless (class name and object identity)

.. literalinclude:: str-repr-default.py
   :caption: :download:`str-repr-default.py`
   :language: python

.. command-output:: python str-repr-default.py
   :cwd: .

Special Object Methods: ``__str__()``, ``__repr__()``
-----------------------------------------------------

* ``__str__()``: return human readable string, describing the
  object. Called, for example, by ``print()``.
* ``__repr__()``: object representation. Usually the code to
  re-construct the object.

.. literalinclude:: str-repr-implemented.py
   :caption: :download:`str-repr-implemented.py`
   :language: python

.. command-output:: python str-repr-implemented.py
   :cwd: .
