.. jf-topic:: python_0130_syntax_etc

.. include:: <mmlalias.txt>

Python: Syntax etc.
===================

.. contents::
   :local:

Syntax: Indentation (1)
-----------------------

**Blocks and Indentation**


* Statements that end with a '``:``' introduce a *block*
* Blocks are *indented*
* End of a block is end of indentation
* *No explicit block delimiters* (like '``{``', '``BEGIN``', ...)
* Indentation is not only *Coding Style*, but also Syntax*

**Careful, you experienced programmers!**

* New bug type: *Indentation Bug*

Syntax: Indentation (2)
-----------------------

::

   i = 0
   while i < 42:
       print('Still not an answer: '+str(i))
       i = i+1
   print('The answer is: '+str(i))

**Keep in mind ...**

* Indentation must be consistent *within one block*
* ... can be mixed otherwise
* Tune your editor's knobs accordingly!

Syntax: Statements and Lines
----------------------------

**Newline ends a statement ...**

::

   answer = 42

**Except ...** Multiline statements

::

   answer = str(42) + \
        ', but only most of the time'

.. list-table::
   :align: left
   
   * - **Braces**
     - **Brackets**
     - **Fun**

   * - ::

          print(
	      "Hello",
	      "World")

     - ::

	  message = [
	      "Hello",
	      "World"]

     - ::

	  message = (
	      "Hello " +
	      "World")

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

