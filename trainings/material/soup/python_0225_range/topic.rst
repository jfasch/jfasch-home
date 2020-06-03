.. include:: <mmlalias.txt>

Python: The ``range`` Function
==============================

.. contents::
   :local:

.. jf-topic:: python_0225_range
   :dependencies: python_0200_sequential_types, python_0220_for

Iteration over Numbers: ``range()``
-----------------------------------

**Rare:** iteration using indexed access

.. code-block:: python
   :caption: Indexed access in C

   char hello[] = "Hello World";
   for (int i=0; i<sizeof(hello)-1; i++)
       printf("%d\n", hello[i]);

* Rarely needed in Python
* Iteration over *data*
* If needed: sequence of integer numbers

.. code-block:: python

   hello = 'Hello World'
   for i in range(len(hello)):
       print(ord(hello[i]))

``range()``: Definition
-----------------------

**The** ``range()`` **function produces numbers** ...

* ``range(100)`` produces ``0, 1, 2, ... 99``
* ``range(5, 100)`` produces ``5, 6, 7, ... 99``
* ``range(5, 100, 2)`` produces ``5, 7, 9, ... 99``

**Produces?**

* Result cannot easily be a list: ``range(10**9)``

.. code-block:: python

   >>> type(range(10**9))
   <class 'range'>

* *Generates* numbers on demand
* |longrightarrow| *Generator*

``range()``: Python 2 vs. Python 3
----------------------------------

**Incompatibility alert:**

* Python 2: ``range(10**9)`` *would* explode!
* Heritage of the old Pre-Generator days
* |longrightarrow| Python 2's ``xrange()`` is a generator

.. code-block:: python
   :caption: If one wants a list in Python 3 (unlikely) ...

   l = list(range(10**9))
