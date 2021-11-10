About This Site
===============

.. contents::
   :local:

.. image:: /_images/python-powered-w.svg
   :align: right
   :alt: Python-powered logo
   :scale: 50%

License: `GPLv3 <http://www.gnu.org/licenses/gpl-3.0.html>`__
-------------------------------------------------------------

The source of this site is licensed under the `GPLv3
<http://www.gnu.org/licenses/gpl-3.0.html>`__.

**Why apply a software license to a website?**

This site contains material for courses that I give. The course
material is structured much like software (topics *depend on* other
topics; see for example :doc:`here
</trainings/material/soup/kernel/index>` and :doc:`here
</trainings/material/soup/python/group>`)

See also `this discussion over at LWN
<https://lwn.net/Articles/394306/>`__.

**Why not an Attribution-ShareAlike (CC BY-SA) license?**

Like with software that I write, I don't want anybody to make money
with my course material *without* giving modifications back.

I'm not a lawyer, but I understand that `CC BY-SA
<https://creativecommons.org/licenses/by-sa/3.0/>`__ permits exactly
that.

**Why not the** `GNU Free Documentation License <https://www.gnu.org/licenses/fdl.html>`__

A while ago, there was a `Debian resolution
<https://www.debian.org/vote/2006/vote_001>`__ to not use the GFDL
because it is *too* restrictive. `This article
<https://web.archive.org/web/20080515215935/http://home.twcny.rr.com/nerode/neroden/fdl.html>`__
describes pretty much the same issues.

**How do I choose a license altogether?**

I have no idea. https://choosealicense.com/ appears helpful.

Github
------

Progress is happening on `Github
<https://github.com/jfasch/jfasch-home>`__.

.. code-block:: console

   $ git clone https://github.com/jfasch/jfasch-home.git

Sphinx
------

Built with `the wonderful Sphinx <https://www.sphinx-doc.org/>`__
documentation generator. Homepages generally contain content, which is
not much different from documentation - so yes, Sphinx is a really
great static website generator. It lets me focus myself on content,
with an eye towards structure and built-in link consistency (it won't
let me break links by moving documents around).

Installation Instructions
-------------------------

.. sidebar:: ``pip`` and ``venv``

   * :doc:`/trainings/material/soup/python/swdev/pip/topic`
   * :doc:`/trainings/material/soup/python/swdev/venv/topic`

Clone Repo, create and populate a virtual environment (as yourself,
not ``root``).

.. code-block:: console

   $ git clone https://github.com/jfasch/jfasch-home.git
   $ python -m venv ~/venv/jfasch-home-venv
   $ . ~/venv/jfasch-home-venv/bin/activate
   (jfasch-home-venv) $ pip install -r requirements.txt

Install external dependencies (as ``root``). This is Fedorish; your
mileage might vary.

.. code-block:: console

   # dnf install pandoc graphviz dia

* ``pandoc`` for markdown handling in jupyter notebooks
* ``graphviz`` for those funky dependency graphs (:doc:`example
  </trainings/material/soup/python/swdev/pip/topic>`)
* ``dia`` for historical baggage (convert ``.dia`` vector drawings to
  SVG)

Work in Progress
----------------

Like any software, this is work in progress. That work is sloppily
tracked :doc:`here <work-in-progress/index>`.

More
----

.. toctree::
   :maxdepth: 1

   opentraining/index
   work-in-progress/index
   recipes/index
   courses/index
   org/index
