.. include:: <mmlalias.txt>

Agenda Computation
==================

Based upon the entry points into the graph (determined by talking to
the customer),

* Compute a subgraph
* Compute its transitive reduction
* Sort nodes topologically
* ... and output that list in reverse order |longrightarrow| agenda

See :doc:`here <../../demo/agenda>` for the use case.

.. jf-task:: topic.basics.agenda
   :dependencies: topic.basics.basic_dependencies,
		  topic.basics.python_testset
   :initial-estimate: 4
   :percent-done: 0

