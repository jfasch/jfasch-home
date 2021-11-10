.. include:: <mmlalias.txt>

Closures (Livehacking Screenplay)
=================================

.. contents::
   :local:

``def`` is a Statement
----------------------

Demonstrate:

* Functions are objects, just like integers are
* ``def`` used inside another function |longrightarrow| local variable
* *function as return value*

.. list-table::
   :align: left

   * *

       .. literalinclude:: code/05_functions_are_objects.py
 	 :caption: :download:`code/05_functions_are_objects.py`
 	 :language: python
 
       .. code-block:: console
       
          $ python code/05_functions_are_objects.py
          f called
          f called
 
     * * ``def`` is a statement
       * creates function object, and name ``f`` in current scope that
	 refers to it
       * ``g = f`` demonstrates this
       * Why shouldn't we return a function from another function   
       * Function that creates a function?

.. list-table::
   :align: left

   * *
       .. literalinclude:: code/10_create_function.py
 	 :caption: :download:`code/10_create_function.py`
 	 :language: python
 
       .. code-block:: console
       
          $ python code/10_create_function.py 
          inner f called
 
     * * ``def`` called in function scope
       * name ``f`` is local
       * returned

Global Scope
------------

* Variables in global scope can be accessed by "inner" functions (no
  surprise)

.. list-table::
   :align: left

   * *

       .. literalinclude:: code/20_global_read.py
	  :caption: :download:`code/20_global_read.py`
	  :language: python
       
       .. code-block:: console
       
          $ python code/20_global_read.py
          inner f called, g = 1

     * * global variable ``g``
       * any function in the same global scope (*module* scope) can
         access it
       * inner function ``f`` can, too, as expected

And Intermediate Scope?
-----------------------

* Variables in the fnction containing the ``def``?

.. list-table::
   :align: left

   * * 
       .. literalinclude:: code/30_intermediate_closure.py
          :caption: :download:`code/30_intermediate_closure.py`
	  :language: python

       .. code-block:: console

          $ python code/30_intermediate_closure.py
          inner f called, intermediate = 1

     * * ``create_f``'s scope is gone after call returns
       * Inner ``f`` has been returned by that call
       * Obviously inner ``def f(): ...`` has *captured* variable
	 ``intermediate`` of enclosing scope
       * |longrightarrow| Definition of *closure*

A Less Theoretical "Use Case"
-----------------------------

.. list-table::
   :align: left

   * * 
       .. literalinclude:: code/35_closure_use_case.py
          :caption: :download:`code/35_closure_use_case.py`
	  :language: python

       .. code-block:: console

        $ python code/35_closure_use_case.py
        blah
        something

     * * (self explanatory)

Assignment to Global Scope
--------------------------

* Recap of ``global`` keyword
* ... used inside inner function

.. list-table::
   :align: left

   * *

       .. literalinclude:: code/40_global_assignment_wrong.py
          :caption: Wrong, :download:`code/40_global_assignment_wrong.py`
	  :language: python
  
       .. code-block:: console
       
          $ python code/40_global_assignment_wrong.py
          inner f called, g = 2
          global g = 1

     * * Revert closure stuff back to global
       * Assign to global variable, forgetting ``global``
       * Ah yes, ``f()`` assigned to (|longrightarrow| *created*)
	 local variable ``g``. This is what the ``global`` keyword is
	 there for

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/50_global_assignment_right.py
          :caption: Right, :download:`code/50_global_assignment_right.py`
          :language: python
       
       .. code-block:: console
       
          $ python code/50_global_assignment_right.py
          inner f called, g = 2
          global g = 2

     * * Ah yes, ``global``


Assignment to Intermediate Scope
--------------------------------

* And now, what about assignment to intermediate scope? To *a variable
  in the closure*?
* Who does this?
* Many non-obvious use cases, used to improve job security

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/60_intermediate_assignment_wrong.py
          :caption: Wrong, :download:`code/60_intermediate_assignment_wrong.py`
          :language: python
       
       .. code-block:: console
       
          $ python code/60_intermediate_assignment_wrong.py
          assign: intermediate = 2
          check: intermediate = 1

     * * rename ``f`` into ``assign``
       * variable ``intermediate`` instead of global ``g``
       * **Discuss**: how to check if ``intermediate`` has been
	 assigned correctly?
       * |longrightarrow| second local function ``check``
       * **Damn**! Again created a local variable!
       * |longrightarrow| ``nonlocal``

.. list-table::
   :align: left

   * * 

       .. literalinclude:: code/70_intermediate_assignment_right.py
          :caption: Wrong, :download:`code/70_intermediate_assignment_right.py`
          :language: python
       
       .. code-block:: console
       
          $ python code/70_intermediate_assignment_right.py
          assign: intermediate = 2
          check: intermediate = 2

     * * Tataa!
