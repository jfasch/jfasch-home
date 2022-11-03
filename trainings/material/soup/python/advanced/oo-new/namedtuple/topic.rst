.. ot-topic:: python.advanced.oo_new.namedtuple
   :dependencies: python.advanced.oo_new.classes_and_dicts

.. include:: <mmlalias.txt>


``collections.namedtuple``
==========================

.. contents::
   :local:

.. sidebar::

   **Documentation**

   * `collections
     <https://docs.python.org/3/library/collections.html>`__

Shortcut For Simple Data-Holding Classes
----------------------------------------

.. code-block:: python

   class Person:
       def __init__(self, firstname, lastname):
           self.firstname = firstname
           self.lastname = lastname

... is the same as ...

.. literalinclude:: named-tuple-simple.py
   :caption: :download:`named-tuple-simple.py`
   :language: python

.. command-output:: python named-tuple-simple.py
   :cwd: .
   
Constructing From Iterable: ``_make()``
---------------------------------------

* Data-holding classes are popular with tabular data (:doc:`CSV
  <../../../misc/csv/topic>`, :doc:`databases <../../../misc/db/group>`, ...)
* Rows are *iterable*
* |longrightarrow| ``someclass._make()``

.. literalinclude:: named-tuple-csv.py
   :caption: :download:`named-tuple-csv.py`
   :language: python

.. command-output:: python named-tuple-csv.py
   :cwd: .

Convert To ``dict``: ``_asdict()``
----------------------------------

.. literalinclude:: named-tuple-asdict.py
   :caption: :download:`named-tuple-asdict.py`
   :language: python

.. command-output:: python named-tuple-asdict.py
   :cwd: .
