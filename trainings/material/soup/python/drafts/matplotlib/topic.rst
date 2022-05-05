.. ot-topic:: python.drafts.matplotlib
   :dependencies: python.swdev.venv,
		  python.swdev.pip


Matplotlib
==========

.. sidebar:: Links

   * `Pyplot tutorial
     <https://matplotlib.org/stable/tutorials/introductory/pyplot.html>`__

.. contents::
   :local:

Installation
------------

Best to create a :doc:`virtual environment
</trainings/material/soup/python/swdev/venv/topic>`

.. code-block:: console

   $ python -m venv ~/env-for-my-work
   $ . ~/env-for-my-work/bin/activate
   (env-for-my-work) $

Install via :doc:`Python Package Index
</trainings/material/soup/python/swdev/pip/topic>`

.. code-block:: console

   (env-for-my-work) $ python -m pip install matplotlib

Basic Usage
-----------

.. literalinclude:: basic.py
   :language: python
   :caption: :download:`basic.py`

Axis Ranges
-----------

Axis ranges are specified in the form ``[xmin, xmax, ymin, ymax]``, like so,

.. literalinclude:: axis.py
   :language: python
   :caption: :download:`axis.py`
