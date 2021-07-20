Sphinxish
=========

Jupyter Notebooks
-----------------

The `nbsphinx <https://nbsphinx.readthedocs.io/>`__ extension is
capable of rendering notebooks, *nicely*! A few things to keep in mind
though.

* The toplevel heading is the document title to Sphinx - same as with
  Sphinx's own reST documents. Give one toplevel heading at the
  beginning, all others one deeper.
* Do not use trailing underscores in notebook text. For example, this
  test (taken from an ``.ipynb`` file directly, note the ``labels_``),

  .. code-block::

     "source": [
      "#### Use the result: output-properties\n",
      "* labels_: cluster membership for each point in the input sequence\n",
     ]
  
  brings a warning,

  .. code-block::

     /home/jfasch/work/jfasch-home/courses/records/2019-11-12/code/BigPlan.ipynb:686: WARNING: Unknown target name: "labels".

Running Sphinx From Source
--------------------------

.. code-block:: console

   $ export PYTHONPATH=$HOME/work/sphinx:$PYTHONPATH
   $ python ~/work/sphinx/sphinx/cmd/build.py -W --keep-going --no-color ~/work/jfasch-home /tmp/jfasch-home/html
