Clientside Graph Rendering
==========================

* Investigate Javascript graph rendering packages
* Prefer one that can do fisheye views
* Embed graph information into site, analogous to what's done
  currently with ``dot`` (from the `GraphViz package
  <https://graphviz.org/>`__) generated inline SVGs.
* Based upon that, implement the rendering.

.. jf-task:: topic.web.ui.dot_alternatives
   :initial-estimate: 40
   :dependencies: topic.basics.basic_dependencies,
		  topic.basics.python_testset,
		  topic.web.ui.dot_alternatives
