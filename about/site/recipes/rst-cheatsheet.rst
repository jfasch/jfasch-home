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

References to a section in the middle of a document requires

* Adding a section label
* Referring to that label using the ``:ref:`` role (either from inside
  the same document, or from any other document)

Example follows ...

.. _dummy-section:

Dummy Section That We Refer To
``````````````````````````````

This section is referred to by the next section. It requires a section
label, like so:

.. code-block:: rst

   .. _dummy-section:
   
   Dummy Section That We Refer To
   ``````````````````````````````
   
   This section is referred to by the next section.

Another Section Contains a Link To The Referred Section Above
`````````````````````````````````````````````````````````````

One refers to the label we created in the :ref:`section above
<dummy-section>` using the ``:ref:`` role:

.. list-table::
   :align: left

   * * :ref:`dummy-section`
     * .. code-block:: rst

          :ref:`dummy-section`

   * * :ref:`Custom referred-to link name <dummy-section>`
     * .. code-block:: rst

          :ref:`Custom referred-to link name <dummy-section>`

Footnotes
---------

A reference to a footnote [#a_footnote]_:

.. code-block:: rst

   A reference to a footnote [#a_footnote]_:

A "Footnotes" footer block:

.. rubric:: Footnotes
.. [#a_footnote] Blah

.. code-block:: rst

   .. rubric:: Footnotes
   .. [#a_footnote] Blah
