.. include:: <mmlalias.txt>


Project Setup
=============

.. contents::
   :local:

Setting Paths
-------------

Source the ``enter.sh`` file in your project's root directory (let's
say ``/home/you/project`` is that directory),

.. code-block:: console

   $ source /home/you/project/enter.sh

Create (And Activate) A Virtual Environment For The Project
-----------------------------------------------------------

We create a virtual environment for this course in
``/home/you/python-course``, 

.. code-block:: console

   $ python -m venv /home/you/python-course

Activate that environment for your work on this project,

.. code-block:: console

   $ source /home/you/python-course/bin/activate

Install Requirements
--------------------

.. sidebar::

   * :doc:`/trainings/material/soup/python/swdev/venv/topic`

Install the project's requirements,

.. code-block:: console

   (python-course) $ python -m pip install -r /home/you/project/requirements.txt
   ... roedel ...
