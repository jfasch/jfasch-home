.. meta::
   :description: Sphinx/reStructured text markup cheat sheet
   :keywords: sphinx, restructured text, cheat sheet

reStructuredText Cheat Sheet
============================

.. contents::
   :local:

.. note::

   Above *Table of Contents* is generated like so:
   
   .. code-block:: rst
   
      .. contents::
         :local:

   HTML metadata given like so (best at the top of the page)

   .. code-block:: rst

      .. meta::
         :description: Sphinx/reStructured text markup cheat sheet
         :keywords: sphinx, restructured text, cheat sheet
   
Further Information
-------------------

* `reStructuredText Directives
  <https://docutils.sourceforge.io/docs/ref/rst/directives.html>`__
* `ReadTheDocs: Guides for documentation authors
  <https://docs.readthedocs.io/en/stable/guides/authors.html>`__

Links
-----

Local Documents
...............

.. list-table::
   :align: left

   * * :doc:`../index`
     * .. code-block:: rst

          :doc:`../index`

   * * :doc:`index`
     * .. code-block:: rst

          :doc:`index`

   * * :doc:`/index`
     * .. code-block:: rst

          :doc:`/index`

   * * :doc:`Overridden Title </index>`
     * .. code-block:: rst

          :doc:`Overridden Title </index>`

External Links
..............

.. list-table::
   :align: left

   * * `LWN.net (my favorite site) <https://lwn.net/>`__
     * .. code-block:: rst

          `LWN.net (my favorite site) <https://lwn.net/>`__

Section References
..................

.. _dummy-section:

Dummy Section That We Refer To
``````````````````````````````

This section is referred to by the next section.

.. code-block:: rst

   .. _dummy-section:
   
   Dummy Section That We Refer To
   ``````````````````````````````
   
   This section is referred to by the next section.

Another Section Contains a Link To The Referred Section Above
`````````````````````````````````````````````````````````````

.. list-table::
   :align: left

   * * :ref:`dummy-section`
     * .. code-block:: rst

          :ref:`dummy-section`

   * * :ref:`Custom referred-to link name <dummy-section>`
     * .. code-block:: rst

          :ref:`Custom referred-to link name <dummy-section>`
