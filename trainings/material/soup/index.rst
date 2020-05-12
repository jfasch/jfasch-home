The Entire Soup
===============

PDF Downloads
-------------

Most of the training material still is in PDF (written in `Latex
Beamer <https://ctan.org/pkg/beamer>`__).

* :download:`../pdf/020-linux-sysprog--en.pdf`
* :download:`../pdf/040-gnu-make.pdf`
* :download:`../pdf/045-cmake.pdf`
* :download:`../pdf/050-c.pdf`
* :download:`../pdf/055-c++03.pdf`
* :download:`../pdf/056-c++11.pdf`
* :download:`../pdf/060-design-patterns-unittests.pdf`
* :download:`../pdf/070-subversion.pdf`
* :download:`../pdf/100-shell-scripting.pdf`
* :download:`../pdf/300-python.pdf`
* :download:`../pdf/400-kernel.pdf`

Topics
------

Newer training material is written in `reStructuredText
<https://docutils.sourceforge.io/rst.html>`__, and massaged by a
Sphinx extension to form a network of *topics* as I call it. This is
:doc:`work in progress </about/site/work-in-progress/s5/index>`;
here's a list of topics that are currently present in this format.

.. toctree::
   :maxdepth: 1
   :glob:

   */topic

Topics naturally have one or more dependencies to other
topics. Together, topics and their dependencies form a network which
is a *directed acyclic graph*.

.. toctree::

   list
   graph

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
