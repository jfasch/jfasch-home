Python Individualtraining (5 Tage, beginnend 28.10.2019)
========================================================

.. toctree::
   :hidden:
   :maxdepth: -1

   LiveHacking.ipynb

.. sidebar:: Inhalt

   .. contents::
      :local:

Der Kurs nahm eine Woche in Anspruch, da hat so einiges Platz. Hier
die gesammelten Notizen inklusive Code; :doc:`für schnell erklärte
Sachen gibts ein Jupyter Notebook <LiveHacking>` (:download:`Download
<LiveHacking.ipynb>`).

Exercises
---------

Slide 51, "Exercises: Basics"
.............................

Write a program that takes a single digit as commandline parameter.
Print the English word for that digit.

.. literalinclude:: Exercises/digit.py
   :caption: :download:`Exercises/digit.py`
   :language: python

Slide 58, "Exercises: While Loop"
.................................

Write a program that takes an integer commandline parameter and checks
whether that number is prime!

.. literalinclude:: Exercises/prime.py
   :caption: :download:`Exercises/prime.py`
   :language: python

Slide 94, "Exercises: Lists, Loops, Functions"
..............................................

Write a function uniq() that takes a sequence as input. It returns a
list with duplicate elements removed, and where the contained elements
appear in the same order that is present in the input sequence. The
input sequence remains unmodified.

.. literalinclude:: Exercises/uniq.py
   :caption: :download:`Exercises/uniq.py`
   :language: python

Slide 121, "Exercises: Strings"
...............................

Write a program that receives any number of arguments and prints them
out right justified at column 20.

.. literalinclude:: Exercises/20.py
   :caption: :download:`Exercises/20.py`
   :language: python

Miscellaneous
-------------

Famous **Generator** Introduction
.................................

*Producing* an infinite sequence (Fibonacci, what else)

.. literalinclude:: Misc/fibo-generator-yield.py
   :caption: :download:`Misc/fibo-generator-yield.py`
   :language: python

``eval()``: Convert a String into a Python Data Structure
.........................................................

During the ``uniq`` exercise, people tend to want to pass a Python
list from the commandline, naively.

**Question**: how can I take an argument from the commandline (say,
``sys.argv[1]``) and interpret that as a list?

**Answer**: `eval
<https://docs.python.org/3/library/functions.html#eval>`__

The following program does that. Call it like so,

.. code-block:: console

   $ ./eval-argv.py '[1, 2, 3, 4]'

('$' is the shell prompt, the quotes are necessary to prevent the
shell from splitting arguments at the spaces)

.. literalinclude:: Misc/eval-argv.py
   :caption: :download:`Misc/eval-argv.py`
   :language: python

Operator Overloading
....................

Here's a little snippet that demonstrates this. `See the docs for more
<https://docs.python.org/3/reference/datamodel.html#special-method-names>`__.

.. literalinclude:: Misc/operator-overloading.py
   :caption: :download:`Misc/operator-overloading.py`
   :language: python

Getters and Setters
...................

Called "Properties" in Python; see below for a snippet. `See the docs
for more
<https://docs.python.org/3/library/functions.html#property>`__.

.. literalinclude:: Misc/getter-setter.py
   :caption: :download:`Misc/getter-setter.py`
   :language: python

More on Listcomprehensions and Generator Expressions
....................................................

.. literalinclude:: Misc/listcomprehension-generatorexpression.py
   :caption: :download:`Misc/listcomprehension-generatorexpression.py`
   :language: python

More on Local and Global Scope and Global Variables
...................................................

.. literalinclude:: Misc/scope.py
   :caption: :download:`Misc/scope.py`
   :language: python

Closures: Between Local and Global
..................................

.. literalinclude:: Misc/scope-closure.py
   :caption: :download:`Misc/scope-closure.py`
   :language: python

Project
-------

We had two days left, in addition to the usual three days which are
sufficient to learn the basics. A group project was launched, with the
somewhat real-life topic "talking to switches and doing all kinds of
stuff with that information".

This gave us the opportunity to discover a couple of areas more
closely.

* Object oriented programming (a switch has interfaces, and both have
  properties)
* Storing all that in databases
* Exception handling
* Commandline interfaces
* Unit testing

`See Github for source code
<https://github.com/jfasch/jfasch-home/tree/master/courses/records/2019-10-28/SwitchZeug/>`__.
