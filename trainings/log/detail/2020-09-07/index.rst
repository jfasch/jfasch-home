.. include:: <mmlalias.txt>

Python Advanced (7.9.2020 - 10.9.2020)
======================================

.. contents::
   :local:

.. sidebar:: *Training Information*

   **Start**

   Montag 7.9.2020, 8:00

   **Official Description**

   :doc:`/trainings/repertoire/python-advanced`

   **Material**

   .. csv-table::

      :doc:`OpenTraining </about/site/opentraining/index>` Topics, :doc:`/trainings/material/soup/python/python`
      PDF Slides (obsolete), :download:`Python </trainings/material/pdf/300-python.pdf>`

This is a training for a team which is already experienced in Python
programming. There were some special requirements for the training,
such as to loose a couple of words about AI/machinelearning and other
topics, as well as a fuzzy "bring us advanced stuff".

Preparation
-----------

Workspace Setup
...............

* :doc:`/trainings/material/soup/draft/installation`
* :doc:`/trainings/material/soup/draft/vscode`

Github for Exercises
....................

Please create `Github <https://github.com/>`__ accounts and send them
to training@faschingbauer.co.at. We will do exercises via a private
repository on Github. (See the :doc:`privacy statement
</trainings/codex>`.)

Advanced Core Python Topics
---------------------------

Python is easy; one can solve nontrivial problems in only a few lines
of code, in no time. This does not mean that you have to fully
understand the language - which is good because this is what makes the
language easy.

On the other hand, there's always a line to cross where you wish you
knew more. Here the more advanced core Python topics that shall be
covered.

* :doc:`/trainings/material/soup/python/python_1010_generators_yield/topic`
* :doc:`/trainings/material/soup/draft/context_manager`
* :doc:`/trainings/material/soup/draft/encoding`
* :doc:`/trainings/material/soup/draft/exceptions`
* :doc:`/trainings/material/soup/python/python_1200_modules/topic`

  * TODO: separate *module usage* (|longrightarrow| "The ``import``
    statement", ``PYTHONPATH``, etc.)  from *module content*
    (``__all__``, ``__init__.py``, etc.)

* :doc:`/trainings/material/soup/draft/duck-typing`
* :doc:`/trainings/material/soup/draft/special_methods`
* :doc:`/trainings/material/soup/draft/starargs/topic`
* :doc:`/trainings/material/soup/draft/closures/topic`
* :doc:`/trainings/material/soup/draft/decorators/topic`

Special Topics
--------------

* :doc:`/trainings/material/soup/draft/ai`

  * :doc:`/trainings/material/soup/draft/machine-learning-intro`
  * :doc:`/trainings/material/soup/draft/linear-regression/topic`
  * :doc:`/trainings/material/soup/draft/k-means`

* :doc:`/trainings/material/soup/draft/mysql`
* Unit Testing, Test Driven Development, Design Patterns

  * Excerpt from :doc:`/trainings/repertoire/unittests`
    (:download:`/trainings/material/pdf/060-design-patterns-unittests.pdf`)
  * :doc:`/trainings/material/soup/python/python_5600_unittest/topic`

* Web programming with Jango and/or Flask

Graph
-----

.. jf-topicgraph::
   :entries: drafts.ai.linear_regression,
	     drafts.ai.k_means,
	     drafts.duck_typing,
	     drafts.context_manager,
	     drafts.special_methods,
	     drafts.closures,
	     drafts.decorators,
	     drafts.starargs,
	     python.swdev.python_1200_modules,
	     python.python_1010_generators_yield,
	     drafts.encoding,
	     drafts.mysql,
	     drafts.installation,
	     drafts.exceptions
