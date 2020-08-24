.. include:: <mmlalias.txt>

Decorators (Slideshow)
======================

The Ominous "``@``"
-------------------

* Special syntax |longrightarrow| only syntactic sugar
* Used to *wrap* existing functions/methods

  * Without modifying them

* Examples

  * Debugging: printing function name and arguments
  * Timing information: time spent inside a function
  * Adding a D-Bus interface to a plain Python class
  * Defining Flask URL routes to call Python functions
  * ...

What and How
------------

* Only syntactic sugar for inner functions/closures (see
  :doc:`../closures/topic`)
* Can be implemented as functions

.. code-block:: python

   @debug
   def bar(a, b, c):
       ...

* Can be implemented as classes (usually when decorator is
  parameterized |longrightarrow| state needs to be remembered)

.. code-block:: python

   @debug(prefix)
   def bar(a, b, c):
       ...

