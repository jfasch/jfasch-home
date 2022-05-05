.. ot-topic:: python.drafts.argparse
   :dependencies: python.basics.python_0139_commandline_argv

.. include:: <mmlalias.txt>


Commandline Parsing with ``argparse``
=====================================

.. sidebar:: Documentation

   * :doc:`python:library/argparse`
   * :doc:`python:howto/argparse`

.. contents::
   :local:

Basics
------

* Commandline parsing using only raw ``sys.argv`` is tedious (see
  :doc:`here
  </trainings/material/soup/python/basics/python_0139_commandline_argv/topic>`)
* Nobody wants positional arguments
* Error checking is rarely done correctly |longrightarrow|
  ``IndexError`` when accessing an argument the user didn't pass

The following program would be called like so ...

.. code-block:: console

   $ python raw.py 0.5 samples.csv

.. literalinclude:: raw.py
   :language: python

If the user didn't give the filename argument, position 2 would be
invalid in ``sys.argv`` ...

.. code-block:: console

   $ python raw.py 0.5 
   Traceback (most recent call last):
     File "/home/jfasch/work/jfasch-home/trainings/material/soup/python/drafts/argparse/raw.py", line 4, in <module>
       outputfilename = sys.argv[2]
   IndexError: list index out of range

Handling Positional Arguments
-----------------------------

.. literalinclude:: positional.py
   :language: python

Omitting the second (filename) argument leads to an error, clearly,
but that comes with a *usage* message,

.. code-block:: console

   $ python positional.py 0.5
   usage: positional.py [-h] interval outputfilename
   positional.py: error: the following arguments are required: outputfilename

The user will then say what she is suggested,

.. code-block:: console

   $ python positional.py -h
   usage: positional.py [-h] interval outputfilename
   
   positional arguments:
     interval        interval (in seconds) that we retrieve samples
     outputfilename  file to write samples to ("-" for stdout)
   
   optional arguments:
     -h, --help      show this help message and exit

Ah:

.. code-block:: console

   $ python positional.py 0.5 samples.csv
   ...

The ``type`` parameter to ``add_argument()`` helps, too,

.. code-block:: console

   $ python positional.py 0,5 samples.csv
   usage: positional.py [-h] interval outputfilename
   positional.py: error: argument interval: invalid float value: '0,5'

Handling Named Arguments: ``--interval`` ...
--------------------------------------------

Most people prefer named arguments over positional arguments, for
readability ...

.. code-block:: console

   $ python named.py --interval 0.5 --outputfilename samples.csv
   ...

This is as simple as ...

.. literalinclude:: named.py
   :language: python

The command can then be invoked in many ways ...

.. code-block:: console
   :caption: Full long options (best to use in shell scripts, for
             readability)

   $ python named.py --interval 0.5 --outputfilename samples.csv

.. code-block:: console
   :caption: Short (single character) options

   $ python named.py -i 0.5 -o samples.csv

.. code-block:: console
   :caption: Giving unique prefixes is sufficient with long options

   $ python named.py --int 0.5 --ou samples.csv
