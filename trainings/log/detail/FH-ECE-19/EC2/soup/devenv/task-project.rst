.. ot-task:: ec2.devenv.project
   :responsible: joerg.faschingbauer
   :percent-done: 30
   :dependencies: ec2.devenv.sshfs, 
		  ec2.devenv.sphinx_intro,
		  ec2.devenv.virtualbox


Create Initial Project Structure
================================

.. contents::
   :local:

Description
-----------

* Add tests/
* Doc:

  * ``pytest`` usage in project
  * Structure
  * Deployment to Raspi. Add references to

    * :doc:`task-sshfs`
    * :doc:`/trainings/material/soup/python/draft/pip/topic`
    * :doc:`/trainings/material/soup/python/draft/venv/topic`

  * Sphinx build
  * VirtualBox usage

Dependencies
------------

.. ot-graph::
   :entries: ec2.devenv.project
