.. ot-topic:: python.misc.ai.linear_regression
   :dependencies: python.swdev.venv, 
		  python.misc.ai.machine_learning_intro

Linear Regression
=================

.. contents::
   :local:

Topic Overview
--------------

`Linear Regression
<https://en.wikipedia.org/wiki/Linear_regression>`__ serves as an
introductory example to "data science". The algorithm is simple to
use, and the problems (predictions, usually) that it solves are easy
to understand.

Here we use weather history data [#weather-history-data]_ to
demonstrate how

* a model is built
* a model is verified
* a model is used to *predict*

To keep the demo simple, the set of *input features* is
one-dimensional - containing only the minimum day temperature -, as is
the set of *output features* - maximum day temperature. Normally, at
least the input set is multi dimensional, and carefully chosen. The
bigger part of data science revolves around just this discipline -
choosing the set of input features.

Also, you will agree that is complete nonsense to choose "minimum day
temperature" as single input feature, and to predict the maximum day
temperature from it. We do just that.

Jupyter Notebook
----------------

A :doc:`Jupyter Notebook <linear_regression>` (download:
:download:`linear_regression.ipynb`) is the heart of the topic. It has
much of the code, together with explanations.

.. toctree::

   linear_regression.ipynb

Running Code
------------

While such notebooks are cute for research papers and for trying
around, one should not use them as an IDE and/or runtime
environments - *they are not*.

:doc:`Here <code>`'s a running program that does the same, but does
not show the fancy graphs that nobody needs.

Dataset
-------

Both the notebook and the program use a :doc:`test dataset
<history_data>` (download: :download:`history_data.csv`).

.. toctree::
   :hidden:

   code
   history_data

.. rubric:: Footnotes

.. [#weather-history-data] Although such data is always the first
			   dataset every aspiring data scientist uses,
			   it is not easy find one free dataset. I
			   spent the bigger part of the research for
			   this set of topics searching for
			   appropriate datasets.

Topic Dependencies
------------------

.. ot-graph::
   :entries: python.misc.ai.linear_regression

