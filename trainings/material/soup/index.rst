Topics
======

Newer training material is written in `reStructuredText
<https://docutils.sourceforge.io/rst.html>`__, and massaged by a
Sphinx extension to form a network of *topics* as I call it. This is
:doc:`work in progress </about/site/work-in-progress/topic/index>`.

Topics naturally depend on other topics. Together, topics and their
dependencies form a directed acyclic - see for example :doc:`the full
set of Python topics, laid out as one such graph <python/fullgraph>`.

The Python training has been converted to this format; :doc:`see there
<python/python>` for how this could look like (careful though: *this
is work in progress*).

.. toctree::

   python/python
   list
   graph

.. toctree::
   :hidden:
   :glob:

   */topic

Code
----

Much of the training material is accompanied by a growing code base,
mostly written in Python, C, and C++. For reference, here's the
``CMakeLists.txt`` file that steers the build of C and C++ material.

.. literalinclude:: CMakeLists.txt
   :language: cmake

.. note::

   See :doc:`here </trainings/log/detail/2020-03-30/setup>` for how to
   build the sample code that is referenced.
