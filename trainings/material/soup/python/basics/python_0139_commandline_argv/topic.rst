.. ot-topic:: python.basics.python_0139_commandline_argv
   :dependencies: python.basics.python_0130_syntax_etc

.. include:: <mmlalias.txt>


How to Bring Commandline Parameters into a Program
==================================================

.. contents::
   :local:

Commandline Arguments
---------------------

**Python is lean:**

* Very few *built-in* functionality (compared to other languages)
* Extension through *modules*
* First (and most used): ``sys``

.. code-block:: python
   :caption: File ``args.py``

   #!/usr/bin/python
   import sys
   print(sys.argv[0])
   print(sys.argv[1])
   print(sys.argv[2])

.. code-block:: console

   $ ./x.py one argument
   ./x.py
   one
   argument

Comments vs. Documentation
--------------------------

**As in many other script languages ...**

::

   # this is a very important comment, which is
   # definitely worth a read

**Docstrings** (slightly off-topic)

* First string in a function, module, class, or method
* Tools to generate documentation from it

::

   def do_something(some_number):
       """ Doing something with a number """
       # some code here ...

::

   >>> print(do_something.__doc__)
   Doing something with a number

