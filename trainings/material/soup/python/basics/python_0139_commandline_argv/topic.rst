.. ot-topic:: python.basics.python_0139_commandline_argv
   :dependencies: python.basics.python_0130_syntax_etc,
		  python.basics.python_0125_running

.. include:: <mmlalias.txt>


Commandline Arguments (``sys.argv``)
====================================

.. contents::
   :local:

Commandline Arguments
---------------------

.. sidebar:: Further information: ``argparse``

   On top of ``sys.argv``, the ``argparse`` module
   (:doc:`documentation <python:library/argparse>`) provides further
   functionality to parse commandline parameters.

**Python is lean:**

* Very few *built-in* functionality (compared to other languages)
* Extension through *modules*
* First (and most used): ``sys``

.. literalinclude:: args.py
   :caption: :download:`args.py`
   :language: python

.. code-block:: console

   $ python args.py one argument
   ['args.py', 'one', 'argument']
   0: args.py
   1: one
   2: argument
