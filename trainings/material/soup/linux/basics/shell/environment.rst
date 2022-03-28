.. ot-topic:: linux.basics.shell.environment
   :dependencies: linux.basics.intro.process

.. include:: <mmlalias.txt>


Environment Variables
=====================

.. contents::
   :local:

One More Process Attribute: The Environment
-------------------------------------------

* Inherited from parent process
* List of ``name=value`` pairs (all strings)
* |longrightarrow| *Environment variables*

List of currently set environment variables ...

.. code-block:: console

   $ env
   SHELL=/bin/bash
   EDITOR=emacs
   PWD=/home/jfasch/work/jfasch-home/trainings/material/soup/linux/basics/shell
   HOME=/home/jfasch
   USERNAME=jfasch
   PATH=/home/jfasch/HomeBrain/bin:/home/jfasch/.local/bin:/home/jfasch/bin:/home/jfasch/HomeBrain/bin:/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin
