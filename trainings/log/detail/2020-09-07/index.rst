.. include:: <mmlalias.txt>

Python Advanced (7.9.2020 - 10.9.2020)
======================================

.. sidebar:: *Training Information*

   .. contents::
      :local:

   **Start**

   Montag 7.9.2020, 9:00

   **Training Description**

   :doc:`/trainings/repertoire/python-advanced`

   **Training Material**

   .. csv-table::

      :doc:`Topics </about/site/opentraining/index>`, :doc:`/trainings/material/soup/python/python`
      PDF Slides (obsolete), :download:`Python </trainings/material/pdf/300-python.pdf>`

Requirements
------------

* Web programming with Jango and/or Flask
* AI, machine learning
* Databases, especially MySQL
* Unit testing, test driven development
* Design patterns

This is a training for a team which is already experienced in Python
programming. Makes sense to shine some light on advanced and
interesting Python features, such as

* :doc:`Iteration and generators
  </trainings/material/soup/python/python_1010_generators_yield/topic>`
* :doc:`Context managers (the "with" statement)
  </trainings/material/soup/draft/context_manager>`
* Encoding. TODO: somehow externalize "encoding" stuff from these:

  * :doc:`/trainings/material/soup/python/python_0330_strings_encoding/topic`
  * :doc:`/trainings/material/soup/python/python_0500_files/topic`

* :doc:`Modules and packages
  </trainings/material/soup/python/python_1200_modules/topic>`. TODO:
  separate *module usage* (|longrightarrow| "The ``import``
  statement", ``PYTHONPATH``, etc.)  from *module content*
  (``__all__``, ``__init__.py``, etc.)
* :doc:`Philosophical excourse: Duck Typing vs. Strict OO
  </trainings/material/soup/draft/duck-typing>` (who could do data
  science if it had to be done using strong typing?)

Agenda
------

TODO:

* calculate toposorted topic list
* verify accuracy of entrypoints against TODO's

.. jf-topicgraph::
   :entries: drafts.ai.linear_regression,
	     drafts.ai.k_means,
	     drafts.duck_typing,
	     drafts.context_manager,
	     drafts.special_methods,
	     python.swdev.python_1200_modules,
	     python.python_1010_generators_yield,
	     python.basics.python_0330_strings_encoding,
	     python.basics.python_0500_files,
	     drafts.mysql,
	     drafts.installation
