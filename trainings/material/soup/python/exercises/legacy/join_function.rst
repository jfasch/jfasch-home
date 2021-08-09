.. include:: <mmlalias.txt>

Functions: ``join()``
=====================

.. jf-exercise:: python.exercises.legacy.join_function
   :dependencies: python.exercises.legacy.uniq_function,
		  python.basics.python_0270_functions,
		  python.basics.python_0150_datatypes_overview,
		  python.basics.python_0150_datatypes_overview_compound

Write a function ``join()`` that takes a string list ``strings``
and a string ``separator`` as parameter. It joins ``strings``
together into a single string, using ``separator`` as a
separator. For example,

* ``join(['Hello', 'World'], '-')`` returns ``'Hello-World'``
* ``join(['Hello'], '-')`` returns ``'Hello'``

Dependencies
------------

.. jf-topicgraph::
   :entries: python.exercises.legacy.join_function
