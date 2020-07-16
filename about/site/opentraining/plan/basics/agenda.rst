.. include:: <mmlalias.txt>

Agenda Computation
==================

*Use case*: see :doc:`here <../../usecases/agenda>`.

Based upon the entry points into the graph (determined by talking to
the customer),

* Compute a subgraph
* Compute its `transitive reduction
  <https://networkx.github.io/documentation/stable/reference/algorithms/generated/networkx.algorithms.dag.transitive_reduction.html>`__
* `Sort nodes topologically
  <https://networkx.github.io/documentation/stable/reference/algorithms/generated/networkx.algorithms.dag.topological_sort.html>`__
* ... and output that list in reverse order |longrightarrow| agenda

.. jf-task:: topic.basics.agenda
   :dependencies: topic.basics.basic_dependencies,
		  topic.basics.python_testset
   :initial-estimate: 4
   :percent-done: 0

