.. ot-topic:: python.basics.python_0139_commandline_argv
   :dependencies: python.basics.python_0130_syntax_etc,
		  python.basics.python_0125_running

.. include:: <mmlalias.txt>


Commandline Arguments (``sys.argv``)
====================================

.. contents::
   :local:

Operating Systems and Programs
------------------------------

* *The Shell* is just one way to start a program

  * Generally speaking, programs are started by other programs (the
    shell is just an ordinary program, after all)
  * |longrightarrow| service manager, Cron-Jobs

* *Deal* between OS and program

  * Argument vector (|longrightarrow| ``argv``)
  * Environment variables
  * Exit status

.. list-table::
   :align: left

   * * .. code-block:: console

          $ ls -l

     * Argument vector: ``['ls', '-l']``

Commandline Arguments in Python
-------------------------------

.. literalinclude:: args.py
   :caption: :download:`args.py`
   :language: python

.. list-table::
   :align: left

   * * .. command-output:: python args.py Joerg Faschingbauer
          :cwd: .

     * Argument vector: ``['args.py', 'Joerg', 'Faschingbauer']``

Cosmetics: Rudimentary Argument Parsing
---------------------------------------

.. sidebar:: Further information: ``argparse``

   On top of ``sys.argv``, the ``argparse`` module provides further
   functionality to parse commandline parameters.

   See :doc:`/trainings/material/soup/python/drafts/argparse/topic`

.. literalinclude:: args-parsing.py
   :caption: :download:`args-parsing.py`
   :language: python

.. command-output:: python args-parsing.py Joerg
   :cwd: .
   :returncode: 1
