S5 Integration
==============

.. toctree::

   tests/index

Work in Progress: S5 Web Slides
-------------------------------

The conversion of my old `Latex Beamer slides
<https://ctan.org/pkg/beamer>`__ to the `S5 slide format
<https://meyerweb.com/eric/tools/s5/>`__ is *work in progress*. To put
it more precisely, I am converting to `reStructuredText
<https://docutils.sourceforge.io/rst.html>`__, which, in turn, is
converted to S5 by the `rst2s5
<https://docutils.sourceforge.io/docs/user/slide-shows.html>`__ tool.

This makes sense because the entire site is massaged with `Sphinx
<https://www.sphinx-doc.org/en/master/>`__, which itself builds upon
reStructuredText.

You can view the state of conversion in the (rather huge) table in
:doc:`hier </trainings/material/index>`.

Implementation Notes
--------------------

S5 (via `rst2s5
<https://docutils.sourceforge.io/docs/user/slide-shows.html>`__) isnot
as integrated as I want it to be.

.. todo::

   Big fat TODO: S5 integration!!

Lets say, there is a reST file ``some-slides.rst`` that contains slide
material.

* ``some-slides.rst`` is rendered during the regular Sphinx build
  process. This means that if it uses S5/reST specific markup (for
  example ``.. class:: handout``), then Sphinx warns and produces an
  error into the output HTML.
* ``some-slides.rst`` must contain a ``download`` role for a file
  ``some-slides.s5.html`` somewhere near the top (inside a
  ``sidebar``, ideally),

  .. code-block:: rst

     .. sidebar:: Slideshow

	:download:`some-slides.s5.html`

* ``some-slides.s5.html`` (the S5 HTML) is created *manually*, into
  the same directory as ``some-slides.rst``.

  .. code-block:: console

     $ rst2s5.py --theme-url ../../_static/s5/ui/default \
		  some-slides.rst some-slides.s5.html

  ``--theme-url`` is given so that downloader can find the S5
  theme. The funky path is given because

  * ``/_static/s5/ui/default`` is the S5 theme (committed there)
  * Sphinx places download link targets in (for example)
    ``/_downloads/7a046b2e956b892f20b3485964f7b2cf/some-slides.s5.html``. The
    relative, two-up, URI works well because of that.
