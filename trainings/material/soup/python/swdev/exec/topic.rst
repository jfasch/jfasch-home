.. meta::
   :description: Python - The exec Function
   :keywords: python, exec, configuration

.. include:: <mmlalias.txt>

The ``exec()`` Function
=======================

.. contents::
   :local:

.. ot-topic:: python.swdev.exec
   :dependencies: python.basics.python_0450_dictionaries,
		  python.basics.python_0500_files

Dictionaries Everywhere: Context
--------------------------------

The following program does nothing but create one global variable,
``a``.

.. literalinclude:: globals-simple.py
   :caption: :download:`globals-simple.py`

It does nothing else with that variable, but begs a number of
**questions**:

* *Where is a global variable stored?*
* *What is a variable?*

It turns out that the ``globals()`` function gives the answers.

.. literalinclude:: globals-printed.py
   :caption: :download:`globals-printed.py`

.. command-output:: python globals-printed.py
   :cwd: .

**Answers:**

* *Where is a global variable stored?* In a dictionary: although the
  dictionary that is printed contains a large number of internal
  entries (those containing double-underscores), we clearly see our
  ``a``.
* *What is a variable?* A *string* that is used as the key into that
  dictionary, and whose associated value is the object that the
  variable refers to.

Enter ``exec()``
----------------

* Python executes the *program* above in a *context* - a dictionary
  that is accessed using ``globals()``
* All global objects (variables, functions, modules, ...) are stored
  in that context dictionary under their names. Names are strings

**Question:**

* Is there a Python function that we can use to execute Python code?

**Answer:** sure there is ... ``exec()`` (full documentation `here
<https://docs.python.org/3/library/functions.html#exec>`__)

.. literalinclude:: exec.py
   :caption: :download:`exec.py`

.. command-output:: python exec.py
   :cwd: .

``exec()``, and Context
-----------------------

Passing the ``globals`` parameter (a dictionary) to ``exec()`` is cool
because

* we confine the execution of arbitrary Python code to that dictionary
* no side effects leak into our program
* *the executed code may have side effects outside the program*

  * |longrightarrow| be careful where the code comes from
  * |longrightarrow| don't blindly execute any Python snippets that
    you receive from The Internet

**Omitting** ``globals``, though, modifies the context (what would be
 returned by ``globals()``) of the caller |longrightarrow| *careful*,
 this not usually what one wants.

And What Is This Used For, Realistically?
-----------------------------------------

* The `Ansible <https://www.ansible.com/>`__ remote automation system
  passes Python code around to machines that it controls remotely.
* It enables one to use Python as a configuration file syntax.

Lets illustrate the latter use case with a simple (yet contrived)
example.

* A configuration file contains a list of student records (first and
  last name, matriculation number)
* A program reads that configuration file, and does something with the
  student records (here, we simply print them to ``stdout`` because we
  cannot come up with a something more valuable)

.. literalinclude:: students.conf
   :caption: :download:`students.conf`

.. literalinclude:: print-students.py
   :caption: :download:`print-students.py`

.. command-output:: python print-students.py students.conf
   :cwd: .
