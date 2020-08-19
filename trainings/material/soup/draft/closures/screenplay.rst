.. include:: <mmlalias.txt>

Closures (Livehacking Screenplay)
=================================

``def`` is a Statement
----------------------

Creates a function, and points a name to it (syntactic sugar).

.. code-block:: python

   >>> f()
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   NameError: name 'f' is not defined
   >>> def f():
   ...     print('f called')
   ... 
   >>> f
   <function f at 0x7fc8cc842310>
   >>> f()
   f called

.. code-block:: python

   >>> g = f
   >>> g()
   f called

**Discuss**

* Why shouldn't we return a function from another function   
* Function that creates a function?

.. literalinclude:: code/10_create_function.py
   :caption: :download:`code/10_create_function.py`
   :language: python

.. code-block:: console

   $ python code/10_create_function.py 
   inner f called

Global Scope
------------

.. literalinclude:: code/20_global_read.py
   :caption: :download:`code/20_global_read.py`
   :language: python

.. code-block:: console

   $ python code/20_global_read.py
   inner f called, g = 1

As expected.

And Intermediate Scope?
-----------------------

.. literalinclude:: code/30_intermediate_closure.py
   :caption: :download:`code/30_intermediate_closure.py`
   :language: python

.. code-block:: console

   $ python code/30_intermediate_closure.py
   inner f called, intermediate = 1

**Discuss**

* ``create_f``'s scope is gone after call returns
* Inner ``f`` has been returned by that call
* Obviously inner ``def f(): ...`` has *captured* variable
  ``intermediate`` of enclosing scope

|longrightarrow| *Closure*

How About Assignment?
---------------------

Assignment to Global Scope
..........................

.. literalinclude:: code/40_global_assignment_wrong.py
   :caption: Wrong, :download:`code/40_global_assignment_wrong.py`
   :language: python

.. code-block:: console

   $ python code/40_global_assignment_wrong.py
   inner f called, g = 2
   global g = 1

Ah yes, ``f()`` assigned to (|longrightarrow| *created*) local
variable ``g``. This is what the ``global`` keyword is there for:

.. literalinclude:: code/50_global_assignment_right.py
   :caption: Right, :download:`code/50_global_assignment_right.py`
   :language: python

.. code-block:: console

   $ python code/50_global_assignment_right.py
   inner f called, g = 2
   global g = 2

Assignment to Intermediate Scope
................................

* rename ``f`` into ``assign``
* variable ``intermediate`` instead of global ``g``
* **Discuss**: how to check if ``intermediate`` has been assigned
  correctly?
* |longrightarrow| second local function ``check``

.. literalinclude:: code/60_intermediate_assignment_wrong.py
   :caption: Wrong, :download:`code/60_intermediate_assignment_wrong.py`
   :language: python

.. code-block:: console

   $ python code/60_intermediate_assignment_wrong.py
   assign: intermediate = 2
   check: intermediate = 1

**Damn** |longrightarrow| ``nonlocal``

.. literalinclude:: code/70_intermediate_assignment_right.py
   :caption: Wrong, :download:`code/70_intermediate_assignment_right.py`
   :language: python

.. code-block:: console

   $ python code/70_intermediate_assignment_right.py
   assign: intermediate = 2
   check: intermediate = 2
