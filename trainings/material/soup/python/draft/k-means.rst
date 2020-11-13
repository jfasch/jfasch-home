.. jf-topic:: python.drafts.ai.k_means
   :dependencies: python.drafts.venv, 
		  python.drafts.ai.machine_learning_intro,
		  python.drafts.ai.linear_regression

K-Means
=======

.. contents::
   :local:

Topic Overview
--------------

`K-Means <https://en.wikipedia.org/wiki/K-means_clustering>`__ is a
popular *clustering* algorithm. Clustering algorithms fall into the
category *unsupervised learning*. As such, K-Means sorts input data
into a parameterizable set of clusters.

This topic is a wrapper around training material that originates from
an :doc:`inhouse training given to a company
</trainings/log/detail/2019-11-12/index>` specializing in spectral
image analysis; the hard- and software they create is used to classify
chunks of material running by on a conveyor belt. The topic artifacts
might contain terminology from their problem domain (a lot of MATLAB
stuff).

The problem is demonstrated not by dealing with spectral images with
256 planes, but by color-reducing this PNG image

.. image:: /trainings/log/detail/2019-11-12/code/veggie.png

to this

.. image:: /trainings/log/detail/2019-11-12/code/veggie-reduced.png

Artifacts
---------

Like :doc:`linear-regression/topic`, this topic consists of

* A :doc:`Jupyter Notebook
  </trainings/log/detail/2019-11-12/code/BigPlan>` (download:
  :download:`/trainings/log/detail/2019-11-12/code/BigPlan.ipynb`)
* A corresponding Python program (download:
  :download:`/trainings/log/detail/2019-11-12/code/color-reduce.py`)
* Input data, in the form of a PNG (download:
  :download:`/trainings/log/detail/2019-11-12/code/veggie.png`)

Topic Dependencies
------------------

.. jf-topicgraph::
   :entries: python.drafts.ai.k_means
