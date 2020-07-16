"See Also" Type of Relation
===========================

"Depends On" is the most basic relation in the system; it solves the
problem of maintainability a lot. "Depends On" relations are directed,
and they *must not* build up cycles. (Or a training will possibly last
infinitely.)

Another type of relation is "See Also". It is used to navigate through
the material, having no particular target in mind. "See Also" is also
directed, but it may introduce cycles - just as hyperlinks on The Web
can.

Tasks:

* Add new parameter ``see-also`` to ``jf-topic`` directive.
* Differentiate "Depends On" and "See Also" types of edges using
  `NetworkX <https://networkx.github.io/>`__ edge attributes.
* Modify existing code that currently treats any edge as "Depends On".
* Add "See Also" links as a sidebar to topics.

.. jf-task:: topic.basics.see_also
   :dependencies: topic.basics.basic_dependencies,
		  topic.basics.python_testset
   :initial-estimate: 8
   :percent-done: 0

