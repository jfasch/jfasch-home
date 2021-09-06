.. include:: <mmlalias.txt>

Dictionary: Errors?
===================

.. jf-exercise:: python.exercises.legacy.dict_keyerror
   :dependencies: python.basics.python_0150_datatypes_overview_compound 

In the interactive interpreter, create a dictionary like so:

.. code-block:: console

   >>> d = {
   ...     'one': 1,
   ...     'two': 2,
   ... }
   >>> d['one']
   1

What happens if you access a non-existent key?

.. code-block:: console

   >>> d['three']

Dependencies
------------

.. jf-topicgraph::
   :entries: python.exercises.legacy.dict_keyerror
