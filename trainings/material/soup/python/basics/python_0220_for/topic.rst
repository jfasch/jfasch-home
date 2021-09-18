.. include:: <mmlalias.txt>

``for`` Loops
=============

.. contents::
   :local:

.. ot-topic:: python.basics.python_0220_for
   :dependencies: python.basics.python_0200_sequential_types,
		  python.basics.python_0193_while

Iteration over ... Something
----------------------------

**Iteration:** a central concept everywhere

* Programs build and manipulate data
* ... and occasionally (most often?) iterate over data
* |longrightarrow| Specialized looping construct: ``for``

.. code-block:: python

   for name in ['Caro', 'Johanna', 'Eva', 'Jörg']:
       print(name)

* ``name``: *loop variable*
* Bound to the current element in the list, four times in a row
* A list is *iterable* - many other types participate in this game

``break``, ``continue``, ``else``
---------------------------------

**Just as with** ``while``: usual looping features

* ``break`` ends the loop - ``else`` clause not executed
* ``continue`` executes block with next element (if any)

.. code-block:: python

   haystack = ['straw', 'mouse', 'straw', 'needle', 'straw']
   for item in haystack:
       if item == 'needle':
           break
   else:
       print("couldn't find needle")
