.. include:: <mmlalias.txt>

Functions: Global and Local Scope (Livehacking Screenplay)
==========================================================

.. contents::
   :local:

Undefined Variable
------------------

Using a name that is not defined (neither in local nor in global
scope) leads to an error:

.. jupyter-execute::
   :raises:

   def f():
       print(x)
   
   f()

Local Variable
--------------

``x`` defined locally:

.. jupyter-execute::

   def f():
       x = 1
       print(x)
   
   f()

* **Rule**: when a name is assigned to the first time, it is created
  in that scope where the assignment takes place.
* |longrightarrow| ``x`` is a *local variable*
* This is not Javascript where one has to use ``let`` to prevent
  accidental creation of a *global* variable

Global Variable
---------------

If a name is not defined locally, Python continues to lookup in global
scope:

.. jupyter-execute::

   def f():
       print(x)
   
   x = 42
   f()

Note: ``x`` must be visible at *call* time, not at *definition*
time

Local and Global Variable With Same Name
----------------------------------------

Local variables *shadow* global variables:

.. jupyter-execute::

   x = 666
   
   def f():
       x = 1
       print('local:', x)
   
   f()
   print('global:', x)

Assignment to Global Variable: ``global``
-----------------------------------------

.. sidebar::

   **See also**

   * :doc:`/trainings/material/soup/python/advanced/closures/topic`

* How do I assign to a global variable then, if assignment creates a
  variable in local scope?
* |longrightarrow| ``global`` keyword
* See :doc:`here
  </trainings/material/soup/python/advanced/closures/topic>` for a
  description of the ``nonlocal`` keyword

.. jupyter-execute::

   x = 666
   
   def f():
       global x
       x = 1
       print('assigned global:', x)
   
   f()
   print('global:', x)
